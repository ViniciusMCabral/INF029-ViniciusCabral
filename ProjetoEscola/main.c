#include <stdio.h>
#include <string.h>
#define TamAluno 3
#define TamProf 3
#define CAD_SUCESSO -1
#define MATRICULA_INVALIDA -2
#define LISTA_CHEIA -3
#define ATUALIZACAO_SUCESSO -4
#define MATRICULA_INEXISTENTE -5
#define EXCLUSAO_SUCESSO -6

typedef struct data{
    int dia;
    int mes;
    int ano;
} Data;
typedef struct aluno {
    int matricula;
    char sexo;
    int ativo;
    char nome[50];
    char cpf[20];
    Data dataNascimento;
} Aluno;
typedef struct pro {
    int matricula;
    char sexo;
    int ativo;
    char nome[50];
    char cpf[20];
    Data dataNascimento;
} Professor;

int menuPrincipal();
int menuAluno();
int cadastrarAluno(int contAluno, Aluno listaAluno[]);
void listarAluno(int contAluno, Aluno listaAluno[]);
int atualizarAluno(int contAluno, Aluno listaAluno[]);
int excluirAluno(int contAluno, Aluno listaAluno[]);
int menuProf();
int cadastrarProf(int contProf, Professor listaProf[]);
void listarProf(int contProf, Professor listaProf[]);
int atualizarProf(int contProf, Professor listaProf[]);
int excluirProf(int contProf, Professor listaProf[]);

int main(void){

    Aluno listaAluno[TamAluno];
    Professor listaProf[TamProf];
    int opcao;
    int contAluno = 0;
    int contProf = 0;
    int matricula;
    char sexo;
    char nome[50];
    char cpf[20];

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
                            else if(retorno == EXCLUSAO_SUCESSO){
                                printf("Aluno excluido com sucesso\n");
                                contAluno--;
                            }
                            else{
                                printf("Matricula Inexistente\n");
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
                int opcaoProf;

                do{
                    opcaoProf = menuProf();


                    switch(opcaoProf){

                        case 0:

                            printf("Voltando...\n");
                            break;

                        case 1:
                            int retorno = cadastrarProf(contProf, listaProf);
                            if(retorno == LISTA_CHEIA)
                                printf("Lista de professores cheia\n");
                            else if(retorno == MATRICULA_INVALIDA)
                                printf("Matricula invalida\n");
                            else{
                                printf("Professor cadastrado com sucesso\n");
                                contProf++;
                            }
                            break;

                        case 2:
                            listarProf(contProf, listaProf);

                            break;

                        case 3:
                            retorno = atualizarProf(contProf, listaProf);
                            if(retorno == MATRICULA_INVALIDA){
                                printf("Matricula invalida\n");
                            }
                            else if(retorno == MATRICULA_INEXISTENTE){
                                printf("Matricula inexistente\n");
                            }
                            else{
                                printf("Professor atualizado com sucesso\n");
                            }

                            break;

                        case 4:
                            retorno = excluirProf(contProf, listaProf);
                            if(retorno == MATRICULA_INVALIDA){
                                printf("Matricula invalida\n");
                            }
                            else if(retorno == EXCLUSAO_SUCESSO){
                                printf("Professor excluido com sucesso\n");
                                contProf--;
                            }
                            else{
                                printf("Matricula Inexistente\n");
                            }
                            break;
                        default:

                            printf("Opção Inválida\n");
                            break;

                        }

                    }while(opcaoProf != 0);
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
//ALUNO
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
        char nome[50];
        char sexo;
        char cpf[20];
        printf("Digite a matricula:\n");  
        scanf("%d", &matricula); 
        printf("Digite o nome:\n");
        scanf("%s", &nome);
        printf("Digite o sexo(M/F):\n");
        scanf(" %c", &sexo);
        printf("Digite o CPF:\n");
        scanf("%s", &cpf);

        printf("Digite a data de nacimento:\n");
        printf("Dia:\n");
        scanf("%d", &listaAluno[contAluno].dataNascimento.dia);

        printf("Mes:\n");
        scanf("%d", &listaAluno[contAluno].dataNascimento.mes);

        printf("Ano:\n");
        scanf("%d", &listaAluno[contAluno].dataNascimento.ano);


    if(matricula < 0){
        return MATRICULA_INVALIDA;
    }

        listaAluno[contAluno].matricula = matricula;
        listaAluno[contAluno].sexo = sexo;
        listaAluno[contAluno].ativo = 1;
        strcpy(listaAluno[contAluno].nome, nome);
        strcpy(listaAluno[contAluno].cpf, cpf);
        contAluno++;
        return CAD_SUCESSO;
    }
}
void listarAluno(int contAluno, Aluno listaAluno[]){
    printf("Listando Aluno...\n\n");

    if(contAluno == 0){
    printf("Lista vazia\n");
    }
    else{
        for(int i = 0; i < contAluno; i++){
            if(listaAluno[i].ativo == 1){
                printf("Aluno %d:\n", i+1);
                printf("Matricula: %d\n", listaAluno[i].matricula);
                printf("Nome: %s\n", listaAluno[i].nome);
                printf("Sexo: %c\n", listaAluno[i].sexo);
                printf("CPF: %s\n", listaAluno[i].cpf);
                printf("Data de nascimento: %d/%d/%d\n\n", listaAluno[i].dataNascimento.dia, listaAluno[i].dataNascimento.mes,                                 listaAluno[i].dataNascimento.ano);

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
            printf("Digite a nova matricula:\n");
            int novaMatricula;
            scanf("%d", &novaMatricula);
            printf("Digite o novo nome:\n");
            char novoNome[50];
            scanf("%s", &novoNome);
            printf("Digite o novo CPF:\n");
            char novoCpf[20];
            scanf("%s", &novoCpf);
            printf("Digite o novo sexo:\n");
            char novoSexo;
            scanf(" %c", &novoSexo);
            printf("Digite a nova data de nascimento:\n");
            printf("Dia:\n");
            scanf("%d", &listaAluno[i].dataNascimento.dia);
            printf("Mes:\n");
            scanf("%d", &listaAluno[i].dataNascimento.mes);
            printf("Ano:\n");
            scanf("%d", &listaAluno[i].dataNascimento.ano);
            listaAluno[i].matricula = novaMatricula;
            listaAluno[i].sexo = novoSexo;
            strcpy(listaAluno[i].nome, novoNome);
            strcpy(listaAluno[i].cpf, novoCpf);
            achou = 1;
            break;
        }
    }
    if(achou)
        return ATUALIZACAO_SUCESSO;
    else   
        return MATRICULA_INEXISTENTE;
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
        for(int i = 0; i <= contAluno - 1; i++){ 
            if(matricula == listaAluno[i].matricula){
                //exclusao logica
                listaAluno[i].ativo = -1;
                for(int j = i; j < contAluno - 1; j++){ //shift
                    listaAluno[j].matricula = listaAluno[j+1].matricula;
                    listaAluno[j].sexo = listaAluno[j+1].sexo;
                    strcpy(listaAluno[j].cpf, listaAluno[j+1].cpf);
                    strcpy(listaAluno[j].nome, listaAluno[j+1].nome);
                    listaAluno[j].dataNascimento.dia = listaAluno[j+1].dataNascimento.dia;
                    listaAluno[j].dataNascimento.mes = listaAluno[j+1].dataNascimento.mes;
                    listaAluno[j].dataNascimento.ano = listaAluno[j+1].dataNascimento.ano;
                }

                achou = 1;
                break;
            }
        }

        if(achou)
            return EXCLUSAO_SUCESSO;
        else   
            return MATRICULA_INEXISTENTE;
    }
}
//PROFESSOR
int menuProf(){
    int opcaoProf;
    printf("0 - Voltar\n");
    printf("1 - Cadastrar Professor\n");
    printf("2 - Listar Professor\n");
    printf("3 - Atualizar Professor\n");
    printf("4 - Excluir Professor\n");
    scanf("%d", &opcaoProf);
    return opcaoProf;
}
int cadastrarProf(int contProf, Professor listaProf[]){
    printf("Cadastrando Professor...\n");

    if(contProf == TamProf){
        return LISTA_CHEIA;
    }  
    else{
        int matricula;
        char nome[50];
        char sexo;
        char cpf[20];
        printf("Digite a matricula:\n");  
        scanf("%d", &matricula); 
        printf("Digite o nome:\n");
        scanf("%s", &nome);
        printf("Digite o sexo(M/F):\n");
        scanf(" %c", &sexo);
        printf("Digite o CPF:\n");
        scanf("%s", &cpf);

        printf("Digite a data de nacimento:\n");
        printf("Dia:\n");
        scanf("%d", &listaProf[contProf].dataNascimento.dia);

        printf("Mes:\n");
        scanf("%d", &listaProf[contProf].dataNascimento.mes);

        printf("Ano:\n");
        scanf("%d", &listaProf[contProf].dataNascimento.ano);


    if(matricula < 0){
        return MATRICULA_INVALIDA;
    }

        listaProf[contProf].matricula = matricula;
        listaProf[contProf].sexo = sexo;
        listaProf[contProf].ativo = 1;
        strcpy(listaProf[contProf].nome, nome);
        strcpy(listaProf[contProf].cpf, cpf);
        contProf++;
        return CAD_SUCESSO;
    }
}
void listarProf(int contProf, Professor listaProf[]){
    printf("Listando Professor...\n\n");

    if(contProf == 0){
    printf("Lista vazia\n");
    }
    else{
        for(int i = 0; i < contProf; i++){
            if(listaProf[i].ativo == 1){
                printf("Professor %d:\n", i+1);
                printf("Matricula: %d\n", listaProf[i].matricula);
                printf("Nome: %s\n", listaProf[i].nome);
                printf("Sexo: %c\n", listaProf[i].sexo);
                printf("CPF: %s\n", listaProf[i].cpf);
                printf("Data de nascimento: %d/%d/%d\n\n", listaProf[i].dataNascimento.dia, listaProf[i].dataNascimento.mes,                                 listaProf[i].dataNascimento.ano);

            }
        } 
    }
}
int atualizarProf(int contProf, Professor listaProf[]){
    printf("Atualizando Professor...\n");
    printf("Digite a matricula\n");
    int matricula;
    scanf("%d", &matricula);
    int achou = 0;
    if(matricula < 0){
        return MATRICULA_INVALIDA;
    }
    for(int i = 0; i < contProf; i++){
        if(listaProf[i].matricula == matricula && listaProf[i].ativo){
            printf("Digite a nova matricula:\n");
            int novaMatricula;
            scanf("%d", &novaMatricula);
            printf("Digite o novo nome:\n");
            char novoNome[50];
            scanf("%s", &novoNome);
            printf("Digite o novo CPF:\n");
            char novoCpf[20];
            scanf("%s", &novoCpf);
            printf("Digite o novo sexo:\n");
            char novoSexo;
            scanf(" %c", &novoSexo);
            printf("Digite a nova data de nascimento:\n");
            printf("Dia:\n");
            scanf("%d", &listaProf[i].dataNascimento.dia);
            printf("Mes:\n");
            scanf("%d", &listaProf[i].dataNascimento.mes);
            printf("Ano:\n");
            scanf("%d", &listaProf[i].dataNascimento.ano);
            listaProf[i].matricula = novaMatricula;
            listaProf[i].sexo = novoSexo;
            strcpy(listaProf[i].nome, novoNome);
            strcpy(listaProf[i].cpf, novoCpf);
            achou = 1;
            break;
        }
    }
    if(achou)
        return ATUALIZACAO_SUCESSO;
    else   
        return MATRICULA_INEXISTENTE;
}
int excluirProf(int contProf, Professor listaProf[]){
    printf("Excluindo Professor...\n");
    int matricula;
    printf("Digite a matricula\n");
    scanf("%d", &matricula);
    int achou = 0;
    if(matricula < 0){
        return MATRICULA_INVALIDA;
    }
    else{
        for(int i = 0; i <= contProf - 1; i++){ 
            if(matricula == listaProf[i].matricula){
                //exclusao logica
                listaProf[i].ativo = -1;
                for(int j = i; j < contProf - 1; j++){ //shift
                    listaProf[j].matricula = listaProf[j+1].matricula;
                    listaProf[j].sexo = listaProf[j+1].sexo;
                    strcpy(listaProf[j].cpf, listaProf[j+1].cpf);
                    strcpy(listaProf[j].nome, listaProf[j+1].nome);
                    listaProf[j].dataNascimento.dia = listaProf[j+1].dataNascimento.dia;
                    listaProf[j].dataNascimento.mes = listaProf[j+1].dataNascimento.mes;
                    listaProf[j].dataNascimento.ano = listaProf[j+1].dataNascimento.ano;
                }

                achou = 1;
                break;
            }
        }

        if(achou)
            return EXCLUSAO_SUCESSO;
        else   
            return MATRICULA_INEXISTENTE;
    }
}