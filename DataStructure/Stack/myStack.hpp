#include <iostream>


using namespace std;

int MAX_STACK_SIZE = 1000;

char STACK_IS_FULL[] = "error ! stack is full";
char STACK_IS_EMPTY[] = "error ! stack is empty";

class Stack {
private:
	int maxSize;
	int *stack;
	int top = -1;

public:
	Stack(int maxSize);
	void error(char* err);
	bool isEmpty();
	bool isFull();
	void push(int t);
	int size();
	int pop();
	void show();
};

Stack::Stack(int maxSize = MAX_STACK_SIZE) {
	cout << "stack size is " << maxSize << endl;
	this->maxSize = maxSize;
	this->stack = new int[maxSize];
}
void Stack::error(char* err) {
	cout << err << endl;
	exit(1);
}
bool Stack::isEmpty() {
	return top == -1;
}
bool Stack::isFull() {
	return top+1 == maxSize;

}

void Stack::push(int t) {
	// stack 이 꽉차있을시 에러
	if (isFull()) {
		error(STACK_IS_FULL);
	}
	else {
		cout << "push stack " << t << endl;
		stack[++top] = t;
	}
}
int Stack::pop() {
	// stack이 비어있을시 에러
	if (isEmpty()) {
		error(STACK_IS_EMPTY);
	}
	return stack[top--];
}
int Stack::size() {
	return top+1;
}
void Stack::show() {
	if (isEmpty()) {
		cout << STACK_IS_EMPTY << endl;
		return;
	}
	cout << " ┌━━━┓" << endl;
	for (int i = top; i >=0; i--) {
		cout << " │ " << stack[i] << " │" << endl;
	}
	cout << " ┗━━━┘ " << endl;
}
