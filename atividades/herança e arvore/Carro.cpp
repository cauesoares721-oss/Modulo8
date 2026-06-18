#include <iostream>
#include <string > 
using namespace std;

class Veiculo {

protected:
    string marca;
   
};

class Carro : public Veiculo {
    private:
      string modelo;
};