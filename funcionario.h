#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <iostream>

using std::string;

class Funcionario {
protected:
	int id;
	string nome;
	string cpf;
	short idade;
	short tipoSanguineo;
	char fatorRH;
	string especialidade;

public:
	/**
	* @brief Construtor vazio.
	*/
	Funcionario();
	/**
	* @brief Construtor por id.
	*
	* @param[in] id_ O número de identificação do funcionario.
	*/
	Funcionario(int id_);

	Funcionario(int id_, string nome_, string cpf_, short idade_,
		short tipoSanguineo_, char fatorRH_, string especialidade_);

	~Funcionario();

	int getId()const;	
};

#endif