/*****************************************************************//**
 * \file   Grafo.c
 * \brief  Ficheiro que guarda os métodos relativos a grafos
 * 
 * \email  a27969@alunos.ipca.pt
 * \author Marco Cardoso
 * \date   24 maio 2024
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "Structs.h"
#include "Grafo.h"
#include "Vertice.h"
#include "Fila.h"

#define MAX 10

#pragma region Criacao
/**
* Cria um grafo.
*
* \param maxVertices Máximo de vértices a armazenar
* \param erro Controlo de erros
* \return Grafo* - Grafo
*/
Grafo* CriarGrafo(int maxVertices)
{

    Grafo* aux = (Grafo*)malloc(sizeof(Grafo));
    // Controlo de erros
    if (aux == NULL) return NULL;

    // Inicializacao do grafo
    aux->inicioGraph = NULL;
    aux->nrVertices = 0;
    aux->maxVertices = maxVertices;

    return aux;

}
#pragma endregion
#pragma region Mostragem do grafo
/**
 * Mostra um grafo a partir de um vertice.
 *
 * \param grafoInicio Inicio do grafo
 */
void MostrarGrafo(Vertice* grafoInicio)
{
    Vertice* current = grafoInicio;
    while (current != NULL)
    {
        Adjacente* currentAdjacent = current->nextAdjacente;

        printf("%d: ", current->id);
        printf("%c\n", current->nome);


        while (currentAdjacent != NULL)
        {
            printf("\t");
            printf("----> %d --- Distancia: %d\n", currentAdjacent->id, currentAdjacent->distancia);
            currentAdjacent = currentAdjacent->next;
        }

        current = current->nextVertice;
    }
}

/**
 * Mostra um grafo dado um grafo.
 *
 * \param gr Grafo a mostrar
 */
void MostrarGrafoV2(Grafo* gr)
{
    MostrarGrafo(gr->inicioGraph);
}

/**
 * Mostra Vertice.
 *
 * \param v Vertice a mostrar
 */
void ProcessaVertice(Vertice* v)
{
    printf("%d | ", v->id);
}
#pragma endregion
#pragma region BFT
/**
 * Percorre o caminho de um grafo a partir de um vertice.
 *
 * \param g Grafo
 * \param vOrigin Vertice de origem
 * \return Boolean - Verifica se conseguiu ou nao
 */
bool BreadthFirstTraversalLA(Grafo* g, int vOrigin)
{
    // Variaveis da fila
    int queue[MAX];
    int rear, front;

    // Inicializacao
    rear = front = 0;

    bool succ = false;
    int nextVertice;

    // Guarda a lista de vertices
    Vertice* lstVertices = g->inicioGraph;

    // Procura o vertice na lista de vertices e marca o vertice como visitado
    Vertice* aux = OndeEstaVertice(lstVertices, vOrigin);

    if (aux == NULL) return false;

    aux->visitado = true;

    // Insere vertice na fila
    succ = insertQueue(queue, &rear, vOrigin);
    if (!succ) return false;

    // Enquanto a lista nao estiver vazia
    while (!isQueueEmpty(rear, front))
    {
        // Trata do vertice da frente da lista
        nextVertice = removeQueue(queue, &front);

        // Verifica onde esta o vertice
        aux = OndeEstaVertice(lstVertices, nextVertice);

        if (aux == NULL) return false;

        // Mostra o vertice
        ProcessaVertice(aux);

        // Avanca para a proxima adjacencia
        Adjacente* adj = aux->nextAdjacente;

        // Enquanto a adjacencia for true
        // Procura o vertice ao qual a adjacencia esta ligada
        while (adj)
        {
            aux = OndeEstaVertice(lstVertices, adj->id);
            if (aux->visitado == false)
            {
                aux->visitado = true;
                succ = insertQueue(queue, &rear, adj->id);

            }
            adj = adj->next;
        }
    }
    return true;
}

/**
 * Procura um caminho entre 2 vertices, retorna a soma das ajdas e a soma dos ID's.
 *
 * \param g Grafo
 * \param vOrigin Vertice origem
 * \param vDestino Vertice destino
 * \param somaCaminho Soma do caminho entre os 2 vertices
 * \param somaId Soma dos vertices pelo caminho
 * \return Boolean - Se encontrou caminho ou nao
 */
bool BreadthFirstSearchLA(Grafo* g, int vOrigin, int vDestino, int* somaCaminho, int* somaId)
{
    // Auxiliar variables
    // Queue
    int queue[MAX];
    int rear, front;
    rear = front = 0;

    int soma = 0;

    bool succ = false;
    int nextVertice;

    Vertice* lstVertices = g->inicioGraph;

    //marca vertice como visitado 
    Vertice* aux = OndeEstaVertice(lstVertices, vOrigin);
    if (aux == NULL) return false;
    if (aux->id == vDestino) return true;
    aux->visitado = true;

    //insere vertice na queue 
    succ = insertQueue(queue, &rear, vOrigin);
    if (!succ) return false;

    while (!isQueueEmpty(rear, front))
    {
        //trata nodo da frente da queue
        nextVertice = removeQueue(queue, &front);
        aux = OndeEstaVertice(lstVertices, nextVertice);
        if (aux == NULL) return false;

        ProcessaVertice(aux);
        // Soma dos ID
        *somaId = *somaId + aux->id;

        // Caso encontre, retorna true
        if (aux->id == vDestino) return true;
        Adjacente* adj = aux->nextAdjacente;

        // Soma das adjas
        *somaCaminho = *somaCaminho + adj->distancia;
        
        while (adj) {
            aux = OndeEstaVertice(lstVertices, adj->id);
            if (aux->visitado == false)
            {
                aux->visitado = true;
                succ = insertQueue(queue, &rear, adj->id);
                //ProcessaVertice(aux);
            }
            adj = adj->next;
        }
    }

    return false;
}

/**
 * Coloca o campo visitado a true de uma lista de vertices.
 *
 * \param listaVer Lista de vertices
 * \return Vertice* - Retorna a lista do vertices
 */
Vertice* LimparVisitadoVertices(Vertice* listaVer)
{
    Vertice* aux = listaVer;

    while (aux)
    {
        aux->visitado = false;
        aux = aux->nextVertice;
    }
    return listaVer;
}
#pragma endregion





