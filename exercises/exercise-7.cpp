/*
Prática 7: Implemente um programa para fazer conversão de temperaturas em graus Fahrenheit par. graus Celsius e vice-versa.
O programa deverá apresentar os seguintes subprogramas:
(a) Função para converter temperaturas em graus Fahrenheit para graus Celsius.
  Esta função receberá como parâmetro de entrada o valor da temperatura em graus Fahrenheit a ser convertido e 
  deverá calcular e retornar para o programa o valor correspondente em graus Celsius.
  O main se encarregará de exibir o resultado ao usuário.
(b) Função para converter temperaturas em graus Celsius para graus Fahrenheit. 
Esta função receberá como parâmetro de entrada o valor da temperatura em graus Celsius a ser convertido e 
deverá calcular e retornar para o programa o valor correspondente em graus Fahrenheit. O main se
encarregará de exibir o resultado ao usuário.
OBSI: O programa deverá permitir que o usuário faça quantas conversões desejar e só deverá terminar sua execução se o usuário solicitar.
Para isso, o método main deverá ter um loop dentro do qual o usuário fará a escolha de que ação deseja executar.
OBS2: Toda entrada e saída de dados deve ser feita pelo programa principal (método main).
OBS3: Para as conversões, utilize i fórmulas abaixo:
(F - 32)
F = C*1.8 + 32
C = 1.8
Exemplo de tela:
Opções:
1 - Converter temperatura em graus Fahrenheit para graus Celsius
2 - Converter temperatura em graus Celsius para graus Fahrenheit
0 - Encerrar o programa
Digite a opção desejada:
*/

#include <iostream>
#include <iomanip>
using namespace std;

float celsiusParaFahrenhit(float temp_celsius){
  int i;
  i = (temp_celsius * 1.8) + 32;
  return (i);
}


float fahrenheitParaCelcius(float temp_fahrenheit){
  int j;
  j = (temp_fahrenheit - 32) / 1.8;
  return (j);
}


int main(){
  int escolha;
  float temperatura, resultado;

  do{
    cout << "Escolha uma das opções abaixo: \n";
    cout << "1 - Converter temperatura em graus Fahrenheit para graus Celsius\n";
    cout << "2 - Converter temperatura em graus Celsius para graus Fahrenheit\n";
    cout << "0 - Encerrar o programa\n";
    cin >> escolha;

    switch (escolha)
    {
    case 1:
      cout << "Informe a temperatura em graus Fahrenheit: ";
      cin >> temperatura;
      resultado = fahrenheitParaCelcius(temperatura);
      cout << "A temperatura é de " << resultado << "Cº\n";
      cout << endl;
      break;

    case 2:
      cout << "Informe a temperatura em graus Celsius: ";
      cin >> temperatura;
      resultado = celsiusParaFahrenhit(temperatura);
      cout << "A temperatura é de " << resultado << "Fº\n";
      cout << endl;
      break;

    case 0:
      cout << "Programa encerrado." << endl;
      cout << endl;
      break;

    default:
      cout << "Opção inválida, tente novamente.\n";
    }

  } while (escolha != 0);

  return 0;
}

