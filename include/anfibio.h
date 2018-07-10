#include "animal.h"

using std::string;

class Anfibio : public Animal {
protected:
	int totalMudas;
	string ultimaMuda;

public:
	/**
	* @brief Construtor vazio.
	*/
	Anfibio();
	/**
	* @brief Destrutor da classe.
	*/
	~Anfibio();
};