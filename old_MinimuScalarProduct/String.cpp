/*
 * String.cpp
 *
 *  Created on: Mar 31, 2012
 *      Author: yanock
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <sstream>
#include "String.h"
using namespace std;

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while(std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    return split(s, delim, elems);
}

void afficheVecteur(vector<int> v)
{
	for (size_t taille = 0; taille < v.size(); taille++)
	{
		cout << v[taille] << " " ;
	}
	cout << endl;
}

bool sortGreater (int i,int j) { return (i>j); }


