//Ryan Peterson
//CSC 161
//11-30-2018

// CSC-161 Homework Twelve
// FILE: quick.cpp
// Original by Michael Main, modified by Steve Kaminski
// An interactive test program for the quicksort function
// This file is to be completed by the student

#include <algorithm>  // Provides swap
#include <cstdlib>    // Provides EXIT_SUCCESS, size_t
#include <iostream>   // Provides cout and cin
using namespace std;

// PROTOTYPES of the functions used in this test program:
void quicksort(int data[ ], size_t n);
// Precondition: data is an array with at least n components.
// Postcondition: The elements of data have been rearranged so
// that data[0] <= data[1] <= ... <= data[n-1].

void partition(int data[ ], size_t n, size_t& pivot_index);
// Precondition: n > 1, and data is an array (or subarray)
// with at least n elements.
// Postcondition: The function has selected some "pivot value"
// that occurs in data[0]..data[n-1]. The elements of data
// have then been rearranged, and the pivot index set so that:
//   -- data[pivot_index] is equal to the pivot;
//   -- Each item before data[pivot_index] is <= the pivot;
//   -- Each item after data[pivot_index] is > the pivot.

void setPivot(int data[ ], size_t n);
// Precondition: n > 1 and data is an array or subarray
// Postcondition: data[0] holds the selected pivot value
//  The original value of data[0] has been swapped with the selected pivot value

int main( )
{
    // Announce the program
    cout << "\nCSC-161 Homework Twelve: Implementing the QuickSort Algorithm\n";
    // Declare useful values
    const char BLANK = ' ';
    size_t i = 0;
    // Initialize our test data arrays
    const size_t SIZE1 = 10;
    int data1[]= {34, 33, 9, 45, 1, -1, 9, -18, 75, 100 };
    const size_t SIZE2 = 15;  // Number of elements in the array to be sorted
    int data2[]= {100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86 };
    const size_t SIZE3 = 1000;
    int data3[SIZE3];
    // Initialize the third array to random int values
    for (i = 0; i < SIZE3; i++)
        data3[i] = rand();
    // Beginning of quick sort tests
    // Sort the arrays and print the result with two blanks after each number
    quicksort(data1, SIZE1);
    cout << "\nSorted First Array: " << endl;
    for (i = 0; i < SIZE1; i++)
        cout << data1[i] << BLANK << BLANK;
    cout << endl;
    quicksort(data2, SIZE2);
    cout << "\nSorted Second Array: " << endl;
    for (i = 0; i < SIZE2; i++)
        cout << data2[i] << BLANK << BLANK;
    cout << endl;
    // On the large third array, just print the first ten and last ten values
    quicksort(data3, SIZE3);
    cout << "\nSorted Third Array (first ten): " << endl;
    for (i = 0; i < 10; i++)
        cout << data3[i] << BLANK << BLANK;
    cout << endl;
    cout << "Sorted Third Array (last ten): " << endl;
    for (i = SIZE3 - 10; i < SIZE3; i++)
        cout << data3[i] << BLANK << BLANK;
    cout << endl << endl;
    system("Pause");
    return EXIT_SUCCESS;
}

void quicksort(int data[ ], size_t n)
// Library facilities used: cstdlib
{
    size_t pivot_index; // Array index for the pivot element
    size_t n1;          // Number of elements before the pivot element
    size_t n2;          // Number of elements after the pivot element

    if (n > 1)
    {
        // Partition the array, and set the pivot index.
        partition(data, n, pivot_index);

        // Compute the sizes of the subarrays.
        n1 = pivot_index;
        n2 = n - n1 - 1;
        
        // Recursive calls will now sort the subarrays.
        quicksort(data, n1);
        quicksort((data + pivot_index + 1), n2);
    }
}

void partition(int data[ ], size_t n, size_t& pivot_index)
// Library facilities used: algorithm, cstdlib
{

	setPivot(data, n); //get pivot value set into data[0]
	int pivot = data[0]; //set pivot to value in data[0]
	size_t too_small_index = n - 1;
	size_t too_big_index = 1;

	while (too_big_index <= too_small_index) //loop to check through array
	{
		while (data[too_big_index] < n || data[too_big_index] <= pivot)
		{
			++too_big_index;
		}

		while (data[too_small_index] > pivot)
		{
			--too_small_index;
		}

		if (too_big_index < too_small_index)
		{
			swap(data[too_big_index], data[too_small_index]);
		}
	}

	pivot_index = too_small_index; //set pivot index
	data[0] = data[pivot_index]; //swap 
	data[pivot_index] = pivot;
	
}

void setPivot(int data[ ], size_t n)
// Library facilties used: algorithm, cstdlib
// This function chooses a pivot value as the median of three
// randomly selected values.  The selected pivot is swapped with
// data[0] so that the pivot value is in the first position of the array
{
	int a, b, c; //variables for randomization
	int i, j, largest, index_large; //variables to sort the median array
	int median_index = 0;
	a = rand() % n-1; //randomly selected index value
	b = rand() % n-1;
	c = rand() % n-1;

	int median[3] = { data[a], data[b], data[c] }; //set random values into median array

	for (i = 2; i > 0; --i) //sort median array with basic selection sort
	{
		largest = median[0];
		index_large = 0;
		for (j = 1; j <= i; ++j)
		{
			if (median[j] > largest)
			{
				largest = median[j];
				index_large = j;
			}
		}
		swap(median[i], median[index_large]);
	}
	
	for (int k = 0; k < n; k++) //iterate through the main data to find the index of where the median value is
	{
		if (data[k] == median[1])
		{
			median_index = k;
			break;
		}
	}

	swap(data[0], data[median_index]); //swap zero index with median index
}


