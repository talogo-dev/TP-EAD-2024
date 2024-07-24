/*****************************************************************//**
 * \file   Ficheiro.h
 * \brief  Ficheiro que armazena todos as assinaturas dos metodos relacionados a ficheiros
 *
 * \email  a27969@alunos.ipca.pt
 * \author Marco Cardoso
 * \date   24 maio 2024
 *********************************************************************/
#pragma once

#include <stdio.h>
#include <stdlib.h>

#include "Structs.h"
#pragma region Importacao e contagem
/**
* Importa os valores de um ficheiro para um array dinâmico de inteiros.
*/
int* ImportarValoresFicheiro(int quant, char nomeFicheiro[]);

/**
 * Conta as linhas de um ficheiro.
 */
int ContarLinhas(char nomeFicheiro[], int* erro);

/**
 * Conta as colunas de um ficheiro.
 */
int ContarColunas(char nomeFicheiro[], int* erro);
#pragma endregion
#pragma region Guardar e carregar grafo
/**
 * Guarda o grafo em ficheiro binario..
 */
int GuardarGrafoBinario(Vertice* listaVer, char* nomeFicheiro);

/**
 * Guarda as adjacencias num ficheiro binario.
 */
int GuardarAdjacenciasBinario(Adjacente* listaAdja, char nomeFicheiro, int idVerticeOrigem);

/**
 * Carrega os vertices de um ficheiro binario.
 */
Vertice* CarregarVerticesBinario(Vertice* h, char* fileName);

/**
 * Carrega as adjacencias de um ficheiro binario.
 */
Grafo* CarregarAdjacenciasBinario(Grafo* gr, Vertice* g);
#pragma endregion
#pragma region Metodos Extra
/**
 * Mostra os valores armazenados de um ficheiro.
 */
void MostrarValores(int* valores, int quantValores);
#pragma endregion





