#include<stdio.h>


typedef struct _FRACAO {
    
    int numerador, denominador;
}FRACAO;

void soma(FRACAO f1, FRACAO f2);
void substracao(FRACAO f1, FRACAO f2);
void multiplicacao(FRACAO f1, FRACAO f2);
void divisao(FRACAO f1, FRACAO f2);

int main(void){

    FRACAO f1, f2;

    printf("Insira o valor do numerador da fração 1: \n");
    scanf("%d", &f1.numerador);

    printf("Insira o valor do denominador da franção 1: \n");
    scanf("%d", &f1.denominador);

    if(f1.denominador == 0){
        printf("Aviso! Não pode inserir 0 como denominador. \n");
        return 0;
    }

    printf("Insira o valor do numerador da fração 2: \n");
    scanf("%d", &f2.numerador);

    printf("Insira o valor do denominador da franção 2: \n");
    scanf("%d", &f2.denominador);

    if(f2.denominador == 0){
        printf("Aviso! Não pode inserir 0 como denominador. \n");
        return 0;
    }

    soma(f1, f2);
    substracao(f1, f2);
    multiplicacao(f1, f2);
    divisao(f1, f2);

    return 0;
}

void soma(FRACAO f1, FRACAO f2){

    FRACAO f3;

    if (f1.denominador != f2.denominador){

        f3.denominador = f1.denominador * f2.denominador;
        f3.numerador = (f1.numerador * f2.denominador) + (f2.numerador * f1.denominador);

    }else{

        f3.denominador = f1.denominador;
        f3.numerador = f1.numerador + f2.numerador;
    }

    printf("\nA soma das frações é: %d / %d\n", f3.numerador, f3.denominador);
}

void  substracao(FRACAO f1, FRACAO f2){

    FRACAO f3;

    if (f1.denominador != f2.denominador){

        f3.denominador = f1.denominador * f2.denominador;
        f3.numerador = (f1.numerador * f2.denominador) - (f2.numerador * f1.denominador);

    }else{

        f3.denominador = f1.denominador;
        f3.numerador = f1.numerador - f2.numerador;
    }

    printf("\nA subtração das frações é: %d / %d\n", f3.numerador, f3.denominador);

}

void multiplicacao(FRACAO f1, FRACAO f2){

    FRACAO f3;

    f3.denominador = f1.denominador * f2.denominador;
    f3.numerador = f1.numerador * f2.numerador;

    printf("\nO produto das frações é: %d / %d\n", f3.numerador, f3.denominador);

}

void divisao(FRACAO f1, FRACAO f2){

    FRACAO f3;

    f3.numerador = f1.numerador * f2.denominador;
    f3.denominador = f1.denominador * f2.numerador;

    printf("\nA divisão das frações é: %d / %d\n", f3.numerador, f3.denominador);

}