#include<stdio.h>


void solve()
{
char arr[1000];
int n;
printf("enter size of string\n");
scanf("%d",&n);
for(int i=0;i<n;i++){
  scanf(" %c",&arr[i]);
}
arr[n]='\0';
char b[n+1];
int k=0;
for(int i=n-1;i>=0;i--){
  b[k]=arr[i];
  k++;
}
b[k]='\0';
for(int i=0;i<=n;i++){
  printf("%c",b[i]);
}
printf("\n");













}






int main()
{
  
int t=1;
//scanf("%d",&t);

while(t--){
  solve();
}


  return 0;
}