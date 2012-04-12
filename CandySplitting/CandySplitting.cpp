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
#include <string>
#include <time.h>
#undef main

using namespace std;

clock_t start=clock();

void displayList(QStringList list, string ds)
{
	QString str = "";
	foreach (QString qstr, list)
		str.append(qstr + " ");

	cout << ds << " : ";	
	cout << str.toStdString() <<endl;
	
}

int main()
{
	QString filename = "C-large-practice";
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
		QString output;
		bool ok;
		int resultxor = 0, result = 0;
		
		int nbCandies = in.readLine().toInt();
		QStringList  candies = in.readLine().split(" ");
		
		QList<int> list;
		for (int j = 0; j < candies.size() ; j++) 
             list.append(candies[j].toInt());
		
		foreach (int candie, list)
		{
			resultxor^=candie;
			result+=candie;
		}
		cout << result << " " << resultxor << endl;
		
		if (resultxor > 0 )
			output.append("NO");
		else
		{
			qSort(list.begin(), list.end(), qLess<int>());
			result -= list[0];
			output = QString::number(result);
		}
		
		cout << "Case #"<< i+1 << ": " << output.toStdString() <<  endl;
		out << "Case #"<< i+1 << ": " << output <<endl;
	}

	

	printf("time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}
