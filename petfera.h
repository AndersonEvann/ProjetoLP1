#ifndef PETFERA_H
#define PETFERA_H

#include <map>
#include <iostream>
#include <limits>
#include <fstream>
#include <sstream> // std::stringstream

#include "animal.h"
#include "funcionario.h"

using namespace std;

class Petfera {
private:
	string nome;
	map<int, Animal> animais;
	map<int, Funcionario> funcionarios;
	int idAnimal = 0;
	int idFuncionario = 0;

public:
	Petfera(string nome_);
	~Petfera();

	//== Métodos relacionados a animais.

	/**
	* @brief Cadastrar um animal.
	*
	* @param[in] a Objeto de uma classe derivada da classe Animal.
	*/
	void cadastrar(Animal a);
	/**
	* @brief Remover um animal.
	*
	* @param[in] a Objeto de uma classe derivada da classe Animal.
	*/
	void remover(Animal a);
	/**
	* @brief Alterar os dados de um animal cadastrado.
	*
	* @param[in] a Objeto de uma classe derivada da classe Animal.
	*/
	void alterar(Animal a);
	/**
	* @brief Consulta os dados cadastrados de um animal.
	*
	* @param a Objeto de uma classe derivada da classe Animal.
	*/
	void consultar(Animal a);

	//== Métodos relacionados a funcionarios.

	/**
	* @brief Cadastro de funcionario.
	*
	* @param[in] f Objeto da classe Funcionario.
	*/
	void cadastrar(Funcionario f);
	/**
	* @brief Remover um funcionario.
	*
	* @param[in] f Objeto da classe Funcionario.
	*/
	void remover(Funcionario f);
	/**
	* @brief Altera os dados de um funcionario.
	*
	* @param[in] f Objeto da classe Funcionario.
	*/
	void alterar(Funcionario f);
	/**
	* @brief Consultar dados cadastrados de um funcionario.
	*
	* @param[in] f Objeto da classe Funcionario.
	*/
	void consultar(Funcionario f);

	void carregarDados();

	//=== Métodos relacionados ao funcionamento do programa.

 	//=== Método relacionado ao menu(APENAS A INTERFACE).
 	void menuPrincipal();
 	//=== Métodos auxiliares.
 protected:
	/**
	* @brief Tentar ler uma entrada.
	*
	* @param[in] opc A variavel para armazenar a entrada escolhida.
	*/
	void opcaoDeEntrada(char &opcao);
	/**
	* @brief Tentar pegar resposta do usuario.
	*
	* @param[in] valor Variavel que recebe true caso sim e false caso nao.
	*/
	void simOUnao(bool &valor);
	/**
	* @brief Define o que o programa deve fazer.
	*
	* @param[in] opcao Variavel que recebeu a opcao desejada.
	*/
	void menuDeEscolha(char opcao);
	/**
	* @brief Pegar informações adicionais do animal.
	*/
	void infoEntradaAnimal();
	/**
	* @brief Retorna um animal.
	*
	* @param[in] mamifero um mamifero
	* @param[in] reptil   um reptil
	* @param[in] ave      uma ave
	* @param[in] anfibio  um anfibio
	*
	* @return {descricao de um valor de retorno}
	*/
	Animal *infoEntradaClasse(bool mamifero, bool reptil, bool ave, bool anfibio);
	//Sobrecarga para petfera
	friend ostream &operator<<(ostream &os, const Petfera &pf);
};

#endif