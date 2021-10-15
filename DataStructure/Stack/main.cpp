#include <iostream>
#include "myStack.hpp"

using namespace std;
int main() {
	Stack<char> stack(3);
	stack.push('+');
	stack.push('s');
	stack.push('-');
	stack.show();
	cout << "stack size " << stack.size() << endl;
	int pop = stack.pop();
	cout << "���� �� : " << pop << endl;
	stack.show();
	pop = stack.pop();
	cout << "���� �� : " << pop << endl;
	stack.show();
	cout << "���� ���ÿ��� ���� �����ִ°� : " << stack.getTop() << endl;
	return 0;
}