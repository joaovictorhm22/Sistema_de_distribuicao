#ifndef LOCAL_H_INCLUDED
#define LOCAL_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Insumo.h"
#include "Epi.h"
#include "Medicamento.h"
#include "Vacina.h"
#include <stdlib.h>
using namespace std;

class Local
{
private:
  string nome;
  int tipo;
  vector<Insumo *> insumo; 

public:
  static Insumo *aux;
  Local(string nome, int tipo); 
  int sizeInsumos(); 
  void cadastraEPI(); 
  void cadastraMedicamento(); 
  void cadastraVacina(); 
  Insumo *getInsumo(int indice); 
  int distribui(string nome, int quantidade);
  void removerInsumo(int indice);
  void distribuiEPI(string nome, int quantidade, int valorUnitario, string dtVencimento, string nomeFabricante, int tipo, string descricao);
  void distribuiMedicamento(string nome, int quantidade, int valorUnitario, string dtVencimento, string nomeFabricante, string dosagem, string administracao, string disponibilizacao);
  void distribuiVacina(string nome, int quantidade, int valorUnitario, string dtVencimento, string nomeFabricante, int tipo, int quantDoses, int intervalo);
   // OK NAS DISTRIBUICOES EPI MEDICAMENTO E VACINA
};

Local::Local(string nome, int tipo) 
{
  this->nome = nome;
  this->tipo = tipo;
}

Insumo *Local::aux = NULL; 

int Local::sizeInsumos(){ 
  return this->insumo.size();
}
void Local::cadastraEPI(){
  cout << "---------------- EPI ----------------" << endl;
  string nome, dtVencimento, nomeFabricante, descricao;
  int quantidade, valorUnitario, tipo;
  cout << "Digite o nome do EPI: " << endl;
  cin >> nome;
  cout << "Digite a quantidade: " << endl;
  cin >> quantidade;
  int tamanho = sizeInsumos(), incremento=0;

  if(tamanho!=0){
    
    for(int i=0; i<tamanho;i++){
      if(this->insumo[i]->getNome().compare(nome)==0){
       incremento = this->insumo[i]->getQuantidade()+quantidade;
       this->insumo[i]->setQuantidade(incremento);
       
      } 
    }
  }
  if(incremento==0){
    cout << "Digite o valor unitario: " << endl;
    cin >> valorUnitario;
    cout << "Digite a data de vencimento(DD/MM/AAAA): " << endl;
    cin >> dtVencimento;
    cout << "Digite o nome do fabricante: " << endl;
    cin >> nomeFabricante;   
    cout << "Digite o tipo: " << endl;
    cin >> tipo;
    cout << "Digite a descricao: " << endl;
    cin >> descricao;
    this->insumo.push_back(new Epi(nome, quantidade, valorUnitario, dtVencimento, nomeFabricante, tipo, descricao));
    
  }
}

void Local::cadastraMedicamento(){ 
  cout << "---------------- MEDICAMENTO ----------------" << endl;
  string nome, dtVencimento,nomeFabricante, dosagem, administracao, disponibilizacao;
  int quantidade; int valorUnitario;
  cout << "Digite o nome do medicamento: " << endl;
  cin >> nome;
  cout << "Digite a quantidade: " << endl;
  cin >> quantidade;
  int tamanho = sizeInsumos(), incremento=0;
  
  if(tamanho!=0){
    
    for(int i=0; i<tamanho;i++){
      if(this->insumo[i]->getNome().compare(nome)==0){
       incremento = this->insumo[i]->getQuantidade()+quantidade;
       this->insumo[i]->setQuantidade(incremento);
      } 
    }
  }
  if(incremento==0){
    cout << "Digite o valor unitario: " << endl;
    cin >> valorUnitario;
    cout << "Digite a data de vencimento(DD/MM/AAAA): " << endl;
    cin >> dtVencimento;
    cout << "Digite o nome do fabricante: " << endl;
    cin >> nomeFabricante;
    cout << "Digite a dosagem: " << endl;
    cin >> dosagem;
    cout << "Digite a administracao: " << endl;
    cin >> administracao;
    cout << "Digite a disponibilizacao: " << endl;
    cin >> disponibilizacao;
  this->insumo.push_back(new Medicamento(nome, quantidade, valorUnitario, dtVencimento, nomeFabricante, dosagem, administracao, disponibilizacao));
  }
}


void Local::cadastraVacina(){
  cout << "---------------- VACINA ----------------" << endl;
  string nome, dtVencimento,nomeFabricante;
  int quantidade,valorUnitario,tipo, quantDoses, intervalo;
  cout << "Digite o nome da vacina: " << endl;
  cin >> nome;
  cout << "Digite a quantidade: " << endl;
  cin >> quantidade; 
   int tamanho = sizeInsumos(), incremento=0;
  if(tamanho!=0){
    for(int i=0; i<tamanho;i++){
      if(this->insumo[i]->getNome().compare(nome)==0){
       incremento = this->insumo[i]->getQuantidade()+quantidade;
       this->insumo[i]->setQuantidade(incremento);
      } 
    }
  }
  if(incremento ==0){
  cout << "Digite o valor unitario: " << endl;
  cin >> valorUnitario;
  cout << "Digite a data de vencimento(DD/MM/AAAA): " << endl;
  cin >> dtVencimento; 
  cout << "Digite o nome do fabricante: " << endl;
  cin >> nomeFabricante;
  cout << "Digite o tipo: " << endl;
  cin >> tipo;
  cout << "Digite a quantidade de doses: " << endl;
  cin >> quantDoses;
  cout << "Digite o intervalo: " << endl;
  cin >> intervalo;
  this->insumo.push_back(new Vacina(nome, quantidade, valorUnitario, dtVencimento, nomeFabricante, tipo, quantDoses, intervalo));
  }
  
}

Insumo *Local::getInsumo(int indice){ // retornando o insumo desejado ok
  return this->insumo[indice];
}

int Local::distribui(string nome, int quantidade){
  int tamanho = sizeInsumos();
  int novoValor=0;
  for (int i = 0; i < tamanho; i++){ //percorrendo o vetor de insumos
    if (this->insumo[i]->getNome().compare(nome) == 0) {// verificando se existe no estoque 
      if (this->insumo[i]->getQuantidade() > quantidade) {//verificando se tem quantidade superior ao que é desejado  
        int novoValor = this->insumo[i]->getQuantidade() - quantidade;      // retira a quantidade desejada do estoque do MS
        this->insumo[i]->setQuantidade(novoValor); // mdofica para  o valor atualizado do estoque
        return i;

      }
      else if (this->insumo[i]->getQuantidade() == quantidade){ // se for igual ao que tem no estoque
        //clonando o objeto para o insumo aux
        //adicionando propriedade em comum de insumos
        string nome = this->insumo[i]->getNome();
        int quantidade = this->insumo[i]->getQuantidade();
        int valorUnitario = this->insumo[i]->getValorUnitario();
        string dtVencimento = this->insumo[i]->getDTVenciment();
        string nomeFabricante = this->insumo[i]->getNomeFabricante();
        if (this->insumo[i]->getTipoInsumo() == 1){
          //criar um epi adicionando propriedades especificas do EPI 
          int tipo = this->insumo[i]->getTipo();
          string descricao = this->insumo[i]->getDescricao();
          Local::aux = new Epi(nome, quantidade, valorUnitario, dtVencimento, nomeFabricante, tipo, descricao);
        }
        else if (this->insumo[i]->getTipoInsumo() == 2){
          //criar um medicamento
          //adicionando propriedades especificas do MEDICAMENTO
          string dosagem = this->insumo[i]->getDosagem();
          string administracao = this->insumo[i]->getAdministracao();
          string disponibilizacao = this->insumo[i]->getDisponibilizacao();
          Local::aux = new Medicamento(nome, quantidade, valorUnitario, dtVencimento, nomeFabricante, dosagem, administracao, disponibilizacao);
        }
        else if (this->insumo[i]->getTipoInsumo() == 3){
          //criar uma vacina
          int tipo = this->insumo[i]->getTipo();
          int quantDoses = this->insumo[i]->getQuantDoses();
          int intervalo = this->insumo[i]->getIntervalo();
          Local::aux = new Vacina(nome, quantidade, valorUnitario, dtVencimento, nomeFabricante, tipo, quantDoses, intervalo);
        }
        int elementoRemovido = i;
        this->insumo.erase(this->insumo.begin() + elementoRemovido);
        
        return -1;
      }
      else{
        cout << "Imposivel remover uma quantidade maior que a no estoque" << endl;
      
        return -3;
      }
    }
  }

  cout << "INSUMO NaO DISPONIVEL NO ESTOQUE! " << endl;
  return -2;
}

void Local::distribuiEPI(string nome, int quantidade, int valorUnitario, string dtVencimento, string nomeFabricante, int tipo, string descricao){
  this->insumo.push_back(new Epi(nome, quantidade, valorUnitario, dtVencimento, nomeFabricante, tipo, descricao));
}

void Local::distribuiMedicamento(string nome, int quantidade, int valorUnitario, string dtVencimento, string nomeFabricante, string dosagem, string administracao, string disponibilizacao){
  this->insumo.push_back(new Medicamento(nome, quantidade, valorUnitario, dtVencimento, nomeFabricante, dosagem, administracao, disponibilizacao));
}

void Local::distribuiVacina(string nome, int quantidade, int valorUnitario, string dtVencimento, string nomeFabricante, int tipo, int quantDoses, int intervalo){
  this->insumo.push_back(new Vacina(nome, quantidade, valorUnitario, dtVencimento, nomeFabricante, tipo, quantDoses, intervalo));
}

#endif