#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void fill_array(int array[], int start);
void print_array(int array[], int start);
int smallest(int array[], int start, int end);

int main()
{
	const int size = 10;
	int array[size];
	
	fill_array(array, size);
	
	print_array(array, size);
	
	cout << smallest(array, 0, size-1) << endl;
	return 0;
}


void fill_array(int array[], int size)
{
	srand(time(NULL));
	for(int i=0; i<size; i++)
	{
		array[i] = rand() % 100 + 1;
	}
}


void print_array(int array[], int size)
{
	for(int i=0; i<size; i++)
	{
		cout << array[i];
		if(i+1 < size)
			cout << ", ";
	}
	cout << endl;
}


int smallest(int array[], int start, int end)
{
	if(start<end)
	{
		int middle = (start+end)/2;
		int smallest_l = smallest(array, start, middle);
		int smallest_r = smallest(array, middle+1, end);
		if(smallest_l < smallest_r)
			return smallest_l;
		else
			return smallest_r;
	}
	else
	{
		return array[start];
	}
}
