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

class AllOtherPlayersHaveUsedTheirCardsException : public exception {
	public: 
		const char* what() const throw() {
			return "Eits, ternyata semua pemain sudah memakai kartu kemampuan. Yah kamu kena sendiri deh, kemampuanmu menjadi abilityless. Yah, pengunaan kartu ini sia-sia";
		}
};
#endif