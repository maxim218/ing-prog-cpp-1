#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <pthread.h>
using namespace std;

int arr[1000];
int x;
bool flag;

void * first(void *) {
    for(int i = 0; i < 1000; i += 2) {
        if(arr[i] == x) {
            flag = true;
            break;
        }
    }
}

void * second(void *) {
    for(int i = 1; i < 1000; i += 2) {
        if(arr[i] == x) {
            flag = true;
            break;
        }
    }
}

int main() {
    for(int i = 0; i < 1000; i++) {
        arr[i] = i;
    }

    cout << "Input X: ";
    cin >> x;
    cout << "\n\n";

    flag = false;

    pthread_t x1;
    pthread_t x2;

    pthread_create(&x1, NULL, first, NULL);
    pthread_create(&x2, NULL, second, NULL);

    pthread_join(x1, NULL);
    pthread_join(x2, NULL);

    if(flag == true) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }

    return 0;
}