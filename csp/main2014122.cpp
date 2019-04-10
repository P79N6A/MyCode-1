#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int y[]={1,-1,0,1};
int x[]={0,1,1,-1};//分别为向右，向左下，向下，向右上 
int y1[]={1,1,0,-1};
int x1[]={0,-1,1,1};
int num[500][500]; 
int main(int argc, char** argv) 
{
	 int n;
	 cin >> n;
	 int i=0,j=0;
	 for(i=0;i<n;i++)
	 {
	 	for(j=0;j<n;j++)
	 	{
	 		cin >>num[i][j];
		}
	 }
	 i=0;
	 j=0;
	 int p=0,q=0;
	 while(1)
	 {
	 	
	 	cout << num[i][j]<<" ";
	 	while(1)
	 	{
	 	 q=p%4;	
		 i+=x[q];
		 j+=y[q];
		 cout << num[i][j]<<" ";
		 if(i==0||i==n-1||j==0||j==n-1)
		 {
		 	p++;
		 }
		 if((i==n-1&&j==0&&n%2==0)||(i==0&&j==n-1&&n%2!=0))
		 {
		 	break;
		 }
	 }	
	 	p=0;
	 	int t;
		 if(n%2==0)
		 {
		 	t=x[1];
		 	x[1]=x[3];
		 	x[3]=t;
		 	t=y[1];
		 	y[1]=y[3];
		 	y[3]=t;
		}
		else
		{
			t=x[0];
			x[0]=x[2];
			x[2]=t;
			t=y[0];
			y[0]=y[2];
			y[2]=t;	
		 } 
		while(1)
		{
			 q=p%4;
			 i+=x[q];
			 j+=y[q];
			 cout << num[i][j]<<" ";
			 if(i==0||i==n-1||j==0||j==n-1)
			 {
			 	p++;
			 }
			 if(i==n-1&&j==n-1)
			 {
			 	break;
			 }
		}
	 	if(i==n-1&&j==n-1)
	 	{
		  break;
		}
	}
	return 0;
}
