#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* Função para buscar produtos pelo idproduto */

/* Arvore binária */
typedef struct busca{
    idproduto produto;
    struct busca *esquerda;
    struct busca *direita;
} busca;

busca* buscaProduto(busca *raiz, const char *codigo){
    while(raiz != NULL){
        int cmp = strcmp(codigo, raiz->produto.id_codProduto);
        if(cmp == 0){
            printf("Produto encontrado\n");
        return raiz;
        }
        else if(cmp < 0){
            raiz = raiz->esquerda;
        }
        else{
            raiz = raiz->direita;
        }
    }
    return NULL;
}

/* Funçaõ para atulizar produtos */

void atulizacaoProduto(busca *raiz, const char *codigo){
    busca *produtoNode = buscaProduto(raiz, codigo); /* Retorna o ponteiro para nó ou NULL */
    /* If para verificar se o valor for = NULL, não consiguira encontrar */
    if(produtoNode == NULL){
    printf("Produto do código '%s', não foi encontrado\n", codigo);  
    return;       
    }

    /* Bloco para digitar/atulizar */
    printf("Atualizar produto do código '%s'...:  ", produtoNode->produto.nomeProduto);
    printf("Atulizar a quantidade em estoque: ");
        scanf("%d", &produtoNode->produto.quantidadeStock);
    getchar(); //Limpar o buffer

    printf("Digite o valor do produto");
        scanf("%f", &produtoNode->produto.valorProduto);
    getchar(); //Limpar o buffer

    printf("Produtos atualizado com sucesso... \n");

}

/* Função para listar todos os produtos */
void listaProdutos(busca *raiz){
    if(raiz != NULL){
        listaProdutos(raiz->esquerda);
        printf("Código: %s |Nome: %s|Quantidade: %d|Preço: %.2f\n", 
        raiz->produto.id_codProduto, raiz->produto.nomeProduto,
        raiz->produto.quantidadeStock, raiz->produto.valorProduto);
        listaProdutos(raiz->direita);

    }
}

/* Função para adicionar produto */

busca* inserirProduto(busca *raiz, idproduto novoProduto){
    if(raiz == NULL){
    /* Cria um novo nó na arvore se chegado */
    busca *novoNo = (busca*)malloc(sizeof(busca));
    if(novoNo == NULL){
        fprintf(stderr,"Erro ao alocar memória para o novo produto\n");
        return raiz;
    }
    novoNo->produto = novoProduto;
    novoNo->esquerda = novoNo->direita = NULL;
    return novoNo;
    }
    /* Decide onde o produto vai ser guardado, levando em consideração a lógica de condição */
    if(strcmp(novoProduto.id_codProduto, raiz->produto.id_codProduto) < 0){
        raiz->esquerda = inserirProduto(raiz->esquerda, novoProduto);
    }
    else{
        raiz->direita = inserirProduto(raiz->direita, novoProduto);
    }
    return raiz;
}

/* Função para remover produtos */

busca* removerProduto(busca *raiz, const char *codigo){
   if (raiz == NULL) return NULL;
   
   if(strcmp(codigo, raiz->produto.cod_idProduto) < 0){
    raiz->esquerda = removerProduto(raiz->esquerda, codigo);
   }
   else if(strcmp(codigo, raiz->produto.id_codProduto) > 0){
    raiz->direita = removerProduto(raiz->direita, codigo);
   }
   else{
    /* Caso não encontre nenhum valor */
    if(raiz->esquerda == NULL){
        busca *temp = raiz->direita;
        free(raiz);
        return temp;
    }
    else if(raiz->direita == NULL){
        busca *temp = raiz->esquerda;
        free(raiz);
        return temp;
    }
    /* buscar dados na sub árvore */
    busca *temp = raiz->direita;
    while(temp && temp->esquerda != NULL){
        temp = temp->esquerda;
    }
    /* Substituir produtos */
    raiz->produto = temp->produto;
    /* Remover o in-order */
    raiz->direita = removerProduto(raiz->produto, temp->produto.id_codProduto);
   }
   return raiz;
}






    

