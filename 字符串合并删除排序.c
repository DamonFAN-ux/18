#include<stdio.h>
#include<string.h>
int Del(char s1[][10], char s2[][10], char *s3[]);
int main() 
{
    char s1[10][10] = {"jixiang", "lihua", "lihua", "lijian", "wanger", "zhanglin"};
    char s2[10][10] = {"chenming", "lihua", "lijian", "liutian", "zhouqi", "zhouqi"};
    char *s3[10] = {0};
    int n=Del(s1, s2, s3);
    int i,j,k;
    for (i = 0; i < n; i++) 
    {
     for (j = i + 1; j < n; j++) 
     {
      if (strcmp(s3[i], s3[j]) == 0)
      {
       for (k = j; k < n - 1; k++) 
       {
        strcpy(s3[k], s3[k + 1]);
       }
        n--;
        j--;
      }
     }
    }
    int index;
    for(i=0;i<n-1;i++)
    {
      index=i;
      for(j=i+1;j<n;j++)
      {
      if(strcmp(s3[index],s3[j])>0)
      {
       index=j;
      }
      }
      char*tmp=s3[i];
      s3[i]=s3[index];
      s3[index]=tmp;
    }
    for (k = 0; k < n; k++)
    {
      printf("%s ", s3[k]);
    }
    return 0;
}
int Del(char s1[][10], char s2[][10], char *s3[]) 
{
  int i, j, k, n1 = 6, n2 = 6, n3;
  for (i = 0; i < n1; i++) 
 {
  for (j = i + 1; j < n1; j++) 
  {
   if (strcmp(s1[i], s1[j]) == 0) 
   {
    for (k = j; k < n1 - 1; k++) 
    {
      strcpy(s1[k], s1[k + 1]);
    }
      n1--;
      j--;
   }
  }
 }
  int m = 0;
  for (i = 0; i < n1; i++)
  {
   s3[m++] = s1[i];
  }
  for (i = 0; i < n2; i++) 
  {
   for (j = i + 1; j < n2; j++) 
   {
    if (strcmp(s2[i], s2[j]) == 0) 
    {
     for (k = j; k < n2 - 1; k++)
     {
      strcpy(s2[k], s2[k + 1]);
     }
      n2--;
      j--;
    }
   }
  }
  for (i = 0; i < n2; i++) 
  {
   s3[m++] = s2[i];
  }
  n3 = n1 + n2;
  return n3;
}
