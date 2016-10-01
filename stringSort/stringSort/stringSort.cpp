/*********************************************************************
** Author:Benjamin Fields
** Date:9/21/2016
** Description:File to implement a version of the selection sort 
** algorithm with an array of C++ strings (std::string). The function
** should take two parameters: 1-array of strings(pointer) 2-size of 
** array. Function should be case insensitive
** Dependencies: 
*********************************************************************/

#include<iostream>
#include <string>
#include <cctype>

//returns 1 if str1 < str2, 0 if equal and -1 if str1 > str2
int caseInsensitiveStringCompare(const std::string &str1, const std::string &str2)
{
	char cstr1[255];
	char cstr2[255];
	if (str1.length() > 254 || str2.length() > 254)
	{
		std::cout << "Buffer overflow error" << std::endl;
		exit(EXIT_FAILURE);
	}
	strcpy(cstr1, str1.c_str());
	strcpy(cstr2, str2.c_str());
	for (int i = 0; i < (int)strlen(cstr1); i++)
	{
		cstr1[i] = toupper(cstr1[i]);
	}
	for (int i = 0; i < (int)strlen(cstr2); i++)
	{
		cstr2[i] = toupper(cstr2[i]);
	}
	return strcmp(cstr1, cstr2);
}

void stringSort(std::string array[], int numStrs)
{
	int startScan, minIndex;
	std::string minValue;
	for (startScan = 0; startScan < (numStrs - 1); startScan++)
	{
		minIndex = startScan;
		minValue = array[startScan];
		for (int index = startScan + 1; index < numStrs; index++)
		{
			if (caseInsensitiveStringCompare(array[index], minValue) < 0)
			{
				//std::cout << "Applying switch" << std::endl;
				minValue = array[index];
				minIndex = index;
			}
		}
		array[minIndex] = array[startScan];
		array[startScan] = minValue;
	}
}

void printArray(std::string array[], int size)
{
	for (int i = 0; i < 8; i++)
	{
		std::cout << *(array + i) << " | ";
	}
	std::cout << "\n";
}

int main(int argc, char* argv[])
{
	std::cout << "\n\nCheckpoint 1\n\n" << std::endl;
	std::string testString[8] = { "ben","Joe","adam","Dog","CAT","YOU","XAVIER","JOHN" };
	printArray(testString, 8);
	std::cout << "\n\nCheckpoint 2\n\n" << std::endl;
	stringSort(testString, 8);
	std::cout << "\n\nCheckpoint 3\n\n" << std::endl;
	std::cout << "Back in main after string sort" << std::endl;
	printArray(testString, 8);
	system("PAUSE");
	return 0;
}
