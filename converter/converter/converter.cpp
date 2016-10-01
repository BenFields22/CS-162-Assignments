#include <iostream>
#include <string>
#include <cmath>

int binToDec(std::string myString)
{
	std::cout << "Entered Recursive function with string: " << myString.c_str() << std::endl;
	if (myString.length() == 1)
	{
		std::cout << "Base Case reached" << std::endl;
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
		if (myString[0] == '1')
		{
			return (int)pow(2, myString.length() - 1) + binToDec(myString.erase(0, 1));
		}
		else
		{
			return 0 + binToDec(myString.erase(0, 1));
		}
	}
}

std::string decToBin(int num) 
{
	std::cout << "Entered decToBin Recursive Function with number: "<<num << "(base case value) and remainer: "<<num%2<< std::endl;
	if (num == 0)
	{
		std::cout << "Base case reached" << std::endl;
		return "0";
	}
	else if (num == 1)
	{
		std::cout << "Base case reached" << std::endl;
		return "1";
	}
	else
	{
		return decToBin(num/2) + std::to_string(num%2);
	}
}

int main(int argc, char* argv[])
{
	std::string binary = "10110111";
	int number = 183;
	int convertedBinary = binToDec(binary);
	std::cout << "\n\nBack in main after conversion of binary number to integer" << std::endl;
	std::cout << "Value should equal 183. Value returned: "<<convertedBinary << "\n\n"<<std::endl;
	std::string convertedInteger = decToBin(number);
	std::cout << "\n\nBack in main after conversion of integer to binary" << std::endl;
	std::cout << "String should be 10110111. Returned string: "<<convertedInteger <<"\n\n"<< std::endl;
	std::cout << "Test 1: " << binToDec("1010") << std::endl;
	std::cout << "Test 2: " << decToBin(2) << std::endl;
	system("PAUSE");
	return 0;
}