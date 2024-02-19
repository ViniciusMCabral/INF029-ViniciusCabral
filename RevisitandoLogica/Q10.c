/* Faça um programa que leia os dados de nome, idade, sexo e cpf de 5 pessoas. Ao final imprima tudo. Utilize vetor e struct. */
#include <stdio.h>
int main(){
struct dados_aluno
  {
    char nome[40];
    int idade;
    char sexo;
    char cpf[15];
  };
  struct dados_aluno aluno[5];
  for(int i = 0; i < 5; i ++){
    printf("Digite o nome do aluno %d: ", i + 1);
    scanf("%s", aluno[i].nome);
    printf("Digite a idade do aluno %d: ", i + 1);
    scanf("%d", &aluno[i].idade);
    printf("Digite o sexo do aluno %d: ", i + 1);
    scanf(" %c", &aluno[i].sexo);
    printf("Digite o cpf do aluno %d: ", i + 1);
    scanf("%s", aluno[i].cpf);
  }

  for(int i = 0; i < 5; i ++){
    printf("\n\nNome do aluno %d: %s\n", i + 1, aluno[i].nome);
    printf("Idade do aluno %d: %d\n", i + 1, aluno[i].idade);
    printf("Sexo do aluno %d: %c\n", i + 1, aluno[i].sexo);
    printf("Cpf do aluno %d: %s\n", i + 1, aluno[i].cpf);
  }

}