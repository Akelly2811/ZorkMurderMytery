#ifndef ITEM_H_
#define ITEM_H_
#include "interface.h"
#include <map>
#include <QString>
#include <iostream>
using namespace std;

class Item : Interface {
private:
    QString description;
    QString LongItemDescription;
    QString Examination;
    int weightGrams : 15;
    float value;
    friend class Room;

public:
    Item (QString description, int inWeight, float inValue);
    Item (QString description);
    Item();
    Item (const Item& other);
    QString shortDescription();
    void setLongDescription(QString ItemDescription);
    QString longDescription();
    bool operator < (const Item& other) const;
    bool operator > (const Item& other) const;
    bool operator == (const QString& other) const;
    bool operator != (const QString& other) const;
    void setExamination(QString examinationString);
    QString getExamination();
    int getWeight();
    void setWeight(int weightKG);
    float getValue();
    void setValue(float value);


};

#endif /*ITEM_H_*/
