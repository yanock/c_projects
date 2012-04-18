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
		str.append(list[l]+" ");
	cout << ds << " : " << endl;
	cout << str.toStdString() <<endl;
}




int main() {
	
	QString filename = "B-small-practice1";
	//QString filename = "test";
	QFile file(filename+".in");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	 return 0;
	 
	QFile file2(filename+".out");
	if (!file2.open(QIODevice::WriteOnly | QIODevice::Text))
	 return 0;
       
	QTextStream out(&file2);
	QTextStream in(&file);

	QFile file3(filename+".liste");
	if (!file3.open(QIODevice::WriteOnly | QIODevice::Text))
	 return 0;
       
	QTextStream f3(&file3);
	
	int test_case = in.readLine().toInt();

	for(int i=0; i < test_case; i++) //on parcours toute notre liste
	{
		int nbSong = in.readLine().toInt();
		QStringList  songList;
		for(int j=0; j < nbSong; j++) // on crée notre liste
			songList.append(in.readLine().toUpper());
				
		cout << "Case #"<< i+1 << ":" <<  endl;
		out << "Case #"<< i+1 << ":" <<  endl;
		if(nbSong == 1) //si elle est seule
		{
			cout << "\"\"" << endl;
			out << "\"\"" << endl;
		}
		else
		{
			for(int j=0; j < nbSong; j++)  //on cherche le nombre d'occurences possible par chanson
			{
				int tailleSubstr = 1;
				bool ok = true;
				QString mot;
				QStringList result;
				
				while (tailleSubstr <= songList[j].size() && ok)
				{
					for(int l=0; l < songList[j].size()-tailleSubstr+1;l++)
					{
						
						QString sub = songList[j].mid(l, tailleSubstr);
						
						mot = QString();
						mot.append(".*");
						mot.append(sub); //lower
						mot.append(".*");
						
						QRegExp rx(mot);
						bool ajouter = true;
						for(int k = 0; k < nbSong; k++)
						{	
							
							if(songList[k].compare(songList[j]) != 0)
							{
								if(rx.exactMatch(songList[k])) //lower
								{
									//cout << songList[j].toStdString() << " " << songList[k].toStdString() << " " << mot.toStdString() << endl;
									ajouter = false;
								}
							}
							
							
						}
						if(ajouter)
								result.append(sub);

					}
					if(!result.isEmpty())
							ok = false;
					tailleSubstr++;
				}
				
				result.sort();
				if(!result.isEmpty() && result.size()>1)
				{
					cout << endl;
					displayList(result, "result");
					cout << endl;
					
					for(int l=0;l<result.size(); l++)
						f3 << result[l] << endl;
					f3 << endl;
					
				}
				if(!result.isEmpty())
				{
					cout << "\"" << result[0].toUpper().toStdString() <<  "\"" << endl;
					out << "\"" << result[0].toUpper() << "\"" << endl;
				}
				else
				{
					cout << ":(" << endl;
					out << ":(" << endl;
				}
			}
		}
	}

	

	printf("time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}
