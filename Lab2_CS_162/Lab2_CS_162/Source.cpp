#include <iostream>
#include <algorithm>


int linearSearch(const int list[], int size, int value, int &countLin)
{
	int index = 0;
	int position = -1;
	bool found = false;

	while(index < size && !found)
	{
		if (list[index] == value)
		{
			found = true;
			position = index;
		}
		countLin++;
		index++;
	}
	return position;
}

int binarySearch(const int array[], int size, int value, int &countBin)
{
	int first = 0, last = size - 1, middle, position = -1;
	bool found = false;

	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (array[middle] == value)
		{
			found = true;
			position = middle;
		}
		else if (array[middle] > value)
		{
			last = middle - 1;
		}
		else
		{
			first = middle + 1;
		}
		countBin++;
	}
	return position;
}

void fillArray(int array[], int size1)
{
	for (int i = 0; i < size1; i++)
	{
		array[i] = rand() % 1000000 + 1;
	}
}

void testArrays(int array[], int size1)
{
	int randomNumber = rand() % 1000000 + 1;
	std::cout << "Going to search for the value: " <<randomNumber<< std::endl;
	int countLin = 0, countBin = 0;
	int binaryReturn = binarySearch(array, size1, randomNumber,countBin);
	int linearReturn = linearSearch(array, size1, randomNumber, countLin);
	std::cout << "Linear search returned value: "<<linearReturn <<" and went through "<< countLin <<" Iterations"<< std::endl;
	std::cout << "Binary search returned value: " << binaryReturn << " and went through " << countBin << " Iterations" << std::endl;

}

void printArray(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << "\n\n";
}

void verifySearchFunctions()
{
	std::cout << "\n\n*******************TESTING*******************\n\n" << std::endl;
	std::cout << "Testing search functions" << std::endl;
	int testArray[] = { 3,4,1,7,55,77,2,1,8,9 };
	printArray(testArray, 10);
	std::sort(testArray, testArray + 10);
	printArray(testArray, 10);
	int count = 0;
	int linAns = linearSearch(testArray, 10, 55, count);
	int binAns = binarySearch(testArray, 10, 55, count);
	if (linAns == 8 && binAns == 8)
		std::cout << "Both search functions are performing nominally" << std::endl;
	else
		std::cout << "Search functions are not performing correctly" << std::endl;

	std::cout << "Testing program functions: fillArray, printArray, std::sort and testArrays\n" << std::endl;
	std::cout << "Testing fillarray function\n" << std::endl;
	fillArray(testArray, 10);
	std::cout << "Testing print array function\n" << std::endl;
	printArray(testArray, 10);
	std::cout << "Testing std::sort function\n" << std::endl;
	std::sort(testArray, testArray + 10);
	printArray(testArray, 10);
	std::cout << "Testing testArrays function\n" << std::endl;
	testArrays(testArray, 10);
	std::cout << "\n\n*******************TESTING COMPLETE*******************\n\n" << std::endl;
}

int main(int argc, char *argv[])
{
	verifySearchFunctions();

	/*int array1[1000];
	fillArray(array1, 1000);

	int array2[10000];
	fillArray(array2, 10000);

	int array3[100000];
	fillArray(array3, 100000);

	std::sort(array1, array1 + 1000);
	std::sort(array2, array2 + 10000);
	std::sort(array3, array3 + 100000);

	testArrays(array1, 1000);
	testArrays(array2, 10000);
	testArrays(array3, 100000);*/

	//int array4[1000000];
	//fillArray(array4, 1000000);
	//std::sort(array4, array4 + 1000000);
	//testArrays(array4,1000000);
	
	system("PAUSE");
	return 0;
}