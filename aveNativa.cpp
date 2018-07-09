#include "aveNativa.h"

AveNativa::AveNativa() {}

AveNativa::~AveNativa() {}

void AveNativa::print(ostream &os) {
	os << this-id << this->classe << this->nome
	   << this->cientifico << this->sexo << this->tamanho
	   << this->dieta << this->veterinario.getId()
	   << this->tratador.getId() << this->batismo << std::endl;
}