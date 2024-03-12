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
#include "Metodos.h"

int main()
{
	Matriz* inicio = NULL;
	int* valoresTodos = NULL;
	int linhas = 0;
	int colunas = 0;
	int quantidadeValores = 0;

	int* valoresLinhaAdicionar = (int*)malloc(sizeof(int) * 5);
	*(valoresLinhaAdicionar) = 100;
	*(valoresLinhaAdicionar + 1) = 200;
	*(valoresLinhaAdicionar + 2) = 300;
	*(valoresLinhaAdicionar + 3) = 400;
	*(valoresLinhaAdicionar + 4) = 500;
	
	int* valoresColunaAdicionar = (int*)malloc(sizeof(int) * 6);
	*(valoresColunaAdicionar) = 999;
	*(valoresColunaAdicionar + 1) = 999;
	*(valoresColunaAdicionar + 2) = 999;
	*(valoresColunaAdicionar + 3) = 999;
	*(valoresColunaAdicionar + 4) = 999;
	*(valoresColunaAdicionar + 5) = 999;

	//int quantidadeValores = ContarValoresFicheiro("DadosMatriz.csv"); // Funciona
	linhas = ContarLinhas("DadosMatriz.csv"); // Funciona +/-
	colunas = ContarColunas("DadosMatriz.csv"); // Funciona
	quantidadeValores = linhas * colunas;

	valoresTodos = ImportarValoresFicheiro(quantidadeValores, "DadosMatriz.csv"); // Funciona

	inicio = CriarListaLigada(inicio, valoresTodos, quantidadeValores); // Funciona
	inicio = MudarValorMatriz(inicio, quantidadeValores, 7, 0); // Funciona
	inicio = InserirLinhaMatriz(inicio, valoresLinhaAdicionar, colunas, &linhas); // Funciona
	inicio = InserirColunaMatriz(inicio, valoresColunaAdicionar, linhas, &colunas); // Funciona +/-
	//inicio = RemoverLinhaMatriz(inicio, colunas, &linhas); // Funciona

	MostrarMatrizes(inicio);

	displayMatrix(inicio, linhas, colunas);

	// Limpar os apontadores
	free(valoresColunaAdicionar);
	free(valoresLinhaAdicionar);
	free(valoresTodos);
}