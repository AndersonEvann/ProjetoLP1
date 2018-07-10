#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

#include "funcionario.h"
#include "veterinario.h"
#include "tratador.h"

using namespace std;

/**
* @brief Classe animal.
*/
class Animal {
protected:
	int id;
	string classe;
	string nome;
	string cientifico;
	char sexo;
	float tamanho;
	string dieta;
	Veterinario veterinario;
	Tratador tratador;
	string batismo;

public:
	/**
	* @brief Construtor vazio.
	*/
	Animal();
	Animal(int id_, string classe);
	/**
	* @brief Construtor completo com a classe Funcionario passado por classe.
	*
	* @param[in] id_          O número de identificação do animal. Número unico.
	* @param[in] classe_      A classe do animal(Anfibio, Reptil, Ave ou Mamifero).
	* @paran[in] nome_        O nome popular da especie.
	* @param[in] cientifico_  O nome cientifico do animal.
	* @param[in] sexo_        O sexo do animal.
	* @param[in] tamanho_     O tamanho em metros do animal.
	* @param[in] dieta_       A alimentação regular do animal.
	* @param[in] veterinario_ O veterinario que cuida do animal.
	* @param[in] tratador_    O tratador que cuida do animal.
	* @param[in] batismo_     O nome de batismo do animal.
	*/
	Animal(int id_, string classe_, string nome_, string cientifico_,
		char sexo_, float tamanho_, string dieta_, Veterinario veterinario_,
		Tratador tratador_, string batismo_);
	/**
	* @brief Construtor completo com a classe Funcionario passado por id.
	*
	* @param[in] id_          O número de identificação do animal. Número unico.
	* @param[in] classe_      A classe do animal(Anfibio, Reptil, Ave ou Mamifero).
	* @paran[in] nome_        O nome popular da especie.
	* @param[in] cientifico_  O nome cientifico do animal.
	* @param[in] sexo_        O sexo do animal.
	* @param[in] tamanho_     O tamanho em metros do animal.
	* @param[in] dieta_       A alimentação regular do animal.
	* @param[in] veterinario_ O identificador do veterinario que cuida do animal.
	* @param[in] tratador_    O identificador do tratador que cuida do animal.
	* @param[in] batismo_     O nome de batismo do animal.
	*/
	Animal(int id_, string classe_, string nome_, string cientifico_,
		char sexo_, float tamanho_, string dieta_, int veterinario_,
		int tratador_, string batismo_);
	/**
	* @brief Destrutor da classe.
	*/
	virtual~Animal();
	// === Métodos da classe ===
	/**
	* @brief Pega o número de identificação do animal.
	*/
	int getId();
	/**
	* @brief Passar o número de identificação do animal.
	*
	* @param[in] id_ O identificador.
	*/
	void setId(int id_);
	/**
	* @brief Demais métodos para obter os atributos da classe Animal.
	*/
	void setClasse(string classe_);
	void setNome(string nome_);
	void setCientifico(string cientifico_);
	void setSexo(char sexo_);
	void setTamanho(float tamanho_);
	void setDieta(string dieta_);
	void setVeterinario(Veterinario veterinario_);
	void setTratador(Tratador tratador_);
	void setBatismo(string batismo_);

	//=== Sobrecarga dos operadores de inserção e extração.
	friend ostream &operator<<(ostream &os, const Animal &a);
	friend istream &operator>>(istream &is, Animal &a);
};

#endif