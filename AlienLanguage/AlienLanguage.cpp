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


using namespace std;

clock_t start=clock();

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

	QStringList  list1 = in.readLine().split(" ");
    int taille_mot = list1[0].toInt();
	int taille_dico = list1[1].toInt();
	int test_case = list1[2].toInt();
	
	//cout << taille_mot << " " << taille_dico << " " << test_case <<endl;
	
	for(int i=0; i < test_case; i++)
	{
		
		QStringList  dico;

		for(i = 0; i < taille_dico; i++)
		{
			dico.append(in.readLine());
		}

		for(i = 0; i < test_case; i++)
		{
			int result = 0;
			QString mot = in.readLine();
			//cout << mot.toStdString()  <<endl;
			mot.replace("(", "[");
			mot.replace(")", "]");
			//cout << mot.toStdString()  <<endl;
			
			QRegExp rx(mot); 
			
			for(int k = 0; k < taille_dico; k++)
			{
				if(rx.indexIn(dico[k]) != -1) 
					result++;
			}
			cout << "Case #"<< i+1 << ": " << result << endl;
			out << "Case #"<< i+1 << ": " << result << endl;
			
			
		}
		
	}


	printf("time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}
