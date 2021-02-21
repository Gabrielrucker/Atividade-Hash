

#include "../include/espalhamento.h"
#include "../include/arquivo.h"

bool insere_no_arquivo(FILE* fp, REGISTRO* p, int pos) {

    fp = fopen("dados.bin", "ab");
    fseek(fp, pos * sizeof(REGISTRO), SEEK_SET);
    fwrite(&p, sizeof(REGISTRO), 1, fp);
    fclose(fp);
    return true;


}