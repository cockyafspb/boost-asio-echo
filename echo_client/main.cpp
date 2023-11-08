#include "client.h"


int main(int argc, char *argv[])
{
    if (argc != 3) {
        std::cerr << "Usage: echo_client <ip> <port>\n";
        return EXIT_FAILURE;
    }
    io_context ioc;
    tcp::endpoint endpoint(address::from_string(argv[1]), std::stoi(argv[2]));
    client client(ioc, endpoint);
    std::thread t([&ioc]() { ioc.run(); });
    std::string data;
    while (data.substr(0, 4) != "exit") {
        std::getline(std::cin, data);
        data += '\n';
        client.write(data);
    }
    t.join();
    return EXIT_SUCCESS;
}