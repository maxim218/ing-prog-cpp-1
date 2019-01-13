#include <iostream>
#include <string.h>
using namespace std;

int proiz(int a, int b) {
	int x = a * b;
	return x;
}

int proiz(int a, int b, int c) {
	int x = a * b * c;
	return x;
}

class MyString {
	protected:
		char s[2500];
		
	public:
		MyString() {
			strcpy(s, "\0");
		}
		
		void getString(char * sss) {
			strcpy(sss, s);
		}
		
		void setString(const char * sss) {
			strcpy(s, sss);
		}
		
		operator = (const char * sss) {
			strcpy(s, sss);
		}
		
		operator += (const char * sss) {
			strcat(s, sss);
		}
		
		operator -= (int x) {
			int n = strlen(s);
			int k = n - x;
			if(k >= 0) {
				s[k] = '\0';
			} else {
				strcpy(s, "\0");
			}
		}
		
		operator == (MyString obj) {
			char x[2500];
			obj.getString(x);
			
			int n1 = strlen(s);
			int n2 = strlen(x);
			
			if(n1 != n2) {
				return false;
			}
			
			for(int i = 0; i < n1; i++)
				if(s[i] != x[i])
					return false;
					
			return true;
		}
		
		void printString() {
			cout << "String: " << s << "\n";
		}
};

int main() {
	int a = 7;
	int b = 2;
	float x = (a + 0.0) / (b + 0.0);
	cout << x << "\n\n";
	
	cout << proiz(7, 8) << "\n";
	cout << proiz(4, 5, 6) << "\n\n";
	
	MyString y;
	
	y.setString("hello world !!!");
	y.printString();
	
	y = "I am Maxim";
	y.printString();
	
	y += " I like programming";
	y.printString();
	
	y = "maxim";
	y.printString();
	y -= 3;
	y.printString();
	y -= 50;
	y.printString();
	
	cout << "\n\n";
	
	MyString aa;
	MyString bb;
	
	aa = "george";
	bb = "george";
	if(aa == bb) 
		cout << "YES" << "\n";
	else
		cout << "NO" << "\n";
		
	aa = "maxim";
	bb = "maXim";
	if(aa == bb) 
		cout << "YES" << "\n";
	else
		cout << "NO" << "\n";
		
	
	
	
	cout << "\n\n";
	return 0;
}


