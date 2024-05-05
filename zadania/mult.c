#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Użycie: %s <zakres X> <zakres Y>\n", argv[0]);
        return 1;
    }

    int zakres_x = atoi(argv[1]);
    int zakres_y = atoi(argv[2]);

    int pytania = 0;
    int poprawne_odpowiedzi = 0;
    int niepoprawne_odpowiedzi = 0;

    time_t start_time = time(NULL);
    printf("quiz mnozenia\n (wpisz 0 aby zakonczyc)\n");
    while (1) {
        srand(time(NULL));
        int liczba1 = rand() % zakres_x + 1;
        int liczba2 = rand() % zakres_y + 1;

        printf("Ile to jest %d * %d?: ", liczba1, liczba2);

        int odpowiedz;
        scanf("%d", &odpowiedz);

        if (odpowiedz <= 0) {
            break;
        }

        pytania++;

        int oczekiwany_wynik = liczba1 * liczba2;

        if (odpowiedz == oczekiwany_wynik) {
            printf("Poprawna odpowiedz!\n");
            poprawne_odpowiedzi++;
        } else {
            printf("zla odpowiedz: %d.\n", oczekiwany_wynik);
            niepoprawne_odpowiedzi++;
        }
    }

    time_t end_time = time(NULL);
    int calkowity_czas = (int)(end_time - start_time);

    printf("wyniki\n");
    printf("  liczba pytan: %d\n", pytania);
    printf("  poprawne odpowiedzi: %d\n", poprawne_odpowiedzi);
    printf("  zle odpowiedzi: %d\n", niepoprawne_odpowiedzi);
    printf("  czas trwania quizu: %d sekundy\n", calkowity_czas);
    if(poprawne_odpowiedzi > niepoprawne_odpowiedzi){
        printf("  zdales !!!\n");
    }else{
        printf("  zapraszam na poprawke\n");
    }

    return 0;
}
