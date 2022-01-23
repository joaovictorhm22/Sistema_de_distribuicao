#ifndef EPI_H_INCLUDED
#define EPI_H_INCLUDED

#include <iostream>
#include <string>
#include "Insumo.h"

using namespace std;

class Epi : public Insumo
{
private:
  int tipo;
  string descricao;

public:
  Epi(string nome, int quantidade, int valorUnitario, string dtVencimento, string nomeFabricante, int tipo, string descricao);
  void toString();
  void imprimeCompleto();
  //get
  int getTipo(); 
  string getDescricao();
};
Epi::Epi(string nome, int quantidade, int valorUnitario, string dtVencimento, string nomeFabricante, int tipo, string descricao) : Insumo(nome, quantidade, valorUnitario, dtVencimento, nomeFabricante, 1){ 
  this->tipo = tipo;
  this->descricao = descricao;
}

void Epi::toString()
{
  Insumo::toString();
}

void Epi::imprimeCompleto()
{
  Insumo::imprimeCompleto();
  cout << "Tipo: " << this->tipo << endl;
  cout << "Descricao: " << this->descricao << endl;
  cout << "\n\n" << endl;
}

int Epi::getTipo()
{
  return this->tipo;
}

string Epi::getDescricao()
{
  return this->descricao;
}

#endif