/*  URI Online Judge | 1069  */
#include <iostream>
using namespace std;
template <class T> class Fila {
  protected:  
    template <class TT> class Celula {
      public:
        Celula<TT> *prox;
        TT valor;
        Celula(TT v) {
          this->valor = v;
          prox = nullptr;
        }
    };
    int tamanho;
    Celula<T> *primeiro;
    Celula<T> *ultimo;
  public:
    Fila() {
      ultimo = primeiro = nullptr;
      tamanho = 0;
    }
    ~Fila() {
      Celula<T> *aux;
      while(primeiro!=nullptr) {
        aux=primeiro;
        primeiro = primeiro->prox;
        delete aux;
      }
    }
    int getTamanho() {
    return tamanho;
    }
    bool inserir(const T &valor) {
      if(this->primeiro == nullptr) {
        this->ultimo = this->primeiro = new Celula<T>(valor);
      } else {
        this->ultimo->prox = new Celula<T>(valor);
        this->ultimo = this->ultimo->prox;
      }
      ++tamanho;
      return true;
    }
    bool excluir(void) {
      if(this->primeiro==nullptr) {
        return false;
      } else {
        Celula<T> *aux;
        aux = primeiro;
        this->primeiro = this->primeiro->prox;
        delete aux;
        --tamanho;
      }
      return true;
    }
    void mostrar() {
      if(this->primeiro== nullptr) {
        cout << "<<nada>>";
      } else {
        cout << this->primeiro->valor;
      }
        cout << endl;
    }
    char RetornaPrimeiro(){
      if(this->primeiro== nullptr) {
        return '0';
      } else {
        return this->primeiro->valor;
      }     
    }
};

int main() {
  Fila<char> Musica;
  Fila<char> Compasso;
  char aux[10000];
  int CompassoCerto = 0;
  cin.getline(aux, 10000);
  for(int i = 0; aux[i]; i++){
    Musica.inserir(aux[i]);
  }
  for(int j = Musica.getTamanho(); j > 0; j--){
    if(Musica.RetornaPrimeiro() != '/'){
      Compasso.inserir(Musica.RetornaPrimeiro());
      Musica.excluir();
    }
    if(Musica.RetornaPrimeiro() == '/' && Compasso.getTamanho() != 0){
        Musica.excluir();
        float Tempo = 0.0;
        for(int k = Compasso.getTamanho(); k > 0; k--){
          if(Compasso.RetornaPrimeiro() == 'W'){
            Tempo += 1;
          }else if(Compasso.RetornaPrimeiro() == 'H'){
            Tempo += 0.5;
          }else if(Compasso.RetornaPrimeiro() == 'Q'){
            Tempo += 0.25;
          }else if(Compasso.RetornaPrimeiro() == 'E'){
            Tempo += 0.125;
          }else if(Compasso.RetornaPrimeiro() == 'S'){
            Tempo += 0.0625;
          }else if(Compasso.RetornaPrimeiro() == 'T'){
            Tempo +=0.03125;
          }else if(Compasso.RetornaPrimeiro() == 'X'){
            Tempo+=0.015625;
          }

          Compasso.excluir();
        }
        if(Tempo == 1){
          CompassoCerto++;
        }
    }
    if(Musica.RetornaPrimeiro() == '/' && Compasso.getTamanho() == 0){
      Musica.excluir();
    }
  }
  cout<<CompassoCerto<<endl;
  return 0;
}