/*******************************************************************************************
*
*   raylib [core] example - Keyboard input
*
*   Example originally created with raylib 1.0, last time updated with raylib 1.0
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2014-2022 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "stdio.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    
    
    // Initialization
    //--------------------------------------------------------------------------------------
    bool hasLeftClicked = true;
    bool hasRightClicked = false;
    bool hasUpClicked = false;
    bool hasDownClicked = false;
    //bool leftLastClicked = false;
    //bool rightLastClicked = false;
    //bool upLastClicked = false;
    //bool downLastClicked = false;
    const int screenWidth = 500;
    const int screenHeight = 500;
    int score = 0;
    InitWindow(screenWidth, screenHeight, "PONG");
    Image logo = LoadImage("resources/logo.png");             // Load image in CPU memory (RAM)
    Texture2D logotexture = LoadTextureFromImage(logo);      // Image converted to texture, uploaded to GPU memory (VRAM)
    Vector2 ballPosition = { (float)screenWidth/2, (float)screenHeight/2 };
    Vector2 ballSize = { (float)20, (float)20 };
    Vector2 textPos = { (float)screenWidth/2, (float)20};

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    void toggle(bool x) {
        if(x==true && ballPosition.y>GetMousePosition().y){
            hasUpClicked=false;
            hasDownClicked=true;
        }
        if(x==true && ballPosition.y<GetMousePosition().y) {
            hasDownClicked=false; 
            hasUpClicked=true;
        }
        if(x==true && ballPosition.y>(GetMousePosition().y)-40 && ballPosition.y<(GetMousePosition().y)+40) score=score+1;
        else if(x==true) score=0;
        if(hasLeftClicked==true && x==true) hasLeftClicked=false;
        else if(x==true) hasLeftClicked=true;
        if(hasRightClicked==true && x==true) hasRightClicked=false;
        else if(x==true) hasRightClicked=true;
        if(hasUpClicked==true && x==false) hasUpClicked=false;
        else if(x==false) hasUpClicked=true;
        if(hasDownClicked==true && x==false) hasDownClicked=false;
        else if(x==false) hasDownClicked=true;

        
    }
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        /* //----
        if (IsKeyDown(KEY_LEFT)) { 
            if(leftLastClicked==false) {
                if(hasLeftClicked==true) {
                    hasLeftClicked=false;
                }
                else if(hasLeftClicked==false) {
                    hasRightClicked=false;
                    hasLeftClicked=true;
                }
            }
            leftLastClicked=true;

        };
        if(!IsKeyDown(KEY_LEFT)) leftLastClicked = false;
        //----
        //----
        if (IsKeyDown(KEY_RIGHT)) { 
            if(rightLastClicked==false) {
                if(hasRightClicked==true) {
                    hasRightClicked=false;
                }
                else if(hasRightClicked==false) {
                    hasLeftClicked=false;
                    hasRightClicked=true;
                }
            }
            rightLastClicked=true;

        };
        if(!IsKeyDown(KEY_RIGHT)) rightLastClicked = false;
        //----
        //----
        if (IsKeyDown(KEY_UP)) { 
            if(upLastClicked==false) {
                if(hasUpClicked==true) {
                    hasUpClicked=false;
                }
                else if(hasUpClicked==false) {
                    hasDownClicked=false;
                    hasUpClicked=true;
                }
            }
            upLastClicked=true;

        };
        if(!IsKeyDown(KEY_UP)) upLastClicked = false;
        //----
        //----
        if (IsKeyDown(KEY_DOWN)) { 
            if(downLastClicked==false) {
                if(hasDownClicked==true) {
                    hasDownClicked=false;
                }
                else if(hasDownClicked==false) {
                    hasUpClicked=false;
                    hasDownClicked=true;
                }
            }
            downLastClicked=true;

        };
        if(!IsKeyDown(KEY_DOWN)) downLastClicked = false;
        //----  */
        //----------------------------------------------------------------------------------
        if(ballPosition.x<screenWidth-20) {
            if (hasRightClicked==true) ballPosition.x += (float) score+2;
        }
        else toggle(true);
        if(ballPosition.x>15) { 
            if (hasLeftClicked==true) ballPosition.x -= (float) score+2;
        }
        else toggle(true);
        if(ballPosition.y>5) {
            if (hasUpClicked==true) ballPosition.y -= (float) score+2;
        }
        else toggle(false);
        if(ballPosition.y<screenHeight-15) {
            if (hasDownClicked==true) ballPosition.y += (float) score+2;
        }
        else toggle(false);
        
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
            ClearBackground(BLACK);
            //DrawTexture(logotexture, screenWidth/2 - logotexture.width/2, screenHeight/4 - logotexture.height/2 - 40, WHITE);

            DrawTextEx(LoadFont("/resources/pong.ttf"), TextFormat("%i", score), textPos, 100, 1, WHITE);
            //DrawText(TextFormat("Score: %i", score), screenWidth/2-(textLength/2), 20, 20, WHITE);
            DrawRectangleV(ballPosition, ballSize, WHITE);
            //DrawCircleV(ballPosition, 20, WHITE);
            DrawRectangle(0, GetMousePosition().y-25, 10, 50, WHITE); 
            DrawRectangle(screenWidth-10, GetMousePosition().y-25, 10, 50, WHITE); 
        EndDrawing();
        //----------------------------------------------------------------------------------
    }
    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}