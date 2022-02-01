#ifndef BASE_CHARACTER_H
#define BASE_CHARACTER_H
#include "raylib.h"

//Parent Class for both Character class and Enemy class
class BaseCharacter
{
public:
    BaseCharacter();
    Rectangle getCollisionRec();
    void UndoMovement();
    Vector2 getworldPos()
    {
        return WorldPos;
    }
    virtual void tick(float deltaTime);

    //Pure Virtual Method ,Makes the class abstract
    virtual Vector2 GetScreenPos() = 0;

    bool IsAlive()
    {
        return Alive;
    }
    void SetAlive(bool IsAlive)
    {
        Alive = IsAlive;
    }
     
    bool IsbuttonPressed()
    {
        return ButtonPressed;
    }
protected:
    Texture2D texture{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D idle{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D run{LoadTexture("characters/knight_run_spritesheet.png")};
    Vector2 WorldPos{140, 400};

    //rightleft is for changing animation to look forward and backward
    float rightleft{1.f};
    float runningtime{0.f};
    float updatetime{1.f / 18.f};
    int frame{};
    int maxframe{6};
    float speed{8.f};
    float width{};
    int scale{4};
    float height{};
    Vector2 WorldPosLastFrame{};
    Vector2 velocity{};
    bool ButtonPressed = false;

private:
    bool Alive = true;
};

#endif