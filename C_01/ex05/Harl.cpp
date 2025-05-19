#include "Harl.hpp"
#include <iostream>

Harl::Harl() 
{
    levels[0] = "DEBUG";
    levels[1] = "INFO";
    levels[2] = "WARNING";
    levels[3] = "ERROR";

    functions[0] = &Harl::debug;
    functions[1] = &Harl::info;
    functions[2] = &Harl::warning;
    functions[3] = &Harl::error;
}

void Harl::complain(const std::string& level) 
{
    for (int i = 0; i < 4; ++i) 
    {
        if (levels[i] == level) 
        {
            (this->*functions[i])();
            return;
        }
    }
}

void Harl::debug() 
{
    std::cout << "DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info() 
{
    std::cout << "INFO: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning() 
{
    std::cout << "WARNING: I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error() 
{
    std::cout << "ERROR: This is unacceptable! I want to speak to the manager now." << std::endl;
}
