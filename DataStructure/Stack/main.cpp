#include <iostream>
#include "myStack.hpp"
#include "Student.hpp"


using namespace std;

char openStr[4] = "({[";
char closeStr[4] = ")}]";

bool checkType(char myVal, char* type);
bool isCouple(char a, char b);
int main() {
	Stack<char> stack(100);
	char input[] = "()(){{[()]{}}}";
	for (int i = 0; i < sizeof(input)-1; i++) {
		// ������ ����ְ� �� ���� �������϶� ({,(,[) Ǫ��
		if (i == 0) {
			if (checkType(*input, openStr)) {
				stack.push(*(input));
				stack.show();
			}
			else if (checkType(*input, closeStr)) {
				cout << "error";
				break;
			}
		}
		else {
			// ���� ��ȣ�� �ϴ� Ǫ��
			if (checkType(*(input+i), openStr)) {
				stack.push(*(input + i));
			}
			else if (checkType(*(input+i), closeStr)) {
				// ������ȣ�� ������ �ְ� ��
				// �� ����ȣ�� �����ͼ� ¦�� �´��� ��
				stack.push(*(input + i));
				stack.show();
				char popVal = stack.pop();
				char curVal = stack.getTop();
				if (isCouple(curVal, popVal)) {
					cout << stack.getTop() << endl;
					stack.pop();
					cout << stack.getTop() << endl;
				}
				else {
					cout << "error";
					break;
				}

			}
		}

	}
	stack.show();
	if (stack.size() != 0) {
		cout << "error";
	}
	else {
		cout << "����ε� ��ȣ " << endl;
	}


	//Stack<Student> stack(10);
	//char name1[] = "seungho";
	//char dept1[] = "sw";
	//Student st1 = createStudent(20, name1, dept1);
	//char name2[] = "droid";
	//char dept2[] = "cs";
	//Student st2 = createStudent(29, name2, dept2);
	//stack.push(st1);
	//stack.push(st2);
	//Student* tops = stack.getStack();
	//for (int i = 1; i >=0; i--) {
	//	showStudent(tops + i);
	//}
	//Student popV = stack.pop();
	//cout << endl << "���� pop �� ��" << endl;
	//showStudent(&popV);
	//cout << endl << "���� ���ÿ� �ִ� �� " << endl;
	//Student gett = stack.getTop();
	//showStudent(&gett);
	return 0;
}
bool isCouple(char a, char b) {
	if (a == '(' && b == ')') {
		return true;
	}
	else if (a == '{' && b == '}') {
		return true;
	}
	else if (a == '[' && b == ']') {
		return true;
	}
	return false;
}
bool checkType(char myVal, char* type) {
	for (int i = 0; i < sizeof(type); i++) {
		if (*(type + i) == myVal) {
			return true;
		}
	}
	return false;
}