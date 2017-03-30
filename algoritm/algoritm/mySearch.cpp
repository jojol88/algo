#ifndef MY_SEARCH_CPP
#define MY_SEARCH_CPP

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cassert>

using namespace std;


int search_0(int v[], size_t size, int key) {
   for (int i = 0; i < size; ++i) {
      if (v[i] == key) {
         return i;
      }
   }

   return -1;
}


int search_1(int v[], size_t size, int key) {
   v[size] = key;

   int i = 0;
   while (v[i] != key) { ++i; }

   if (i != size) {
      return i;
   }

   return -1;
}


int search_2(const vector<int>& v, int key) {
   for (int i = 0; i < v.size(); ++i) {
      if (v[i] == key)
         return i;
   }

   return -1;
}


int search_3(vector<int>& v, int key) {
   v.push_back(key);
   int i = 0;
   while (v[i] != key)
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


int search_4(int arr[], const size_t size, const int& key) {
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


int binary_search_helper(const vector<int>& v, size_t begin,
   size_t end, int key, size_t depth = 0)
{
   assert(depth < 1000);
   assert(is_sorted(v.begin(), v.end()));

   if (begin < end) {
      // [b, e) = [b, m) U [m] U [m+1, e)
      size_t m = (begin + end) / 2;
      assert((m - begin) + (end - m) == (end - begin));

      if (key < v[m]) {
         return binary_search_helper(v, begin, m, depth + 1);
      }
      else if (v[m] < key) {
         return binary_search_helper(v, m + 1, key, depth + 1);
      }
      else {
         return m;
      }
   }

   return -1;
}


int binary_search(const vector<int>& v, int key) {
   assert(is_sorted(v.begin(), v.end()));

   size_t b = 0;
   size_t e = v.size();
   while (b < e)
   {
      // [b, e) = [b, m) U [m] U [m+1, e)
      size_t m = b + ((v.end() - v.begin()) / 2); // >> 1
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

/////////////////////////////////////////////////////////////////

template<class TIter, class T>
TIter my_lower_bound(TIter begin, TIter end, const T& key)
{
   assert(is_sorted(begin, end));

   while (begin < end)
   {
      TIter m = begin + (end - begin) / 2;
      if (key > *m) {
         begin = m + 1; // [m+1, e)
      }
      else {
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
         begin = m + 1;
      }
   }

   return begin;
}


template<class TIter, class T>
TIter my_binary_search(TIter begin, TIter end, const T& key)
{
   TIter el = lower_bound(begin, end, key);
   return el != end && !(key < *el) ? el : end;
}

#endif // MY_SEARCH