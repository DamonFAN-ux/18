/*第一种情况：奇数阶(2n+1)
1.将1放在第一行的中间
2.后面的数字放在当前数字的前一行后一列
3.如果当前位置已有数据则放在前一个数字的下一行同列
*/
/*第二种情况：单偶数阶(4n+2)*/
/*第三种情况：双偶数阶(4n)*/
#include<stdio.h>
#define N 20
int main()
{   
    int a[N][N]={0};
    int i,n,j,k;
    scanf("%d",&n);
    int row,line,row_0,line_0;//line为行坐标，row为列坐标，line_0记录最新的行坐标，row_0记录最新的列坐标
    line=0;row=(n+1)/2-1;//初始化行、列坐标
    a[line][row]=1;
    for(i=2;i<=n*n;i++)
    {
        line_0=line;row_0=row;//记录上一次循环行、列坐标
        if(line==0&&row==n-1)//第1行第n列的情况
        {
            line=n-1;//行坐标转到第n行
            row=0;//列坐标转到第1行
        }
        else if(line==0)//第1行非第n列的情况
        {
            line=n-1;//行坐标转到第n行
            row++;//列坐标+1
        }
        else if(row==n-1)//非第1行第n列的情况
        {
            row=0;//列坐标转到第1列
            line--;//行坐标-1
        }
        else//普通情况
        {
            line--;//行坐标-1
            row++;//列坐标+1
        }
        if(a[line][row]!=0)//判断该位置是否有数字
        {
            line=line_0+1;//（基于本次for循环开始的坐标）行坐标-1，转跳到下一行
            row=row_0;//（基于本次for循环开始的坐标）列坐标不变
        }
        a[line][row]=i;//赋值
    }
    for(j=0;j<n;j++)
    {
        for(k=0;k<n;k++)
        printf("%d ",a[j][k]);
        printf("\n");
    }
    return 0;
}
