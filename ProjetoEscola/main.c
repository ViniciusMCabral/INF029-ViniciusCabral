#include <stdio.h>
#define TamAluno 3



int main(void){

    struct Aluno
    {
        int matricula;
        char sexo;
        int ativo;
    };

    struct Aluno listaAluno[TamAluno]; 
    int opcao;
    int contAluno = 0;
    int matricula;

    do{

    printf("Projeto Escola\n");
    printf("0 - Sair\n");
    printf("1 - Aluno\n");
    printf("2 - Professor\n");
    printf("3 - Disciplina\n");

    scanf("%d", &opcao);

    switch(opcao){

        case 0:

            printf("Saindo...\n");
            break;

        case 1:

            printf("Aluno\n");
            int opcaoAluno;

            do{

                printf("0 - Voltar\n");
                printf("1 - Cadastrar Aluno\n");
                printf("2 - Listar Aluno\n");
                printf("3 - Atualizar Aluno\n");
                printf("4 - Excluir Aluno\n");

                scanf("%d", &opcaoAluno);

                switch(opcaoAluno){

                    case 0:

                        printf("Voltando...\n");
                        break;

                    case 1:

                        printf("Cadastrando Aluno...\n");

                        if(contAluno == TamAluno){
                                printf("Lista de alunos cheia\n");

                        }

                        else{

                            printf("Digite a matricula\n");
                            scanf("%d", &matricula);

                            if(matricula < 0){
                                printf("Matricula invalida\n");
                            }

                            listaAluno[contAluno].matricula = matricula;
                            listaAluno[contAluno].ativo = 1;
                            contAluno++;

                            printf("Cadastro com sucesso\n");

                        }

                        break;

                    case 2:

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

                        break;

                    case 3:

                        printf("Atualizando Aluno...\n");
                        break;

                    case 4:

                        printf("Excluindo Aluno...\n");
                        printf("Digite a matricula\n");
                        scanf("%d", &matricula);
                        int achou = 0;
                        if(matricula < 0){
                            printf("Matricula Invalida\n");
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

                                    contAluno --;
                                    int achou = 1;
                                    break;
                                }
                            }
                            if(achou){
                                printf("Aluno excluido\n");
                            }
                            else{
                                printf("Matricula inexistente\n");

                            }
                        }
                        break;

                    default:

                        printf("Opção Inválida\n");
                        break;

                }

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

    return 0;
}