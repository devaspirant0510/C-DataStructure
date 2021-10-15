#include <iostream>
#include "myStack.hpp"
#include "Student.hpp"


using namespace std;


int main() {
	Stack<Student> stack(10);
	char name1[] = "seungho";
	char dept1[] = "sw";
	Student st1 = createStudent(20, name1, dept1);
	char name2[] = "droid";
	char dept2[] = "cs";
	Student st2 = createStudent(29, name2, dept2);
	stack.push(st1);
	stack.push(st2);
	Student* tops = stack.getStack();
	for (int i = 1; i >=0; i--) {
		showStudent(tops + i);
	}
	Student popV = stack.pop();
	cout << endl << "현재 pop 한 값" << endl;
	showStudent(&popV);
	cout << endl << "현재 스택에 있는 값 " << endl;
	Student gett = stack.getTop();
	showStudent(&gett);





	
	return 0;
}