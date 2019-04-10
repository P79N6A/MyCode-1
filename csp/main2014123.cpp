#include <iostream>
#include<cstring>
#include<queue>
#include<cstdio>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct trading
{
	int  i;
	char order;
	double price;
	long long size;
	bool operator <(const trading &n) const
	{
		if(order=='b')
		{
			return price > n.price;
		}
		else
		{
			return price < n.price;
		 }
	}
 } ;
 const int N=5000;
 bool cancel[N+1];
int main(int argc, char** argv) {

	int n=0;
	int sellnum=0,buynum=0;
	string tra;
	trading t;
	memset(cancel,false,sizeof(cancel));
	priority_queue<trading> buy,sell;
	while(cin >> tra)
	{
		n++;
		if(tra[0]=='b')
		{
			buynum++;
			t.i=n;
			t.order='b';
			cin >> t.price>>t.size;
			buy.push(t);
		}
		else if(tra[0]=='s')
		{
			sellnum++;
			t.i=n;
			t.order='s';
			cin >> t.price>>t.size;
			sell.push(t);
		}
		else if(tra[0]='c')
		{
			int x;
			cin >> x;
			cancel[x]=true;
		}
		else
		{
			break;
		}
	}
	long long size;
	long long sizebuy=0;
	long long sizesell=0;
	trading b,s;
	/*while(!sell.empty())
	{
		s=sell.top();
		if(cancel[s.i]==true)
		{
			sell.pop();
		}
		else
		{
			break;
		}
	}
	while(!buy.empty())
	{
		b=buy.top();
		if(cancel[b.i]==true)
		{
			if(b.order=='b')
			{
				buynum--;
			}
			else
			{
				sellnum--;
			}
			buy.pop();
		}
		else
		{
			break;
		}
	}*/
	s=sell.top();
	b=buy.top();
	while(1)
	{
		if(b.price>=s.price&&cancel[b.i]==false&&cancel[s.i]==false)
		{
			break;
		}
		else if(sellnum>=buynum)
		{
		    while(1)
            {
                s=sell.top();
                sell.pop();
            }
		}
		else if(sellnum<buynum)
		{
		    while(1)
            {
                b=buy.top();
                buy.pop();
            }

		}
	}
	sizesell=s.size;
	sizebuy=b.size;
	while(1)
	{
		if(!sell.empty())
		{
			t=sell.top();
			sell.pop();
			if(cancel[t.i]==true)
            {
                continue;
            }
			sizesell+=t.size;
		}
		if(!buy.empty())
		{
			t=buy.top();
			buy.pop();
			if(cancel[t.i]==true)
            {
                continue;
            }
			sizebuy+=t.size;
		}
		if(sell.empty()&&buy.empty())
		{
			break;
		}
	}
	cout <<sizebuy<<endl;
	cout << sizesell<<endl;
	size =min(sizebuy,sizesell);
	cout << b.price<<" "<<size;
	return 0;
}
