#ifndef CHARACTER_H
#define CHARACTER_H
#include "raylib.h"
#include "BaseCharacter.h"
class Character : public BaseCharacter
{
public:
    Character(int WinWidth, int WinHeight);
    virtual void tick(float deltaTime) override;
    virtual Vector2 GetScreenPos() override;
    Rectangle GetCollisionRecWeapon()
    {
        return WeaponCollisionRec;
    }
    float GetHealth() const
    {
        return health;
    }
    void GetDamage(float Damage);
private:
    int WindowWidth{};
    int WindowHeight{};
    Texture2D Weapon{LoadTexture("characters/weapon_sword.png")};
    float rotation{};
    Rectangle WeaponCollisionRec{};
    float health{100.f};
};
#endif