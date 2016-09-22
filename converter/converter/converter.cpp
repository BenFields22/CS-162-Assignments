#include <iostream>
#include <string>
#include <cmath>

int binToDec(std::string bin,int index)
{
	int sum = 0;
	int stopCondition = bin.length()-1;
	if (index <= stopCondition)
	{
		if (bin[index] == '1')
		{
			sum = (int)pow(2, (stopCondition - index));
		}
		else if (bin[index] != '0')
		{
			std::cout << "Invalid Binary number" << std::endl;
			system("PAUSE");
			exit(EXIT_FAILURE);
		}
			
		return sum + binToDec(bin, ++index);
	}
	return sum;
}

std::string decToBin(int num)
{
	if (num == 0)
	{
		return "0";
	}
	else if (num == 1)
	{
		return "1";
	}
	else
	{
		return decToBin(num/2) + decToBin(num % 2);
	}
}

int main(int argc, char* argv[])
{
	std::string binary = "10110111";
	int number = 183;
	int index = 0;
	int convertedBinary = binToDec(binary, index);
	std::string convertedInteger = decToBin(number);
	std::cout << convertedBinary << std::endl;
	std::cout << convertedInteger << std::endl;
	system("PAUSE");
	return 0;
}