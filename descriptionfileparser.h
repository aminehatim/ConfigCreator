#ifndef DESCRIPTIONFILEPARSER_H
#define DESCRIPTIONFILEPARSER_H

#include <QDomDocument>
#include <QStringList>
#include <QDir>

class DescriptionFileParser
{
public:
    //Gloabls
    static const QString TEST_DESCRIPTION_TAG_NAME;
    static const QString AUTHOR_TAG_NAME;
    static const QString CREATION_DATE_TAG_NAME;
    static const QString TEST_TAG_NAME;
    static const QString EXECTIME_TAG_NAME;
    static const QString REGED_EXECTIME_TAG_NAME;
    static const QString CMD_EXECTIMET_TAG_NAME;
    static const QString RELATED_BUG_TAG_NAME;
    static const QString VERSION_ATTRIBUTE_NAME;
    static const QString TEST_BENCH_ATTRIBUTE_NAME;
    static const QString COMMENT_ATTRIBUTE_NAME;
    static const QString NUMBER_ATTRIBUTE_NAME;


    DescriptionFileParser(QString descriptionFileName);
    QStringList getUsedTestList();
    void useSubTest(int subTestIndex);
    void removeSubTest(int subTestIndex);


private:
    void getDescription();
    QString descriptionFile;
    QDomDocument descriptionDomDoc;
    QDomElement rootElement;
    QStringList usedSubTest;
    };

#endif // DESCRIPTIONFILEPARSER_H
