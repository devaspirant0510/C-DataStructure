#pragma once
#include <iostream>

#define MAX_QUEUE_SIZE 10000

using namespace std;

template<typename T>
class Queue
{
	private:
		int maxSize;
		char QUEUE_IS_EMPTY[20] = "Queue is empty";
		char QUEUE_IS_FULL[20] = "Queue is full";

	public:
		int front=0;
		int rear=0;
		int tail_val;
		T *queue;
		Queue();
		Queue(int max_size);
		void sendErrorMsg(char* msg);
		bool isEmpty();
		bool isFull();
		int getSize();
		void enqueue(T element);
		T dequeue();
		T* head();
		T* tail();
		void printQueue();
};

template <typename T>
Queue<typename T>::Queue() {
	this->queue = new T[MAX_QUEUE_SIZE];
	this->maxSize = MAX_QUEUE_SIZE;
	front = rear = 0;
}

template <typename T>
Queue<typename T>::Queue(int max_size) {
	this->queue = new  T[max_size];
	this->maxSize = max_size;
	front = rear = 0;
}

template<typename T>
void Queue<typename T>::sendErrorMsg(char* msg) {
	std::cout << msg << std::endl;
}

template<typename T>
bool Queue<typename T>::isEmpty() {
	if (front == rear) {
		return true;
	}
	return false;
}

template<typename T>
bool Queue<typename T>::isFull() {
	if ((rear+1)%this->maxSize==front) {
		return true;
	}
	return false;


}

template<typename T>
int Queue<typename T>::getSize() {
	if (front < rear) {
		return rear - front;
	}
	else {
		return rear + maxSize - front;
	}
}

template<typename T>
void Queue<typename T>::enqueue(T element) {
	if (isFull()) {
		sendErrorMsg(QUEUE_IS_FULL);
		return;
	}
	queue[rear] = element;
	tail_val = rear;
	rear = (rear + 1) % maxSize;
}
template<typename T>
T Queue<typename T>::dequeue() {
	if (isEmpty()) {
		sendErrorMsg(QUEUE_IS_EMPTY);
		return NULL;
	}
	int deqPos = front;
	front = (front + 1) % maxSize;
	
	return queue[deqPos];
}

//template<typename T>
//T Queue<typename T>::front() {
//	if (isEmpty()) {
//		sendErrorMsg("stack is empty");
//		return;
//	}
//	return queue[front];
//}
template<typename T>
T* Queue<typename T>::head() {
	if (isEmpty()) {
		sendErrorMsg(QUEUE_IS_EMPTY);
		return NULL;
	}
	return &queue[front]; 
}

template<typename T>
T* Queue<typename T>::tail() {
	if (isEmpty()) {
		sendErrorMsg(QUEUE_IS_EMPTY);
		return NULL;
	}
	return &queue[tail_val]; 
}

template<typename T>
void Queue<typename T>::printQueue() {
	for (int i = front; i < front + this->getSize(); i++) {
		cout << queue[i % maxSize] << " , ";
	}
	cout << endl;
}
