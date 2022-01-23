#ifndef PERSISTENCIA_H_INCLUDED
#define PERSISTENCIA_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Local.h"

using namespace std;

class Persistencia
{
private:
  ofstream escritaArquivo;
  ifstream leituraArquivo;

public:
  Persistencia();
  void salvarInsumos(vector<Local *> locais);
  void leInsumos(vector<Local *> locais);
};

Persistencia::Persistencia(){}


void Persistencia::salvarInsumos(vector<Local *> locais){
  escritaArquivo.open("backup.txt");
  for (int i = 0; i < locais.size(); i++){
    for (int j = 0; j < locais[i]->sizeInsumos(); j++){ 
      string linha;
      linha.append(to_string(i + 1) + ",");
      linha.append(to_string(locais[i]->getInsumo(j)->getTipoInsumo()) + ",");
      linha.append(locais[i]->getInsumo(j)->getNome() + ",");
      linha.append(to_string(locais[i]->getInsumo(j)->getQuantidade()) + ",");
      linha.append(to_string(locais[i]->getInsumo(j)->getValorUnitario()) + ",");
      linha.append(locais[i]->getInsumo(j)->getDTVenciment() + ",");
      linha.append(locais[i]->getInsumo(j)->getNomeFabricante() + ",");
      if (locais[i]->getInsumo(j)->getTipoInsumo() == 1){ //epi
        linha.append(to_string(locais[i]->getInsumo(j)->getTipo()) + ","); 
        linha.append(locais[i]->getInsumo(j)->getDescricao() + ",");
      }
      else if (locais[i]->getInsumo(j)->getTipoInsumo() == 2){// MEDICAMENTO
        linha.append(locais[i]->getInsumo(j)->getDosagem() + ",");
        linha.append(locais[i]->getInsumo(j)->getAdministracao() + ",");
        linha.append(locais[i]->getInsumo(j)->getDisponibilizacao() + ",");
      }
      else{// VACINA
      
        linha.append(to_string(locais[i]->getInsumo(j)->getTipo()) + ",");
        linha.append(to_string(locais[i]->getInsumo(j)->getQuantDoses()) + ",");
        linha.append(to_string(locais[i]->getInsumo(j)->getIntervalo()) + ",");
      }
      escritaArquivo << linha << endl;
    }
  }
  escritaArquivo.close();
}

void Persistencia::leInsumos(vector<Local *> locais){
  string linha;
  string delimitador = ",";
  vector<string> palavras{};
  size_t pos;
  int local, tipoInsumo, quantidade, valorUnitario,tipo, quantDose,intervalo;

  leituraArquivo.open("backup.txt");
  if (leituraArquivo.is_open()){ //VERIFICAR SE O ARQUIVO TA ABERTO
  
    while (getline(leituraArquivo, linha)){                                         
      string aux = linha;
      while ((pos = aux.find(delimitador)) != string::npos){
        //coloca dentro do array palavras a substring(0,pos) ------- 1,2,nome,.....
        palavras.push_back(aux.substr(0, pos));
        //apaga da string a substring(0, pos + tamanho do delimitador) -------- 2,nome,....
        aux.erase(0, pos + delimitador.length());
      }
      //stoi -> transforma um string em um int
      local = stoi(palavras[0]) - 1; //indice do vetor de locais
      tipoInsumo = stoi(palavras[1]); //tipo insumo
      quantidade = stoi(palavras[3]);
      valorUnitario = stoi(palavras[4]);
      if (tipoInsumo == 1){ //epi    
        tipo = stoi(palavras[7]);
        locais[local]->distribuiEPI(palavras[2], quantidade, valorUnitario, palavras[5], palavras[6], tipo, palavras[8]);
      }
      else if (tipoInsumo == 2){ //medicamento     
        locais[local]->distribuiMedicamento(palavras[2], quantidade, valorUnitario, palavras[5], palavras[6], palavras[7], palavras[8], palavras[9]);
      }
      else{ //vacina
        tipo = stoi(palavras[7]);
        quantDose = stoi(palavras[8]);
        intervalo = stoi(palavras[9]);
        locais[local]->distribuiVacina(palavras[2], quantidade, valorUnitario, palavras[5], palavras[6], tipo, quantDose, intervalo);
      }
      palavras.clear();  // limpa o vetor de palavras
    }
    leituraArquivo.close();
  }
}
#endif