/*****************************************************************//**
 * \file   Ficheiro.c
 * \brief  Ficheiro que guarda os métodos sobre manipulacao de ficheiros
 * 
 * \email  a27969@alunos.ipca.pt
 * \author Marco Cardoso
 * \date   24 maio 2024
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "Structs.h"
#include "Ficheiro.h"
#include "Vertice.h"
#include "Adjacencia.h"

#pragma warning (disable: 4996)
/**
 * Importa os valores de um ficheiro para um array dinâmico de inteiros.
 * 
 * \param quant Quantidade de valores a ler
 * \param nomeFicheiro Nome do ficheiro a ler
 * \return int* - Array dinâmico com o valores
 */
int* ImportarValoresFicheiro(int quant, char nomeFicheiro[])
{
	FILE* fp;
	int i = 0;
	// Aloca memoria para guardar todos os valores do ficheiro .csv
	int* valores = (int*)malloc(sizeof(int) * quant);

	fp = fopen(nomeFicheiro, "r");
	if (fp == NULL) return -1;

	if (valores == NULL) return -1;

	// Importa todos os valores para um array dinamico
	while (fscanf(fp, "%d;", (valores + i)) == 1)
	{
		i++;
	}

	fclose(fp);
	return valores;
}

/**
 * Conta as linhas de um ficheiro.
 * 
 * \param nomeFicheiro Nome do ficheiro a ler
 * \param erro Controlo de erros
 * \return int - Quantidade de linhas
 */
int ContarLinhas(char nomeFicheiro[], int* erro)
{
	FILE* fp;
	int cont = 0;
	char caractere;

	*erro = 0;

	fp = fopen(nomeFicheiro, "r");
	if (fp == NULL) *erro = -1;

	// Controlo de erros
	// Caso nao abra o ficheiro nao conta as linhas
	if (*erro != -1)
	{
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
	}
	else
	{
		return cont;
	}

	// nao sei porque, mas le um \n a mais
	cont--;

	fclose(fp);
	return cont;
}

/**
 * Conta as colunas de um ficheiro.
 * 
 * \param nomeFicheiro Nome do ficheiro a ler
 * \param erro Controlo de erros
 * \return int - Quantidade de colunas
 */
int ContarColunas(char nomeFicheiro[], int* erro)
{
	FILE* fp;
	int cont = 0;
	char ch;

	*erro = 0;

	fp = fopen(nomeFicheiro, "r");
	if (fp == NULL) *erro = -1;
	
	if (*erro != -1)
	{
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
	}
	else
	{
		return cont;
	}

	// Fechando o arquivo
	fclose(fp);

	// Adiciona 1 ao contador para incluir a última coluna antes do "\n"
	return (cont + 1);
}

/**
 * Mostra os valores armazenados de um ficheiro.
 * 
 * \param valores Array dinâmico com os valores
 * \param quantValores Quantidade de valores que tem no array
 */
void MostrarValores(int* valores, int quantValores)
{
	int* aux = valores;
	int i = 0;

	if (aux == NULL) printf("A lista está vazia");

	for(i = 0; i < quantValores; i++)
	{
		printf("Valor %d - %d\n", i + 1, *(valores + i));
	}
}

/**
 * Guarda as adjacencias num ficheiro binario.
 * 
 * \param listaAdja Lista de adjacencias
 * \param nomeFicheiro Nome do ficheiro
 * \param idVerticeOrigem Identificador do vertice a colocar as adjacencias
 * \return Int - Retorna se resultou ou nao
 */
int GuardarAdjacenciasBinario(Adjacente* listaAdja, char nomeFicheiro, int idVerticeOrigem)
{
	FILE* fp;
	// Transforma um caracter em string
	char nomeFicheiroStr[2] = { nomeFicheiro, '\0' };

	if (listaAdja == NULL) return -2;
	fp = fopen(nomeFicheiroStr, "wb");
	if (fp == NULL) return -1;

	Adjacente* aux = listaAdja;
	AdjaFicheiro auxFile;
	while (aux) 
	{
		auxFile.idDestino = aux->id;
		auxFile.idOrigem = idVerticeOrigem;
		auxFile.distancia = aux->distancia;
		fwrite(&auxFile, 1, sizeof(AdjaFicheiro), fp);
		aux = aux->next;
	}
	fclose(fp);
	return 1;
}

/**
 * Guarda o grafo em ficheiro binario.
 * 
 * \param listaVer Lista de vertices
 * \param nomeFicheiro Nome do ficheiro a escrever
 * \return Int - Retorna se resultou ou nao
 */
int GuardarGrafoBinario(Vertice* listaVer, char* nomeFicheiro)
{
	FILE* fp;
	int r;

	if (listaVer == NULL) return -1;

	fp = fopen(nomeFicheiro, "wb");
	if (fp == NULL) return -2;

	Vertice* aux = listaVer;
	VerticeFicheiro auxFicheiro;	//estrutura de vertice para gravar em ficheiro

	while (aux != NULL) 
	{
		auxFicheiro.id = aux->id;
		//strcpy(auxFicheiro.nome, aux->nome);
		auxFicheiro.nome = aux->nome;
		fwrite(&auxFicheiro, 1, sizeof(VerticeFicheiro), fp);
		//Pode gravar de imediato as adjacencias!
		if (aux->nextAdjacente)
		{
			r = GuardarAdjacenciasBinario(aux->nextAdjacente, aux->nome, aux->id);
			if (r < 0) break;
		}
		aux = aux->nextVertice;
	}
	fclose(fp);
	return 1;
}

/**
 * Carrega os vertices de um ficheiro binario.
 * 
 * \param listaVer Lista dos vertices
 * \param nomeFicheiro Nome do ficheiro binario a ler
 * \return Vertice* - Lista dos vertices carregados
 */
Vertice* CarregarVerticesBinario(Vertice* listaVer, char* nomeFicheiro)
{
	FILE* fp = fopen(nomeFicheiro, "rb");
	if (fp == NULL) return NULL;

	int* erro = 0;

	VerticeFicheiro aux;
	Vertice* novo;
	while (fread(&aux, 1, sizeof(VerticeFicheiro), fp)) 
	{
		novo = CriarVertice(aux.id, aux.nome, erro);
		listaVer = InserirVerticeLista(listaVer, novo);
	}
	fclose(fp);
	return listaVer;
}

/**
 * Carrega as adjacencias de um ficheiro binario.
 * 
 * \param gr Grafo a onde inserir as adjacencias
 * \param g  Lista de vertices ???
 * \return Vertice* - Retorna a lista dos vertices com as adjacencias
 */
Grafo* CarregarAdjacenciasBinario(Grafo* gr, Vertice* g) 
{
	FILE* fp;
	if (g == NULL) return -1;
	AdjaFicheiro aux;
	Vertice* auxGraph = g;

	while (auxGraph) 
	{
		char nomeVertice[2] = { auxGraph->nome, '\0' };

		fp = fopen(nomeVertice, "rb");
		if (fp != NULL) 
		{
			while (fread(&aux, 1, sizeof(AdjaFicheiro), fp)) 
			{
				gr = InsereAdjaGrafo(gr, aux.idOrigem, aux.idDestino, aux.distancia);
			}
			fclose(fp);
		}
		auxGraph = auxGraph->nextVertice;
	}
	return gr;
}
