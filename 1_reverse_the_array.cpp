// https://practice.geeksforgeeks.org/problems/reverse-an-array/0
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        for(int i=n;i>0;i--)
        cout<<arr[i]<<" ";
        cout<<endl;
    }
}



// void rvereseArray(int arr[], int start, int end)
// {
//     if (start >= end)
//         return;

//     int temp = arr[start];
//     arr[start] = arr[end];
//     arr[end] = temp;

//     // Recursive Function calling
//     rvereseArray(arr, start + 1, end - 1);
// }