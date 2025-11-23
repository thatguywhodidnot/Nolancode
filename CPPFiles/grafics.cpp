#include <iostream>
#include <iomanip>

//chrono is cpp time library
#include <chrono>

//thread library -> threads are workers doing tasks 1 at a time
//multi threads allow for concurrent tasks
//be careful because threads can technically share memory
#include <thread>

//glad is more modern than glew


//glfw is for windows and input 



#include <raylib.h>




int main (){

    InitWindow(800, 600, "Raylib Test");
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello from Raylib!", 190, 200, 30, BLACK);
        EndDrawing();
    }
    CloseWindow();

    std::cout << "\nmaking grapohics\n\n";


    return 0;
}
