#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct window
{
	int winnum;
	int x1,x2,y1,y2;
}win[15];
struct poin
{
	int x,y;
}point[15];

int order[15];/*°´ÕÕ¶ÑµþË³ÐòµÄ´°¿Ú±àºÅ*/ 

void change(int start)
{
	int i;
	for(i=start-1;i>=0;i--)
	{
		order[i+1]=order[i];
	}
}

int main(int argc, char** argv) 
{
	bool click=false;
	int n,m,i,j;
	cin >>n>>m;
	for(i=0;i<n;i++)
	{
		cin >>win[i].x1>>win[i].y1>>win[i].x2>>win[i].y2;
		win[i].winnum=i;
		order[i]=n-i-1;
	}
	for(i=0;i<m;i++)
	{
		cin >> point[i].x>>point[i].y;
	}
	for(i=0;i<m;i++)
	{
		click=false;
		for(j=0;j<n;j++)
		{
			if((point[i].x>=win[order[j]].x1)&&(point[i].y>=win[order[j]].y1)&&(point[i].x<=win[order[j]].x2)&&(point[i].y<=win[order[j]].y2))
			{
				int temp;
				cout <<win[order[j]].winnum+1/*<<endl*/;
				temp = win[order[j]].winnum;
				change(j); 
				order[0]=temp;
				click=true;
				break;
			}
		}
		if(!click)
		{
			cout << "IGNORED"<<endl;
		}
	}
	
	return 0;
}
