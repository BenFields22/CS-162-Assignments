/*********************************************************************
** Author:Benjamin Fields
** Date:9/21/2016
** Description:File to implement a version of the selection sort 
** algorithm with an array of C++ strings (std::string). The function
** should take two parameters: 1-array of strings(pointer) 2-size of 
** array. Function should be case insensitive
** Dependencies: need the cctype library and the string library
*********************************************************************/

#include<iostream>
#include <string>
#include <cctype>
#include <cstring>
#include <cstdlib>

/*********************************************************************
** Description:function takes two c++ strings and compares them with 
a case insensitive method. The function returns an integer value based
on the comparison results of the two strings
**
*********************************************************************/
//returns 1 if str1 < str2, 0 if equal and -1 if str1 > str2
int caseInsensitiveStringCompare(const std::string &str1, const std::string &str2)
{
	//create c strings to hold the c++ string for comparision 
	char cstr1[255];
	char cstr2[255];

	//prevent a buffer overflow
	if (str1.length() > 254 || str2.length() > 254)
	{
		std::cout << "Buffer overflow error" << std::endl;
		exit(EXIT_FAILURE);
	}

	//copy the c++ strings to the c strings
	strcpy(cstr1, str1.c_str());
	strcpy(cstr2, str2.c_str());

	//convert each c string to all uppercase
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

/*********************************************************************
** Description: This function is an implementation of the selection 
sort algorithm as presented in the class textbook. This algorithm is
modified to sort c++ strings. It takes two parameters which are the 
array to sort and the size of the array or number of strings in this 
case.
**
*********************************************************************/
void stringSort(std::string array[], int numStrs)
{
	//assign values used to track progress of algorithm
	int startScan, minIndex;

	std::string minValue;

	//begin scanning array
	for (startScan = 0; startScan < (numStrs - 1); startScan++)
	{
		minIndex = startScan;
		minValue = array[startScan];
		//increment through positions to compare values
		for (int index = startScan + 1; index < numStrs; index++)
		{
			//caompare using custom string comparision function
			if (caseInsensitiveStringCompare(array[index], minValue) < 0)
			{
				//std::cout << "Applying switch" << std::endl;//debug line

				//apply swap 
				minValue = array[index];
				minIndex = index;
			}
		}
		//update variables to reflect latest progress of algorithm
		array[minIndex] = array[startScan];
		array[startScan] = minValue;
	}
}

/*********************************************************************
** Description:basic function implemented to provide an easy method 
for printing the array when running checks
**
*********************************************************************/
void printArray(std::string array[], int size)
{
	//loop through each position and print to screen
	for (int i = 0; i < 8; i++)
	{
		std::cout << *(array + i) << " | ";
	}
	std::cout << "\n";
}


/*********************************************************************
** Description:Main function used to drive the testing of the string
sort function. This function is the entry point of the program and 
tests a predetermined array of strings
**
*********************************************************************/
int main(int argc, char* argv[])
{
	//std::cout << "\n\nCheckpoint 1\n\n" << std::endl;//debug line

	//create test array
	std::string testString[8] = { "ben","Joe","adam","Dog","CAT","YOU","XAVIER","JOHN" };
	printArray(testString, 8);
	//std::cout << "\n\nCheckpoint 2\n\n" << std::endl;//debug line

	//test the sort function
	stringSort(testString, 8);

	//std::cout << "\n\nCheckpoint 3\n\n" << std::endl;//debug line
	//std::cout << "Back in main after string sort" << std::endl;//debug line

	printArray(testString, 8);
	//system("PAUSE");
	return 0;
}
