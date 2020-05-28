#include "Utilities.h"

string convert_double_to_string(double nr)
{
	string s = to_string(nr);
	int decimalSepPos = s.find('.');
	if (decimalSepPos != string::npos) // npos is a static member constant value with the greatest possible value for an element of type size_t.
	{
		size_t len = s.length() - 1;
		while (s[len] == '0') {
			len--;
		}
		if (len == decimalSepPos)
			s = s.substr(0, len);
		else
			s = s.substr(0, len + 1);
	}
	return s;
}

string convert_int_to_string(int nr)
{
	string s = to_string(nr);
	return s;
}


