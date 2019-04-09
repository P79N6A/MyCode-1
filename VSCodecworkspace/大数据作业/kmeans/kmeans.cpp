#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include<cstring>
#include <cstdio>
using namespace std;
#define dim 3 //维度
#define maxsize 200//输入的最大数据量的个数
#define k 2//聚类中心的个数
class item
{
    public:
        double num[dim];
        int cluster;
        item(double x[dim])
        {
        	for(int i=0;i<dim;i++)
        	{
        		this->num[i]=x[i];
			}
            cluster=-1;
        }
        double distance(double x[dim])
        {
            int i;
            double dis=0;
            for(i=0;i< dim;i++)
            {
                dis+=(num[i]-x[i])*(num[i]-x[i]);
            }
            dis = sqrt(dis);
            return dis;
        }
};
vector<item>itemvec;
bool comparedis(double x[k][dim],double y[k][dim],double err)
{
    for(int i=0;i<k;i++)
    {
        //double dis=0;
        for(int j=0;j<dim;j++)
        {
            //dis+=(x[i][j]-y[i][j])*(y[i][j]-x[i][j]);
           // dis =sqrt((x[i][j]-y[i][j])*(y[i][j]-x[i][j]));
            if(abs(x[i][j]-y[i][j])>err)
            {
                return false;
            }
        }
    }
    return true;
}

void inputdata()
{
    ifstream infile("input.txt");
    if(!infile)
    {
        cout << "Open File Error"<<endl;
        return ;
    } 
    int i;
    char ch;
    for(i=0;i<maxsize;i++)
    {
		string x1,x2,x3;
        if(!infile.get(ch))
        {
            return ;
        }
        while(ch!=',')//读取第一个数据
        {
            if(ch==' ')
            {
                if(!infile.get(ch))
                {
                    return ;
                }
                continue;
            }
            x1+=ch;
            if(!infile.get(ch))  
			{
				return;  
			} 
        }
       // cout << x1;
        if(!infile.get(ch))
        {
            return ;
        }
        while(ch!=',')//读取第二个数据
        {
            if(ch==' ')
            {
                if(!infile.get(ch))
                {
                    return ;
                }
                continue;
            }
            x2+=ch;
            if(!infile.get(ch))  
			{
				return;  
			}  
        }
        //cout << x2;
        if(!infile.get(ch))
        {
            return ;
        }
        while(ch!='\n')//读取第三个数据
            if(ch==' ')
            {
                if(!infile.get(ch))
                {
                    return ;
                }
                continue;
            }
            x3+=ch;
            if(!infile.get(ch))  
			{
				cout<<"文件读取完成"<<endl;  
				return;  
			} 
        }
        //cout << x3;
        double x[dim];
        x[0]=atof(x1.c_str());
        x[1]=atof(x2.c_str());
        x[2]=atof(x3.c_str());
        item t1(x);
		/*for(int i=0;i<dim;i++)
        {
        	//printf("%.2lf ",it->num[i]);
            cout << t1.num[i]<<" ";
        }*/
        itemvec.push_back(t1);
    }
    infile.close();
}
void kmeans(double u[k][dim])
{
    double u0[k][dim];
    memcpy(u0,u,sizeof(u));
    while(1)
    {
        int j;
        vector<item>::iterator it;
        for(it=itemvec.begin();it!=itemvec.end();it++)
        {
            double dis[k];
            for(j=0;j<k;j++)
            {
                dis[j]=it->distance(u0[j]);
            }
            double mindis=dis[0];
            it->cluster=0;
            for(j=1;j<k;j++)
            {
                if(mindis>dis[j])
                {
                    mindis=dis[j];
                    it->cluster=j;
                }
            }
        }
    
        double sum[k][dim];
        int num[k];
        memset(num,0,sizeof(num));
        memset(sum,0,sizeof(sum));
        for(it = itemvec.begin(); it != itemvec.end(); ++it)
        {
            for(int i=0;i<dim;i++)
            {
                sum[it->cluster][i]+=it->num[i];
            }
            num[it->cluster]++;
        }
        //更新聚类中心
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<dim;j++)
         {
               if(num[i]!=0)
              {
                  u[i][j]=(sum[i][j])/(num[i]);//更新坐标
              }
          }
        }
        if (comparedis(u0,u,1.0e-5))
	    {
		   break;
	    }
	    memcpy(u0,u,sizeof(double)*k*dim);//u为新计算出的坐标，uo为前一次的坐标
    }
    //输出
    cout << "K-means中心点坐标为"<< "："<<endl;
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<dim;j++)
        {
        	//printf("%.2lf ",u[i][j]);
            cout << u[i][j]<<" ";
        }
        cout << endl;
    }
    cout <<"所属类别"<< " "<<"坐标"<<endl;
    for(vector<item>::iterator it = itemvec.begin();it!=itemvec.end();it++)
    {
        cout  <<"cluster="<< it->cluster<<" ";
        for(int i=0;i<dim;i++)
        {
        	//printf("%.2lf ",it->num[i]);
            cout << it->num[i]<<" ";
        }
        cout << endl;
    }
}
int main()
{
    inputdata();
    double u[k][dim]={{4.5,8.1,2.8},{-0.9,4.7,-0.3}};
    /*for(vector<item>::iterator it = itemvec.begin();it!=itemvec.end();it++)
    {
        cout  <<"cluster="<< it->cluster<<" ";
        for(int i=0;i<dim;i++)
        {
        	//printf("%.2lf ",it->num[i]);
            cout << it->num[i]<<" ";
        }
        cout << endl;
    }*/
    kmeans(u);
    return 0;
}