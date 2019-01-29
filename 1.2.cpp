#include <iostream>
#include <string.h>
using namespace std;

void reverse(char* str)
{
    int len = (int)strlen(str);
    int le = 0, ri = len - 1;
    while (le < ri) {
        char tmp;
        tmp = str[le];
        str[le] = str[ri];
        str[ri] = tmp;
        le ++;
        ri --;
    }
}

int main()
{
    char str[] = "abcdefg";
    reverse(str);
    cout << str;
}