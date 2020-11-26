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

void createFile(int n);//生成数据
void readFile();//读数据

void bubbleSort();//冒泡排序
void Swap(record& x, record& y);//交换两数的值

void selectSort();//直接选择排序

void insertSort();//（直接)插入排序

void shellSort();//希尔排序

int findPivot(int low, int high);
int partition(int low, int high, int pivot);
void quickSort(int low, int high);

void display(int n);

