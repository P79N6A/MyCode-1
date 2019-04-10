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
	while(cin >>tra)
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
		else if(tra[0]=='c')
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
	while(!sell.empty())
	{
		s=sell.top();
		if(cancel[s.i]==true)
		{
		    if(b.order=='s')
			{
				sellnum--;
			}
			else
			{
				sellnum--;
			}
			sell.pop();
		}
		else
		{
		    sell.pop();
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
				buynum--;
			}
			buy.pop();
		}
		else
		{
		    buy.pop();
			break;
		}
	}
	while(1)
	{
		if(b.price>=s.price)
		{
			break;
		}
		else if(sellnum>=buynum)
		{
		    while(!buy.empty())
            {
                s=sell.top();
                if(cancel[s.i]==true)
                {
                    sell.pop();
                }
                else
                {
                    sell.pop();
                    break;
                }
           }

		}
		else if(sellnum<buynum)
		{
		    while(!buy.empty())
            {
                b=buy.top();
                if(cancel[b.i]==true)
                {
                    buy.pop();
                }
                else
                {
                    buy.pop();
                    break;
                }
            }
		}
	}
    cout << b.price<<" ";
	while(1)
	{
		if(!sell.empty())
		{

			if(cancel[s.i]==true)
            {
                s=sell.top();
                sell.pop();
                continue;
            }
            else
            {
                sizesell+=s.size;
            }
            s=sell.top();
            sell.pop();
		}
		if(!buy.empty())
		{

			if(cancel[b.i]==true)
            {
                b=buy.top();
                buy.pop();
                continue;
            }
            else
            {
                sizebuy+=b.size;
            }
            b=buy.top();
            buy.pop();
		}
		if(sell.empty()&&buy.empty())
		{
			break;
		}
	}
	sizebuy+=b.size;/*在152-184中，因为pop在最后，所以在最后一个元素取到以后，while直接结束，并不会加到sizesell和sizebuy中，所以此处单独相加*/
	sizesell+=s.size;
	size =min(sizebuy,sizesell);
	cout <<size;
	return 0;
}
