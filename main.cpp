#include <iostream>
#include "./loader/definitions.h"

using namespace std;

int main(){
    if( isAuthenticated ){
        cout << "Hello world !" << "\n";
    }
    else {
        cout << "No puedes entrar!" << "\n";
    }

}