#ifndef MEDICAMENTO_H_INCLUDED
#define MEDICAMENTO_H_INCLUDED
#include <iostream>
#include <string>
#include "Insumo.h"

using namespace std;

class Medicamento : public Insumo{
private:
  string dosagem;
  string administracao;
  string disponibilizacao;

public:
  Medicamento(string nome, int quantidade, int valorUnitario, string dtVencimento, string nomeFabricante, string dosagem, string administracao, string disponibilizacao);
  void toString();
  void imprimeCompleto();
  //get
  string getDosagem();
  string getAdministracao();
  string getDisponibilizacao();
};

Medicamento::Medicamento(string nome, int quantidade, int valorUnitario, string dtVencimento, string nomeFabricante, string dosagem, string administracao, string disponibilizacao) : Insumo(nome, quantidade, valorUnitario, dtVencimento, nomeFabricante, 2){
  this->dosagem = dosagem;
  this->administracao = administracao;
  this->disponibilizacao = disponibilizacao;
}

void Medicamento::toString(){
  Insumo::toString();
}

void Medicamento::imprimeCompleto(){
  Insumo::imprimeCompleto();
  cout << "Dosagem: " << this->dosagem << endl;
  cout << "Administracao: " << this->administracao << endl;
  cout << "Disponibilidade: " << this->disponibilizacao << endl;
  cout << "\n\n"
       << endl;
}

string Medicamento::getDosagem(){
  return this->dosagem;
}

string Medicamento::getAdministracao(){
  return this->administracao;
}

string Medicamento::getDisponibilizacao(){
  return this->disponibilizacao;
}
#endif