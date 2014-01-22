#include "configfileeditor.h"
#include "ui_configfileeditor.h"
#include <QTableWidgetItem>



ConfigFileEditor::ConfigFileEditor(QString testLocation, QString configFile, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfigFileEditor)
{
    ui->setupUi(this);
    pConfigFileParser = new ConfigFileParser(testLocation, configFile);

    ui->lineEdit->setReadOnly(true);
    ui->lineEdit_2->setReadOnly(true);

    // tab content
    loadTabContent();
    

}

ConfigFileEditor::~ConfigFileEditor()
{
    delete ui;
}

void ConfigFileEditor::loadTabContent()
{
    ui->tabWidget->setTabEnabled(0, true);
    // Load extension tab
    loadExtensionTab();

    // Load argument tab
    loadArgumentTab();

}

void ConfigFileEditor::loadExtensionTab()
{
    ui->tabWidget->setTabText(0, "Extension");
    ui->extensionTableWidget->setColumnCount(2);
    QStringList headerLabelsList;
    headerLabelsList << "Extension" << "Value";
    ui->extensionTableWidget->setHorizontalHeaderLabels(headerLabelsList);
    QHash<QString, QString> extensionHash = pConfigFileParser->getExtensions();
    QStringList extensionHashKeyList = extensionHash.keys();
    // Populate the tabel
    QString key;
    int row = 0;
    foreach(key, extensionHashKeyList){
        // Column 0
        QTableWidgetItem *newItem = new QTableWidgetItem (key);
        ui->extensionTableWidget->insertRow(row);
        ui->extensionTableWidget->setItem(row,0, newItem);
        // Column 1
        QString value = extensionHash.value(key);
        newItem = new QTableWidgetItem (value);
        ui->extensionTableWidget->setItem(row,1, newItem);
        row++;
    }
}

void ConfigFileEditor::loadArgumentTab()
{

}
