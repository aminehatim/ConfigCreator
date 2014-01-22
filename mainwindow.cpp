#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>


MainWindow::MainWindow(QString testLocation, QString configFile, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pConfigFileParser = new ConfigFileParser(testLocation, configFile);
    ui->statusBar->showMessage(configFile);

    // File list
    ui->fileListComboBox->addItems(pConfigFileParser->getTestFileList());
    QString file;
    foreach (file, pConfigFileParser->getTestFileList()) {
       filesUsedTestList.append(pConfigFileParser->getUsedSubTestList(file));
    }

    // Sub Test content
    pSubTestListModel = new QStringListModel(pConfigFileParser->getSubTestList());
    ui->subTestListView->setModel(pSubTestListModel);
    ui->subTestListView->setEditTriggers(QAbstractItemView::NoEditTriggers);


    pUsedSubTestModel = new QStringListModel(filesUsedTestList.at(ui->fileListComboBox->currentIndex()));
    ui->usedSubTestListView->setModel(pUsedSubTestModel);
    ui->usedSubTestListView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Connections
    connect(ui->fileListComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(updateUsedSubTestList(int)));
    connect(ui->useSubTestButton, SIGNAL(clicked()), this, SLOT(useTest()));
    connect(ui->removeSubTestButton, SIGNAL(clicked()), this, SLOT(unUseTest()));
    connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(cancel()));

    connect(this, SIGNAL(configFileChanged()), this, SLOT(setDocumentModified()));

    configFileIsModified = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Slots
void MainWindow::updateUsedSubTestList(int idx){
    pUsedSubTestModel->setStringList(filesUsedTestList.at(idx));
}

void MainWindow::useTest()
{
    // Add from the view
    int testIdx = ui->subTestListView->currentIndex().row();
    QString newTestName = pConfigFileParser->getSubTestList().at(testIdx);
    QStringList tmp = filesUsedTestList.at(ui->fileListComboBox->currentIndex());
    tmp.append(newTestName);
    filesUsedTestList.removeAt(ui->fileListComboBox->currentIndex());
    filesUsedTestList.insert(ui->fileListComboBox->currentIndex(), tmp);
    int lastIdx = pUsedSubTestModel->rowCount();
    pUsedSubTestModel->insertRows(lastIdx, 1);
    pUsedSubTestModel->setData( pUsedSubTestModel->index(pUsedSubTestModel->rowCount()-1), newTestName);

    emit configFileChanged();
}

void MainWindow::unUseTest()
{
    // Remove from the view
    int testIdx = ui->usedSubTestListView->currentIndex().row();
    pUsedSubTestModel->removeRow(testIdx);
    QStringList tmp = filesUsedTestList.at(ui->fileListComboBox->currentIndex());
    tmp.removeAt(testIdx);
    filesUsedTestList.removeAt(ui->fileListComboBox->currentIndex());
    filesUsedTestList.insert(ui->fileListComboBox->currentIndex(), tmp);

    emit configFileChanged();
}

void MainWindow::setDocumentModified()
{
    configFileIsModified = true;
}

void MainWindow::cancel()
{
    if (configFileIsModified) {
        int retValue = QMessageBox::warning(this, "Warning", "Do you want to discard the changes ?", QMessageBox::Ok, QMessageBox::Cancel);
        if (retValue == QMessageBox::Accepted){
            close();
        }

    }
}
