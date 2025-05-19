#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name)
    : Name(name), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
    std::cout << "ClapTrap " << Name << " has been created!" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << Name << " has been destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (HitPoints > 0 && EnergyPoints > 0)
    {
        std::cout << "ClapTrap " << Name << " attacks " << target
                  << ", causing " << AttackDamage << " points of damage!" << std::endl;
        EnergyPoints--;
    }
    else
    {
        std::cout << "ClapTrap " << Name << " can't attack. No hit points or energy points left." << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (HitPoints > 0)
    {
        if (HitPoints <= amount) {
            HitPoints = 0;
        } else {
            HitPoints -= amount;
        }
        std::cout << "ClapTrap " << Name << " takes " << amount
                  << " points of damage! Current hit points: " << HitPoints << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << Name << " can't take more damage. Already destroyed." << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (HitPoints > 0 && EnergyPoints > 0)
    {
        HitPoints += amount;
        EnergyPoints--;
        std::cout << "ClapTrap " << Name << " is repaired by " << amount
                  << " points! Current hit points: " << HitPoints
                  << ", Current energy points: " << EnergyPoints << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << Name << " can't be repaired. No hit points or energy points left." << std::endl;
    }
}
