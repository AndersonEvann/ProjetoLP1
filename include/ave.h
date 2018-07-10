#include "animal.h"

class Ave : public Animal {
protected:
	int tamanhoDoBico;
	int envergadura;

public:
	/**
	* @brief Construtor vazio.
	*/
	Ave();
	/**
	* @brief Destrutor da classe.
	*/
	~Ave();
};