/*****************************************************************//**
 * \file   Structs.h
 * \brief  Ficheiro que armazena as structs utilizadas no projeto
 *
 * \email  a27969@alunos.ipca.pt
 * \author Marco Cardoso
 * \date   24 maio 2024
 *********************************************************************/

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