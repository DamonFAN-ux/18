#include<stdio.h>
#include<string.h>
#define MAXN 100
void zip(char*p);
int main()
{
    char a[MAXN]={0};
    int k=0;
    printf("请输入字符串：\n");
    while((a[k]=getchar())!='\n')
    k++;
    a[k]='\0';
    zip(a);
    printf("压缩成功了，请输出字符串：\n");
    int i;
    for(i=0;a[i]!='\0';i++)
    putchar(a[i]);
    printf("\n");
    return 0;
}
void zip(char*p)
{
    int count=1,j=0,m;
    int len=strlen(p);
    for(m=0;m<len;m++)
    {
        if(p[m]==p[m+1])
        count++;
        else if(p[m]!=p[m+1])
        {
            if(count==1)
            {
                p[j]=p[m];
                j++;
                count=1;
            }
            else if(count>1&&count<=9)
            {
                p[j]=count+'0';
                j++;
                p[j]=p[m];
                j++;
                count=1;
            }
            else if(count>=10)
            {
                p[j]=(count/10)+'0';
                j++;
                p[j]=(count%10)+'0';
                j++;
                p[j]=p[m];
                j++;
                count=1;
            }
        }
    }
    p[j]='\0';
}