#include "Korpa.h"


Korpa::~Korpa()
{
}

double Korpa::getCijena() const
{
	double ukupnaCijena;
	for (int i = 0; i < brojStavki; i++)
		ukupnaCijena += nizStavki[i].getCijena();
	return ukupnaCijena;
}

void Korpa::dodajStavku(const Artikal &art, const int kol)
{
	if (seqSearch(art) > -1)
		++nizStavki[seqSearch(art)];
	else
	{
		Korpa mojaKorpa;
		mojaKorpa.nizStavki = new Stavka[brojStavki + 1];
		copy(mojaKorpa);
		mojaKorpa.nizStavki[brojStavki] = Stavka(art, kol);
		*this = mojaKorpa;
	}
}

int Korpa::seqSearch(const Artikal art)
{
	for (int i = 0; i < brojStavki; i++)
	{
		if (nizStavki[i] == art)
			return i;
	}
	return -1;
}

inline void Korpa::copy(const Korpa &korpa)
{
	this->nizStavki = new Stavka[korpa.brojStavki];
	for (int i = 0; i < brojStavki; i++)
		this->nizStavki[i] = korpa.nizStavki[i];
}
/*
Korpa & Korpa::operator--()
{
	for (int i = 0; i < brojStavki; i++)
	{
		if (!nizStavki[i].getKolicina());
			//haos!!
	}
}
*/

std::ostream & operator<<(std::ostream &output, Korpa &korpa)
{
	output << "====================================================" << std::endl;
	output << "Korpa:" << korpa.getCijena() << "KM  (broj stavki: "<<korpa.brojStavki<< ")" << std::endl;
	output << "----------------------------------------------------" << std::endl;
	for (int i = 0; i < korpa.brojStavki; i++)
		output << korpa.nizStavki[i]<<std::endl;
	output << "====================================================" << std::endl;
	return output;
}
