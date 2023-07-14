#include "MainLobby.h"

MainLobby::MainLobby(QString inDescription, Item *newItem, Item *newItem2)
    : Room {newItem, newItem2},
      description(inDescription)
{

}

MainLobby::~MainLobby()
{
    vector<Character>().swap(CharactersInRoom);
}

QString MainLobby::shortDescription(){
    return description;
}

void MainLobby::addCharacter(Character *character){
    CharactersInRoom.push_back(*character);
}

void MainLobby::addAnimateObject(AnimateObject *animateObject){
    CharactersInRoom.push_back(*animateObject);
    itemsInRoom.push_back(*animateObject);
}

Character MainLobby::getCharacter(QString name){
    for (int i = 0; i<numberOfCharacters(); i++){
        if (name == CharactersInRoom[i].description)
            return CharactersInRoom[i];
    }
    Character *failsafe = new Character("error");
    return *failsafe;
}


QString MainLobby::displayCharacter() {
    QString tempQString = "Characters in room = ";
    int sizeCharacters = (CharactersInRoom.size());
    if (CharactersInRoom.size() < 1) {
        tempQString = "no Characters in room";
        }
    else if (CharactersInRoom.size() > 0) {
       int x = (0);
        for (int n = sizeCharacters; n > 0; n--) {
            tempQString = tempQString + CharactersInRoom[x].description + "  " ;
            x++;
            }
        }
    return tempQString;
    }

int MainLobby::numberOfCharacters() {
    return CharactersInRoom.size();
}

vector<Character> MainLobby::getCharacterList(){
    return CharactersInRoom;
}
