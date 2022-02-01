#include "Character.h"
#include "raymath.h"

Character::Character(int WinWidth, int WinHeight) : WindowWidth(WinWidth),
                                                    WindowHeight(WinHeight)
{
    width = texture.width / maxframe;
    height = texture.height;
}

void Character::tick(float deltaTime)
{

    //Movement By Keyboard
    if (IsKeyDown(KEY_A))
        velocity.x -= 20.f;
    if (IsKeyDown(KEY_D))
        velocity.x += 20.f;
    if (IsKeyDown(KEY_S))
        velocity.y += 20.f;
    if (IsKeyDown(KEY_W))
        velocity.y -= 20.f;

    //Boundry Conditions
    if (WorldPos.x < 140 || WorldPos.y < 400 || WorldPos.x + 4 * width > 5690 || WorldPos.y + 4 * height > 2830)
        UndoMovement();
    BaseCharacter::tick(deltaTime);

    Vector2 Origin{};
    int Factor{};
    if (rightleft > 0.f)
        Origin = {0.f, static_cast<float>(Weapon.width * scale / 1.5f)};
    else
    {
        Origin = {Weapon.width * scale / 1.5f, Weapon.height * scale / 1.5f};
        Factor = 1;
    }
    //Drawing the sword
    Rectangle SwordSource{0.f, 0.f, static_cast<float>(Weapon.width) * rightleft, static_cast<float>(Weapon.height)};
    Rectangle SwordDest{GetScreenPos().x + (float)(Weapon.width) * scale / 1.8f,
                        GetScreenPos().y + (float)(Weapon.height) * scale / 1.5f,
                        static_cast<float>(Weapon.width) * scale / 1.5f,
                        static_cast<float>(Weapon.height) * scale / 1.5f};

    rotation = 0.f;
    if (rightleft < 0.f)
        SwordDest.x = GetScreenPos().x + (float)(Weapon.width) * scale / 1.8f;
    if (IsKeyDown(KEY_Q) || IsMouseButtonDown(MOUSE_BUTTON_LEFT))
    {
        rotation = 40.f * rightleft;
        ButtonPressed = true;
    }
    WeaponCollisionRec = {GetScreenPos().x + (float)(Weapon.width) * scale / 1.8f - (float)(Weapon.width) * scale / 1.5f * Factor,
                          GetScreenPos().y,
                          static_cast<float>(Weapon.width) * scale / 1.5f,
                          static_cast<float>(Weapon.height) * scale / 1.5f};
    DrawTexturePro(Weapon, SwordSource, SwordDest, Origin, rotation, WHITE);
}

//Returns Screen Pos Of our Character
Vector2 Character::GetScreenPos()
{
    return Vector2{static_cast<float>(WindowWidth) / 2.0f - 4.0f * static_cast<float>(width) / 2.0f,
                   static_cast<float>(WindowHeight) / 2.0f - 4.0f * static_cast<float>(height) / 2.0f};
}

//Damage by Goblins oohoo they are evil lol

void Character::GetDamage(float GetDamage)
{
    health -= GetDamage;
    if (health <= 0)
        SetAlive(false);
}