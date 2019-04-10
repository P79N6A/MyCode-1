#include <iostream>
#include<cstring>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
const int N=1000;
int num[N+1];
int main(int argc, char** argv) 
{
	int n,p;
	cin>>n;
	memset(num,0,sizeof(num));
	while(n--)
	{
		cin >> p;
		num[p]++;
		cout << num[p]<<" ";
	}
	
	return 0;
}
