#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
struct element
{
    int zhishu;//指数
    int xishu;//系数
    element *next;
    element(int zhisuh=0,int xishu=0)
    {
        zhishu = zhishu;
        xishu = xishu;
        next = NULL;
    }
};
struct polylist
{
   element *head;
   element *ele;
   element *tail;
   polylist()
   {
       head = new element; 
       head->xishu = 0;
       head->zhishu = 0;
       tail = head;
   }
   void append(element *ele)
   {
       tail->next = ele;
       tail = ele;
   }
   int length()
   {
       int count =0;
       element *ele = head->next;
       while(ele!=tail)
       {
           count++;
           ele=ele->next;
       }
       count++;
       return count;
   }
    polylist operator + ( polylist &p) 
    {
        polylist lc;
        element *apos=this->head.next,*bpos=p.head.next;
        int len = min(this->length(),p.length());
        while(1)
        { 
            element *temp=new element;
            if(apos.zhishu==bpos.zhishu)
            {
                temp.xishu = apos.xishu + bpos.xishu;
                lc.tail.next = temp;
                lc.tail = temp;
                bpos = bpos.next;
                apos = apos.next;
            }
            else if(apos.zhishu>bpos.zhishu) 
            {
                temp = bpos;
                lc.tail.next = temp;
                lc.tail = temp;
                bpos = bpos.next;
            }
            else 
            { 
                temp = apos;
                lc.tail.next = temp;
                lc.tail = temp;
                apos = apos.next;
            }
            if(apos.next==NULL&&bpos.next==NULL)
            {
                break;
            } 
           
        }

        return lc;
    }
    polylist operator= (polylist &p)
    {
        this.head.next= p.head.next ;
    }

};
int main()
{ 
    cout <<"(请按照“a，b”的格式输入，a为项的系数，b为项的指数，以空格作为分界)"<<endl;
    cout << "请输入第一个多项式"<<endl;
    int zhishu,xishu;
    char c;
    polylist la,lb;
    while(cin >>xishu>>c>>zhishu)
    {
        element *temp = new element;
        temp.zhishu = zhishu;
        temp.xishu = xishu;
        la.tail.next = temp;
        la.tail = temp;
    }
    cout << "请输入第二个多项式"<<endl;
    while(cin >>xishu>>c>>zhishu)
    {
        element *temp = new element;
        temp.zhishu = zhishu;
        temp.xishu = xishu;
        lb.tail.next = temp;
        lb.tail = temp;
    }
    cout<<"两个多项式相加的结果为"<<endl;
    lc = la +lb;
    element *pos=lc.head.next;
    while(pos.next!=NULL)
    {
        printf("%+dX%d",pos.xishu,pos.zhishu);
        pos=pos.next;
    }
    printf("%+dX%d",pos.xishu,pos.zhishu);
    return 0;
}