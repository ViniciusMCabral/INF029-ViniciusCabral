/* Faça um programa que leia a idade de uma pessoa e informe se ela é de maior ou de menor. O programa deve repetir essa ação até que uma idade negativa seja informada */
#include <stdio.h>
int main(){
int idade;
  while(idade >= 0){
    printf("Digite a idade da pessoa: \n");
    scanf("%d", &idade);
    if(idade < 0){
        break;
    }
    else if(idade >= 18){
        printf("A pessoa é maior de idade.\n");
    }
    else{
        printf("A pessoa é menor de idade.\n");
    }
}
}