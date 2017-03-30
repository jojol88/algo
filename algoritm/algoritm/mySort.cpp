#ifndef MY_SORT_CPP
#define MY_SORT_CPP

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <cassert>

using namespace std;


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


template <class TIter>
TIter min_element2(TIter b, TIter e) {
   auto result = b;
   while (b < e) {
      // [ )  = [processed) [curent] [unprocessed)
      // assert(tmp is min from [processed))
      if (*b < *result) {
         result = b;
      }
      ++b;
      // assert(tmp is min from [processed))
   }
   return result;
}


template<class TIter>
void my_naive_sort(TIter b, TIter e) {
   for (auto i = b; i < e; i++) {
      assert(is_sorted(b, i));
      // [sorted) U [unsorted) = [b, i) U [i, e)
      for (auto j = i+1; j < e; j++)
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
   while (b < sorted_begin) {
      // [unsorted) U [sorted) = [b, sb) U [sb e)
      assert(sorted_begin < e);
      assert(is_sorted(sorted_begin, e));

      auto j = b;
      while (j < sorted_begin) {
         if (*j > *(j + 1))
         {
            iter_swap(j + 1, j);
         }
         ++j;
      }

      --sorted_begin;
      assert(is_sorted(sorted_begin, e));
   }
}


template<class TIter>
void my_insertion_sort(TIter b, TIter e) {
	if (b == e)
		return;

	size_t counter = 0;
	for (TIter i = b+1; i < e; ++i) {
		for (TIter j = i; j>b && *(j-1)>*j; --j)
		{
			++counter;
			iter_swap(j-1, j);
		}
		assert(is_sorted(b, i));
	}

	auto pivot = b+1;
	while (pivot < e)
	{
		// [b, pivot)[pivot)[pivot+1, e)
		assert(is_sorted(b, pivot));
		auto i = pivot;
		while (b<i && *i < *(i-1))
		{
			assert(is_sorted(b, i) && is_sorted(i, pivot));
			iter_swap(i - 1, i);
		}
		++pivot;
		assert(is_sorted(b, pivot));
	}

	cout << "count = " << counter << endl;
}


template<class TIter>
void my_merge(TIter b, TIter m, TIter e, TIter buff) {
	const auto size = e - b;
	const auto old = buff;
	const auto e1 = m;

	while (b < e1 && m < e) {
		*buff++ = *b < *m ? *b++ : *m++;
	}

	buff = copy(b, e1, buff);
	buff = copy(m, e, buff);

	assert(buff - old == size);
}


template<class TIter>
void merge_sort(TIter b, TIter e, TIter buff) {
	auto size = e - b;
	if (size > 1)
	{
		auto m = b + size/ 2;
		merge_sort(b, m, buff);
		merge_sort(m, e, buff+size/2);
		copy(buff, buff + size, b);
		my_merge(b, m, e, buff);
	}
	else
	{
		copy(b, e, buff);
	}
}


template<class TIter>
void my_merge_sort(TIter b, TIter e) {
	vector<int> buff(e - b);
	merge_sort(b, e, buff.begin());
	copy(buff.begin(), buff.end(), b);
}

#endif // MY_SORT