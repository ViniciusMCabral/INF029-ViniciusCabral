/* Faça um programa que leia 10 números do usuário e informe quais deles são primos. Além disso, mostre a soma de todos os números primos existentes. */
#include <stdio.h>
int main(){
int array[10], somaprimo = 0, primos[10];
int i, j;
  for(i = 0; i < 10; i ++){
    primos[i] = 1;
  }
  printf("Digite os valores do array: \n");
  for(i = 0; i < 10; i ++){
    scanf("%d", &array[i]);
  }
  for(i = 0; i < 10; i ++){
    for(j = 2; j < array[i]; j ++){
      if(array[i] % j == 0){
        primos[i] = 0;
        break;
      }
    }
  }
  printf("Vetor com os primos: \n");
  for(i = 0; i < 10; i ++){
      if(primos[i] == 1){
        printf("%d ", array[i]);
        somaprimo += array[i];
  }
}
printf("\nSoma dos primos: %d\n", somaprimo);
}