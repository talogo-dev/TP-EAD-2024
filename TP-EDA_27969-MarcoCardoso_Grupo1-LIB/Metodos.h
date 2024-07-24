/*****************************************************************//**
 * \file   Metodos.h
 * \brief  Ficheiro cabecalho que guarda as assinaturas dos metodos todos
 * 
 * \email  a27969@alunos.ipca.pt
 * \author Marco Cardoso
 * \date  24 maio 2024
 *********************************************************************/

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Structs.h"

#pragma region Relacionada com Listas Ligadas
 /**
  * Aloca memoria para guardar uma estrutra do tipo 'Matriz*'.
  */
Matriz* CriarMatriz(int valor);
/**
 * Insere uma 'celula' no fim de uma lista ligada.
 */
Matriz* InserirMatrizFim(Matriz* inicio, Matriz* novoValor);
/**
 * Insere varias 'celulas' a lista ligada, no final dela.
 */
Matriz* CriarListaLigada(Matriz* inicio, int* valoresTodos, int quantValores);
/**
 * Muda um valor a escolha do utilizador por outro valor a escolha do utilizador na matriz.
 */
Matriz* MudarValorMatriz(Matriz* inicio, int valorAMudar, int valor);
/**
 * Muda um valor numa coluna e numa linha especificada pelo utilizador na matriz.
 */
Matriz* MudarValorMatrizLinhaEColuna(Matriz* inicio, int coluna, int linha, int valor);
/**
 * Insere uma linha na matriz.
 */
Matriz* InserirLinhaMatriz(Matriz* inicio, int* valoresAdicionar, int quantColunas, int* quantLinhas);
/**
 * Insere uma coluna na matriz.
 */
Matriz* InserirColunaMatriz(Matriz* inicio, int* valoresColuna, int quantLinhas, int* quantColunas, int nrColuna);
/**
 * Remove uma linha na matriz.
 */
Matriz* RemoverLinhaMatriz(Matriz* inicio, int quantColunas, int* quantLinhas);
/**
 * Remove uma coluna na matriz.
 */
Matriz* RemoverColunaMatriz(Matriz* inicio, int* valoresColuna, int quantLinhas, int* quantColunas, int nrColuna);
#pragma endregion
#pragma region Relacionado com Ficheiros
/**
 * Guarda os valores de um ficheiro para um array dinamico de inteiros.
 */
int* ImportarValoresFicheiro(int quant, char nomeFicheiro[]);
/**
 * Conta quantas linhas tem num ficheiro .csv .
 */
int ContarLinhas(char nomeFicheiro[]);
/**
 * Conta quantas colunas tem num ficheiro .csv .
 */
int ContarColunas(char nomeFicheiro[]);
#pragma endregion
#pragma region Mostrar Matrizes
/**
 * Mostra apenas uma 'celula' de uma lista ligada.
 */
void MostrarMatriz(Matriz* nr);
/**
 * Mostra toda uma lista ligada.
 */
void MostrarMatrizes(Matriz* inicio);

/**
 * Mostra a lista com linhas e colunas.
 */
void MostrarMatrizTabulada(Matriz* inicio, int linhas, int colunas);
#pragma endregion