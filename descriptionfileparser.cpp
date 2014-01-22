#include "descriptionfileparser.h"
#include <QFile>


const QString DescriptionFileParser::TEST_DESCRIPTION_TAG_NAME          ="testDescription";
const QString DescriptionFileParser::AUTHOR_TAG_NAME                    ="author";
const QString DescriptionFileParser::RELATED_BUG_TAG_NAME               ="relatedBug";
const QString DescriptionFileParser::CREATION_DATE_TAG_NAME             ="creationDate";
const QString DescriptionFileParser::TEST_TAG_NAME                      ="test";
const QString DescriptionFileParser::EXECTIME_TAG_NAME                  ="execTime";
const QString DescriptionFileParser::REGED_EXECTIME_TAG_NAME            ="reged";
const QString DescriptionFileParser::CMD_EXECTIMET_TAG_NAME             ="cmd";

const QString DescriptionFileParser::VERSION_ATTRIBUTE_NAME              ="version";
const QString DescriptionFileParser::TEST_BENCH_ATTRIBUTE_NAME           ="testbench";
const QString DescriptionFileParser::COMMENT_ATTRIBUTE_NAME              ="comment";
const QString DescriptionFileParser::NUMBER_ATTRIBUTE_NAME               ="number";


DescriptionFileParser::DescriptionFileParser(QString descriptionFileName)
{
    this->descriptionFile = descriptionFileName;

    descriptionDomDoc = QDomDocument("Description");
    QFile file(descriptionFileName);
    if (!file.open(QIODevice::ReadOnly))
        return;
    if (!descriptionDomDoc.setContent(&file)) {
        file.close();
        return;
    }
    file.close();

    rootElement = descriptionDomDoc.documentElement();

    getDescription();

}

QStringList DescriptionFileParser::getUsedTestList()
{
    return usedSubTest;
}

void DescriptionFileParser::getDescription()
{
    QDomNodeList tmpNodeList;

    // sub tests
    tmpNodeList = rootElement.elementsByTagName(TEST_TAG_NAME);
    for (int i = 0; i<tmpNodeList.length(); i++){
        QString testNumber = tmpNodeList.at(i).toElement().attribute(NUMBER_ATTRIBUTE_NAME);
        usedSubTest.append("test_"+testNumber);
    }


}
