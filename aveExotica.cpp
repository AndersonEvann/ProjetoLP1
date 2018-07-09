#include "aveExotica.h"

AveExotica::AveExotica() {}

AveExotica::~AveExotica() {}

void AveExotica::print(ostream &os) {
	os << this->id << this->classe << this->nome
	   << this->cientifico << this->sexo << this->tamanho
	   << this->dieta << this->veterinario.getId()
	   << this->tratador.getId() << this->batismo << std::endl;
}