#include "RepoFile.h"
RepoFile::RepoFile()
{

}
RepoFile::RepoFile(string fileName)
{
	this->fileName = fileName;
}
RepoFile::~RepoFile()
{

}
void RepoFile::setFileName(string fileName)
{
	this->fileName = fileName;
}
vector<Magazin*> RepoFile::getAll()
{
	return this->magazin;
}
int RepoFile::getSize()
{
	return this->magazin.size();
}
Magazin* RepoFile::get(int pos)
{
	if (pos >= 0 && pos < this->getSize())
	{
		return this->magazin[pos]->clone();
	}
	return new Magazin();
}
void RepoFile::add(Magazin* m)
{
	int ok = 0;
	int p = 1;
	for (size_t i = 0; i < magazin.size(); i++)
	{
		if (magazin[i]->getCod() == (*m).getCod())
			ok = 1;
		if (ok == 1)
		{
			updateMagazin(this->magazin[i], m);
			p = 0;
			ok = 0;
		}
	}
	if(p==1)
	this->magazin.emplace(magazin.begin(),m->clone());
	this->saveToFile();
}
void RepoFile::updateMagazin(Magazin* mVechi, Magazin* mNou)
{
	int k = this->magazin.size();
	for (int i = 0; i < k; i++) {
		if (*(this->get(i)) == *mVechi)
		{
			delete this->magazin[i];
			this->magazin[i] = mNou->clone();
			this->saveToFile();
			return;
		}
	}
}
void RepoFile::deleteMagazin(Magazin* m)
{
	int k = this->magazin.size();
	for (int i = 0; i < k; i++)
	{
		if (**(this->magazin.begin() + i) == *m)
		{
			delete this->magazin[i];
			this->magazin.erase(this->magazin.begin() + i);
			this->saveToFile();
			return;
		}
	}
}
void RepoFile::emptyRepo()
{
	for (int i = 0; i < this->getSize(); i++)
	{
		delete this->magazin[i];
	}
	this->magazin.clear();
}