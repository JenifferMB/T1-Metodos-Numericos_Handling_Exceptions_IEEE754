#include <stdio.h>
#include <stdlib.h>
#include <fenv.h>
#include <string.h>
#include <math.h>


#pragma STDC FENV_ACCESS ON 

void print_bits(unsigned int num, int bits);
void show_fe_exceptions(void);

void print_bits(unsigned int num, int bits) {
    int i;
    for (i = bits - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

void show_fe_exceptions(void)
{
    int exceptionDivZero = fetestexcept(FE_DIVBYZERO);
    int exceptionIne = fetestexcept(FE_INEXACT);
    int exceptionInv = fetestexcept(FE_INVALID);
    int exceptionOvr = fetestexcept(FE_OVERFLOW);
    int exceptionUnd = fetestexcept(FE_UNDERFLOW);

    if(FE_DIVBYZERO == exceptionDivZero){ printf("\nFE_DIVBYZERO: %d", exceptionDivZero);}
    else{printf("\nFE_DIVBYZERO: %d", 0);}
    if(FE_INEXACT == exceptionIne){ printf("\nFE_INEXACT: %d", exceptionIne);}
    else{printf("\nFE_INEXACT: %d", 0);}
    if(FE_INVALID == exceptionInv){ printf("\nFE_INVALID: %d", exceptionInv);}
    else{printf("\nFE_INVALID: %d", 0);}
    if(FE_OVERFLOW == exceptionOvr){ printf("\nFE_OVERFLOW: %d", exceptionOvr);}
    else{printf("\nFE_OVERFLOW: %d", 0);}
    if(FE_UNDERFLOW == exceptionUnd){ printf("\nFE_UNDERFLOW: %d", exceptionUnd);}
    else{printf("\nFE_UNDERFLOW: %d", 0);}
    
    feclearexcept(FE_ALL_EXCEPT);
}

int main(int argc, char *argv[ ]) {
    float resultado, valorA, valorB;
    char operacao;

    if (argc != 4) {
        printf("Argumentos insuficientes");
        return 1;
    }

    operacao = argv[2][0];
    valorA = atof(argv[1]);
    valorB = atof(argv[3]);

    switch (operacao) {
        case '+':
            resultado = valorA + valorB;
            break;
        case '-':
            resultado = valorA - valorB;
            break;
        case 'x':
            resultado = valorA * valorB;
            break;
        case '/':
            resultado = valorA / valorB;
            break;
        default:
            printf("Operacao invalida, utilize apenas '+', '-', 'x' e '/'. \n");
            return 3;
    } 

    printf("Recebi: %f %c %f, Resultado deu = %f \n", valorA, operacao, valorB, resultado);
    printf("Valor 1 em binario: ");
    print_bits(*(unsigned int*)&valorA, sizeof(valorA)*8);
    printf(" = %f", valorA);
    printf("\nValor 2 em binario: ");
    print_bits(*(unsigned int*)&valorB, sizeof(valorB)*8);
    printf(" = %f", valorB);
    printf("\nResultado em binario = ");
    print_bits(*(unsigned int*)&resultado, sizeof(resultado)*8);
    show_fe_exceptions();
    
    return 0;
}
