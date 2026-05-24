#include "CommandParser.h"
#include <sstream>
#include <algorithm>

ParsedCommand CommandParser::parse(const std::string& raw_input)
{
    ParsedCommand cmd;
    std::string input = strip(raw_input);

    if (input.empty()) {
        return cmd;
    }

    std::istringstream stream(input);
    std::string token;

    if (stream >> token) {
        std::transform(token.begin(), token.end(), token.begin(), ::tolower);
        cmd.verb = token;
    }

    while (stream >> token) {
        cmd.args.push_back(token);
    }

    // Add support for direction commands
    if (cmd.verb == "n") {
        cmd.verb = "north";
    } else if (cmd.verb == "s") {
        cmd.verb = "south";
    } else if (cmd.verb == "e") {
        cmd.verb = "east";
    } else if (cmd.verb == "w") {
        cmd.verb = "west";
    }

    return cmd;
}

std::string CommandParser::strip(const std::string& s)
{
    std::string result = s;
    result.erase(result.begin(), std::find_if(result.begin(), result.end(), [](int ch) {
        return !std::isspace(ch);
    }));
    result.erase(std::find_if(result.rbegin(), result.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), result.end());
    return result;
}
