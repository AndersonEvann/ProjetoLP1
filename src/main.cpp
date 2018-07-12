/**
* @file main.cpp
* @brief Programa principal
* @author Anderson Evangelista da Silva
* @since 29-06-2018
* @date 06-07-2018
*/

#include <iostream>
#include <fstream>

#include "petfera.h"

using namespace std;

int main(int argc, char const *argv[])
{
	//instanciando um petshop
	Petfera petfera("PetFera");

<<<<<<< HEAD
	//ler dados do cadastro.
=======
	//@TODO ler dados do cadastro
>>>>>>> 39de400a8c5020515428af826a69a7323d121c51
	petfera.carregarDados();

	//menu
	petfera.menuPrincipal();

	//escrevendo saida para arquivo
	ofstream arqSaida("teste.csv", ofstream::out);

	arqSaida << petfera;
	arqSaida.close();
	//dadosFuncionarios.close();
	//dadosAnimais.close();

	return 0;
}
