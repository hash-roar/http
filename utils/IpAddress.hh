#pragma once

#include <netdb.h>
#include <netinet/in.h>
#include <string>
#include <sys/socket.h>

class IpAddress {
public:
    class RawSockData {
    public:
        sockaddr_storage storage {};
        operator sockaddr*();
        operator const sockaddr*() const;
    };

private:
    socklen_t size_; // size of wrapped address
    RawSockData addr_;

    IpAddress(const std::string& node, const std::string& service, const addrinfo& hints);

    public:
    IpAddress(const std::string &hostname,const std::string &service);
};