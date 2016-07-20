#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include "processo.h"

void comoUsar (char* progName, char* argumentos)
{
    fprintf(stderr, "como usar: %s %s\n", progName, argumentos);
    exit(0);
}

void menuPrincipal () {
    int option = 10;

    printf("\tBem-vindo, usuario!\n");
    printf("Digite 1 para inserir um processo;\nDigite 2 para finalizar um processo;\nDigite 3 para acessar endereco real\nDigite 0 para sair;\n");
    while (option != 0) {
        scanf("%d", &option);
        switch (option) {
            case 0:
                printf("Bye-bye~\n");
                break;
            case 1:
                menuInsereProc();
                break;
            case 2:
                // retira um processo da tabela de processos
                break;
            case 3:
                // acessa um endereco real segundo uma base de segmento e um offset
                break;
            default:
                printf("Opcao invalida!\nDigite 1 para inserir um processo;\nDigite 2 para finalizar um processo;\nDigite 3 para acessar endereco real\nDigite 0 para sair;\n");
                break;
        }
    }
}

void menuInsereProc() {
	int pid, numSeg;
	int *tamanhos;
	int i;
	printf("Digite Pid e quantidade de Segmentos: \n");
	scanf(" %d %d ", &pid, &numSeg);
	tamanhos = calloc(numSeg, sizeof(int));
	for (int i = 0; i < count; ++i)
	{
		printf("Digite tamanho %d:\n",i);
		scanf(" %d ", tamanhos[i]);
	}
	criaProcesso();
}

void printaEspacosLivres () {
    ESPACOLIVRE *noAtual = noCabeca;
    printf("(%d, %d)", noAtual->inicio, noAtual->fim);
    noAtual = noAtual->prox;

    while (noAtual) {
        printf("->(%d, %d)", noAtual->inicio, noAtual->fim);
        noAtual = noAtual->prox;
    }
    printf("\n");
}

void testaAlocacaoDeSegmentosNaMemoria () {
    int tamSegmento = 0, keepRunning = 1;
    char resposta;

    while (keepRunning) {
        printf("Digite um valor inteiro maior que zero para o tamanho do segmento que deseja alocar: ");
        scanf("%d", &tamSegmento);

        while (!(tamSegmento > 0)) {
            printf("\n\t>> Valor invalido!!! <<\n\nDigite um valor inteiro maior que zero para o tamanho do segmento que deseja alocar: ");
            scanf("%d", &tamSegmento);
        }

        printf("Segmento de tamanho %d entra.\n", tamSegmento);
        alocarSegmento(tamSegmento);
        printaEspacosLivres();
        printf("Deseja alocar outro segmento? (y/n) ");
        scanf(" %c", &resposta);
        if (!(resposta == 'Y' || resposta == 'y'))
        {
            printf("See ya~\n");
            keepRunning = 0;
        }
    }
}