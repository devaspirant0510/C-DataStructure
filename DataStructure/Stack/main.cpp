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
	cout << "빼낸 값 : " << pop << endl;
	stack.show();
	pop = stack.pop();
	cout << "빼낸 값 : " << pop << endl;
	stack.show();
	cout << "현재 스택에서 가장 위에있는값 : " << stack.getTop() << endl;
	return 0;
}