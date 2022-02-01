#include "collisions.h"
#include "raylib.h"

//Checking for Collision with Prop
bool collisions::CollisionOccured(Rectangle knight, Rectangle Prop)
{
    if ((knight.x + knight.width >= Prop.x &&
         knight.x <= Prop.x + Prop.width) &&
        (knight.y + knight.height >= Prop.y &&
         knight.y <= Prop.y + Prop.height))
    {
        //Collision Has Occured
        return true;
    }
    else
        return false;
}