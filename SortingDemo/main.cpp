/** Name: main
	Author: Andrey
	Timestamp: 9/30/2013 12:22:41 AM
	Description: MIPT Programming Assignment #1: Sorting Demo */


#define FILE_IO

#include <cassert>
#include <vector>
#include <algorithm>
#include <iterator>
#include <deque>

#ifdef FILE_IO
#include <fstream>
std::ofstream debug("output.txt");
#else
#include <iostream>
#define debug cout
#endif


template<typename Iterator>
void selectionSort(Iterator first, Iterator last) {
	assert(last - first >= 0);

	for (Iterator sorted = first; sorted < last; sorted++) {
		Iterator currentMinimaIndex = sorted;
		for (Iterator i = sorted + 1; i < last; i++)
			if ((*i) < (*currentMinimaIndex))
				currentMinimaIndex = i;
		std::swap(*currentMinimaIndex, *sorted);
	}
}

template<typename Iterator>
void insertionSort(Iterator first, Iterator last) {
	assert(last - first >= 0);

	for (Iterator sorted = first + 1 ; sorted < last; sorted++) {
		std::iterator_traits<Iterator>::value_type key = *sorted;
		Iterator position = first;
		while (*(position) <= *sorted && position < sorted)
			position++;
		std::copy(position, sorted, position + 1);
		*position = key;
	}
}


int main() {
	std::vector<int> v;
	for (int i = 0; i < 1000; i++)
		v.push_back(rand());
	std::vector<int> sorted(v);
	std::vector<int> v1(v), v2(v);
	
	std::sort(sorted.begin(), sorted.end());
	insertionSort(v2.begin(), v2.end());
	selectionSort(v1.begin(), v1.end());

	bool b1 = sorted == v1;
	bool b2 = sorted == v2;

	for (int i = 0; i < v.size(); i++)
		debug << v[i] << std::endl;

}