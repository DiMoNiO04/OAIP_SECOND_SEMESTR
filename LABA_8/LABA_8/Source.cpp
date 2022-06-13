#include <iostream>
#include <conio.h>

using namespace std;

double simpson(double a, double b, int n);
double fun(double x);

int main() {

	setlocale(LC_ALL, "RUS");
	double a, b;
	int n;
	
	cout << "������� ����� ������� ������� a = "; cin >> a;
	cout << "������� ������ ������� ������� b =  "; cin >> b;
	cout << "������� ��� ��� ��������� n = "; cin >> n;
	cout <<"����� = "<< simpson(a, b, n);
}

double fun(double x) {
	return 4 * x * x * x;
	//return log(x) - 5 * cos(x);
}

double simpson(double a, double b, int n) {
	double s = 0, h, x;
	h = (b - a) / n;
	x = a;

	for (int i = 1; i <= n; i++) {
		s += fun(x) + 4 * fun(x + h / 2) + fun(x + h);
		x += h;
	}
	return s * h / 6;
}
