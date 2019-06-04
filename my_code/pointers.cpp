#include "../../../class_04_DUI/src/my_code/pointers.h"

#include <iostream>

using namespace std;

void inc_by_value(int n) {
	++n;
}


void inc_with_pointer(int* iptr) {
	++(*iptr);
}


void inc_with_reference(int& n) {
	++n;
}


Thing** create_array_of_things(int n) {
	Thing** things_array = new Thing*[n];
	for(int i = 0; i <= n; i++){
		things_array[i] = new Thing(i);
	}

    return things_array;
}

void print_all_things(Thing** things, int n) {
	for(int i = 0; i <= n; i++){
		cout << things[i] -> val;
	}
	cout << endl;
}

void double_all_things(Thing** things, int n) {
	for(int i = 0; i <= n; i++){
		things[i] -> val *= 2;
	}
}

void delete_all_things(Thing** things, int n) {
	for(int i = 0; i <= n; i++){
		delete things[i];
	}
	delete [] things;
}


void assignTA(Student& s, Student& ta) {
}

void printTAs(vector<Student> students) {
}


