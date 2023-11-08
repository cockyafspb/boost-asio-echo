#include "client.h"

client::client(io_context &ioc, tcp::endpoint &endpoint)
        : socket(ioc)
{
    do_connect(endpoint);
}

void client::do_connect(tcp::endpoint &endpoint)
{
    socket.async_connect(endpoint, [this](boost::system::error_code ec)
    {
        do_read();
    });
}

void client::write(const std::string &msg)
{
    auto ss = std::make_shared<std::string>(msg);

    post(socket.get_executor(), [this, ss]()
    {
        do_write(ss);
    });
}

void client::do_write(const std::shared_ptr<std::string> &ss)
{
    async_write(socket, boost::asio::buffer(*ss),
                [ss](boost::system::error_code err, size_t bytes) {});
}

void client::do_read()
{
    async_read_until(
            socket,
            boost::asio::dynamic_buffer(data),
            "\n",
            [this](boost::system::error_code ec, std::size_t bytes)
            {
                std::cout << data;
                data.clear();
                do_read();
            });
}
