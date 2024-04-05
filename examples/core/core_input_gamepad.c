/*******************************************************************************************
*
*   raylib [core] example - Gamepad input
*
*   NOTE: This example requires a Gamepad connected to the system
*         raylib is configured to work with the following gamepads:
*                - Xbox 360 Controller (Xbox 360, Xbox One)
*                - PLAYSTATION(R)3 Controller
*         Check raylib.h for buttons configuration
*
*   Example originally created with raylib 1.1, last time updated with raylib 4.2
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2013-2024 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

// NOTE: Gamepad name ID depends on drivers and OS
#define XBOX360_LEGACY_NAME_ID  "Xbox Controller"
#define XBOX360_NAME_ID     "Xbox 360 Controller"
#define PS3_NAME_ID         "PLAYSTATION(R)3 Controller"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    SetConfigFlags(FLAG_MSAA_4X_HINT);  // Set MSAA 4X hint before windows creation

    InitWindow(screenWidth, screenHeight, "raylib [core] example - gamepad input");

    Texture2D texPs3Pad = LoadTexture("resources/ps3.png");
    Texture2D texXboxPad = LoadTexture("resources/xbox.png");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    int gamepad = 0; // which gamepad to display

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // ...
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RL_RAYWHITE);

            if (IsKeyPressed(KEY_LEFT) && gamepad > 0) gamepad--;
            if (IsKeyPressed(KEY_RIGHT)) gamepad++;

            if (IsGamepadAvailable(gamepad))
            {
                DrawText(TextFormat("GP%d: %s", gamepad, GetGamepadName(gamepad)), 10, 10, 10, RL_BLACK);

                if (true)
                {
                    DrawTexture(texXboxPad, 0, 0, RL_DARKGRAY);

                    // Draw buttons: xbox home
                    if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_MIDDLE)) DrawCircle(394, 89, 19, RL_RED);

                    // Draw buttons: basic
                    if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_MIDDLE_RIGHT)) DrawCircle(436, 150, 9, RL_RED);
                    if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_MIDDLE_LEFT)) DrawCircle(352, 150, 9, RL_RED);
                    if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_FACE_LEFT)) DrawCircle(501, 151, 15, RL_BLUE);
                    if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)) DrawCircle(536, 187, 15, RL_LIME);
                    if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT)) DrawCircle(572, 151, 15, RL_MAROON);
                    if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_FACE_UP)) DrawCircle(536, 115, 15, RL_GOLD);

                    // Draw buttons: d-pad
                    DrawRectangle(317, 202, 19, 71, RL_BLACK);
                    DrawRectangle(293, 228, 69, 19, RL_BLACK);
                    if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_FACE_UP)) DrawRectangle(317, 202, 19, 26, RL_RED);
                    if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_FACE_DOWN)) DrawRectangle(317, 202 + 45, 19, 26, RL_RED);
                    if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_FACE_LEFT)) DrawRectangle(292, 228, 25, 19, RL_RED);
                    if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_FACE_RIGHT)) DrawRectangle(292 + 44, 228, 26, 19, RL_RED);

                    // Draw buttons: left-right back
                    if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_TRIGGER_1)) DrawCircle(259, 61, 20, RL_RED);
                    if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_TRIGGER_1)) DrawCircle(536, 61, 20, RL_RED);

                    // Draw axis: left joystick

                    Color leftGamepadColor = RL_BLACK;
                    if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_THUMB)) leftGamepadColor = RL_RED;
                    DrawCircle(259, 152, 39, RL_BLACK);
                    DrawCircle(259, 152, 34, RL_LIGHTGRAY);
                    DrawCircle(259 + (int)(GetGamepadAxisMovement(gamepad, GAMEPAD_AXIS_LEFT_X)*20),
                               152 + (int)(GetGamepadAxisMovement(gamepad, GAMEPAD_AXIS_LEFT_Y)*20), 25, leftGamepadColor);

                    // Draw axis: right joystick
                    Color rightGamepadColor = RL_BLACK;
                    if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_THUMB)) rightGamepadColor = RL_RED;
                    DrawCircle(461, 237, 38, RL_BLACK);
                    DrawCircle(461, 237, 33, RL_LIGHTGRAY);
                    DrawCircle(461 + (int)(GetGamepadAxisMovement(gamepad, GAMEPAD_AXIS_RIGHT_X)*20),
                               237 + (int)(GetGamepadAxisMovement(gamepad, GAMEPAD_AXIS_RIGHT_Y)*20), 25, rightGamepadColor);

                    // Draw axis: left-right triggers
                    DrawRectangle(170, 30, 15, 70, RL_GRAY);
                    DrawRectangle(604, 30, 15, 70, RL_GRAY);
                    DrawRectangle(170, 30, 15, (int)(((1 + GetGamepadAxisMovement(gamepad, GAMEPAD_AXIS_LEFT_TRIGGER))/2)*70), RL_RED);
                    DrawRectangle(604, 30, 15, (int)(((1 + GetGamepadAxisMovement(gamepad, GAMEPAD_AXIS_RIGHT_TRIGGER))/2)*70), RL_RED);

                    //DrawText(TextFormat("Xbox axis LT: %02.02f", GetGamepadAxisMovement(gamepad, GAMEPAD_AXIS_LEFT_TRIGGER)), 10, 40, 10, RL_BLACK);
                    //DrawText(TextFormat("Xbox axis RT: %02.02f", GetGamepadAxisMovement(gamepad, GAMEPAD_AXIS_RIGHT_TRIGGER)), 10, 60, 10, RL_BLACK);
                }
                else if (TextIsEqual(GetGamepadName(gamepad), PS3_NAME_ID))
                {
                    DrawTexture(texPs3Pad, 0, 0, RL_DARKGRAY);

                    // Draw buttons: ps
                    if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_MIDDLE)) DrawCircle(396, 222, 13, RL_RED);

                    // Draw buttons: basic
                    if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_MIDDLE_LEFT)) DrawRectangle(328, 170, 32, 13, RL_RED);
                    if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_MIDDLE_RIGHT)) DrawTriangle((Vector2){ 436, 168 }, (Vector2){ 436, 185 }, (Vector2){ 464, 177 }, RL_RED);
                    if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_FACE_UP)) DrawCircle(557, 144, 13, RL_LIME);
                    if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT)) DrawCircle(586, 173, 13, RL_RED);
                    if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)) DrawCircle(557, 203, 13, RL_VIOLET);
                    if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_FACE_LEFT)) DrawCircle(527, 173, 13, RL_PINK);

                    // Draw buttons: d-pad
                    DrawRectangle(225, 132, 24, 84, RL_BLACK);
                    DrawRectangle(195, 161, 84, 25, RL_BLACK);
                    if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_FACE_UP)) DrawRectangle(225, 132, 24, 29, RL_RED);
                    if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_FACE_DOWN)) DrawRectangle(225, 132 + 54, 24, 30, RL_RED);
                    if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_FACE_LEFT)) DrawRectangle(195, 161, 30, 25, RL_RED);
                    if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_FACE_RIGHT)) DrawRectangle(195 + 54, 161, 30, 25, RL_RED);

                    // Draw buttons: left-right back buttons
                    if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_TRIGGER_1)) DrawCircle(239, 82, 20, RL_RED);
                    if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_TRIGGER_1)) DrawCircle(557, 82, 20, RL_RED);

                    // Draw axis: left joystick
                    Color leftGamepadColor = RL_BLACK;
                    if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_THUMB)) leftGamepadColor = RL_RED;
                    DrawCircle(319, 255, 35, leftGamepadColor);
                    DrawCircle(319, 255, 31, RL_LIGHTGRAY);
                    DrawCircle(319 + (int)(GetGamepadAxisMovement(gamepad, GAMEPAD_AXIS_LEFT_X) * 20),
                               255 + (int)(GetGamepadAxisMovement(gamepad, GAMEPAD_AXIS_LEFT_Y) * 20), 25, leftGamepadColor);

                    // Draw axis: right joystick
                    Color rightGamepadColor = RL_BLACK;
                    if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_THUMB)) rightGamepadColor = RL_RED;
                    DrawCircle(475, 255, 35, RL_BLACK);
                    DrawCircle(475, 255, 31, RL_LIGHTGRAY);
                    DrawCircle(475 + (int)(GetGamepadAxisMovement(gamepad, GAMEPAD_AXIS_RIGHT_X) * 20),
                               255 + (int)(GetGamepadAxisMovement(gamepad, GAMEPAD_AXIS_RIGHT_Y) * 20), 25, rightGamepadColor);

                    // Draw axis: left-right triggers
                    DrawRectangle(169, 48, 15, 70, RL_GRAY);
                    DrawRectangle(611, 48, 15, 70, RL_GRAY);
                    DrawRectangle(169, 48, 15, (int)(((1 - GetGamepadAxisMovement(gamepad, GAMEPAD_AXIS_LEFT_TRIGGER)) / 2) * 70), RL_RED);
                    DrawRectangle(611, 48, 15, (int)(((1 - GetGamepadAxisMovement(gamepad, GAMEPAD_AXIS_RIGHT_TRIGGER)) / 2) * 70), RL_RED);
                }
                else
                {
                    DrawText("- GENERIC GAMEPAD -", 280, 180, 20, RL_GRAY);

                    // TODO: Draw generic gamepad
                }

                DrawText(TextFormat("DETECTED AXIS [%i]:", GetGamepadAxisCount(0)), 10, 50, 10, RL_MAROON);

                for (int i = 0; i < GetGamepadAxisCount(0); i++)
                {
                    DrawText(TextFormat("AXIS %i: %.02f", i, GetGamepadAxisMovement(0, i)), 20, 70 + 20*i, 10, RL_DARKGRAY);
                }

                if (GetGamepadButtonPressed() != GAMEPAD_BUTTON_UNKNOWN) DrawText(TextFormat("DETECTED BUTTON: %i", GetGamepadButtonPressed()), 10, 430, 10, RL_RED);
                else DrawText("DETECTED BUTTON: NONE", 10, 430, 10, RL_GRAY);
            }
            else
            {
                DrawText(TextFormat("GP%d: NOT DETECTED", gamepad), 10, 10, 10, RL_GRAY);

                DrawTexture(texXboxPad, 0, 0, RL_LIGHTGRAY);
            }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(texPs3Pad);
    UnloadTexture(texXboxPad);

    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
