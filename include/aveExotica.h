#include "animal.h"
#include "animalExotico.h"
#include "ave.h"

class AveExotica : public Ave, public AnimalExotico {
public:
	AveExotica();
	~AveExotica();

	void print(ostream &os);
};