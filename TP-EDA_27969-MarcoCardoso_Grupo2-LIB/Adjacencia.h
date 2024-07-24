/*****************************************************************//**
 * \file   Adjacencia.h
 * \brief  Ficheiro que armazena todos as assinaturas dos metodos relacionados a adjacencias
 *
 * \email  a27969@alunos.ipca.pt
 * \author Marco Cardoso
 * \date   24 maio 2024
 *********************************************************************/
#pragma once

#include <stdio.h>
#include <stdlib.h>

#include "Structs.h"
#include "Vertice.h"
#include "Adjacencia.h"
#include "Grafo.h"

#pragma region Criação e Inserção
/**
* Cria uma aresta entre vértices.
*/
Adjacente* CriarAdjacencia(int id, int distancia);
/**
 * Cria uma adjacencia e insere-a na lista de adjacências.
 */
Adjacente* InsereAdj(Adjacente* listaAdja, int idDestino, int distancia);
/**
 * Insere uma adjacencia no grafo.
 */
Grafo* InsereAdjaGrafo(Grafo* g, int idOrigem, int idDestino, int distancia);

/**
 * Insere varias adjacencias a um vertice.
 */
Grafo* InsereAdjasGrafo(Grafo* g, int idOrigem, int quantAdja, int* distancias);
#pragma endregion
#pragma region Remoções
/**
 * Liberta a memoria da adjacencia a remover.
 */
void DestruirAdja(Adjacente* adjacenteRemover);
/**
 * Elimina adjacencias do vertice indicado.
 */
Adjacente* ElimiminaAdj(Adjacente* listAdj, int idAdj);

/**
 * Elimina todas as adjacencias da lista de adjacencias.
 */
Adjacente* ElimiminaAllAdj(Adjacente* listAdj);
/**
 * Elimina a aresta que liga o vertice "origem" ao vertice "destino".
 */
Grafo* EliminaAdjGrafo(Grafo* g, int origem, int destino);
#pragma endregion
#pragma region Metodos Extra
/**
 * Soma todas as adjacencias de um vertice.
 */
int SomaAdjacencias(Grafo* g, int vertice);
#pragma endregion





