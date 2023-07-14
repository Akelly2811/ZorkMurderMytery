#ifndef ROOM_H_
#define ROOM_H_
#include "item.h"
#include "interface.h"
#include <map>
#include <QString>
#include <vector>

class Room : public Interface
{
    private:
        QString description;
        QString LongDescription;
        map<string, Room*> exits;
        QString exitString();
        vector <Item> itemsInRoom;
        friend class MainLobby;

    public:
        int numberOfItems();
        Room(QString inDescription);
        Room(QString inDescription, Item *newItem);
        Room(QString inDescription, Item *newItem, Item *newItem2);
        Room(Item *newItem, Item *newItem2);
        Room();
        ~Room();
        bool operator == (const Room& other) const;
        bool operator != (const Room& other) const;
        void setExits(Room *north, Room *east, Room *south, Room *west);
        QString shortDescription();
        QString Add(QString shortDescription, vector <Item> items);
        QString operator+(vector <Item> items);
        void setLongDescription(QString RoomDescription);
        QString longDescription();
        Room* nextRoom(string direction);
        void addValue(Item *inItem);
        QString displayItem();
        int isItemInRoom(QString inQString);
        vector<Item> getItemList();
        void removeItemFromRoom(Item *inItem);
};

#endif
