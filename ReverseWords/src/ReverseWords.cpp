//============================================================================
// Name        : StoreCredit.cpp
// Author      : yanock
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iterator>
#include <sstream>


using namespace std;

clock_t start=clock();
std::vector<std::string> string_split(const std::string &s, char delim);
std::vector<std::string> &string_split(const std::string &s, char delim, std::vector<std::string> &elems);


std::vector<std::string> &string_split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while(std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::string> string_split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    return string_split(s, delim, elems);
}


int main() {

	//freopen("/yanock/Desktop/storeCredit","r",stdin);
	//freopen("/yanock/Desktop/a1.out","w",stdout);

	ofstream out("../../Desktop/B-large-practice.out");
	ifstream in("../../Desktop/B-large-practice.in");


	if(in)
	{
		int test_case, i;
		size_t j;
		string ligne;
		in >> test_case;
		getline(in, ligne); //get fin de ligne
		for(i = 0; i < test_case; i++)
		{
			getline(in, ligne);
			vector<string> mots;
			mots = string_split(ligne, ' ');

			cout << "Case #" << i+1 << ": ";
			out << "Case #" << i+1 << ": ";
			for (j = mots.size(); j > 0; j--)

			{
				out << mots[j-1] << " ";
				cout << mots[j-1] << " ";
			}
			out.seekp(-1, ios::cur);
			out<<endl;
			cout<<endl;

		}


	}
	else
	{
	    cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
	}

	printf("time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}
