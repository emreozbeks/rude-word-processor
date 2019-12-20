#ifndef SENTENCEPROCESSOR_H
#define SENTENCEPROCESSOR_H

#include <QObject>
#include <QString>
#include <QMap>
#include <QNetworkAccessManager>

class SentenceProcessor : public QObject
{
    Q_OBJECT
public:
    explicit SentenceProcessor(QObject *parent = nullptr);
    ~SentenceProcessor();

    // Clean data inside object
    void initialize(const QString& s);
    // Form resultant sentence
    void process();

    const QString& get_input() const;
    const QString& get_result() const;

signals:

private:
    enum QueryResult {
        SWEAR_WORD_NEGATIVE,
        SWEAR_WORD_POSITIVE
    };

    QNetworkAccessManager *manager;

    QString input_sentence;
    QString result_sentence;
    QStringList word_list;

    QMap<QString, QueryResult> word_result_map;

    static const QString OXFORD_DICTIONARY_API_URL;
    static const char *OXFORD_DICTIONARY_API_APP_ID;
    static const char *OXFORD_DICTIONARY_API_APP_KEY;

    void split_input_sentence();
    void query_word_list();
    void form_final_sentence();
};

#endif // SENTENCEPROCESSOR_H
