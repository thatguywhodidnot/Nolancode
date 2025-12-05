
#ifndef SLEEP_H
#define SLEEP_H

#include <chrono>
#include <thread>

void sleepfor(int x);



 
void sleepfor(int x){
    std::this_thread::sleep_for(std::chrono::milliseconds(x));
}


#endif // SLEEP_H