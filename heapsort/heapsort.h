
#ifndef _HEAPSORT_H_
#define _HEAPSORT_H_

#include <vector>

class Heapsort
{
public:
	static void SortInPlace(std::vector<int>& vec);

private:
	static void Heapify(std::vector<int>& vec, int p, int n);
};

#endif

