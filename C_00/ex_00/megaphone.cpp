#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            std::string arg(argv[i]);
            for (int j = 0; argv[i][j]; j++)
            {
                arg[j] = std::toupper(argv[i][j]);
            }
            std::cout << arg; 

            if (i < argc - 1) 
            {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    return 0;
}
