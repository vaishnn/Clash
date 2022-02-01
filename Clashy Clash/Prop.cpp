#include "Prop.h"
#include "raymath.h"
Prop::Prop(Vector2 pos, Texture2D tex) : WorldPos(pos),
                                         texture(tex)
{
}
//Prop Creation
void Prop::Render(Vector2 KnightPos)
{
    Vector2 screenPos = Vector2Subtract(WorldPos, KnightPos);
    DrawTextureEx(texture, screenPos, 0.f, scale, WHITE);
}

//Gives prop rectangle position and properties
Rectangle Prop::getCollisionRec(Vector2 KnightPos)
{
    Vector2 screenPos = Vector2Subtract(WorldPos, KnightPos);
    return Rectangle{
        screenPos.x,
        screenPos.y,
        (float)texture.width * scale,
        (float)texture.height * scale};
}