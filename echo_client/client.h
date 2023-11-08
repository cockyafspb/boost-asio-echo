#pragma once
#include <iostream>
#include <boost/asio.hpp>

using boost::asio::io_context;
using boost::asio::ip::tcp;
using boost::asio::ip::address;
using boost::system::error_code;

class client
{
public:
    client(io_context& ioc, tcp::endpoint& endpoint);

    void write(const std::string& msg);
    void do_write(const std::shared_ptr<std::string>& ss);
    void do_connect(tcp::endpoint& endpoint);
    void do_read();

private:
    tcp::socket socket;
    std::string data;
};

