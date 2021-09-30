#include <iostream>

using namespace std;

int number_of_bit(int n)
{
    int count = 0;
    while(n != 0)
    {
        n = (n & (n-1));
        count++;
    }

    return count++;
}

int xorOP(int a, int b)
{
    int c = a^b;

    return number_of_bit(c);
}

int main()
{
    int a, b;
    cin>>a>>b;

    cout<<xorOP(a,b)<<endl;

    return 0;
}