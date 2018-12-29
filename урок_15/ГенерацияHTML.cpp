#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cstdlib>
#include <fstream>
using namespace std;

struct node {
	string tag;
	string content;
};

vector <node> v;

void addToFile(string fileName, string data) {
	FILE * f;
	f = fopen(fileName.c_str(), "a+");
	fputs(data.c_str(), f);
	fclose(f);
}

int main(int argc, char** argv) {
	cout << "Input file name: ";
	string fileName;
	cin >> fileName;
	
	FILE * f;
	f = fopen(fileName.c_str(), "w+");
	fclose(f);
	
	cout << "Input header: ";
	string header;
	cin >> header;
	
	cout << "Input strings number: ";
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		node x;
		cout << "Input tag: ";
		cin >> x.tag;
		cout << "Input content: ";
		cin >> x.content;
		v.push_back(x);
	}
	
	
	string s = "<!doctype html>";
	addToFile(fileName, s);
	
	s = "<html>";
	addToFile(fileName, s);
	
	s = "<head>";
	addToFile(fileName, s);
	
	s = "<title>" + header + "</title>";
	addToFile(fileName, s);
	
	s = "</head>";
	addToFile(fileName, s);
	
	s = "<body>";
	addToFile(fileName, s);
	
	for(int i = 0; i < v.size(); i++) {
		node x = v[i];
		s = "<" + x.tag + ">" + x.content + "</" + x.tag + ">";
		s += "<br>";
		addToFile(fileName, s);
	}
	
	s = "</body></html>";
	addToFile(fileName, s);
	
	return 0;
}














