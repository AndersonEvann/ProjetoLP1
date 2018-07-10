#include <iostream>

#include "animalSilvestre.h"

using std::string;

class AnimalNativo : public AnimalSilvestre {
protected:
	string ufOrigem;
	string autorizacao;

public:
	AnimalNativo();
	~AnimalNativo();
};