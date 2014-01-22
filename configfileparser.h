#ifndef CONFIGFILEPARSER_H
#define CONFIGFILEPARSER_H
#include <QDomDocument>
#include <QStringList>
#include <QDir>
#include <QHash>


#include "descriptionfileparser.h"

class ConfigFileParser
{
public:
    // Globals
    static const QString TEST_CONFIG_TAG_NAME;
    static const QString AUTHOR_TAG_NAME;
    static const QString CREATION_DATE_TAG_NAME;
    static const QString TEST_FILE_FOLDER_TAG_NAME;
    static const QString EXTENTIONS_TAG_NAME;
    static const QString INPUT_EXTENTION_TAG_NAME;
    static const QString EXPECTED_EXTENTION_OUTPUT_TAG_NAME;
    static const QString DESCRIPTION_EXTENTION_TAG_NAME;
    static const QString ARGUMENTS_TAG_NAME;
    static const QString HELP_ARG_TAG_NAME;
    static const QString VERBOSE_ARG_TAG_NAME;
    static const QString UPDATE_POSSIBLE_ARG_TAG_NAME;
    static const QString ADD_MODE_ARG_TAG_NAME;
    static const QString DEV_MODE_ARG_TAG_NAME;
    static const QString SUB_TEST_TAG_NAME;
    static const QString TEST_TAG_NAME;
    static const QString REGED_USED_ARGS_T_TAG_NAME;
    static const QString CMD_USED_ARGS_TAG_NAME;
    static const QString VERSION_ATTRIBUTE_NAME;
    static const QString TEST_BENCH_ATTRIBUTE_NAME;
    static const QString COMMENT_ATTRIBUTE_NAME;
    static const QString NUMBER_ATTRIBUTE_NAME;

    static const QString CONFIG_FILE_EXTENSION;


    ConfigFileParser(QString testLocation,  QString configFile);
    QStringList getSubTestList();
    QStringList getTestFileList();
    QStringList getUsedSubTestList(QString fileName);
    QString getTestName();

    static QString createNewConfigFile(QString testLocation, QString testName);
    QHash<QString, QString> getExtensions();

private :
    void getConfigs();


    QDomDocument configDomDoc;
    QDomElement rootElement;
    QString inputFileExtension;
    QString descriptionFileExtention;
    QString outputFileExtension;
    QString testFileLocation;
    QString configFile;
    QDir testDirectory;
    QString testName;
    QStringList subTestList;
    QStringList regEdArgList;
    QStringList cmdArgList;
    QHash<QString, QString> extensionsHash;
    QHash<QString, QString> argumentsHash;



};

#endif // CONFIGFILEPARSER_H
