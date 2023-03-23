#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct reg celula;

//Criando a ESTRUTURA de uma célula
struct reg {
   int conteudo; 
   celula *prox;
};

// inserção no início: retorna a lista atualizada 
celula * insere (celula* l, int i) {
    celula* novo = (celula*) malloc(sizeof(celula));
    novo->conteudo = i;
    novo->prox = l;
    return novo;
}

//Contador nº de células
// 3 5 0
int contador(celula * le) {
    if(le != NULL)
    return 1 + contador(le->prox);
}

// troca 3 4 (11 9 4 5 88 9 3 1 4 3)   >>>   (11 9 4 5 88 9 4 1 4 4)
celula * troca(int sai, int chega, celula * le) {
    if(le == NULL)
    return NULL;
    
    else if(sai != le->conteudo)
    return insere(troca(sai, chega, le->prox), le->conteudo);

    else
    return insere(troca(sai, chega, le->prox), chega);
}

// remover (1 3 6 7 9 10 20 31 57 3)   >>>   (1 6 7 9 10 20 31 57)
celula * remover(int elem, celula * le) {
    if(le == NULL)
    return NULL;

    else if(elem == le->conteudo)
    return remover(elem, le->prox);

    else
    return insere(remover(elem, le->prox), le->conteudo);
}

// seguir (4 3 5 6 8 2 4 20)   >>>   (3 20)
celula * seguir(celula * le, int elem) {
    if (le == NULL)
    return NULL;

    else if (le->conteudo == elem && le->prox != NULL)
    return insere(seguir(le->prox->prox, elem), le->prox->conteudo);

    else if(le->prox == NULL && le->conteudo != elem)
    return NULL;

    else if(le->prox == NULL && le->conteudo == elem)
    return NULL;

    else
    return seguir(le->prox, elem);
}

// f - dobra os pares - soma 1 aos ímpares - soma com os 0
// (2 3 5 7 0 1 2 8 0)   >>>   (4 4 6 8 2 16)
celula * f(celula * le) {
    if(le == NULL)
    return NULL;

    else if(le->conteudo % 2 == 1)
    return insere(f(le->prox), le->conteudo + 1);

    else if(le->conteudo == 0)
    return f(le->prox);

    else
    return insere(f(le->prox), le->conteudo * 2);
}

// remover_primeiro (4 3 2 8 9 3 11 4 8)   >>>   (4 2 8 9 3 11 4 8)
celula * remover_primeiro(int elem, celula * le) {
    if(le == NULL) 
    return NULL;

    else if(le->conteudo == elem)
    return remover_primeiro(INT_MAX, le->prox);

    else
    return insere(remover_primeiro(elem, le->prox), le->conteudo);
}

// remover_pares (4 3 8 10 3 5 3)   >>>   (4 8 10)
celula * remover_pares(celula * le) {
    if(le == NULL)
    return NULL;

    else if(le->conteudo % 2 == 1)
    return remover_pares(le->prox);

    else
    return insere(remover_pares(le->prox), le->conteudo);
}

//mantem posições pares (4 3 8 10 3 5 3)   >>>   (3 10 5)
celula * remover_posi_impares(celula * le) {
    if(le == NULL)
    return NULL;

    else if(le->prox == NULL)
    return le;

    else 
    return insere(remover_posi_impares(le->prox->prox), le->prox->conteudo);
}

// mantem posições ímpares
// impares (2 10 5 4 0 1)   >>>  (2 5 0)
// impares (1 2 3)    >>>  (1 3)
celula * impares(celula * le) {
    if(le == NULL)
    return NULL;

    else if(le->prox == NULL)
    return insere(NULL, le->conteudo);

    else
    return insere(impares(le->prox->prox), le->conteudo);
}

// alterna posicoes de 2 em 2
// impares (2 10 5 4 0 1)   >>>  (10 2 4 5 1 0)
// impares (1 2 3)    >>>  (2 1 3)
celula * alternar(celula * le) { //le == lista encadeada
    if(le == NULL)
    return NULL;

    else if(le->prox == NULL)
    return insere(NULL, le->conteudo);

    else
    return insere(insere(alternar(le->prox->prox), le->conteudo), le->prox->conteudo);
}

// gaguinho (7 4 3 0)    >>>>    (7 7 4 4 3 3 0 0)
celula * gaguinho(celula * le) {
    if(le == NULL)
    return NULL;

    else if(le->prox == NULL)
    return insere(insere(NULL, le->conteudo), le->conteudo);

    else
    return insere(insere(gaguinho(le->prox), le->conteudo), le->conteudo);
}

// combina duas listas, alternando os valores
// (1 8 100) (9 3 2)    >>>    (1 9 8 3 100 2)
// (4 10) (1 2 0 7)    >>>    (4 1 10 2 0 7)
celula * ziper(celula * le1, celula * le2) {
    return NULL;
}

// concatena duas listas recursivamente
// (1 2 3)  (4 5)   >>>  (1 2 3 4 5)
celula * append(celula * le1, celula * le2) {
    if(le1 == NULL && le2 == NULL)
    return NULL;

    else if(le2 == NULL)
    return le1;

    else if(le1->prox == NULL)
    return append(le2, NULL);

    else
    return insere(append(le1, le2), le1->conteudo);
}

// (1 34 18) → (24 25 28)
// (16 26 36) → (6 7 16 17 46)
// (13 14 15 8 7 20) → (3 4 4 5 25 10 11)
celula * fc(celula * le) {
    if(le == NULL) 
    return NULL;
    
    else if(le->conteudo <= 10)
    return fc(le->prox);

    else if(le->conteudo > 10 && le->conteudo % 3 == 0)
    return insere(fc(le->prox), 10 + le->conteudo);

    else
    return insere(insere(fc(le->prox), -9 + le->conteudo), -10 + le->conteudo);
}

// (1 1 1 1 1 2 2 2 5 5 5 7 7 7 7 7 7 7)   >>>   (1 2 5 7)
//Mandar valor diferente de qualquer elemento da lista ao chamar a função empacotar na main
celula * empacotar (celula * le, int anterior) {
    if(le == NULL)
    return NULL;

    else if(le->conteudo == anterior)
    return empacotar(le->prox, le->conteudo);

    else
    return insere(empacotar(le->prox, le->conteudo), le->conteudo);
}

// (1 3 8 9 50)   >>>   (2 6 16 18 100)
celula * dobrar(celula * le) {
    if(le == NULL)
    return NULL;

    else if(le->prox == NULL)
    return insere(NULL, le->conteudo);

    else
    return insere(dobrar(le->prox), 2 * le->conteudo);
}

// (4 5 11 13 11 13)   >>>   (11 -1) 
// 0.1725
celula * fb(celula * le) {
    if(le == NULL)
    return NULL;

    else if((le->conteudo + 1 == le->prox->conteudo) && le->prox->prox != NULL)
    return insere(fb(le->prox->prox), le->conteudo + le->prox->conteudo);

    else if((le->conteudo + 1 == le->prox->conteudo) && le->prox->prox == NULL)
    return insere(insere(NULL, -1), le->conteudo + le->prox->conteudo);

    else if((le->conteudo + 1 != le->prox->conteudo) && le->prox->prox == NULL)
    return insere(insere(NULL, -1), le->conteudo + le->prox->conteudo);

    else 
    return fb(le->prox->prox);
}

//função básica que imprime a lista encadeada construída
void imprime(celula * le) {
    if(le != NULL) {
        printf("O conteúdo é: %d\n", le->conteudo);
        imprime(le->prox);
    }
}

int main () {
    
    celula * l1; //declara uma lista não inicializada
    // (5 6 11 13 12 13)   >>>   (11 25)
    l1 = insere(l1, 13);
    l1 = insere(l1, 11);
    l1 = insere(l1, 13);
    l1 = insere(l1, 11);
    l1 = insere(l1, 5);
    l1 = insere(l1, 4);
    

    printf("/----------------------/\n");

    l1 = fb(l1);
    imprime(l1);



}



