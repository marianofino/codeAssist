/*
 * Source: http://en.wikibooks.org/wiki/Algorithm_Implementation/Sorting/Merge_sort#C.2B.2B
 */

#include <iostream>

using namespace std;
 
void merge(int a[], const int low, const int mid, const int high)
{
	// Variables declaration. 
	int * b = new int[high+1-low];
	int h,i,j,k;
	h=low;
	i=0;
	j=mid+1;
	// Merges the two array's into b[] until the first one is finish
	while((h<=mid)&&(j<=high))
	{
		if(a[h]<=a[j])
		{
			b[i]=a[h];
			h++;
		}
		else
		{
			b[i]=a[j];
			j++;
		}
		i++;
	}
	// Completes the array filling in it the missing values
	if(h>mid)
	{
		for(k=j;k<=high;k++)
		{
			b[i]=a[k];
			i++;
		}
	}
	else
	{
		for(k=h;k<=mid;k++)
		{
			b[i]=a[k];
			i++;
		}
	}
	// Prints into the original array
	for(k=0;k<=high-low;k++) 
	{
		a[k+low]=b[k];
	}
	delete[] b;
}
 
void merge_sort(int a[], const int low, const int high)		// Recursive sort ...
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		merge_sort(a, low,mid);
		merge_sort(a, mid+1,high);
		merge(a, low,mid,high);
	}
}
 
int main(int argc, char* argv[])
{
	int array[] = {25,-57,13,73,69,9,74,-86,-73,4,-18,-58,20,6,-25,-91,-61,90,-26,-89,60,-10,99,36,-42};
   int arraySize = sizeof(array)/sizeof(int);

	// Print input
	cout << endl << "Original array:" << endl;
	for(int i = 0 ; i < arraySize ; i++)
        cout << "array[" << i << "] = " << array[i] << endl;

	merge_sort(array, 0, (arraySize-1) );
 
	// Print output
	cout << endl << "Sorted array:" << endl;
	for(int i = 0 ; i < arraySize ; i++)
        cout << "array[" << i << "] = " << array[i] << endl;

	return 0;
}
