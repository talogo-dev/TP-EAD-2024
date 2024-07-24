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

#pragma region Criação e Inserção
 /**
  * Cria um vertice para ser inserido no grafo.
  */
Vertice* CriarVertice(int id, char nome);
/**
 * Insere um novo vértice dentro da lista de vértices.
 */
Vertice* InserirVerticeLista(Vertice* listaVer, Vertice* verNovo);
/**
 * Cria vários vértices e inseri-los na lista de vértices.
 */
Vertice* CriarVerticesInserirLista(Vertice* listaVertices, int quantVertices);
/**
 * Insere um vértice no grafo.
 */
Grafo* InsereVerticeGrafo(Grafo* g, Vertice* listaVertices, int quantVertices);

#pragma endregion
#pragma region Remoções
/**
 * Liberta a memória do apontador para o vertice.
 */
void DestroiVertice(Vertice* verticeRemover);
/**
 * Elimina um vertice e todas as suas adjacências.
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
 * Verifica se um determinado vértice existe na lista de vértices.
 */
bool* HasVertice(Vertice* listaVer, int id);
/**
 * Verifica se um determinado vértice existe no grafo.
 */
bool HasVerticeGrafo(Grafo* g, int idVertice);
/**
 * Procura onde está um vértice numa lista de vértices.
 */
Vertice* OndeEstaVertice(Vertice* listaVer, int id);
/**
 * Procura um vértice num grafo.
 */
Vertice* OndeEstaVerticeGrafo(Grafo* gr, int idVertice);
/**
 * Mostra o conteúdo da lista de vértices.
 */
void MostrarListaVertices(Vertice* listaVertices);

#pragma endregion



