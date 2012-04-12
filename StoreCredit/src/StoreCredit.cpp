//============================================================================
// Name        : StoreCredit.cpp
// Author      : yanock
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include "String.h"
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

clock_t start=clock();

int main() {

	//freopen("/yanock/Desktop/storeCredit","r",stdin);
	//freopen("/yanock/Desktop/a1.out","w",stdout);

	ofstream out("../../Desktop/A-large-practice.out");
	ifstream in("../../Desktop/A-large-practice.in");


	if(in)
	{
		int test_case, credit, i, nb_article, j, k;
		string ligne;
		in >> test_case;
		for(i = 0; i < test_case; i++)
		{

			in >> credit;
			in >> nb_article;
			getline(in, ligne); //get fin de ligne
			getline(in, ligne);
			//split des element vers un tableau que l'on peut parcourir
			//cout<<ligne<<endl;
			vector<string> articles;
			articles = split(ligne, ' ');

			for (size_t parcours = 0; parcours < articles.size(); parcours++)
			{
				for (size_t parcours2 = parcours+1; parcours2 < articles.size(); parcours2++)
				{
					j = atoi(articles[parcours].c_str());
					k = atoi(articles[parcours2].c_str());
					if((j+k) == credit)
					{
						out << "Case #" << i+1 << ": " << parcours+1 << " " << parcours2+1 <<endl;
						cout << "Case #" << i+1 << ": " << parcours+1 << " " << parcours2+1 <<endl;
					}
				}
			}

		}

	}
	else
	{
	    cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
	}

	printf("time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}
