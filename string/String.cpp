
#include <iostream>
#include <vector>

#include "String.h"

using namespace std;

//static
String::String(const wstring& input)
	: _string(input), _used(input.size(), false)
{
}

// static
void String::permutation(const wstring& input)
{
	String word(input);
	word.permute();
}

void String::permute()
{
	if ( _output.size() == _string.size() ) {
		wcout << wstring(_output.begin(),_output.end()) << endl;
		return;
	}

	for(int i=0; i<_used.size(); i++) {
		if ( _used[i] == false ) {
			_used[i] = true;
			_output.push_back(_string[i]);
			permute();
			_output.pop_back();
			_used[i] = false;
		}
	}
}

void reverse_string(const wstring& input, wstring& output)
{
	vector<wchar_t> text;
	int length = input.length();

	if ( length == 0 )
		return;

	for(int i=length-1; i>=0; i--) {
		text.push_back(input[i]);
	}

	int i=0, end=0;
	while( i<length ) {
		while(end<length && text[end] != L' ') {
			end++;
		}
	
		int w = end-1;	
		while(i<w) {
			wchar_t c = text[i];
			text[i] = text[w];
			text[w] = c;
			i++;
			w--;
		}

		end++;
		i=end;
	}

	output.resize(length);
	for(int i=0; i<length; i++)
		output[i] = text[i];

}

void itoa(int num, std::wstring& output)
{
	bool neg=(num<0)?true:false;
	vector<wchar_t> buffer;

	if (num < 0 ) num *=-1;
	while(num>0) {
		wchar_t c = (num%10)+'0';
		buffer.push_back(c);
		num /= 10;
	}
	if (neg)
		buffer.push_back('-');

	output = wstring(buffer.rbegin(), buffer.rend());
}

