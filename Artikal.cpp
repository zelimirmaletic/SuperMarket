#include "Artikal.h"
#include <utility>

Artikal::Artikal(const char * naziv, const char * jed, const double cijena)
{
	this->naziv = new char[strlen(naziv) + 1];
	this->jedinicaMjere = new char[std::strlen(jed) + 1];
	strcpy(this->naziv, naziv);
	strcpy(this->jedinicaMjere, jed);
	this->jedinicnaCijena = cijena;
}

Artikal::Artikal():Artikal("?","?",0.0)
{}

bool Artikal::operator==(const Artikal &mojArtikal) const
{
	return (bool)(!strcmp(this->naziv, mojArtikal.naziv));
}

Artikal & Artikal::operator=(const Artikal &artikal)
{
	if (this != &artikal)
	{
		this->~Artikal();
		copy(artikal);
	}
	return *this;
}

Artikal & Artikal::operator=(Artikal &&artikal)
{
	if (this != &artikal)
	{
		this->~Artikal();
		move(std::move(artikal));
	}
	return *this;

}

void Artikal::move(Artikal &&artikal)
{
	naziv = std::move(artikal.naziv);
	jedinicaMjere = std::move(artikal.jedinicaMjere);
	jedinicnaCijena = std::move(artikal.jedinicnaCijena);
	artikal.naziv = artikal.jedinicaMjere = nullptr;
	 //Version without <utility>
	/*
	this->naziv = artikal.naziv;
	this->jedinicaMjere = artikal.jedinicaMjere;
	this->jedinicnaCijena = artikal.jedinicnaCijena;
	artikal.jedinicaMjere = artikal.naziv= nullptr;
	artikal.naziv = nullptr;
	*/
}

void Artikal::copy(const Artikal artikal)
{
	std::strcpy(naziv = new char[strlen(artikal.naziv)+1],artikal.naziv);
	std::strcpy(jedinicaMjere = new char[strlen(artikal.jedinicaMjere) + 1], artikal.jedinicaMjere);
	this->jedinicnaCijena = artikal.jedinicnaCijena;
}


std::ostream & operator<<(std::ostream &output, const Artikal &artikal)
{
	output << artikal.naziv << "(" << artikal.jedinicnaCijena << ")" << std::endl;
	return output;
}

std::istream & operator>>(std::istream &input,Artikal &artikal)
{
	input >> artikal;
	input >> artikal;
	input >> artikal;
	return input;
}
