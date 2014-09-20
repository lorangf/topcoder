
#include <algorithm>
#include <iostream>
#include <vector>

#include "heapsort.h"

// first child = 2x+1
// second child = 2x+2
// parent node = (c-1)/2 

using namespace std;

// static
void Heapsort::SortInPlace(vector<int>& vec)
{
	// Create binary heap
	for(int i=0; i<vec.size(); i++) {
		// Advancing the index add the number as a leaf.
		// Now we need to bubble up to the root to make sure
		// that the min Heap relationship is preserve.
		int j=i;
		while(j>0) {
			// Compare the node to its parent
			int p = (j-1)/2;
			
			// Comparing child to its parent
			if ( vec[j] > vec[p] )
				swap(vec[p], vec[j]);

			j=p;
		}
	}

	// The binary heap is now a max heap
	// Remove the max and swap it with last leaf in the tree
	// Bubble down the tree to make sure the max heap is valid
	// Repeat until there is only one element, which is the smallest
	int last=vec.size()-1;
	while(last>0) {
		// Swap the max with the last leaf in the tree, essentially
		// positioning the element at the right place in the vector
		swap(vec[0], vec[last]);

		// Decrement the number of nodes to parse for validating the max heap
		last--;

		// Validate the tree
		Heapify(vec, 0, last);
	}
}

void Heapsort::Heapify(vector<int>& vec, int p, int last)
{
	int left = 2*p+1;
	int right = 2*p+2;
	int largest = p;

	if ( left <= last && vec[left] > vec[largest] ) {
		largest = left;
	}
	if ( right <= last && vec[right] > vec[largest] ) {
		largest = right;
	}
	
	if ( largest != p ) {
		swap(vec[p],vec[largest]);
		Heapify(vec,largest,last);
	}

}

