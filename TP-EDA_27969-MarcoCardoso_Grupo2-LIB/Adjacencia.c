/*****************************************************************//**
 * \file   Adjacencia.c
 * \brief  Ficheiro que guarda os métodos sobre adjacências
 * 
 * \email  a27969@alunos.ipca.pt
 * \author Marco Cardoso
 * \date   24 maio 2024
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Structs.h"
#include "Adjacencia.h"
#include "Vertice.h"

 /**
  * Cria uma aresta entre vértices.
  *
  * \param id Identificador para ligar ao vértice de destino
  * \param distancia Distancia da aresta
  * \return Adjacente* - Uma aresta
  */
Adjacente* CriarAdjacencia(int id, int distancia)
{
	Adjacente* adj;

	// Aloca memória
	adj = (Adjacente*)malloc(sizeof(Adjacente));

	if (adj == NULL) return NULL;

	// Inicialização
	adj->distancia = distancia;
	adj->id = id;
	adj->next = NULL;

	return adj;
}

/**
 * Cria uma adjacencia e insere-a na lista de adjacências.
 *
 * \param listaAdja Lista de adjacencias
 * \param idDestino Identificador do vertice destino
 * \param peso Valor para colocar na distancia da aresta
 * \return Adjacente* - Lista de adjacencias
 */
Adjacente* InsereAdj(Adjacente* listaAdja, int idDestino, int distancia)
{

	Adjacente* adj;
	adj = CriarAdjacencia(idDestino, distancia);

	if (adj == NULL)
	{
		return listaAdja;	//se não conseguiu criar nova adjacencia
	}

	//insere a nova adjacencia no inicio
	//se lista de adjacencia estiver vazia
	if (listaAdja == NULL)
	{
		listaAdja = adj; 
	}
	else // Senao insere no fim da lista
	{
		//inserir no fim da LA
		Adjacente* aux = listaAdja;

		while (aux->next != NULL)
		{
			aux = aux->next;
		}
		// Insere no ultimo sitio da lista
		aux->next = adj;
	}
	return listaAdja;
}

/**
 * Insere uma adjacencia no grafo.
 *
 * \param g Grafo
 * \param idOrigem Identificador do vértice origem
 * \param idDestino Identificador do vértice destino
 * \param peso Peso a colocar na aresta
 * \return Grafo* - Grafo com as adjacencias
 */
Grafo* InsereAdjaGrafo(Grafo* g, int idOrigem, int idDestino, int distancia)
{

	////testes
	//*res = false;

	//Verificar se vertices existem
	Vertice* vInicio = OndeEstaVerticeGrafo(g, idOrigem);
	Vertice* vFim = OndeEstaVerticeGrafo(g, idDestino);

	if (vInicio == NULL) return g;
	if (vFim == NULL) return g;
	if (distancia <= 0) return g;
	

	vInicio->nextAdjacente = InsereAdj(vInicio->nextAdjacente, idDestino, distancia);
	

	//*res = true;
	return g;

}
/** 
 * Insere varias adjacencias a um vertice.
 * 
 * \param g Grafo onde vai ser inserido
 * \param idOrigem Identificador do vertice de origem
 * \param quantAdja Quantidade de vertices que estara ligado
 * \param distancias Distancias das arestas
 * \return Grafo* - Grafo com as adjacencias
 */
Grafo* InsereAdjasGrafo(Grafo* g, int quantVer, int quantAdja, int* distancias)
{
	if (g == NULL) return NULL;
	
	for (int j = 1; j <= quantVer; j++)
	{
		if (j == 1)
		{
			for (int i = 0; i < quantAdja; i++)
			{
				g = InsereAdjaGrafo(g, j, i + 1, *(distancias + i));
			}
		}
		else
		{
			int distanciaValor = (j * quantAdja) - quantAdja;

			for (int i = 0; i < quantAdja * j; i++)
			{
				g = InsereAdjaGrafo(g, j, i + 1, *(distancias + distanciaValor));
				distanciaValor++;
			}
		}
	}

	return g;
}
#pragma region Remoções
/**
 * Liberta a memoria da adjacencia a remover.
 * 
 * \param adjacenteRemover Adjecencia a remover
 */
void DestruirAdja(Adjacente* adjacenteRemover)
{
	free(adjacenteRemover);
}

/**
 * Elimina adjacencias do vertice indicado.
 * 
 * \param listAdj Lista de adjacencias do vertice
 * \param idAdj Identificador da adjacencia
 * \return Adjacente* - Nova lista de adjacencia do vertice
 */
Adjacente* ElimiminaAdj(Adjacente* listAdj, int idAdj)
{
	//*res = false;
	if (listAdj == NULL) return NULL;
	//procura adjacencia

	Adjacente* aux = listAdj;
	Adjacente* ant = NULL;

	while (aux && aux->id != idAdj)
	{
		ant = aux;
		aux = aux->next;
	}
	// Se chegou ao fim e nao encontrou, devolve a lista
	if (!aux) return listAdj;	

	//apaga adjacencia no inicio
	if (ant == NULL)
	{
		//apaga todas adjacencias do vertice a eliminar
		listAdj = aux->next;
	}
	else 
	{
		//apaga vertice
		ant->next = aux->next;
	}

	//Apaga as adjacencias
	DestruirAdja(aux);
	//*res = true;
	return listAdj;
}
/**
 * Elimina todas as adjacencias da lista de adjacencias.
 * 
 * \param listAdj Lista de adjacencias
 * \return Adjacente* - Lista de adjacencias
 */
Adjacente* ElimiminaAllAdj(Adjacente* listAdj)
{
	//*res = false;
	if (listAdj == NULL) return NULL;
	//procura adjacencia
	Adjacente* aux = listAdj;
	while (aux) 
	{
		if (aux)
		{
			listAdj = aux->next;
		}

		DestruirAdja(aux);

		aux = listAdj;
	}
	listAdj = NULL;
	//*res = true;
	return listAdj;
}

/**
 * Elimina a aresta que liga o vertice "origem" ao vertice "destino".
 * 
 * \param g Grafo
 * \param origem Vertice "origem"
 * \param destino Vertice "destino"
 * \return Grafo* - Grafo sem a adjacencia
 */
Grafo* EliminaAdjGrafo(Grafo* g, int origem, int destino)
{

	//testes
	//*res = false;

	//Verificar se vertices existem
	Vertice* originNode = OndeEstaVerticeGrafo(g, origem);
	if (originNode == NULL) return g;
	Vertice* destinyNode = OndeEstaVerticeGrafo(g, destino);
	if (!destinyNode) return g;

	// tentar entender
	originNode->nextAdjacente = ElimiminaAdj(originNode->nextAdjacente, destino);
	return g;
}
#pragma endregion

/**
 * Soma todas as adjacencias de um vertice.
 * 
 * \param g Grafo 
 * \param vertice Vertice a somar as suas adjacencias
 * \return Int - Soma das adjacencias
 */
int SomaAdjacencias(Grafo* g, int vertice)
{
	if (g == NULL) return -1;
	if (vertice < 0) return -2;

	Grafo* aux = g;
	Vertice* auxVer = NULL;
	int soma = 0;

	auxVer = OndeEstaVerticeGrafo(g, vertice);

	Adjacente* auxAdja = auxVer->nextAdjacente;

	while (auxAdja != NULL)
	{
		soma = soma + auxAdja->distancia;

		auxAdja = auxAdja->next;
	}
	return soma;
}


