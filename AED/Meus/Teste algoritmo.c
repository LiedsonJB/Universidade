#include <stdio.h>


int inv(int n){
    int d;
    static N=0;

  if(n > 0){

        d=n%10;
        N= N*10+d;
        n/=10;
        inv(n);
    }else
    return N;


  }

void main(){

    int n;

    scanf("%d", &n);

    printf("%d", inv(n));

}
