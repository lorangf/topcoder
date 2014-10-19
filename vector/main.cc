
#include <iostream>
#include <vector>

int main(int argc, char* argv[])
{
	std::vector<int> vec = {1, 2};
	for( auto v : vec ) {
		std::cout << v << ' ';
	}
	std::cout << std::endl;

	return 0;
}

