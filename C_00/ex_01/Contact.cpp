#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact() {}

void Contact::setDetails(const std::string& fn, const std::string& ln, const std::string& nn, const std::string& pn, const std::string& ds)
{
    first_name = fn;
    last_name = ln;
    nickname = nn;
    phone_number = pn;
    darkest_secret = ds;
}

void Contact::displayContact() const
{
    std::cout << "First name: " << first_name << std::endl;
    std::cout << "Last name: " << last_name << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone number: " << phone_number << std::endl;
    std::cout << "Darkest secret: " << darkest_secret << std::endl;
}

void Contact::displayBrief() const
{
    std::cout << std::setw(10) << std::right << first_name << " | "
              << std::setw(10) << std::right << last_name << " | "
              << std::setw(10) << std::right << nickname << std::endl;
}
