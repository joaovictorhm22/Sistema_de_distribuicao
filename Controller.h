#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Local.h"
#include "Menu.h"
#include "Persistencia.h"
#include <stdlib.h>
using namespace std;

class Controller{
private:
  vector<Local *> locais; 
  Menu *menu; 
  Persistencia *persistencia;
  void imprimeTudo(int indice); 
  void imprimeTudoPorTipo(int indice, int tipo); 
  void listarInsumo(int tipo); 
  void imprimeTudoComDescricao(int indice); 

public:
  Controller();
  void main(); 
  void cadastrarInsumosMS(); 
  void consultaInsumos(); 
  void consultaInsumosDescricao(); 
  void consultaInsumosPorTipo(); 
  void distribuiInsumos(); 
};

Controller::Controller(){
  this->menu = new Menu(); 
  this->persistencia = new Persistencia();
  string estados[] = {"Ministerio da Saude", "Acre", "Alagoas", "Amapa", "Amazonas", "Bahia", "Ceara", "Distrito Federal", "Espirito Santo", "Goias", "Maranhão", "Mato Grosso", "Mato Grosso do Sul", "Minas Gerais", "Para", "Paraiba", "Parana", "Pernambuco", "Piaui", "Rio de Janeiro", "Rio Grande do Norte", "Rio Grande do Sul", "Rondonia", "Roraima", "Santa Catarina", "Sao Paulo", "Sergipe", "Tocantins"};
  for (int i = 0; i < 28; i++){
    this->locais.push_back(new Local(estados[i], i));
  }
}

void Controller::main(){
  int opcaoPrograma = 0;
  bool executanto = true;
  this->persistencia->leInsumos(this->locais);
  while (executanto){
    opcaoPrograma = this->menu->menuPrincipal(); //receber a ocpcao do menuprincipal
    switch (opcaoPrograma){
    case 0: //se for 0 vai salvar no arquivo as informacoes e encerrar o programa  
      this->persistencia->salvarInsumos(this->locais);
      executanto = false;
      break;
    case 1:
    //  system("cls");  
      this->cadastrarInsumosMS(); 
   //   system("pause");
     // system("cls"); 
      break;
    case 2:
      this->consultaInsumos();
      system("pause");
    //  system("cls");
      break;
    case 3:
      system("cls");
      this->consultaInsumosDescricao(); 
    
      break;
    case 4:
      system("cls");
      this->consultaInsumosPorTipo(); 
   
      break;
    case 5:
      this->distribuiInsumos(); 
      system("pause");
   //   system("cls");
      break;
    default:
      cout << "Opcao invalida" << endl;
      break;
    }
  }
}

void Controller::cadastrarInsumosMS(){ 
  int opcao = 0;
  opcao = this->menu->telaCadastroInsumo(); // 1-EPI 2-MEDICAMENTO 3-VACINA
  system("cls"); 
  switch (opcao){
  case 1: //EPI
  //system("cls"); 
    this->locais[0]->cadastraEPI();  // cadastra no MS que é o indice 0 do vector de locais um objeto EPI
    break;
  case 2:
    this->locais[0]->cadastraMedicamento(); // cadastra no MS que é o indice 0 do vector de locais um objeto MEDICAMENTO
    break;
  case 3:
    this->locais[0]->cadastraVacina(); // cadastra no MS que é o indice 0 do vector de locais um objeto VACINA
    break;
  default:
    cout << "Insumo invalido" << endl;
    break;
  }
}

void Controller::consultaInsumos(){ 
  int localEstoque = 0;
  localEstoque = this->menu->telaDeLocais(); // recebe o local onde quer consultar
  if (localEstoque >= 0 && localEstoque < 28){
    this->imprimeTudo(localEstoque);
  }
  else{
    cout << "Local invalido" << endl;
  }
}

void Controller::consultaInsumosDescricao(){
  int localEstoque = 0;
  localEstoque = this->menu->telaDeLocais();
  if (localEstoque >= 0 && localEstoque < 28){
    this->imprimeTudoComDescricao(localEstoque);
  }
  else{
    cout << "Local invalido" << endl;
  }
}

void Controller::consultaInsumosPorTipo(){
 // system("cls");
  int opcao = 0;
  opcao = this->menu->telaConsultarInsumo();  //1-EPI 2- MEDICAMENTO 3- VACINA
  switch (opcao){
  case 1: //listar epi
    this->listarInsumo(1);
    break;
  case 2: //listar medicamento
    this->listarInsumo(2);
    break;
  case 3: //listar vacina
    this->listarInsumo(3);
    break;
  default:
    cout << "Opcao invalida" << endl;
    break;
  }
}

void Controller::distribuiInsumos(){ 
  int opcao = this->menu->telaDistribuirInsumo(); // 1-epi 2-medicamento 3-vacina
  if (opcao > 0 && opcao < 4){
    int local = this->menu->telaEstado(); //opcao de estados
    if (local >= 0 && local < 28){
      string nome;
      cout << "Qual o nome do produto: " << endl;
      cin >> nome;
      int quantidade = 0;
      cout << "Qual a quantidade para a distribuicao: " << endl;
      cin >> quantidade;
      int tamanho = 0,tamanho2=0;
      tamanho = this->locais[0]->sizeInsumos();
      tamanho2= this->locais[local]->sizeInsumos();
      int incremento=0;
       //pegando tamanho do ministerio da saude que é o estoque de onde será distribuido
      int confirmaDistribuicao = this->locais[0]->distribui(nome, quantidade);
      if(tamanho2>0){ //se ja existir algum insumo naquele estado
        for(int i = 0; i<tamanho2 ; i++){
          if(this->locais[local]->getInsumo(i)->getNome().compare(nome)==0){
           incremento = this->locais[local]->getInsumo(i)->getQuantidade()+quantidade;
          //  cout<<quantidade<<endl;

            this->locais[local]->getInsumo(i)->setQuantidade(incremento);
          }
        }
      }
      if(incremento ==0){
        if (confirmaDistribuicao >= 0){ //se a quantidade que vai ser retirada é menor que a do estoque 
          int valorUnitarios = this->locais[0]->getInsumo(confirmaDistribuicao)->getValorUnitario();
      //   string nome= this->locais[0]->getInsumo(confirmaDistribuicao)->getNome();
          string dtVencimento = this->locais[0]->getInsumo(confirmaDistribuicao)->getDTVenciment();
          string nomeFabricante = this->locais[0]->getInsumo(confirmaDistribuicao)->getNomeFabricante();
          int tipoInsumo = this->locais[0]->getInsumo(confirmaDistribuicao)->getTipoInsumo();
          if (opcao == 1){
            //criar nova epi
            int tipo = this->locais[0]->getInsumo(confirmaDistribuicao)->getTipo();
            string descricao = this->locais[0]->getInsumo(confirmaDistribuicao)->getDescricao();
            this->locais[local]->distribuiEPI(nome, quantidade, valorUnitarios, dtVencimento, nomeFabricante, tipo, descricao);
          }
          else if (opcao == 2){
            //criar novo medicamento
            string dosagem = this->locais[0]->getInsumo(confirmaDistribuicao)->getDosagem();
            string administracao = this->locais[0]->getInsumo(confirmaDistribuicao)->getAdministracao();
            string disponibilizacao = this->locais[0]->getInsumo(confirmaDistribuicao)->getDisponibilizacao();
            this->locais[local]->distribuiMedicamento(nome, quantidade, valorUnitarios, dtVencimento, nomeFabricante, dosagem, administracao, disponibilizacao);
          }
          else{
            //criar nova vacina
            int tipo = this->locais[0]->getInsumo(confirmaDistribuicao)->getTipo();
            int quantDoses = this->locais[0]->getInsumo(confirmaDistribuicao)->getQuantDoses();
            int intervalo = this->locais[0]->getInsumo(confirmaDistribuicao)->getIntervalo();
            this->locais[local]->distribuiVacina(nome, quantidade, valorUnitarios, dtVencimento, nomeFabricante, tipo, quantDoses, intervalo);
          }
        }
        else if (confirmaDistribuicao == -1){ // SE REMOVEU TODO O ESTOQUE DAQUELE INSUMO 
          //"clonar" insumo aux (atributo Local)
          string nome = this->locais[0]->aux->getNome();
          int quantidade = this->locais[0]->aux->getQuantidade();
          int valorUnitario = this->locais[0]->aux->getValorUnitario();
          string dtVencimento = this->locais[0]->aux->getDTVenciment();
          string nomeFabricante = this->locais[0]->aux->getNomeFabricante();
          if (this->locais[0]->aux->getTipoInsumo() == 1){ //SE FOR EPI
            int tipo = this->locais[0]->aux->getTipo();
            string descricao = this->locais[0]->aux->getDescricao();
            this->locais[local]->distribuiEPI(nome, quantidade, valorUnitario, dtVencimento, nomeFabricante, tipo, descricao);
          }
          else if (this->locais[0]->aux->getTipoInsumo() == 2){ //SE FOR MEDICAMENTO
            string dosagem = this->locais[0]->aux->getDosagem();
            string administracao = this->locais[0]->aux->getAdministracao();
            string disponibilizacao = this->locais[0]->aux->getDisponibilizacao();
            this->locais[local]->distribuiMedicamento(nome, quantidade, valorUnitario, dtVencimento, nomeFabricante, dosagem, administracao, disponibilizacao);
          }
          else if (this->locais[0]->aux->getTipoInsumo() == 3){ //SE FOR VACINA
            int tipo = this->locais[0]->aux->getTipo();
            int quantDoses = this->locais[0]->aux->getQuantDoses();
            int intervalo = this->locais[0]->aux->getIntervalo();
            this->locais[local]->distribuiVacina(nome, quantidade, valorUnitario, dtVencimento, nomeFabricante, tipo, quantDoses, intervalo);
          }
          this->locais[0]->aux = NULL;
        }
      }
    }
    else{
      cout << "Local invalida" << endl;
    }
  }
  else{
    cout << "Opcao invalida" << endl;
  }
}

void Controller::imprimeTudo(int indice){ 
  int tamanho = this->locais[indice]->sizeInsumos(); // pegar o tamanho do vetor dos insumos
  system("cls");
  cout << "------------------ EPI ------------------" << endl;
  for (int i = 0; i < tamanho; i++){ //vai percorrer o vetor de insumos daquele local
    if (this->locais[indice]->getInsumo(i)->getTipoInsumo() == 1){ //se o tipo de insumo for epi    
      this->locais[indice]->getInsumo(i)->toString(); //imprime o nome e quantidade no estoque daquele local
    }
  }
  cout << "-------------- Medicamento --------------" << endl;
  for (int i = 0; i < tamanho; i++){
    if (this->locais[indice]->getInsumo(i)->getTipoInsumo() == 2){     
      this->locais[indice]->getInsumo(i)->toString();
    }
  }
  cout << "---------------- Vacina ----------------" << endl;
  for (int i = 0; i < tamanho; i++){
    if (this->locais[indice]->getInsumo(i)->getTipoInsumo() == 3){     
      this->locais[indice]->getInsumo(i)->toString();
    }
  }
}

void Controller::imprimeTudoPorTipo(int indice, int tipo) 
{
  system("cls");
  if (tipo == 1){
    cout << "------------------ EPI ------------------" << endl;
    int tamanho = this->locais[indice]->sizeInsumos();
    for (int i = 0; i < tamanho; i++){
      if (this->locais[indice]->getInsumo(i)->getTipoInsumo() == 1){
        this->locais[indice]->getInsumo(i)->toString();
      }
    }
  }
  else if (tipo == 2){
    cout << "-------------- Medicamento --------------" << endl;
    int tamanho = this->locais[indice]->sizeInsumos();
    for (int i = 0; i < tamanho; i++){
      if (this->locais[indice]->getInsumo(i)->getTipoInsumo() == 2){
        this->locais[indice]->getInsumo(i)->toString();
      }
    }
  }
  else if (tipo == 3){
    cout << "---------------- Vacina ----------------" << endl;
    int tamanho = this->locais[indice]->sizeInsumos();
    for (int i = 0; i < tamanho; i++){
      if (this->locais[indice]->getInsumo(i)->getTipoInsumo() == 3){
        this->locais[indice]->getInsumo(i)->toString();
      }
    }
  }
  system("pause");
  system("cls");
}

void Controller::imprimeTudoComDescricao(int indice){ 
  int tamanho = this->locais[indice]->sizeInsumos();
  system ("cls");
  cout << "------------------ EPI ------------------" << endl;
  for (int i = 0; i < tamanho; i++){
    if (this->locais[indice]->getInsumo(i)->getTipoInsumo() == 1){
      this->locais[indice]->getInsumo(i)->imprimeCompleto();
    }
  }
  cout << "-------------- Medicamento --------------" << endl;
  for (int i = 0; i < tamanho; i++){
    if (this->locais[indice]->getInsumo(i)->getTipoInsumo() == 2){
      this->locais[indice]->getInsumo(i)->imprimeCompleto();
    }
  }
  cout << "---------------- Vacina ----------------" << endl;
  for (int i = 0; i < tamanho; i++){
    if (this->locais[indice]->getInsumo(i)->getTipoInsumo() == 3){
      this->locais[indice]->getInsumo(i)->imprimeCompleto();
    }
  }
  system ("pause");
  //system("cls");
}

void Controller::listarInsumo(int tipo){ 
  int localEstoque = 0;
  localEstoque = this->menu->telaDeLocais(); //LOCAL QUE DESEJA CONSULTAR DE 0 A 27 
  if (localEstoque >= 0 && localEstoque < 28){
    this->imprimeTudoPorTipo(localEstoque, tipo);
  }
  else {
    cout << "Local invalido" << endl;
  }
}

#endif