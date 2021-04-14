#include "func.h"

int main()
{

    setlocale(LC_ALL, "Portuguese");

    /*Chaves Privadas*/
    int p = 23;
    int q = 7;

    //----------------------------------------------------------------//

    /*Chave Publica*/

    int n = p*q;
    int e;
    int phiN = (p-1)*(q-1);
    int d;

    //----------------------------------------------------------------//

        /*Variaveis Gerais*/
    int stringCripto[41], stringDesCripto[41];
    int i,resposta,x1,x2,j,k=0;
    char st[41];
    do{



    printf("Criptografia RSA\n\n");
    printf("Criptografar[1] \nDescriptografar[2]\nMostrar Chaves[3]\nSair[0]\n\nInforme o numero: ");
    scanf("%d", &resposta);

    while(resposta>3 || resposta<0){
        printf("Criptografia RSA\n\n");
        printf("Criptografar[1] \nDescriptografar[2]\nSair[0]\n\nInforme o numero: ");
        scanf("%d", &resposta);
    }
    LimpaTela;

    switch (resposta)
    {
    case 1:
        printf("Informe a chave publica");
        printf("\nN: ");
        scanf("%d", &x1);
        printf("E: ");
        scanf("%d", &x2);

        printf("Informe o que deseja criptografar: ");
        scanf(" %40[^\n]", st);
        st[strlen(st)] = '\0';

        LimpaTela;

        printf("Criptografando a mensagem \n");
        printf("\nMensagem: ");
        puts(st);
        PulaLinha;

        //Mensagem em ASCII
            mensagemASCII(st);
        //Criptografa e printa a mensagem
        printf("\nMensagem Criptografada: ");
        for (int i=0; st[i] != '\0'; i++){
            printf("%d ", criptografaMensagem(x1,x2,st,i));
        }

        PulaLinha;
        PulaLinha;
    break;

    case 2:
        i=0;
        printf("Informe o valor de E: ");
        scanf("%d", &e);
        d = achaD(e,phiN);

        printf("\nInforme a mensagem codificada: ");

        char str[501];
        scanf(" %500[^\n]", str);

            char *ptr = strtok(str, " ");
            while(ptr != NULL)
            {
                stringCripto[i] = atoi(ptr);
                ptr = strtok(NULL, " ");
                i++;
            }
            PulaLinha;
            printf("Mensagem decodificada em ASCII: ");
            for(j=0;j<i;j++){
                printf("%d ",modular(stringCripto[j],d,n));
            }
            PulaLinha;
            printf("Mensagem decodificada: ");
            for(j=0;j<i;j++){
                printf("%c",modular(stringCripto[j],d,n));
            }
            PulaLinha;


        break;

        case 3:
            e = acharSegundaPublica(p,q,phiN);
            LimpaTela;
            d = achaD(e,phiN);
            printf("Informe a senha: ");
            for (i=0; i<4; i++)
                {
                    st[i] = getch();
                    putchar('*');
                }
                PulaLinha;
                if(st[0]=='4'&&st[1]=='8'&&st[2]=='6'&&st[3]=='2'){
                    LimpaTela;
                    printf("Senha Correta");
                    printf("\nChave Privada: (%d , %d)\n", p,q);
                    printf("Chave Publica: (%d , %d)\n\n", n, e);
                }
                else{
                    system("cls");
                    printf("Senha Incorreta\n");
                    PulaLinha;
                    }
            break;

            }
            }while(resposta!=0);
    system("pause");
    return 0;
}