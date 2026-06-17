#include <iostream>
using namespace std;

class Restaurante {
private:
    string nome;
    string cardapio;
    
public:
    // Método para definir o modelo
    void setModelo(string m) {
        modelo = m;
    }

    // Método para obter o modelo
    string getModelo() {
        return modelo;
    }

    // Método para definir a velocidade
    void setVelocidade(int v) {
        if (v >= 0 && v <= 300) {
            velocidade = v;
        }
    }

    // Método para obter a velocidade
    int getVelocidade() {
        return velocidade;
    }
};

int main() {
    Carro meuCarro;

    meuCarro.setModelo("Ferrari");
    meuCarro.setVelocidade(200);

    cout << "Modelo: " << meuCarro.getModelo() << endl;
    cout << "Velocidade: " << meuCarro.getVelocidade() << " km/h" << endl;

    return 0;
   

    
    


}