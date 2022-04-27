#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class Menu{
private:
  void estados(); 
public:
  int menuPrincipal(); 
  int telaCadastroInsumo(); 
  int telaDeLocais(); 
  int telaEstado(); 
  int telaConsultarInsumo(); 
  int telaDistribuirInsumo(); 
};

int Menu::menuPrincipal(){ 
  int opcaoPrograma = 0;
  system ("clear");
  cout << "---------------- Programa ----------------" << endl;
  cout << "1 - Cadatro de insumo: " << endl;
  cout << "2 - Consulta de todos insumo: " << endl;
  cout << "3 - Consulta da descricao do insumo:" << endl;
  cout << "4 - Consulta de insumos por tipo: " << endl;
  cout << "5 - Distribuir insumo: " << endl;
  cout << "0 - Sair do Programe" << endl;
  cout << "Digite uma opcao: " << endl;
  cin >> opcaoPrograma;
  return opcaoPrograma;
}

int Menu::telaCadastroInsumo(){// retorna a opcao de insumo que deseja cadastrar 
  int opcao = 0;
  system ("clear");
  cout << "-------------- Cadastro de Insumo --------------" << endl;
  cout << "1 - EPI" << endl;
  cout << "2 - Medicamento" << endl;
  cout << "3 - Vacina" << endl;
  cout << "Qual Insumo voce deseja cadastrar?" << endl;
  cin >> opcao;
  return opcao;
}

int Menu::telaConsultarInsumo(){ 

  int opcao = 0;
  system ("clear");
  cout << "-------------- Consulta de Insumo --------------" << endl;
  cout << "1 - EPI" << endl;
  cout << "2 - Medicamento" << endl;
  cout << "3 - Vacina" << endl;
  cout << "Qual Insumo voce deseja consultar?" << endl;
  cin >> opcao;
  return opcao;
}

int Menu::telaDeLocais(){
  int opcao = 0;
  system("clear");
  cout << "-------------- LOCAIS --------------" << endl;
  cout << "0 - MINISTERIO DA SAUDE" << endl;
  this->estados();
  cout << "Em qual estoque voce deseja consultar o insumo?" << endl;
  cin >> opcao;
 system("clear");
  return opcao;
}

int Menu::telaEstado(){
  int opcao = 0;
  
  system("clear");
  cout << "-------------- Estados --------------" << endl;
  this->estados();
  cout << "Para qual estado você deseja distribuir?" << endl;
  cin >> opcao;
  return opcao;
}

int Menu::telaDistribuirInsumo(){
  int opcao = 0;
  system("clear");
  cout << "-------------- Distribui de Insumo --------------" << endl;
  cout << "1 - EPI" << endl;
  cout << "2 - Medicamento" << endl;
  cout << "3 - Vacina" << endl;
  cout << "Qual Insumo voce deseja distribuir?" << endl;
  cin >> opcao;
  return opcao;
}

void Menu::estados(){
  string estados_[] = {"Acre", "Alagoas", "Amapa", "Amazonas", "Bahia", "Ceara", "Distrito Federal", "Espirito Santo", "Goias", "Maranhão", "Mato Grosso", "Mato Grosso do Sul", "Minas Gerais", "Para", "Paraiba", "Parana", "Pernambuco", "Piaui", "Rio de Janeiro", "Rio Grande do Norte", "Rio Grande do Sul", "Rondonia", "Roraima", "Santa Catarina", "Sao Paulo", "Sergipe", "Tocantins"};
  for (int i = 0; i < 27; i++){
    cout << i+1 << "-" << estados_[i] << endl;
  }
  
}

#endif