/* Faça um programa que leia a idade de duas pessoas e imprima a soma das idades */
#include <stdio.h>
int main(){
  int idade1, idade2, somaidades;
  printf("Digite as duas idades: \n");
  scanf("%d%d", &idade1, &idade2);
  somaidades = idade1 + idade2;
  printf("A soma das duas idades eh: %d\n", somaidades);
}