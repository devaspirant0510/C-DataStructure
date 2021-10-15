#pragma once
#pragma once
#include <iostream>

using namespace std;

typedef struct Student {
	int id;
	char name[20];
	char dept[20];
} student;

student createStudent(int id, char name[], char dept[]) {
	student st;
	st.id = id;
	strcpy_s(st.name, name);
	strcpy_s(st.dept,dept);
	return st;
}
void showStudent(student* st) {
	cout << "    studnet info    " << endl;
	cout << "id --> " << st->id << endl;
	cout << "name --> " << st->name << endl;
	cout << "dept --> " << st->dept << endl;
}


