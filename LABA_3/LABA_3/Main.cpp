//���������� ����������
#include<iostream>
#include<random>
#include<iomanip>

using namespace std;  //����������� ������������ ����

struct Stack {    //��������� ����������������� �����
	int info;     //������������� ����� �����
	Stack* next;  //�������� ����� �����(��������� �� ���� �������)
}*top, * t;       //������� ����� - top, ������� ��������� - t

enum mainChoice {  //���� ��� ������
	EXIT,          //�����(0)
	CREATE,        //������� ����(1)
	ADD,           //�������� ����(2)
	VIEW,          //����������� ����(3)
	DELETE,        //������� ����(4)
	SORT,          //����������� ����(5)
	INDIVIDUAL     //�������������� �������(6)
};

void menu();                      //������� ����
Stack* InStack(Stack* p, int in); //���������� �������� � ����
void View(Stack* p);              //������������� ����  
void Del_All(Stack*& p);          //������� ����
Stack* Del_Otr(Stack* b);         //�������������� �������
void Sort_info(Stack* p);         //���������� �����

int main() {                   //������� �������
	setlocale(LC_ALL, "RUS");  //���������� ������� ����������
	srand(time(NULL));         //������ ������ ������
	menu();                    //����� �������� ����
	system("pause");           //�������� �������
	system("cls");             //�������� �������
	cout << "�� ��������!\n";
	return 0;
}

void menu() {
	int in, size, choice;

	while (true) {
		cout << "1. ������� ����\n2. �������� ������ � ����\n3. �������� �����\n4. ������� ����\n5. C��������� �����\n6. ������� �� ���������� ����� ������������� ��������.\n0. �����\n<< "; cin >> choice;
		switch (choice) {
		case CREATE: case ADD: {
			if (choice == CREATE && top != NULL) {
				cout << "������ �����!";
				break;
			}
			cout << "������� ������ ������ �������� << "; cin >> size;
			if (size <= 0) {
				cout << "������������ ����.\n";
			}
			else {
				for (int number = 0; number < size; number++) {
					in = rand() % 21 - 10;  //��������� ��������� �����
					top = InStack(top, in); //��������� � �������
				}
				if (choice == CREATE) {
					cout << "������ ���� �������� �� " << size << " ���������" << endl;
				}
				else {
					cout << "��������� � ���� " << size << " ���������" << endl;
				}
			}
			system("pause");
			system("cls");
			break;
		}
		case VIEW: {           //�������� �����
			if (top == NULL) {  //��������� ���� ���� ����
				cout << "���� ����\n";
				system("pause");
				system("cls");
				break;
			}
			cout << setw(30) << "����: " << endl;
			View(top);  //������� ����
			system("pause");
			system("cls");
			break;
		}
		case DELETE: {
			Del_All(top);
			cout << "���� ����������!" << endl;
			system("pause");
			system("cls");
			break;
		}
		case SORT: {
			if (top == NULL)
			{
				cout << "���� ����\n";
				system("pause");
				system("cls");
				break;
			}
			cout << setw(30) << "����: " << endl;
			Sort_info(top);
			View(top);
			system("pause");
			system("cls");
			break;
		}
		case INDIVIDUAL: {
			if (top == NULL)
			{
				cout << "���� ����\n";
				system("pause");
				system("cls");
				break;
			}
			top = Del_Otr(top);
			cout << setw(30) << "����� ���� ��� ������������� �����:" << endl;
			View(top);
			system("pause");
			system("cls");
			break;
		}
		case EXIT: {
			if (top != NULL) {
				Del_All(top);
			}
			return;
		}
		default: {
			cout << "�������� ����. ��������� �������\n";
			system("pause");
			system("cls");
		}
		}
	}
}

Stack* InStack(Stack* p, int in) {  //���������� �������� � ����
	Stack* t = new Stack;  //�������� ������ ������
	t->info = in;  //������������� ����� ������� , ���������� ����� �������
	t->next = p;   //������� ���������� �������� �� t (����� �������)
	return t;      //��������� ������� �����
}


void View(Stack* p) {  //������������� ����
	Stack* t = p;
	while (t != NULL) {   //���� ���� �� ������
		cout << " " << t->info << endl;   //������� �� ����� �������������� �����
		t = t->next;  //������������ ��������� t �� ��������� �������
	}
	cout << endl;
}

void Del_All(Stack*& p) {  //�������� ������������ ������
	Stack* t;
	while (p != NULL) {
		t = p;
		p = p->next;
		delete t;   //������������ ����������� ����� ������
	}
}

Stack* Del_Otr(Stack* b) {  //�������������� �������
	b = InStack(b, 21);  //��������� ����� �����
	Stack* p = b;        //���������� � �������
	t = p->next;         //������� t= �������
	while (t != NULL) {  //���� �� ����
		if (t->info < 0) { //���� �� ������ 0
			p->next = t->next;
			delete t;  //������� �������� t
			t = p->next; //��������� � ������ ������ ��������� �� t
		}
		else {
			p = t;
			t = t->next;
		}
	}
	//�������� �� ������� ������������ ��������
	t = b;
	b = b->next;
	delete t;  //������������ ����������� ����� ������
	return b;
}

void Sort_info(Stack* p) {  //���������� �����
	Stack* t = NULL, * t1;
	int r;
	do {
		for (t1 = p; t1->next != t; t1 = t1->next) {
			if (t1->info > t1->next->info) {
				r = t1->info;
				t1->info = t1->next->info;
				t1->next->info = r;
			}
		}
		t = t1;
	} while (p->next != t);
}
