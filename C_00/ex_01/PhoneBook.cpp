#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : oldest_index(0) {}

void PhoneBook::addContact(const Contact& contact)
{
    contacts[oldest_index] = contact;
    oldest_index = (oldest_index + 1) % 8;
}

void PhoneBook::searchContact() const
{
    std::cout << "   Index  | First Name | Last Name  | Nickname   " << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    for (int i = 0; i < 8; ++i)
    {
        std::cout << std::setw(10) << std::right << i << " | ";
        contacts[i].displayBrief(); 
    }
}

const Contact& PhoneBook::getContact(int index) const
{
    return contacts[index];
}

// Additional functions
void displayMenu()
{
    std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
}

void addContact(PhoneBook& phonebook)
{
    std::string first_name, last_name, nickname, phone_number, darkest_secret;

    std::cout << "Enter first name: ";
    std::getline(std::cin, first_name);
    std::cout << "Enter last name: ";
    std::getline(std::cin, last_name);
    std::cout << "Enter nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Enter phone number: ";
    std::getline(std::cin, phone_number);
    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, darkest_secret);

    if (first_name.empty() || last_name.empty() || nickname.empty() ||
        phone_number.empty() || darkest_secret.empty())
    {
        std::cout << "Error: All fields must be filled." << std::endl;
        return;
    }

    Contact new_contact;
    new_contact.setDetails(first_name, last_name, nickname, phone_number, darkest_secret);
    phonebook.addContact(new_contact);
}

void searchContacts(const PhoneBook& phonebook)
{
    phonebook.searchContact();

    std::cout << "Enter the index of the contact to display: ";
    int index;
    std::cin >> index;
    std::cin.ignore();

    if (index < 0 || index >= 8)
    {
        std::cout << "Error: It must be a number between 0 and 7" << std::endl;
        return;
    }

    const Contact& contact = phonebook.getContact(index);
    contact.displayContact();
}

int main()
{
    PhoneBook phonebook;
    std::string command;

    while (true)
    {
        displayMenu();
        std::getline(std::cin, command);

        if (command == "ADD")
        {
            addContact(phonebook);
        }
        else if (command == "SEARCH")
        {
            searchContacts(phonebook);
        }
        else if (command == "EXIT")
        {
            break;
        }
        else
        {
            std::cout << "Invalid command. Please try again." << std::endl;
        }
    }

    return 0;
}
