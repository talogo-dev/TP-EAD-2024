/*
* Email: a27969@alunos.ipca.pt
* Autor: Marco Cardoso
* Data (Inicio): 09/03/2024
* Versao: 0.0
* Data (Ultima Modificacao): 09/03/2024
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

	int quantidadeValores = ContarValoresFicheiro("DadosMatriz.csv");
	valoresTodos = ImportarValoresFicheiro(quantidadeValores, "DadosMatriz.csv");

	//printf("Linhas: %d", quantidadeValores);
	//for (int i = 0; i < quantidadeValores; i++)
	//{
	//	printf("\nValor: %d", *(valoresTodos + i));
	//}

	inicio = InserirMatrizesFim(inicio, valoresTodos, quantidadeValores);
	MostrarMatrizes(inicio);
}