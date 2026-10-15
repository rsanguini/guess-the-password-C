#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main()
    {
    setlocale(LC_ALL,"portuguese");
    int c,n1,n2,n3,n4,x,x1,x2,x3,x4,tentativa,acertos=0,aux,j;
    int fix1 = -1, fix2 = -1, fix3 = -1, fix4 = -1;

    do
    {
    system("cls");
    printf("\n\t\t\t\t--SEJA BEM VINDO AO JOGO DA ADIVINHAÇÃO!!!!--");
    printf("\n------------------------------------------------------------------------------------------------------------------------");
    printf("\n\n\t -Como funciona o jogo??");
    printf("\n\n\t\t-->Este é o jogo onde você terá o objetivo de adivinhar uma senha aleatória que contém quatro dígitos(ou seja, está entre 1000 e 9999), em apenas 10 tentativas!!!\n\n\n");
    printf("------------------------------------------------------------------------------------------------------------------------");
    printf("\n\n\t -Você deseja jogar???");
    printf("\n\n\t\t -->Digite (1) para começar e (2) para sair: ");
    scanf("%d",&c);
    if(c==2)
    {
        system("cls");
        printf("\n\n\t\n\n\n \t\t\t\t\t\tOBRIGADO!!!");
    printf("\n\n\t\n\n\n \t\t ---->Reinicie o programa caso voc� queira jogar mais tarde!!\n\n\n\n\n\n\n");
        exit(0);
    }
    }while(c!=1);
      
  return 0;
}
