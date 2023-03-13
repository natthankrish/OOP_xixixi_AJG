#ifndef CARDEXCEPTION_HPP
#define CARDEXCEPTION_HPP

#include <exception>
using namespace std;

class PlayerDoesNotHaveCardException : public exception  {
	public: 
		const char* what() const throw() {
			return "Ets, tidak bisa. Kamu tidak punya kartu Ability ";
		}
};

#endif