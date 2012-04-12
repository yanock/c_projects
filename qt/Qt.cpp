/*
#include <QApplication>
#include <QPushButton>

 int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);

     QPushButton hello("Hello world!");
     hello.resize(100, 30);

     hello.show();
     return app.exec();
 }

 #include <QApplication>
 #include <QTimer>
 
 int main(int argc, char *argv[])
{
        QCoreApplication a(argc, argv); 

        //Put your application code here

        //This line shouldn't be reached until the application is quitting
        QTimer::singleShot(0, &a, SLOT(quit()));
        return a.exec();
}
*/
#define QT3_SUPPORT
#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QLabel *label = new QLabel("Linux is wonderful", 0);
	app.setMainWidget(label);
	label->show();
	return app.exec();
}
