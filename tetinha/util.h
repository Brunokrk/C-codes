#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct{
    int numero_da_conta;
    char nome_do_clinte[10];
    float saldo_corrente;
    int tipo_cartao;//(0 –não possui; 1:cartão TIPO1; 2: cartão TIPO2)
    float limite_emprestimo;
    float saldo_cartao;
    float saldo_ivestimento;
}conta;
void ler_contas(conta*);
void modif_contas(conta*);
void descarregar(conta*);
void carregar(conta*);
int achar_conta(conta*);
void registro(conta, char, float);
char menu();