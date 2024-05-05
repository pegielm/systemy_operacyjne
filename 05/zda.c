#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Użycie: %s <rozmiar bufora> <plik.src> <plik.trg>\n", argv[0]);
        return 1;
    }

    int buffer_size = atoi(argv[1]);
    char *src_file = argv[2];
    char *trg_file = argv[3];

    FILE *src = fopen(src_file, "rb");
    if (src == NULL) {
        printf("Nie można otworzyć pliku źródłowego: %s\n", src_file);
        return 1;
    }

    FILE *trg = fopen(trg_file, "wb");
    if (trg == NULL) {
        printf("Nie można otworzyć pliku docelowego: %s\n", trg_file);
        fclose(src);
        return 1;
    }

    char buffer[buffer_size];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, buffer_size, src)) > 0) {
        fwrite(buffer, 1, bytes_read, trg);
    }

    fclose(src);
    fclose(trg);

    printf("Plik został skopiowany pomyślnie.\n");

    return 0;
}
