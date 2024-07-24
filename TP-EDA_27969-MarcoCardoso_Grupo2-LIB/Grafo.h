/*****************************************************************//**
 * \file   Grafo.h
 * \brief  Ficheiro que armazena todos as assinaturas dos metodos relacionados a grafos
 *
 * \email  a27969@alunos.ipca.pt
 * \author Marco Cardoso
 * \date   24 maio 2024
 *********************************************************************/
#pragma once

#include <stdio.h>
#include <stdlib.h>

#include "Structs.h"
#include "Grafo.h"

#pragma region Criacao
/**
* Cria um grafo.
*/
Grafo* CriarGrafo(int maxVertices);
#pragma endregion
#pragma region Mostragem do grafo
/**
 * Mostra um grafo a partir de um vertice.
 */
void MostrarGrafo(Vertice * graph);
/**
 * Mostra um grafo dado um grafo.
 */
void MostrarGrafoV2(Grafo * gr);
/**
 * Mostra um vertice.
 */
void ProcessaVertice(Vertice * v);
#pragma endregion
#pragma region BFT
/**
 * Percorre o caminho de um grafo a partir de um vertice.
 */
bool BreadthFirstTraversalLA(Grafo * g, int vOrigin);
/**
 * Procura um caminho entre 2 vertices, retorna a soma das ajdas e a soma dos ID's.
 */
bool BreadthFirstSearchLA(Grafo * g, int vOrigin, int vDestino, int* somaCaminho, int* somaId);
/**
 * Coloca o campo visitado a true de uma lista de vertices.
 */
Vertice* LimparVisitadoVertices(Vertice * inicio);
#pragma endregion




