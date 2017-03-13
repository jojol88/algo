#include <iostream>
#include <vector>

using namespace std;


int search_0(const vector<int>& v, const int& key) {
	for (int i = 0; i < v.size; ++i) {
		if (v[i] == key)
			return i;
	}

	return -1;
}


int search_1(int arr[], const int& size, const int& key) {
	arr[size] = key;

	int i = 0;
	while (arr[i] != key) {
		++i;
	}

	if (i != size) {
		return i;
	}
	

	return -1;
}


int search_2(vector<int>& v, const int& key) {
	v.push_back(key);

	int i = 0;
	while (v[i] != key )
	{
		++i;
	}

	v.pop_back();

	if (i != v.size())
	{
		return i;
	}

	return -1;
}

ostream& operator<<(ostream& o, const vector<T>& v)
{
	o << 
}

template<class TFunc, class TResult, class TParam1>
void test(TResult expect, TFunc f, TParam1 param) {
	auto got = f(param);
	if (got != expect) {
		cerr << "failed: " << expect << " != " << got << endl;
	}
}

template<class TFunc, class TResult, class TParam1, class TParam2>
void test(TResult expect, TFunc f, TParam1 p1, TParam2 p2) {
	auto got = f(p1, p2);
	if (got != expect) {
		cerr << "failed: " << expect << " != " << got << endl;
	}
}


void test_search()
{
	typedef vector<int> Array;

	test(8, search_2, Array({0,1,2,3,4,5,6,7}))
}

int main() {
	vector<int> v;
	int key = 10;

	for (int i = 0; i < v.size; ++i) {
		v[i] = i;
	}

	cout << "array element = " << search(arr, size, key) << endl;


	system("pause");
	return 0;
}