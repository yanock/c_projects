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

void gererActions(int *actionAll, int *actionCouleur, QStringList listActionsCouleur, QStringList listActionAll, int *avanceCouleur, string couleur, bool* boolAction)
{
	
	//cout << couleur << " " << *actionAll << " " << *actionCouleur << endl;
	
	//si c'est à moi de jouer et si je suis au bon endroit
	if(listActionAll[*actionAll].toStdString() == couleur && listActionsCouleur[*actionCouleur].toInt() == *avanceCouleur && !*boolAction)
	{
		//cout << "play" << couleur <<  endl;
		*actionAll = *actionAll+1;
		*actionCouleur = *actionCouleur+1;
		*boolAction = true;
	}
	//si je ne suis pas encore arrivé au bon endroit	
	else if (listActionsCouleur[*actionCouleur].toInt() != *avanceCouleur)
	{
		//cout << "avance" << couleur <<  endl;
		if(*avanceCouleur<listActionsCouleur[*actionCouleur].toInt())
			*avanceCouleur = *avanceCouleur+1;
		else
			*avanceCouleur = *avanceCouleur-1;
	}
	
	
}

void displayList(QStringList list)
{
	QString str = "";
	for(int l=0;l<list.size(); l++)
		str.append(list[l]);
	cout << str.toStdString() <<endl;
	
}


int main() {

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
		QString  actions = in.readLine();
		

		
		QStringList listActions = actions.split(" ");
		int  nbAction = listActions[0].toInt();
		QStringList listActionsBlue = QStringList(), listActionAll = QStringList(), listActionsOrange = QStringList();

		
		
		for(int j=1;j<nbAction*2; j+=2)
		{
			if(listActions[j] == "O")
				listActionsOrange.append(listActions[j+1]);
			else
				listActionsBlue.append(listActions[j+1]);
				
			listActionAll.append(listActions[j]);
		}
		
		bool continuer = true, boolAction = false;
		
		int compteAction  = 0, actionAll = 0, actionOrange = 0, actionBlue = 0, avanceOrange = 0, avanceBlue = 0;
		
		/*cout << "list : ";
		displayList(listActionAll);
		
		displayList(listActionsOrange);
		displayList(listActionsBlue);
		*/
		
		while(continuer)
		{
			
			//cout<< "B " << listActionsBlue.size() << " " << actionBlue << endl;
			if(listActionAll.indexOf("B")!=-1 && listActionsBlue.size()>actionBlue)
			{
				gererActions(&actionAll, &actionBlue, listActionsBlue, listActionAll, &avanceBlue, "B", &boolAction);
			}
			
			//cout << "O " << listActionsOrange.size() << " " << actionOrange << endl;
			if(listActionAll.indexOf("O")!=-1  && listActionsOrange.size()>actionOrange)	
			{
				gererActions(&actionAll, &actionOrange, listActionsOrange, listActionAll, &avanceOrange, "O", &boolAction);		
			}
			
			compteAction++;
			//cout << compteAction << endl;
			boolAction = false;
			
			
			if((actionOrange == listActionsOrange.size() && actionBlue == listActionsBlue.size()))
				continuer = false;
		}
		
		 
		cout << "Case #"<< i+1 << ": " << compteAction - 1 << endl;

		out << "Case #"<< i+1 << ": " << compteAction - 1 << endl;
	}

	

	printf("time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
	
	
}
