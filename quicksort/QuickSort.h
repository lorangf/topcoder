
#ifndef _QUICKSORT_H_ 
#define _QUICKSORT_H_ 

class QuickSort
{
public:
	static void sort(int* array, int len);

private:
	static void sort(int* array, int start, int len);
};

#endif

