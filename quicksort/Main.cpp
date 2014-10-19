
#include <iostream>
#include <cstdlib>
#include <vector>

#include "QuickSort.h"

using namespace std;

int main(int argc, char* argv[])
{
	// Initialize the vec with 10 random numbers
	vector<int> vec;
	int n=5;
	vec.reserve(n);

 	srand(34);
	for(int i=0; i<n; i++)
		vec.push_back(rand()%50);

	cout << "Unsorted vector: ";
	for(vector<int>::iterator it=vec.begin(); it != vec.end(); ++it)
		cout << *it << " ";
	cout << endl;

	int arr[n];
	std::copy(vec.begin(), vec.end(), arr);
	QuickSort::sort(arr, n);

	for(int i=0; i<n; i++)
		vec[i] = arr[i];

	cout << "Sorted vector: ";
	for(vector<int>::iterator it=vec.begin(); it != vec.end(); ++it)
		cout << *it << " ";
	cout << endl;
	return 0;
}

