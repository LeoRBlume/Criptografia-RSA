#ifndef _FUNC_H
#define _FUNC_H

#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>


int acharSegundaPublica(int, int, int);
int criptografaMensagem(int, int, const char [], int);
void mensagemASCII(const char []);
int modular(int, unsigned int, unsigned int);
int achaD(int, int);

#define LimpaTela system("cls")
#define PulaLinha printf("\n")

#endif // _FUNC_H