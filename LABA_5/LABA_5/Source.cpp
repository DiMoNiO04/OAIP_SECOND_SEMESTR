#include<iostream>
#include<string>

using namespace std;


struct Tree {
	int key;
	string surname;
	Tree* left, * right;
} *root;

enum mainMenu {
	EXIT,
	CREATE,
	ADD,
	VIEW,
	DELETE_FOR_KEY,
	FIND,
	COUNT_SYMBOLS,
	DELETE_TREE
};

enum mainViewMenu {
	EXIT_FROM_VIEW,
	DIRECT_BYPASS,
	REVERSE_BYPASS,
	ASCENDING_KEY,
	TREE_VIEW
};

enum mainTaskMenu {
	DIRECT_TASK=1,
	REVERSE_TASK,
	ASCENDING_TASK
};

void mainMenu();
void mainViewMenu();
void createTree(int number, string surname);
void addInTree(int number, string surname);
void DirectView(Tree* root);
void ReverseView(Tree* root);
void AscendingOrderView(Tree* root);
void View_Tree(Tree* p, int level);
void view();
void Del_Tree(Tree* t);
void findForKey(int number);
void DirectViewTask(Tree* root);
void ReverseViewTask(Tree* root);
void AscendingOrderViewTask(Tree* root);
void individualTask();


int main() {
	setlocale(LC_ALL, "RUS");
	string surname;
	int mainChoice, number=0;

	while (true) {
		system("pause");
		system("cls");
		mainMenu();
		cin >> mainChoice;

		switch (mainChoice) {
		case CREATE: {
			createTree(number, surname);
			break;
		}
		case ADD: {
			addInTree(number, surname);
			break;
		}
		case VIEW: {
			view();
			break;
		}
		case DELETE_FOR_KEY: {

			if (!root) {
				cout << " �������� ������ !\n";
				break;
			}
			cout << "������� ���� ������� ����� �������: "; cin >> number;
			Tree* Del, * Prev_Del, * R, * Prev_R;
			Del = root;
			Prev_Del = NULL;
			while (Del != NULL && Del->key != number) {
				Prev_Del = Del;
				if (Del->key > number) {
					Del = Del->left;
				}
				else {
					Del = Del->right;
				}
			}
			if (Del == NULL) { // ������� �� ������
				cout << "���� �� ������!\n";
				break;
			}
			//-------------------- ����� �������� R ��� ������ --------------------------------
			if (Del->right == NULL) {
				R = Del->left;
			}
			else {
				if (Del->left == NULL) {
					R = Del->right;
				}
				else {
					//---------------- ���� ����� ������ ���� � ����� ��������� -----------------
					Prev_R = Del;
					R = Del->left;
					while (R->right != NULL) {
						Prev_R = R;
						R = R->right;
					}
					//----------- ����� ������� ��� ������ R � ��� ������ Prev_R -------------
					if (Prev_R == Del) {
						R->right = Del->right;
					}
					else {
						R->right = Del->right;
						Prev_R->right = R->left;
						R->left = Prev_R;
					}
				}
			}
			if (Del == root) {
				root = R; // ������ ������, �������� ��� �� R
			}
			else {
				//------- ��������� R ������������ � ������ ���������� ���� -----------
				if (Del->key < Prev_Del->key) {
					Prev_Del->left = R; // �� ����� �����
				}
				else {
					Prev_Del->right = R; // �� ������ �����
				}
			}
			delete Del;
			cout << "���� ������!\n";
			break;
		}
		case FIND: {
			findForKey(number);
			break;
		}
		case COUNT_SYMBOLS: {
			individualTask();
			break;
		}
		case DELETE_TREE: {
			Del_Tree(root);
			cout << "������ �������!\n";
			root = NULL;
			break;
		}
		case EXIT: {
			if (root != NULL) {
				Del_Tree(root);
			}
			return 0;
		}
		}
	}
}

void mainMenu() {
	cout << "1. ������� ������\n"
		<< "2. ��������\n"
		<< "3. ��������\n"
		<< "4. �������� �� �����\n"
		<< "5. ����� �� �����\n"
		<< "6. ���������� �������� �� ���� �������� ������\n"
		<< "7. ������� ������\n"
		<< "0. ����� �� ���������\n"
		<< "<< ";
}

void mainViewMenu() {
	cout << "� ����� ������� ������� ������ ?\n"
		<< "1. ������ �������\n"
		<< "2. �������� �������\n"
		<< "3. �������� ����������� �����\n"
		<< "4. �������� � ���� ������\n"
		<< "<< ";
}

void createTree(int number, string surname) {

	cout << "������� ������ ������:\n";
	cout << "������� ���� ����� << "; cin >> number;
	cout << "������� ������� << "; cin >> surname;
	Tree* t = new Tree;
	t->key = number;
	t->surname = surname;
	t->left = t->right = NULL;
	root = t;
}

void addInTree(int number, string surname) {

	if (root == NULL) {
		cout << "�������� ������� ������ ������\n";
	}
	else {
		cout << "������� ���� << "; cin >> number;
		cout << "������� ������� << "; cin >> surname;

		Tree* prev, * t;
		bool find = true;
		t = root;
		prev = t;

		while (t && find) {
			prev = t;
			if (number == t->key) {
				find = false;
				cout << "���� ��� ������������ � ���������. ���� ������ ���� ��������!";
			}
			else {
				if (number < t->key) {
					t = t->left;
				}
				else {
					t = t->right;
				}
			}
		}

		if (find) {
			Tree* t = new Tree;
			t->key = number;
			t->surname = surname;
			t->left = t->right = NULL;
			if (number < prev->key) {
				prev->left = t;
			}
			else {
				prev->right = t;
			}
		}
	}
}

void DirectView(Tree* root) {

	if (root) {
		cout << "����: " << root->key << " ���: " << root->surname << endl;
		DirectView(root->left);
		DirectView(root->right);
	}
}

void ReverseView(Tree* root) {

	if (root) {
		ReverseView(root->left);
		ReverseView(root->right);
		cout << "����: " << root->key << " ���: " << root->surname << endl;
	}
}

void AscendingOrderView(Tree* root) {

	if (root) {
		AscendingOrderView(root->left);
		cout << "����: " << root->key << " ���: " << root->surname << endl;
		AscendingOrderView(root->right);
	}
}

void View_Tree(Tree* p, int level) {

	string str;
	if (p) {
		View_Tree(p->right, level + 1);
		for (int i = 0; i < level; i++) {
			str = str + "  ";
		}
		cout << str << p->key << "-" << p->surname << endl;
		View_Tree(p->left, level + 1);
	}
}

void view() {

	if (root == NULL) {
		cout << "�������� ������!";
	}
	else {
		int choiceView;
		mainViewMenu();
		cin >> choiceView;

		switch (choiceView) {
		case DIRECT_BYPASS: {
			DirectView(root);
			break;
		}
		case REVERSE_BYPASS: {
			ReverseView(root);
			break;
		}
		case ASCENDING_KEY: {
			AscendingOrderView(root);
			break;
		}
		case TREE_VIEW: {
			View_Tree(root, 0);
			break;
		}
		case EXIT_FROM_VIEW: {
			break;
		}
		}
	}
}

void Del_Tree(Tree* t) {

	if (t != NULL) {
		Del_Tree(t->left);
		Del_Tree(t->right);
		delete t;
	}
}

void findForKey(int number) {

	if (!root) {
		cout << "�������� ������!\n";
	}
	cout << "������� ����, ������� ������ ����� << "; cin >> number;
	Tree* t = root;

	while (root != NULL) {
		if (root->key == number) {
			cout << "��������� ������: " << "����: " << root->key << "   ���: " << root->surname << endl;
			break;
		}
		else {
			if (number < root->key) {
				root = root->left;
			}
			else {
				root = root->right;
			}
		}
	}
	if (root == NULL) {
		cout << "�������� �� �������" << endl;
	}
	root = t;
}

void DirectViewTask(Tree* root){
	if (root) {
		cout << "����: " << root->key << "   ---> " << root->surname.length() <<endl;
		DirectViewTask(root->left); // ������ ���������
		DirectViewTask(root->right); // ����� ���������
	}
}

void ReverseViewTask(Tree* root){
	if (root)
	{
		ReverseViewTask(root->left); // ������ ���������
		ReverseViewTask(root->right); // ����� ���������
		cout << "����: " << root->key << "   ---> " << root->surname.length() << endl;
	}
}

void AscendingOrderViewTask(Tree* root){
	if (root) {
		AscendingOrderViewTask(root->left); // ����� ���������
		cout << "����: " << root->key << "   ---> " << root->surname.length() << endl;
		AscendingOrderViewTask(root->right); // ������ ���������
	}
}

void individualTask() {

	if (root == NULL) {
		cout << " �������� ������ !";
	}
	else {
		int choiceCount = 0;
		cout << "� ����� ������� �������� ���������� �������� � ������� ������:\n 1. ������ �������\n2. �������� �������\n3. � ������� ����������� �����\n<< "; cin >> choiceCount;
		switch (choiceCount) {
		case DIRECT_TASK: {
			DirectViewTask(root);
			break;
		}
		case REVERSE_TASK: {
			ReverseViewTask(root);
			break;
		}
		case ASCENDING_TASK: {
			AscendingOrderViewTask(root);
			break;
		}
		}
	}
}



