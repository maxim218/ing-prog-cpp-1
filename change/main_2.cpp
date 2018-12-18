#include <iostream>
#include <string.h>
#include <cstdlib>
#include <fstream>
using namespace std;

struct pupil {
	int id;
	char name[50];
};

struct mark {
	int pupilID;
	int markValue;
};

struct database {
	pupil pupilsArr[100];
	mark marksArr[1000];
	int pupilsSize;
	int marksSize;
};

void saveDatabase(const char * fileName, database z) {
	FILE * f;
	f = fopen(fileName, "w+");
	fwrite(&z, sizeof(z), 1, f);
	fclose(f);
}

database readDatabase(const char * fileName) {
	FILE * f;
	f = fopen(fileName, "r");
	database z;
	fread(&z, sizeof(z), 1, f);
	fclose(f);
	return z;
}

bool isFileExists(const char * s) {
	ifstream ifile(s);
	return ifile;
}

void printDatabase(database z) {
	cout << "Pupils: " << "\n";
	for(int i = 0; i < z.pupilsSize; i++) {
		cout << z.pupilsArr[i].id << "  " << z.pupilsArr[i].name << "\n";
	}
	cout << "\n";
	cout << "Marks: " << "\n";
	for(int i = 0; i < z.marksSize; i++) {
		cout << "User: " << z.marksArr[i].pupilID << "  ";
		cout << "Mark: " << z.marksArr[i].markValue << "\n";
	}
}

void addPupil(pupil z, database &obj) {
	obj.pupilsArr[obj.pupilsSize] = z;
	obj.pupilsSize++;
}

void addMark(mark z, database &obj) {
	obj.marksArr[obj.marksSize] = z;
	obj.marksSize++;
}

int main() {
	database obj;
	
	if(isFileExists("file.txt") == true) {
		database xxx = readDatabase("file.txt");
		printDatabase(xxx);
	}
	
	pupil p;
	
	p.id = 10;
	strcpy(p.name, "maxim");
	addPupil(p, obj);
	
	p.id = 20;
	strcpy(p.name, "george");
	addPupil(p, obj);
	
	saveDatabase("file.txt", obj);
	
    return 0;
}























