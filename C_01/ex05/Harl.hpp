#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl 
{
public:
    Harl();
    void complain(const std::string& level);

private:
    void debug();
    void info();
    void warning();
    void error();

    void (Harl::*functions[4])();
    std::string levels[4];
};

#endif
