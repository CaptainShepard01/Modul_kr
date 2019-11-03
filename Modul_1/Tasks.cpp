#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "Header.h"

using namespace std;

struct point {
	int x;
	int y;
};

struct treug {
	point a;
	point b;
	point c;
};


double fact(int n)
{
	if (n == 0 || n == 1)return 1;
	if (n < 0)return -1;
	double rez = 1;
	for (int i = 1; i <= n; ++i) rez *= i;
	return rez;
}

double sum(double eps)
{
	double rez = 0, cur = 0;
	bool flag = true;
	int i = 0;
	while (flag) {
		cur = (pow((-2), i) / fact(i));
		if (abs(cur) <= eps)break;
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

/*1*/void Task_1() {
	double eps;
	do {
		cout << "Enter your epsylon (>0): ";
		cin >> eps;
	} while (eps <= 0);
	cout << "Result: ";
	cout << sum(eps);
	cout << endl;
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

float dist(point a, point b) { return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2)); }

bool prtr(treug t) {
	if ((pow(dist(t.a, t.b), 2) + pow(dist(t.b, t.c), 2) == pow(dist(t.c, t.a), 2)) || (pow(dist(t.b, t.c), 2) + pow(dist(t.c, t.a), 2) == pow(dist(t.a, t.b), 2)) || (pow(dist(t.c, t.a), 2) + pow(dist(t.a, t.b), 2) == pow(dist(t.b, t.c), 2)))return true;
	else return false;
}

void Prtr(int n, int m)
{
	treug* Tr = new treug[n];
	for (int i = 0; i < n; ++i) {
			Tr[i].a.x = rand() % (2 * m) - m;
			Tr[i].a.y = rand() % (2 * m) - m;
			Tr[i].b.x = rand() % (2 * m) - m;
			Tr[i].b.y = rand() % (2 * m) - m;
			Tr[i].c.x = rand() % (2 * m) - m;
			Tr[i].c.y = rand() % (2 * m) - m;
	}
	cout << "Show us right triangolas (if there are some):\n";
	cout << endl;
	int count = 0;
	for (int i = 0; i < n; ++i) {
		if (prtr(Tr[i])) {
			cout << "Triangola:\n";
			cout << "A = " << "(" << Tr[i].a.x << ", " << Tr[i].a.y  << ")" << endl;
			cout << "B = " << "(" << Tr[i].b.x << ", " << Tr[i].b.y << ")" << endl;
			cout << "C = " << "(" << Tr[i].c.x << ", " << Tr[i].c.y << ")" << endl;
			cout << endl;
		}
	}
	cout << endl;
	cout << "That's all right triangolas!\n";
	delete[] Tr;
}

/*2*/  void Task_2()
{
	int n, m;
	cout << "Enter the number of triangolas: ";
	cin >> n;
	cout << "Enter max coordinate (integer): ";
	cin >> m;
	Prtr(n, m);
	cout << endl;
}

bool ok(char* s) {
	bool flag;
	for (int i = 0; i < (strlen(s) / 2); ++i) {
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
	int charcnt = 1;
	int cnt = 0;
	for (int l = 0; l <= (strlen(s)-1) / 2; ++l) {
		char* s1 = new char[charcnt];
		char* s2 = new char[charcnt];
		for (int j = 0; j < charcnt; ++j) {
			s1[charcnt - 1 - j] = s[strlen(s) - 1 - j];
		}
		for (int j = 0; j < charcnt; ++j) {
			s2[j] = s[strlen(s) - 1 - j - charcnt];
		}
		if (strcmp(s1, s2)==0)cnt = strlen(s) - charcnt - 1;
		++charcnt;
		delete[] s1;
		delete[] s2;
	}

	char* s1 = new char[cnt + 2];
	s1[cnt + 1] = '\0';
	for (int i = 0; i <= cnt; ++i) {
		s1[i] = s[i];
	}
	int z = strlen(s);
	char* sx = new char[cnt+2];
	sx[cnt + 1] = '\0';
	for (int k = 0; k <= cnt; ++k) {
		sx[k] = s1[strlen(s1)-1-k];
	}
	if (ok(s)) {
		cout << "Palindrom:\n";
		cout << s << endl;
		return;
	}
	if(strlen(s1)!=1) {
		cout << "Palindrom:\n";
		cout << s1 << sx << endl;
		return;
	}
	else {
		char* s3 = new char[strlen(s)+1];
		s3[strlen(s)] = '\0';
		for (int i = 0; i < strlen(s); ++i) {
			s3[i] = s[strlen(s) - 1 - i];
		}
		cout << "Palindrom:\n";
		cout << s << s3 << endl;
		delete[] s3;
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
	/*for (int i = 0; i < b; ++i) {
		cout << s[i] << "  ";
	}*/

	int min = 0;
	for (int i = 0; i < a; ++i) {
		for (int j = 0; j < b; ++j) {
			min = s[j];
			for (int k = j; k < b; ++k) {
				if (s[k] < min) {
					int temp = m[i][k];
					m[i][k] = m[i][j];
					m[i][j] = temp;
				}
			}
		}
	}

	cout << "Sorted Matrix:\n";

	for (int i = 0; i < a; ++i) {
		for (int j = 0; j < b; ++j) {
			cout << m[i][j] << " ";
		}
		cout << endl;
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
