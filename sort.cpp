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

//ð������(��ʼ��
void bubbleSort() {
	clock_t start, end;
	int n;
	cout << "���������ݵĸ���:";
	cin >> n;
	createFile(n);
	readFile();
	start = clock();
	int flag = 0;//��Ǳ����������ж��ڲ�ѭ���Ƿ����˽���
	for (int i = 1; i < n; i++) {
		flag = 0;
		for (int j = 2; j <= n - i + 1; j++) {
			if (A[j - 1] > A[j]) {
				Swap(A[j - 1], A[j]);
				flag = 1;//���������������flag=1
			}
		}
		if (flag == 0) {//���û�з���������˵��Ԫ���Ѿ�����ֱ�����
			for (int i = 1; i <= n; i++) {
				cout << A[i] << endl;
			}
			end = clock();
			cout << "ð������time = " << double(double(end) - double(start)) / CLOCKS_PER_SEC << "s" << endl;
			return;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		cout << A[i] << endl;
	}

	end = clock();
	cout << "ð������time = " << double(double(end) - double(start)) / CLOCKS_PER_SEC << "s" << endl;

}

void Swap(record& x, record& y) {
	record temp;
	temp = x;
	x = y;
	y = temp;
}
//ð�����򣨽�����


//ֱ��ѡ�����򣨿�ʼ��
void selectSort() {
	clock_t start, end;
	int n;
	cout << "���������ݵĸ���:";
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

	cout << "ֱ��ѡ������time = " << double(double(end) - double(start)) / CLOCKS_PER_SEC << "s" << endl;
}
//ֱ��ѡ�����򣨽�����


//��ֱ��)�������򣨿�ʼ��
void insertSort() {
	clock_t start, end;
	int n;
	cout << "���������ݵĸ���:";
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

	cout << "ֱ�Ӳ�������time = " << double(double(end) - double(start)) / CLOCKS_PER_SEC << "s" << endl;

}
//��ֱ��)�������򣨽�����


//ϣ�����򣨿�ʼ��
void shellSort() {//ѡ�õ���������Ϊ1,2,4,8.....
	clock_t start, end;
	int n,d;
	cout << "���������ݵĸ���:";
	cin >> n;
	createFile(n);
	readFile();
	start = clock();
	int i, k,q;
	for (d = n / 2; d >= 1; d = d / 2) {
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

			/*
			while (k >= 1) {
				if (A[i + k * d] < A[i + (k - 1) * d]) {
					Swap(A[i + k * d], A[i + (k - 1) * d]);
					k--;
				}
				else {
					k--;
				}
			}
			*/
			/*
			while (A[i + k * d] < A[i + (k - 1) * d] && k >= 1) {
				Swap(A[i + k * d], A[i + (k - 1) * d]);
				k--;
			}*/
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << A[i] << endl;
	}
	end = clock();

	cout << "ϣ������time = " << double(double(end) - double(start)) / CLOCKS_PER_SEC << "s" << endl;
}
//ϣ�����򣨽�����



//�������򣨿�ʼ��
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
	return 0;//����ȫ����ͬ������ֻ��һ������
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
//�������򣨽�����

void display(int n) {
	for (int i = 1; i <= n; i++) {
		cout << A[i] << endl;
	}
}
