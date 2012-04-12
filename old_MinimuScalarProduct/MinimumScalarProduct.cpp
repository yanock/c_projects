//============================================================================
// Name        : StoreCredit.cpp
// Author      : yanock
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <fstream>
#include "String.h"
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

clock_t start=clock();

int main() { //????

	//freopen("/yanock/Desktop/storeCredit","r",stdin);
	//freopen("/yanock/Desktop/a1.out","w",stdout);

	ofstream out("../../Desktop/A-large-practice.out");
	ifstream in("../../Desktop/A-large-practice.in");


	if(in)
	{
		int test_case, i, taille_vecteur, j, valeur;
		string ligne;
		in >> test_case;

		for(i = 0; i < test_case; i++)
		{
			int resultat = 0;
			in >> taille_vecteur;
			vector<int> vecteur1, vecteur2;
			for(j = 0; j < taille_vecteur; j++)
			{
				in >> valeur;
				vecteur1.push_back(valeur);
			}
			sort (vecteur1.begin(), vecteur1.end());

			for(j = 0; j < taille_vecteur; j++)
			{
				in >> valeur;
				vecteur2.push_back(valeur);
			}
			sort (vecteur2.begin(), vecteur2.end(), sortGreater);

			cout<<"vecteur 1"<<endl;
			afficheVecteur(vecteur1);
			cout<<"vecteur 2"<<endl;
			afficheVecteur(vecteur2);



			for (size_t parcours2 = 0; parcours2 < taille_vecteur; parcours2++)
			{
				resultat+=vecteur1[parcours2]*vecteur2[parcours2];
			}

			out << "Case #" << i+1 << ": " << resultat <<endl;
			cout << "Case #" << i+1 << ": " << resultat <<endl;
		}

	}
	else
	{
	    cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
	}

	printf("time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}
