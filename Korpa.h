#pragma once
#include "Stavka.h"
class Korpa
{
	Stavka *nizStavki;
	int brojStavki;
	friend std::ostream &operator<<(std::ostream &, Korpa &);
public:
	inline Korpa() :brojStavki(0), nizStavki(nullptr) {};
	~Korpa() { empty(); };
	double getCijena() const;
	void dodajStavku(const Artikal&, const int);
	int seqSearch(const Artikal);
private:
	inline void empty() { delete[] nizStavki; nizStavki = nullptr; }
	inline void copy(const Korpa &);
	//Korpa &operator--();
};

