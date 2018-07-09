#include "funcionario.h"

Funcionario::Funcionario() {}

Funcionario::Funcionario(int id_) : id(id_) {}

Funcionario::Funcionario(int id_, string nome_, string cpf_, short idade_,
		short tipoSanguineo_, char fatorRH_, string especialidade_) : id(id_),
		nome(nome_) {}

Funcionario::~Funcionario() {}

int Funcionario::getId() const {
	return id;
}		