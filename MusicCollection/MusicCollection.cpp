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
	
	QString filename = "test";
	QFile file(filename+".in");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	 return 0;
		QFile file2(filename+".out");
	if (!file2.open(QIODevice::WriteOnly | QIODevice::Text))
	 return 0;
       
	QTextStream out(&file2);
	QTextStream in(&file);

	
	int test_case = in.readLine().toInt();

	for(int i=0; i < test_case; i++) //on parcours toute notre liste
	{
		int nbSong = in.readLine().toInt();
		QStringList  songList;
		for(int j=0; j < nbSong; j++) // on crée notre liste
			songList.append(in.readLine());
		
		cout << "Case #"<< i+1 << ":" <<  endl;
		out << "Case #"<< i+1 << ":" <<  endl;
		
		for(int j=0; j < nbSong; j++)  //on cherche le nombre d'occurences possible par chanson
		{
			int tailleSubstr = 1;
			bool ok = true;
			QString mot;
			QStringList result;
			if(nbSong == 1) //si elle est seule
			{
				cout << "\"\"" << endl;
				out << "\"\"" << endl;
			}
			else
			{
				while (tailleSubstr <songList[j].size() && ok)
				{
					mot = QString();
					mot.append(".*");
					mot.append(".*"); //substr
					mot.append(".*");
					
					QRegExp rx(mot);
					
					for(int k = j+1; k < nbSong; k++)
					{
						if(rx.indexIn(songList[k]) != -1)
							break;
						else
							
						
					}
					if(result == 0)
						ok = false;
					compteur++;
				}
				if(ok)
				{
					cout << "\"" << mot.toStdString() <<  "\"" << endl;
					out << "\"" << mot << "\"" << endl;
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
