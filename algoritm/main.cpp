#include <iostream>

using namespace std;


int search(int arr[], const int& size, const int& key) {
	for (int i = 0; i < size; ++i) {
		if (arr[i] == key)
			return i;
	}

	return -1;
}


bool test(int arr[], const int& size) {
	for (int i = 0; i < size; ++i) {
		if (search(arr, size, i) != i) {
			return false;
		}
	}
	
	return true;
}


int main() {
	const int size = 50;
	int arr[size];
	int key = 10;

	for (int i = 0; i < size; ++i) {
		arr[i] = i;
	}

	cout << "array element = " << search(arr, size, key) << endl;

	if (test(arr, size)) {
		cout << "SUCCESS" << endl;
	}
	else {
		cout << "ERROR" << endl;
	}

	system("pause");
	return 0;
}