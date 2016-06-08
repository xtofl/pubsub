#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

std::string make_daytime_string()
{
  std::time_t now = std::time(0);
  return std::ctime(&now);
}

int main()
{
  try
  {
    boost::asio::io_service io_service;
    tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 4000));

    const std::function<void()> spawn = [&]{
        // note: no unique_ptr... http://stackoverflow.com/questions/37709819/why-must-a-boost-asio-handler-be-copy-constructible
        auto socket = std::make_shared<tcp::socket>(io_service);
        acceptor.accept(*socket);

        io_service.post([=]{
            std::string message = make_daytime_string();

            boost::system::error_code ignored_error;
            boost::asio::write(*socket, boost::asio::buffer(message), ignored_error);
        });
        io_service.post(spawn);
    };

    io_service.post(spawn);

    io_service.run();
  }
  catch (std::exception& e)
  {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  return 0;
}
