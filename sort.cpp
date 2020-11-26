#include "head.h"

record A[MAX] = { 0 };

void createFile(int n) {
	FILE* fp_w;
	fopen_s(&fp_w, "data.txt", "w");
	fprintf(fp_w, "%d\n", n);
	srand(time(0));
	for (int i = 1; i <= n; i++) {
		fprintf(fp_w, "%d ", (rand() % n)+1);
	}
	fclose(fp_w);
}

void readFile() {
	int n;
	FILE* fp_r;
	fopen_s(&fp_r, "data.txt", "r");
	fscanf_s(fp_r, "%d", &n);
	A[0] = n;
	for (int i = 1; i <= n; i++) {
		fscanf_s(fp_r, "%d", &A[i]);
	}
	fclose(fp_r);
}

//冒泡排序(开始）
void bubbleSort() {
	clock_t start, end;
	int n;
	cout << "请输入数据的个数:";
	cin >> n;
	createFile(n);
	readFile();
	start = clock();
	int flag = 0;//标记变量，用来判断内层循环是否发生了交换
	for (int i = 1; i < n; i++) {
		flag = 0;
		for (int j = 2; j <= n - i + 1; j++) {
			if (A[j - 1] > A[j]) {
				Swap(A[j - 1], A[j]);
				flag = 1;//如果发生交换，则flag=1
			}
		}
		if (flag == 0) {//如果没有发生交换，说明元素已经有序，直接输出
			for (int i = 1; i <= n; i++) {
				cout << A[i] << endl;
			}
			end = clock();
			cout << "冒泡排序time = " << double(double(end) - double(start)) / CLOCKS_PER_SEC << "s" << endl;
			return;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		cout << A[i] << endl;
	}

	end = clock();
	cout << "冒泡排序time = " << double(double(end) - double(start)) / CLOCKS_PER_SEC << "s" << endl;

}

void Swap(record& x, record& y) {
	record temp;
	temp = x;
	x = y;
	y = temp;
}
//冒泡排序（结束）


//直接选择排序（开始）
void selectSort() {
	clock_t start, end;
	int n;
	cout << "请输入数据的个数:";
	cin >> n;
	createFile(n);
	readFile();
	start = clock();
	int min_key, min_index;
	for (int i = 1; i < n; i++) {
		min_index = i;
		min_key = A[i];
		for (int j = i + 1; j <= n; j++) {
			if (A[j] < min_key) {
				min_key = A[j];
				min_index = j;
			}
		}
		if (min_index != i) {
			Swap(A[i], A[min_index]);
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << A[i] << endl;
	}
	
	end = clock();

	cout << "直接选择排序time = " << double(double(end) - double(start)) / CLOCKS_PER_SEC << "s" << endl;
}
//直接选择排序（结束）


//（直接)插入排序（开始）
void insertSort() {
	clock_t start, end;
	int n;
	cout << "请输入数据的个数:";
	cin >> n;
	createFile(n);
	readFile();
	
	start = clock();
	
	int i, j;
	
	for (i = 2; i <= n; i++) {
		j = i;
		while (A[j] < A[j - 1]&& j > 1) {
			Swap(A[j], A[j - 1]);
			j--;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		cout << A[i] << endl;
	}

	end = clock();

	cout << "直接选择排序time = " << double(double(end) - double(start)) / CLOCKS_PER_SEC << "s" << endl;

}
//（直接)插入排序（结束）