#include <stdio.h>
#include <stdlib.h>

unsigned int potencia (unsigned int b, unsigned int e){
    unsigned int r;
    if(e==0)
        return 1;
    
    r= potencia(b, e/2);
    
    if(e%2==0){
        printf("e-> %d\n", e);
        printf("r-> %d\n", r);
        return r*r;

    }
    else{
        printf("e-> %d\n", e);
        printf("r-> %d\n", r);
        return r*r*b;
    }    
}

int main(){
    
    printf("%d", potencia(2,10));
    return 0;
}