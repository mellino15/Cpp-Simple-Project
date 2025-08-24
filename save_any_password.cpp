/*
Questo programma permette di salvare e recuperare password da file di testo.
L'utente può scegliere di salvare una password con un ID specifico che diventerà
il nome del file di testo in cui la password sarà memorizzata. In alternativa,
l'utente può recuperare una password fornendo l'ID corrispondente.
Loso che non è molto utile perchè se non si ricorda il nome del file non si può recuperare la password.
ma è un esercizio di programmazione in C++.
*/


#include <iostream>
#include <fstream>
#include <vector>
#include <random>

using namespace std;

void stampaRicordami() {
    cout << R"(
 ____     ___  ___ ___    ___  ___ ___  ____     ___  ____       ___ ___    ___ 
|    \   /  _]|   |   |  /  _]|   |   ||    \   /  _]|    \     |   |   |  /  _]
|  D  ) /  [_ | _   _ | /  [_ | _   _ ||  o  ) /  [_ |  D  )    | _   _ | /  [_ 
|    / |    _]|  \_/  ||    _]|  \_/  ||     ||    _]|    /     |  \_/  ||    _]
|    \ |   [_ |   |   ||   [_ |   |   ||  O  ||   [_ |    \     |   |   ||   [_ 
|  .  \|     ||   |   ||     ||   |   ||     ||     ||  .  \    |   |   ||     |
|__|\_||_____||___|___||_____||___|___||_____||_____||__|\_|    |___|___||_____| Welcome to the BETA!
                                                                                

)" << endl;
}

int main(){
    stampaRicordami();
    int scelta;
    cout<<"Digita \"1\" se vuoi salvare una tua password con un id per poterla trovare facilmente. Digita \"2\" se vuoi cercare una password salvata con questo programma (bada bene: il file contenente la password deve essere nella stessa directory dell'eseguibile)\n\n--- ";
    cin>>scelta;
    if(scelta == 1){
        string id, password;
        cout<<"\n\nInserisci l'ID della password per ricordartela (si raccomanda di includere anche l'estensione del file. ES: \".txt\"): ";
        cin.ignore();
        getline(cin, id);
        ifstream file(id);
        while(file.is_open()){
            file.close();
            cout<<"Il file con l'ID "<<id<<" esiste già. Scegline un altro: ";
            cin>>id;
            file.open(id);
        }
        ofstream filePassword(id);
        cout<<"Inserisci la password da salvare: ";
        getline(cin, password);
        filePassword << password;
        filePassword.close();
        cout<<"\nLa password è stata salvata con successo in un file con l'ID: "<<id<<endl;
    }else if(scelta == 2){
        string id;
        cout<<"\n\nInserisci l'ID assegnato in precedenza alla password: ";
        cin.ignore();
        getline(cin, id);
        ifstream file(id);
        if(!file.is_open()){
            cout<<"\nFile non esistente.";
        }else{
            string linea;
            getline(file, linea);
            cout<<"\nLa password è: "<<linea<<endl;
            file.close();
        }
    }else{
        while(scelta != 1 && scelta != 2){
            cout<<"\n\nScelta non valida. Digita \"1\" per creare una password forte o \"2\" per salvare una tua password con un ID.\n\n--- ";
            cin>>scelta;
        }
    }
    return 0;
}