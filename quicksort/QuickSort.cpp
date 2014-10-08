
#include "QuickSort.h"

using namespace std;

//static
void QuickSort.sort(int* array, int len)
{
	if ( !array ) return;
	QuickSort::sort(array, 0, len-1);
}

// static
void QuickSort:sort(int* array, int start, int end)
{
	// zero or one item in the list
	if ( start <= end ) return;

	// Exact 2 items in the list, swap if not sorted )
	if ( end-start==1 ) {
		if ( array[start] > array[end] ) {
			std::swap(array[start],array[end]);
		}
	}

	// Now the general case where we need to chose a pivot
	int pindex = (end+start)/2;
	int pivot = array[pindex];
	
	while(start<end) {
		// Find first item in the array bigger than pivot
		while( start<end && array[start]<=pivot )
			start++;

		// Find last item in the array small er than the pivot
		while(end>start && array[end]>pivot )
			end--;

		// Swap the two items if index valid
		//
	}
}
