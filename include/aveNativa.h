#include "ave.h"
#include "animalNativo.h"

class AveNativa : public Ave, public AnimalNativo {
public:
	AveNativa();
	~AveNativa();

	void print(ostream &os);
};