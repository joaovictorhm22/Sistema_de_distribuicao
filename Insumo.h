#ifndef INSUMO_H_INCLUDED
#define INSUMO_H_INCLUDED
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

class Insumo
{
protected:
  string nome;
  int quantidade;
  int valorUnitario;
  string dtVencimento;
  string nomeFabricante;
  int tipoInsumo;

public:
  Insumo(string nome, int quantidade, int valorUnitario, string dtVencimento, string nomeFabricante, int tipoInsumo);
  virtual void toString();  
  virtual void imprimeCompleto(); 
  //get
  string getNome(); 
  int getQuantidade();
  int getValorUnitario();
  string getDTVenciment();
  string getNomeFabricante();
  int getTipoInsumo();
  //get virtual
  virtual int getTipo();
  virtual string getDescricao();
  virtual string getDosagem();
  virtual string getAdministracao();
  virtual string getDisponibilizacao();
  virtual int getQuantDoses();
  virtual int getIntervalo();
  //set
  void setQuantidade(int quantidade); 
};

Insumo::Insumo(string nome, int quantidade, int valorUnitario, string dtVencimento, string nomeFabricante, int tipoInsumo)
{
  this->nome = nome;
  this->quantidade = quantidade;
  this->valorUnitario = valorUnitario;
  this->dtVencimento = dtVencimento;
  this->nomeFabricante = nomeFabricante;
  this->tipoInsumo = tipoInsumo;
}

int Insumo::getTipoInsumo()
{
  return this->tipoInsumo;
}

void Insumo::toString() 
{
  cout << "Nome: " << this->nome << endl;
  cout << "Quantidade: " << this->quantidade << endl;
}

void Insumo::imprimeCompleto() 
{
  cout << "Nome: " << this->nome << endl;
  cout << "Quantidade: " << this->quantidade << endl;
  cout << "Valor Unitario: " << this->valorUnitario << endl;
  cout << "Data Vencimento: " << this->dtVencimento << endl;
  cout << "Nome do fabricante: " << this->nomeFabricante << endl;
  cout << "Tipo do Insumo: " << this->tipoInsumo << endl;
}

string Insumo::getNome()
{
  return this->nome;
}

int Insumo::getQuantidade()
{
  return this->quantidade;
}

int Insumo::getValorUnitario()
{
  return this->valorUnitario;
}

string Insumo::getDTVenciment()
{
  return this->dtVencimento;
}

string Insumo::getNomeFabricante()
{
  return this->nomeFabricante;
}

int Insumo::getTipo()
{
  return 0;
}

string Insumo::getDescricao()
{
  return "";
}
string Insumo::getDosagem()
{
  return "";
}

string Insumo::getAdministracao()
{
  return "";
}

string Insumo::getDisponibilizacao()
{
  return "";
}

int Insumo::getQuantDoses()
{
  return 0;
}

int Insumo::getIntervalo()
{
  return 0;
}

void Insumo::setQuantidade(int valor)
{
  this->quantidade = valor;
}

#endif