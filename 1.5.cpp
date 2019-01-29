#include <iostream>
#include <string>
using namespace std;

string compressString(string str);
string shortenWithSameAlpha(char alpha, int duplicated_cnt);

string compressString(string str)
{
    if (str.length() == 0) {
        return str;
    }

    string res;
    int point_at = 0;
    for (int i = 1; i < str.length(); i++) {
        if (str[point_at] != str[i]) {
            int duplicated_cnt = i-point_at;
            res += shortenWithSameAlpha(str[point_at], duplicated_cnt);
            point_at = i;
        }
    }
    int duplicated_int = str.length() - point_at;
    res += shortenWithSameAlpha(str[point_at], duplicated_int);
    
    return (str.length() <= res.length()) ? str : res;
}

string shortenWithSameAlpha(char alpha, int duplicated_cnt)
{
    string res;
    res = alpha + to_string(duplicated_cnt);

    return res;
}

int main()
{
    cout << compressString("aabccccccccaaa");

    return 0;
}