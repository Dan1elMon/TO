#ifndef SYNONYMLIST_H
#define SYNONYMLIST_H

#include <QString>
#include <QVector>

class SynonymList {
public:
    explicit SynonymList(const QString& mainWord);
    QVector<QString> getSynonyms() const;
    void addSynonym(const QString& synonym);
    void removeSynonym(const QString& synonym);
    void clearAll();  // Nueva función para vaciar la lista

private:
    QString word;
    QVector<QString> synonyms;
};

#endif // SYNONYMLIST_H
