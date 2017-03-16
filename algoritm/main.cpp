#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cassert>

using namespace std;


ostream& operator<<(ostream& o, const vector<T>& v) {
	o << "[";
	for (auto& x : v)
	{
		o << x << ", ";
	}

	return o << "]";
}


template<class TFunc, class TResult, class TParam1>
void test(TResult expect, TFunc f, TParam1 p1) {
	auto got = f(p1);
	if (got != expect) {
		cerr << "failed: " << expect << " != " << got << endl;
	}
}


template<class TFunc, class TResult, class TParam1, class TParam2>
void test(TResult expect, TFunc f, TParam1 p1, TParam2 p2) {
	auto got = f(p1, p2);
	if (got != expect) {
		cerr << "failed: f(" << p1 << ", " << p2 << ") = " << got << " != " << expect << endl;
	}
}


void test_search()
{
	typedef vector<int> Array;

	auto search = search_2;
	
	// key not exists in array
		// deregate
		test(-1, search, Array(), key);
		// trivial
		test(-1, search, Array({ key - 1 }), key);
		// trivial-2
		test(-1, search, Array({ key - 1, key + 1 }), key);
		// general
		test(-1, search, Array({1,2,3,4,5,6,7}), key);

	// key exists in array
		// deregate not appliable
		// trivial
		test(-1, search, Array({ key }), key);
		// trivial-2
		test(-1, search, Array({ key, key + 1 }), key);
		// general
		test(-1, search, Array({ 1,2,3,4,5,7 }), key);
}


int search_0(const vector<int>& v, const int& key) {
	for (int i = 0; i < v.size; ++i) {
		if (v[i] == key)
			return i;
	}

	return -1;
}


int search_1(int arr[], const size_t size, const int& key) {
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


int binary_search_helper(
	const vector<int>& v, 
	size_t begin,
	size_t end,
	int key)
{
	assert(is_sorted(v.begin(), v.end()));

	if (begin == end )
	{
		return -1;
	}
	if (end-begin == 1)
	{
		if (v[begin] == key)
		{
			return begin;
		}
		else
		{
			return -1;
		}
	}

	size_t m = (begin + end) / 2;
	// [0, s) = [0, m) U [m, s)

	if (key < v[m])
	{
		return binary_search_helper(v, begin, m, key);
	}
	else if (v[m] < key)
	{
		return binary_search_helper(v, m, end, key);
	}
	else
	{
		return m;
	}
}


int main() 
{
	test_search();

	system("pause");
	return 0;
}