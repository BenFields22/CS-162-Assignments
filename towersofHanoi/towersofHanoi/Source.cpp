#include <iostream>
#include <string>

void moveDisks(int n, std::string source, std::string dest, std::string temp)
{
	if (n > 0)
	{
		moveDisks(n - 1, source, temp, dest);
		std::cout << "Move a disk from " << source << " to " << dest << std::endl;
		moveDisks(n - 1, temp, dest, source);
	}
}

int main(int argc, char *argv[])
{
	moveDisks(5, "peg 1", "peg 3", "peg 2");
	std::cout << "All disks have been moved" << std::endl;
	system("PAUSE");
	return 0;
}