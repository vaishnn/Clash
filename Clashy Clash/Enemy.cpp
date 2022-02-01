#include "Enemy.h"
#include "raymath.h"
#include "collisions.h"

Enemy::Enemy(Vector2 Pos, Texture2D idle_tex, Texture2D run_tex)
{
    WorldPos = Pos;
    idle = idle_tex;
    run = run_tex;
    texture = idle_tex;
    width = texture.width / maxframe;
    height = texture.height;
    speed = 5.f;
}

//returns the Rectangle Coordinates and properties

void Enemy::tick(float deltaTime)
{
    if (!IsAlive())
        return;
    //Psedo Code
    //First direction to the knight from enemy is needed
    //then  normalization of direction vector
    velocity = Vector2Subtract(target->GetScreenPos(), GetScreenPos());
    //then scaling the vector
    //then moving enemy

    BaseCharacter::tick(deltaTime);
}

Vector2 Enemy::GetScreenPos()
{
    Vector2 Mddle = Vector2Subtract(WorldPos, target->getworldPos());
    return Vector2Add(Mddle, {1000, 1000});
}