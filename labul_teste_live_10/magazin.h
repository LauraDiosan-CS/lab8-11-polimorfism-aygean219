#pragma once
#include <ostream>
#include <string>
using namespace std;
class Magazin {
protected:
	string cod;
	string nume;
	double pret;
	string data_introducerii;
	double  nr_exemplare_disponibile;
public:
	Magazin();
	Magazin(string, string, double, string, double);
	Magazin(const Magazin&);
	~Magazin();
	virtual Magazin* clone();
	string  getCod();
	string getNume();
	double  getPret();
	string getDataIntroducerii();
	double  getNrExemplareDisponibile();
	void setCod(string);
	void setNume(string);
	void setPret(double);
	void setDataIntroducerii(string);
	void setNrExemplareDisponibile(double  nr);
	Magazin& operator=(const Magazin& m);
	bool operator==(const Magazin& m);
	virtual string toStringDelimiter(string delim);


};