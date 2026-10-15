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

        if (tentativa >= 5 && tentativa != 10)
        {
            printf("\t------ DICAS ------\n\t");
            switch(tentativa)
            {
                case 5:
                if (fix1 == -1)
                    printf("-->Primeira dica: O primeiro n�mero � %s.\n\n\n", (n1 % 2 == 0) ? "par" : "�mpar");
                else if (fix2 == -1)
                    printf("-->Primeira dica: O segundo n�mero � %s.\n\n\n", (n2 % 2 == 0) ? "par" : "�mpar");
                else if (fix3 == -1)
                    printf("-->Primeira dica: O terceiro n�mero � %s.\n\n\n", (n3 % 2 == 0) ? "par" : "�mpar");
                else if (fix4 == -1)
                    printf("-->Primeira dica: O quarto n�mero � %s.\n\n\n", (n4 % 2 == 0) ? "par" : "�mpar");
                break;

                case 6:
                {
                int soma = n1 + n2 + n3 + n4;
                printf("-->Segunda dica: A soma dos d�gitos da senha � %d.\n\n", soma);
                break;
                }

                case 7:
                {
                int maior = n1;
                if (n2 > maior) maior = n2;
                if (n3 > maior) maior = n3;
                if (n4 > maior) maior = n4;
                printf("-->Terceira dica: O maior d�gito da senha � %d.\n\n", maior);
                break;
                }

                case 8:
                printf("-->Quarta dica: An�lise dos d�gitos ainda n�o descobertos:\n\t");
                if (fix1 == -1)
                printf("- O primeiro d�gito � %s que 5.\n\n\n", (n1 >= 5) ? "maior ou igual" : "menor");
                if (fix2 == -1)
                printf("- O segundo d�gito � %s que 5.\n", (n2 >= 5) ? "maior ou igual" : "menor");
                if (fix3 == -1)
                printf("- O terceiro d�gito � %s que 5.\n", (n3 >= 5) ? "maior ou igual" : "menor");
                if (fix4 == -1)
                printf("- O quarto d�gito � %s que 5.\n", (n4 >= 5) ? "maior ou igual" : "menor");
                break;

                case 9:
                if (n1 == n2 || n1 == n3 || n1 == n4 || n2 == n3 || n2 == n4 || n3 == n4)
                {
                    printf("-->Quinta dica: A senha cont�m d�gitos repetidos.\n");
                }
                else
                {
                    printf("-->Quinta dica: Todos os d�gitos da senha s�o diferentes.\n");
                }

                break;
            }
        }
        }
            else
            {
                printf("\n\n");
                printf("\n\n-----------------------------------------------------------------------------------------------------------------------");
                printf("\n\n\t\t\tPARAB�NS!! Voc� acertou a senha em %d tentativa(s)!!\n\n\n\n", tentativa);
                break;
            }

        printf("Pressione qualquer tecla para continuar\n\n");
        getch();
        }
        if (fix1 == -1 || fix2 == -1 || fix3 == -1 || fix4 == -1)
        {
            system("cls");
            printf("\n\n\n\t\t\tFim de jogo! O n�mero correto era %d.\n\n", n);
        }

    printf("Pressione qualquer tecla para continuar");
    getch();
    system("cls");
    printf("\n\n\n\t\t\tDeseja jogar novamente?\n\n");
    printf("\n\t\t\tDigite 1 para jogar novamente ou outro n�mero para encerrar: ",j);
    scanf("%d",&j);

    fix1 = fix2 = fix3 = fix4 = -1;
    system("cls");

    }while(j==1);

    printf("\n\n\n\t\t\tObrigado por jogar!\n\n\n");

    system ("pause");
    return 0;
}
