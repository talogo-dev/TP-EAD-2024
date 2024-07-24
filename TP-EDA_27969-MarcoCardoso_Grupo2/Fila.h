/*****************************************************************//**
 * \file   Ficheiro.h
 * \brief  Ficheiro que armazena todos as assinaturas dos metodos relacionados a filas
 *
 * \email  a27969@alunos.ipca.pt
 * \author Marco Cardoso
 * \date   24 maio 2024
 *********************************************************************/

#pragma once
#include <stdbool.h>

#pragma region Metodos
/**
* Insere o valor na fila.
*/
bool insertQueue(int queue[], int* rear, int data);
/**
 * Remove o valor que esta por cima da lista.
 */
int removeQueue(int queue[], int* front);
/**
 * Verifica se a fila esta vazia.
 */
bool isQueueEmpty(int rear, int front);
#pragma endregion






