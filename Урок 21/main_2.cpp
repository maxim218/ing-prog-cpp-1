#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <pthread.h>
using namespace std;

int a1, b1, a2, b2;
int s1, s2;

void longFunc() {
	for(int k = 0; k < 999999; k++) {
		int h = 2;
		h *= 4;
		h *= 4;
		h *= 4;
	}
}

void * first (void *) {
	s1 = 0;
	for(int i = a1; i <= b1; i++) {
		s1 += i;
		cout << "A";
		longFunc();
	}
}

void * second (void *) {
	s2 = 0;
	for(int i = a2; i <= b2; i++) {
		s2 += i;
		cout << "a";
		longFunc();
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
	
	cout << "\n\n";
	
	cout << "S1 = " << s1 << "\n";
	cout << "S2 = " << s2 << "\n";
	cout << "S1 + S2 = " << (s1 + s2) << "\n";
	
	cout << "\n\n";
	
	cout << "Time: " << clock() / 1.0 << "\n\n";
	
	cout << "\n\n";
	
	return 0;
}





