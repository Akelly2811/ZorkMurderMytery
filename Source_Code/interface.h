#ifndef INTERFACE_H
#define INTERFACE_H
#include <iostream>
#include <QString>
using namespace std;

class Interface
{
public:
    Interface();
    virtual QString shortDescription() = 0;
    virtual void setLongDescription(QString RoomDescription) = 0;
    virtual QString longDescription() = 0;
};

#endif // INTERFACE_H
