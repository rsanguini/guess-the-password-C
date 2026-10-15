#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main()
    {
    setlocale(LC_ALL,"portuguese");
    int c,n1,n2,n3,n4,x,x1,x2,x3,x4,tentativa,acertos=0,aux,j;
    int fix1 = -1, fix2 = -1, fix3 = -1, fix4 = -1;

    do{
    srand(time(NULL));
    int n=(rand()%9000)+1000;
    n4=n%10;
    n3=(n/10)%10;
    n2=(n/100)%10;
    n1=(n/1000)%10;

        
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
    
    for(tentativa=1;tentativa<=10;tentativa++)
        {
        system("cls");
        printf("%d",n);
        while(1)
            {
            printf("\t\t\t\t\t\tTentiva %d de 10:\n",tentativa);
            printf("------------------------------------------------------------------------------------------------------------------------");
            printf("\n\t*!!Lembre-se que a senha é composta por um número entre 1000 e 9999!!*\n\n");
            printf("\n\t-->Digite uma tentativa de senha: ",x);
            if (scanf("%d",&x)!=1)
                {
                printf("\nNúmero inválido.\nDigite novamente.\n\n");
                while (getchar() != '\n');
                    {
                    getch();
                    system("cls");
                    }
                }
            else if(x<1000||x>9999)
                {
                printf("\nNúmero inválido.\nDigite novamente.\n\n");
                }
            else
                {
                break;
                }
            }
        x4=x%10;
        x3=(x/10)%10;
        x2=(x/100)%10;
        x1=(x/1000)%10;

        printf("\n\t\tSENHA: ");

        if(x1==n1 || fix1 != -1)
            {
            fix1 = n1;
            printf("\t%d \t",fix1);
            }
        else
            {
            printf("\t\t\t __\t");
            }
        if(x2==n2 || fix2 != -1)
            {
            fix2 = n2;
            printf("%d \t",fix2);
            }
        else
            {
            printf(" __ \t");
            }
        if(x3==n3 || fix3 != -1)
            {
            fix3 = n3;
            printf("%d \t",fix3);
            }
        else
            {
            printf("__ \t");
            }
        if(x4==n4 || fix4 != -1)
            {
            fix4 = x4;
            printf("%d \t",fix4);
            }
        else
            {
            printf("__ \t");
            }

            int acertos = 0;
            if (fix1 != -1) acertos++;
            if (fix2 != -1) acertos++;
            if (fix3 != -1) acertos++;
            if (fix4 != -1) acertos++;

        if(acertos!=4)
        {
            printf("\n\n-----------------------------------------------------------------------------------------------------------------------");
            printf("\n\n\t-->Você acertou %d dígito(s)",acertos);
            printf("\n\n\t-->Continue tentando!!\n\n\n");
        }
        }
        }while(j==1);
            
  return 0;
}
