#include <stdio.h>
#include <string.h>
#define TamAluno 3
#define TamProf 3
#define TamDisc 3
#define CAD_SUCESSO -1
#define MATRICULA_INVALIDA -2
#define LISTA_CHEIA -3
#define ATUALIZACAO_SUCESSO -4
#define MATRICULA_INEXISTENTE -5
#define EXCLUSAO_SUCESSO -6
#define CODIGO_INVALIDO -7
#define SEXO_INVALIDO -8
#define SEMESTRE_INVALIDO -9

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
    int contMatriculado;
} Aluno;

typedef struct pro {
    int matricula;
    char sexo;
    int ativo;
    char nome[50];
    char cpf[20];
    Data dataNascimento;
} Professor;

typedef struct disc {
    char nome[50];
    int semestre;
    int codigo;
    int ativo;
    int matriculaProf;
    Aluno alunos[TamAluno];
    int contador;
} Disciplina;

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
int menuDisciplina();
int cadastrarDisciplina(int contDisc, Disciplina listaDisc[], int contProf, Professor listaProf[]);
int atualizarDisciplina(int contDisc, Disciplina listaDisc[], int contProf, Professor listaProf[]);
void listarDisciplina(int contDisc, Disciplina listaDisc[], int contProf, Professor listaProf[]);
int excluirDisciplina(int contDisc, Disciplina listaDisc[], int contProf, Professor listaProf[]);
int inserirAlunoDisciplina(int contDisc, Disciplina listaDisc[], int contAluno, Aluno listaAluno[], int posicaoDisc, int i);
int excluirAlunoDisciplina(int contDisc, Disciplina listaDisc[], int posicaoDisc);
int menuRelatorio();
void listarUmaDisc(int contDisc, Disciplina listaDisc[], int posicaoDisc, Professor listaProf[], int contProf);
void listarAlunosPsexo(int contAluno, Aluno listaAluno[]);
void bubbleSortPorNome(Aluno listaAluno[], int contAluno);
void listarAlunosOrdenadosPorNome(Aluno listaAluno[], int contAluno);
void bubbleSortPorDataNascimento(Aluno listaAluno[], int contAluno);
void listarAlunosOrdenadosPorDataNascimento(Aluno listaAluno[], int contAluno);
void listarProfessorPsexo(int contProf, Professor listaProf[]);
void listarProfessoresOrdenadosPorNome(Professor listaProf[], int contProf);
void listarProfessoresOrdenadosPorDataNascimento(Professor listaProf[], int contProf);
void listarAniversariantesMes(Professor listaProf[], int contProf, int mes, int contAluno, Aluno listaAluno[]);
void listarPessoasPorBusca(Professor listaProf[], int contProf, char busca[], int contAluno, Aluno listaAluno[]);
void listarAlunosMenosTresDisciplinas(Aluno listaAluno[], int contAluno);
void listarDisciplinasExcedentes(Disciplina listaDisc[], int contDisc, Professor listaProf[], int contProf);

int main(void){

    Aluno listaAluno[TamAluno];
    Professor listaProf[TamProf];
    Disciplina listaDisc[TamDisc];
    int opcao;
    int contAluno = 0;
    int contProf = 0;
    int contDisc = 0;
    int matricula;
    char sexo;
    char nome[50];
    char cpf[20];
    char codigo[20];
    int semestre;
    char profNome[50];
    int posicaoDisc;
    int mesDesejado;
    int i;
    for(int i = 0; i < TamDisc; i++){
        listaDisc[i].contador = 0;
    }
    for(int i = 0; i < TamAluno; i++){
        listaAluno[i].contMatriculado = 0;
    }

    do{

        opcao = menuPrincipal();


        switch(opcao){

            case 0:

                printf("Saindo...\n");
                break;

            case 1:
                int opcaoAluno;
                do{
                    printf("--------------------------------------------------\n");
                    printf("Aluno\n");
                    opcaoAluno = menuAluno();


                    switch(opcaoAluno){

                        case 0:

                            printf("\nVoltando...\n");
                            break;

                        case 1:
                            int retorno = cadastrarAluno(contAluno, listaAluno);
                            if(retorno == LISTA_CHEIA){
                                printf("\nLista de alunos cheia\n");
                            }
                            else if(retorno == MATRICULA_INVALIDA){
                                printf("\nMatricula invalida, numero digitado incorreto ou numero de matricula ja existente\n");
                            }
                            else if(retorno == SEXO_INVALIDO){
                                printf("\nSexo digitado errado\n");
                            }
                            else if(retorno == CAD_SUCESSO){
                                printf("\nAluno cadastrado com sucesso\n");
                                contAluno++;
                            }
                            break;

                        case 2:
                            listarAluno(contAluno, listaAluno);

                            break;

                        case 3:
                            retorno = atualizarAluno(contAluno, listaAluno);
                            if(retorno == MATRICULA_INVALIDA){
                                printf("\nMatricula invalida\n");
                            }
                            else if(retorno == MATRICULA_INEXISTENTE){
                                printf("\nMatricula invalida\n");
                            }
                            else if(retorno == SEXO_INVALIDO){
                                printf("\nSexo digitado errado\n");
                            }
                            else if(retorno == ATUALIZACAO_SUCESSO){
                                printf("\nAluno atualizado com sucesso\n");
                            }

                            break;

                        case 4:
                            retorno = excluirAluno(contAluno, listaAluno);
                            if(retorno == MATRICULA_INVALIDA){
                                printf("\nMatricula invalida\n");
                            }
                            else if(retorno == EXCLUSAO_SUCESSO){
                                printf("\nAluno excluido com sucesso\n");
                                contAluno--;
                            }
                            else if(retorno == MATRICULA_INEXISTENTE){
                                printf("\nMatricula Inexistente\n");
                            }
                            break;
                        default:

                            printf("\nOpção Inválida\n");
                            break;

                        }

                    }while(opcaoAluno != 0);

                break;
            case 2:
                int opcaoProf;
                do{
                    printf("--------------------------------------------------\n");
                    printf("Professor\n");
                    opcaoProf = menuProf();


                    switch(opcaoProf){

                        case 0:

                            printf("\nVoltando...\n");
                            break;

                        case 1:
                            int retorno = cadastrarProf(contProf, listaProf);
                            if(retorno == LISTA_CHEIA){
                                printf("\nLista de professores cheia\n");
                            }
                            else if(retorno == MATRICULA_INVALIDA){
                                printf("\nMatricula invalida, numero digitado incorreto ou numero de matricula ja existente\n");
                            }
                            else if(retorno == SEXO_INVALIDO){
                                printf("\nSexo digitado errado\n");
                            }
                            else if(retorno == CAD_SUCESSO){
                                printf("\nProfessor cadastrado com sucesso\n");
                                contProf++;
                            }
                            break;

                        case 2:
                            listarProf(contProf, listaProf);

                            break;

                        case 3:
                            retorno = atualizarProf(contProf, listaProf);
                            if(retorno == MATRICULA_INVALIDA){
                                printf("\nMatricula invalida\n");
                            }
                            else if(retorno == MATRICULA_INEXISTENTE){
                                printf("\nMatricula inexistente\n");
                            }
                            else if(retorno == SEXO_INVALIDO){
                                printf("\nSexo digitado errado\n");
                            }
                            else if(retorno == ATUALIZACAO_SUCESSO){
                                printf("\nProfessor atualizado com sucesso\n");
                            }

                            break;

                        case 4:
                            retorno = excluirProf(contProf, listaProf);
                            if(retorno == MATRICULA_INVALIDA){
                                printf("\nMatricula invalida\n");
                            }
                            else if(retorno == EXCLUSAO_SUCESSO){
                                printf("\nProfessor excluido com sucesso\n");
                                contProf--;
                            }
                            else if(retorno == MATRICULA_INEXISTENTE){
                                printf("\nMatricula Inexistente\n");
                            }
                            break;
                        default:

                            printf("\nOpção Inválida\n");
                            break;

                        }

                    }while(opcaoProf != 0);
                break;

            case 3:
                int opcaoDisciplina;
                do{
                    printf("--------------------------------------------------\n");
                    printf("Disciplina\n");
                    opcaoDisciplina = menuDisciplina();


                    switch(opcaoDisciplina){

                        case 0:

                            printf("\nVoltando...\n");
                            break;

                        case 1:
                            int retorno = cadastrarDisciplina(contDisc, listaDisc, contProf, listaProf);
                            if(retorno == LISTA_CHEIA)
                                printf("\nLista de disciplinas cheia\n");
                            else if(retorno == CODIGO_INVALIDO)
                                printf("\nCodigo invalido, numero digitado incorreto ou codigo ja existente para outra disciplina\n");
                            else if(retorno == MATRICULA_INEXISTENTE){
                                printf("\nEsse professor nao foi cadastrado\n");
                            }
                            else if(retorno == SEMESTRE_INVALIDO){
                                printf("\nSemestre invalido, provavelmente foi digitado um numero menor que 1 ou maior que 20(limite)\n");
                            }
                            else if(retorno == CAD_SUCESSO){
                                printf("\nDisciplina cadastrada com sucesso\n");
                                contDisc++;
                            }
                            break;

                        case 2:
                            listarDisciplina(contDisc, listaDisc, contProf, listaProf);
                            break;

                        case 3:
                            retorno = atualizarDisciplina(contDisc, listaDisc, contProf, listaProf);
                            if(retorno == CODIGO_INVALIDO){
                                printf("\nCodigo invalido\n");
                            }
                            else if(retorno == MATRICULA_INEXISTENTE){
                                printf("\nCodigo inexistente\n");
                            }
                            else if(retorno == SEMESTRE_INVALIDO){
                                printf("\nSemestre invalido, provavelmente foi digitado um numero menor que 1 ou maior que 20(limite)\n");  
                            }
                            else if(retorno == ATUALIZACAO_SUCESSO){
                                printf("\nDisciplina atualizada com sucesso\n");
                            }

                            break;

                        case 4:
                            retorno = excluirDisciplina(contDisc, listaDisc, contProf, listaProf);
                            if(retorno == CODIGO_INVALIDO)
                                printf("\nCodigo invalido, numero digitado incorreto ou codigo ja existente para outra disciplina\n");
                            else if(retorno == EXCLUSAO_SUCESSO){
                                printf("\nProfessor excluido com sucesso\n");
                                contDisc--;
                            }
                            else if(retorno == MATRICULA_INEXISTENTE){
                                printf("\nMatricula Inexistente\n");
                            }
                            break;
                        case 5:
                            retorno = inserirAlunoDisciplina(contDisc, listaDisc, contAluno, listaAluno, posicaoDisc, i);                
                            if(retorno == MATRICULA_INVALIDA)
                                printf("\nMatricula invalida\n");
                            else if(retorno == MATRICULA_INEXISTENTE){
                                printf("\nEsse Aluno nao foi cadastrado\n");
                            }
                            else if(retorno == CODIGO_INVALIDO){
                                printf("\nCodigo da disciplina digitado errado\n");
                            }
                            else if(retorno == CAD_SUCESSO){
                                printf("\nAluno cadastrado na disciplina com sucesso\n");
                                listaDisc[posicaoDisc].contador++;
                                listaAluno[i].contMatriculado++;
                            }
                            break;
                        case 6:
                            retorno = excluirAlunoDisciplina(contDisc, listaDisc, posicaoDisc);
                            if(retorno == MATRICULA_INVALIDA){
                                printf("\nMatricula invalida\n");
                            }
                            else if(retorno == EXCLUSAO_SUCESSO){
                                printf("\nAluno excluido da disciplina com sucesso\n");
                                listaDisc[posicaoDisc].contador--;
                            }
                            else if(retorno == MATRICULA_INEXISTENTE){
                                printf("\nMatricula Inexistente\n");
                            }
                            break;
                            break;
                        default:

                            printf("\nOpção Inválida\n");
                            break;

                        }

                    }while(opcaoDisciplina != 0);
                break;
            case 4:
                int opcaoRelatorio;
            do{
                printf("--------------------------------------------------\n");
                printf("Relatorio\n");
                opcaoRelatorio = menuRelatorio();
                switch(opcaoRelatorio){

                    case 0:

                        printf("\nVoltando...\n");
                        break;

                    case 1:
                        listarUmaDisc(contDisc, listaDisc, posicaoDisc, listaProf, contProf);
                        break;

                    case 2:
                        listarAlunosPsexo(contAluno, listaAluno);
                        break;

                    case 3:
                        listarAlunosOrdenadosPorNome(listaAluno, contAluno);
                        break;
                    case 4:
                        listarAlunosOrdenadosPorDataNascimento(listaAluno, contAluno);
                        break;
                    case 5:
                        listarProfessorPsexo(contProf, listaProf);
                        break;
                    case 6:
                        listarProfessoresOrdenadosPorNome(listaProf, contProf);
                        break;
                    case 7:
                        listarProfessoresOrdenadosPorDataNascimento(listaProf, contProf);
                        break;
                    case 8:
                        printf("\nDigite o mês desejado: \n");
                        scanf("%d", &mesDesejado);
                        listarAniversariantesMes(listaProf, contProf, mesDesejado, contAluno, listaAluno);
                        break;
                    case 9:

                        char busca[100];
                        getchar();
                        printf("\nDigite a string de busca (minimo tres letras): \n");
                        fgets(busca, 100, stdin);
                        int tamString = strlen(busca) -1;
                        busca[tamString] = '\0';
                        if (strlen(busca) < 3)
                        {
                            printf("\nA busca deve conter no minimo tres letras.\n");
                        }
                        else
                        {
                            listarPessoasPorBusca(listaProf, contProf, busca, contAluno, listaAluno);
                        }

                        break;
                    case 10:
                        listarAlunosMenosTresDisciplinas(listaAluno, contAluno);
                        break;                
                    case 11:
                        listarDisciplinasExcedentes(listaDisc, contDisc, listaProf, contProf);
                        break;
                    default:
                        printf("\nOpção Inválida\n");
                        break;

                }

            }while(opcaoRelatorio != 0);
            default:

                printf("\nOpção inválida\n");
                break;

        }

    }while(opcao != 0);
}
//funções
//ALUNO
int menuPrincipal(){
    int opcao;
    printf("--------------------------------------------------\n");
    printf("Projeto Escola\n");
    printf("\n0 - Sair\n");
    printf("1 - Aluno\n");
    printf("2 - Professor\n");
    printf("3 - Disciplina\n");
    printf("4 - Relatorios\n");
    scanf("\n%d", &opcao);
    return opcao;
}
int menuAluno(){
    int opcaoAluno;
    printf("\n0 - Voltar\n");
    printf("1 - Cadastrar Aluno\n");
    printf("2 - Listar Aluno\n");
    printf("3 - Atualizar Aluno\n");
    printf("4 - Excluir Aluno\n");
    scanf("\n%d", &opcaoAluno);
    return opcaoAluno;
}
int cadastrarAluno(int contAluno, Aluno listaAluno[]){
    printf("--------------------------------------------------\n");
    printf("Cadastrando Aluno...\n");

    if(contAluno == TamAluno){
        return LISTA_CHEIA;
    }  
    else{
        int matricula;
        char nome[50];
        char sexo;
        char cpf[20];
        printf("\nDigite a matricula:\n");  
        scanf("\n%d", &matricula);
        for(int i = 0; i < contAluno; i++){
            if(matricula == listaAluno[i].matricula){
                return MATRICULA_INVALIDA;
                break;
            }
        }
        getchar();
        printf("Digite o nome:\n");
        fgets(nome, 50, stdin);
        int tamString = strlen(nome) -1;
        nome[tamString] = '\0';
        printf("Digite o sexo(M/F):\n");
        scanf(" \n%c", &sexo);
        if(sexo != 'M' && sexo != 'm' && sexo != 'F' && sexo != 'f'){
            return SEXO_INVALIDO;
        }
        getchar();
        printf("Digite o CPF:\n");
        fgets(cpf, 20, stdin);
        tamString = strlen(cpf) -1;
        cpf[tamString] = '\0';
        printf("Digite a data de nacimento:\n");
        printf("Dia:\n");
        scanf("\n%d", &listaAluno[contAluno].dataNascimento.dia);
        
        printf("Mes:\n");
        scanf("\n%d", &listaAluno[contAluno].dataNascimento.mes);

        printf("Ano:\n");
        scanf("\n%d", &listaAluno[contAluno].dataNascimento.ano);
        


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
    printf("--------------------------------------------------\n");
    printf("Listando Aluno...\n");

    if(contAluno == 0){
    printf("Lista vazia\n");
    }
    else{
        for(int i = 0; i < contAluno; i++){
            if(listaAluno[i].ativo == 1){
                printf("\nAluno %d:\n", i+1);
                printf("Matricula: %d\n", listaAluno[i].matricula);
                printf("Nome: %s\n", listaAluno[i].nome);
                printf("Sexo: %c\n", listaAluno[i].sexo);
                printf("CPF: %s\n", listaAluno[i].cpf);
                printf("Data de nascimento: %d/%d/%d\n", listaAluno[i].dataNascimento.dia, 
                                                         listaAluno[i].dataNascimento.mes,                                 
                                                         listaAluno[i].dataNascimento.ano);
            }
        } 
    }
}
int atualizarAluno(int contAluno, Aluno listaAluno[]){
    printf("--------------------------------------------------\n");
    printf("Atualizando Aluno...\n");
    if(contAluno == 0){
        printf("Lista vazia\n");
    }
    else{
        printf("\nDigite a matricula\n");
        int matricula;
        scanf("\n%d", &matricula);
        int achou = 0;
        if(matricula < 0){
            return MATRICULA_INVALIDA;
        }
        for(int i = 0; i < contAluno; i++){
            if(listaAluno[i].matricula == matricula && listaAluno[i].ativo){
                printf("Digite a nova matricula:\n");
                int novaMatricula;
                scanf("\n%d", &novaMatricula);
                getchar();
                printf("Digite o novo nome:\n");
                char novoNome[50];
                fgets(novoNome, 50, stdin);
                int tamString = strlen(novoNome) -1;
                novoNome[tamString] = '\0';
                printf("Digite o novo sexo:\n");
                char novoSexo;
                scanf(" \n%c", &novoSexo);
                if(novoSexo != 'M' && novoSexo != 'm' && novoSexo != 'F' && novoSexo != 'f'){
                    return SEXO_INVALIDO;
                    break;
                }
                getchar();
                printf("Digite o novo CPF:\n");
                char novoCpf[20];
                fgets(novoCpf, 20, stdin);
                tamString = strlen(novoCpf) -1;
                novoCpf[tamString] = '\0';
                printf("Digite a nova data de nascimento:\n");
                printf("Dia:\n");
                scanf("\n%d", &listaAluno[i].dataNascimento.dia);
                printf("Mes:\n");
                scanf("\n%d", &listaAluno[i].dataNascimento.mes);
                printf("Ano:\n");
                scanf("\n%d", &listaAluno[i].dataNascimento.ano);

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
   
}
int excluirAluno(int contAluno, Aluno listaAluno[]){
    printf("--------------------------------------------------\n");
    printf("Excluindo Aluno...\n");
    if(contAluno == 0){
        printf("Lista vazia\n");
    }
    else{
        int matricula;
        printf("\nDigite a matricula\n");
        scanf("\n%d", &matricula);
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
}
//PROFESSOR
int menuProf(){
    int opcaoProf;    
    printf("\n0 - Voltar\n");
    printf("1 - Cadastrar Professor\n");
    printf("2 - Listar Professor\n");
    printf("3 - Atualizar Professor\n");
    printf("4 - Excluir Professor\n");
    scanf("\n%d", &opcaoProf);
    return opcaoProf;
}
int cadastrarProf(int contProf, Professor listaProf[]){
    printf("--------------------------------------------------\n");
    printf("Cadastrando Professor...\n");

    if(contProf == TamProf){
        return LISTA_CHEIA;
    }  
    else{
        int matricula;
        char nome[50];
        char sexo;
        char cpf[20];
        printf("\nDigite a matricula:\n");  
        scanf("\n%d", &matricula);
        for(int i = 0; i < contProf; i++){
            if(matricula == listaProf[i].matricula){
                return MATRICULA_INVALIDA;
                break;
            }
        }
        getchar();
        printf("Digite o nome:\n");
        fgets(nome, 50, stdin);
        int tamString = strlen(nome) -1;
        nome[tamString] = '\0';
        printf("Digite o sexo(M/F):\n");
        scanf(" \n%c", &sexo);
        if(sexo != 'M' && sexo != 'm' && sexo != 'F' && sexo != 'f'){
            return SEXO_INVALIDO;
        }
        getchar();
        printf("Digite o CPF:\n");
        fgets(cpf, 20, stdin);
        tamString = strlen(cpf) -1;
        cpf[tamString] = '\0';

        printf("Digite a data de nacimento:\n");
        printf("Dia:\n");
        scanf("\n%d", &listaProf[contProf].dataNascimento.dia);

        printf("Mes:\n");
        scanf("\n%d", &listaProf[contProf].dataNascimento.mes);

        printf("Ano:\n");
        scanf("\n%d", &listaProf[contProf].dataNascimento.ano);

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
    printf("--------------------------------------------------\n");
    printf("Listando Professor...\n");

    if(contProf == 0){
    printf("Lista vazia\n");
    }
    else{
        for(int i = 0; i < contProf; i++){
            if(listaProf[i].ativo == 1){
                printf("\nProfessor %d:\n", i+1);
                printf("Matricula: %d\n", listaProf[i].matricula);
                printf("Nome: %s\n", listaProf[i].nome);
                printf("Sexo: %c\n", listaProf[i].sexo);
                printf("CPF: %s\n", listaProf[i].cpf);
                printf("Data de nascimento: %d/%d/%d\n", listaProf[i].dataNascimento.dia, 
                                                         listaProf[i].dataNascimento.mes,                                 
                                                         listaProf[i].dataNascimento.ano);
            }
        } 
    }
}
int atualizarProf(int contProf, Professor listaProf[]){
    printf("--------------------------------------------------\n");
    printf("Atualizando Professor...\n");
    if(contProf == 0){
        printf("Lista vazia\n");
    }
    else{
        printf("\nDigite a matricula\n");
        int matricula;
        scanf("\n%d", &matricula);
        int achou = 0;
        if(matricula < 0){
            return MATRICULA_INVALIDA;
        }
        for(int i = 0; i < contProf; i++){
            if(listaProf[i].matricula == matricula && listaProf[i].ativo){
                printf("Digite a nova matricula:\n");
                int novaMatricula;
                scanf("\n%d", &novaMatricula);
                getchar();
                printf("Digite o novo nome:\n");
                char novoNome[50];
                fgets(novoNome, 50, stdin);
                int tamString = strlen(novoNome) -1;
                novoNome[tamString] = '\0';
                printf("Digite o novo sexo:\n");
                char novoSexo;
                scanf(" \n%c", &novoSexo);
                if(novoSexo != 'M' && novoSexo != 'm' && novoSexo != 'F' && novoSexo != 'f'){
                    return SEXO_INVALIDO;
                }
                getchar();
                printf("Digite o novo CPF:\n");
                char novoCpf[20];
                fgets(novoCpf, 20, stdin);
                tamString = strlen(novoCpf) -1;
                novoCpf[tamString] = '\0';
                printf("Digite a nova data de nascimento:\n");
                printf("Dia:\n");
                scanf("\n%d", &listaProf[i].dataNascimento.dia);
                printf("Mes:\n");
                scanf("\n%d", &listaProf[i].dataNascimento.mes);
                printf("Ano:\n");
                scanf("\n%d", &listaProf[i].dataNascimento.ano);
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
}
int excluirProf(int contProf, Professor listaProf[]){
    printf("--------------------------------------------------\n");
    printf("Excluindo Professor...\n");
    if(contProf == 0){
        printf("Lista vazia\n");
    }
    else{
        int matricula;
        printf("\nDigite a matricula\n");
        scanf("\n%d", &matricula);
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
}
// DISCIPLINA
int menuDisciplina(){
    int opcaoDisciplina;
    printf("\n0 - Voltar\n");
    printf("1 - Cadastrar Disciplina\n");
    printf("2 - Listar Disciplina\n");
    printf("3 - Atualizar Disciplina\n");
    printf("4 - Excluir Disciplina\n");
    printf("5 - Inserir aluno em alguma Disciplina\n");
    printf("6 - Excluir aluno em alguma Disciplina\n");
    scanf("\n%d", &opcaoDisciplina);
    return opcaoDisciplina;
}
int cadastrarDisciplina(int contDisc, Disciplina listaDisc[], int contProf, Professor listaProf[]){
    printf("--------------------------------------------------\n");
    printf("Cadastrando Disciplinas...\n");

    if(contDisc == TamDisc){
        return LISTA_CHEIA;
    }  
    else{
        char nome[50];
        int semestre;
        int matricula;
        int codigo;
        int achou = 0;
        printf("\nDigite o codigo:\n");  
        scanf("\n%d", &codigo);
        for(int i = 0; i < contDisc; i++){
            if(codigo == listaDisc[i].codigo){
                return CODIGO_INVALIDO;
                break;
            }
        }
        getchar();
        printf("Digite o nome:\n");
        fgets(nome, 50, stdin);
        int tamString = strlen(nome) -1;
        nome[tamString] = '\0';
        printf("Digite o semestre da disciplina:\n");
        scanf("\n%d", &semestre);
        if(semestre < 1 || semestre > 20){
            return SEMESTRE_INVALIDO;
        }
        printf("Digite a matricula do professor:\n");
        scanf("\n%d", &matricula);
        for(int i = 0; i < contProf; i++){
            if(matricula == listaProf[i].matricula){
                achou = 1;
                listaDisc[contDisc].matriculaProf = listaProf[i].matricula;
                break;
            }
        }
        if(!achou){
            return MATRICULA_INEXISTENTE;
        }
        if(codigo < 0){
                return CODIGO_INVALIDO;
        }
            listaDisc[contDisc].codigo = codigo;
            listaDisc[contDisc].semestre = semestre;
            listaDisc[contDisc].ativo = 1;
            strcpy(listaDisc[contDisc].nome, nome);
            contDisc++;
            return CAD_SUCESSO;

    }
}
void listarDisciplina(int contDisc, Disciplina listaDisc[], int contProf, Professor listaProf[]){
    printf("--------------------------------------------------\n");
    printf("Listando Disciplinas...\n");

    if(contDisc == 0){
        printf("Lista vazia\n");
    }
    else{
        for(int i = 0; i < contDisc; i++){
            if(listaDisc[i].ativo == 1){
                printf("\nDisciplina %d:\n", i+1);
                printf("Codigo: %d\n", listaDisc[i].codigo);
                printf("Nome: %s\n", listaDisc[i].nome);
                printf("Semestre: %d\n", listaDisc[i].semestre);
                for(int j = 0; j < contProf; j++){
                    if(listaDisc[i].matriculaProf == listaProf[j].matricula){
                        printf("Professor: %s\n", listaProf[j].nome);
                    }
                }
            } 
        }
    }
}
int atualizarDisciplina(int contDisc, Disciplina listaDisc[], int contProf, Professor listaProf[]){
    printf("--------------------------------------------------\n");
    printf("Atualizando Disciplina...\n");
    if(contDisc == 0){
        printf("Lista vazia\n");
    }
    else{
        printf("\nDigite o codigo\n");
        int codigo;
        scanf("\n%d", &codigo);
        int achou = 0;
        if(codigo < 0){
            return CODIGO_INVALIDO;
        }
        for(int i = 0; i < contDisc; i++){
            if(listaDisc[i].codigo == codigo && listaDisc[i].ativo){
                printf("Digite o novo codigo:\n");
                int novaCodigo;
                scanf("\n%d", &novaCodigo);
                if(novaCodigo < 0){
                    return CODIGO_INVALIDO;
                }
                getchar();
                printf("Digite o novo nome:\n");
                char novoNome[50];
                fgets(novoNome, 50, stdin);
                int tamString = strlen(novoNome) -1;
                novoNome[tamString] = '\0';
                printf("Digite o novo semestre:\n");
                int novoSemestre;
                scanf("\n%d", &novoSemestre);
                if(novoSemestre < 1 || novoSemestre > 20){
                    return SEMESTRE_INVALIDO;
                }
                getchar();
                printf("Digite a nova matricula do professor:\n");
                int novaMatricula;
                scanf("\n%d", &novaMatricula);
                for(int j = 0; j < contProf; j++){
                    if(novaMatricula == listaProf[j].matricula){
                        listaDisc[i].matriculaProf = listaProf[j].matricula;
                        break;
                    }
                }
                listaDisc[i].codigo = novaCodigo;
                listaDisc[i].semestre = novoSemestre;
                strcpy(listaDisc[i].nome, novoNome);
                achou = 1;
                break;
            }
        }
        if(achou)
            return ATUALIZACAO_SUCESSO;
        else   
            return MATRICULA_INEXISTENTE;
    }
    
}
int excluirDisciplina(int contDisc, Disciplina listaDisc[], int contProf, Professor listaProf[]){
    printf("--------------------------------------------------\n");
    printf("Excluindo Disciplina...\n");
    if(contDisc == 0){
        printf("Lista vazia\n");
    }
    else{
        int codigo;
        printf("\nDigite o codigo\n");
        scanf("\n%d", &codigo);
        int achou = 0;
        if(codigo < 0){
            return CODIGO_INVALIDO;
        }
        else{
            for(int i = 0; i <= contDisc - 1; i++){ 
                if(codigo == listaDisc[i].codigo){
                    //exclusao logica
                    listaDisc[i].ativo = -1;
                    for(int j = i; j < contDisc - 1; j++){ //shift
                        listaDisc[j].codigo = listaDisc[j+1].codigo;
                        listaDisc[j].semestre = listaDisc[j+1].semestre;
                        strcpy(listaDisc[j].nome, listaDisc[j+1].nome);
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
}
int inserirAlunoDisciplina(int contDisc, Disciplina listaDisc[], int contAluno, Aluno listaAluno[], int posicaoDisc, int i){
    printf("--------------------------------------------------\n");
    printf("Inserindo Aluno...\n");
    if(contDisc == 0){
        printf("Lista vazia\n");
    }
    else{
        int matricula;
        printf("\nDigite a matricula\n");
        scanf("\n%d", &matricula);
        printf("Digite o codigo da disciplina\n");
        int codigo;
        scanf("\n%d", &codigo);
        int achou = 0;
        int achouCodigo = 0;
        if(matricula < 0 || contDisc <= 0){
            return MATRICULA_INVALIDA;
        }
        else{
            for(int j = 0; j < contDisc; j++){
                if(codigo == listaDisc[j].codigo){
                    posicaoDisc = j;
                    achouCodigo = 1;
                    break;
                }
            }
            if(achouCodigo){
                for(int i = 0; i < contAluno; i++){ 
                if(matricula == listaAluno[i].matricula){
                    achou = 1;
                    listaDisc[posicaoDisc].alunos[listaDisc[posicaoDisc].contador] = listaAluno[i];
                    break;
                    }
                }
            }
            else{
                return CODIGO_INVALIDO;
            }
        }

        if(!achou)
            return MATRICULA_INEXISTENTE;
        else
            return CAD_SUCESSO;
    }
}
int excluirAlunoDisciplina(int contDisc, Disciplina listaDisc[], int posicaoDisc){
    printf("--------------------------------------------------\n");
    printf("Excluindo Aluno da Disciplina...\n");
    if(contDisc == 0){
        printf("Lista vazia\n");
    }
    else{
        int matricula;
        printf("\nDigite a matricula\n");
        scanf("\n%d", &matricula);
        printf("Digite o codigo da disciplina\n");
        int codigo;
        scanf("\n%d", &codigo);
        int achou = 0;
        if(codigo < 0){
            return MATRICULA_INVALIDA;
        }
        else{
            for(int j = 0; j < contDisc; j++){
                if(codigo == listaDisc[j].codigo){
                    posicaoDisc = j;
                    break;
                }
            }
            for(int i = 0; i <= contDisc - 1; i++){ 
                if(matricula == listaDisc[posicaoDisc].alunos[i].matricula){
                    //exclusao logica
                    listaDisc[i].ativo = -1;
                    for(int j = i; j < contDisc - 1; j++){ //shift
                        listaDisc[posicaoDisc].alunos[j] = listaDisc[posicaoDisc].alunos[j+1];
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
}
//RELATORIO
int menuRelatorio(){
    int opcaoRelatorio;
    printf("\n0 - Voltar\n");
    printf("1 - Listar uma disciplina(dados da disciplina e alunos matriculados)\n");
    printf("2 - Listar alunos por sexo(Masculino/Feminino)\n");
    printf("3 - Listar alunos ordenados por nome\n");
    printf("4 - Listar alunos por data de nascimento\n");
    printf("5 - Listar professores por sexo(Masculino/Feminino)\n");
    printf("6 - Listar professores ordenados por nome\n");
    printf("7 - Listar professores por data de nascimento\n");
    printf("8 - Aniversariantes do mes\n");
    printf("9 - Lista de pessoas a partir de uma string de busca\n");
    printf("10 - Lista de alunos matriculados em menos de 3 disciplinas\n");
    printf("11 - Lista de professores, com nome de professor que extrapolam 40 vagas\n");
    scanf("\n%d", &opcaoRelatorio);
    return opcaoRelatorio;
}
void listarUmaDisc(int contDisc, Disciplina listaDisc[], int posicaoDisc, Professor listaProf[], int contProf){
    printf("--------------------------------------------------\n");
    printf("Listando uma Disciplina especifica...\n");
    if(contDisc == 0){
        printf("Lista vazia\n");
    }
    else{
        printf("\nDigite o codigo da disciplina\n");
        int codigo;
        scanf("\n%d", &codigo);
        for(int j = 0; j < contDisc; j++){
        if(codigo == listaDisc[j].codigo){
            posicaoDisc = j;
            break;
        }
        }
        if(listaDisc[posicaoDisc].ativo == 1){           
            printf("\nCodigo: %d\n", listaDisc[posicaoDisc].codigo);
            printf("Nome: %s\n", listaDisc[posicaoDisc].nome);
            printf("Semestre: %d\n", listaDisc[posicaoDisc].semestre);
            for(int j = 0; j < contProf; j++){
                if(listaDisc[posicaoDisc].matriculaProf == listaProf[j].matricula){
                    printf("Professor: %s\n", listaProf[j].nome);
                    printf("Maricula: %d\n", listaProf[j].matricula);
                    printf("Sexo: %c\n", listaProf[j].sexo);
                    printf("CPF: %s\n", listaProf[j].cpf);
                    printf("Data de nascimento: %d/%d/%d\n", listaProf[j].dataNascimento.dia, 
                                                             listaProf[j].dataNascimento.mes, 
                                                            listaProf[j].dataNascimento.ano);
                }
            }
            printf("\nAlunos Matriculados:\n");
            for(int i = 0; i < listaDisc[posicaoDisc].contador; i++){
                //printf("Aluno %d:\n", i+1, listaDisc[posicaoDisc].alunos[i].nome);
                printf("\nMatricula: %d\n", listaDisc[posicaoDisc].alunos[i].matricula);
                printf("Nome: %s\n", listaDisc[posicaoDisc].alunos[i].nome);
                printf("Sexo: %c\n", listaDisc[posicaoDisc].alunos[i].sexo);
                printf("CPF: %s\n", listaDisc[posicaoDisc].alunos[i].cpf);
                printf("Data de nascimento: %d/%d/%d\n", listaDisc[posicaoDisc].alunos[i].dataNascimento.dia,                             
                                                         listaDisc[posicaoDisc].alunos[i].dataNascimento.mes, 
                                                         listaDisc[posicaoDisc].alunos[i].dataNascimento.ano);
            }
        }

    }
}
void listarAlunosPsexo(int contAluno, Aluno listaAluno[]){
    printf("--------------------------------------------------\n");
    printf("Listando alunos por sexo(M/F)\n");
    printf("\nDigite o sexo\n");
    char sexo;
    scanf(" \n%c", &sexo);
    if(contAluno == 0){
        printf("Lista vazia\n");
    }
    else{
        if(sexo == 'M' || sexo == 'm'){
            for(int i = 0; i < contAluno; i++){
                if(listaAluno[i].sexo == 'M' || listaAluno[i].sexo == 'm'){
                    printf("\nMatricula: %d\n", listaAluno[i].matricula);
                    printf("Nome: %s\n", listaAluno[i].nome);
                    printf("Sexo: %c\n", listaAluno[i].sexo);
                    printf("CPF: %s\n", listaAluno[i].cpf);
                    printf("Data de nascimento: %d/%d/%d\n", listaAluno[i].dataNascimento.dia,                             
                                                             listaAluno[i].dataNascimento.mes, 
                                                             listaAluno[i].dataNascimento.ano);
                }
            }
        }
        else if(sexo == 'F' || sexo == 'f'){
            for(int i = 0; i < contAluno; i++){
                if(listaAluno[i].sexo == 'F' || listaAluno[i].sexo == 'f'){
                    printf("\nMatricula: %d\n", listaAluno[i].matricula);
                    printf("Nome: %s\n", listaAluno[i].nome);
                    printf("Sexo: %c\n", listaAluno[i].sexo);
                    printf("CPF: %s\n", listaAluno[i].cpf);
                    printf("Data de nascimento: %d/%d/%d\n", listaAluno[i].dataNascimento.dia,                             
                                                             listaAluno[i].dataNascimento.mes, 
                                                             listaAluno[i].dataNascimento.ano);
                }
            }
        }
        else{
            printf("Sexo digitado errado\n");
        }
    }
}
void bubbleSortPorNome(Aluno listaAluno[], int contAluno){
    for(int i = 0; i < contAluno - 1; i++){
        for(int j = 0; j < contAluno - i - 1; j++){
            if(strcmp(listaAluno[j].nome, listaAluno[j + 1].nome) > 0) {
                Aluno temp = listaAluno[j];
                listaAluno[j] = listaAluno[j + 1];
                listaAluno[j + 1] = temp;
            }
        }
    }
}


void listarAlunosOrdenadosPorNome(Aluno listaAluno[], int contAluno){
    printf("--------------------------------------------------\n");
    printf("Alunos Ordenados por Nome\n");
    if(contAluno == 0){
        printf("Lista de alunos vazia\n");
    } 
    else{
        
        bubbleSortPorNome(listaAluno, contAluno);

        
        for(int i = 0; i < contAluno; i++){
            printf("\nMatricula: %d\n", listaAluno[i].matricula);
            printf("Nome: %s\n", listaAluno[i].nome);
            printf("Sexo: %c\n", listaAluno[i].sexo);
            printf("CPF: %s\n", listaAluno[i].cpf);
            printf("Data de nascimento: %d/%d/%d\n", listaAluno[i].dataNascimento.dia,                             
                                                     listaAluno[i].dataNascimento.mes, 
                                                     listaAluno[i].dataNascimento.ano);
        }
    }
}
void bubbleSortPorDataNascimento(Aluno listaAluno[], int contAluno){
    for(int i = 0; i < contAluno - 1; i++){
        for(int j = 0; j < contAluno - i - 1; j++) 
            if(listaAluno[j].dataNascimento.ano > listaAluno[j + 1].dataNascimento.ano ||
                (listaAluno[j].dataNascimento.ano == listaAluno[j + 1].dataNascimento.ano &&
                listaAluno[j].dataNascimento.mes > listaAluno[j + 1].dataNascimento.mes) ||
                (listaAluno[j].dataNascimento.ano == listaAluno[j + 1].dataNascimento.ano &&
                listaAluno[j].dataNascimento.mes == listaAluno[j + 1].dataNascimento.mes &&
                listaAluno[j].dataNascimento.dia > listaAluno[j + 1].dataNascimento.dia)){
                Aluno temp = listaAluno[j];
                listaAluno[j] = listaAluno[j + 1];
                listaAluno[j + 1] = temp;
            }
        }
}
void listarAlunosOrdenadosPorDataNascimento(Aluno listaAluno[], int contAluno){
    printf("--------------------------------------------------\n");
    printf("Alunos Ordenados por Data de nascimento\n");
    if(contAluno == 0){
        printf("Lista de alunos vazia\n");
    } 
    else{

        bubbleSortPorDataNascimento(listaAluno, contAluno);


        for(int i = 0; i < contAluno; i++){
            printf("\nMatricula: %d\n", listaAluno[i].matricula);
            printf("Nome: %s\n", listaAluno[i].nome);
            printf("Data de nascimento: %d/%d/%d\n", listaAluno[i].dataNascimento.dia,                             
                                                     listaAluno[i].dataNascimento.mes, 
                                                     listaAluno[i].dataNascimento.ano);
        }
    }
}
void listarProfessorPsexo(int contProf, Professor listaProf[]){
    printf("--------------------------------------------------\n");
    printf("Listando Professores por sexo(M/F)\n");
    if(contProf == 0){
        printf("Lista vazia\n");
    }
    else{
        printf("\nDigite o sexo\n");
        char sexo;
        scanf(" \n%c", &sexo);
        if(sexo == 'M' || sexo == 'm'){
            for(int i = 0; i < contProf; i++){
                if(listaProf[i].sexo == 'M' || listaProf[i].sexo == 'm'){
                    printf("\nMatricula: %d\n", listaProf[i].matricula);
                    printf("Nome: %s\n", listaProf[i].nome);
                    printf("Sexo: %c\n", listaProf[i].sexo);
                    printf("CPF: %s\n", listaProf[i].cpf);
                    printf("Data de nascimento: %d/%d/%d\n", listaProf[i].dataNascimento.dia,                             
                                                             listaProf[i].dataNascimento.mes, 
                                                             listaProf[i].dataNascimento.ano);
                }
            }
        }
        else if(sexo == 'F' || sexo == 'f'){
            for(int i = 0; i < contProf; i++){
                if(listaProf[i].sexo == 'F' || listaProf[i].sexo == 'f'){
                    printf("\nMatricula: %d\n", listaProf[i].matricula);
                    printf("Nome: %s\n", listaProf[i].nome);
                    printf("Sexo: %c\n", listaProf[i].sexo);
                    printf("CPF: %s\n", listaProf[i].cpf);
                    printf("Data de nascimento: %d/%d/%d\n", listaProf[i].dataNascimento.dia,                             
                                                             listaProf[i].dataNascimento.mes, 
                                                             listaProf[i].dataNascimento.ano);
                }
            }
        }
        else{
            printf("Sexo digitado errado\n");
        }
    }
}
void listarProfessoresOrdenadosPorNome(Professor listaProf[], int contProf){
    printf("--------------------------------------------------\n");
    printf("Alunos Ordenados por Nome\n");
    if(contProf == 0){
        printf("Lista de alunos vazia\n");
    } 
    else{

        bubbleSortPorNome(listaProf, contProf);


        for(int i = 0; i < contProf; i++){
            printf("\nMatricula: %d\n", listaProf[i].matricula);
            printf("Nome: %s\n", listaProf[i].nome);
            printf("Sexo: %c\n", listaProf[i].sexo);
            printf("CPF: %s\n", listaProf[i].cpf);
            printf("Data de nascimento: %d/%d/%d\n", listaProf[i].dataNascimento.dia,                             
                                                     listaProf[i].dataNascimento.mes, 
                                                     listaProf[i].dataNascimento.ano);
        }
    }
}
void listarProfessoresOrdenadosPorDataNascimento(Professor listaProf[], int contProf){
    printf("--------------------------------------------------\n");
    printf("Professores Ordenados por Data de Nascimento\n");
    if(contProf == 0){
        printf("Lista de professores vazia\n");
    } 
    else{
        
        bubbleSortPorDataNascimento(listaProf, contProf);

        for(int i = 0; i < contProf; i++){
            printf("\nMatricula: %d\n", listaProf[i].matricula);
            printf("Nome: %s\n", listaProf[i].nome);
            printf("Data de nascimento: %d/%d/%d\n", listaProf[i].dataNascimento.dia,                             
                                                     listaProf[i].dataNascimento.mes, 
                                                     listaProf[i].dataNascimento.ano);    
        }
    }
}
void listarAniversariantesMes(Professor listaProf[], int contProf, int mes, int contAluno, Aluno listaAluno[]){
    printf("--------------------------------------------------\n");
    printf("Aniversariantes do Mes\n");
    if(contProf == 0 && contAluno == 0){
        printf("Lista de professores vazia\n");
    } 
    else{
        for(int i = 0; i < contProf; i++){
            if(listaProf[i].dataNascimento.mes == mes) {
                printf("\nMatricula: %d\n", listaProf[i].matricula);
                printf("Nome: %s\n", listaProf[i].nome);
                printf("Data de Nascimento: %d/%d/%d\n", listaProf[i].dataNascimento.dia,
                                                         listaProf[i].dataNascimento.mes, 
                                                         listaProf[i].dataNascimento.ano);
            }
        }
        for(int i = 0; i < contAluno; i++){
            if(listaAluno[i].dataNascimento.mes == mes) {
                printf("\nMatricula: %d\n", listaAluno[i].matricula);
                printf("Nome: %s\n", listaAluno[i].nome);
                printf("Data de Nascimento: %d/%d/%d\n", listaAluno[i].dataNascimento.dia,
                                                         listaAluno[i].dataNascimento.mes, 
                                                         listaAluno[i].dataNascimento.ano);
            }
        }
    }
}
void listarPessoasPorBusca(Professor listaProf[], int contProf, char busca[], int contAluno, Aluno listaAluno[]){
    printf("--------------------------------------------------\n");
    printf("Resultado da Busca: %s\n", busca);
    if(contProf == 0 && contAluno == 0){
        printf("Lista de pessoas vazia\n");
    } else{
        int encontrou = 0;
        for(int i = 0; i < contProf; i++){
            if(strstr(listaProf[i].nome, busca) != NULL){
                printf("\nMatricula: %d\n", listaProf[i].matricula);
                printf("Nome: %s\n", listaProf[i].nome);
                encontrou = 1;
            }
        }
        for(int i = 0; i < contAluno; i++){
            if(strstr(listaAluno[i].nome, busca) != NULL){
                printf("\nMatricula: %d\n", listaAluno[i].matricula);
                printf("Nome: %s\n", listaAluno[i].nome);
                encontrou = 1;
            }
        }
        if(!encontrou){
            printf("Nenhuma pessoa encontrada com %s\n", busca);
        }
    }
}
void listarAlunosMenosTresDisciplinas(Aluno listaAluno[], int contAluno){
    printf("--------------------------------------------------\n");
    printf("\nAlunos Matriculados em Menos de 3 Disciplinas:\n");
    if(contAluno == 0){
        printf("\nLista vazia ou disciplina sem matricula de alunos\n");
    }
    for(int i = 0; i < contAluno; i++){
        if(listaAluno[i].contMatriculado < 3){
            printf("\nMatricula: %d\n", listaAluno[i].matricula);
            printf("Nome: %s\n", listaAluno[i].nome);
            printf("Sexo: %c\n", listaAluno[i].sexo);
            printf("CPF: %s\n", listaAluno[i].cpf);
            printf("Data de nascimento: %d/%d/%d\n", listaAluno[i].dataNascimento.dia,                             
                                                     listaAluno[i].dataNascimento.mes, 
                                                     listaAluno[i].dataNascimento.ano);
        }

    }
    
}
void listarDisciplinasExcedentes(Disciplina listaDisc[], int contDisc, Professor listaProf[], int contProf){
    printf("\nDisciplinas com Mais de 40 Vagas\n");
    if(contDisc == 0 || contProf == 0){
        printf("Lista de disciplinas ou de professores vazia\n");
    } 
    else{
        int achou = 0;
        for(int i = 0; i < contDisc; i++){
            if(listaDisc[i].contador > 40){
                printf("Nome da Disciplina: %s\n", listaDisc[i].nome);
                printf("Vagas: %d\n", listaDisc[i].contador);
                for(int j = 0; j < contProf; j++){
                    if(listaProf[j].matricula == listaDisc[i].matriculaProf){
                        printf("Nome do Professor: %s\n", listaProf[j].nome);
                        break;
                    }
                }
                achou = 1;
            }
        }

     if(!achou){
            printf("Nenhuma disciplina com mais de 40 vagas.\n");
        }
    }
}




