#include <iostream>
#include <string>

using namespace std;



class Carro
 { 
    public:
     string marca;
     string modelo;
     int ano;
     string cor;


     void mostrarInformacoes (){
        cout << "Marca: " << marca << endl;
        cout << "Modelo: "<< modelo << endl;
        cout << "Ano: "  << ano << endl;
        cout << "Cor: " << cor << endl;




     }
};

int main ()
{ Carro meuCarro;

    meuCarro.marca = "Chevrolet";
    meuCarro.modelo = "Montana";
    meuCarro.ano = 2022;
    meuCarro.cor= "Prata";

    meuCarro.mostrarInformacoes();
    return 0 ;



}