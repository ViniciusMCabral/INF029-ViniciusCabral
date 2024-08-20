#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"

typedef struct {
    int *valor;
    int tamanho;
    int tamAtual;
} EstruturaAux;


EstruturaAux vetorPrincipal[TAM];

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{

    if (posicao < 1 || posicao > 10) {
        return POSICAO_INVALIDA;
    }


    if (tamanho < 1) {
       return TAMANHO_INVALIDO;
    }

    if (vetorPrincipal[posicao].valor != NULL) {
        return JA_TEM_ESTRUTURA_AUXILIAR;
    }
    else {
        vetorPrincipal[posicao].valor = (int *)malloc(tamanho * sizeof(int));
        if (vetorPrincipal[posicao].valor == NULL) {
           return SEM_ESPACO_DE_MEMORIA;
        }
        else {
            vetorPrincipal[posicao].tamanho = tamanho;
            vetorPrincipal[posicao].tamAtual = 0;
           return SUCESSO;
        }      
    }    
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Retorno (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{

    if (posicao < 1 || posicao > 10)
        return POSICAO_INVALIDA;

    if (vetorPrincipal[posicao].valor == NULL)
    {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    if (vetorPrincipal[posicao].tamAtual == vetorPrincipal[posicao].tamanho) 
    {
        return SEM_ESPACO;
    }

    vetorPrincipal[posicao].valor[vetorPrincipal[posicao].tamAtual] = valor;
    vetorPrincipal[posicao].tamAtual++;
    return SUCESSO;
}


/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{

    if (posicao < 1 || posicao > 10)
        return POSICAO_INVALIDA;

    if (vetorPrincipal[posicao].valor == NULL)
    {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    if (vetorPrincipal[posicao].tamAtual == 0)
    {
        return ESTRUTURA_AUXILIAR_VAZIA;
    }

    vetorPrincipal[posicao].tamAtual--;
    return SUCESSO; 
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{

    if (posicao < 1 || posicao > 10)
        return POSICAO_INVALIDA;

    if (vetorPrincipal[posicao].valor == NULL)
    {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    if (vetorPrincipal[posicao].tamAtual == 0)
    {
        return ESTRUTURA_AUXILIAR_VAZIA;
    }

    int numExiste = 0;
    int index = -1;
    for (int i = 0; i < vetorPrincipal[posicao].tamanho; i++) {
        if (vetorPrincipal[posicao].valor[i] == valor) {
            numExiste = 1;
            index = i;
            break;
        }
    }

    if (!numExiste) {
        return NUMERO_INEXISTENTE;
    }

    for (int i = index; i < vetorPrincipal[posicao].tamAtual - 1; i++) {
        vetorPrincipal[posicao].valor[i] = vetorPrincipal[posicao].valor[i + 1];
    }

    vetorPrincipal[posicao].tamAtual--;

    return SUCESSO;
}

int ehPosicaoValida(int posicao)
{
    if (posicao < 1 || posicao > 10)
    {
       return POSICAO_INVALIDA;
    }
    else
        return SUCESSO;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

    if (posicao < 1 || posicao > 10) {
        return POSICAO_INVALIDA;
    }
  
    if (vetorPrincipal[posicao].valor == NULL) {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    for (int i = 0; i < vetorPrincipal[posicao].tamAtual; i++) {
        vetorAux[i] = vetorPrincipal[posicao].valor[i];
    }

    return SUCESSO;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/

void bubbleSort(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

    if (posicao < 1 || posicao > 10) {
        return POSICAO_INVALIDA;
    }

    if (vetorPrincipal[posicao].valor == NULL) {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    for (int i = 0; i < vetorPrincipal[posicao].tamAtual; i++) {
        vetorAux[i] = vetorPrincipal[posicao].valor[i];
    }

    bubbleSort(vetorAux, vetorPrincipal[posicao].tamAtual);

    return SUCESSO;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int IAux = 0;
    int todasVazias = 1;

    for (int i = 1; i <= 10; i++) {
        if (vetorPrincipal[i].valor != NULL && vetorPrincipal[i].tamAtual > 0) {
            todasVazias = 0;
            for (int j = 0; j < vetorPrincipal[i].tamAtual; j++) {
                vetorAux[IAux++] = vetorPrincipal[i].valor[j];
            }
        }
    }

    if (todasVazias) {
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }

    return SUCESSO;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int IAux = 0;
    int todasVazias = 1;
    int totalElementos = 0;

    for (int i = 1; i <= 10; i++) {
        if (vetorPrincipal[i].valor != NULL && vetorPrincipal[i].tamAtual > 0) {
            todasVazias = 0;
            totalElementos += vetorPrincipal[i].tamAtual;
        }
    }

    if (todasVazias) {
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }

    for (int i = 1; i <= 10; i++) {
        if (vetorPrincipal[i].valor != NULL && vetorPrincipal[i].tamAtual > 0) {
            for (int j = 0; j < vetorPrincipal[i].tamAtual; j++) {
                vetorAux[IAux++] = vetorPrincipal[i].valor[j];
            }
        }
    }

    bubbleSort(vetorAux, totalElementos);

    return SUCESSO;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
    int retorno = 0;
    
    if (posicao < 1 || posicao > 10) {
        return POSICAO_INVALIDA;
    }

    // Verificar se existe uma estrutura auxiliar nesta posição
    if (vetorPrincipal[posicao].valor == NULL) {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    // Calcular o novo tamanho
    int tamanhoAtual = vetorPrincipal[posicao].tamanho;
    int tamanhoResultante = tamanhoAtual + novoTamanho;

    // Verificar se o novo tamanho é válido
    if (tamanhoResultante < 1) {
        return NOVO_TAMANHO_INVALIDO;
    }

    // Realocar a memória para o novo tamanho
    int *novoDados = (int *)realloc(vetorPrincipal[posicao].valor, tamanhoResultante * sizeof(int));
    if (novoDados == NULL) {
        return SEM_ESPACO_DE_MEMORIA;
    }

    // Atualizar a estrutura auxiliar
    vetorPrincipal[posicao].valor = novoDados;
    vetorPrincipal[posicao].tamanho = tamanhoResultante;

    // Se o novo tamanho for menor, garantir que a quantidade de elementos não seja maior que o tamanho
    if (vetorPrincipal[posicao].tamAtual > tamanhoResultante) {
            vetorPrincipal[posicao].tamAtual = tamanhoResultante;
    }

    return SUCESSO;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{

    if (posicao < 1 || posicao > 10) {
        return POSICAO_INVALIDA;
    }

    if (vetorPrincipal[posicao].valor == NULL) {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    if (vetorPrincipal[posicao].tamAtual == 0) {
        return ESTRUTURA_AUXILIAR_VAZIA;
    }

    return vetorPrincipal[posicao].tamAtual;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/

No* criarNo(int conteudo) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        return NULL;
    }
    novo->conteudo = conteudo;
    novo->prox = NULL;
    return novo;
}

void adicionarNo(No *cabeca, int conteudo) {
    No *novo = criarNo(conteudo);
    if (novo == NULL) {
        return; 
    }

    No *atual = cabeca;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    atual->prox = novo;
}

No* montarListaEncadeadaComCabecote() {
    No *cabecote = criarNo(0); 
    if (cabecote == NULL) {
        return NULL; 
    }

    int elementosInseridos = 0;

    for (int i = 0; i < TAM; i++) {
        if (vetorPrincipal[i].valor != NULL && vetorPrincipal[i].tamAtual > 0) {
            for (int j = 0; j < vetorPrincipal[i].tamAtual; j++) {
                adicionarNo(cabecote, vetorPrincipal[i].valor[j]);
                elementosInseridos++;
            }
        }
    }

    if (elementosInseridos == 0) {
        free(cabecote); 
        return NULL;
    }

    return cabecote;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/

void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
    No *atual = inicio->prox;
    int i = 0;

    while (atual) {
        vetorAux[i] = atual->conteudo;
        atual = atual->prox;
        i++;
    }
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/

void destruirListaEncadeadaComCabecote(No **inicio)
{
    No *atual = *inicio;
    No *anterior = NULL;

    while (atual) {
        anterior = atual;
        atual = atual->prox;
        free(anterior);
        anterior = NULL;
    }
    
    *inicio = NULL;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar()
{
    for (int i = 0; i < TAM; i++) {
        vetorPrincipal[i].valor = NULL;
        vetorPrincipal[i].tamanho = 0;
        vetorPrincipal[i].tamAtual = 0;
    }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
    for (int i = 1; i < TAM; i++) {
        if (vetorPrincipal[i].valor != NULL) {
            free(vetorPrincipal[i].valor);
            vetorPrincipal[i].valor = NULL;
            vetorPrincipal[i].tamAtual = 0;
            vetorPrincipal[i].tamanho = 0;
        }
    }
}