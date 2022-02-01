#include "raylib.h"
#include "BaseCharacter.h"
#include "Character.h"

class Enemy : public BaseCharacter
{
public:
    Enemy(Vector2 Pos, Texture2D idle_tex, Texture2D run_tex);
    virtual void tick(float deltaTime) override;
    void SetTarget(Character *character)
    {
        target = character;
    }
    virtual Vector2 GetScreenPos() override;
    float DoDamage()
    {
        return damagePerSec * GetFrameTime();
    }
private:
    Character *target;
    float damagePerSec{10.f};
};