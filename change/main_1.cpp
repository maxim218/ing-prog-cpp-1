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

bool isFileExists(const char * s) {
	ifstream ifile(s);
	return ifile;
}

void readRecordsFromFile(char * fileName) {
	user z;
	cout << "\n\n";
	cout << "Content: " << "\n";
	FILE * f;
	f = fopen(fileName, "r");
	while(fread(&z, sizeof(z), 1, f) > 0) {
		cout << "ID: " << z.id << "  " << "Login: " << z.login << "\n";
	}
	fclose(f);
	cout << "\n";
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
	
	bool b = isFileExists(finalFileName);
	
	if(b == true) {
		readRecordsFromFile(finalFileName);
	} else {
		cout << "\n\n" << "File not found !!!" << "\n\n";
	}
    
    return 0;
}

















