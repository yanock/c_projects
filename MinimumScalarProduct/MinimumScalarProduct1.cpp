//============================================================================
// Name        : StoreCredit.cpp
// Author      : yanock
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QString>
#include <QStringList>
#include <QMessageBox>
#include <QDebug>
#include <QByteArray>
#include <QList>
#include "BigIntegerLibrary.hh"

using namespace std;


int main() {
	//freopen("/yanock/Desktop/storeCredit","r",stdin);
	//freopen("/yanock/Desktop/a1.out","w",stdout);
	QString filename = "A-large-practice";
     QFile file(filename+".in");
     if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
         return 0;
 	QFile file2(filename+".out");
     if (!file2.open(QIODevice::WriteOnly | QIODevice::Text))
         return 0;
       
	QTextStream out(&file2);
	QTextStream in(&file);
	


     int test_case = in.readLine().toInt();
	 

	for(int i=0; i < test_case; i++)
	{
		BigInteger result(0);
		int taille_vecteur = in.readLine().toInt();
		QList<int> vecteur1;
		QList<int> vecteur2;
		QStringList  list1 = in.readLine().split(" ");
		QStringList  list2 = in.readLine().split(" ");
		
		for (int j = 0; j < taille_vecteur; j++) 
		{
             vecteur1.append(list1[j].toInt());
             vecteur2.append(list2[j].toInt());
		}
		
		qSort(vecteur1.begin(), vecteur1.end(), qGreater<int>());
		qSort(vecteur2.begin(), vecteur2.end(), qLess<int>());
		
		
		for (int j = 0; j < taille_vecteur; j++) 
		{
            BigInteger a(vecteur1[j]);
			BigInteger b(vecteur2[j]);
			out << vecteur1[j] << " " << vecteur2[j] << endl;
			result+=a*b;
		}
			BigInteger f(0);
			string s2 = bigIntegerToString(result);
			cout << "Case #"<< i+1 << ": " << result << endl;
			out << "Case #"<< i+1 << ": " << s2.c_str() << endl;

	}

 

	 


	return 0;
}
