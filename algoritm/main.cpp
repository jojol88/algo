#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cassert>

using namespace std;

template <class T>
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
	} else {
		cout << "cool" << endl;
	}
}


template<class TFunc, class TResult, class TParam1, class TParam2>
void test(TResult expect, TFunc f, TParam1 p1, TParam2 p2) {
	auto got = f(p1, p2);
	if (got != expect) {
		cerr << "failed: f(" << p1 << ", " << p2 << ") = " << got << " != " << expect << endl;
	} else {
		cout << "cool" << endl;
	}
}


int search_0(const vector<int>& v, const int& key) {
	for (auto i = 0; i < v.size(); ++i) {
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


int search_3(const std::vector<int>& v, int key) {
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] == key) {
			return i;
		}
	}

	return -1;
}


int binary_search_helper( const vector<int>& v, size_t begin, 
                           size_t end,	int key,	size_t depth=0)
{
	assert(depth < 1000);
	assert(is_sorted(v.begin(), v.end()));

	if (begin < end) {
      // [b, e) = [b, m) U [m] U [m+1, e)
		size_t m = (begin + end) / 2;
		assert((m - begin) + (end - m) == (end - begin));

		if (key < v[m]) {
			return binary_search_helper(v, begin, m, depth+1);
		}
		else if (v[m] < key) {
			return binary_search_helper(v, m+1, key, depth+1);
		}
		else {
			return m;
		}
	}
	
	return -1;
}


int binary_search0(const vector<int>& v, int key) {
	assert(is_sorted(v.begin(), v.end()));

	size_t b = 0;
	size_t e = v.size();
	while (b < e)
	{
		// [b, e) = [b, m) U [m] U [m+1, e)
		size_t m = b + ((v.end() -v.begin()) /2); // >> 1
		if (key < v[m]) {
			e = m;
		}
		else if (v[m] < key) {
			b = m + 1;
		}
		else {
			return m;
		}
	}

	return -1;
}


template<class TIter, class T> 
TIter my_lower_bound(TIter begin, TIter end, const T& key)
{
	assert(is_sorted(begin, end));
	
	while (begin < end)
	{
		TIter m = begin + (end - begin) / 2;
		if (key > *m) {
			begin = m+1; // [m+1, e)
		} else {
			end = m; // [b, m)
		}
	}

	return begin;
}


template<class TIter, class T>
TIter my_upper_bound(TIter begin, TIter end, const T& key)
{
	assert(is_sorted(begin, end));

	while (begin < end)
	{
		TIter m = begin + (end - begin) / 2;
		if (key < *m) {
			end = m; 
		}
		else {
			begin = m+1;
		}
	}

	return begin;
}


template<class TIter, class T>
TIter binary_search1(TIter begin, TIter end, const T& key)
{
   TIter el = lower_bound(begin, end, key);
   return el != end && !(key < *el) ? el : end;
}


template<class TIter>
TIter my_min_element(TIter begin, TIter end)
{
   auto result = begin;
   auto iter = begin + 1;
   while (iter < end)
   {
	   // [) = [processed) [curent] [unprocessed)
      if (*iter < *result)
      {
         result = iter;
      }

      ++iter;
   }

   return result;
}


template<class TIter>
void naive_sort(TIter b, TIter e) {
	for (size_t i = b; i < e; i++)
	{
		assert(is_sorted(b, i));
		// [sorted) U [unsorted) = [b, i) U [i, e)
		for (size_t j = i++; j < e; j++)
		{
			// [unsorted) = [i] U [i+1, j) U [j, e)
			assert(min_element(i, j) == i);

			if (*j <*i) {
				swap(*i, *j);
			}

			assert(min_element(i, j) == i);
		}
		assert(is_sorted(b, i++));
	}
}


template<class TIter>
void my_selection_sort(TIter b, TIter e) {
	for (auto i = b; i < e; i++)
	{
		// [sorted) U [unsorted) = [b, i) U [i, e)
		assert(is_sorted(b, i));
		swap(*i, *my_min_element(i, e));
	}
}


template<class TIter>
void my_bubble_sort(TIter b, TIter e) {
	if (b == e)
	{
		return;
	}

	auto sorted_begin = e - 1;
	while(b < sorted_begin) {
		assert(sorted_begin < e);
		assert(is_sorted(sorted_begin, e));

		auto j = b;
		while(j < sorted_begin)
		{
			if (*j > *(j+1))
			{
				iter_swap(j+1, j);
			}
			++j;
		}
		--sorted_begin;
	}
}


void test_sort()
{
	typedef vector<int> Array;

	auto sort = [](const vector<int>& u)
	{
		auto v = u;
		my_bubble_sort(v.begin(), v.end());
		return v;
	};
	

	test(Array(), sort, Array()); // degerate
	test(Array({ 1 }), sort, Array({1})); // trivial
	test(Array({ 1, 2 }), sort, Array({ 1, 2 })); // trivial2
	test(Array({ 1, 2 }), sort, Array({ 2, 1 })); // trivial2
	test(Array({ 1 }), sort, Array({ 1 })); // trivial2
	test(Array({ 1, 1 }), sort, Array({ 1, 1 })); // trivial2
												 
	test(Array({ 1, 1, 1 }), sort, Array({ 1, 1, 1 }));
	test(Array({ 1, 2, 3 }), sort, Array({ 1, 2, 3 })); 
	test(Array({ 1, 2, 3 }), sort, Array({ 3, 2, 1 })); 
	test(Array({ 1, 2, 3 }), sort, Array({ 2, 3, 1 }));

	test(Array({ 0,1,5,5,6,7,8 }), sort, Array({ 8,5,1,7,6,0,5 })); 
}


//void test_search()
//{
//	typedef vector<int> Array;
//
//	auto search = [](const vector<int>& v, int key)
//	{
//		auto r = lower_bound(v.begin(), v.end(), key);
//		return r != v.end() ? r-v.begin() : -1;
//	};
//
//	auto key = 8;
//	// key not exists in array
//	test(-1, search, Array(), key); // degerate
//	test(-1, search, Array({ key - 1 }), key); // trivial
//	test(-1, search, Array({ key - 1, key + 1 }), key); // trivial2
//	test(-1, search, Array({ 1,2,3,4,5,7 }), key); // general
//	test(-1, search, Array({ 9,10,11,12 }), key); // general
//	test(-1, search, Array({ 4,1,2,7,10 }), key); // general
//												  // key exists in array
//												  // non appliable // degerate
//	test(0, search, Array({ key }), key); // trivial
//	test(0, search, Array({ key, key + 1 }), key); // trivial2
//	test(1, search, Array({ key - 1, key }), key); // trivial2
//	test(8, search, Array({ 0,1,2,3,4,5,6,7,key }), key); // general
//	test(0, search, Array({ key, 9,10,11,12 }), key); // general
//	test(2, search, Array({ 4,1,key,7,10 }), key); // general                
//
//	test(0, search, Array({ key,1,key,7,10 }), key); // general                
//	test(2, search, Array({ 2,1,key,7,key }), key); // general   
//}


int main() 
{
	test_sort();

	system("pause");
	return 0;
}

/*	
	a half-opened interval [*b,*e)
	b - first element
	empty if b = e
	size = e - b
	invariant = never changing
*/

/*
	upper bound - lower bound = кол. заданных элементов

	0(c) = 0(1)
	0(c + f(n)) = 0(f(n))
	0(c*f(n)) = 0(f(n))
	if f(n) = 0(g(n)) then 0(f(n) + g(n)) = 0(g(n))

	a<b && b<c => assert(a < c)

	summ 1 ... n = (n+1)n /2
*/