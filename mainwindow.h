#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "configfileparser.h"
#include <QStringListModel>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QString testLocation, QString configFile, QWidget *parent = 0);
    ~MainWindow();

public slots:
    void updateUsedSubTestList(int idx);
    void useTest();
    void unUseTest();
    void setDocumentModified();
    void cancel();
signals:
    void configFileChanged();
private:
    Ui::MainWindow *ui;
    ConfigFileParser *pConfigFileParser;
    QStringListModel *pSubTestListModel;
    QStringListModel *pUsedSubTestModel;
    QList<QStringList> filesUsedTestList;
    bool configFileIsModified;
};

#endif // MAINWINDOW_H
