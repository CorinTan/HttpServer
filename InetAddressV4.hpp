#pragma once
#include "Copyable.hpp"

#include <string>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <utility>

// 只支持 IPv4
class InetAddressV4 : public Copyable{
public:
    explicit InetAddressV4() { 
        reset();
    }    

    explicit InetAddressV4(const std::string &ip, u_int16_t port) { 
        reset();
        setIp(ip);
        setPort(port);
    }
     
    InetAddressV4 &setIp(const std::string &ip) {
        inet_aton(ip.c_str(), &(addr_.sin_addr));
        return *this;
    }
    
    InetAddressV4 &setPort(uint16_t port) {
        addr_.sin_port = htons(port);
        return *this;
    }

    InetAddressV4 & setIpPort(const std::string &ip, uint16_t port) {
        return setIp(ip).setPort(port);
    }
    
    std::string toIpStr() const {
        return inet_ntoa(addr_.sin_addr);
    }

    // 网络序
    uint32_t toIpNum() const {
        return addr_.sin_addr.s_addr;
    }

    uint16_t toPort() const {
        return ntohs(addr_.sin_port);
    }

    auto getIpPort() const {
        return std::make_pair(toIpStr(), toPort());
    }

    const sockaddr *getSockAddrPtr() const {
        return reinterpret_cast<const sockaddr *>(&addr_); 
    }

    InetAddressV4 & reset() {
        memset(&addr_, 0, INET_ADDRSTRLEN);
        addr_.sin_family = AF_INET;
        return *this;
    }

private:
    sockaddr_in addr_;
};