#include <iostream>
#include <string>

using namespace std;



class ContaBancaria
 { 
    public : 
     string titular;
     int saldo;  
       

  void depositar(int valor)
  {    
    saldo += valor;

  }

  void sacar(int valor)
{
    if (saldo >= valor)
    {
        saldo = saldo - valor;
    }
    else
    {
        cout << "Saldo insuficiente!" << endl;
    }
}
    


  };

 int main (){
    ContaBancaria conta;

    conta.titular = "Cauê";
    conta.saldo = 1000 ;

    conta.depositar(0);
    conta.sacar(1200);


    cout << "Titular da conta: " << conta.titular << endl;
    cout << "Saldo da conta : " << conta.saldo << endl;



 }