#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	int n; 

	cout<<"Enter n : ";
	cin>>n;

	char arr[200][200];

	for(int i = 0; i<=n; i++)
	{
		for(int j = 0; j<=n; j++)
		{
			cin>>arr[i][j];
		}
	}
    
    cout<<"\n";
	
    for(int i = n; i>=0; --i)
    {
    	for(int j = 0; j<=n; j++)
    	{
    		cout<<arr[i][j];
    	}

    
		}

    cout<<endl;

	return 0;
}