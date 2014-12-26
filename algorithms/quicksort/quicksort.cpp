/*
 * Source: https://gsamaras.wordpress.com/code/quicksort-c/
 */

#include <iostream>
 
using namespace std;
 
/**
 * Swap the parameters.
 * @param a - The first parameter.
 * @param b - The second parameter.
*/
void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
 
/**
 * Swap the parameters without a temp variable.
 * Warning! Prone to overflow/underflow.
 * @param a - The first parameter.
 * @param b - The second parameter.
*/
void swapNoTemp(int& a, int& b)
{
    a -= b;
    b += a;// b gets the original value of a
    a = (b - a);// a gets the original value of b
}
 
/**
 * Find and return the index of pivot element.
 * @param a - The array.
 * @param first - The start of the sequence.
 * @param last - The end of the sequence.
 * @return - the pivot element
*/
int pivot(int a[], int first, int last) 
{
    int  p = first;
    int pivotElement = a[first];
 
    for(int i = first+1 ; i <= last ; i++)
    {
        /* If you want to sort the list in the other order, change "<=" to ">" */
        if(a[i] <= pivotElement)
        {
            p++;
            swap(a[i], a[p]);
        }
    }
 
    swap(a[p], a[first]);
 
    return p;
}

/**
 * Quicksort.
 * @param a - The array to be sorted.
 * @param first - The start of the sequence to be sorted.
 * @param last - The end of the sequence to be sorted.
*/
void quickSort( int a[], int first, int last ) 
{
    int pivotElement;
 
    if(first < last)
    {
        pivotElement = pivot(a, first, last);
        quickSort(a, first, pivotElement-1);
        quickSort(a, pivotElement+1, last);
    }
}

int main()
{
   int array[] = {25,-57,13,73,69,9,74,-86,-73,4,-18,-58,20,6,-25,-91,-61,90,-26,-89,60,-10,99,36,-42};
   int arraySize = sizeof(array)/sizeof(int);

	// Print input
	cout << endl << "Original array:" << endl;
	for(int i = 0 ; i < arraySize ; i++)
        cout << "array[" << i << "] = " << array[i] << endl;
 
   quickSort(array, 0, arraySize);
 
   // Print output
	cout << endl << "Sorted array:" << endl;
	for(int i = 0 ; i < arraySize ; i++)
        cout << "array[" << i << "] = " << array[i] << endl;
     
   return 0;
}
