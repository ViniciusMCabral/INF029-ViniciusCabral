/* Faça um programa que verifique se um número é primo */
#include <stdio.h>
int main(){
int num, i, contador = 0;
  printf("Digite um número: \n");
  scanf("%d", &num);
  for(i = 0; i < num; i ++){
    if(num % 2 == 0){
      contador += 1;
    }
  }
  if(num == 1 || contador > 2){
    printf("Nao eh primo!\n");
  }
  else if(contador < 3 && num != 1){
    printf("Eh primo!\n");
  }
}