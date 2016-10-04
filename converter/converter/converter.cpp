/*********************************************************************
** Author:Benjamin Fields
** Date:9/21/2016
** Description: Program that contains two functions used to convert a 
binary number into a decimal integer and a decimal integer into a its
binary representation
** Dependencies: need the string library and the cmath library as well
as the iostream library for input and output
*********************************************************************/


#include <iostream>
#include <string>
#include <cmath>

/*********************************************************************
** Description: Binary to decimal. Function takes as a parameter a 
c++ string and returns the decimal integer value. This function also 
employs a recursive technique to solve the problem.
**
*********************************************************************/
int binToDec(std::string myString)
{
	//debug line to track program
	//std::cout << "Entered Recursive function with string: " << myString.c_str() << std::endl;

	//declare the base case
	if (myString.length() == 1)
	{
		//std::cout << "Base Case reached" << std::endl;//debug line 
		
		//check if the leftmost character is a 1 or 0 to add the proper value
		if (myString[0] == '1')
		{
			return (int)pow(2, 0);
		}
		else
		{
			return 0;
		}
	}
	else
	{
		//recursive step
		if (myString[0] == '1')
		{
			//if left most character is one add 2^power of correct power based on string
			//and concatenate that with the value returned from the recursive call with 
			//the first character removed
			return (int)pow(2, myString.length() - 1) + binToDec(myString.erase(0, 1));
		}
		else
		{
			//if 0 then dont add anything but recursively call for next positions
			//with the first character removed
			return 0 + binToDec(myString.erase(0, 1));
		}
	}
}

/*********************************************************************
** Description:decimal to binary. Takes as a parameter one integer 
and returns the binary C++ string representation. The function also 
uses a recursive technique to solve the problem.
**
*********************************************************************/
std::string decToBin(int num) 
{
	//debug line for tracking
	//std::cout << "Entered decToBin Recursive Function with number: "<<num << "(base case value) and remainer: "<<num%2<< std::endl;
	
	//check base case which is reached when the division by two returns 1 or 0 
	//indicating the last position is reached
	if (num == 0)
	{
		//std::cout << "Base case reached" << std::endl;//debug line
		return "0";
	}
	else if (num == 1)
	{
		//std::cout << "Base case reached" << std::endl;//debug line
		return "1";
	}
	else
	{
	   	//create the string to contain the remainder
	   	std::string remainder;

		//assign the string a value of 1 or 0
	   	if(num%2 == 1)
		   remainder = "1";
		else
		   remainder = "0";


		//recursive step called 
		return decToBin(num/2) + remainder;
	}
}


/*********************************************************************
** Description:Main function that is used to drive the testing of the 
two convert functions listed above. Tests a conversion of an integer 
to binary and a binary number to integer.
**
*********************************************************************/
int main(int argc, char* argv[])
{
	//create test string
	std::string binary = "10110111";

	//create test int
	int number = 183;

	//test the binary to decimal conversion
	int convertedBinary = binToDec(binary);

	//print to check the value returned
	std::cout << "\n\nBack in main after conversion of binary number to integer" << std::endl;
	std::cout << "Value should equal 183. Value returned: "<<convertedBinary << "\n\n"<<std::endl;

	//test decimal to binary
	std::string convertedInteger = decToBin(number);

	//print to check value returned
	std::cout << "\n\nBack in main after conversion of integer to binary" << std::endl;
	std::cout << "String should be 10110111. Returned string: "<<convertedInteger <<"\n\n"<< std::endl;
	std::cout << "Test 1: " << binToDec("1010") << std::endl;
	std::cout << "Test 2: " << decToBin(2) << std::endl;
	//system("PAUSE");
	return 0;
}
