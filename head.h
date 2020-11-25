#pragma once
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <windows.h>

using namespace std;
typedef int record;
#define MAX 1000000

void createFile(int n);
void readFile();
void bubbleSort();
void Swap(record& x, record& y);
