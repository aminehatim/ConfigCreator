/********************************************************************************
** Form generated from reading UI file 'configfileeditor.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGFILEEDITOR_H
#define UI_CONFIGFILEEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfigFileEditor
{
public:
    QLabel *label;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableWidget *extensionTableWidget;
    QWidget *tab_2;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QToolButton *toolButton;

    void setupUi(QDialog *ConfigFileEditor)
    {
        if (ConfigFileEditor->objectName().isEmpty())
            ConfigFileEditor->setObjectName(QStringLiteral("ConfigFileEditor"));
        ConfigFileEditor->resize(618, 408);
        label = new QLabel(ConfigFileEditor);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 80, 111, 16));
        tabWidget = new QTabWidget(ConfigFileEditor);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 140, 601, 251));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        extensionTableWidget = new QTableWidget(tab);
        extensionTableWidget->setObjectName(QStringLiteral("extensionTableWidget"));
        extensionTableWidget->setGeometry(QRect(10, 10, 581, 201));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());
        label_2 = new QLabel(ConfigFileEditor);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 20, 57, 15));
        label_3 = new QLabel(ConfigFileEditor);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 50, 111, 16));
        lineEdit = new QLineEdit(ConfigFileEditor);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(130, 20, 211, 23));
        lineEdit_2 = new QLineEdit(ConfigFileEditor);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(130, 50, 211, 23));
        lineEdit_3 = new QLineEdit(ConfigFileEditor);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(130, 80, 211, 23));
        toolButton = new QToolButton(ConfigFileEditor);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(350, 80, 28, 22));

        retranslateUi(ConfigFileEditor);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ConfigFileEditor);
    } // setupUi

    void retranslateUi(QDialog *ConfigFileEditor)
    {
        ConfigFileEditor->setWindowTitle(QApplication::translate("ConfigFileEditor", "Config Editor", 0));
        label->setText(QApplication::translate("ConfigFileEditor", "Test file Folder : ", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("ConfigFileEditor", "Tab 1", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("ConfigFileEditor", "Tab 2", 0));
        label_2->setText(QApplication::translate("ConfigFileEditor", "Author :", 0));
        label_3->setText(QApplication::translate("ConfigFileEditor", "Creation date : ", 0));
        toolButton->setText(QApplication::translate("ConfigFileEditor", "...", 0));
    } // retranslateUi

};

namespace Ui {
    class ConfigFileEditor: public Ui_ConfigFileEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGFILEEDITOR_H
