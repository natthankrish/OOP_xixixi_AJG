#ifndef INVENTORYEXCEPTION_H
#define INVENTORYEXCEPTION_H

#include <exception>
using namespace std;

class PlayerCardFullException : public exception  {
	const char* what() const throw() {
		return "Kartu Player Sudah Penuh";
	}
};

class PlayerCardEmptyException : public exception  {
	const char* what() const throw() {
		return "Kartu Player Sudah Kosong";
	}
};

class TableCardFullException : public exception  {
	const char* what() const throw() {
		return "Kartu di Meja Sudah Penuh";
	}
};

class CardNotFoundException : public exception  {
	const char* what() const throw() {
		return "Kartu Tidak Ada Di Meja";
	}
};

#endif