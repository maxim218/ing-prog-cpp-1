#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
using namespace std;

void longFunction() {
    for(int i = 0; i < 100000; i++) {
        int h = 50;
        h = h / 2;
        h = h / 2;
    }
}

int main() {
    int a = 1;
    int b = 2000;

    int summa = 0;

    for(int i = a; i <= b; i++) {
        summa += i;
        longFunction();
    }

    cout << "\n";
    cout << "Summa: " << summa << "\n";
    cout << "\n";
    
    cout << "Time: " << clock() << "\n\n";

    return 0;
}