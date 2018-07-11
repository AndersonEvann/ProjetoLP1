#include "petfera.h"
#include "mamifero.h"

Petfera::Petfera(string nome_) : nome(nome_) {}

Petfera::~Petfera() {
	/** @TODO Transferir todos os dados de volta para o arquivo */
}

//== Métodos relacionado a Animal.

void Petfera::cadastrar(Animal a) {
	std::pair<std::map<int, Animal>::iterator, bool> ret;
	ret = this->animais.insert(std::pair<int, Animal>(a.getId(), a));
	if(ret.second == false) {
		std::cout << "Um animal com o id " << ret.first->first
		<< " já foi cadastrado." << std::endl;
	}
}

void Petfera::remover(Animal a) {
	this->animais.erase(a.getId());
}

void Petfera::alterar(Animal a) {
	this->animais.erase(a.getId());
	this->cadastrar(a);
}

//== Métodos relacionados a Funcionario.

void Petfera::cadastrar(Funcionario f) {
	std::pair<std::map<int, Funcionario>::iterator, bool> ret;
	ret = this->funcionarios.insert(std::pair<int, Funcionario>(f.getId(), f));
	if(ret.second == false) {
		std::cout << "Um funcionario com o id " << ret.first->first
		<< " já foi cadastrado." << std::endl;
	}
}

void Petfera::remover(Funcionario f) {
	this->funcionarios.erase(f.getId());
}

void Petfera::alterar(Funcionario f) {
	this->funcionarios.erase(f.getId());
	this->cadastrar(f);
}

void Petfera::carregarDados() {
	// Abrindo os arquivos
	fstream dadosAnimais;
	fstream dadosFuncionarios;
	string animalFile = "./data/cadastroAnimais.csv";
	string funcionarioFile = "./data/cadastroFuncionarios.csv";

	dadosAnimais.exceptions(fstream::failbit | fstream::badbit);
	dadosFuncionarios.exceptions(fstream::failbit | fstream::badbit);

	try {
		dadosAnimais.open(animalFile, fstream::in | fstream::out);
	} catch(const ifstream::failure &e) {
		std::cerr << "Erro ao carregar arquivo: " << animalFile << std::endl;
	} try {
		dadosFuncionarios.open(funcionarioFile, fstream::in | fstream::out);
	} catch(const ifstream::failure &e) {
		std::cerr << "Erro ao carregar arquivo: " << funcionarioFile << std::endl;
	}

	//Carregando cabeçalho
	string header;
	getline(dadosAnimais, header);

	//Carregando os dados
	Animal ani;
	string line;
	stringstream linestream;

	getline(dadosAnimais, line);
	linestream << line;
	linestream >> ani;
	this->cadastrar(ani);
}

void Petfera::opcaoDeEntrada(char &opcao) {
	try {
		cin >> opcao;
	} catch(istream::failure e) {
		std::cerr << "Valor invalido" << std::endl;
	}
}

void Petfera::simOUnao(bool &valor) {
	valor = false;
	bool flag = true;
	char opcao = ' ';
	while(flag) {
		this->opcaoDeEntrada(opcao);
		switch(opcao) {
			case 's': case 'S':
				valor = true;
				flag = false;
				break;
			case 'n': case 'N':
				flag = false;
				break;
			default:
				std::cerr << ">> opcao invalida" << std::endl;
				break;
		}
	}
}

void Petfera::menuPrincipal() {
	this->carregarDados();
	char opcao = ' ';
	std::cout << "Bem-vindo ao " << this->nome << "!" << std::endl;
	while(opcao != '0') {
		std::cout << ">>> Digite uma opcao"             << std::endl;

		std::cout << "(1)Cadastrar animal"              << std::endl
		          << "(2)Remover animal"                << std::endl
		          << "(3)Alterar os dados de um animal" << std::endl
		          << "(4)Consultar um animal"           << std::endl;

		std::cout << "(5)Cadastrar um funcionario"           << std::endl
		          << "(6)Remover um funcionario"             << std::endl
		          << "(7)Alterar os dados de um funcionario" << std::endl
		          << "(8)Consultar um funcionario"           << std::endl;

		std::cout << "(0)Sair." << std::endl;
		// @TODO substituir esse cin por getline e pegar tudo com string, depois tratar.
		this->opcaoDeEntrada(opcao);
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		this->menuDeEscolha(opcao);
	}
}

void Petfera::menuDeEscolha(char opcao) { // @TODO Implementar as outras opções */
	switch(opcao) {
		case '0':
			break; // Opcao de sair.
		case '1': //Opcao cadastrar animal.
			this->infoEntradaAnimal();
			break;
		case '2': // Opcao remover animal.
			{
				int id;
				std::cout << ">> Digite o identificador do animal:" << std::endl;
				try {
					cin >> id;
				} catch(istream::failure e) {
					std::cerr << ">>valor invalido" << std::endl;
				}
				Animal animal(id, "");
				this->remover(animal);
				break;
			}
		case '3': // Opçao alterar dados de um animal.
			{			
				int id;
				std::cout << ">> Digite o identificador do animal:" << std::endl;
				try {
					cin >> id;
				} catch(istream::failure e) {
					std::cerr << ">> Valor invalido" << std::endl;
				}
				Animal animal(id, "");
				this->remover(animal);
				this->infoEntradaAnimal();
				break;
			}
		default:
			std::cerr << ">> opcao invalida" << std::endl;
			break;
	}
}

void Petfera::infoEntradaAnimal() {
	bool anfibio = false, ave = false, mamifero = false,
	reptil = false, silvestre = false, nativo = false;
	char opcao;
	// Pegando informações gerais.
	cout << "Selecione uma classe de animal:" << endl
	     << "(1)Anfibio"  << endl
	     << "(2)Ave"      << endl
	     << "(3)Mamifero" << endl
	     << "(4)Reptil"   << endl;

	this->opcaoDeEntrada(opcao);
	switch(opcao) {
		case '1':
			anfibio = true;
			break;
		case '2':
			ave = true;
			break;
		case '3':
			mamifero = true;
			break;
		case '4':
			reptil = true;
			break;
		default:
			cerr << ">> opção invalida" << endl;
			break;
	}
	cout << "O animal é silvestre?" << endl
		 << "(s)Sim" << endl
		 << "(n)Nao" << endl;

	this->simOUnao(silvestre);
	if(silvestre) {
		cout << "O animal é nativo?" << endl
			 << "(s)Sim" << endl
			 << "(n)Nao" << endl;
		this->simOUnao(nativo);
	}

	//=== Parte principal da função

	//Pegando as informações comuns aos animais
	int id;
	cout << "Informe o id do aniaml." << endl;
	cin >> id;

	string classe = anfibio ? "Amphibia" : reptil ? "Reptilia" : ave ? "Aves" : mamifero ? "Mammalia" : "";
	
	string nome;
	cout << "Digite o nome popular da especie:" << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, nome);

	string cientifico;
	cout << "Digite o nome cientifico da especie:" << endl;
	getline(cin, cientifico);

	string sexo;
	cout << "Digite o sexo do animal(M/F):" << endl;
	getline(cin, sexo);

	string tamanho;
	cout << "Digite o tamanho do animal em metros:" << endl;
	getline(cin, tamanho);

	string dieta;
	cout << "O que o animal come?" << endl;
	getline(cin, dieta);

	string veterinario;
	cout << "Digite o identificador do Veterinário responsavel:" << endl;
	getline(cin, veterinario);

	string tratador;
	cout << "Digite o identificador do tratador responsavel:" << endl;
	getline(cin, tratador);

	string batismo;
	cout << "Digite o nome de batismo:" << endl;
	getline(cin, batismo);

	try {
		Animal *an;
		an = new Animal(int(id), classe, nome, cientifico, sexo[0], stof(tamanho),
			dieta, stoi(veterinario), stoi(tratador), batismo);
		cadastrar(*an);
	} catch(invalid_argument &i) {
		cerr << "Argumento invalido" << endl;
	}
}

Animal *Petfera::infoEntradaClasse(bool mamifero, bool reptil, bool ave, bool anfibio) {
	//Pegando as informações especificas de cada classe
	//Mamifero
	string corPelo;
	//Reptil
	bool venenoso;
	string tipoVeneno;
	//Ave
	//int tamanhoBico;
	//int envergadura
	//Anfibio
	//int totalMudas;
	string ultimaMuda;

	if(mamifero) {
		cout << "Qual a cor do pelo?" << endl;
		getline(cin, corPelo);
		try {
			Mamifero *m;
			// @TODO Faltando passar id(resolver isso)
			m = new Mamifero('0', "", "", "", ' ', 0, "", 0, 0, "", corPelo);
			Animal *an = m;
			return an;
		} catch(invalid_argument &i) {
			cerr << "Argumento invalido" << endl;
		}
	}

	if(reptil) {
		cout << "O animal é venenoso?" << endl;
		simOUnao(venenoso);
	}

	if(ave) {
		cout << "Qual a cor do pelo?" << endl;
		getline(cin, corPelo);
	}

	if(anfibio) {
		cout << "Qual a cor do pelo?" << endl;
		getline(cin, corPelo);
	}

	return nullptr;
}

ostream &operator<<(ostream &os, const Petfera &pf) {
	//Header
	os << "Id, Classe, Nome, Nome cientifico, Sexo, Tamanho(m), Dieta, Veterinario responsavel, Tratador responsavel, Nome de batismo."
	   //<< ",Total de mudas, Ultima muda, Tamanho do bico, envergadura"
	   << endl;

	for(auto const &x : pf.animais) {
		os << x.second; //Animal
	}

	return os;
}
