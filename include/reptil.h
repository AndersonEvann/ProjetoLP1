#include "animal.h"

using std::string;

class Reptil : public Animal {
protected:
	bool venenoso;
	string tipoVeneno;

public:
	/**
	* @brief Contrutor vazio.
	*/
	Reptil();
	/**
	* @brief Destrutor vazio.
	*/
	~Reptil();
};