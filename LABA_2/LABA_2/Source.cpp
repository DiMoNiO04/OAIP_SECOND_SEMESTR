#include<iostream>

using namespace std;

int recFunction(int firstNumber, int secondNumber);
int function(int firstNumber, int secondNumber);

int main() {

	setlocale(LC_ALL, "RUS");
	int firstNumber, secondNumber;
	cout << "������� ������ ����� << "; cin >> firstNumber;
	cout << "������� ������ ����� << "; cin >> secondNumber;

	if (firstNumber != 0 || secondNumber != 0) {
		if (firstNumber < 0 || secondNumber < 0) {
			firstNumber = abs(firstNumber);
			secondNumber = abs(secondNumber);
		}
		cout << "\n����������� �������:\n��� ����� �����: " << recFunction(firstNumber, secondNumber);
		cout << "\n\n������� �������:\n��� ����� �����: " << function(firstNumber, secondNumber);
	}
	else {
		cout << "������� ������� �����, ������ �� ����� ���� ���������";
	}
}

int recFunction(int firstNumber, int secondNumber) {

	if (secondNumber % firstNumber == 0) 
		return firstNumber;
	else 
		recFunction(secondNumber % firstNumber, firstNumber);
}

int function(int firstNumber, int secondNumber) {

	while (firstNumber != secondNumber) {
		if (secondNumber > firstNumber) 
			secondNumber = secondNumber - firstNumber;
		else 
			firstNumber = firstNumber - secondNumber;
	}
	return secondNumber;
}
