/*
Prática 8:
solicitar ao usuário que informe o tamanho de três segmentos de reta. 
O programa deverá emitir uma mensagem informando se os segmentos informados pelo usuário formam ou não um triângulo e, 
caso formem, qual o tipo do triângulo formado. Para tal, o programa deverá fazer uso, obrigatoriamente, 
dos subprogramas abaixo relacionados:
(a) Uma função que recebe como parâmetros de entrada três segmentos de reta e, como saída, 
retorna 0 (se não formarem um triângulo) ou 1 (se formarem um triângulo). Para que os segmentos de reta formem um tijângulo, 
é necessário que cada segmento seja menor que a soma dos dois outros segmentos.
Uma função que recebe como parâmetros de entrada três segmentos de reta e,
 como retorna 1 (se o triângulo for escaleno), 2 (se o triângulo for isóscele) ou 3 (se o triângulo for equilátero).
  Lembre-se que: um triângulo escaleno tem os três lados diferentes, um triângulo equilátero tem os três lados iguais e um triângulo 
  isóscele tem apenas dois lados iguais.
O método main irá solicitar ao usuário os valores dos três segmentos de reta e, utilizando a função do item (a), 
decidir se formam ou não um triângulo. Caso formem um triângulo, o main deverá exibir uma mensagem informando que 
tipo de triângulo formam. Para descobrir que tipo de triângulo os segmentos formam, o main deverá utilizar a função
 definida no item (b).
OBS: O método main deve FORÇAR que os valores dos segmentos de reta fornecidos pelo usuário sejam maiores que zero.
*/

#include <iostream>
#include <iomanip>
using namespace std;

bool isTryangle(float a, float b, float c){
  return (a + b > c) && (c + b > a) && (a + c > b);
}

int triangleType(float a, float b, float c){
  if (a == b && b == c){
    return 1;
  }

  else if (a != b && b != c){
    return 2;
  }

  else{
    return 3;
  }
  return 0;
}

int main(){
  float reta_1, reta_2, reta_3;

  do{
    cout << "Informe o tamanho do primeiro segmento de reta em m: \n";
    cin >> reta_1;
  } while (reta_1 <= 0);

  do{
    cout << "Informe o tamanho do segundo segmento de reta em m: \n";
    cin >> reta_2;
  } while (reta_2 <= 0);

  do{
    cout << "Informe o tamanho do terceiro segmento de reta em m: \n";
    cin >> reta_3;
  } while (reta_3 <= 0);


  if (isTryangle(reta_1, reta_2, reta_3)){
    cout << "As três retas formam um triângulo" << endl;

    int type = triangleType(reta_1, reta_2, reta_3);
    if (type == 1) {
      cout << "O triângulo formado é um triângulo equilátero." << endl;
    }
    else if (type == 2)
    {
      cout << "O triângulo formado é um triângulo escaleno." << endl;
    }
    else {
      cout << "O triângulo formado é um triângulo isóceles" << endl;
    }
  }
  
  else {
    cout << "As três retas não formam um triângulo" << endl;
  }
  
  return 0;
}

