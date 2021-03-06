#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "compressao.h"
#include "adt.h"
#include "bitop.h"

#define DEBUG 1

void descompress(FILE *f,  char *h){
    setlocale(LC_ALL,"");

    //Tamanho do Lixo
    int trash;
    //Tamanho da  arvore
    int sizeTree, savesizeTree;
    //Para obter a arvore do arquivo
    pnode *huff;
    //Um novo arquivo com o nome e a extenção original
    FILE *Writeoutput;
    FILE *fbin;

    fbin = fopen(h,"rb");

    //Remove a extenção .huff
    h[strlen(h) - 5] = '\0';
    //Cria um novo arquivo com o nome e a extenção original
    Writeoutput = fopen(h,"w");
    //Fecha o arquivo
    fclose(Writeoutput);
    //Abre o arquivo para se modificado
    Writeoutput = fopen(h,"r+");
    // Inicializa a Lista
    huff = startpnode();

    //Recebe o tamanho do lixo
    trash = givemethetrash(f);
    printf("Tamanho : %d\n",trash);


    //Recebe o tamanho da arvore
    sizeTree = givemethesizeTree(f);
    printf("Tamanho : %d\n",sizeTree);


    //Tamanho original da arvore
    savesizeTree = sizeTree;
    //Obtem a arvore do arquivo
    huff = givemeHtree(f,&sizeTree);
    //INICIA A DESCOMPRESSAO DO ARQUIVO
    makedescompressOutputfile(fbin, Writeoutput, huff, trash, savesizeTree);


    if(DEBUG){
        printf("TRASH: %d\n",trash);
        printf("SIZETREE: %d\n",savesizeTree);
        printHtree(huff);
        printf("\n");
        //makeallchars();
    }

    printf("FIM DA DESCOMPRESSAO!\n");
}
