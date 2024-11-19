/*
Prática 5: 
Idade para votar: entre 18 e 90 anos. 
No Paraíso Feliz moram apenas 100 pessoas. 
Implemente um programa para 
Solicitar ao usuário a idade de cada pessoa que mora no Paraíso Feliz 
Determinar se esta pessoa pode ou não votar. 
Para cada pessoa, o programa deve exibir a seguinte frase: 
"Esta pessoa tem <idade> anos e [pode / não pode] votar." 
Ao final, o programa deve exibir o total e o percentual de votantes e não votantes. 
OBS: O programa deve forçar a digitação de idades válidas. 
Uma idade válida é uma idade no intervalo de 0 a 120.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int num_votantes, num_nao_votantes, idade, num_votos;

    num_votos = 0;
    num_votantes = 0;
    num_nao_votantes = 0;

    while (num_votos < 10) {
        cout << "Informe a sua idade: ";
        cin >> idade;
        num_votos = num_votos + 1;

        if (idade >= 0 && idade <= 120){
           if(idade < 18 || idade > 90) {
                cout << "Você tem " << idade << " anos, por isso não pode votar." << endl;
                num_nao_votantes = num_nao_votantes + 1;
            } 

            else if (idade >= 18 && idade <= 90){
                cout << "Você tem " << idade << " anos, por isso pode votar." << endl;
                num_votantes = num_votantes + 1;
            }
        }

        else{
            cout << "A idade informada não é válida ";
            num_votos = num_votos - 1;
        }      
    }
    
    cout << "O número de votantes foi de: " << num_votantes << endl;
    cout << "O número de não votantes foi de: " << num_nao_votantes << endl;

    return 0;
}
