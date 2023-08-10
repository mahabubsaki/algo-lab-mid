#include <bits/stdc++.h>
using namespace std;
bool isPalindromPossible(string str)
{
    int freq_arr[26];
    for (int i = 0; i < 26; i++)
    {
        freq_arr[i] = 0;
    }

    int oddCount = 2;
    bool result = true;
    for (int i = 0; i < str.size(); i++)
    {
        int index = str[i] - 97;

        freq_arr[index] += 1;
    }
    for (int i = 0; i < 26; i++)
    {
        if (oddCount == 0)
        {
            result = false;
            break;
        }
        if (freq_arr[i] % 2 == 1)
            oddCount--;
    }
    return result;
}
int main()
{
    string str;
    cin >> str;
    if (isPalindromPossible(str))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    return 0;
}