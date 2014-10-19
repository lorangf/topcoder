
#include "QuickSort.h"

using namespace std;

//static
void QuickSort::sort(int* array, int len)
{
	if ( !array ) return;
	QuickSort::sort(array, 0, len-1);
}

// static
void QuickSort::sort(int* array, int left, int right)
{
	// Need to chose a pivot
	int pivot = array[(left+right)/2];
	int i = left;
	int j = right;

	while(i<=j) {
		// Find first item in the array bigger than pivot
		while( array[i]<pivot )
			i++;

		// Find last item in the array small er than the pivot
		while( array[j]>pivot )
			j--;

		// Swap the two items if index valid
		if ( i <= j ) {
			int tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;	
			i++;
			j--;
		}
	}

	if ( left < j )
		sort(array, left, j);
	if ( i < right )
		sort(array, i, right );
}
