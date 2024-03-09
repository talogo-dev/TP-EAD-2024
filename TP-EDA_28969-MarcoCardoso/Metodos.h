/*
* Email: a27969@alunos.ipca.pt
* Autor: Marco Cardoso
* Data (Inicio): 09/03/2024
* Versao: 0.0
* Data (Ultima Modificacao): 09/03/2024
*/
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Structs.h"

#pragma region Relacionada com Listas Ligadas
/// <summary>
/// Aloca memoria para guardar uma estrutra do tipo 'Matriz*'
/// </summary>
/// <param name="valor">Int - Valor a guardar dentro da estrutura</param>
/// <returns>Matriz* - 'Celula' que depois pode ser anexada a uma lista ligada</returns>
Matriz* CriarMatriz(int valor);
/// <summary>
/// Insere uma 'celula' no fim de uma lista ligada
/// </summary>
/// <param name="inicio">Matriz* - O primeiro endereco da lista ligada</param>
/// <param name="novoValor">Matriz* - 'Celula' a guardar</param>
/// <returns>Matriz* - Lista ligada com a 'celula' no fim dela</returns>
Matriz* InserirMatrizFim(Matriz* inicio, Matriz* novoValor);
/// <summary>
/// Insere varias 'celulas' a lista ligada, no final dela
/// </summary>
/// <param name="inicio">Matriz* - O primeiro endereco da lista ligada</param>
/// <param name="valoresTodos">Int* - Array dinamico de inteiros</param>
/// <param name="quantValores">Int - Quantidade de valores</param>
/// <returns>Matriz* - Lista ligada com todas as 'celulas'</returns>
Matriz* InserirMatrizesFim(Matriz* inicio, int* valoresTodos, int quantValores);
#pragma endregion
#pragma region Relacionado com Ficheiros
/// <summary>
/// Conta quantos valores existem num ficheiro
/// </summary>
/// <param name="nomeFicheiro">Char[] - Nome do ficheiro a ler</param>
/// <returns>Int - Quantidade de valores</returns>
int ContarValoresFicheiro(char nomeFicheiro[]);
/// <summary>
/// Guarda os valores de um ficheiro para um array dinamico de inteiros
/// </summary>
/// <param name="quant">Int - Quantidade de valores dentro do ficheiro</param>
/// <param name="nomeFicheiro">Char[] - Nome do ficheiro a ler</param>
/// <returns>Int* - Array dinamico de inteiros</returns>
int* ImportarValoresFicheiro(int quant, char nomeFicheiro[]);
#pragma endregion
#pragma region Mostrar Matrizes
/// <summary>
/// Mostra apenas uma 'celula' de uma lista ligada
/// </summary>
/// <param name="nr">Matriz - Uma 'celula' da lista ligada</param>
void MostrarMatriz(Matriz* nr);
/// <summary>
/// Mostra toda uma lista ligada
/// </summary>
/// <param name="inicio">Matriz* - O primeiro endereco da lista ligada</param>
void MostrarMatrizes(Matriz* inicio);
#pragma endregion

