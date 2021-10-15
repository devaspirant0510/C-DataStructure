#include <iostream>


using namespace std;

int MAX_STACK_SIZE = 1000;

char STACK_IS_FULL[] = "error ! stack is full";
char STACK_IS_EMPTY[] = "error ! stack is empty";

template <typename T>
class Stack {
private:
	int maxSize;
	int top = -1;

public:
	T* stack;
	Stack(int maxSize);
	void error(char* err);
	bool isEmpty();
	bool isFull();
	void push(T t);
	int size();
	T pop();
	void show();
	T getTop();
	T* getStack();
};

template <typename T>
Stack<typename T>::Stack(int maxSize) {
	this->maxSize = maxSize;
	this->stack = new T[maxSize];
}
template <typename T>
void Stack<typename T>::error(char* err) {
	cout << err << endl;
	exit(1);
}
template <typename T>
bool Stack<typename T>::isEmpty() {
	return top == -1;
}
template <typename T>
bool Stack<typename T>::isFull() {
	return top+1 == maxSize;

}
template<typename T>
T Stack<typename T>::getTop() {
	return stack[top];
}

template <typename T>
void Stack<typename T>::push(T t) {
	// stack 이 꽉차있을시 에러
	if (isFull()) {
		error(STACK_IS_FULL);
	}
	else {
		stack[++top] = t;
	}
}
template <typename T>
T Stack<typename T>::pop() {
	// stack이 비어있을시 에러
	if (isEmpty()) {
		error(STACK_IS_EMPTY);
	}
	return stack[top--];
}
//template <typename T>
//T Stack<typename T>::top() {
//	return 1;
//}
template <typename T>
int Stack<typename T>::size() {
	return top+1;
}
template <typename T>
void Stack<typename T>::show() {
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

template <typename T>
T* Stack<typename T>::getStack() {
	return stack;
}
