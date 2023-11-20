#include <stdio.h>
#include <string.h>

int deret(int a,int b){
  if (b == 0) {
    return 0;
  } else {
    return a + deret(a, b - 1);
  }

}

int deret2(int init,int params){
    int total = init;
    if(params != 1){
        printf("%d - ",total);
        total += 2;
        deret2(total,params-1);
    }
    if(params == 1){
        printf("%d ",total);
        return total;
    }
}

int deret5(int init,int params){
    int total = init;
    if(params != 1){
        printf("%d - ",total);
        total *= 5;
        deret5(total,params-1);
    }
    if(params == 1){
        printf("%d ",total);
        return total;
    }
}

int main() {
    // int totalValue;
    char str[100]="Makan";
    // totalValue = deret5(2,6);
    // printf("\nTotal deret = %d",totalValue);
    
    return 0;
}