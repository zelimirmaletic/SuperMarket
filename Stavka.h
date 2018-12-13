#pragma once
#include "Artikal.h"
#include <iostream>
class Stavka
{
	Artikal artikal;
	int kolicina;
	friend std::ostream &operator<<(std::ostream &, const Stavka &);
public:
	Stavka(const Artikal&, const int kol = 0);
	Stavka()=default;
	//Nema potrebe za definisanjem move i copy konstruktora, koristimo default-ne
	Stavka &operator+=(const int);
	constexpr double getCijena(void){ return (double)this->kolicina*this->artikal.getCijena(); }
	constexpr int getKolicina(void){ return this->kolicina; }
	inline bool operator==(const Stavka stavka) { return (bool)(stavka.artikal == this->artikal); }
	inline Stavka &operator++() { this->kolicina++; return *this; }
};


