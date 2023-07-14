#include "Character.h"

Character::Character(QString inDescription)
    : description(inDescription)
{
}

QString Character::shortDescription(){
    return description;
}

void Character::setLongDescription(QString CharacterDescription)
{
    LongDescription = CharacterDescription;
}

QString Character::longDescription(){
    return LongDescription;
}


void Character::setDialogueLocation(QString location){
    dialogueLocation = location;
}

QString Character::getDialogueLocation(){
    return dialogueLocation;
}

QString Character::getDialogue(int choice){
    QFile file(dialogueLocation);
    QTextStream stream(&file);
    int line = 0;
    if(file.open(QIODevice::ReadOnly))
        while(!stream.atEnd()) {
            if(line == choice)
                dialogue = stream.readLine();
            else
                stream.readLine();
            line++;
        }
    return dialogue;
}

void Character::setCharacterPic(QString location){
    picLocation = location;
}

QString Character::getCharacterPic(){
    return picLocation;
}



