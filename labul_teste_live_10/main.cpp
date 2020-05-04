#include "animal_de_companie.h"
#include "magazin.h"
#include "produse_magazin.h"
#include "teste_repo_2.h"
#include "RepoFile.h"
#include "RepoFileCsv.h"
#include "RepoFileCsv.h"
#include <iostream>
#include <Windows.h>
using namespace std;
int main()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << "Start...." << endl;
	TestRepoFile2 t;
	t.testAll();
	cout << "Stop..." << endl;
	return 0;
}