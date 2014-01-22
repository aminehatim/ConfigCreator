#include "configfileparser.h"
#include <QFile>
#include <QTextStream>


// GLOBALS
const QString ConfigFileParser::TEST_CONFIG_TAG_NAME                ="testConfig";
const QString ConfigFileParser::AUTHOR_TAG_NAME                     ="author";
const QString ConfigFileParser::CREATION_DATE_TAG_NAME              ="creationDate";
const QString ConfigFileParser::TEST_FILE_FOLDER_TAG_NAME           ="testFilesFolder";
const QString ConfigFileParser::EXTENTIONS_TAG_NAME                 ="extensions";
const QString ConfigFileParser::INPUT_EXTENTION_TAG_NAME            ="input";
const QString ConfigFileParser::EXPECTED_EXTENTION_OUTPUT_TAG_NAME  ="expectedOutput";
const QString ConfigFileParser::DESCRIPTION_EXTENTION_TAG_NAME      ="description";
const QString ConfigFileParser::ARGUMENTS_TAG_NAME                  ="arguments";
const QString ConfigFileParser::HELP_ARG_TAG_NAME                   ="help";
const QString ConfigFileParser::VERBOSE_ARG_TAG_NAME                ="verboseMode";
const QString ConfigFileParser::UPDATE_POSSIBLE_ARG_TAG_NAME        ="updatePossible";
const QString ConfigFileParser::ADD_MODE_ARG_TAG_NAME               ="addMode";
const QString ConfigFileParser::DEV_MODE_ARG_TAG_NAME               ="devMode";
const QString ConfigFileParser::SUB_TEST_TAG_NAME                   ="subTests";
const QString ConfigFileParser::TEST_TAG_NAME                       ="test";
const QString ConfigFileParser::REGED_USED_ARGS_T_TAG_NAME          ="regedUsedArgs";
const QString ConfigFileParser::CMD_USED_ARGS_TAG_NAME              ="cmdUsedArgs";

const QString ConfigFileParser::VERSION_ATTRIBUTE_NAME              ="version";
const QString ConfigFileParser::TEST_BENCH_ATTRIBUTE_NAME           ="testbench";
const QString ConfigFileParser::COMMENT_ATTRIBUTE_NAME              ="comment";
const QString ConfigFileParser::NUMBER_ATTRIBUTE_NAME               ="number";

const QString ConfigFileParser::CONFIG_FILE_EXTENSION               =".Config.xml";



ConfigFileParser::ConfigFileParser(QString testLocation, QString configFile)
{
    this->configFile = configFile;
    testDirectory = QDir(testLocation);

    configDomDoc = QDomDocument("Config");
    QFile file(configFile);
    if (!file.open(QIODevice::ReadOnly))
        return;
    if (!configDomDoc.setContent(&file)) {
        file.close();
        return;
    }
    file.close();
    rootElement = configDomDoc.documentElement();
    testName = configFile.split(".testConfig.xml").at(0);

    getConfigs();

}

QStringList ConfigFileParser::getSubTestList()
{
    return subTestList;
}

QStringList ConfigFileParser::getTestFileList()
{
    // Getting test files
    QStringList fileFilterList;
    fileFilterList <<"*" + inputFileExtension;

    QStringList fileList = testDirectory.entryList(fileFilterList, QDir::Files);
    return fileList;
}

QStringList ConfigFileParser::getUsedSubTestList(QString fileName)
{
    QString tmpName = fileName.split(inputFileExtension).at(0);
    QString descriptionfile = testDirectory.absoluteFilePath(tmpName + descriptionFileExtention);

    DescriptionFileParser descriptionFileParser(descriptionfile);
    return descriptionFileParser.getUsedTestList();

}

QString ConfigFileParser::getTestName()
{
    return testName;

}

QString ConfigFileParser::createNewConfigFile(QString testLocation, QString testName)
{
    // This function will create the defualt config file
    // When adding a new element make sure to add it to getConfigs() function
    // Create a new config file under the testLocationt
    QDomDocument newConfigDomDoc = QDomDocument("ConfigFile");
    // Create root node
    QDomElement rootElement = newConfigDomDoc.createElement(TEST_CONFIG_TAG_NAME);
    newConfigDomDoc.appendChild(rootElement);

    // Create all the childs
    QDomElement authorElement = newConfigDomDoc.createElement(AUTHOR_TAG_NAME);
    rootElement.appendChild(authorElement);

    QDomElement creationDateElement = newConfigDomDoc.createElement(CREATION_DATE_TAG_NAME);
    rootElement.appendChild(creationDateElement);

    QDomElement testFileLocationElement = newConfigDomDoc.createElement(TEST_FILE_FOLDER_TAG_NAME);
    rootElement.appendChild(testFileLocationElement);

    QDomElement extensionElement = newConfigDomDoc.createElement(EXTENTIONS_TAG_NAME);
    QDomElement inputExtensionElement = newConfigDomDoc.createElement(INPUT_EXTENTION_TAG_NAME);
    QDomElement outputExtensionElement = newConfigDomDoc.createElement(EXPECTED_EXTENTION_OUTPUT_TAG_NAME);
    QDomElement descriptionFileExtentionElement = newConfigDomDoc.createElement(DESCRIPTION_EXTENTION_TAG_NAME);
    extensionElement.appendChild(inputExtensionElement);
    extensionElement.appendChild(outputExtensionElement);
    extensionElement.appendChild(descriptionFileExtentionElement);
    rootElement.appendChild(extensionElement);

    QDomElement argumentsElement = newConfigDomDoc.createElement(ARGUMENTS_TAG_NAME);
    QDomElement helpArgElement = newConfigDomDoc.createElement(HELP_ARG_TAG_NAME);
    QDomElement verboseArgElement = newConfigDomDoc.createElement(VERBOSE_ARG_TAG_NAME);
    QDomElement updateArgElement = newConfigDomDoc.createElement(UPDATE_POSSIBLE_ARG_TAG_NAME);
    QDomElement addArgElement = newConfigDomDoc.createElement(ADD_MODE_ARG_TAG_NAME);
    QDomElement devArgsElement = newConfigDomDoc.createElement(DEV_MODE_ARG_TAG_NAME);
    argumentsElement.appendChild(helpArgElement);
    argumentsElement.appendChild(verboseArgElement);
    argumentsElement.appendChild(updateArgElement);
    argumentsElement.appendChild(addArgElement);
    argumentsElement.appendChild(devArgsElement);
    rootElement.appendChild(argumentsElement);

    QDomElement subTestElement= newConfigDomDoc.createElement(SUB_TEST_TAG_NAME);
    rootElement.appendChild(subTestElement);

    // Save the document to the disk
    QDir testLocationDir = QDir(testLocation);
    QString configFilePath = testLocationDir.absoluteFilePath(testName + CONFIG_FILE_EXTENSION);

    QFile newConfigFile (configFilePath);
    newConfigFile.open(QIODevice::WriteOnly);

    QTextStream fileStream(&newConfigFile);
    fileStream << newConfigDomDoc.toString(4);
    newConfigFile.close();

    return configFilePath;

}

void ConfigFileParser::getConfigs()
{
    //Extension
    getExtensions();
    //Arguments


    // sub tests
//    tmpNodeList = rootElement.elementsByTagName(TEST_TAG_NAME);
//    for (int i = 0; i<tmpNodeList.length(); i++){
//        QString testNumber = tmpNodeList.at(i).toElement().attribute(NUMBER_ATTRIBUTE_NAME);
//        subTestList.append("test_"+testNumber);

//        QDomNode regEdArgsNode = tmpNodeList.at(i).firstChild();
//        QDomNode cmdArgsNode = regEdArgsNode.nextSibling();

//        regEdArgList.append(regEdArgsNode.firstChild().nodeValue());
//        cmdArgList.append(cmdArgsNode.firstChild().nodeValue());

//    }



}

QHash<QString, QString> ConfigFileParser::getExtensions(){

    QDomElement extensionsElement = rootElement.firstChildElement(EXTENTIONS_TAG_NAME);
    QDomNodeList extensionNodelist= extensionsElement.childNodes();
    QDomNode extensionNode;

    for (int i = 0; i<extensionNodelist.length(); i++){
        extensionNode = extensionNodelist.at(i);
        // Save it to the hash
        argumentsHash.insert(extensionNode.toElement().tagName(), extensionNode.firstChild().nodeValue());
    }

    return argumentsHash;
}
