#include "sentenceprocessor.h"

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

#include <QEventLoop>

const QString SentenceProcessor::OXFORD_DICTIONARY_API_URL = "https://od-api.oxforddictionaries.com:443/api/v2/entries/en-us/";
const char *SentenceProcessor::OXFORD_DICTIONARY_API_APP_ID = "872a1554";
const char *SentenceProcessor::OXFORD_DICTIONARY_API_APP_KEY = "8f9ae1ee5a5f302b96dfb69f5be55751";

SentenceProcessor::SentenceProcessor(QObject *parent)
    : QObject(parent),
      manager(new QNetworkAccessManager)
{}

SentenceProcessor::~SentenceProcessor()
{
    delete manager;
}

void SentenceProcessor::initialize(const QString& s)
{
    input_sentence = s;
    process();
}

void SentenceProcessor::process()
{
    split_input_sentence();
    query_word_list();
    form_final_sentence();
}

const QString& SentenceProcessor::get_input() const
{
    return input_sentence;
}

const QString& SentenceProcessor::get_result() const
{
    return result_sentence;
}

void SentenceProcessor::split_input_sentence()
{
    for (auto& a : input_sentence.split(' ')) {
        word_list.push_back(a.toLower());
    }
}

void SentenceProcessor::query_word_list()
{
   //
}

void SentenceProcessor::form_final_sentence()
{
    QString result("");

    for (auto& a : input_sentence.split(' ')) {
        result += " ";
        if (word_result_map[a.toLower()] == QueryResult::SWEAR_WORD_NEGATIVE) {
            result += a;
        } else {
            result += QString(a.length(), '*');
        }
    }

    result_sentence = result;
}
