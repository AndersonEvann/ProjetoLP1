/**
* @file exportar.cpp
* @brief Programa para exportar os dados do Petfera.
* @author Anderson Evangelista da Silva
* @since 29/06/2018
* @data 09/07/2018
*/

#include <string>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	//flags
	bool cflag = false, vflag = false, tflag = false;
	//parametros
	string classe, veterinario, tratador;
	//nome dos arquivos
	string arqSaida;
	//variaveis do getopt
	int index, c;
	opterr = 0;

	while((c = getopt(argc, argv, "c:v:t")) != -1) {
		switch(c) {
			case 'c':
				cflag = true;
				classe = optarg;
				break;
			case 'v':
				vflag = true;
				veterinario = optarg;
				break;
			case 't':
				tflag = true;
				tratador = optarg;
				break;
			case '?': {
					cerr << "Opcao desconhecida do caractere " << optopt << "." << endl;
					return EXIT_FAILURE;
				}
			default:
				abort();
		}
	}

	if(optind < argc) {
		//pega a img como ultimo argumento depois das opçoes
		arqSaida = argv[optind++];
	} else {
		cerr << "faltando argumento nome do arquivo de saida" << endl;
		return EXIT_FAILURE;
	}
	for(index = optind; index < argc; index++) {
		cout << "Non-option argument " << argv[index] << endl;
	}

	if(cflag) {
		//@TODO
	}
	//veterinario
	if(vflag) {
		//@TODO
	}
	//tratador
	if(tflag) {
		//@TODO
	}

	std::ifstream dadosAnimais;
	std::ifstream dadosFuncionarios;
	dadosAnimais.open("data/dadosAnimais.csv");

	try {
		dadosFuncionarios.open("./data/cadastroAnimais.csv", fstream::in | fstream::out);
		dadosAnimais.open("./data/cadastroFuncionarios.csv", fstream::in | fstream::out);
	} catch(const ifstream::failure &e) {
		cerr << "Erro de leitura. Arquivo(s) faltando na pasta ./data/." << endl;
	}

	std::ofstream dadosExport(arqSaida, std::ofstream::trunc);

	if(filtrado.bad()) {
		cerr << "O arquivo de saida informado nao pode ser aberto" << endl;
		cerr << "Abortando execucao do programa" << endl;
		return 1;
	}

	string header;
	string linha;
	std::vector<string> dados;

	while(getline(dadosAnimais, linha)) {
		filtrando.push_back(linha);
	}

	if(cFlag) {
		filtrando = filtrar(filtrando, classe, 1);
	}

	if(vFlag) {
		filtrando = filtrar(filtrando, buscarCodigo(dadosFuncionarios, veterinario, 0), 7);
	}

	if(tFlag) {
		filtrando = filtrar(filtrando, buscarCodigo(dadosFuncionarios, tratador, 1), 8);
	}

	for(std::vector<string>::iterator i = filtrando.begin(); i != filtrando.end(); i++) {
		filtrando << *i << endl;
	}

	cout << "Dados extraidos para o arquivo >>" << dadosExport "<<" << endl;

	dadosAnimais.close();
	dadosFuncionarios.close();
	dadosExport.close();

	return EXIT_SUCCESS;
}