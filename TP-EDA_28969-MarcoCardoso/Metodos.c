/*
* Email: a27969@alunos.ipca.pt
* Autor: Marco Cardoso
* Data (Inicio): 09/03/2024
* Versao: 0.2
* Data (Ultima Modificacao): 12/03/2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Structs.h"

#pragma warning(disable : 4996)

#pragma region Relacionada com Listas Ligadas
/**
 * Aloca memoria para guardar uma estrutra do tipo 'Matriz*'.
 * 
 * \param valor Valor a guardar dentro da estrutura
 * \return 'Celula' que depois pode ser anexada a uma lista ligada
 */
Matriz* CriarMatriz(int valor)
{
	Matriz* novoNumero = (Matriz*)malloc(sizeof(Matriz));

	if (novoNumero == NULL) return NULL;

	novoNumero->valor = valor;
	novoNumero->prox = NULL;

	return novoNumero;
}

/**
 * Insere uma 'celula' no fim de uma lista ligada.
 * 
 * \param inicio O primeiro endereco da lista ligada
 * \param novoValor 'Celula' a guardar
 * \return Lista ligada com a 'celula' no fim dela
 */
Matriz* InserirMatrizFim(Matriz* inicio, Matriz* novoValor)
{
	if (novoValor == NULL) return inicio;
	if (inicio == NULL) inicio = novoValor;
	else
	{
		Matriz* aux = inicio;
		while (aux->prox != NULL) aux = aux->prox;
		aux->prox = novoValor;
	}
	return inicio;
}

/**
 * Insere varias 'celulas' a lista ligada, no final dela.
 * 
 * \param inicio O primeiro endereco da lista ligada
 * \param valoresTodos Array dinamico de inteiros
 * \param quantValores Quantidade de valores
 * \return  Lista ligada com todas as 'celulas'
 */
Matriz* CriarListaLigada(Matriz* inicio, int* valoresTodos, int quantValores)
{
	Matriz* novoValor = NULL;
	Matriz* aux = inicio;

	for (int i = 0; i < quantValores; i++)
	{
		novoValor = CriarMatriz(*(valoresTodos + i));

		aux = InserirMatrizFim(aux, novoValor);
	}
	return aux;
}

/**
 * Muda um valor a escolha do utilizador por outro valor a escolha do utilizador na matriz.
 * 
 * \param inicio O primeiro endereco da lista ligada
 * \param quantValores Quantidade de valores
 * \param valorAMudar Valor a mudar
 * \param valor Valor no qual o "Valor a mudar" vai ficar
 * \return Lista ligada com os valores mudados
 */
Matriz* MudarValorMatriz(Matriz* inicio, int quantValores, int valorAMudar, int valor)
{
	Matriz* aux = inicio;

	while (aux != NULL)
	{
		if (aux->valor == valorAMudar)
		{
			aux->valor = valor;
		}
		aux = aux->prox;
	}

	return inicio;
}

/**
 * Insere uma linha na matriz.
 * 
 * \param inicio O primeiro endereco da lista ligada
 * \param valoresAdicionar Valores a adicionar a linha
 * \param quantColunas Quantidade de colunas que a matriz tem
 * \return Inicio da lista ligada
 */
Matriz* InserirLinhaMatriz(Matriz* inicio, int* valoresAdicionar, int quantColunas, int* quantLinhas)
{
	if (inicio == NULL) return NULL;
	Matriz* aux = inicio;
	int i = 0;

	while (aux != NULL)
	{
		aux = aux->prox;
	}

	while (i < quantColunas)
	{
		Matriz* novaLinhaValor = CriarMatriz(*(valoresAdicionar + i));
		aux = InserirMatrizFim(inicio, novaLinhaValor);
		i++;
	}

	*(quantLinhas) = *(quantLinhas) + 1;

	return inicio;
}

/**
 * Remove uma linha na matriz.
 * 
 * \param inicio O primeiro endereco da lista ligada
 * \param quantColunas Quantidade de colunas que a matriz tem
 * \param quantLinhas Quantidad de linha que a matriz tem
 * \return Inicio da lista ligada
 */
Matriz* RemoverLinhaMatriz(Matriz* inicio, int quantColunas, int* quantLinhas)
{
	if (inicio == NULL) return NULL;
	Matriz* aux = inicio;
	int i = 0;

	while (aux != NULL)
	{
		aux = aux->prox;
	}

	while (i < quantColunas)
	{
		aux = NULL;
		i++;
	}

	*(quantLinhas) = *(quantLinhas) - 1;
	

	return inicio;
}
/**
 * Insere uma coluna na matriz.
 * 
 * \param inicio O primeiro endereco da lista ligada
 * \param valoresAdicionar Valores a adicionar a coluna
 * \return Inicio da lista ligada
 */

Matriz* InserirColunaMatriz(Matriz* inicio, int* valoresColuna, int quantLinhas, int* quantColunas)
{
	Matriz* aux = inicio;
	Matriz* novoValorColuna = (Matriz*)malloc(sizeof(Matriz));
	int i = 0; // numero de valores
	int j = 0; // indice do array "valoresColuna"
	int k = 1; // multiplicador para as colunas

	if (inicio == NULL) return NULL;

	while (aux != NULL)
	{
		if ((i == *(quantColunas)-1))
		{
			// Criar memoria
			novoValorColuna = CriarMatriz(*(valoresColuna + j));

			novoValorColuna->prox = aux->prox;
			aux->prox = novoValorColuna;

			j++;
		}

		if (i == (*(quantColunas)-1) + quantLinhas * k)
		{
			// Criar memoria
			novoValorColuna = CriarMatriz(*(valoresColuna + j));

			novoValorColuna->prox = aux->prox;
			aux->prox = novoValorColuna;

			j++;
			k++;
		}
		i++;
		aux = aux->prox;
	}

	*(quantColunas) = *(quantColunas) + 1;
	
	return inicio;
}
#pragma endregion
#pragma region Mostrar Matrizes

/**
 * Mostra apenas uma 'celula' de uma lista ligada.
 * 
 * \param nr Uma 'celula' da lista ligada
 */
void MostrarMatriz(Matriz* nr)
{
	printf("\nMatriz: %d\n", nr->valor);
}

/**
 * Mostra toda uma lista ligada.
 * 
 * \param inicio O primeiro endereco da lista ligada
 */
void MostrarMatrizes(Matriz* inicio)
{
	if (inicio == NULL) printf("Lista Vazia!");
	Matriz* aux = inicio;
	// Enquanto nao chegar ao ultimo numero...
	while (aux != NULL)
	{
		// Mostrar o Numero
		MostrarMatriz(aux);
		// Avança uma casa
		aux = aux->prox;
	}
}

void displayMatrix(Matriz* head, int rows, int columns) {
	int r = rows;
	int c = columns;
	int* ptr = malloc((r * c) * sizeof(int));

	Matriz* aux = head;

	// Percorre a lista ligada e preenche a matriz
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (aux != NULL) {
				// Calcula o índice correto no array unidimensional
				ptr[i * columns + j] = aux->valor;
				aux = aux->prox;
			}
		}
	}
	// Exibe a matriz
	printf("Matriz:\n");
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			printf("%d ", ptr[i * columns + j]);
		}
		printf("\n");
	}

	// Libera a memória alocada para o array unidimensional
	free(ptr);
}
#pragma endregion
#pragma region Relacionado com Ficheiros
/**
 * Conta quantos valores existem num ficheiro.
 * 
 * \param nomeFicheiro Nome do ficheiro a ler
 * \return Quantidade de valores
 */
int ContarValoresFicheiro(char nomeFicheiro[])
{
	int cont = 0;
	FILE* fp;
	fp = fopen(nomeFicheiro, "r");
	if (fp == NULL) return -1;

	int a = 0;

	while (fscanf(fp, "%d;", &a) == 1)
	{
		cont++;
	}

	fclose(fp);

	return cont;
}

/**
 * Guarda os valores de um ficheiro para um array dinamico de inteiros.
 * 
 * \param quant Quantidade de valores dentro do ficheiro
 * \param nomeFicheiro Nome do ficheiro a ler
 * \return Array dinamico de inteiros
 */
int* ImportarValoresFicheiro(int quant, char nomeFicheiro[])
{
	FILE* fp;
	int i = 0;
	int* valores = (int*)malloc(sizeof(int) * quant);

	fp = fopen(nomeFicheiro, "r");
	if (fp == NULL) return -1;

	if (valores == NULL) return -1;

	while (fscanf(fp, "%d;", (valores + i)) == 1)
	{
		i++;
	}

	fclose(fp);
	return valores;
}

/**
 * Conta quantas linhas tem num ficheiro .csv .
 * 
 * \param nomeFicheiro Nome do ficheiro a ler
 * \return Quantidade de linhas
 */
int ContarLinhas(char nomeFicheiro[])
{
	int cont = 0;
	FILE* fp;
	char caractere;

	fp = fopen(nomeFicheiro, "r");
	if (fp == NULL) return -1;

	// Enquanto nao for o fim do ficheiro
	while ((caractere = fgetc(fp)) != EOF) {
		// Verifica se o caracter e igual a mudar de linha
		if (caractere == '\n') {
			cont++;
		}
	}
	
	// nao sei porque, mas le um \n a mais
	cont--;
	fclose(fp);
	return cont;
}

/**
 * Conta quantas colunas tem num ficheiro .csv .
 * 
 * \param nomeFicheiro Nome do ficheiro a ler
 * \return Quantidade de colunas
 */
int ContarColunas(char nomeFicheiro[])
{
	int cont = 0;
	FILE* fp;
	char caractere;
	fp = fopen(nomeFicheiro, "r");
	if (fp == NULL) return -1;

	// Lê o arquivo caractere por caractere
	while ((caractere = fgetc(fp)) != EOF) {
		// Incrementa o contador se encontrar um ponto e vírgula ou uma quebra de linha
		if (caractere == ';' || caractere == '\n') {
			cont++;
			// Se encontrar uma quebra de linha, termina a contagem
			if (caractere == '\n') {
				break;
			}
		}
	}

	// Fecha o arquivo
	fclose(fp);

	return cont;
}
#pragma endregion

