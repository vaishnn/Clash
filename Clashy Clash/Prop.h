#include "raylib.h"

class Prop
{
public:
    Prop(Vector2 pos, Texture2D tex);
    void Render(Vector2 KnightPos);
    Rectangle getCollisionRec(Vector2 KnightPos);

private:
    Texture2D texture{};
    Vector2 WorldPos{};
    float scale{4.f};
};