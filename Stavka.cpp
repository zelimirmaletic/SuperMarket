#include "Stavka.h"

Stavka::Stavka(const Artikal &art, const int kol):artikal(art),kolicina(kol)
{}

Stavka::Stavka():Stavka(Artikal::Artikal(),0)//delegirajuci konstruktor!
{}

Stavka & Stavka::operator+=(const int inkrement)
{
	this->kolicina += inkrement;
	return *this;
}

std::ostream & operator<<(std::ostream &output, const Stavka &stavka)
{
	output << stavka.artikal << " " << stavka.kolicina << "(" << stavka.artikal.getCijena() *stavka.kolicina<< ")";
	return output;
}
