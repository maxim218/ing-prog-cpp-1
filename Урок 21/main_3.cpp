#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
using namespace std;

int arr[100];
int n;
int x;

bool exists;

void * first (void *) {
	for(int i = 0; i < n; i += 2) {
		if(arr[i] == x) {
			exists = true;
			break;	
		}
	}
}

void * second (void *) {
	for(int i = 1; i < n; i += 2) {
		if(arr[i] == x) {
			exists = true;
			break;	
		}
	}
} 

int main() {
	exists = false;
	
	cout << "Input N: " << "\n";
	cin >> n;
	
	cout << "Input " << n << " numbers: " << "\n";
	for(int i = 0; i < n; i++) cin >> arr[i];
	
	cout << "Input X: " << "\n";
	cin >> x;
	
	pthread_t x1;
	pthread_t x2;
	
	pthread_create(&x1, NULL, first, NULL);
	pthread_create(&x2, NULL, second, NULL);
	
	pthread_join(x1, NULL);
	pthread_join(x2, NULL);
	
	cout << "\n\n";
	
	if(exists == true) {
		cout << "YES" << "\n";
	} else {
			cout << "NO" << "\n";
	}
	
	cout << "\n\n";
	
	return 0;
}