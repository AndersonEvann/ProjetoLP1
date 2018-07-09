#include "animal.h"
#include "funcionario.h"

using std::string;

Animal::Animal() {}

Animal::Animal(int id_, string classe_) : id(id_), classe(classe_) {}

Animal::Animal(int id_, string classe_, string nome_, string cientifico_,
	char sexo_, float tamanho_, string dieta_, Veterinario veterinario_,
	Tratador tratador_, string batismo_) : id(id_), classe(classe_), nome(nome_),
	cientifico(cientifico_), sexo(sexo_), tamanho(tamanho_), dieta(dieta_), veterinario(veterinario_),
	tratador(tratador_), batismo(batismo_) {}

Animal::Animal(int id_, string classe_, string nome_, string cientifico_,
	char sexo_, float tamanho_, string dieta_, int veterinario_, int tratador_,
	string batismo_) : id(id_), classe(classe_), nome(nome_), cientifico(cientifico_),
	sexo(sexo_), tamanho(tamanho_), dieta(dieta_), veterinario(veterinario_), tratador(tratador_),
	batismo(batismo_) {}

Animal::~Animal() {}

int Animal::getId() {
	return id;
}

void Animal::setId(int id_) {
	this->id = id_;
}

void Animal::setClasse(string classe_) {
	this->classe = classe_;
}
void Animal::setNome(string nome_) {
	this->nome = nome_;
}
void Animal::setCientifico(string cientifico_) {
	this->cientifico = cientifico_;
}
void Animal::setSexo(char sexo_) {
	this->sexo = sexo_;
}
void Animal::setTamanho(float tamanho_) {
	this->tamanho = tamanho_;
}
void Animal::setDieta(string dieta_) {
	this->dieta = dieta_;
}
void Animal::setVeterinario(Veterinario veterinario_) {
	this->veterinario = veterinario_;
}
void Animal::setTratador(Tratador tratador_) {
	this->tratador = tratador_;
}
void Animal::setBatismo(string batismo_) {
	this->batismo = batismo_;
}

ostream &operator<<(ostream &os, const Animal &a) {
	os << a.id << a.classe << a.nome << a.cientifico
	   << a.sexo << a.tamanho << a.dieta << a.veterinario.getId()
	   << a.tratador.getId() << a.batismo << std::endl;

	return os;
}
/**
* @brief Recebendo dados em stream no formato csv.
*
* @param is input stream.
* @param a Objeto Animal que vai receber os atributos.
* @return {descrição do valor de retorno}
*/
istream &operator>>(istream &is, Animal &a) {
	// Tokens dos atributos;
	string tokens[10];

	for(int i = 0; i < 10; i++) {
		getline(is, tokens[i], ',');
	}

	//Carregando os atributos NA classe.
	a.setId(stoi(tokens[0]));
	a.setClasse(tokens[1]);
	a.setNome(tokens[2]);
	a.setCientifico(tokens[3]);
	a.setSexo(tokens[4][0]);
	a.setTamanho(stof(tokens[5]));
	a.setDieta(tokens[6]);
	a.setVeterinario(Veterinario(stoi(tokens[7])));
	a.setTratador(Tratador(stoi(tokens[8])));
	a.setBatismo(tokens[9]);

	return is;
}