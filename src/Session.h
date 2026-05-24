#ifndef SESSION_H
#define SESSION_H

#include <boost/asio.hpp>
#include <memory>
#include <string>
#include "CommandDispatcher.h"
#include "CommandParser.h"
#include "World.h"
#include "Player.h"

class Session : public std::enable_shared_from_this<Session>
{
public:
    Session(boost::asio::io_context& io_context, World& world);
    void start();
    void deliver(const std::string& msg);
    Player player_;

private:
    boost::asio::ip::tcp::socket socket_;
    std::string read_buffer_;
    CommandDispatcher command_dispatcher_;
    CommandParser command_parser_;
    World& world_;

    void do_read();
    void do_write(std::string msg);
    void on_command(const std::string& command);
};

using session_ptr = std::shared_ptr<Session>;

#endif
