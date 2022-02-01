#include "raylib.h"
#include "raymath.h"
#include "Prop.h"
#include "Character.h"
#include "collisions.h"
#include "Enemy.h"
#include <string>

//Documentation is very important
int main()
{

    //window dimensions : the Game Resolution
    int WindowDim[2] = {1920, 1080};
    InitWindow(WindowDim[0], WindowDim[1], "Clashy Clash");
    Texture2D Back = LoadTexture("textures/1st.png");

    //Object of character Class
    Character knight{WindowDim[0], WindowDim[1]};

    //Position of Map(Initial)
    Vector2 MapPos{100, 100};
    Texture2D Begin{LoadTexture("characters/0.png")};

    //Change Var is for Changing this Variable for all the time
    int ChangeVar{};

    //array of Props , Because declaring them one by one is stupid
    Prop props[6]{
        Prop{{2000, 1000}, LoadTexture("textures/Rock.png")},
        Prop{{1500, 1300}, LoadTexture("textures/Rock.png")},
        Prop{{4000, 2000}, LoadTexture("textures/Sign.png")},
        Prop{{2100, 1500}, LoadTexture("textures/Log.png")},
        Prop{{2500, 2500}, LoadTexture("textures/Bush.png")},
        Prop{{3000, 2900}, LoadTexture("textures/Sign.png")}};

    //Collision Object Creation
    collisions Occured;

    //Creating Enemy objet Slime
    Enemy enemies{
        Vector2{200.f, 400.f},
        LoadTexture("characters/goblin_idle_spritesheet.png"),
        LoadTexture("characters/goblin_run_spritesheet.png")};

    enemies.SetTarget(&knight);
   

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        // Beginning Screen
        if (!IsKeyDown(KEY_ENTER) && ChangeVar == 0)
        {
            DrawTextureEx(Begin, {300, 230}, 0.f, 1.8f, WHITE);
        }
        else
        {
            ChangeVar = 1;
        }
        //Ending Of Screen , Beginning Screen

        //Game Starts Over HEre
        if (ChangeVar == 1)
        {
            ClearBackground(BLACK);
            MapPos = Vector2Scale(knight.getworldPos(), -1);

            //Drawing Our Background ,, means Map
            DrawTextureEx(Back, MapPos, 0.0, 4.f, WHITE);

            //for knight animation and every other stuff
            knight.tick(GetFrameTime());

            //Prop Rendering
            for (auto prop : props)
            {
                prop.Render(knight.getworldPos());
            }
            //Is Our Hero Alive Or Was He Slaughtered
            if (!knight.IsAlive())
            {
                ClearBackground(BLACK);
                DrawText("Well You Suck Really Hard", 300, 200, 150, RED);
                EndDrawing();
                continue;
            }
            //I knew He will Not let Us down
           /* else
            {
                std::string knightHealth = "Health: ";
                knightHealth.append(std::to_string(knight.GetHealth()), 0, 5);
                DrawText(knightHealth.c_str(), 40, 40, 40, RED);
            }*/

            //Collision Detection
            for (auto prop : props)
            {
                if (Occured.CollisionOccured(knight.getCollisionRec(), prop.getCollisionRec(knight.getworldPos())))
                {
                    knight.UndoMovement();
                }
            }
            //for (auto enemies : hehehaha)
            
                enemies.tick(GetFrameTime());

             //Goblin Killing , I know it's Crime But its So fun to kill _________________________________________ Goblins
            if (knight.IsbuttonPressed())
            {
                //for (auto enemies : hehehaha)
                
                    if (Occured.CollisionOccured(knight.GetCollisionRecWeapon(), enemies.getCollisionRec()))
                    {

                        enemies.SetAlive(false);
                        //Health Managment Yeah Our Character gotta Die
                    }
                
            }
            if (Occured.CollisionOccured(knight.GetCollisionRecWeapon(), enemies.getCollisionRec()))
                knight.GetDamage(enemies.DoDamage());
            EndDrawing();
        }
    }
    UnloadTexture(Begin);
    UnloadTexture(Back);
}