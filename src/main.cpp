#include <iostream>
#include "ask.h"
using namespace std;
int main(){
    cout << "Hello World" << endl;
    bool answer = askYorN("Are you ok?");
    if (answer){
        cout << "I am happy to hear that" << endl;
    }else{
        cout << "Sorry to hear that" << endl;
    }
}