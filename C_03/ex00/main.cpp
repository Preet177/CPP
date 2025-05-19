#include "ClapTrap.hpp"

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

    return 0;
}
