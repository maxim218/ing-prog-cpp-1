#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <pthread.h>
using namespace std;

void longFunction() {
    for(int i = 0; i < 100000; i++) {
        int h = 50;
        h = h / 2;
        h = h / 2;
    }
}

int a1, b1, s1;
int a2, b2, s2;

void * first(void *) {
    s1 = 0;
    for(int i = a1; i <= b1; i++) {
        s1 += i;
        longFunction();
    }
}

void * second(void *) {
    s2 = 0;
    for(int i = a2; i <= b2; i++) {
        s2 += i;
        longFunction();
    }
}

int main() {
    a1 = 1;
    b1 = 1000;

    a2 = 1001;
    b2 = 2000;

    pthread_t x1;
    pthread_t x2;

    pthread_create(&x1, NULL, first, NULL);
    pthread_create(&x2, NULL, second, NULL);

    pthread_join(x1, NULL);
    pthread_join(x2, NULL);

    cout << "S1: " << s1 << "\n";
    cout << "S2: " << s2 << "\n";
    int summa = s1 + s2;
    cout << "Summa: " << summa << "\n\n";

    cout << "Time: " << clock() << "\n\n";

    return 0;
}