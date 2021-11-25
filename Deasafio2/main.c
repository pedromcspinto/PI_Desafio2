#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define BACKSPACE 8
#define ENTER 13
#define PONTO 46

/**
    Pedro Pinto
    n� A22000888
    Programa��o imperativa

    NOTA:
    N�o consegui concluir a inser��o de dados decimais
 */

int minuscula(char c);
int maiuscula(char c);
int inteiro(char c);
int especial(char c);
int tudo(char c);
int existePonto(char*s);
void addCh(char*s, char c, int*ptr);
void delCh(char*s,int*ptr);
void clearString(char*string);
void menu();
void menu1();
void menu2();
int naoNumerico(char op, char c);
int numerico(char op, char c);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char c;
    int i, opcao, comp, dec;
    char *string;
    int*i_ptr=&i;

    do{
        i=0;
        menu();
        printf("Escolha uma op��o: "); scanf("%d", &opcao);
        if(opcao==0){
            system("CLS");
            printf("A encerrar...");
            break;
        }
        system("CLS");

        switch(opcao){
            case 1:
                    menu1();
                    printf("Escolha uma op��o: "); scanf("%d", &opcao);
                    printf("Comprimento: "); scanf("%d", &comp);
                    string=(char*)calloc(comp, sizeof(char));
                    clearString(string);
                    system("CLS");
                    printf("Escreva um caracter: ");
                    do{
                        c=getche();
                            if(naoNumerico(opcao,c)){
                                addCh(string,c,i_ptr);
                            }else if(c==BACKSPACE && *i_ptr!=0){
                                delCh(string,i_ptr);
                                system("CLS");
                                printf("Escreva um caracter: %s", string);
                            }else if(c==ENTER){
                                break;
                            }else{
                                system("CLS");
                                printf("Escreva um caracter: %s", string);
                            }
                    }while(*i_ptr<comp);
                    printf("\n\nResultado final � %s �\n", string);
                break;

            case 2:
                    menu2();
                    printf("Escolha uma op��o: "); scanf("%d", &opcao);
                    if(opcao==1){
                            system("CLS");
                            printf("Comprimento: "); scanf("%d", &comp);
                            string=(char*)calloc(comp, sizeof(char));
                            clearString(string);
                            system("CLS");
                            printf("Escreva um caracter: ");
                            do{
                                c=getche();
                                    if(numerico(opcao,c)){
                                        addCh(string,c,i_ptr);
                                    }else if(c==BACKSPACE && *i_ptr!=0){
                                        delCh(string,i_ptr);
                                        system("CLS");
                                        printf("Escreva um caracter: %s", string);
                                    }else if(c==ENTER){
                                        break;
                                    }else{
                                        system("CLS");
                                        printf("Escreva um caracter: %s", string);
                                    }
                            }while(*i_ptr<comp);
                        printf("\n\nResultado final � %s �\n", string);
                    }else{
                        system("CLS");
                        printf("Comprimento: "); scanf("%d", &comp);
                        string=(char*)calloc(comp, sizeof(char));
                        clearString(string);
                        do{
                        printf("Numero de casas decimais: "); scanf("%d", &dec);
                        }while(dec>=comp-1);
                        system("CLS");
                         printf("Escreva um caracter: ");
                        do{
                            c=getche();
                                if(numerico(opcao,c)){
                                    addCh(string,c,i_ptr);
                                }else if(c==BACKSPACE && *i_ptr!=0){
                                    delCh(string,i_ptr);
                                    system("CLS");
                                    printf("Escreva um caracter: %s", string);
                                }else if(c==ENTER){
                                    break;
                                }else{
                                    system("CLS");
                                    printf("Escreva um caracter: %s", string);
                                }
                        }while(*i_ptr<comp);
                    printf("\n\nResultado final � %s �\n", string);
                    }
                break;
        }
    }while(opcao!=0);
}

/**
    fun��o que delimita os caracteres de letras min�sculas na tabela ASCII que se podem usar para adicionar � string
 */

int minuscula(char c){
    int found=0;

    if((c>=97 && c<=122)|| c==32)
    found=1;

    return found;
}

/**
    fun��o que delimita os caracteres de letras mai�sculas na tabela ASCII que se podem usar para adicionar � string
 */

int maiuscula(char c){
    int found=0;

    if((c>=65 && c<=90)|| c==32)
    found=1;

    return found;
}

/**
    fun��o que delimita os caracteres especiais na tabela ASCII que se podem usar para adicionar � string
 */


int especial(char c){
    int found=0;

    if((c>=33 && c<=47)|| (c>=58 && c<=64)
       || (c>=91 && c<=96) || (c>=123 && c<=126) || c==32)
    found=1;

    return found;
}

/**
    fun��o que delimita os numeros inteiros na tabela ASCII que se podem usar para adicionar � string
 */

int inteiro(char c){
    int found=0;

    if(c>=48 && c<=57)
    found=1;

    return found;
}

/**
    fun��o que delimita todos os caracteres da tabela ASCII que se podem usar para adicionar � string
 */

int tudo(char c){
    int found=0;

    if(c>=32 && c<=254)
    found=1;

    return found;
}

/**
    fun��o para detetar a exist�ncia de um ponto da string
 */

int existePonto(char*s){
    int found=1;
    if((strchr(s,'.')-s)<0)
        found=0;

    return found;
}

/**
    Adicionar um caracter a uma string, utilizando o apontador do indice da mesma
 */

void addCh(char*s, char c, int*ptr){
    int i=*ptr;
    s[i]=c;
    s[i+1]='\0';
    *ptr+=1;
}

/**
    Apagar um caracter a uma string, utilizando o apontador do indice da mesma
 */

void delCh(char*s,int*ptr){
    int i=*ptr;
    s[i-1]='\0';
    *ptr=*ptr-1;
}

/**
    limpeza de string
 */

void clearString(char*string){
    string[0]='\0';
}

/**
    menu inicial para escolher dados num�ricos e n�o num�ricos
 */

void menu(){
    printf("\n\t\t\t\t\t**********************************************\n");
    printf("\t\t\t\t\t\t  Rotina de Entrada de dados\n");
    printf("\t\t\t\t\t**********************************************\n");
    printf("\t\t\t\t\t  1- N�o num�rico\n\n");
    printf("\t\t\t\t\t  2- Num�rico\n\n");
    printf("\t\t\t\t\t  0- Sair\n");
    printf("\t\t\t\t\t**********************************************\n\n\n");
}

/**
    menu para escolher as limita��es dos dados n�o num�ricos
 */

void menu1(){
    printf("\n\t\t\t\t\t**********************************************\n");
    printf("\t\t\t\t\t\t  Rotina de Entrada de dados\n");
    printf("\t\t\t\t\t**********************************************\n");
    printf("\t\t\t\t\t  1- Letras Mai�sculas\n\n");
    printf("\t\t\t\t\t  2- Letras Min�sculas\n\n");
    printf("\t\t\t\t\t  3- Letras Mai�sculas e especiais\n\n");
    printf("\t\t\t\t\t  4- Letras Min�sculas e especiais\n\n");
    printf("\t\t\t\t\t  5- Letras Mai�sculas, Mai�sculas e N�meros\n\n");
    printf("\t\t\t\t\t  6- Letras Todos os caracteres\n\n");
    printf("\t\t\t\t\t**********************************************\n\n\n");
}

/**
    menu para escolher as limita��es dos dados num�ricos
 */

void menu2(){
    printf("\n\t\t\t\t\t**********************************************\n");
    printf("\t\t\t\t\t\t  Rotina de Entrada de dados\n");
    printf("\t\t\t\t\t**********************************************\n");
    printf("\t\t\t\t\t  1- N�meros Inteiros\n\n");
    printf("\t\t\t\t\t  2- Numeros Decimais\n\n");
    printf("\t\t\t\t\t**********************************************\n\n\n");
}

/**
    fun��o para escolher a limita��o de dados n�o num�ricos a entrar
 */

int naoNumerico(char op, char c){
    int res;
    switch(op){
        case 1: res=maiuscula(c); break;
        case 2: res=minuscula(c); break;
        case 3: res=(maiuscula(c) || especial(c)); break;
        case 4: res=(minuscula(c) || especial(c)); break;
        case 5: res=(maiuscula(c) || minuscula(c) || inteiro(c)); break;
        case 6: res=tudo(c); break;
    }
    return res;
}

/**
    fun��o para escolher a limita��o de dados num�ricos a entrar
 */

int numerico(char op, char c){
    int res;
    switch(op){
        case 1: res=inteiro(c); break;
        case 2: res=(inteiro(c) || c==PONTO); break;
    }
    return res;
}
