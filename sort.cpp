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
void bubbleSort(int n) {
	//clock_t start, end;
	//int n;
	//cout << "���������ݵĸ���:";
	//cin >> n;
	//createFile(n);
	//readFile();
	//start = clock();
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
			//for (int i = 1; i <= n; i++) {
				//cout << A[i] << endl;
			//}
			//end = clock();
			//cout << "ð������time = " << double(double(end) - double(start)) / CLOCKS_PER_SEC << "s" << endl;
			return;
		}
	}
	
//	for (int i = 1; i <= n; i++) {
	//	cout << A[i] << endl;
//	}

	//end = clock();
	//cout << "ð������time = " << double(double(end) - double(start)) / CLOCKS_PER_SEC << "s" << endl;

}

void Swap(record& x, record& y) {
	record temp;
	temp = x;
	x = y;
	y = temp;
}
//ð�����򣨽�����


//ֱ��ѡ�����򣨿�ʼ��
void selectSort(int n) {
	//clock_t start, end;
	//int n;
	//cout << "���������ݵĸ���:";
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

	//cout << "ֱ��ѡ������time = " << double(double(end) - double(start)) / CLOCKS_PER_SEC << "s" << endl;
}
//ֱ��ѡ�����򣨽�����


//��ֱ��)�������򣨿�ʼ��
void insertSort(int n) {
	//clock_t start, end;
	//int n;
	//cout << "���������ݵĸ���:";
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

	//cout << "ֱ�Ӳ�������time = " << double(double(end) - double(start)) / CLOCKS_PER_SEC << "s" << endl;

}
//��ֱ��)�������򣨽�����


//ϣ�����򣨿�ʼ��
void shellSort(int n) {//ѡ�õ���������Ϊ1,2,4,8.....
	
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
//ϣ�����򣨽�����



//�������򣨿�ʼ��

//ʵ�֣�һ��
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
*/

//ʵ�֣�����
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

//�������򣨽�����

void display(int n) {
	for (int i = 1; i <= n; i++) {
		cout << A[i] << endl;
	}
}


//�����򣨿�ʼ��
//(һ����ô������������н���
//������ȡ��Ԫ�غ���ô������
void heapSort(int n) {
	int i;
	for (i = n / 2; i >= 1; i--) {
		heapAdjust(i, n);
	}//����С����
	for (i = n; i >= 2; i--) {
		Swap(A[1], A[i]);
		heapAdjust(1, i - 1);
	}
}

void heapAdjust(int first, int last) {
	
	int r = first;
	while (r <= last / 2) {//rΪ��Ҷ�ӽ��
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
//�����򣨽�����


//�������򣨿�ʼ��
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
	int* temp = new int[n+1];//��ʱ���飬�洢��ǰλ������������
	temp[0] = n;//0��λ�ò������ݣ������ݵ��ܸ���
	int* count = new int[10];//����0-9��10��Ͳ
	int radix = 1;
	int i, j, k;
	for (i = 1; i <= d; i++) {//����d���ؼ��֣�����Ҫ��d��
		for (j = 0; j < 10; j++) {
			count[j] = 0;//��ÿ��Ͱ����
		}
		for (j = 1; j <= n; j++) {
			k = (A[j]/radix) % 10;
			count[k]++;//ͳ��ÿ��Ͱ�е����ݸ���
		}
		for (j = 1; j <= 9; j++) {
			count[j] += count[j - 1];//��temp�е�λ�÷ָ�ÿ��Ͱ
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
//�������򣨽�����


//�˵���
void showMenu() {
	cout << "1��ð������" << endl;
	cout << "2����������" << endl;
	cout << "3��ֱ��ѡ������" << endl;
	cout << "4��������" << endl;
	cout << "5����������" << endl;
	cout << "6��ϣ������" << endl;
	cout << "7����������" << endl;
	cout << "0���˳�" << endl;
}



