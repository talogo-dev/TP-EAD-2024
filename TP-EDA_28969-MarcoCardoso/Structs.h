/*
* Email: a27969@alunos.ipca.pt
* Autor: Marco Cardoso
* Data (Inicio): 09/03/2024
* Versao: 0.2
* Data (Ultima Modificacao): 12/03/2024
*/

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Uma estrutura que permite armazenar um valor e criar uma lista ligada.
 */
typedef struct Matriz
{
	int valor;
	struct Matriz* prox;
} Matriz;
