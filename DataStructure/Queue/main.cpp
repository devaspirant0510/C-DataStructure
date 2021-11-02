#include <iostream>
#include "myQueue.hpp"

using namespace std;
typedef struct {
	char name[20];
	int age;
} Person;
Person createPerson(char* name, int age);
int main() {
	Queue<int> q = Queue<int>(9);
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.printQueue();
	cout << "dequeue : " <<q.dequeue() << endl;
	cout << "dequeue : " <<q.dequeue() << endl;
	q.printQueue();
	cout << "queue head : " << *(q.head()) << " queue tail : " << *(q.tail()) << endl;
	Queue<Person> structQ = Queue<Person>(20);
	char name1[20] = "seungho";
	structQ.enqueue(createPerson(name1, 20));
	cout << structQ.head()->age<< endl;
	cout << structQ.head()->name << endl;

	return 0;
}
Person createPerson(char* name, int age) {
	Person person;
	strcpy_s(person.name, 20,name);
	person.age = age;
	return person;
}