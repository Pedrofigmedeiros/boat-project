/*
Prática 9: Implemente um programa que solicite ao usuário que informe 3 números inteiros, 
chame um procedimento que receba como parâmetro esses 3 valores e ache e exiba o maior e o menor valor dentre os valores informados.

*/

#include <iostream>
using namespace std;

void findTheNumbers(float a, float b, float c) {
    float maior_num, menor_num;
    maior_num = a;
    menor_num = a;

    if (b > maior_num) {
        maior_num = b;
    }
    if (c > maior_num) {
        maior_num = c;
    }

    if (b < menor_num) {
        menor_num = b;
    }
    if (c < menor_num) {
        menor_num = c;
    }

    cout << "O maior número é " << maior_num << endl;
    cout << "O menor número é " << menor_num << endl;
}

int main() {
    float num_1, num_2, num_3;

    cout << "Informe o primeiro número real: ";
    cin >> num_1;
    cout << "Informe o segundo número real: ";
    cin >> num_2;
    cout << "Informe o terceiro número real: ";
    cin >> num_3;

    findTheNumbers(num_1, num_2, num_3);

    return 0;
}
