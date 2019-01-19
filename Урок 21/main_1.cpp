#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
using namespace std;

void longFunc() {
	for(int k = 0; k < 999999; k++) {
		int h = 2;
		h *= 4;
		h *= 4;
		h *= 4;
	}
}

int main() {
	int a = 1;
	int b = 2000;
	
	int s = 0;
	
	for(int i = a; i <= b; i++) {
		s += i;
		longFunc();
		cout << "A";
	}
	
	cout << "\n\n";
	cout << "Summa: " << s << "\n";
	cout << "\n\n";
	cout << "Time: " << clock() / 1.0 << "\n\n";
	
	return 0;
}

