/*****************************************************************//**
 * \file   Vertice.c
 * \brief  Ficheiro que armazena todos os metodos relativos a vertices
 *
 * \email  a27969@alunos.ipca.pt
 * \author Marco Cardoso
 * \date   24 maio 2024
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "Structs.h"
#include "Vertice.h"
#include "Adjacencia.h"

#pragma region Cria��o e Inser��o
/**
* Cria um vertice para ser inserido no grafo.
*
* \param id Id do vertice
* \param nome Nome para o vertice
* \param erro Controlo de erro
* \return Vertice
*/
Vertice* CriarVertice(int id, char nome)
{
	// Aloca espa�o para guardar um v�rtice
	Vertice* aux = (Vertice*)malloc(sizeof(Vertice));
	if (aux == NULL) //*erro = -1;
		return NULL;

	if (nome == NULL) //*erro = -2;
		return NULL;

	// Inicializa o v�rtice
	aux->nome = nome;
	aux->id = id;
	aux->nextAdjacente = NULL;
	aux->nextVertice = NULL;

	// Serve para procura
	aux->visitado = false;

	return aux;
}
/**
 * Insere um novo v�rtice dentro da lista de v�rtices.
 *
 * \param listaVer Lista de v�rtices
 * \param verNovo V�rtice a adicionar
 * \return Vertice* - Lista de v�rtices
 */
Vertice* InserirVerticeLista(Vertice* listaVer, Vertice* verNovo)
{

	Vertice* aux = listaVer;

	if (listaVer == NULL)
	{
		listaVer = verNovo;
		return listaVer;
	}

	if (HasVertice(aux, verNovo->id))
	{
		return listaVer;
	}
	else
	{
		//procura onde inserir
		Vertice* antVertice = NULL;
		while (aux != NULL && aux->id < verNovo->id)
		{
			antVertice = aux;
			aux = aux->nextVertice;
		}
		//Insere
		//*res = true;
		if (antVertice == NULL)
		{
			verNovo->nextVertice = listaVer;	//insere � cabe�a
			listaVer = verNovo;
		}
		else
		{
			verNovo->nextVertice = aux;
			antVertice->nextVertice = verNovo;
		}

	}
	return listaVer;

}
/**
 * Cria v�rios v�rtices e coloca dados no mesmo.
 *
 * \param listaVertices Lista de V�rtices
 * \param quantVertices Quantidade de v�rtices a inserir
 * \param erro Controlo de erro
 * \return Vertice* - Lista de v�rtices
 */
Vertice* CriarVerticesInserirLista(Vertice* listaVertices, int quantVertices)
{

	Vertice* aux = NULL;
	Vertice* listaAux = listaVertices;
	int nome = 65;

	for (int i = 0; i < quantVertices; i++)
	{
		aux = CriarVertice(i + 1, nome);
		listaAux = InserirVerticeLista(listaAux, aux);

		nome++;
	}

	if (listaAux == NULL) return NULL;

	return listaAux;
}

/**
 * Insere um v�rtice no grafo.
 *
 * \param g Grafo a inserir
 * \param listaVertices Lista de v�rtices
 * \param quantVertices Quantidade de v�rtices
 * \param erro Controlo de erros
 * \return Grafo* - Grafo com os v�rtices
 */
Grafo* InsereVerticeGrafo(Grafo* g, Vertice* listaVertices, int quantVertices)
{
	//testes
	//*erro = 0;

	// Verifica se o vertice novo esta vazio
	if (listaVertices == NULL)
	{
		//*erro = -1;
		return g;
	}
	// Verifica se o grafo esta vazio
	if (g == NULL) 
	{
		//*erro = -2;
		return NULL;
	}

	///verificar se V j� existe no grafo...
	if (HasVerticeGrafo(g, listaVertices->id)) 
	{
		//*res = -3;
		return g;
	}

	g->nrVertices = quantVertices;

	// Verifica se 
	if (g->nrVertices > g->maxVertices)
	{
		//*erro = -4;
		return NULL;
	}

	g->inicioGraph = InserirVerticeLista(g->inicioGraph, listaVertices);

	return g;
}
#pragma endregion
#pragma region Remo��o
/**
 * Liberta a mem�ria do apontador para o vertice.
 * 
 * \param verticeRemover Vertice a remover
 */
void DestroiVertice(Vertice* verticeRemover)
{
	free(verticeRemover);
}

/**
 * Elimina um vertice e todas as suas adjac�ncias.
 * 
 * \param vertices Lista de vertices
 * \param codVertice Identificador do vertice a remover
 * \return Vertice* - Lista de vertices
 */
Vertice* EliminaVertice(Vertice* listaVer, int idVertice) 
{
	if (listaVer == NULL) return NULL;
	//procurar vertice
	Vertice* aux = listaVer;
	Vertice* ant = NULL; // Segue o aux

	while (aux->id != idVertice) 
	{
		ant = aux;
		aux = aux->nextVertice;
	}
	if (!aux) return listaVer;	//signifca que n�o existe o vertice

	//apaga vertice no inicio
	if (ant == NULL)
	{
		//apaga todas adjacencias do vertice a eliminar
		aux->nextAdjacente = ElimiminaAllAdj(aux->nextAdjacente);
		//if (*res == false) return vertices;
		listaVer = aux->nextVertice;
	}
	else {
		//apaga vertice
		ant->nextVertice = aux->nextVertice;
	}
	DestroiVertice(aux);
	return listaVer;
}

/**
 * Elimina um vertice e as suas adjacencias de um grafo.
 * 
 * \param g Grafo onde vai remover
 * \param idVertice Identificador do vertice a remover
 * \return Grafo* - Grafo sem o vertice e as respetivas adjacencias
 */
Grafo* EliminaVerticeGrafo(Grafo* g, int idVertice) 
{
	if (g == NULL) return NULL;

	g->inicioGraph = EliminaAdjacenciaAllVertices(g->inicioGraph, idVertice);
	g->inicioGraph = EliminaVertice(g->inicioGraph, idVertice);
	//if (*res == true) 

	g->nrVertices--;

	return g;
}
/**
 * Elimina todas as adjacencias de um vertice.
 * 
 * \param listaVer Lista de vertices
 * \param idAdj Identificador da adjacencia
 * \return Vertice* - Lista de vertices
 */
Vertice* EliminaAdjacenciaAllVertices(Vertice* listaVer, int idAdj)
{
	if (listaVer == NULL) return NULL;

	Vertice* aux = listaVer;

	while (aux)
	{
		aux->nextAdjacente = ElimiminaAdj(aux->nextAdjacente, idAdj);
		aux = aux->nextVertice;
	}
	return listaVer;
}
#pragma endregion
#pragma region Utilidade
/**
 * Verifica se um determinado v�rtice existe na lista de v�rtices.
 *
 * \param listaVer Lista de v�rtices
 * \param id Identificador do v�rtice a procurar
 * \return bool - Se o v�rtice existe ou n�o
 */
bool* HasVertice(Vertice* listaVer, int id)
{
	Vertice* aux = listaVer;
	if (aux == NULL) return false;

	while (aux != NULL)
	{
		if (aux->id == id)
		{
			return true;
		}
		aux = aux->nextVertice;
	}
	return false;
}

///**
/** Verifica se um determinado v�rtice existe no grafo.
 * 
 * \param g Grafo a verificar
 * \param idVertice Identificador do vertice
 * \return bool - Se existe ou nao
 */
bool HasVerticeGrafo(Grafo* g, int idVertice) 
{
	if (g == NULL) return false;
	return (HasVertice(g->inicioGraph, idVertice));
}

/**
 * Procura onde est� um v�rtice numa lista de v�rtices.
 *
 * \param listaVer Lista de v�rtices
 * \param id Identificador do v�rtice a procurar
 * \return Vertice* - O vertice encontrado
 */
Vertice* OndeEstaVertice(Vertice* listaVer, int id)
{
	if (listaVer == NULL) return NULL;

	Vertice* aux = listaVer;

	while (aux != NULL)
	{
		if (aux->id == id)
		{
			return aux;
		}
		aux = aux->nextVertice;
	}
	return NULL;
}

/**
 * Procura um v�rtice num grafo.
 *
 * \param gr Grafo onde procurar o v�rtice
 * \param idVertice Identificador do v�rtice a procurar
 * \return Vertice* - V�rtice encontrado
 */
Vertice* OndeEstaVerticeGrafo(Grafo* gr, int idVertice)
{
	if (gr == NULL) return NULL;

	return (OndeEstaVertice(gr->inicioGraph, idVertice));
}

/**
 * Mostra o conte�do da lista de v�rtices.
 *
 * \param listaVertices Lista de v�rtices
 */
void MostrarListaVertices(Vertice* listaVertices)
{
	Vertice* aux = listaVertices;

	while (aux != NULL)
	{
		printf("\nId: %d - Nome: %c", aux->id, aux->nome);
		aux = aux->nextVertice;
	}
}

#pragma endregion
