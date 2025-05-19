#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;
    
    std::cout << Fixed::max(a, b) << std::endl;
    return 0;
}

/*

int main() {
    Fixed a(5.05f);
    Fixed b(2.5f);
    Fixed c(5.05f);

    
    std::cout << std::boolalpha; 
    std::cout << "a > b: " << (a > b) << std::endl; 
    std::cout << "a < b: " << (a < b) << std::endl; 
    std::cout << "a >= c: " << (a >= c) << std::endl; 
    std::cout << "a <= b: " << (a <= b) << std::endl; 
    std::cout << "a == c: " << (a == c) << std::endl; 
    std::cout << "a != b: " << (a != b) << std::endl; 

    return 0;
} */
/*
int main() {
    Fixed a(5.05f);
    Fixed b(2.0f);

    Fixed resultAdd = a + b;
    Fixed resultSub = a - b;
    Fixed resultMul = a * b;
    Fixed resultDiv = a / b;

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "a + b: " << resultAdd << std::endl;
    std::cout << "a - b: " << resultSub << std::endl;
    std::cout << "a * b: " << resultMul << std::endl; 
    std::cout << "a / b: " << resultDiv << std::endl; 

    return 0;
} */