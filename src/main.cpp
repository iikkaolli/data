#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

int main(int argc, char **argv)
{
	std::cout << "Hello World!" << std::endl;	

	std::vector<int> myVector {1,2,3,4,5,6,7,8,9,10};

	for(const auto& number : myVector)
	{
		std::cout << number << std::endl;
	}

	int nSeconds = 0;
	while(nSeconds++ < 10)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << nSeconds << std::endl;
	}	

	return 0;
}

