#include <iostream>
#include <string>
using namespace std;

bool isSequenceString(string &str_a, string &str_b)
{
	if (str_a == str_b) {
		return true;
	} else {
		for (int i = 0; i < str_a.length() - 1; i++) {
			string replaced_str = str_a.substr(i+1) + str_a.substr(0, i+1);
			if (replaced_str == str_b) {
				return true;
			}
		}
	}
	return false;
}

int main()
{
	string a = "abcdef";
	string b = "defabc";
	cout << isSequenceString(a, b);
}