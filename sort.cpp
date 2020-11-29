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
void bubbleSort(int n) {
	//clock_t start, end;
	//int n;
	//cout << "请输入数据的个数:";
	//cin >> n;
	//createFile(n);
	//readFile();
	//start = clock();
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
			//for (int i = 1; i <= n; i++) {
				//cout << A[i] << endl;
			//}
			//end = clock();
			//cout << "冒泡排序time = " << double(double(end) - double(start)) / CLOCKS_PER_SEC << "s" << endl;
			return;
		}
	}
	
//	for (int i = 1; i <= n; i++) {
	//	cout << A[i] << endl;
//	}

	//end = clock();
	//cout << "冒泡排序time = " << double(double(end) - double(start)) / CLOCKS_PER_SEC << "s" << endl;

}

void Swap(record& x, record& y) {
	record temp;
	temp = x;
	x = y;
	y = temp;
}
//冒泡排序（结束）


//直接选择排序（开始）
void selectSort(int n) {
	//clock_t start, end;
	//int n;
	//cout << "请输入数据的个数:";
	//cin >> n;
	//createFile(n);
	//readFile();
	//start = clock();
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

//	for (int i = 1; i <= n; i++) {
	//	cout << A[i] << endl;
	//}
	
	//end = clock();

	//cout << "直接选择排序time = " << double(double(end) - double(start)) / CLOCKS_PER_SEC << "s" << endl;
}
//直接选择排序（结束）


//（直接)插入排序（开始）
void insertSort(int n) {
	//clock_t start, end;
	//int n;
	//cout << "请输入数据的个数:";
	//cin >> n;
	//createFile(n);
	//readFile();
	
	//start = clock();
	
	int i, j;
	
	for (i = 2; i <= n; i++) {
		j = i;
		while (A[j] < A[j - 1]&& j > 1) {
			Swap(A[j], A[j - 1]);
			j--;
		}
	}
	
//	for (int i = 1; i <= n; i++) {
	//	cout << A[i] << endl;
//	}

	//end = clock();

	//cout << "直接插入排序time = " << double(double(end) - double(start)) / CLOCKS_PER_SEC << "s" << endl;

}
//（直接)插入排序（结束）


//希尔排序（开始）
void shellSort(int n) {//选用的增量序列为1,2,4,8.....
	
	int d;
	
	int i;
	int k;
	int j;

	for (d = n / 2; d >= 1; d = d / 2) {
		/*
		for (i = 1; i <= d; i++) {
			k = 0;
			while (i + k * d <= n) {
				k++;
			}
			k = k - 1;
			for (int s = 1; s <= k; s++) {
				q = s;
				while (A[i + q * d] < A[i + (q - 1) * d]&&q>=1) {
					Swap(A[i + q * d], A[i + (q - 1) * d]);
					q--;
				}
			}

		}
		*/
		for (int i = d + 1; i <= n; i++) {
			 j = i;
			 while (j - d >= 1 && A[j] < A[j - d]) {
				 Swap(A[j], A[j - d]);
				 j = j - d;
			 }
		}
	}
	
}
//希尔排序（结束）



//快速排序（开始）

//实现（一）
/*
int findPivot(int low, int high) {
	int flag;
	flag = A[low];
	for (int k = low + 1; k <= high; k++) {
		if (A[k] > flag) {
			return k;
		}
		else if (A[k] < flag) {
			return low;
		}
	}
	return 0;//数据全部相同，或者只有一个数据
}

int partition(int low, int high,int pivot) {
	int l, r;
	do {
		for (l = low; A[l] < A[pivot]; l++);
		for (r = high; A[r] >= A[pivot]; r--);
		if (l < r) {
			Swap(A[l], A[r]);
		}
	}while (l <= r);
	return l;
}

void quickSort(int low, int high) {
	int pivot;
	int k;
	pivot = findPivot(low, high);
	if (pivot != 0) {
		k = partition(low, high, pivot);
		quickSort(low, k - 1);
		quickSort(k, high);
	}
}
*/

//实现（二）
void quickSort(int low, int high) {
	if (low > high) {
		return;
	}
	int pivot = A[low];
	int i = low, j = high;

	while (i != j)
	{
		while (A[j] >= pivot && j > i) { j--; }
		while (A[i] <= pivot && i < j) { i++; }

		if (i < j) { Swap(A[i], A[j]); }
	}

	A[low] = A[i];
	A[i] = pivot;

	quickSort(i + 1, high);
	quickSort(low, i - 1);

}

//快速排序（结束）

void display(int n) {
	for (int i = 1; i <= n; i++) {
		cout << A[i] << endl;
	}
}


//堆排序（开始）
//(一）怎么利用无序的序列建堆
//（二）取除元素后怎么调整堆
void heapSort(int n) {
	int i;
	for (i = n / 2; i >= 1; i--) {
		heapAdjust(i, n);
	}//建立小根堆
	for (i = n; i >= 2; i--) {
		Swap(A[1], A[i]);
		heapAdjust(1, i - 1);
	}
}

void heapAdjust(int first, int last) {
	
	int r = first;
	while (r <= last / 2) {//r为非叶子结点
		if ((r == last / 2) && (last % 2 == 0)) {
			if (A[r] < A[2 * r]) {
				Swap(A[r], A[2 * r]);
			}
			r = last;
		}
		else if ((A[r] < A[2 * r]) &&( A[2 * r] >= A[2 * r + 1])) {
			Swap(A[r], A[2*r]);
			r = 2*r;
		}
		else if ((A[r] < A[2 * r + 1]) &&( A[2 * r + 1] > A[2 * r])) {
			Swap(A[r], A[2 * r+1]);
			r = 2 * r+1;
		}
		else {
			r = last;
		}
	}
	
}
//堆排序（结束）


//基数排序（开始）
int maxBit(int n) {
	int maxData = A[1];
	for (int i = 2; i <= n; i++) {
		if (A[i] > maxData) {
			maxData = A[i];
		}
	}
	int d = 1;
	while (maxData >= 10) {
		maxData /= 10;
		d++;
	}
	return d;
}

void radixSort(int n) {
	int d = maxBit(n);
	int* temp = new int[n+1];//临时数组，存储当前位排序过后的数组
	temp[0] = n;//0号位置不存数据，存数据的总个数
	int* count = new int[10];//象征0-9这10个筒
	int radix = 1;
	int i, j, k;
	for (i = 1; i <= d; i++) {//共有d个关键字，所以要排d趟
		for (j = 0; j < 10; j++) {
			count[j] = 0;//对每个桶置零
		}
		for (j = 1; j <= n; j++) {
			k = (A[j]/radix) % 10;
			count[k]++;//统计每个桶中的数据个数
		}
		for (j = 1; j <= 9; j++) {
			count[j] += count[j - 1];//将temp中的位置分给每个桶
		}
		for (j = n; j >= 1; j--) {
			k = (A[j] / radix) % 10;
			temp[count[k]] = A[j];
			count[k]--;
		}
		for (j = 1; j <= n; j++) {
			A[j] = temp[j];
		}
		radix = 10 * radix;
	}
	
	delete[] temp;
	delete[] count;
}
//基数排序（结束）


//菜单栏
void showMenu() {
	cout << "1、冒泡排序" << endl;
	cout << "2、快速排序" << endl;
	cout << "3、直接选择排序" << endl;
	cout << "4、堆排序" << endl;
	cout << "5、插入排序" << endl;
	cout << "6、希尔排序" << endl;
	cout << "7、基数排序" << endl;
	cout << "0、退出" << endl;
}



