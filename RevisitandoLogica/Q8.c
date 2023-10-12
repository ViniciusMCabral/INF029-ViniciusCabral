/* Faça um programa que calcula o fatorial de um número */
#include <stdio.h>
int main(){
int numero, fatorial = 1, i;
  printf("Digite o numero: \n");
  scanf("%d", &numero);
  for(i = 1; i <= numero; i ++){
    fatorial *= i;
  }
  printf("O fatorial de %d eh: %d\n", numero, fatorial);
}