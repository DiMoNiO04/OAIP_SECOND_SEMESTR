#include<iostream>

using namespace std;  //����������� ������������ ����

//����� � ������� ����
enum mainChoice {
	EXIT,       //�����
	CREATE,     //�������� �������
	ADD,        //���������� � �������
	VIEW,       //�������� �������
	INDIVIDUAL, //������������� �������
	DELETE      //�������� �������
};


//������� ��������� �������
struct Spis2 {
	int info;  //������������� �����
	Spis2* prev, * next;  //�������� �����
} *top, * finish, * t;  //��������� �� ������ � ����� �������


void menu();  //����
void Creat(Spis2** top, Spis2** finish, int in);  //�������� �������
void Add(Spis2** top, Spis2** finish, int beginOrEnd, int in);  //�������� � �������
void View(int beginOrEnd, Spis2* t);   //�������� �������
void Del_All(Spis2** top);   //�������� �������
void Zadanie(Spis2** b, Spis2** e);


int main() {
	setlocale(LC_ALL, "RUS");  //���������� ������� ���������
	menu();  //����� ����
	system("pause");  //�������� �������
	system("cls");    //������� �������
	cout << "�� ��������!" << endl;
	return 0;
}


void menu() {
	int in, choice, beginOrEnd;
	while (true) {
		cout << "1. ������� �������\n2. �������� � �������\n3. ����������� �������\n4. �������� ������� ������� �������� �������.\n5. ������� �������\n0. �����\n<< "; cin >> choice;
		switch (choice) {
		case CREATE: {  
			cout << "��������� ���������� ������� << "; cin >> in;
			Creat(&top, &finish, in);  //�������� �������
			system("pause");  
			system("cls");
			break;
		}
		case ADD: {
			if (top) {
				cout << "������� ������� << "; cin >> in;
				cout << "�������� � ������ - 0, � ����� - 1?\n<< "; cin >> beginOrEnd;
				Add(&top, &finish, beginOrEnd, in);  //���������� � �������
				if (beginOrEnd == 0 || beginOrEnd == 1) {
					if (beginOrEnd == 0) {
						t = top;
					}
					else {
						t = finish;
					}
				}
				else {
					cout << "������������ �����\n";
				}
			}
			else {
				cout << "��� ������ �� ������ ������� �������, � ����� ������� �������� � ���\n";
			}
			system("pause");
			system("cls");
			break;
		}
		case VIEW: {
			if (!top) {
				cout << "������� �����!\n";
				system("pause");
				system("cls");
				break;
			}
			else {
				cout << "����������� � ������ - 0 , ����������� � ����� - 1\n<< "; cin >> beginOrEnd;
				if (beginOrEnd == 0) {
					t = top;
					cout << "������� �������: " << endl;
				}
				else {
					t = finish;
					cout << "������� � �����" << endl;
				}
				View(beginOrEnd, t);  //�������� �������
				system("pause");
				system("cls");
				break;
			}
			system("pause");
			system("cls");
			break;
		}
		case INDIVIDUAL: {
			cout << "\n����������� �������: ";
			View(beginOrEnd, t);  //�������� �������
			Zadanie(&top, &finish);
			cout << "\n������� � ���������� �������� ��������: ";
			View(beginOrEnd, t);  //�������� �������
			system("pause");
			system("cls");
			break;
		}
		case DELETE: {
			Del_All(&top);   //�������� �������
			cout << "������� �������\n";
			system("pause");
			system("cls");
			break;
		}
		case EXIT: {
			if (top != NULL) {
				Del_All(&top);  //�������� �������
			}
			return;
		}
		default: {
			cout << "������������ ����. ��������� �������";
			system("pause");
			system("cls");
		}
		}
	}
}

void Creat(Spis2** top, Spis2** finish, int in) {
	t = new Spis2;   //������ ������, ����������� ���������� ����� � ��
	t->info = in;  //���� ���������� � ������������ ��
	t->next = t->prev = NULL;  //��������� �������� �����
	*top = *finish = t;  //������������� ��������� ������ � ����� �� ��������� ������ �������
}

void Add(Spis2** top, Spis2** finish, int beginOrEnd, int in) {
	t = new Spis2;  //������ ������, ����������� ���������� ����� � ��
	t->info = in;   //���� ���������� � ������������ ��
	if (beginOrEnd == 0) {  //���� ���������� � ������
		t->prev = NULL;    //����������� ���
		t->next = *top;    //����� ������� ��������� � ������
		(*top)->prev = t;  //�������� ����� ������� �������
		*top = t;          //������������ ��������� ������ �� �����
	}
	else if(beginOrEnd == 1){  //���� ���������� � �����
		t->next = NULL;      //���������� ���
		t->prev = *finish;   //��������� ����� ������� � ���������
		(*finish)->next = t; //�������� ����� ������� ����������
		*finish = t;         //������������ ��������� ����� �� �����
	}
}


void View(int beginOrEnd, Spis2* t) {
	while (t) {  //���� ������� �� �����
		cout << t->info << "  ";  //������� ��
		if (beginOrEnd == 0) { //���� ����� � ������
			t = t->next;   //������������ ��������� �� ���������
		}
		else {            //���� ����� � �����
			t = t->prev;  //������������ ��������� �� ����������
		}
	}
	cout << endl;
}

void Del_All(Spis2** top) {
	while (*top) {   //���� ������� �� �����
		t = *top;   //������������ ��������� �� ������
		*top = (*top)->next;   //������ ����� ���������
		delete t;   //������������ ����������� ����� ������
	}
}


void Zadanie(Spis2** b, Spis2** e){
	int a;
	a = top->info;
	top->info = finish->info;
	finish->info = a;
}
