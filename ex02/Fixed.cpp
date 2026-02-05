#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _value(value << _fractionalBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _value(roundf(value * (1 << _fractionalBits))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _value(other._value) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		_value = other._value;
	}
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	return _value;
}

void Fixed::setRawBits(int const raw) {
	_value = raw;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(_value) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
	return _value >> _fractionalBits;
}

bool Fixed::operator>(const Fixed& other) const {
	return _value > other._value;
}

bool Fixed::operator<(const Fixed& other) const {
	return _value < other._value;
}

bool Fixed::operator>=(const Fixed& other) const {
	return _value >= other._value;
}

bool Fixed::operator<=(const Fixed& other) const {
	return _value <= other._value;
}

bool Fixed::operator==(const Fixed& other) const {
	return _value == other._value;
}

bool Fixed::operator!=(const Fixed& other) const {
	return _value != other._value;
}

Fixed Fixed::operator+(const Fixed& other) const {
	Fixed result;
	result.setRawBits(_value + other._value);
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
	Fixed result;
	result.setRawBits(_value - other._value);
	return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
	Fixed result;
	result.setRawBits((_value * other._value) >> _fractionalBits);
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
	Fixed result;
	result.setRawBits((_value << _fractionalBits) / other._value);
	return result;
}

Fixed& Fixed::operator++() {
	_value++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	_value++;
	return temp;
}

Fixed& Fixed::operator--() {
	_value--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	_value--;
	return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}