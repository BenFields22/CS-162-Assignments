//practice in programming the quicksort algorithm 
#include <iostream>
#include <algorithm>

int partition(int arr[], int start, int end)
{
	std::cout << "Entered partition function with array: ";
	for (int i = start; i < end+1; i++)
		std::cout << arr[i] << " ";
	std::cout << "and start: " << start << " which is " << arr[start] << " and end " << end << " which is " << arr[end] << "\n\n" <<std::endl;

	//the pivot element is taken to be the element at the start of the subrange to be partitioned
	int pivotValue = arr[start];
	std::cout << "Pivot Value chosen is " << pivotValue << std::endl;
	int pivotPosition = start;
	std::cout << "Pivot Position is " << pivotPosition << std::endl;

	//rearrange the rest of the array elements to partition the subrange from start to end
	for (int pos = start + 1; pos <= end; pos++)
	{
		std::cout << "In for loop with pos: " << pos << " and pivotPosition: " << pivotPosition << std::endl;
		std::cout << "Checking if " << arr[pos] << " < " << pivotValue << std::endl;
		if (arr[pos] < pivotValue)
		{
			std::cout << "It was indeed less than " << pivotValue << std::endl;
			//arr[scan] is the "current item
			//swap the current item with the item to the right of the pivot element
			std::cout << "About to swap " << arr[pivotPosition + 1] << " and " << arr[pos] << std::endl;
			std::swap(arr[pivotPosition + 1], arr[pos]);
			//swap the current item with the pivot element
			std::cout << "About to swap " << arr[pivotPosition] << " and " << arr[pivotPosition+1] << std::endl;
			std::swap(arr[pivotPosition], arr[pivotPosition + 1]);
			//adjust the pivot position so it stays withj the pivot element
			pivotPosition++;

			std::cout << "The array is now: ";
			for (int i = start; i < end+1; i++)
				std::cout << arr[i] << " ";
			std::cout << "\n\n";
		}
		else
		{
			std::cout << "was not less than" << std::endl;
		}
	}
	std::cout << "Finished partitioning and the pivotPosition is " << pivotPosition << std::endl;
	return pivotPosition;
}

void quicksort(int arr[], int start, int end)
{
	std::cout << "Entered quicksort with array: ";
	for (int i = start; i < end+1; i++)
		std::cout << arr[i] << " ";
	std::cout << "and start: "<<start<<" which is "<<arr[start]<<" and end "<<end<<" which is "<<arr[end] << "\n\n"<<std::endl;
	if (start < end)
	{
		//partition the array and get the pivot point 
		int p = partition(arr, start, end);

		//sort the portion before the pivot point
		quicksort(arr, start, p - 1);

		//sort the portion after the pivot point
		quicksort(arr, p + 1, end);
	}
}
void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";

	std::cout << "\n\n";
}

int main(int argc, char *argv[])
{
	const int SIZE = 10;
	int array[SIZE] = { 17, 53,9,2,30,1,82,64,26,5 };
	printArray(array, 10);

	quicksort(array, 0, SIZE - 1);

	printArray(array, 10);

	system("PAUSE");
	return 0;
}