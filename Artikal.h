#pragma once
#include<string>
#include<iostream>

class Artikal
{
	 char *naziv;
	 char *jedinicaMjere;
	 double jedinicnaCijena;
	 friend std::ostream &operator<<(std::ostream &, const Artikal&);
	 friend std::istream &operator>>(std::istream &, const Artikal&);
public:
	Artikal(const char *, const char *, const double cijena = 0.0);
	Artikal();
	inline Artikal(const Artikal  &artikal) { copy(artikal); }
	inline Artikal(Artikal &&artikal) { move(std::move(artikal)); }
	bool operator==(const Artikal&) const;
	inline ~Artikal() { empty(); };
	Artikal &operator=(const Artikal &);
	Artikal &operator=(Artikal &&);
	constexpr double getCijena(void){ return jedinicnaCijena; };
private:
	inline void empty() { delete[] naziv; delete[] jedinicaMjere; naziv = jedinicaMjere = nullptr; }
	void move(Artikal&&);
	void copy(const Artikal);
};

