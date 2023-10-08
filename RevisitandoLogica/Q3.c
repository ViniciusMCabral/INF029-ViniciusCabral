/* Faça um programa que leia dois valores informados pelo usuário e inverta os valores nas variáveis lidas */
#include <stdio.h>
int main(){
  int a, b, aux;
  printf("Digite os valores: \n");
  scanf("%d%d", &a, &b);
  printf("Valores: %d %d\n", a, b);
  aux = a;
  a = b;
  b = aux;
  printf("Valores permutados: %d %d\n", a, b);
}