#include <stdio.h>
#define TamAluno 3
#define CAD_SUCESSO -1
#define MATRICULA_INVALIDA -2
#define LISTA_CHEIA -3
#define ATUALIZACAO_ALUNO_SUCESSO -4
#define MATRICULA_INEXISTENTE -5
#define EXCLUSAO_SUCESSO -6

typedef struct
{
int matricula;
char sexo;
int ativo;
char nome[50];
int cpf;
char dataNascimento[50];

}Aluno;

int menuPrincipal();
int menuAluno();
int cadastrarAluno(contAluno, listaAluno);
void listarAluno(contAluno, listaAluno);
int atualizarAluno(contAluno, listaAluno);
int excluirAluno(contAluno, listaAluno);

int main(void){

Aluno listaAluno[TamAluno]; 
int opcao;
int contAluno = 0;
int matricula;
char sexo;

do{

  opcao = menuPrincipal();


  switch(opcao){

  case 0:

  printf("Saindo...\n");
  break;
  
  case 1:

  printf("Aluno\n");
  int opcaoAluno;

  do{
  opcaoAluno = menuAluno();


  switch(opcaoAluno){

    case 0:

      printf("Voltando...\n");
      break;

    case 1:
      int retorno = cadastrarAluno(contAluno, listaAluno);
      if(retorno == LISTA_CHEIA)
          printf("Lista de alunos cheia\n");
      else if(retorno == MATRICULA_INVALIDA)
          printf("Matricula invalida\n");
      else{
          printf("Aluno cadastrado com sucesso\n");
          contAluno++;
      }
      break;

    case 2:
      listarAluno(contAluno, listaAluno);

      break;

    case 3:
       retorno = atualizarAluno(contAluno, listaAluno);
        if(retorno == MATRICULA_INVALIDA){
          printf("Matricula invalida\n");
        }
        else if(retorno == MATRICULA_INEXISTENTE){
          printf("Matricula inexistente\n");
        }
        else{
          printf("Aluno atualizado com sucesso\n");
        }

      break;

    case 4:
        retorno = excluirAluno(contAluno, listaAluno);
        if(retorno == MATRICULA_INVALIDA){
          printf("Matricula invalida\n");
        }
        else if(retorno == MATRICULA_INEXISTENTE){
          printf("Matricula inexistente\n");
        }
        else{
          printf("Aluno excluido com sucesso\n");
          contAluno--;
        }
    default:

          printf("Opção Inválida\n");
          break;

    }
    break;
}while(opcaoAluno != 0);

  break;
  case 2:

  printf("Professor\n");
  break;

  case 3:

  printf("Disciplina\n");
  break;

  default:

  printf("Opção inválida\n");
  break;

}

}while(opcao != 0);
}
//funções
int menuPrincipal(){
  int opcao;
  printf("Projeto Escola\n");
  printf("0 - Sair\n");
  printf("1 - Aluno\n");
  printf("2 - Professor\n");
  printf("3 - Disciplina\n");
  scanf("%d", &opcao);
  return opcao;
}
  int menuAluno(){
  int opcaoAluno;
  printf("0 - Voltar\n");
  printf("1 - Cadastrar Aluno\n");
  printf("2 - Listar Aluno\n");
  printf("3 - Atualizar Aluno\n");
  printf("4 - Excluir Aluno\n");
  scanf("%d", &opcaoAluno);
  return opcaoAluno;
}
int cadastrarAluno(int contAluno, Aluno listaAluno[]){
  printf("Cadastrando Aluno...\n");

  if(contAluno == TamAluno){
  return LISTA_CHEIA;
}  

  else{
  int matricula;
  printf("Digite a matricula\n");  
  scanf("%d", &matricula);                       

  if(matricula < 0){
  return MATRICULA_INVALIDA;
}

  listaAluno[contAluno].matricula = matricula;
  listaAluno[contAluno].ativo = 1;
  contAluno++;
  return CAD_SUCESSO;
}
void listarAluno(int contAluno, Aluno listaAluno[]){
  printf("Listando Aluno...\n");

  if(contAluno == 0){

  printf("Lista vazia\n");
  }

  else{

    for(int i = 0; i < contAluno; i++){
      if(listaAluno[i].ativo = 1){
        printf("Matricula: %d\n", listaAluno[i].matricula);
      }
    } 
  }
}
int atualizarAluno(int contAluno, Aluno listaAluno[]){
  printf("Atualizando Aluno...\n");
  printf("Digite a matricula\n");
  int matricula;
  scanf("%d", &matricula);
  int achou = 0;
  if(matricula < 0){
    return MATRICULA_INVALIDA;
  }
  for(int i = 0; i < contAluno; i++){
    if(listaAluno[i].matricula == matricula && listaAluno[i].ativo){
      printf("Digite a nova matricula\n");
      int novaMatricula;
      scanf("%d", &novaMatricula);
      listaAluno[i].matricula = novaMatricula;
      achou = 1;
      break;
    }
  }
  if(achou)
    return ATUALIZACAO_ALUNO_SUCESSO;
  else   
    return MATRICULA_INEXISTENTE;
}
}
int excluirAluno(int contAluno, Aluno listaAluno[]){
  printf("Excluindo Aluno...\n");
        int matricula;
        printf("Digite a matricula\n");
        scanf("%d", &matricula);
        int achou = 0;
        if(matricula < 0){
          return MATRICULA_INVALIDA;
        }
        else{
            for(int i = 0; i < contAluno - 1; i++){ 
                if(matricula == listaAluno[i].matricula){
                    //exclusao logica
                    listaAluno[i].ativo = -1;
                    for(int j = i; j < contAluno; j++){ //shift
                        listaAluno[j].matricula = listaAluno[j+1].matricula;
                        listaAluno[j].sexo = listaAluno[j+1].sexo;
                        listaAluno[j].sexo = listaAluno[j+1].sexo;
                    }

                    int achou = 1;
                    break;
                }
            }

            if(achou)
              return EXCLUSAO_SUCESSO;
            else   
              return MATRICULA_INEXISTENTE;
        }
}