#pragma once
#include "magazin.h"
#include <vector>
using namespace std;
class RepoFile {
protected:
	vector<Magazin*> magazin;
	string fileName;
public:
	RepoFile();
	RepoFile(string fileName);
	~RepoFile();
	void setFileName(string fileName);
	vector<Magazin*> getAll();
	int getSize();
	Magazin* get(int pos);
	void add(Magazin* m);
	void updateMagazin(Magazin* mVechi, Magazin* mNou);
	void deleteMagazin(Magazin* m);
	void emptyRepo();
	virtual void loadFromFile() = 0;
	virtual void saveToFile() = 0;
};