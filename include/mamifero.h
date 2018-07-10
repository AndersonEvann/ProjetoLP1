#include "animal.h"

class Mamifero : public Animal {
protected:
	string corPelo;

public:
	/**
	* @brief Construtor vazio.
	*/
	Mamifero(string corPelo_ = "ND");
	/**
	* @brief Construtor completo.
	*
	* @param[in] id_ O número de identificação do animal.
	* @param[in] classe_ A classe a qual o animal pertence.
	* @param[in] nome_ O nome popular da especie.
	* @param[in] cientifico_ O nome cientifico do animal.
	* @param[in] sexo_ O sexo do animal.
	* @param[in] tamanho_ O tamanho em metros do animal.
	* @param[in] dieta_ A alimentação do animal.
	* @param[in] veterinario_ O identificador do veterinario responsavel.
	* @param[in] tratador_ O identificador do tratador responsavel.
	* @param[in] batismo_ O nome de batismo do animal.
	* @param[in] corPelo_ A cor do pelo do animal.
	*/
	Mamifero(int id_, string classe_, string nome_, string cientifico_,
		char sexo_, float tamanho_, string dieta_, int veterinario_,
		int tratador_, string batismo_, string corPelo_);
	/**
	* @brief Destrutor da classe.
	*/
	~Mamifero();
};