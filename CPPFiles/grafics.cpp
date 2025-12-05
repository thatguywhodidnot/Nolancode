#include <iostream>
#include <iomanip>
// #include <thread>
// #include <chrono>
#include <raylib.h>
#include <cmath>
#include <string>
#include <cstring>

//chrono is cpp time library

//thread library -> threads are workers doing tasks 1 at a time
//multi threads allow for concurrent tasks
//be careful because threads can technically share memory


//glad is more modern than glew


//glfw is for windows and input 


bool Vector2Equals(Vector2 a, Vector2 b) {
    return ((std::round(a.x) == std::round(b.x) ) && (std::round(a.y) == std::round(b.y)));
}


class bullet1(){

    Vector2 playerpos; 
    int grade;

    bullet(Vector2 pos, int grade){
        pos = playerpos;
        grade = grade;
    }
    void travel(){

    }

};

class Player{

	public:
	    Vector2 pos = {300,300};
		float speed = .3f;

        bool udie = false;
	    float deathtimer = 0.0f;
        


        void die(){
                udie = true;
                deathtimer = 1.0f;
                pos = {300,300};
        }

        void update() {
            if (IsKeyDown(KEY_RIGHT)) pos.x += speed; 
            if (IsKeyDown(KEY_LEFT)) pos.x -= speed; 
            if (IsKeyDown(KEY_UP)) pos.y -= speed; 
            if (IsKeyDown(KEY_DOWN)) pos.y += speed; 

            if(udie){
                deathtimer -= GetFrameTime();
                if(deathtimer <=0){
                    udie =false;
                }
            }

	    }

        void shoot(){


        }

	    void draw() {
		    DrawCircleV(pos, 20, RED);
	    }

        

};

class Deadly{
    public:
	    Vector2 objpos = {500,500};
        Vector2 objsize = {20,20};
        Rectangle spot = {500,500,20,20};
        
        void draw() {
		    DrawRectangleRec(spot, GREEN);
	    }

        void attack(Player& p){
            if (spot.x < p.pos.x) spot.x+=(p.speed/ 2);
            else if (spot.x > p.pos.x) spot.x-=(p.speed/ 2);
            if (spot.y < p.pos.y) spot.y+=(p.speed/ 2);
            else if (spot.y > p.pos.y) spot.y-=(p.speed/ 2);
            

        };
        void kill(Player& p){

            if (CheckCollisionCircleRec(p.pos,20,spot)){
                p.die();
                spot = {500,500,20,20};
                


            };
        }



};

const char* showpos(Vector2 pos){

    static std::string cpos = (std::to_string(pos.x )+ "  " + std::to_string(pos.y));
    return cpos.c_str();

}


int main (){

    Player p;
    Deadly box;

    InitWindow(800, 600, "Raylib Test");
    while (!WindowShouldClose()) {

        float deltatime = GetFrameTime();
        Vector2 mousepos = GetMousePosition();
        const std::string cpos =("You are at " + std::to_string(p.pos.x )+ "  " + std::to_string(p.pos.y));

        const std::string mpos = ( "Aiming at " + std::to_string(mousepos.x )+ "  " + std::to_string(mousepos.y));


        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText(TextFormat("Frame Time: %.4f", deltatime), 10, 40, 20, DARKGRAY);
         
        
        p.update();
        p.draw();
        box.draw();
        box.kill(p);
        box.attack(p);
        if (p.udie) {
            DrawText("you died", 190, 200, 30, BLACK);

        }
        DrawText((cpos.c_str()), 90, 20, 20, BLACK);
        DrawText((mpos.c_str()), 90, 0, 20, BLACK);


        

        EndDrawing();
    }
    CloseWindow();

    std::cout << "\nmaking grapohics\n\n";


    return 0;
}
