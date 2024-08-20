#include<stdio.h>
int main()
{
  char s1[80],s2[80];
  int i=0,result;
  scanf("%s",s1);
  scanf("%s",s2);
  while(s1[i]==s2[i]&&s1[i]!='\0')
  i++;
  if(s1[i]=='\0'&&s2[i]=='\0')
  result=0;
  else
  {
    result=s1[i]-s2[i];
  }
  printf("result:%d\n",result);
  return 0;
}