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
 
int _tmain(int argc, _TCHAR* argv[])
{
	int arraySize;
	// a[] is the array to be sorted. ArraySize is the size of a[] ...
	merge_sort(a, 0, (arraySize-1) );        // would be more natural to use merge_sort(a, 0, arraySize ), so please try ;-)
 
	// some work 
	return 0;
}
