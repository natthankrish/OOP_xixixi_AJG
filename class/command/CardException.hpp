#ifndef CARDEXCEPTION_HPP
#define CARDEXCEPTION_HPP

#include <exception>
using namespace std;

class PlayerDoesNotHaveCardException : public exception  {
	const char* what() const throw() {
		return "Palyer tidak memiliki kartu.";
	}
};

#endif