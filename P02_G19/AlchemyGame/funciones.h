#pragma once
void dataLoad();
bool myfunction(std::string &a, std::string &b);
void leerComando(std::string &comandoJugador, std::vector<std::string> &currentList, std::vector<std::string> &elementsBasics);
void add(int numero, std::vector<std::string> &currentList);
void _delete(int numero, std::vector<std::string> &currentList);
void addBasics(std::vector <std::string> &currentList, std::vector<std::string> &elements_basics);
void informasao(int &indice, std::vector<std::string> &currentList);
void clean(std::vector<std::string> &currentList);
void Tutorial();

enum class status
{
	_Clave1,
	_Clave2,
	_Value
};

