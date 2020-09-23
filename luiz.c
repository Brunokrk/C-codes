#include <stdio.h>
#include <stdlib.h>
int main(){
    int x, op, resultado;

    printf("1: x+2\n");
    printf("2: x+2 \n");
    printf("3: x+2\n");
    printf("4: x+2\n");

    while(1){
        printf("Escolha a equacao \n");
        scanf("%d", &op);
        if((op>1)&&(op<4)){
            break;
        }
        
        printf("Escolha x:");
        scanf("%d", &x);

        if (op == 1){
            resultado = x+2;
            printf("Resultado: %d", resultado );
        }
        if (op == 2){
            resultado = x+2;
            printf("Resultado: %d", resultado );
        }        
        if (op == 3){
            resultado = x+2;
            printf("Resultado: %d", resultado );
        }
        if (op == 4){
            resultado = x+2;
            printf("Resultado: %d\n", resultado );
        }
    }
    

}