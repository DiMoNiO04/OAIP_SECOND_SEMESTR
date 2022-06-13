#include<iostream>
#include<string>
#include <windows.h>
#include <iomanip>
#include <ctime>


using namespace std;

enum menu {
	EXIT,
	LINE_SEARCH,
	BINARY_SEARCH,
	SORT,
	QUICK_SORT
};

int choiceMenu;

void menu();
void printArr(int* arr, int& size);
void lineSearch(int* arr, int& size);
void binarySearch(int* arr, int& size);
void sort(int* arr, int& size);
void swap(int* array, int first, int second);
void quickSort(int* arr, int leftSide, int rightSide);

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	int size=0;

	cout << "������� ������ �������: "; cin >> size;
	if (size < 1) {
		cout << "�������� ���� ������� �������";
		return 0;
	}
	else {
		int* arr = new int[size];
		for (int i = 0; i < size; i++) {
			arr[i] = rand() % 41 - 20;
		}

		menu();
		while (choiceMenu != EXIT) {
			
			system("cls");
			switch (choiceMenu) {
			case LINE_SEARCH: {
				lineSearch(arr, size);
				break;
			}
			case BINARY_SEARCH: {
				binarySearch(arr, size);
				break;
			}
			case SORT: {
				cout << "�������� ������: ";
				printArr(arr, size);
				cout << "���������� ������� ������� ������ �� ������� �������� �����������" << endl;
				sort(arr, size);
				printArr(arr, size);
				break;
			}
			case QUICK_SORT: {
				cout << "�������� ������: ";
				printArr(arr, size);
				cout << "������ ������������ � ������� ������� ����������" << endl;
				quickSort(arr, 0, size-1);
				printArr(arr, size);
				break;
			}
			case EXIT: {
				break;
			}
			}
			system("pause");
			system("cls");
			menu();
		}
	}
}

void menu() {

	cout << " 1. �������� ����� ����� � �������" << endl
		<< " 2. �������� ����� ����� � �������" << endl
		<< " 3. ���������� �������" << endl
		<< " 4. ���������� ������� quickSort �������" << endl
		<< " 0. ����� �� ���������" << endl
		<< "<< ";
	cin >> choiceMenu;
}

void printArr(int* arr, int& size) {
	
	cout << "��� ������: ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void lineSearch(int* arr, int& size) {

	printArr(arr, size);
	int searchNumber=0;
	cout << "�������� ������� ����� << ";  cin >> searchNumber;

	bool find = false;
	for (int i = 0; i < size; i++) {
		if (arr[i] == searchNumber) {
			cout << "������� ����� " << searchNumber << " ������� � ���������� �� ������� " << i + 1 << endl << endl;
			find = true;
			break;
		}
	}
	if (find == false) {
		cout << "������� ����� �� ������� � �������\n";
	}
}

void binarySearch(int* arr, int& size) {

	printArr(arr, size);
	int searchNumber = 0;
	cout << "�������� ������� ����� << ";  cin >> searchNumber;

	int lowest = 0, higher = size - 1;
	bool find = false;

	while (lowest <= higher) {
		int middle = (higher + lowest) / 2;
		int quess = arr[middle];
		if (arr[middle] == searchNumber) {
			cout << "������� ����� " << searchNumber << " ������� � ���������� �� ������� " << middle + 1 << endl << endl;
			find = true;
			break;
		}
		else if (searchNumber < quess) {
			higher = middle - 1;
		}
		else {
			lowest = middle + 1;
		}
	}
	if (find == false) {
		cout << "������� ����� �� ������� � �������\n";
	}
}

void sort(int* arr, int& size) {

	for (int i = 0; i < size - 1; i++) {
		int m = i;
		for (int j = i + 1; j < size; j++) {
			if (arr[j] < arr[m]) {
				m = j;
			}
		}
		int r = arr[m];
		arr[m] = arr[i];
		arr[i] = r;
	}
}

void quickSort(int* arr, int leftSide, int rightSide) {

	if (rightSide <= leftSide) {
		return;
	}

	int wall = leftSide, pivot = rightSide;
	for (int i = leftSide; i < rightSide; i++) {
		if (arr[i] < arr[pivot]) {
			swap(arr, i, wall);
			wall++;
		}
	}
	swap(arr, wall, pivot);
	quickSort(arr, leftSide, wall - 1);
	quickSort(arr, wall + 1, rightSide);
}

void swap(int* array, int first, int second){
	int temp = array[first];
	array[first] = array[second];
	array[second] = temp;
}