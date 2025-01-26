/* Bom esse projeto eu vou usar NOSQL como principal ideia, para criar o BD de uma loja */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

/* (typedef struct) para criar varias variaveis de tipos diferente */
/* Lembrete breve sobre o struct; Eu usei, pois as variaveis são de valores unicos */
typedef struct stockloja{
    char id_codProduto[15];
    char nomeProduto[50]; 
    int quantidadeStock;
    float valorProduto;
} idproduto;

/* Função para cadastar produtos */

void cadastroProdutos(idproduto *produtos){
    /* Armazenar o código do produto */
    printf("Digite o código do produto.:  ");
    fgets(produtos-> id_codProduto, sizeof(produtos-> id_codProduto), stdin);
    produtos-> id_codProduto[strcspn(produtos->id_codProduto, "\n")] = '\0';
    /* Armazenar nomeProduto */

    printf("Nome do Produto.:  ");
    fgets(produtos-> nomeProduto, sizeof(produtos-> nomeProduto), stdin); /* Lê os produtos e armazena na estrutura, incluindo a quebra de linha '\n' */
    produtos-> nomeProduto[strcspn(produtos-> nomeProduto, "\n")] = '\0'; /* Após a leitura ele remove o caractere '\n', deixado pelo fgets*/
    
    /* Armazena o quantidade de produtos em stock */

    printf("Quantidade de produtos.: ");
    scanf("%d", &produtos-> quantidadeStock);
    getchar(); /* Limpar o buffer */

    /* Valores do produto  */

    printf("Digitar o valor.: ");
    scanf("%f", &produtos-> valorProduto);
    getchar(); /* Limpar o buffer */
}

/* Função para armazenar produtos, usando dois tipos de ponteiros */
void armazenarProdutos(const char *nomeprodutos, idproduto *produtos){
    FILE *arquivo = fopen(nomeprodutos, "ab"); /* Abertura do arquivo no modo edição*/
    /* Valores não encontrados, exibira a mensagem de erro ao abrir o arquivo  */
    if(arquivo == NULL){
        perror("Erro ao abrir o arquivo"); 
    }
    fwrite(produtos, sizeof(idproduto), 1, arquivo);
    fclose(arquivo);
}

/* Função para carregar o que foi armazenado */
int carregarProdutos(const char *nomeprodutos, idproduto *produtos, int maxprodutos){
    FILE *arquivo = fopen(nomeprodutos, "rb"); /* Abertura do arquivo no modo leitura */
    if(arquivo == NULL){
        perror("Erro ao abrir o arquivo");
        return 0;
    }
    int  i = 0;
    while(fread(&produtos[i], sizeof(idproduto), 1, arquivo) == 1 && i < maxprodutos){
        i++;
    }
    fclose(arquivo);
    return i; /* Retornar o número de produtos cadastrado */
}






