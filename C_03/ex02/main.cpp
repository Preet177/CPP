#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ClapTrap clap("CLAPPY");

    clap.attack("target1");
    clap.takeDamage(5);
    clap.beRepaired(3);

    clap.attack("target2");
    clap.takeDamage(8);
    clap.beRepaired(5);

    clap.attack("target3");

    ScavTrap scav("SCAVVY");

    scav.attack("target4");
    scav.takeDamage(15);
    scav.beRepaired(10);

    scav.guardGate();

    FragTrap frag("FRAGGY");

    frag.attack("target5");
    frag.takeDamage(20);
    frag.beRepaired(15);

    frag.highFivesGuys();

    return 0;
}
