#include"iostream"
using namespace std;

 bool isPallindrome(string str, int l, int r){
     if(l>=r) return true;
     if(str[l]!=str[r]) return false;
     isPallindrome(str, l+1, r-1);
 }

 int powerSet(string str, int i, string curStr){
   if(i==str.length()){
       cout<<curStr<<" ";
      return 0;
       
   }
   powerSet(str, i+1, curStr+str[i]);
   powerSet(str, i+1, curStr);
 }

  string swap(string s, int l, int i){
	        char temp = s[l];
	        s[l] = s[i];
	        s[i] = temp;
	        return s;
	    }
	   
	   void permute(string s, int l, int r){
	       if(l==r){
	           cout<<s<<" ";
	           return;
	       }
	       for(int i = l; i<=r; i++){
	           s = swap(s, l, i);
	           permute(s, l+1, r);
	           s = swap(s, l, i);
	           
	       }
	   }

signed int main(){
    string str = "abc";
//cout<<isPallindrome(str, 0, str.size()-1)<<endl;

string curStr = "";
powerSet(str, 0, curStr);
// permute(str, 0, str.size()-1);
return(0);
}