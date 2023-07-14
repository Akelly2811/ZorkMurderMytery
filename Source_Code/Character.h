#ifndef CHARACTER_H_
#define CHARACTER_H_
#include "main.h"
#include <iostream>
#include <QString>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDebug>
using namespace std;
#include <vector>
using std::vector;


class Character {
public:
    //vector < Item > itemsInCharacter;
    //void addItem(Item *item);
    friend class MainLobby;
    Character(QString description);
    QString shortDescription();
    void setLongDescription(QString CharacterDescription);
    QString longDescription();
    QString getDialogue(int choice);
    QString getDialogueLocation();
    void setDialogueLocation(QString location);
    void setCharacterPic(QString location);
    QString getCharacterPic();
private:
    QString description;
    QString LongDescription;
    QString dialogue;
    QString dialogueLocation;
    QString picLocation;
};


#endif /*CHARACTER_H_*/
