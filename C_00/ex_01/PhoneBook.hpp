#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>

class Contact
{
private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

public:
    Contact();
    void setDetails(const std::string& fn, const std::string& ln, const std::string& nn, const std::string& pn, const std::string& ds);
    void displayContact() const;
    void displayBrief() const;

};

class PhoneBook
{
private:
    Contact contacts[8];  
    int oldest_index;

public:
    PhoneBook();
    void addContact(const Contact& contact);
    void searchContact() const;
    const Contact& getContact(int index) const;
};

#endif
