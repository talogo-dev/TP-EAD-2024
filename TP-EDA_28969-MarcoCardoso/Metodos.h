/*
* Email: a27969@alunos.ipca.pt
* Autor: Marco Cardoso
* Data (Inicio): 09/03/2024
* Versao: 0.2
* Data (Ultima Modificacao): 12/03/2024
*/


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
Matriz* MudarValorMatriz(Matriz* inicio, int quantValores, int valorAMudar, int valor);

/**
 * Insere uma linha na matriz.
 */
Matriz* InserirLinhaMatriz(Matriz* inicio, int* valoresAdicionar, int quantColunas, int* quantLinhas);
/**
 * Insere uma coluna na matriz.
 */
Matriz* InserirColunaMatriz(Matriz* inicio, int* valoresColuna, int quantLinhas, int* quantColunas);
/**
 * Remove uma linha na matriz.
 */
Matriz* RemoverLinhaMatriz(Matriz* inicio, int quantColunas, int* quantLinhas);
#pragma endregion
#pragma region Relacionado com Ficheiros
/**
 * Conta quantos valores existem num ficheiro.
 */
int ContarValoresFicheiro(char nomeFicheiro[]);
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

void displayMatrix(Matriz* head, int rows, int columns);
#pragma endregion

