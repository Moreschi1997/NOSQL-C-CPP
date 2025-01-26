#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* Função para buscar produtos pelo idproduto */

int buscaProdutos(idproduto *produtos, int total, const char *codigo){
    //Contador e o i; lógica for para uma iteração deterministica
    for(int i = 0; i <= total; i++) {
        if(strcmp(produtos[i].id_codProdutos, codigo) == 0){
        return i; /* Volta o valor da iteração */
        }
    }
    return -1; /* Se o valor não e incontrado volta -1  */
}

/* Funçaõ para atulizar produtos */

void atulizacaoProduto(idprodutos *produtos, int total, const char *codigo){
    int buscaIndice = buscarProdutos(produtos, total, codigo); /* Armazena o indice do produto encontrado com base no código */
        if(buscaIndice == -1){
            printf("Código/Produto '%s' não encontrado... \n", codigo);
        }
    /* Bloco para digitar/atulizar */
    printf("Atualizar produto do código '%s'...:  ", produtos[buscaIndice].nomeProduto);
    printf("Atulizar a quantidade em estoque: ");
        scanf("%d", &produtos[buscaIndice].quantidadeStock);
    getchar(); //Limpar o buffer

    printf("Digite o valor do produto");
        scanf("%f", &produtos[buscaIndice].valorProduto);
    getchar(); //Limpar o buffer

    printf("Produtos atualizado com sucesso... \n");

}

/* Função para listar todos os produtos */
void listaProdutos(idprodutos *produtos, int total){
    printf("\n--- Produtos em estoque ---\n");
    for(int i = 0; i <= total; i++){
        printf("Código do produto...: %s", produtos[i].id_CodProduto);
        printf("Nome do produto: %s\n", produtos[i].nomeProduto);
        printf("Quantidade em stock: %d", produtos[i].quantidadesStock);
        printf("Valor do produto..: %f", produtos[i].valorProduto);
        printf("\n----------------------\n");
    }

}

/* Função para adicionar produto */

int adicionarProduto(idprodutos *produtos, int total, int maxProdutos){
    /* Se for maior que maxProdutos não tera como alocar um novo produto  */
    if(total > maxProdutos){
        printf("Erro ao adicionar produtos...  ");
        return total;
    }
    printf("\n--- Adicionar produto ---\n");
    cadastroProdutos(produtos[total]); /* Chamada da função "cadastroProdutos" para adicionar dados */
    printf("Adicionado produtos com sucesso");

    return total +1;
}

/* Função para remover produtos */

int removerProduto(idprodutos *produtos, int total, const char *codigo){
    /* Se for maior que maxProdutos não tera como alocar um novo produto  */
    int buscaIndice = buscarProdutos(produtos, total, codigo); /* Armazena dados, para fazer a chamada do que for remover */
    /* -1 para fazer a busca do indice a esquerda  */
    if(buscaIndice == -1){
        printf("Erro ao remover produto cód '%s' do stock...  ");
        return total;
    }
    /* Remove produto com deslocamento a esquerda */
    for(int i = buscaIndice; i <= total -1; i++){
        produtos[i] = produtos[i + 1];//i e usado para iteração, também e usado + 1 para não iterar sobre aqueles alocado a esquerda
    }
    printf("Produto do cód '%s' removido com sucesso");
    return total +1; /* Incremento o total de produto e retorna */
}






    

