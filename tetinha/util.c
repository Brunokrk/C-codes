#include"util.h"
#define num_contas 2

void ler_contas(conta *a){
    int i;
    for(i=0; i<num_contas; i++){
        printf("\n-----Conta %d: -----\n", i);
        printf("Numero da conta: %d\n", a[i].numero_da_conta);
        printf("Nome do cliente: %s\n", a[i].nome_do_clinte);
        printf("Saldo da conta corrente: %f\n", a[i].saldo_corrente); 
        printf("Tipo do cartao: %d\n", a[i].tipo_cartao);
        printf("Limite de emprestimo: %f\n", a[i].limite_emprestimo);
        printf("Saldo do cartao: %f\n", a[i].saldo_cartao);
        printf("Saldo invetimento: %f\n", a[i].saldo_ivestimento);
    } 

}
void modif_contas(conta *a){
    int i;
    for(i=0; i<num_contas; i++){
        printf("\n-----Conta %d: -----\n", i);
        printf("Numero da conta: ");
        scanf("%d", &a[i].numero_da_conta);
        printf("Nome do cliente: ");
        scanf("%s", a[i].nome_do_clinte);fflush(stdin);
        printf("Saldo da conta corrente: ");
        scanf("%f", &a[i].saldo_corrente);
        printf("Tipo do cartao(0:nao possui, 1:cartao TIPO1, 2:cartao TIPO2): ");
        scanf("%d", &a[i].tipo_cartao);
        printf("Limite de emprestimo: ");
        scanf("%f", &a[i].limite_emprestimo);
        printf("Saldo do cartao: ");
        scanf("%f", &a[i].saldo_cartao);
        printf("Saldo invetimento: ");
        scanf("%f", &a[i].saldo_ivestimento);
    }
}
void descarregar(conta *a){
    FILE *file = fopen("contas.bin", "rb");
    fread(a, sizeof(conta), num_contas, file);
    fclose(file);
}
void carregar(conta *a){
    int i;
    FILE *file = fopen("contas.bin", "wb");
    for(i=0; i<num_contas; i++)
        fwrite(&a[i], sizeof(conta), 1, file);
    fclose(file);
}
int achar_conta(conta *a){
    int i;
    int nconta;
    while(1){
        printf("Numero da conta: ");
        scanf("%d", &nconta);
        for(i=0; i<num_contas; i++){
            if(a[i].numero_da_conta == nconta)
                return i;                
        }
        printf("-Numero de conta invalido-\n");       
    }
}
void registro(conta a, char tipo, float valor){
    FILE *f = fopen("movimento.txt", "a");
    switch (tipo){
        case 's':        
            fprintf(f,"Conta: %d ---- Sacou: %f\n", a.numero_da_conta, valor);
        break;
        case 'd':
            fprintf(f,"Conta: %d ---- Depositou: %f\n", a.numero_da_conta, valor);
        break;
        case 'c':
            fprintf(f,"Conta: %d ---- Usou credito: %f\n", a.numero_da_conta, valor);
        break;
        case 'i':
            fprintf(f,"Conta: %d ---- Investiu: %f\n", a.numero_da_conta, valor);
        break;
        case 'e':
            fprintf(f,"Conta: %d ---- Emprestou: %f\n", a.numero_da_conta, valor);
        break;
    }
    fclose(f);
}
char menu(){
    char c;
    char *opicoes = "012sSdDcCiIeE";
    int i;
    printf("-------- Menu --------\n");
    printf("1- Modificar todas as contas\n");
    printf("2- listar todas as contas\n");
    printf("s- Realizar saque\n");
    printf("d- Fazer um deposito\n");
    printf("c- credito via cartao\n");
    printf("i- Realizar um investimento\n");
    printf("e- pedir emprestimo\n");
    printf("Oque voce deseja fzr:\n");
    while(1){
        scanf("%c", &c);fflush(stdin);
        for (i=0; i<13; i++){
            if(opicoes[i] == c)
                return tolower(c);
        }
        printf("Opicao invalida\n");
    }
}