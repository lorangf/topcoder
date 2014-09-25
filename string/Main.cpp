
#include <iostream>

#include "String.h"

using namespace std;

int main(int argc, char* argv[])
{
	wstring text(L"This is a string to reverse.");

	wstring reverse;
	reverse_string(text, reverse);
	wcout << "Original: " << text << endl;
	wcout << "Reversed: " << reverse << endl;

	return 0;
}

