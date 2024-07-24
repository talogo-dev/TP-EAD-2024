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

#include "Structs.h"


/*
* Struct para a lista de adjacencias
*/
typedef struct Adjacente
{
	int id;
	int distancia;
	struct Adjacente* next;
}Adjacente;

/**
 * Struct para guardar a lista de adjacencias em ficheiro binario.
 */
typedef struct AdjaFicheiro
{
	int idOrigem;
	int idDestino;
	int distancia;
}AdjaFicheiro;

/*
* Struct para a lista de vertices
*/
typedef struct Vertice
{
	int id;
	char nome;
	bool visitado;
	Adjacente* nextAdjacente;
	struct Vertice* nextVertice;
}Vertice;

/**
 * Struct para guardar a lista de vertices em ficheiro binario.
 */
typedef struct VerticeFicheiro 
{
	int id;
	char nome;		
} VerticeFicheiro;

/*
* Struct para armazenar o grafo
*/
typedef struct Grafo
{
	Vertice* inicioGraph;
	int nrVertices;
	int maxVertices;
}Grafo;

