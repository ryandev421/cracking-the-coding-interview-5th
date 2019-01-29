#include <iostream>
#include <string>
using namespace std;

bool isStringWithUniqueAlpha(string str)
{
    bool checked[255] = {false};

    for (int i = 0; i < str.length(); i++) {
        if (checked[(int)str[i]]) {
            return false;
        } else {
            checked[(int)str[i]] = true;
        }
    }
    return true;
}

int main()
{
    cout << isStringWithUniqueAlpha("aAbcEQ");
}