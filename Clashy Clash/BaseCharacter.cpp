#include "BaseCharacter.h"
#include "raymath.h"

BaseCharacter::BaseCharacter()
{
}

//Undoes Movement As Name Suggests
void BaseCharacter::UndoMovement()
{
    WorldPos = WorldPosLastFrame;
}

//Returns the Rectangle Properties like position and width and height 
Rectangle BaseCharacter::getCollisionRec()
{
    return Rectangle{
        GetScreenPos().x,
        GetScreenPos().y,
        width * (float)scale,
        height * (float)scale};
}
void BaseCharacter::tick(float deltaTime)
{
    if (!IsAlive())
        return;

    WorldPosLastFrame = WorldPos;

    if (Vector2Length(velocity) != 0.0)
    {
        //World Pos = World Pos +velocity
        WorldPos = Vector2Add(WorldPos, Vector2Scale(Vector2Normalize(velocity), speed));
        if (velocity.x < 0.f)
            rightleft = -1.f;
        else
            rightleft = 1.f;
        texture = run;
    }
    else
        texture = idle;
    velocity={};
    Rectangle Source;
    Source.height = height;
    Source.width = rightleft * width;
    Source.x = static_cast<float>(width) * static_cast<float>(frame);
    Source.y = 0;

    //On Screen
    Rectangle sec;
    sec.height = 4 * height;
    sec.width = 4 * width;
    sec.x = GetScreenPos().x;
    sec.y = GetScreenPos().y;
    //Drawing Rectangle
    DrawTexturePro(texture, Source, sec, {0.f, 0.f}, 0.0f, WHITE);
    //running time Evaluation
    runningtime += deltaTime;
    //animation factor
    if (runningtime > updatetime)
    {
        runningtime = 0.f;
        frame++;
        if (frame >= maxframe)
            frame = 0;
    }
}
