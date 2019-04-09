#include <iostream>
#include <cstring>
using namespace std;

#define init 0
#define leftup 1
#define left 2
#define up 3

void lcs_print(int **lcs_direction,char* str1,char* str2,int row,int col)
{
    int length1 = (int)strlen(str1);
    int length2 = (int) strlen(str2);
    if(str1==NULL || str2==NULL)
    {
        return;
    }
    if(length1==0 ||length2==0 || !(row< length1 && col<length2))
    {
        return;
    }
    if(lcs_direction[row][col]==leftup)
    {
        if(row>0&&col>0)
        {
            lcs_print(lcs_direction,str1,str2,row-1,col-1);
        }
        cout << str1[row];
    }
    if(lcs_direction[row][col] == up)
    {
        if(row>0)
        {
            lcs_print(lcs_direction,str1,str2,row-1,col);
        }
    }
    if(lcs_direction[row][col] == left)
    {

        if(col>0)
        {
            lcs_print(lcs_direction,str1,str2,row,col-1);
        }
    }
}
int lcs(char *str1,char *str2)
{
    int length1 = (int)strlen(str1);
    int length2 = (int)strlen(str2);
    int **lcs_direction;
    lcs_direction =(int **) new int [(int)strlen(str1)];
    for(int i =0;i<(int)strlen(str1);i++)
    {
        lcs_direction[i] = new int [(int)strlen(str2)];
    }

    int **lcs_length;
    lcs_length = (int **)new int[length1];
    for(int i=0;i<length1;i++)
    {
        lcs_length[i] = new int [length2];
    }
    for(int i=0;i<length1;i++)
    {
        for(int j=0;j<length2;j++)
        {
            lcs_length[i][j]=0;
        }
    }
    for(int i=0;i<length1;i++)
    {
        for(int j=0;j<length2;j++)
        {
            lcs_direction[i][j] = init;
        }
    }
    for(int i=0;i<length1;i++)
    {
        for(int j =0;j<length2;j++)
        {
            if(i==0||j==0)
            {
                if(str1[i]== str2[j])
                {
                    lcs_length[i][j] = 1;
                    lcs_direction[i][j] =leftup ;
                }
                else
                {
                    if(i>0)
                    {
                        lcs_length[i][j] = lcs_length[i-1][j];
                        lcs_direction [i][j]= up;
                    }
                    if(j>0)
                    {
                        lcs_length[i][j] = lcs_length[i][j-1];
                        lcs_direction[i][j] = left;
                    }
                }
            }
            else if(str1[i]==str2[j])


                {
                    lcs_length[i][j]= lcs_length[i-1][j-1] + 1;
                    lcs_direction[i][j] = leftup;
                }
                else if(lcs_length[i-1][j]>lcs_length[i][j-1])


                    {
                        lcs_length[i][j]= lcs_length[i-1][j];
                        lcs_direction[i][j] = up;
                    }
                    else
                    {
                        lcs_length[i][j] = lcs_length[i][j-1];
                        lcs_direction[i][j] = left;
                    }


        }
    }
    lcs_print(lcs_direction,str1,str2,length1-1,length2-1);
    return lcs_length[length1-1][length2-1];
}



int main()
{
    char *str1="abcde";
    char *str2="abde";
    lcs(str1,str2);
    cout << "Hello world!" << endl;
    return 0;
}
