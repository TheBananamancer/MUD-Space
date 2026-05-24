#include "Session.h"
#include <iostream>

Session::Session(boost::asio::io_context& io_context, World& world)
    : socket_(io_context), world_(world)
{
    player_.currentRoom = nullptr;
}

void Session::start()
{
    player_.currentRoom = world_.persistence_manager_.starting_room;
    do_read();
}

void Session::deliver(const std::string& msg)
{
    do_write(msg);
}

void Session::do_read()
{
    boost::asio::async_read_until(socket_, boost::asio::dynamic_buffer(read_buffer_), "\r\n",
        [self = shared_from_this()](const boost::system::error_code& error, std::size_t bytes_transferred) {
            if (!error) {
                self->on_command(self->read_buffer_.substr(0, bytes_transferred - 2));
                self->read_buffer_.erase(0, bytes_transferred);
                self->do_read();
            } else {
                std::cerr << "Error on read: " << error.message() << std::endl;
            }
        });
}

void Session::do_write(std::string msg)
{
    msg += "\r\n";
    boost::asio::async_write(socket_, boost::asio::buffer(msg),
        [self = shared_from_this()](const boost::system::error_code& error, std::size_t /*bytes_transferred*/) {
            if (error) {
                std::cerr << "Error on write: " << error.message() << std::endl;
            }
        });
}

void Session::on_command(const std::string& command)
{
    ParsedCommand parsed_command = command_parser_.parse(command);
    std::string response = command_dispatcher_.get_handler(parsed_command.verb)(*this, parsed_command);
    deliver(response);
}
