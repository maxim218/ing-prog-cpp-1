#include <iostream>
#include <string.h>
#include <cstdlib>
#include <fstream>
using namespace std;

struct node {
	int countryId;
	char countryName[100];
};

struct city {
	int cityId;
	int countryId;
	char cityName[100];
};

bool controlCountryID(const char * fileName, int ID) {
	bool result = false;
	node z;
	FILE * f;
	f = fopen(fileName, "r");
	while(fread(&z, sizeof(z), 1, f) > 0) {
		if(z.countryId == ID) {
			result = true;
			break;
		}
	}
	fclose(f);
	return result;
}

void addCity(const char * fileName, city z) {
	int countryID = z.countryId;
	
	bool flag = controlCountryID("countries.txt", countryID);
	if(flag == false) {
		return;
	}
	
	FILE * f;
	f = fopen(fileName, "a+");
	fwrite(&z, sizeof(z), 1, f);
	fclose(f);
}

void readCities(const char * fileName) {
	cout << "\n";
	city z;
	FILE * f;
	f = fopen(fileName, "r");
	while(fread(&z, sizeof(z), 1, f) > 0) {
		cout << z.cityId << " " << z.countryId << " " << z.cityName << "\n";
	}
	fclose(f);
	cout << "\n";
}

void readFromFile(const char * fileName) {
	node z;
	FILE * f;
	f = fopen(fileName, "r");
	while(fread(&z, sizeof(z), 1, f) > 0) {
		cout << "CountryID: " << z.countryId << "\n";
		cout << "CountryName: " << z.countryName << "\n";
		cout << "\n";
	}
	fclose(f);
}

void addToFile(node x, const char * fileName) {
	bool flag = controlCountryID(fileName, x.countryId);
	if(flag == true) {
		return;
	}
	
	FILE * f;
	f = fopen(fileName, "a+");
	fwrite(&x, sizeof(x), 1, f);
	fclose(f);
}

int main() {
	readFromFile("countries.txt");
	
	cout << "Input N: " << "\n";
	int n;
	cin >> n;
	
	cout << "\n";
	
	for(int i = 0; i < n; i++) {
		node k;
		cout << "\n";
		cout << "Input country ID: ";
		cin >> k.countryId;
		cout << "Input country Name: ";
		cin >> k.countryName;
		addToFile(k, "countries.txt");
	}
	
	cout << "\n";
	readFromFile("countries.txt");
	cout << "\n\n";
	
	cout << "Input K:  ";
	int k;
	cin >> k;
	
	for(int i = 0; i < k; i++) {
		city h;
		cout << "ID city: ";
		cin >> h.cityId;
		cout << "ID country: ";
		cin >> h.countryId;
		cout << "Name city: ";
		cin >> h.cityName;
		addCity("cities.txt", h);
	} 
	
	readCities("cities.txt");
	
	return 0;
}





