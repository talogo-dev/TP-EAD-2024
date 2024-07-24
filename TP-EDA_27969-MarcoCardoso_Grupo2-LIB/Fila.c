/*****************************************************************//**
 * \file   Fila.c
 * \brief  Ficheiro que guarda os métodos relativos a filas
 * 
 * \email  a27969@alunos.ipca.pt
 * \author Marco Cardoso
 * \date   24 maio 2024
 *********************************************************************/

#include <stdio.h>
#include <stdbool.h>

#include "Fila.h"

/**
 * Insere o valor na fila.
 * 
 * \param queue Fila
 * \param rear Ultimo valor
 * \param data Valor a colocar
 * \return Boolean - Verifica se guardou os dados na lista
 */
bool insertQueue(int queue[], int* rear, int data) 
{
	queue[(*rear)++] = data;
	return true;
}

/**
 * Remove o valor que esta por cima da lista.
 * 
 * \param queue Fila
 * \param front Primeiro valor
 * \return Int - O valor da lista
 */
int removeQueue(int queue[], int* front)
{
	return queue[(*front)++];
}

/**
 * Verifica se a fila esta vazia.
 * 
 * \param rear Ultimo valor
 * \param front Primeiro valor
 * \return Boolean - Verifica se os dois sao iguais
 */
bool isQueueEmpty(int rear, int front)
{
	return rear == front;
}