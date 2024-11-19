/*
Prática 4: Implemente um programa que solicite ao usuário três números reais e
determine qual o menor e qual o maior dos números digitados. 
Considere que os três números podem ou não ser diferentes entre si.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    float num_1, num_2, num_3, maior_num, menor_num;

    cout << "Informe o primeiro número real: ";
    cin >> num_1;
    cout << "Informe o segundo número real: ";
    cin >> num_2;
    cout << "Informe o terceiro número real: ";
    cin >> num_3;

    maior_num = num_1;
    menor_num = num_1;

    if (num_2 > maior_num){
        maior_num = num_2;
    }

    if(num_3 > maior_num) {
        maior_num = num_3;
    }

    if (num_2 < menor_num){
        menor_num = num_2;
    }

    if(num_3 < menor_num) {
        menor_num = num_3;
    }

    cout << "O maior número é " << maior_num << endl;
    cout << "O menor número é " << menor_num << endl;

    return 0;
}
