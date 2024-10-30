#include "SynonymList.h"

SynonymList::SynonymList(const QString& mainWord) : word(mainWord) {}

QVector<QString> SynonymList::getSynonyms() const {
    return synonyms;
}

void SynonymList::addSynonym(const QString &synonym) {
    synonyms.append(synonym);  // Agrega el sinónimo al QVector
}

void SynonymList::removeSynonym(const QString& synonym) {
    synonyms.removeAll(synonym);
}

void SynonymList::clearAll() {
    synonyms.clear();  // Limpia todos los elementos en el QVector
}
