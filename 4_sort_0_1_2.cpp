// https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1

void sort012(int arr[],int [])
{
    int low=0,mid=0,high=n-1;
    while(mid<=high)
    {
        if(a[mid]==0)
        swap(a[mid++],a[low++])
        else if(a[mid]==1)
        mid++;
        else
        swap(a[mid],a[high--]);
    }
}