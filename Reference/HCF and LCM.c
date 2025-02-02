#include <stdio.h>
int main(){
  int a,b;
  printf("Enter the two numbers: ");
  scanf("%d %d",&a, &b);
  int hcf(int x,int y);
  int lcm(int x,int y);
}
int hcf(int x, int y){
  if(y==0){
    return x;
  return hcf(y,x%y);
}

int lcm(int x, int y){
  return((x*y)/hcf(x,y));
}
