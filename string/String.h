
#ifndef _STRING_H_
#define _STRING_H_

#include <string>
#include <vector>

class String
{
public:
	static void permutation(const std::wstring& str);
private:
	String(const std::wstring& input);
	void permute();

	std::wstring _string;
	std::vector<bool> _used;
	std::vector<wchar_t> _output;
};

void reverse_string(const std::wstring& input, std::wstring& output);
void itoa(int num, std::wstring& output);

#endif

