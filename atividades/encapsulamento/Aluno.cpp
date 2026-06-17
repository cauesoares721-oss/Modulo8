#include <iostream>
#include <string>

using namespace std;

class Aluno{
private:
    string nome;
    float nota; 

public:

    Aluno (string n,float nt){
        nome = n;

        if (nt >= 0 && nt <=10){
            nota = n; 
        }
        else {
            nota = 0;
            cout << "Erro: Nota invalida" << endl;
        }
    }
        void set_notas (float nt) {
            if (nt >= 0 && nt <=10){
                nota= nt;
            }
            else {
                nota=0;
                cout << "Erro: nota invalida!"<< endl;

            }   
        }

        float get_nota(){
            returb nota;
        }
        string get_nome (){
            return nome;
        }

};
int main(){
    Aluno a ("Carlos", 8.5);
    
    cout << "Nome: " << a.get_nome()<< endl;
    cout << "Nota: " << a.get_nota ()<< endl;

    a.set_notas(12);
    a.set_notas(9,2);

    cout <<"Nova nota: " << a.get_nota() << endl;
     return 0;
}