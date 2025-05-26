#include<iostream>
using namespace std;
int main()
{
	int n;
	
	cout << "enter array size : ";
	cin >> n;

	int arr[n]; 
	
	for(int  i=0; i<n; i++)
	{
		cout << "Enter arry["<< i << "]:";
		cin >> arr[i];
	}
	cout<< "even number is: ";
	for (int i=0; i<n;i++)
	if(arr[i]%2==0){
		cout << arr[i] << " ";
	}
}