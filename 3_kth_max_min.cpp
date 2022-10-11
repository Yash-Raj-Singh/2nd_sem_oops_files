// https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1

int kthSmallest(int arr[],int N,int K)
{
    sort(arr,arr+N);
    return arr[K-1];
}