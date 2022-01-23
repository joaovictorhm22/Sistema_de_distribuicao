#ifndef VACINA_H_INCLUDED
#define VACINA_H_INCLUDED

#include <iostream>
#include <string>
#include "Insumo.h"

using namespace std;

class Vacina : public Insumo{
private:
  int tipo;
  int quantDoses;
  int intervalo;

public:
  Vacina(string nome, int quantidade, int valorUnitario, string dtVencimento, string nomeFabricante, int tipo, int quantDoses, int intervalo);
  void toString();
  void imprimeCompleto();
  //get
  int getTipo();
  int getQuantDoses();
  int getIntervalo();
};

Vacina::Vacina(string nome, int quantidade, int valorUnitario, string dtVencimento, string nomeFabricante, int tipo, int quantDoses, int intervalo) : Insumo(nome, quantidade, valorUnitario, dtVencimento, nomeFabricante, 3){
  this->tipo = tipo;
  this->quantDoses = quantDoses;
  this->intervalo = intervalo;
}

void Vacina::toString(){
  Insumo::toString();
}

void Vacina::imprimeCompleto(){
  Insumo::imprimeCompleto();
  cout << "Tipo: " << this->tipo << endl;
  cout << "Quantidade de doses: " << this->quantDoses << endl;
  cout << "Intervalo: " << this->intervalo << endl;
}

int Vacina::getTipo(){
  return this->tipo;
}

int Vacina::getQuantDoses(){
  return this->quantDoses;
}

int Vacina::getIntervalo(){
  return this->intervalo;
}
#endif