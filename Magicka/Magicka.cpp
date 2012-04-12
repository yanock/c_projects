//============================================================================
// Name        : Magicka.cpp
// Author      : yanock
// Version     :
// Copyright   : Your copyright notice
// Description : Main du projet magicka
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
	QString filename = "B-large-practice";
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
		int indexAll = 0, k = 0;
		QStringList listAll = in.readLine().split(" " );
		QStringList combination = QStringList(), opposition = QStringList(), invocation = QStringList();
		
		k = indexAll;
		
		if(listAll[indexAll].toInt()>0)
		{
			for(int j=0; j<listAll[k].toInt(); j++)
			{
				combination.append(listAll[j+k+1]);
				indexAll++;
			}
		}

		indexAll++;

		k = indexAll;
		
		if(listAll[indexAll].toInt()>0)
		{
			for(int j=0; j<listAll[k].toInt(); j++)
			{
				opposition.append(listAll[j+k+1]);
				indexAll++;
			}
		}
		indexAll++;

		k = indexAll;
		
		invocation.append(listAll[k+1]);
		
		QString result = "";
		//foreach (QString lettre, invocation)
		
		for (int r = 0; r < invocation[0].size(); r++)
		{
			QString tmp  = invocation[0];
			QCharRef lettre = tmp[r];
			bool ok1 = false, ok2 = false;
			if(result.size()>0)
			{
				QString comb, combinv;
				comb.append(result[result.size()-1]);
				comb.append(lettre);
								
				combinv.append(lettre);
				combinv.append(result[result.size()-1]);
				foreach (QString c, combination)
				{
					
					if(c.left(2) == comb || c.left(2) == combinv)
					{
						//cout << "comb : " << comb.toStdString() << " result : " << result.toStdString() << endl;
						ok1 = true;
						//result.append(c[c.size()-1]);
						result[result.size()-1] = c[c.size()-1];
						//cout <<" result : " << result.toStdString() << endl;
					}
				}
				
				if(!ok1)
				{
					foreach (QString o, opposition)
					{
						
						for (int l = 0; l< result.size(); l++)
						{
							QString op, opinv;
							op.append(result[l]);
							op.append(lettre); 
							opinv.append(lettre);
							opinv.append(result[l]);
							if(o.left(2) == op || o.left(2) == opinv)
							{
								//cout << "op : " << op.toStdString() << " result : " << result.toStdString() << endl;
								ok2 = true;
								result = "";
								//cout <<" result : " << result.toStdString() << endl;
								break;
							}
							
						}
					}
				}
				
				if (!ok1 && !ok2)
					result.append(lettre);  // rien ne se passe, on ajoute la lettre
					
				
			}
			else
				result.append(lettre); // debut de traitement, on ajoute la lettre
		}
		//echo
		QString chaine;
		chaine.append("[");
		for (int l = 0; l< result.size(); l++)
			chaine.append(result[l] + ", ");
		chaine = chaine.mid(0, chaine.size()-2);
		chaine.append("]");
		out << "Case #"<< i+1 << ": " << chaine <<  endl;
		cout << "Case #"<< i+1 << ": " << chaine.toStdString() <<  endl;	
	}

	printf("time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}
