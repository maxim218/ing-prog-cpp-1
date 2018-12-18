#include <iostream>
#include <string.h>
#include <cstdlib>
#include <fstream>
using namespace std;

void rewriteFile(const char * fileName) {
	FILE * f;
	f = fopen(fileName, "w+");
	fclose(f);
}

struct user {
	int id;
	char login[50];
};

void addToFile(const char * fileName, user z) {
	FILE * f;
	f = fopen(fileName, "a+");
	fwrite(&z, sizeof(z), 1, f);
	fclose(f);
}

int main() {
	cout << "\n\n";
	
    char finalFileName[20];
    strcpy(finalFileName, "users.txt");
    
    cout << "Do you want to rewrite: Y/N: ";
    char c;
    cin >> c;
    
    if(c == 'Y') {
		rewriteFile(finalFileName);
	}
	
	cout << "\n\n";
	
	cout << "Input N: ";
	int n;
	cin >> n;
	
	cout << "\n\n";
	
	for(int i = 0; i < n; i++) {
		user u;
		cout << "Input ID: ";
		cin >> u.id;
		cout << "Input Login: ";
		cin >> u.login;
		cout << "\n";
		addToFile(finalFileName, u);
	}
    
    return 0;
}

















