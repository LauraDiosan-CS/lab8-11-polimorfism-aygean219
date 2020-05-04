#include <assert.h>
#include "teste_repo_2.h"
#include "produse_magazin.h"
#include "animal_de_companie.h"
#include "RepoFileTxt.h"
#include "RepoFileCsv.h"
#include <iostream>
using namespace std;
void TestRepoFile2::teste()
{	
	RepoFile* repo = new RepoFileCsv(this->fileNameInCsv);
	repo->loadFromFile();
	repo->setFileName(this->fileNameOutCsv);
	Animal* a1 = new Animal("pwf6", "papagal", 100, "01.04.2020", 2, 5);
	Produs* a2 = new Produs("d59g", "mancare_pesti", 30, "11.12.2019",12, "01.01.2022");
	Animal* a3 = new Animal("eh79", "hamster", 60, "03.05.2020", 1, 3);
	Animal* a4 = new Animal("d59g", "canar", 70, "07.03.2020", 3, 1);
	assert(repo->getSize() == 2);
	assert(*(repo->get(0)) == *a2);
	assert(*(repo->get(1)) == *a1);
	repo->add(a3);
	assert(repo->getSize() == 3);
	assert(*(repo->get(0)) == *a3);
	assert(*(repo->get(1)) == *a2);
	assert(*(repo->get(2)) == *a1);
	repo->add(a4);
	assert(repo->getSize() == 3);
	assert(*(repo->get(0)) == *a3);
	assert(*(repo->get(1)) == *a4);
	assert(*(repo->get(2)) == *a1);

}
void TestRepoFile2::testAll()
{
	this->teste();
}