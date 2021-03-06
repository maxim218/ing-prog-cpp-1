#include <iostream>
#include <string.h>
#include <cstdlib>
#include <fstream>
using namespace std;

char map[50][50];

int row;
int col;
int size;

int arr[50][50];

void initMap() {
	FILE * f;
	f = fopen("file.txt","r");
	int x;
    char c;
    while ((x=getc(f)) != EOF){
       c = char(x);
       if(c == 'W' || c == 'A') {
		   map[row][col] = c;
		   col++;
		   if(col == size) {
			   col = 0;
			   row++;
		   }
	   }
    }
	fclose(f);
}

void printMap() {
	cout << "\n";
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void initArr() {
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			if(map[i][j] == 'W') {
				arr[i][j] = 999;
			}
			if(map[i][j] == 'A') {
				arr[i][j] = -1;
			}
		}
	}
}

void printElement(int x) {
	if(x == -1) { cout << "-1 "; return; }
	if(x == 999) { cout << "999"; return; }
	if(x < 10) { cout << x << "  "; return; }
	if(x < 100) { cout << x << " "; return; }
	if(x < 1000) { cout << x; return; }
}

void printArr() {
	cout << "\n";
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			printElement(arr[i][j]);
			cout << " | ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void paintWay(int x1, int y1, int x2, int y2) {
	arr[y1][x1] = 0;
	int nowColor = 0;
	
	while(arr[y2][x2] == -1) {
		for(int i = 0; i < size; i++) {
			for(int j = 0; j < size; j++) {
				if(arr[i][j] == nowColor) {
					if(arr[i - 1][j] == -1) arr[i - 1][j] = nowColor + 1;
					if(arr[i + 1][j] == -1) arr[i + 1][j] = nowColor + 1;
					if(arr[i][j - 1] == -1) arr[i][j - 1] = nowColor + 1;
					if(arr[i][j + 1] == -1) arr[i][j + 1] = nowColor + 1;
				}
			}
		}
		nowColor++;
	}
}

struct pointStruct {
	int x;
	int y;
};

pointStruct pointsArr[1000];
int pointsSize = 0;

void addPoint(int nowY, int nowX) {
	pointStruct p;
	p.x = nowX;
	p.y = nowY;
	pointsArr[pointsSize] = p;
	pointsSize++;
}

void goPrintBack(int nowY, int nowX) {	
	int value = arr[nowY][nowX];
	
	cout << "Y: ";
	printElement(nowY);
	cout << " |   ";
	cout << "X: ";
	printElement(nowX);
	cout << "\n";
	
	addPoint(nowY, nowX);
	
	int i, j;
	
	i = nowY - 1;
	j = nowX;
	if(arr[i][j] < value && arr[i][j] != -1) {
		goPrintBack(i, j);
		return;
	}
	
	i = nowY + 1;
	j = nowX;
	if(arr[i][j] < value && arr[i][j] != -1) {
		goPrintBack(i, j);
		return;
	}
	
	i = nowY;
	j = nowX - 1;
	if(arr[i][j] < value && arr[i][j] != -1) {
		goPrintBack(i, j);
		return;
	}
	
	i = nowY;
	j = nowX + 1;
	if(arr[i][j] < value && arr[i][j] != -1) {
		goPrintBack(i, j);
		return;
	}
}

bool isPoint(int yy, int xx) {
	for(int i = 0; i < pointsSize; i++) {
		pointStruct p = pointsArr[i];
		if(p.x == xx && p.y == yy) {
			return true;
		}
	}
	return false;
}

void printNiceWay() {
	cout << "\n";
	for(int i = 0; i < size; i++)  {
		for(int j = 0; j < size; j++) {
			bool b = isPoint(i, j);
			if(b == true) {
				cout << "-  ";
			} else {
				if(arr[i][j] == 999) 
					cout << "999";
				else
					cout << "0  ";
			}
			cout << " | ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int main() {
	row = 0;
	col = 0;
	size = 10;
	
	initMap();
	printMap();
	
	initArr();
	printArr();
	
	int x1 = 1;
	int y1 = 8;
	
	int x2 = 7;
	int y2 = 2;
	
	paintWay(x1, y1, x2, y2);
	printArr();
	
	cout << "\n";
	pointsSize = 0;
	goPrintBack(y2, x2);
	cout << "\n";
	
	printNiceWay();
}

