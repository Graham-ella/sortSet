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

void createFile(int n);//��������
void readFile();//������

void bubbleSort(int n);//ð������
void Swap(record& x, record& y);//����������ֵ

void selectSort(int n);//ֱ��ѡ������

void insertSort(int n);//��ֱ��)��������

void shellSort(int n);//ϣ������

int findPivot(int low, int high);
int partition(int low, int high, int pivot);
void quickSort(int low, int high);

void display(int n);

void heapSort(int n);
void heapAdjust(int first, int last);


void showMenu();

