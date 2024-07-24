/*****************************************************************//**
 * \file   Main.c
 * \brief  Ficheiro que chama todos os metodos do grupo 1
 * 
 * \email  a27969@alunos.ipca.pt
 * \author Marco Cardoso
 * \date   24 maio 2024
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#pragma comment(lib, "TP-EDA_27969-MarcoCardoso_Grupo1-LIB.lib")

#include "Structs.h"
#include "Metodos.h"

int main()
{
	#pragma region Inicialização de variáveis
	Matriz* inicio = NULL;
	int* valoresTodos = NULL;
	int linhas = 0;
	int colunas = 0;
	int quantidadeValores = 0;
	#pragma endregion

	#pragma region Valores Para a linha e coluna
	int* valoresLinhaAdicionar = (int*)malloc(sizeof(int) * 5);
	*(valoresLinhaAdicionar) = 100;
	*(valoresLinhaAdicionar + 1) = 200;
	*(valoresLinhaAdicionar + 2) = 300;
	*(valoresLinhaAdicionar + 3) = 400;
	*(valoresLinhaAdicionar + 4) = 500;
	
	int* valoresColunaAdicionar = (int*)malloc(sizeof(int) * 7);
	*(valoresColunaAdicionar) = 999;
	*(valoresColunaAdicionar + 1) = 999;
	*(valoresColunaAdicionar + 2) = 999;
	*(valoresColunaAdicionar + 3) = 999;
	*(valoresColunaAdicionar + 4) = 999;
	*(valoresColunaAdicionar + 5) = 999;
	*(valoresColunaAdicionar + 6) = 999;
	#pragma endregion

	#pragma region Chamadas de métodos
	linhas = ContarLinhas("DadosMatriz.csv");
	colunas = ContarColunas("DadosMatriz.csv");

	// Calcula a quantidade de valores que existe dentro do ficheiro .csv
	quantidadeValores = linhas * colunas;

	// Guarda os valores num array dinamico
	valoresTodos = ImportarValoresFicheiro(quantidadeValores, "DadosMatriz.csv");

	// Cria a lista com os valores importados
	inicio = CriarListaLigada(inicio, valoresTodos, quantidadeValores);

	inicio = MudarValorMatriz(inicio, 53, 0);
	inicio = MudarValorMatrizLinhaEColuna(inicio, 5, 2,1111);

	// Colunas
	inicio = InserirColunaMatriz(inicio, valoresColunaAdicionar, linhas, &colunas, 4);
	inicio = RemoverColunaMatriz(inicio, valoresColunaAdicionar, linhas, &colunas, 4);

	// Linhas
	inicio = InserirLinhaMatriz(inicio, valoresLinhaAdicionar, colunas, &linhas);
	inicio = RemoverLinhaMatriz(inicio, colunas, &linhas);

	#pragma endregion

	// Mostrar a matriz
	printf("Matriz:\n\n");
	MostrarMatrizTabulada(inicio, linhas, colunas);

	// Limpar os apontadores
	free(valoresColunaAdicionar);
	free(valoresLinhaAdicionar);
	free(valoresTodos);
}