/* Faça um programa que leia a idade de uma pessoa e informe se ela é de maior ou menor */
#include <stdio.h>
int main(){
  int idade;
  printf("Digite a idade da pessoa: \n");
  scanf("%d", &idade);
  if(idade >= 18){
    printf("A pessoa é maior de idade.\n");
  }
  else{
    printf("A pessoa é menor de idade.\n");
  }
}