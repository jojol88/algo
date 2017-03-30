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

#endif // MY_SORT