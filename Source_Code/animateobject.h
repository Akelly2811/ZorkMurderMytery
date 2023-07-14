#ifndef ANIMATEOBJECT_H
#define ANIMATEOBJECT_H
#include "Character.h"
#include "item.h"

class AnimateObject : public Item, public Character
{
public:
    AnimateObject(QString description);

};

#endif // ANIMATEOBJECT_H
