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

    //bool leftLastClicked = false;
    //bool rightLastClicked = false;
    //bool upLastClicked = false;
    //bool downLastClicked = false;
    const int screenWidth = 1024;
    const int screenHeight = 960;
    InitWindow(screenWidth, screenHeight, "Mario Bros.");
    Texture2D MarioSprite = LoadTexture("resources/mario.png");
    Texture2D FloorB = LoadTexture("resources/floorb.png");
    Texture2D LuckyB = LoadTexture("resources/luckyb.png");
    Vector2 MarioPosition = {screenWidth/2, screenHeight/2};
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    int framesToJump = 0;
 
    int DistanceOffset = 0;
    //--------------------------------------------------------------------------------------
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
           int BrickDistance = 0;
            ClearBackground((Color){ 7, 155, 176, 1 });
            DrawTextureEx(MarioSprite, MarioPosition, 0, 4, WHITE);
            
            while(BrickDistance-DistanceOffset<screenWidth) {
                DrawTextureEx(FloorB, (Vector2) {BrickDistance-DistanceOffset, screenHeight-128}, 0, 4, WHITE);
                DrawTextureEx(FloorB, (Vector2) {BrickDistance-DistanceOffset, screenHeight-64}, 0, 4, WHITE);
                BrickDistance=BrickDistance+64;
            }
            if((IsKeyDown(KEY_SPACE)) && (MarioPosition.y>screenHeight-200)) {
                if(!(MarioPosition.x>=1100-DistanceOffset && MarioPosition.x<=1300-DistanceOffset)) {
                    framesToJump = 20;
                }
                else {
                    framesToJump = 10;
                }
                
            }
            if(IsKeyDown(KEY_D)) {
                DistanceOffset=DistanceOffset+8;
            }
            if(IsKeyDown(KEY_A)) {
                if(!(DistanceOffset<8)) {
                DistanceOffset=DistanceOffset-8;
            }
            }
            if(framesToJump>0) {
                    MarioPosition.y=MarioPosition.y-20;
                    framesToJump=framesToJump-1;
            }
            if(MarioPosition.y<screenHeight-192) {
            MarioPosition.y=MarioPosition.y+10;
            }
            //DrawTexture(logotexture, screenWidth/2 - logotexture.width/2, screenHeight/4 - logotexture.height/2 - 40, WHITE);

            //DrawText(TextFormat("Score: %i", score), screenWidth/2-(textLength/2), 20, 20, WHITE);
            //DrawCircleV(ballPosition, 20, WHITE);
            char distancestr[5];
            itoa(DistanceOffset, distancestr, 10);
            char toJump[5];
            itoa(framesToJump, toJump, 10);
            DrawText(distancestr, 64, 64, 40, BLACK);
            DrawText(toJump, 64, 128, 40, BLACK);
            DrawTextureEx(LuckyB,(Vector2) {1200-DistanceOffset, screenHeight-384}, 0, 4, WHITE);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }
    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}