/*
Questo programma ti consente di generare password casuali utilizzando lafunzione "rand()".
Ho creato un solo array contenente tutti i caratteri e poi ho sfruttato la capacità di agire sui
"limiti" all'interno i quali la funzione "rand()" può agire per dirgli, in questo caso, di andare a generare numeri casuali 
tra "52 + 10" (rand()% 52 + 10) per prendere solo le lettere, saltando i primi 10 caratteri che sono numeri.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int main(){
    int lunghezzaPassword;
    char caratteri[67] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                            'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
                            'i', 'j', 'k', 'l', 'm', 'n', 'o',
                            'p', 'q', 'r', 's', 't', 'u', 'v',
                            'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                            'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 
                            'U', 'V', 'W', 'X', 'Y', 'Z', '?', '!', '@', '#', '$'};
    vector<char> password;
    int scelta;
    srand(time(NULL));
    cout<<"Scegli se generare la tua password casuale con:\n1) Numeri\n2) Lettere\n3) Simboli\n4) Tutto insieme\n";
    cin>>scelta;
    
    switch (scelta)
    {
        case 1:
            cout << "Inserisci la lunghezza della password: ";
            cin >> lunghezzaPassword;
            for(int i = 0; i < lunghezzaPassword; i++){
            int numero = rand()% 10;
            password.push_back(caratteri[numero]);
            }
            cout << "La password generata e': ";
            for(int i = 0; i < password.size(); i++){
                cout<<password[i];
            }
            break;
        case 2:
            cout << "Inserisci la lunghezza della password: ";
            cin >> lunghezzaPassword;
            for(int i = 0; i < lunghezzaPassword; i++){
            int numero = rand()% 52 + 10;
            password.push_back(caratteri[numero]);
            }
            cout << "La password generata e': ";
            for(int i = 0; i < password.size(); i++){
                cout<<password[i];
            } 
            break;
        case 3:
            cout << "Inserisci la lunghezza della password: ";
            cin >> lunghezzaPassword;
            for(int i = 0; i < lunghezzaPassword; i++){
            int numero = rand()% 5 + 62;
            password.push_back(caratteri[numero]);
            }
            cout << "La password generata e': ";
            for(int i = 0; i < password.size(); i++){
                cout<<password[i];
            }
            break;
        case 4:
            cout << "Inserisci la lunghezza della password: ";
            cin >> lunghezzaPassword;
            for(int i = 0; i < lunghezzaPassword; i++){
            int numero = rand()% 67;
            password.push_back(caratteri[numero]);
            }
            cout << "La password generata e': ";
            for(int i = 0; i < password.size(); i++){
                cout<<password[i];
            }
            break;
        default:
            cout<<"Scelta non valida";
            break;     
    }
    return 0;
}
