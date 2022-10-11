// https://practice.geeksforgeeks.org/problems/move-all-negative-elements-to-end1813

void arrange(int a[],int n){
    int neg=0;
    int pos=n-1;
    while(neg<=pos)
    {
        if(a[neg]<0 && a[pos]<0)
        neg++;
        else if(a[neg]>0 && a[pos]<0)
        {
            swap(a[neg],a[pos]);
            neg++;
            pos--;
        }
        else if(a[neg]>0 && a[pos]>0)
        pos--;
        else{
            neg++;
            pos--;
        }
    }
}