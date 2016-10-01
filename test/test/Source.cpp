#include <iostream>
#include <math.h>

int binToDec(std::string myString)
{
	std::cout << "Entered Recursive function with string: " << myString.c_str() << std::endl;
	if (myString.length() - 1 == 0)
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
			return (int)pow(2, myString.length() -1)+binToDec(myString.erase(0,1));
		}
		else
		{
			return 0 + binToDec(myString.erase(0, 1));
		}
	}
}

int main()
{
	std::string binNum = "1111";
	std::cout << "String length is: " << binNum.length() << std::endl;
	int ans = binToDec(binNum);
	std::cout << "Back in main" << std::endl;
	std::cout << ans << std::endl;
	system("PAUSE");
	return 0;
}