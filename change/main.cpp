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
	f = open(fileName, "a+");
	fwrite(&z, sizeof(z), 1, f);
	fclose(f);
}

int main() {
    char finalFileName[20];
    strcpy(finalFileName, "users.txt");
    
    cout << "Do you want to rewrite: Y/N: ";
    char c;
    cin >> c;
    
    if(c == 'Y') {
		rewriteFile(finalFileName);
	}
	
	
    
    return 0;
}

















