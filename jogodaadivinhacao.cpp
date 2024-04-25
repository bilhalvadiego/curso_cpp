#include<iostream>
#include<random>
#include<string>

using namespace std;

int main(){
    cout << "*************************************" << endl;
    cout << "* Bem vindos ao jogo da Adivinhação *" << endl;
    cout << "*************************************" << endl;

    random_device rd;

    mt19937 gen(rd());

    uniform_int_distribution<int> dis(1,100);

    int numero_secreto = dis(gen);

    string nro_tentativas;
    int nro_tentativa;

    while(true){
        cout << "Quantas tentativas você deseja?" << endl;
        cin >> nro_tentativas;

        if (nro_tentativas == "chega") {
            cout << "Tudo bem. Tchau e até logo!" << endl;
            return 0;
        }

        try{
            nro_tentativa = stoi(nro_tentativas);
            break;
        } catch (...){
            cout << endl << "Entrada inválida. Por favor, insira um número ou 'chega': " << endl << endl;
            continue;
        }
    }
    
    cout << "Ótimo. Você possui " << nro_tentativa << " tentativas. Vamos começar!" << endl;
    cout << "Tente adivinhar o número secreto entre 1 e 100. " << endl;
    
    int tentativas = 0;

    string entrada;
    bool bWarning = false;
    string sWarning = "Tente novamente!";

    while(true){
        
        if (tentativas >= nro_tentativa){
            cout << "Você excedeu o limite de tentativas. O numero era " << numero_secreto << "." << endl;
            break;
        } else if (tentativas == (nro_tentativa-1)) {
            cout << "CUIDADO, ESTA É SUA ÚLTIMA TENTATIVA!" << endl;
            bWarning = true;
            sWarning = " ";
        }

        cout << "Vamos para a tentativa #" << (tentativas + 1) << " de " << nro_tentativa << " tentativas." << endl << "Qual o seu palpite? Ou digite 'chega' para sair: " << endl;
        cin >> entrada;

        if (entrada == "chega") {
            cout << "Tudo bem. O nro era " << numero_secreto << endl;
            return 0;
        }

        int tentativa;
        
        try {
            tentativa = stoi(entrada);
        } catch (...){
            cout << endl << "Entrada inválida. Por favor, insira um número ou 'chega': " << endl << endl;
            continue;
        }

        tentativas++;


        if (tentativa > numero_secreto){
            cout << "O numero secreto é MENOR do que o número que você informou. " << sWarning << endl << endl;
            continue;
        }
        if (tentativa < numero_secreto){
            cout << "O numero secreto é MAIOR do que o número que você informou. " << sWarning << endl << endl;
            continue;
        }
        if (tentativa == numero_secreto){
            cout << "Parabéns! Você acertou o número secreto." << endl << endl;
            break;
        }
    }

}