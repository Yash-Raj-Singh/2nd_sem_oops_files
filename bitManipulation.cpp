#include"iostream"
using namespace std;

int getBit(int n, int pos){
return((n & (1<<pos))!=0); 
}

int setBit(int n, int pos){
return((n | (1<<pos))); 
}

int clearBit(int n, int pos){
return((n & ~(1<<pos))); 
}

int updateBit(int n, int pos){
    int val;
    cout<<"Enter the val.";
    cin>>val;
    n = (n & ~(1<<pos));
return(n | (val<<pos)); 
}

signed main(){
int n;
int pos;
cout<<"Enter the no.";
cin>>n;
cout<<"Enter the pos.";
cin>>pos;
// cout<<getBit(n, pos);
// cout<<setBit(n, pos);
// cout<<clearBit(n, pos);
cout<<updateBit(n, pos);
}