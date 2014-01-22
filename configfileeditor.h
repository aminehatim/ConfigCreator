#ifndef CONFIGFILEEDITOR_H
#define CONFIGFILEEDITOR_H

#include <QDialog>
#include <QTableView>
#include <QAbstractTableModel>

#include "configfileparser.h"

namespace Ui {
class ConfigFileEditor;
}

class ConfigFileEditor : public QDialog
{
    Q_OBJECT

public:
    explicit ConfigFileEditor(QString testLocation, QString configFile, QWidget *parent = 0);
    ~ConfigFileEditor();
    void loadTabContent();
    void loadExtensionTab();
    void loadArgumentTab();

private:
    Ui::ConfigFileEditor *ui;
    ConfigFileParser *pConfigFileParser;


};

#endif // CONFIGFILEEDITOR_H
