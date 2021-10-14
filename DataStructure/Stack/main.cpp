#include <iostream>
#include "myStack.hpp"

using namespace std;
int main() {
	Stack stack(3);
	stack.push(3);
	stack.push(5);
	stack.push(7);
	stack.show();
	cout << "stack size " << stack.size() << endl;
	int pop = stack.pop();
	cout << "»©³½ °ª : " << pop << endl;
	stack.show();
	pop = stack.pop();
	cout << "»©³½ °ª : " << pop << endl;
	stack.show();

	
	return 0;
}