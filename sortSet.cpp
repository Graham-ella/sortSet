#include "head.h"
int main() {
	clock_t start, end;
	int n;
	int select = 0;
	while (true) {
		showMenu();
		cin >> select;
		switch (select) {
			case 1:
				cout << "请输入数据的个数:";
				cin >> n;
				createFile(n);//生成随机数
				readFile();//给A赋值
				start = clock();
				bubbleSort(n);
				end = clock();
				//display(n);
				cout << "冒泡排序time = " << double(double(end) - double(start)) / CLOCKS_PER_SEC << "s" << endl;
				system("pause");
				system("cls");
				break;
			case 2:
				cout << "请输入数据的个数:";
				cin >> n;
				createFile(n);//生成随机数
				readFile();//给A赋值
				start = clock();
				quickSort(1, n);
				end = clock();
				//display(n);
				cout << "快速排序time = " << double(double(end) - double(start)) / CLOCKS_PER_SEC << "s" << endl;
				system("pause");
				system("cls");
				break;
			case 3:
				cout << "请输入数据的个数:";
				cin >> n;
				createFile(n);//生成随机数
				readFile();//给A赋值
				start = clock();
				selectSort(n);
				end = clock();
				//display(n);
				cout << "直接选择排序time = " << double(double(end) - double(start)) / CLOCKS_PER_SEC << "s" << endl;
				system("pause");
				system("cls");
				break;
			case 4:
				cout << "请输入数据的个数:";
				cin >> n;
				createFile(n);//生成随机数
				readFile();//给A赋值
				start = clock();
				heapSort(n);
				end = clock();
				//display(n);
				cout << "堆排序time = " << double(double(end) - double(start)) / CLOCKS_PER_SEC << "s" << endl;
				system("pause");
				system("cls");
				break;
			case 5:
				cout << "请输入数据的个数:";
				cin >> n;
				createFile(n);//生成随机数
				readFile();//给A赋值
				start = clock();
				insertSort(n);
				end = clock();
				//display(n);
				cout << "插入排序time = " << double(double(end) - double(start)) / CLOCKS_PER_SEC << "s" << endl;
				system("pause");
				system("cls");
				break;
			case 6:
				cout << "请输入数据的个数:";
				cin >> n;
				createFile(n);//生成随机数
				readFile();//给A赋值
				start = clock();
				shellSort(n);
				end = clock();
				//display(n);
				cout << "希尔排序time = " << double(double(end) - double(start)) / CLOCKS_PER_SEC << "s" << endl;
				system("pause");
				system("cls");
				break;
			case 7:
				cout << "请输入数据的个数:";
				cin >> n;
				createFile(n);//生成随机数
				readFile();//给A赋值
				start = clock();
				radixSort(n);
				end = clock();
				//display(n);
				cout << "基数排序time = " << double(double(end) - double(start)) / CLOCKS_PER_SEC << "s" << endl;
				system("pause");
				system("cls");
				break;

			case 0:
				cout << "欢迎下次再来!" << endl;
				system("pause");
				return 0;
			default:
				cout << "非法输入，请重新输入" << endl;
				break;
		


		}
	}
}