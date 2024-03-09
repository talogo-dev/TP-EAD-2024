/*
* Email: a27969@alunos.ipca.pt
* Autor: Marco Cardoso
* Data (Inicio): 09/03/2024
* Versao: 0.0
* Data (Ultima Modificacao): 09/03/2024
*/

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Matriz
{
	int valor;
	struct Matriz* prox;
} Matriz;
