#include <iostream>
/*  badizz™ */
using namespace std;

int partition(int array[],int left,int pivot,int right);
int quickSort(int array[], int left, int right);

int count = 0;

int partition(int array[],int left,int pivot,int right) {
    int split = left + 1, tmp;

    for (int track = left + 1; track < right; track++) 
	{
        if (array[track] < pivot) 
		{
            tmp = array[track];
            array[track] = array[split];
            array[split] = tmp;
            split++;
        }
    }

    tmp = array[split - 1];
    array[split - 1] = array[left];
    array[left] = tmp;
    return split - 1;
    /*  badizz™ */
}


int quickSort(int array[], int left, int right) 
{
    if (right <= left)
        return 0;

    int mid = (right + left - 1)/2;
    int pivot = array[mid];
    array[mid] = array[left];
    array[left] = pivot;
    int split = partition(array,left,pivot,right);
    count += right - left - 1;

    quickSort(array,left,split);
    quickSort(array,split + 1,right);
    return count;
    /*  badizz™ */
}

int main() {

    int secim,adet;
	cin>>secim>>adet;
	
	int a[adet];
	int ans;
	
	for (int m=0; m<adet-1; m++)
  		{
			cin>>a[m];
  		}

    cout << quickSort(a, 0, adet);
    /*  badizz™ */
    return 0;
}
