#include "mainwindow.h"
#include <QApplication>
#include <QString>
#include <QTextStream>
#include <QFile>
#include <QDir>
#include <QStringList>

#include "configfileparser.h"
#include "configfileeditor.h"

// Function declaration
QStringList getArgumentList(int argc, char*argv[]);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextStream out(stdout);

    // Put all the argument into a stringList (avoid conversion issues)
    QStringList argumentList = getArgumentList(argc, argv);
    int argumentCount = argumentList.size();

    //Parse the arguments
    QString configFilePath, testLocation;

    // New option
    if (argumentList.at(0) ==  "-n") {
        if (argumentCount != 3) {
            out << "Missing arguments!"<< endl ;
            out << "Usage configMaker.exe -n testLocation testBenchName" << endl;
        }

      testLocation = argv[2];
      QDir testDir = QDir(testLocation);
      if (!testDir.exists()) {
          out << testLocation + " does not exits" << endl;
          out << "Usage configMaker.exe -n testLocation testBenchName" << endl;
          return 1;
      }
      QString testBenchName = argv[3];

     //configFilePath = ConfigFileParser::createNewConfigFile(testLocation, testBenchName);
     QDir testLocationDir = QDir(testLocation);
     QString configFilePath = testLocationDir.absoluteFilePath(testBenchName + ".Config.xml");

     ConfigFileEditor configFileEditor(testLocation, configFilePath);
     configFileEditor.exec();
    }

    if (argc == 3){
        // Get test loation
        testLocation = argv[1];
        // Get the Test Name
        configFilePath = argv[2];
        // verify file exitance
        QFile configFile(configFilePath);
        if (!configFile.exists()){
            out << "Couldn't find " + configFilePath << endl;
            out << "Usage ConfigMaker.exe testLocation testName"<<endl;
          //  return 1;
        }
    }
    else {
        // Error
        out << "Missing argument!"<<endl;
        out << "Usage ConfigMaker.exe testLocation testName"<<endl;
       // return 1;
    }



    MainWindow mainWindow(testLocation, configFilePath);
    mainWindow.show();

    return a.exec();
}


QStringList getArgumentList(int argc, char *argv[]){
    QStringList argumentList;
    // We just add arguments
    for(int i=1; i<argc; i++){
        argumentList.append(argv[i]);
    }
    return argumentList;
}
