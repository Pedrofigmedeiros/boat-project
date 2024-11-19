/*
Prática 6: Impiemente um programa para calcular e exibir a soma dos N números inteiros maiores que zero, 
onde N (quantidade de números a serem somados) é um valor informado pelo usuário.
OBS: Para ser válido, N deve ser maior que zero. O programa deve forçar que o usuário informe um valor de N válido.
Exemplo: Se N = 10, então:
1+2+3+4+5+6+7+8+9+10
Soma = 55
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int numero, soma = 0;
    cout << "Informe um numero inteiro maior que zero: ";
    cin >> numero;
    
    if(numero > 0){
        for (int i = 0; i <= numero; i++){
            soma += i;
        }
        cout << "A soma dos números de 0 até " << numero << " é: " << soma << endl;
    } 
    
    else{
        cout << "Valor inválido, informe um valor maior que zero";
    }

    return 0;
}
