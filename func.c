#include "func.h"

int acharSegundaPublica(int p, int q, int phiN){


    for(int i=3;i<phiN;i++){
        if(phiN % i !=0){
            return i;
        }
    }

}


int achaD(int e, int phiN){

for (int i = 0; i<phiN; i++){

        if((i*e)%phiN == 1){
            return i;
        }

    }

}


void mensagemASCII(const char st[]){

    printf("Mensagem em ASCII:");

     for (int i=0; st[i] != '\0'; i++){
        printf(" %d", st[i]);
     }
     printf("\n");

}


int criptografaMensagem(int x1, int x2, const char st[], int i){

    int aux;

        aux = st[i];
        aux = modular(aux,x2,x1);


    return aux;

}

int modular(int base, unsigned int exp, unsigned int mod)
{
    int x = 1;
    int i;
    int power = base % mod;

    for (i = 0; i < sizeof(int) * 8; i++) {
        int least_sig_bit = 0x00000001 & (exp >> i);
        if (least_sig_bit)
            x = (x * power) % mod;
        power = (power * power) % mod;
    }

    return x;
}

