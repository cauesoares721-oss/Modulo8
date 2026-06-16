#include <iostream>
#include <string>

using namespace std;


const int NUM_JOGOS =4 ;
//funcção para calcular a pontuação
int calcularPontuação(int bolao1,int bolao2,int real1,int real2)
  if (bolao1== real  && bolao2 == real2)
     return 10;

//vencedor do bolão,inicialmente considerando como empate
int vencedorBolao = 0 ;

//verificação 
if (bolao1 > bolao2 )
 vencedorBolao = 1 
else if (bolao2 > bolao1)
    vencendorBolao=2

int vencedorReal = 0;
if (real1 > real2)
   vencedorReal = 1;
else if (real2 > real1)
  vencedorReal=2;


if (vencedorBolao == vencedorReal)

else

   return 0;

int main ()
string time1[NUM_JOGOS]= {"BRA", "RSA", "FRA", "GER"}
string time2[NUM_JOGOS]= {"EGT","MAR","ARG","COS"}

int placarBolao1[NUM_JOGOS],placarBolao2[NUM_JOGOS];

int resultadoReal1[NUM_JOGOS],resultadoReal2[NUM_JOGOS];

cout<<<"---------------------------------"
cout<<<"     BOLÃO DA COPA 2026           "
cout<<<"---------------------------------"

for (int i =0; i <NUM_JOGOS;i++)
cout <<"Jogo" << (i+1)
cin >> placarBolao01[i];
cin >> placarBolao02[i];

cin>> resultadoReal1[i];
cin>> resultadoReal2[i];

int totalPontos = 0;

for (int i = 0; i < NUM_JOGOS;i++)

int pontos = 
calcularPontuação(...)
totalPontos += pontos;

cout << "Palpite: "

cout << "Real: "

if (pontos ==10 )
 cout << "Placar exato +10 pts "
else if (pontos ==5)
 cout<<"Acertou o vencedor +5 pts"
else 
 cout<<"Errou +0 pts"



cout<< "TOTAL DE PONTOS: "
<< totalPontos
<<"pontos";


