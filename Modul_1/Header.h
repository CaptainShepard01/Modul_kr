#pragma once
#include <stdio.h>
#include <iostream>
#include <cstdlib>

using namespace std;

struct point;

struct treug;

double fact(int n);
double sum(double eps);
void Task_1();

float dist(point a, point b);
bool prtr(treug t);
void Prtr(int n, int m);
void Task_2();

void Posfinder(char* s, char t);
void Task_3();

bool ok(char* s);
void Palindromer(char* s);
void Task_4();


void MatrSort(int** m, int a, int b);
void Task_5();

int main();


