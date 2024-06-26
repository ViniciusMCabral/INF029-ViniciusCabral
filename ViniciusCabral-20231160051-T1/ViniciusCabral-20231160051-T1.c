// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Vinicius Machak Cabral
//  email: vmachakcabral@gmail.com
//  Matrícula: 20231160051
//  Semestre: 2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include "ViniciusCabral-20231160051-T1.h" 
#include <string.h>
#include <stdlib.h>

DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
  char sMes[3];
  char sAno[5];
  int i; 

  for (i = 0; data[i] != '/'; i++){
    sDia[i] = data[i];	
  }
  if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
    sDia[i] = '\0';  // coloca o barra zero no final
  }else {
    dq.valido = 0;
    return dq;
  }  


  int j = i + 1; //anda 1 cada para pular a barra
  i = 0;

  for (; data[j] != '/'; j++){
    sMes[i] = data[j];
    i++;
  }

  if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
    sMes[i] = '\0';  // coloca o barra zero no final
  }else {
    dq.valido = 0;
    return dq;
  }


  j = j + 1; //anda 1 cada para pular a barra
  i = 0;

  for(; data[j] != '\0'; j++){
    sAno[i] = data[j];
    i++;
  }

  if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
    sAno[i] = '\0';  // coloca o barra zero no final
  }else {
    dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

  dq.valido = 1;

  return dq;
}
/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[]) {
    DataQuebrada dq = quebraData(data);

    if(!dq.valido) {
        return 0;
    }

    int iDia = dq.iDia;
    int iMes = dq.iMes;
    int iAno = dq.iAno;
    
    if(iAno < 1){
        return 0;
    }

    if(iMes < 1 || 
        iMes > 12){
        return 0;
    }


    if(iDia < 1 || 
        iDia > 31){
        return 0;
    }

    if((iMes == 4 || 
        iMes == 6 || 
        iMes == 9 || 
        iMes == 11) && 
        iDia > 30){
        return 0;
    }
    if(iMes == 2){
        int bissexto = ((iAno % 4 == 0) && 
        (iAno % 100 != 0)) || 
        (iAno % 400 == 0);
        if((bissexto && iDia > 29) || 
            (!bissexto && iDia > 28)){
            return 0;
        }
    }
    return 1;
}



/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[]) {
    DiasMesesAnos dma;

    if(q1(datainicial) == 0) {
        dma.retorno = 2;
        return dma;
    }
    if(q1(datafinal) == 0) {
        dma.retorno = 3;
        return dma;
    }

    DataQuebrada dqInicial = quebraData(datainicial);
    DataQuebrada dqFinal = quebraData(datafinal);

    int iDiainicial = dqInicial.iDia;
    int iMesinicial = dqInicial.iMes;
    int iAnoinicial = dqInicial.iAno;

    int iDiafinal = dqFinal.iDia;
    int iMesfinal = dqFinal.iMes;
    int iAnofinal = dqFinal.iAno;

    if(iAnoinicial > iAnofinal ||
        (iAnoinicial == iAnofinal && iMesinicial > iMesfinal) ||
        (iAnoinicial == iAnofinal && iMesinicial == iMesfinal && iDiainicial > iDiafinal)) {
        dma.retorno = 4;
        return dma;
    }

    dma.qtdAnos = iAnofinal - iAnoinicial;
    dma.qtdMeses = iMesfinal - iMesinicial;
    dma.qtdDias = iDiafinal - iDiainicial;

    if(dma.qtdDias < 0) {
        int diasMesAnterior = 0;
        if(iMesinicial == 1) {
            diasMesAnterior = 31;
        } else if(iMesinicial == 2) {
            if((iAnoinicial % 4 == 0 && iAnoinicial % 100 != 0) || (iAnoinicial % 400 == 0)) {
                diasMesAnterior = 28;
            } else{
                diasMesAnterior = 27;
            }
            if(iMesfinal == 3) {
                if((iAnofinal % 4 == 0 && iAnofinal % 100 != 0) || (iAnofinal % 400 == 0)) {
                    diasMesAnterior = 29;
                } else{
                    diasMesAnterior = 28;
                }
            }
        } else if(iMesinicial == 3 || iMesinicial == 5 || iMesinicial == 7 || iMesinicial == 8 || iMesinicial == 10 || iMesinicial == 12) {
            diasMesAnterior = 31;
        } else{
            diasMesAnterior = 30;
        }
        dma.qtdDias += diasMesAnterior;
        dma.qtdMeses--;
        if(dma.qtdMeses < 0) {
            dma.qtdMeses += 12;
            dma.qtdAnos--;
        }
    }

    dma.retorno = 1; 
    return dma;
}


/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive) {
    int qtdOcorrencias = 0;
    char textoCopia[strlen(texto) + 1]; 

        strcpy(textoCopia, texto); 
    
    if(!isCaseSensitive) {    
        for(int i = 0; textoCopia[i] != '\0'; i++) {
            if(c >= 'a' && c     <= 'z') {
                if(textoCopia[i] >= 'A' && textoCopia[i] <= 'Z') {
                    textoCopia[i] = textoCopia[i] + 32;
                }    
            }    
            else {    
                if(textoCopia[i] >= 'a' && textoCopia[i] <= 'z') {
                        textoCopia[i] = textoCopia[i] - 32;
                    }
                }
                
            }
    
        for(int i = 0; textoCopia[i] != '\0'; i++) {
            if(c == textoCopia[i]) {
                qtdOcorrencias++;
            }    
        }    
    } else {    
        for(int i = 0; texto[i] != '\0'; i++) { 
            if(c == texto[i]) { 
                qtdOcorrencias++;
                }
            }
        }
    
    return qtdOcorrencias;
}    
    
/*    
 Q4 = encontra    r palavra em texto
 @objetivo    
    Pesquisar     todas as ocorrências de uma palavra em um texto
 @entrada    
    uma string     texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (st    rBusca) no texto base (texto).
 @saida    
    Um número n >= 0 correspondente a quantid    ade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido     com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do     texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas pos    ições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busc    a no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;    
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *texto, char *strBusca, int *posicoes) {
    int qtdOcorrencias = 0;
    int textoTam = strlen(texto);
    int buscaTam = strlen(strBusca);
    int i, j, k;

    for(i = 0; i <= textoTam - buscaTam; i++) {
        for(j = 0, k = i; j < buscaTam && texto[k] == strBusca[j]; j++, k++);
        
        if(j == buscaTam) {
            qtdOcorrencias++;
            posicoes[2 * (qtdOcorrencias - 1)] = i + 1;
            posicoes[2 * (qtdOcorrencias - 1) + 1] = i + buscaTam;

            i = k - 1;
        }
    }

    return qtdOcorrencias;
}
/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */                                

int q5(int num) {    
    int invertido = 0;

    while(num != 0) {
        int digito = num % 10;
        invertido = invertido * 10 + digito;
        num /= 10;
    }
    num = invertido;
    return num;
}

                                                                                                                                    
/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca) {
    int qtdOcorrencias = 0;
    int temp = numerobase;
    
    while(temp > 0) {   
        if(temp % 10 == numerobusca) {
            qtdOcorrencias++;
        }
        temp /= 10;
    }
    
    return qtdOcorrencias;
}