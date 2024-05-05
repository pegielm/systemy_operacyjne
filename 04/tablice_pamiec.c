#include <stdio.h>

int main(){
    int a[10];
    int b[10];
    int *wsk = a;
    for(int i = 0; i < 10; i++){
        a[i] = i;
        b[i] = i+10;
    }
    printf("Wartosc zmiennej wsk: %d\n", *wsk);
    wsk = wsk + 1;
    printf("Wartosc zmiennej wsk: %d\n", *wsk);
    return 0;
}