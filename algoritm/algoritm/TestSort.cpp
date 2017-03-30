#ifndef MY_TEST_SORT_CPP
#define MY_TEST_SORT_CPP

#include "mySort.cpp"
#include "testHelper.cpp"


template <class TSorter>
void test_sorting(TSorter my_sort)
{
   typedef vector<int> Array;

   auto sort = [my_sort](vector<int> u)
   {
      my_sort(u.begin(), u.end());
      return u;
   };


   test(Array(), sort, Array());       // degerate
   test(Array({ 1 }), sort, Array({ 1 })); // trivial
   test(Array({ 1, 2 }), sort, Array({ 1, 2 })); // trivial 2nd
   test(Array({ 1, 2 }), sort, Array({ 2, 1 })); // trivial 2nd
   test(Array({ 1, 1 }), sort, Array({ 1, 1 })); // trivial 2nd

   test(Array({ 1, 1, 1 }), sort, Array({ 1, 1, 1 }));
   test(Array({ 1, 2, 3 }), sort, Array({ 1, 2, 3 }));
   test(Array({ 1, 2, 3 }), sort, Array({ 3, 2, 1 }));
   test(Array({ 1, 2, 3 }), sort, Array({ 2, 3, 1 }));

   test(Array({ 0, 1, 5, 5, 6, 7, 8 }),
      sort, Array({ 8, 5, 1, 7, 6, 0, 5 }));
}

#endif // TEST_SORT