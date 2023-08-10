#include <bits/stdc++.h>
using namespace std;

int calculateSum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int lastDigit = n % 10;
    return lastDigit + calculateSum((n - lastDigit) / 10);
}
int main()
{
    int n;
    cin >> n;
    cout << calculateSum(n);
    return 0;
}