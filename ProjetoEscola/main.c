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
//no struc disciplina colocar 'int matriculaProfessor' no lugar de 'Professor prof', porque se usar da segunda maneira tera informacoes repetidas
//use listaProf[] quando for imprimir o nome do professor
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
int inserirAlunoDisciplina(int contDisc, Disciplina listaDisc[], int contAluno, Aluno listaAluno[], int posicaoDisc);
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
    for(int i = 0; i < TamDisc; i++){
        listaDisc[i].contador = 0;
    }

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
                                printf("Matricula invalida, numero digitado incorreto ou numero de matricula ja existente\n");
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
                                printf("Matricula invalida\n");
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
                                printf("Matricula invalida, numero digitado incorreto ou numero de matricula ja existente\n");
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
                int opcaoDisciplina;

                do{
                    opcaoDisciplina = menuDisciplina();


                    switch(opcaoDisciplina){

                        case 0:

                            printf("Voltando...\n");
                            break;

                        case 1:
                            int retorno = cadastrarDisciplina(contDisc, listaDisc, contProf, listaProf);
                            if(retorno == LISTA_CHEIA)
                                printf("Lista de disciplinas cheia\n");
                            else if(retorno == MATRICULA_INVALIDA)
                                printf("Codigo invalido, numero digitado incorreto ou codigo ja existente para outra disciplina\n");
                            else if(retorno == MATRICULA_INEXISTENTE){
                                printf("Esse professor nao foi cadastrado\n");
                            }
                            else{
                                printf("Disciplina cadastrada com sucesso\n");
                                contDisc++;
                            }
                            break;

                        case 2:
                            listarDisciplina(contDisc, listaDisc, contProf, listaProf);
                            break;

                        case 3:
                            retorno = atualizarDisciplina(contDisc, listaDisc, contProf, listaProf);
                            if(retorno == MATRICULA_INVALIDA){
                                printf("Codigo invalido\n");
                            }
                            else if(retorno == MATRICULA_INEXISTENTE){
                                printf("Codigo inexistente\n");
                            }
                            else{
                                printf("Disciplina atualizada com sucesso\n");
                            }

                            break;

                        case 4:
                            retorno = excluirDisciplina(contDisc, listaDisc, contProf, listaProf);
                            if(retorno == MATRICULA_INVALIDA){
                                printf("Matricula invalida\n");
                            }
                            else if(retorno == EXCLUSAO_SUCESSO){
                                printf("Professor excluido com sucesso\n");
                                contDisc--;
                            }
                            else{
                                printf("Matricula Inexistente\n");
                            }
                            break;
                        case 5:
                            retorno = inserirAlunoDisciplina(contDisc, listaDisc, contAluno, listaAluno, posicaoDisc);                
                            if(retorno == MATRICULA_INVALIDA)
                                printf("Matricula invalida\n");
                            else if(retorno == MATRICULA_INEXISTENTE){
                                printf("Esse Aluno nao foi cadastrado\n");
                            }
                            else if(retorno == CODIGO_INVALIDO){
                                printf("Codigo da disciplina digitado errado\n");
                            }
                            else{
                                printf("Aluno cadastrado na disciplina com sucesso\n");
                                listaDisc[posicaoDisc].contador++;
                            }
                            break;
                        case 6:
                            retorno = excluirAlunoDisciplina(contDisc, listaDisc, posicaoDisc);
                            if(retorno == MATRICULA_INVALIDA){
                                printf("Matricula invalida\n");
                            }
                            else if(retorno == EXCLUSAO_SUCESSO){
                                printf("Aluno excluido da disciplina com sucesso\n");
                                listaDisc[posicaoDisc].contador--;
                            }
                            else{
                                printf("Matricula Inexistente\n");
                            }
                            break;
                            break;
                        default:

                            printf("Opção Inválida\n");
                            break;

                        }

                    }while(opcaoDisciplina != 0);
                break;
            case 4:
                printf("Relatorio\n");
                int opcaoRelatorio;
            do{
                opcaoRelatorio = menuRelatorio();
                switch(opcaoRelatorio){

                    case 0:

                        printf("Voltando...\n");
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
                        break;
                    case 9:
                        break;
                    case 10:
                        break;                
                    case 11:
                        break;
                    default:
                        printf("Opção Inválida\n");
                        break;

                }

            }while(opcaoRelatorio != 0);
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
    printf("4 - Relatorios\n");
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
        scanf(" %c", &sexo);
        getchar();
        printf("Digite o CPF:\n");
        fgets(cpf, 20, stdin);
        tamString = strlen(cpf) -1;
        cpf[tamString] = '\0';
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
    printf("Listando Aluno...\n");

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
                printf("Data de nascimento: %d/%d/%d\n", listaAluno[i].dataNascimento.dia, listaAluno[i].dataNascimento.mes,                                 listaAluno[i].dataNascimento.ano);

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
            getchar();
            printf("Digite o novo nome:\n");
            char novoNome[50];
            fgets(novoNome, 50, stdin);
            int tamString = strlen(novoNome) -1;
            novoNome[tamString] = '\0';
            getchar();
            printf("Digite o novo CPF:\n");
            char novoCpf[20];
            fgets(novoCpf, 20, stdin);
            tamString = strlen(novoCpf) -1;
            novoCpf[tamString] = '\0';
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
        scanf(" %c", &sexo);
        getchar();
        printf("Digite o CPF:\n");
        fgets(cpf, 20, stdin);
        tamString = strlen(cpf) -1;
        cpf[tamString] = '\0';

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
    printf("Listando Professor...\n");

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
                printf("Data de nascimento: %d/%d/%d\n", listaProf[i].dataNascimento.dia, listaProf[i].dataNascimento.mes,                                 listaProf[i].dataNascimento.ano);

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
            getchar();
            printf("Digite o novo nome:\n");
            char novoNome[50];
            fgets(novoNome, 50, stdin);
            int tamString = strlen(novoNome) -1;
            novoNome[tamString] = '\0';
            getchar();
            printf("Digite o novo CPF:\n");
            char novoCpf[20];
            fgets(novoCpf, 20, stdin);
            tamString = strlen(novoCpf) -1;
            novoCpf[tamString] = '\0';
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
// DISCIPLINA
int menuDisciplina(){
    int opcaoDisciplina;
    printf("0 - Voltar\n");
    printf("1 - Cadastrar Disciplina\n");
    printf("2 - Listar Disciplina\n");
    printf("3 - Atualizar Disciplina\n");
    printf("4 - Excluir Disciplina\n");
    printf("5 - Inserir aluno em alguma Disciplina\n");
    printf("6 - Excluir aluno em alguma Disciplina\n");
    scanf("%d", &opcaoDisciplina);
    return opcaoDisciplina;
}
int cadastrarDisciplina(int contDisc, Disciplina listaDisc[], int contProf, Professor listaProf[]){
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
        printf("Digite o codigo:\n");  
        scanf("%d", &codigo);
        for(int i = 0; i < contDisc; i++){
            if(codigo == listaDisc[i].codigo){
                return MATRICULA_INVALIDA;
                break;
            }
        }
        getchar();
        printf("Digite o nome:\n");
        fgets(nome, 50, stdin);
        int tamString = strlen(nome) -1;
        nome[tamString] = '\0';
        printf("Digite o semestre da disciplina:");
        scanf("%d", &semestre);
        printf("Digite a matricula do professor:\n");
        scanf("%d", &matricula);
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
                return MATRICULA_INVALIDA;
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
    printf("Listando Disciplinas...\n");

    if(contDisc == 0){
        printf("Lista vazia\n");
    }
    else{
        for(int i = 0; i < contDisc; i++){
            if(listaDisc[i].ativo == 1){
                printf("Disciplina %d:\n", i+1);
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
    printf("Atualizando Disciplina...\n");
    printf("Digite o codigo\n");
    int codigo;
    scanf("%d", &codigo);
    int achou = 0;
    if(codigo < 0){
        return MATRICULA_INVALIDA;
    }
    for(int i = 0; i < contDisc; i++){
        if(listaDisc[i].codigo == codigo && listaDisc[i].ativo){
            printf("Digite o novo codigo:\n");
            int novaCodigo;
            scanf("%d", &novaCodigo);
            getchar();
            printf("Digite o novo nome:\n");
            char novoNome[50];
            fgets(novoNome, 50, stdin);
            int tamString = strlen(novoNome) -1;
            novoNome[tamString] = '\0';
            printf("Digite o novo semestre:\n");
            int novoSemestre;
            scanf("%d", &novoSemestre);
            getchar();
            printf("Digite a nova matricula do professor:\n");
            int novaMatricula;
            scanf("%d", &novaMatricula);
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
int excluirDisciplina(int contDisc, Disciplina listaDisc[], int contProf, Professor listaProf[]){
    printf("Excluindo Disciplina...\n");
    int codigo;
    printf("Digite o codigo\n");
    scanf("%d", &codigo);
    int achou = 0;
    if(codigo < 0){
        return MATRICULA_INVALIDA;
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
int inserirAlunoDisciplina(int contDisc, Disciplina listaDisc[], int contAluno, Aluno listaAluno[], int posicaoDisc){
    printf("Inserindo Aluno...\n");
    int matricula;
    printf("Digite a matricula\n");
    scanf("%d", &matricula);
    printf("Digite o codigo da disciplina\n");
    int codigo;
    scanf("%d", &codigo);
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
int excluirAlunoDisciplina(int contDisc, Disciplina listaDisc[], int posicaoDisc){
    printf("Excluindo Aluno da Disciplina...\n");
    int matricula;
    printf("Digite a matricula\n");
    scanf("%d", &matricula);
    printf("Digite o codigo da disciplina\n");
    int codigo;
    scanf("%d", &codigo);
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
//RELATORIO
int menuRelatorio(){
    int opcaoRelatorio;
    printf("0 - Voltar\n");
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
    scanf("%d", &opcaoRelatorio);
    return opcaoRelatorio;
}
void listarUmaDisc(int contDisc, Disciplina listaDisc[], int posicaoDisc, Professor listaProf[], int contProf){
    printf("Listando uma Disciplina especifica...\n");
    printf("Digite o codigo da disciplina\n");
    int codigo;
    scanf("%d", &codigo);
    if(contDisc == 0){
        printf("Lista vazia\n");
    }
    else{
        for(int j = 0; j < contDisc; j++){
        if(codigo == listaDisc[j].codigo){
            posicaoDisc = j;
            break;
        }
        }
        if(listaDisc[posicaoDisc].ativo == 1){           
            printf("Codigo: %d\n", listaDisc[posicaoDisc].codigo);
            printf("Nome: %s\n", listaDisc[posicaoDisc].nome);
            printf("Semestre: %d\n", listaDisc[posicaoDisc].semestre);
            for(int j = 0; j < contProf; j++){
                if(listaDisc[posicaoDisc].matriculaProf == listaProf[j].matricula){
                    printf("Professor: %s\n", listaProf[j].nome);
                }
            }
            printf("Alunos Matriculados:\n");
            for(int i = 0; i < listaDisc[posicaoDisc].contador; i++){
                printf("Aluno %d: %s\n", i+1, listaDisc[posicaoDisc].alunos[i].nome);
            }
        }

    }
}
void listarAlunosPsexo(int contAluno, Aluno listaAluno[]){
    printf("Listando alunos por sexo(M/F)\n");
    printf("Digite o sexo\n");
    char sexo;
    scanf(" %c", &sexo);
    if(contAluno == 0){
        printf("Lista vazia\n");
    }
    else{
        if(sexo == 'M' || sexo == 'm'){
            for(int i = 0; i < contAluno; i++){
                if(listaAluno[i].sexo == 'M' || listaAluno[i].sexo == 'm'){
                    printf("%s\n", listaAluno[i].nome);
                }
            }
        }
        else if(sexo == 'F' || sexo == 'f'){
            for(int i = 0; i < contAluno; i++){
                if(listaAluno[i].sexo == 'F' || listaAluno[i].sexo == 'f'){
                    printf("%s\n", listaAluno[i].nome);
                }
            }
        }
        else{
            printf("Sexo digitado errado\n");
        }
    }
}
void bubbleSortPorNome(Aluno listaAluno[], int contAluno){
    for (int i = 0; i < contAluno - 1; i++) {
        for (int j = 0; j < contAluno - i - 1; j++) {
            if (strcmp(listaAluno[j].nome, listaAluno[j + 1].nome) > 0) {
                Aluno temp = listaAluno[j];
                listaAluno[j] = listaAluno[j + 1];
                listaAluno[j + 1] = temp;
            }
        }
    }
}


void listarAlunosOrdenadosPorNome(Aluno listaAluno[], int contAluno){
    printf("\nAlunos Ordenados por Nome\n");
    if (contAluno == 0) {
        printf("Lista de alunos vazia\n");
    } 
    else{
        
        bubbleSortPorNome(listaAluno, contAluno);

        
        for (int i = 0; i < contAluno; i++) {
            printf("%s\n", listaAluno[i].nome);
        }
    }
}
void bubbleSortPorDataNascimento(Aluno listaAluno[], int contAluno){
    for (int i = 0; i < contAluno - 1; i++) {
        for (int j = 0; j < contAluno - i - 1; j++) {
            if (listaAluno[j].dataNascimento.ano > listaAluno[j + 1].dataNascimento.ano ||
                (listaAluno[j].dataNascimento.ano == listaAluno[j + 1].dataNascimento.ano &&
                listaAluno[j].dataNascimento.mes > listaAluno[j + 1].dataNascimento.mes) ||
                (listaAluno[j].dataNascimento.ano == listaAluno[j + 1].dataNascimento.ano &&
                listaAluno[j].dataNascimento.mes == listaAluno[j + 1].dataNascimento.mes &&
                listaAluno[j].dataNascimento.dia > listaAluno[j + 1].dataNascimento.dia)) {
                Aluno temp = listaAluno[j];
                listaAluno[j] = listaAluno[j + 1];
                listaAluno[j + 1] = temp;
            }
        }
    }
}
void listarAlunosOrdenadosPorDataNascimento(Aluno listaAluno[], int contAluno){
    printf("\nAlunos Ordenados por Data de nascimento\n");
    if (contAluno == 0) {
        printf("Lista de alunos vazia\n");
    } 
    else{

        bubbleSortPorDataNascimento(listaAluno, contAluno);


        for (int i = 0; i < contAluno; i++) {
            printf("%s\n", listaAluno[i].nome);
        }
    }
}
void listarProfessorPsexo(int contProf, Professor listaProf[]){
    printf("Listando Professores por sexo(M/F)\n");
    printf("Digite o sexo\n");
    char sexo;
    scanf(" %c", &sexo);
    if(contProf == 0){
        printf("Lista vazia\n");
    }
    else{
        if(sexo == 'M' || sexo == 'm'){
            for(int i = 0; i < contProf; i++){
                if(listaProf[i].sexo == 'M' || listaProf[i].sexo == 'm'){
                    printf("%s\n", listaProf[i].nome);
                }
            }
        }
        else if(sexo == 'F' || sexo == 'f'){
            for(int i = 0; i < contProf; i++){
                if(listaProf[i].sexo == 'F' || listaProf[i].sexo == 'f'){
                    printf("%s\n", listaProf[i].nome);
                }
            }
        }
        else{
            printf("Sexo digitado errado\n");
        }
    }
}
void listarProfessoresOrdenadosPorNome(Professor listaProf[], int contProf){
    printf("\nAlunos Ordenados por Nome\n");
    if (contProf == 0) {
        printf("Lista de alunos vazia\n");
    } 
    else{

        bubbleSortPorNome(listaProf, contProf);


        for (int i = 0; i < contProf; i++) {
            printf("%s\n", listaProf[i].nome);
        }
    }
}
void listarProfessoresOrdenadosPorDataNascimento(Professor listaProf[], int contProf){
    printf("\nProfessores Ordenados por Data de Nascimento\n");
    if (contProf == 0) {
        printf("Lista de professores vazia\n");
    } 
    else {
        // Ordena os professores por data de nascimento
        bubbleSortPorDataNascimento(listaProf, contProf);

        // Lista os professores ordenados
        for (int i = 0; i < contProf; i++) {
            printf("%s\n", listaProf[i].nome);    
        }
    }
}
