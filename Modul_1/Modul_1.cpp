#include <stdio.h>
#include <iostream>
#include <cstdlib>

using namespace std;

double fact(int n) 
{
	if (n == 0 || n == 1)return 1;
	if (n < 0)return - 1;
	double rez = 1;
	for (int i = 1; i <= n; ++i) rez *= i;
	return rez;
}

 /*1*/   double sum(double eps)                   
{
	 double rez = 0, cur = 0;
	 bool flag = true;
	int i = 0;
	while (flag) {
		cur = (pow(-2, i) / fact(i));
		if (cur <= eps)break;
		rez += cur;
		++i;
	}
	return rez;
}    

int Posfinder(char* s, char t)     
{
	int pos = 0;
	for (int i = 0; i < strlen(s); ++i) {
		if (s[i] == t) {
			pos = i + 1;
			cout << "Position: ";
			return pos;
		}
	}
	if (pos == 0) {
		cout << "There is no t-char in this strinf!\n";
		return -1;
	}
}

/*3*/    void Task_3()
{
	char* s = new char[1000];
	cout << "Enter your string:\n";
	cin.getline(s, 1000);
	char t;
	cout << "Enter char-target: ";	
	cin >> t;
	cout << Posfinder(s, t) << endl;
}

struct point {
	int x;
	int y;
};

struct treug {
	point a;
	point b;
	point c;
};

float dist(point a, point b) { return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)); }

bool prtr(treug t) {
	if ((pow(dist(t.a, t.b), 2) + pow(dist(t.b, t.c), 2) == pow(dist(t.c, t.a), 2)) || (pow(dist(t.b, t.c), 2) + pow(dist(t.c, t.a), 2) == pow(dist(t.a, t.b), 2)) || (pow(dist(t.c, t.a), 2) + pow(dist(t.a, t.b), 2) == pow(dist(t.b, t.c), 2)))return true;
	else return false;
}

/*2*/   void Prtr(int n, int m)
{
	treug* Tr = new treug[n];
	for (int i = 0; i < n; ++i) {
		Tr[i].a.x = rand() * (2 * m) - m;
		Tr[i].a.y = rand() * (2 * m) - m;
		Tr[i].b.x = rand() * (2 * m) - m;
		Tr[i].b.y = rand() * (2 * m) - m;
		Tr[i].c.x = rand() * (2 * m) - m;
		Tr[i].c.y = rand() * (2 * m) - m;
	}
	cout << "Show us right triangolas:\n";
	cout << endl;
	for (int i = 0; i < n; ++i) {
		if (prtr(Tr[i])) {
			cout << "Triangola:\n";
			cout << "A = " << "(" << Tr[i].a.x << ", " << Tr[i].a.y << endl;
			cout << "B = " << "(" << Tr[i].b.x << ", " << Tr[i].b.y << endl;
			cout << "C = " << "(" << Tr[i].c.x << ", " << Tr[i].c.y << endl;
		}
		cout << endl;
	}
	cout << endl;
	cout << "That's all right triangolas!\n";
	delete[] Tr;
}

bool ok(char* s) {
	bool flag;
	for (int i = 0; i < (strlen(s)/2); ++i) {
		if (s[i] == s[strlen(s) - 1 - i])flag = true;
		else {
			flag = false;
			break;
		}
	}
	return flag;
}

void Palindromer(char* s)
{
	char* s1 = new char[strlen(s)+1];
	for (int i = 0; i < strlen(s1); ++i) {
		s1[i] = s[i];
	}
	cout << strlen(s1) << endl;

	int k = strlen(s);
	if (ok(s)) {
		cout << s << endl;
		return;
	}
	else {		
		for (int i = 0; i < k; ++i) {
			s[i] = s1[strlen(s)-1-i];
		}
		cout << s1 << s;
		return;
	}
	delete[] s1;
}

/*4*/  void Task_4()
{
	char* s = new char[100];
	cout << "Enter the string:\n";
	cin.getline(s, 100);
	Palindromer(s);
}

void MatrSort(int** m, int a, int b)
{
	int* s = new int[b];
	for (int g = 0; g < b; ++g) {
		s[g] = 0;
	}
	for (int i = 0; i < b; ++i) {
		for (int j = 0; j < a; ++j) {
			if ((abs(m[j][i]) % 2) == 1 && m[j][i] < 0) {
				s[i] += abs(m[j][i]);
			}
		}
	}
	for (int i = 0; i < b; ++i) {
		cout << s[i] << "  ";
	}
	cout << endl;
	delete[] s;
}

/*5*/  void Task_5()
{
	int a, b;
	cout << "Enter number of lines of the matrix: ";
	cin >> a;
	cout << "Enter number of columns of the matrix: ";
	cin >> b;
	int** m = new int* [a];
	for (int i = 0; i < a; ++i) {
		m[i] = new int[b];
	}
	cout << "Enter elements of matrix:\n";
	for (int i = 0; i < a; ++i) {
		for (int j = 0; j < b; ++j) {
			cin >> m[i][j];
		}
	}
	cout << endl;
	MatrSort(m, a, b);
}

int main()
{
	Task_3();
	return 0;
}
