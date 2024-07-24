/*****************************************************************//**
 * \file   Vertice.h
 * \brief  Ficheiro que armazena todos as assinaturas dos metodos relacionados a vertices
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
#include "Vertice.h"
#include "Grafo.h"

#pragma region Cria��o e Inser��o
 /**
  * Cria um vertice para ser inserido no grafo.
  */
Vertice* CriarVertice(int id, char nome);
/**
 * Insere um novo v�rtice dentro da lista de v�rtices.
 */
Vertice* InserirVerticeLista(Vertice* listaVer, Vertice* verNovo);
/**
 * Cria v�rios v�rtices e inseri-los na lista de v�rtices.
 */
Vertice* CriarVerticesInserirLista(Vertice* listaVertices, int quantVertices);
/**
 * Insere um v�rtice no grafo.
 */
Grafo* InsereVerticeGrafo(Grafo* g, Vertice* listaVertices, int quantVertices);

#pragma endregion
#pragma region Remo��es
/**
 * Liberta a mem�ria do apontador para o vertice.
 */
void DestroiVertice(Vertice* verticeRemover);
/**
 * Elimina um vertice e todas as suas adjac�ncias.
 */
Vertice* EliminaVertice(Vertice* listaVer, int idVertice);
/**
 * Elimina um vertice e as suas adjacencias de um grafo.
 */
Grafo* EliminaVerticeGrafo(Grafo* g, int idVertice);
/**
 * Elimina todas as adjacencias de um vertice.
 */
Vertice* EliminaAdjacenciaAllVertices(Vertice* listaVer, int idAdj);
#pragma endregion
#pragma region Utilidade
/**
 * Verifica se um determinado v�rtice existe na lista de v�rtices.
 */
bool* HasVertice(Vertice* listaVer, int id);
/**
 * Verifica se um determinado v�rtice existe no grafo.
 */
bool HasVerticeGrafo(Grafo* g, int idVertice);
/**
 * Procura onde est� um v�rtice numa lista de v�rtices.
 */
Vertice* OndeEstaVertice(Vertice* listaVer, int id);
/**
 * Procura um v�rtice num grafo.
 */
Vertice* OndeEstaVerticeGrafo(Grafo* gr, int idVertice);
/**
 * Mostra o conte�do da lista de v�rtices.
 */
void MostrarListaVertices(Vertice* listaVertices);

#pragma endregion



