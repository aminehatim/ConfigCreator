/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionExit;
    QWidget *centralWidget;
    QListView *subTestListView;
    QListView *usedSubTestListView;
    QPushButton *useSubTestButton;
    QPushButton *removeSubTestButton;
    QComboBox *fileListComboBox;
    QPushButton *cancelButton;
    QPushButton *saveButton;
    QPushButton *infoButton;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuAbout;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(629, 457);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        subTestListView = new QListView(centralWidget);
        subTestListView->setObjectName(QStringLiteral("subTestListView"));
        subTestListView->setGeometry(QRect(20, 50, 260, 300));
        usedSubTestListView = new QListView(centralWidget);
        usedSubTestListView->setObjectName(QStringLiteral("usedSubTestListView"));
        usedSubTestListView->setGeometry(QRect(350, 50, 260, 300));
        useSubTestButton = new QPushButton(centralWidget);
        useSubTestButton->setObjectName(QStringLiteral("useSubTestButton"));
        useSubTestButton->setGeometry(QRect(290, 160, 50, 31));
        removeSubTestButton = new QPushButton(centralWidget);
        removeSubTestButton->setObjectName(QStringLiteral("removeSubTestButton"));
        removeSubTestButton->setGeometry(QRect(290, 190, 51, 31));
        fileListComboBox = new QComboBox(centralWidget);
        fileListComboBox->setObjectName(QStringLiteral("fileListComboBox"));
        fileListComboBox->setGeometry(QRect(350, 30, 221, 22));
        cancelButton = new QPushButton(centralWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(530, 370, 75, 23));
        saveButton = new QPushButton(centralWidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setGeometry(QRect(450, 370, 75, 23));
        infoButton = new QPushButton(centralWidget);
        infoButton->setObjectName(QStringLiteral("infoButton"));
        infoButton->setGeometry(QRect(570, 30, 41, 21));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 629, 20));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setEnabled(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Config Maker v1.0", 0));
        actionNew->setText(QApplication::translate("MainWindow", "New ", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save ", 0));
        actionSave_As->setText(QApplication::translate("MainWindow", "Save As ..", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit ", 0));
#ifndef QT_NO_TOOLTIP
        useSubTestButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Use the selected subTest</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        useSubTestButton->setText(QApplication::translate("MainWindow", ">>", 0));
#ifndef QT_NO_TOOLTIP
        removeSubTestButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Remove subTest</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        removeSubTestButton->setText(QApplication::translate("MainWindow", "<<", 0));
        cancelButton->setText(QApplication::translate("MainWindow", "Cancel ", 0));
        saveButton->setText(QApplication::translate("MainWindow", "Save", 0));
        infoButton->setText(QApplication::translate("MainWindow", "Info", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuAbout->setTitle(QApplication::translate("MainWindow", "About", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
