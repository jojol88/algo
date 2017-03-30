#ifndef TEST_SEARCH_CPP
#define TEST_SEARCH_CPP

#include "mySearch.cpp"
#include "testHelper.cpp"


void test_search_1() {

   typedef vector<int> Array;

   auto search = search_2;

   auto key = 8;
   // key not exists in array
   test(-1, search, Array(), key); // degerate
   test(-1, search, Array({ key - 1 }), key); // trivial
   test(-1, search, Array({ key - 1, key + 1 }), key); // trivial2
   test(-1, search, Array({ 1,2,3,4,5,7 }), key); // general
   test(-1, search, Array({ 9,10,11,12 }), key); // general
   test(-1, search, Array({ 4,1,2,7,10 }), key); // general
                                                 // key exists in array
                                                 // non appliable // degerate
   test(0, search, Array({ key }), key); // trivial
   test(0, search, Array({ key, key + 1 }), key); // trivial2
   test(1, search, Array({ key - 1, key }), key); // trivial2
   test(8, search, Array({ 0,1,2,3,4,5,6,7,key }), key); // general
   test(0, search, Array({ key, 9,10,11,12 }), key); // general
   test(2, search, Array({ 4,1,key,7,10 }), key); // general                

   test(0, search, Array({ key,1,key,7,10 }), key); // general                
   test(2, search, Array({ 2,1,key,7,key }), key); // general                
}


void test_search_2() {

   typedef vector<int> Array;

   auto search = [](const vector<int>& v, int key) {
      auto r = my_binary_search(v.begin(), v.end(), key);
      return r != v.end() ? r - v.begin() : -1;
   };

   auto key = 8;
   // key not exists in array
   test(-1, search, Array(), key); // degerate
   test(-1, search, Array({ key - 1 }), key);          // trivial
   test(-1, search, Array({ key + 1 }), key);          // trivial
   test(-1, search, Array({ key - 2, key - 1 }), key);   // trivial2
   test(-1, search, Array({ key + 1, key + 2 }), key);   // trivial2
   test(-1, search, Array({ key - 1, key + 1 }), key);   // trivial2
   test(-1, search, Array({ 1,2,3,4,5,7 }), key);    // general
   test(-1, search, Array({ 9,10,11,12 }), key);     // general
   test(-1, search, Array({ 1,2,4,7,10 }), key);     // general

                                                     // key exists in array
                                                     // non appliable // degerate
   test(0, search, Array({ key }), key);                     // trivial
   test(0, search, Array({ key, key + 1 }), key);              // trivial2
   test(1, search, Array({ key - 1, key }), key);              // trivial2
   test(8, search, Array({ 0,1,2,3,4,5,6,7,key }), key);     // general
   test(0, search, Array({ key, 9,10,11,12 }), key);         // general
   test(2, search, Array({ 1,4,key,9,10 }), key);            // general                

   test(0, search, Array({ key, key, key + 1, key + 2 }), key);  // general                
   test(2, search, Array({ key - 2, key - 1, key, key }), key);  // general                
   test(2, search, Array({ 1, 7, key, key }), key);          // general
}

#endif // TEST_SEARCH