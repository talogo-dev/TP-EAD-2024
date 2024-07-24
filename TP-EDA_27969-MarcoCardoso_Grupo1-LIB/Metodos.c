/*****************************************************************//**
 * \file   Metodos.c
 * \brief  Metodos utilizadas para o projeto
 *
 * \email  a27969@alunos.ipca.pt
 * \author Marco Cardoso
 * \date   24 maio 2024
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Structs.h"
#include "Metodos.h"

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
Matriz* MudarValorMatriz(Matriz* inicio, int valorAMudar, int valor)
{
	Matriz* aux = inicio;

	// Percorre a lista 
	while (aux != NULL)
	{
		// Caso encontre o valor indicado, troca - o por outro valor indicado
		if (aux->valor == valorAMudar)
		{
			aux->valor = valor;
		}
		aux = aux->prox;
	}

	return inicio;
}
/**
 * Mudar o valor de uma matriz dada a sua linha e coluna.
 *
 * \param inicio O primeiro endereco da lista ligada
 * \param coluna Coluna do valor a mudar
 * \param linha Linha do valor a mudar
 * \param valor Valor substituto
 * \return Lista ligada com o valor mudado
 */
Matriz* MudarValorMatrizLinhaEColuna(Matriz* inicio, int coluna, int linha, int valor)
{
	Matriz* aux = inicio;
	int i = 1;
	int posicao = coluna * linha;

	while (i < posicao)
	{
		aux = aux->prox;
		i++;
	}
	aux->valor = valor;

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

	// Percorre a lista e a variavel "aux" fica no fim da lista
	while (aux != NULL)
	{
		aux = aux->prox;
	}
	// Adiciona valores enquanto houver colunas disponiveis
	while (i < quantColunas)
	{
		Matriz* novaLinhaValor = CriarMatriz(*(valoresAdicionar + i));
		aux = InserirMatrizFim(inicio, novaLinhaValor);
		i++;
	}

	*(quantLinhas) = *(quantLinhas)+1;

	return inicio;
}
/**
 * Remove uma linha na matriz.
 *
 * \param inicio O primeiro endereco da lista ligada
 * \param quantColunas Quantidade de colunas que a matriz tem
 * \param quantLinhas Quantidade de linhas que a matriz tem
 * \return Inicio da lista ligada
 */
Matriz* RemoverLinhaMatriz(Matriz* inicio, int quantColunas, int* quantLinhas)
{
	if (inicio == NULL) return NULL;
	Matriz* aux = inicio;
	Matriz* final = (Matriz*)malloc(sizeof(Matriz));
	// Contadores
	int i = 0;
	int j = 0;

	while (aux != NULL)
	{
		// O aux coloca se no primeiro valor da ultima linha
		if (i == (*(quantLinhas) - 1) * quantColunas)
		{
			break;
		}
		aux = aux->prox;
		i++;
	}
	// Quando estiver no primeiro elemento da ultima linha, da "free" a todas as celulas dessa linha
	while (aux != NULL)
	{
		final = aux->prox;
		free(aux);
		aux = final;
	}

	// Remove uma linha
	*(quantLinhas) = *(quantLinhas)-1;

	return inicio;
}
/**
 * Insere uma coluna na matriz.
 *
 * \param inicio O primeiro endereco da lista ligada
 * \param valoresColuna Valores para adicionar na coluna
 * \param quantLinhas Quantidade de linhas que a matriz tem
 * \param quantColunas Quantidade de colunas que a matriz tem
 * \return Inicio da lista ligada
 */
Matriz* InserirColunaMatriz(Matriz* inicio, int* valoresColuna, int quantLinhas, int* quantColunas, int nrColuna)
{
	Matriz* aux = inicio;
	Matriz* novoValorColuna = NULL;
	Matriz* novoValorColunav2 = NULL;

	for (int i = 0; i < quantLinhas; i++)
	{
		for (int j = 0; j < (*quantColunas) + 1; j++)
		{
			if (j == nrColuna - 2)
			{
				novoValorColuna = CriarMatriz(*valoresColuna);

				novoValorColunav2 = aux->prox;
				novoValorColuna->prox = novoValorColunav2;
				aux->prox = novoValorColuna;
			}
			aux = aux->prox;
		}
	}
	(*quantColunas)++;
	return inicio;
}
/**
 * Remove uma coluna na matriz.
 *
 * \param inicio O primeiro endereco da lista ligada
 * \param quantLinhas Quantidade de linhas que a matriz tem
 * \param quantColunas Quantidade de colunas que a matriz tem
 * \return Inicio da lista ligada
 */
Matriz* RemoverColunaMatriz(Matriz* inicio, int* valoresColuna, int quantLinhas, int* quantColunas, int nrColuna)
{
	Matriz* aux = inicio;
	Matriz* segAux = aux;

	aux = aux->prox;

	for (int i = 0; i < quantLinhas; i++)
	{
		for (int j = 0; j < (*quantColunas) - 1; j++)
		{
			if (j == nrColuna - 2)
			{
				segAux->prox = aux->prox;
				free(aux);
				aux = segAux->prox;
			}
			if (aux->prox == NULL)
				break;

			aux = aux->prox;
			segAux = segAux->prox;
		}
	}
	(*quantColunas)--;
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

/**
 * Mostra a lista com linhas e colunas.
 * 
 * \param inicio O primeiro endereco da lista ligada
 * \param linhas Quantidade de linhas
 * \param colunas Quantidade de colunas
 */
void MostrarMatrizTabulada(Matriz* inicio, int quantLinhas, int quantColunas)
{

	Matriz* aux = inicio;

	for (int i = 0; i < quantLinhas; i++)
	{
		for (int j = 0; j < quantColunas; j++)
		{
			if (aux != NULL)
			{
				printf("%d\t", aux->valor);
			}
			aux = aux->prox;
		}
		puts("\n");
	}
}
#pragma endregion
#pragma region Relacionado com Ficheiros
/**
 * Conta quantas linhas tem num ficheiro .csv .
 *
 * \param nomeFicheiro Nome do ficheiro a ler
 * \return Quantidade de linhas
 */
int ContarLinhas(char nomeFicheiro[])
{
	FILE* fp;
	int cont = 0;
	char caractere;

	fp = fopen(nomeFicheiro, "r");
	if (fp == NULL) return -1;

	// Enquanto nao for o fim do ficheiro, caractere le um caractere do ficheiro
	while ((caractere = fgetc(fp)) != EOF)
	{
		// Verifica se o caracter e igual a "\n"
		if (caractere == '\n')
		{
			// se for, cont aumenta
			cont++;
		}
	}
	
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
	FILE* fp;
	int cont = 0;
	char ch;

	fp = fopen(nomeFicheiro, "r");
	if (fp == NULL) return -1;

	// Lê o arquivo caracter por caracter
	while ((ch = fgetc(fp)) != EOF)
	{
		// Incrementa o contador se encontrar um ponto e vírgula
		if (ch == ';')
		{
			cont++;
		}
		// Se encontrar um "\n", termina o contador
		if (ch == '\n')
		{
			break;
		}
	}

	// Fechando o arquivo
	fclose(fp);

	// Adiciona 1 ao contador para incluir a última coluna antes do "\n"
	return (cont + 1);
}
/**
 * Guarda os valores de um ficheiro para um array dinamico de inteiros.
 *
 * \param quant Quantidade de valores dentro do ficheiro
 * \param nomeFicheiro Nome do ficheiro a ler
 * \return Int* - Array dinamico de inteiros
 */
int* ImportarValoresFicheiro(int quant, char nomeFicheiro[])
{
	FILE* fp;
	int i = 0;

	// Aloca memoria para guardar todos os valores do ficheiro .csv
	int* valores = (int*)malloc(sizeof(int) * quant);

	// Abertura do ficheiro
	fp = fopen(nomeFicheiro, "r");
	if (fp == NULL) return -1;

	if (valores == NULL) return -1;

	// Importacao de todos os valores para um array dinamico
	while (fscanf(fp, "%d;", (valores + i)) == 1)
	{
		i++;
	}

	fclose(fp);

	// Retorna o array dinamico
	return valores;
}
#pragma endregion

