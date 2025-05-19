#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intValue) : value(intValue << fractionalBits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatValue) : value(roundf(floatValue * (1 << fractionalBits)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->value = other.getRawBits();
    }
    return *this;
}

bool Fixed::operator>(const Fixed &other) const { return value > other.value; }
bool Fixed::operator<(const Fixed &other) const { return value < other.value; }
bool Fixed::operator>=(const Fixed &other) const { return value >= other.value; }
bool Fixed::operator<=(const Fixed &other) const { return value <= other.value; }
bool Fixed::operator==(const Fixed &other) const { return value == other.value; }
bool Fixed::operator!=(const Fixed &other) const { return value != other.value; }

Fixed Fixed::operator+(const Fixed &other) const { return Fixed(this->toFloat() + other.toFloat()); }
Fixed Fixed::operator-(const Fixed &other) const { return Fixed(this->toFloat() - other.toFloat()); }
Fixed Fixed::operator*(const Fixed &other) const { return Fixed(this->toFloat() * other.toFloat()); }
Fixed Fixed::operator/(const Fixed &other) const { return Fixed(this->toFloat() / other.toFloat()); }

Fixed &Fixed::operator++() { ++value; return *this; } 
Fixed Fixed::operator++(int) { Fixed temp = *this; ++value; return temp; } 
Fixed &Fixed::operator--() { --value; return *this; }
Fixed Fixed::operator--(int) { Fixed temp = *this; --value; return temp; }

int Fixed::getRawBits() const
{
    return value;
}

void Fixed::setRawBits(int const raw)
{
    value = raw;
}

float Fixed::toFloat() const
{
    return static_cast<float>(value) / (1 << fractionalBits);
}

int Fixed::toInt() const
{
    return value >> fractionalBits;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) 
{
    if (a < b) 
        return a;
     else 
        return b;
    
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) 
{
    if (a < b) 
        return a;
     else
        return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
   if (a > b) 
        return a;
     else
        return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) 
{
   if (a > b) 
        return a;
     else
        return b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}