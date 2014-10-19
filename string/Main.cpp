
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

	wcout << "Integer Conversion: " << endl;
	int num = -5932;
	wstring conversion;
	itoa(num, conversion);
	wcout << "Integer=" << num << ". Converted string: <" << conversion << ">" << endl;

	wcout << "Permutation of a string" << endl;
	wstring word(L"iron");
	wcout << "Input: " << word << endl;
	String::permutation(word);

	return 0;
}

