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
			cout << "time = " << double(double(end) - double(start)) / CLOCKS_PER_SEC << "s" << endl;
			return;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		cout << A[i] << endl;
	}

	end = clock();
	cout << "time = " << double(double(end) - double(start)) / CLOCKS_PER_SEC << "s" << endl;

}

void Swap(record& x, record& y) {
	record temp;
	temp = x;
	x = y;
	y = temp;
}
//ð�����򣨽�����

//�������򣨿�ʼ��

