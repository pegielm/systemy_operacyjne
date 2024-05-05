#include <stdio.h>

int main(){
    int a = 5;
    int *wsk = &a;
    printf("Wartosc zmiennej a: %d\n", a);
    printf("Adres zmiennej a: %p\n", &a);
    printf("Wartosc wskaznika wsk: %p\n", wsk);
    printf("Wartosc zmiennej wskaznikowej: %d\n", *wsk);
    printf("Adres zmiennej wskaznikowej: %p\n", &wsk);
    return 0;
}