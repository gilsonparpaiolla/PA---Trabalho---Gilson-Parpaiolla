#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct tInvestimento{
  float montInicial, juroAno, periodoAno;
};

//Criação do Nó
struct tNo{
  tInvestimento info;
  tNo* proximo;
};

tNo* criaNo (tInvestimento item){
  tNo* no = new tNo;

  no -> info = item;
  no -> proximo = NULL;

  return no;
}
/////////////////////

struct tLista{
  tNo* primeiro;
  tNo* ultimo;
  tNo* marcador;
  int tamanho = 0;
};

int obterTamanho(tLista* pLista){
  return pLista -> tamanho;
}

bool listaVazia(tLista* pLista){
  return (pLista->tamanho == 0);
}

bool finalLista(tLista* pLista){
  return (pLista->marcador == 0);
}

void incluirNoFim(tLista* pLista, tInvestimento info){
  tNo* no;
  no = criaNo(info);

  if (listaVazia(pLista)){
    pLista -> primeiro = no;
  }else{
    pLista -> ultimo -> proximo = no;
  }

  pLista -> ultimo = no;
  pLista -> marcador = no;
  pLista -> tamanho++;
}

void imprimirLista(tLista* pLista){
  pLista -> marcador = pLista -> primeiro;

  while(!finalLista(pLista)){
    tInvestimento informacao = pLista -> marcador -> info;

    cout << "Montante Investido: " << informacao.montInicial << endl;
    cout << "Juro ao ano: " << informacao.juroAno << endl;
    cout << "Periodo em anos: " << informacao.periodoAno << endl;

    pLista->marcador = pLista->marcador->proximo;

  }
}

void salvarArquivo(tLista* pLista, tInvestimento invest){
  ofstream arquivo;
  int tamanho;

  cout << "Digite a quantidade de informacoes que ira digitar: " << endl;
  cin >> tamanho;

  for (int i = 0; i < tamanho; i++){
    cout << "Montante Inicial: ";
    cin >> invest.montInicial;
    cout << "Juro ao Ano: ";
    cin >> invest.juroAno;
    cout << "Periodo ao Ano: ";
    cin >> invest.periodoAno;
    incluirNoFim(pLista, invest);
  }

  imprimirLista(pLista);
}



int main() {
  tLista* investimento = new tLista;
  tInvestimento invest;

  while (true){
    char escolha;
    cout << "Digite para escolher uma das opções abaixo: " << endl;
    cout << "(s)Para salvar um arquivo" << endl;
    cout << "(r)Para ler um arquivo" << endl;
    cout << "(e)Para sair do programa" << endl;
    cin >> escolha;

    if (escolha == 's'){
      cout << "\033[2J\033[1;1H";
      salvarArquivo(investimento, invest);
    }else if(escolha == 'r'){
      cout << "\033[2J\033[1;1H";
    }else if(escolha == 'e'){
      break;
    }else{
      cout << "\033[2J\033[1;1H"; 
      cout << "Escolha inválida" << endl;
      continue;
    }
  }
  return 0;
}