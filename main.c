#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <conio.h>

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
    printf("\n\t\t\t\t--SEJA BEM VINDO AO JOGO DA ADIVINHACAO!!!!--");
    printf("\n------------------------------------------------------------------------------------------------------------------------");
    printf("\n\n\t -Como funciona o jogo??");
    printf("\n\n\t\t-->Este e o jogo onde voce tera o objetivo de adivinhar uma senha aleatoria que contem quatro digitos(ou seja, esta entre 1000 e 9999), em apenas 10 tentativas!!!\n\n\n");
    printf("------------------------------------------------------------------------------------------------------------------------");
    printf("\n\n\t -Voce deseja jogar???");
    printf("\n\n\t\t -->Digite (1) para comecar e (2) para sair: ");
    scanf("%d",&c);
    if(c==2)
    {
        system("cls");
        printf("\n\n\t\n\n\n \t\t\t\t\t\tOBRIGADO!!!");
    printf("\n\n\t\n\n\n \t\t ---->Reinicie o programa caso voce queira jogar mais tarde!!\n\n\n\n\n\n\n");
        exit(0);
    }
    }while(c!=1);

    for(tentativa=1;tentativa<=10;tentativa++)
        {
        system("cls");
        //printf("%d",n);   ----> número gerado impresso na tela para fazer testes (basta adicionar ele no código para revelar e testar todos os comandos do código)
        while(1)
            {
            printf("\t\t\t\t\t\tTentiva %d de 10:\n",tentativa);
            printf("------------------------------------------------------------------------------------------------------------------------");
            printf("\n\t*!!Lembre-se que a senha e composta por um numero entre 1000 e 9999!!*\n\n");
            printf("\n\t-->Digite uma tentativa de senha: ",x);
            if (scanf("%d",&x)!=1)
                {
                printf("\nNumero invalido.\nDigite novamente.\n\n");
                while (getchar() != '\n');
                    {
                    _getch();
                    system("cls");
                    }
                }
            else if(x<1000||x>9999)
                {
                printf("\nNumero invalido.\nDigite novamente.\n\n");
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
            printf("\n\n\t-->Voce acertou %d digito(s)",acertos);
            printf("\n\n\t-->Continue tentando!!\n\n\n");

        if (tentativa >= 5 && tentativa != 10)
        {
            printf("\t------ DICAS ------\n\t");
            switch(tentativa)
            {
                case 5:
                if (fix1 == -1)
                    printf("-->Primeira dica: O primeiro numero e %s.\n\n\n", (n1 % 2 == 0) ? "par" : "impar");
                else if (fix2 == -1)
                    printf("-->Primeira dica: O segundo numero e %s.\n\n\n", (n2 % 2 == 0) ? "par" : "impar");
                else if (fix3 == -1)
                    printf("-->Primeira dica: O terceiro numero e %s.\n\n\n", (n3 % 2 == 0) ? "par" : "impar");
                else if (fix4 == -1)
                    printf("-->Primeira dica: O quarto numero e %s.\n\n\n", (n4 % 2 == 0) ? "par" : "impar");
                break;

                case 6:
                {
                int soma = n1 + n2 + n3 + n4;
                printf("-->Segunda dica: A soma dos digitos da senha e %d.\n\n", soma);
                break;
                }

                case 7:
                {
                int maior = n1;
                if (n2 > maior) maior = n2;
                if (n3 > maior) maior = n3;
                if (n4 > maior) maior = n4;
                printf("-->Terceira dica: O maior digito da senha e %d.\n\n", maior);
                break;
                }

                case 8:
                printf("-->Quarta dica: Analise dos digitos ainda nao descobertos:\n\t");
                if (fix1 == -1)
                printf("- O primeiro digito e %s que 5.\n\n\n", (n1 >= 5) ? "maior ou igual" : "menor");
                if (fix2 == -1)
                printf("- O segundo digito e %s que 5.\n", (n2 >= 5) ? "maior ou igual" : "menor");
                if (fix3 == -1)
                printf("- O terceiro digito e %s que 5.\n", (n3 >= 5) ? "maior ou igual" : "menor");
                if (fix4 == -1)
                printf("- O quarto digito e %s que 5.\n", (n4 >= 5) ? "maior ou igual" : "menor");
                break;

                case 9:
                if (n1 == n2 || n1 == n3 || n1 == n4 || n2 == n3 || n2 == n4 || n3 == n4)
                {
                    printf("-->Quinta dica: A senha contem digitos repetidos.\n");
                }
                else
                {
                    printf("-->Quinta dica: Todos os digitos da senha sao diferentes.\n");
                }

                break;
            }
        }
        }
            else
            {
                printf("\n\n");
                printf("\n\n-----------------------------------------------------------------------------------------------------------------------");
                printf("\n\n\t\t\tPARABENS!! Voce acertou a senha em %d tentativa(s)!!\n\n\n\n", tentativa);
                break;
            }

        printf("Pressione qualquer tecla para continuar\n\n");
        _getch();
        }
        if (fix1 == -1 || fix2 == -1 || fix3 == -1 || fix4 == -1)
        {
            system("cls");
            printf("\n\n\n\t\t\tFim de jogo! O numero correto era %d.\n\n", n);
        }

    printf("Pressione qualquer tecla para continuar");
    _getch();
    system("cls");
    printf("\n\n\n\t\t\tDeseja jogar novamente?\n\n");
    printf("\n\t\t\tDigite 1 para jogar novamente ou outro numero para encerrar: ",j);
    scanf("%d",&j);

    fix1 = fix2 = fix3 = fix4 = -1;
    system("cls");

    }while(j==1);

    printf("\n\n\n\t\t\tObrigado por jogar!\n\n\n");

    system ("pause");
    return 0;
}
