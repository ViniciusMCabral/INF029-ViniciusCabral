/* Faça um programa que leia dois valores informados pelo usuário e inverta os valores nas variáveis lidas sem utilizar variável auxiliar */
#include <stdio.h>
int main(){
  int a, b;
  printf("Digite o valor A e de B: \n");
  scanf("%d%d", &a, &b);
  a = a + b;
  b = a - b;
  a = a - b;
  printf("O valor de A é: %d\nO valor de B é: %d", a, b);
}