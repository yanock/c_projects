//============================================================================
// Name        : base.cpp
// Author      : yanock
// Version     :
// Copyright   : Your copyright notice
// Description : Fichier de base pour le c++
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
#include <time.h>
#include <string>
#undef main

using namespace std;

clock_t start=clock();

void displayList(QStringList list, string ds)
{
	QString str = "";
	for(int l=0;l<list.size(); l++)
		str.append(list[l]);
	cout << ds << " : " << endl;
	cout << str.toStdString() <<endl;
	
}

int main() {

	QString filename = "A-small-practice1";
	QFile file(filename+".in");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	 return 0;
		QFile file2(filename+".out");
	if (!file2.open(QIODevice::WriteOnly | QIODevice::Text))
	 return 0;
       
	QTextStream out(&file2);
	QTextStream in(&file);

	QList<QChar> vowel;
	vowel << 'a' << 'e' << 'i' << 'o' << 'u' ;

	int test_case = in.readLine().toInt();

	for(int i=0; i < test_case; i++)
	{
		QString str = in.readLine(), output;
		
		if((str.at(str.size()-1).toLower()== 'y'))
			output = str+" is ruled by nobody.";
		else if(vowel.indexOf((str.at(str.size()-1)).toLower()) == -1)
			output = str+" is ruled by a king.";
		else
			output = str+" is ruled by a queen.";
		
		
		cout << "Case #"<< i+1 << ": " << output.toStdString() << endl;
		out << "Case #"<< i+1 << ": " << output << endl;
	}

	

	printf("time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}
