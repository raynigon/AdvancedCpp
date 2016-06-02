#include <iterator>
#include <algorithm>
#include <vector>
#include <iostream>
#include <set>

#include "Concepts.h"

template<typename Iterator>
void mySortImpl(Iterator begin, Iterator end, std::random_access_iterator_tag)
{
	std::sort(begin, end);
}

/*template<typename Iterator>
void mySort(Iterator begin, Iterator end)
{
	mySortImpl(begin, end, std::iterator_traits<Iterator>::iterator_category());
}*/


void mySort(RandomAccessIterator begin, RandomAccessIterator end)
{
	std::sort(begin, end);
}

int main()
{
	std::vector<int> container = {9, 2, 4, 8, 5, 1, 6, 7, 3};
	//std::set<int> container = { 9, 2, 4, 8, 5, 1, 6, 7, 3 };
	//mySort(container.begin(), container.end());

	mySort(container.begin(), container.end());

	std::for_each(container.begin(), container.end(), [](int a){
		std::cout << a << std::endl; 
	});
}

