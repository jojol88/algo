#ifndef MY_TEST_HELPER_CPP
#define MY_TEST_HELPER_CPP

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

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
   }
   else {
      cout << "cool" << endl;
   }
}


template<class TFunc, class TResult, class TParam1, class TParam2>
void test(TResult expect, TFunc f, TParam1 p1, TParam2 p2) {
   auto got = f(p1, p2);
   if (got != expect) {
      cerr << "failed: f(" << p1 << ", " << p2 << ") = " << got << " != " << expect << endl;
   }
   else {
      cout << "cool" << endl;
   }
}

#endif // MY_TEST_HELPER