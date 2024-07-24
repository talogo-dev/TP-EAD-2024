/*****************************************************************//**
 * \file   Main.c
 * \brief  Ficheiro que chama todos os metodos do grupo 2
 *
 * \email  a27969@alunos.ipca.pt
 * \author Marco Cardoso
 * \date   24 maio 2024
 *********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#pragma comment(lib,"TP-EDA_27969-MarcoCardoso_Grupo2-LIB.lib") 

#include "Structs.h"

#include "Grafo.h"
#include "Vertice.h"
#include "Adjacencia.h"

#include "Ficheiro.h"

/// DEBUG
#define DEBUG 0
#define GRAFO_CARREGADO 0

int main()
{
	#pragma region Declaracao de Variaveis
	/// Grafo
	Grafo* grafo = NULL;
	Grafo* grafoCarregado = NULL;

	/// Vertices
	Vertice* aux = NULL;
	Vertice* listaVertices = NULL;
	// Lista para guardar os vertices guardados
	Vertice* listaVerticesCarregado = NULL;

	/// Outros
	int* valores = NULL;
	int quantValores = 0, quantVertices = 0, quantAdjacencicas = 0;
	bool procura = false;
	int somaAdj = 0;
	int somaCaminho = 0;
	int somaCaminhoId = 0;

	// Manipulacao de erros
	int *erro = NULL;
	int erroGuardarGrafo = 0;
	int erroContLinhas = 0, erroContColunas = 0;
	int erroImportarValores = 0;
	#pragma endregion
	#pragma region Chamada de metodos relacionado ao grafo
	// Conta os vertices
	quantVertices = ContarLinhas("DadosMatriz.csv", &erroContLinhas);

	// Conta as adjacencias
	quantAdjacencicas = ContarColunas("DadosMatriz.csv", &erroContColunas);

	// Conta os valores do ficheiro
	quantValores = quantVertices * quantAdjacencicas;

	// Armazena os pesos entre vertices
	valores = ImportarValoresFicheiro(quantValores, "DadosMatriz.csv");

	// Armazena a lista de vertices
	listaVertices = CriarVerticesInserirLista(listaVertices, quantVertices);

	#pragma region Insercao no grafo
	// Cria o grafo
	grafo = CriarGrafo(quantVertices);
	grafoCarregado = CriarGrafo(quantVertices);

	// Insere a lista de vertices dentro do grafo
	grafo = InsereVerticeGrafo(grafo, listaVertices, quantVertices);

	// Inserir as adjacencias dentro do grafo
	grafo = InsereAdjasGrafo(grafo, quantVertices, quantAdjacencicas, valores);
	#pragma endregion

	// Guarda o grafo num ficheiro binario
	erroGuardarGrafo = GuardarGrafoBinario(listaVertices, "Vertices.bin");

	// Remover uma aresta
	//grafo = EliminaAdjGrafo(grafo, 5, 3);
	//grafo = EliminaAdjGrafo(grafo, 5, 1);
	//grafo = EliminaAdjGrafo(grafo, 5, 4);
	//grafo = EliminaAdjGrafo(grafo, 5, 5);
	//grafo = EliminaAdjGrafo(grafo, 5, 2);

	// Remover um vértice e as suas adjacencias
	//grafo = EliminaVerticeGrafo(grafo, 2);

	#pragma region Carregamento do grafo
	// Carrega os vertices
	grafoCarregado->inicioGraph = CarregarVerticesBinario(listaVerticesCarregado, "Vertices.bin");
	grafoCarregado = CarregarAdjacenciasBinario(grafoCarregado, grafoCarregado->inicioGraph);
	#pragma endregion
	#pragma endregion
	#pragma region Mostragem dos grafos
	MostrarGrafoV2(grafo);
	if (GRAFO_CARREGADO)
	{
		printf("\n\n==========Grafo Carregado de um ficheiro binario==========\n\n");
		MostrarGrafoV2(grafoCarregado);
	}
	#pragma endregion
	#pragma region Travessia BTF e soma de adjacencias
	printf("\nTravessia BFT:\n");
	procura = BreadthFirstTraversalLA(grafo, 4);
	printf("\n");

	// Coloca os vertices campo visitado a false
	grafo->inicioGraph = LimparVisitadoVertices(grafo->inicioGraph);

	// Procurar caminho entre 2 vertices
	printf("\nExiste caminho entre %d e %d?\n", 4, 2);
	procura = BreadthFirstSearchLA(grafo, 1, 3, &somaCaminho, &somaCaminhoId);
	// A soma nao me esta a dar muito bem
	printf("\n%s - Peso: %d\n", procura ? "Sim" : "Nao", somaCaminho);
	printf("A soma dos Id e: %d\n", somaCaminhoId);

	// Soma das adjacencias
	somaAdj = SomaAdjacencias(grafo, 3);
	printf("\nSoma das adjacencias do vertice 3: %d\n\n", somaAdj);
#pragma endregion
	#pragma region Debug
	if (DEBUG)
	{
		printf("Dados\n");
		printf("\tNumero de vertices: %d\n", quantVertices);
		printf("\tNumero de adjacencias: %d\n", quantAdjacencicas);
		printf("\tQuantidade de valores: %d\n\n", quantValores);

		printf("Valores Armazenados:\n");
		MostrarValores(valores, quantValores);

		printf("\n\n");

		printf("Lista de vertices:\n");
		MostrarListaVertices(listaVertices);

		printf("\n\n");

		if (procura)
		{
			printf("\nFoi encontrado um caminho!\n");
		}

#pragma region Controlo de erros

		printf("Manipulacao de erros:\n\n");

		if (erroContLinhas == -1)
		{
			printf("Erro ao contar linhas\n");
		}

		if (erroContColunas == -1)
		{
			printf("Erro ao contar colunas\n");
		}

		// Guardar grafo
		if (erroGuardarGrafo == -2)
		{
			printf("Erro ao guardar o grafo! (Ficheiro nao criado)\n");
		}

		if (erroGuardarGrafo == -1)
		{
			printf("Erro ao guardar o grafo! (Lista de vertices vazia)\n");
		}

#pragma endregion

	}
#pragma endregion
}