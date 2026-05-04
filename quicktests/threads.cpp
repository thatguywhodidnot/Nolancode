#include <iostream>
#include <thread>

using namespace std;


void do_smth(){
	
	cout << "something is being done";
}


int main(){
	thread worker(do_smth);
	worker.join();


}
