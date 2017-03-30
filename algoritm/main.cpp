#include "algoritm/TestSearch.cpp"
#include "algoritm/TestSort.cpp"


int main(int argc, char const *argv[])
{
   typedef vector<int>::iterator Iter;

   test_sorting(my_naive_sort<Iter>);
   test_sorting(my_selection_sort<Iter>);
   test_sorting(my_bubble_sort<Iter>);
   
   test_search_1();
   test_search_2();

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