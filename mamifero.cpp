#include "mamifero.h"

Mamifero::Mamifero(string corPelo_) : corPelo(corPelo_) {}

Mamifero::Mamifero(int id_, string classe_, string nome_, string cientifico_,
		char sexo_, float tamanho_, string dieta_, int veterinario_,
		int tratador_, string batismo_, string corPelo_) : 
	Animal() {
		id = id_;
		classe = classe_;
		nome = nome_;
		cientifico = cientifico_;
		sexo = sexo_;
		tamanho = tamanho_;
		dieta = dieta_;
		veterinario = veterinario_;
		tratador = tratador_;
		batismo = batismo_;
		corPelo = corPelo_;
	}

Mamifero::~Mamifero() {}