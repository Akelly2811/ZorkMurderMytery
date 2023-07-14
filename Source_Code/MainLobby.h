#ifndef MAINLOBBY_H
#define MAINLOBBY_H
#include "Room.h"
#include "animateobject.h"

class MainLobby : public Room
{
    private:
        QString description;
        map<string, Room*> exits;
        QString exitString();
        vector <Character> CharactersInRoom;
        friend class mainwindow;

    public:
        MainLobby(QString description, Item *newItem, Item *newItem2);
        ~MainLobby();
        QString shortDescription() override;
        void addCharacter(Character *character);
        void addAnimateObject(AnimateObject *animateObject);
        Character getCharacter(QString name);
        QString displayCharacter();
        int isCharacterInRoom(QString inQString);
        vector<Character> getCharacterList();
        int numberOfCharacters();

};

#endif // MAINLOBBY_H
