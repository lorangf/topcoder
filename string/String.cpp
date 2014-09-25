
#include <vector>

#include "String.h"

using namespace std;

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
