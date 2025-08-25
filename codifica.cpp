/*
Con questo programma hai la possibilità di criptare e decriptare frasi intere secondo un tuo alfabeto personale
scelto all'avvio del programma. il programma ha sostanzialmente 2 punti di riferimento: una variebile stringa 
con l'alfabeto che tutti conosciamo e una stringa con quello personale dell'utente. Successivamente il programma 
si baserà su ciò che c'è dentro il file chiamato "scelta.txt" per decidere se andare a criptare o decriptare
8in caso non abbiate creato il file il programma è impostato su "criptare" di default).
*/

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <limits>

using namespace std;

void clearScreen() {
    // Funzione per pulire lo schermo
    cout << "\033[2J\033[1;1H"; // ANSI escape code per pulire lo schermo
}

void welcomeMessage(){
    clearScreen();
    cout<< R"(
 ______    ________  ______   ______    ______   _________        __       ______   __   __   ______      
/_____/\  /_______/\/_____/\ /_____/\  /_____/\ /________/\      /_/\     /_____/\ /_/\ /_/\ /_____/\     
\::::_\/_ \__.::._\/\:::__\/ \:::_ \ \ \::::_\/_\__.::.__\/      \:\ \    \:::_ \ \\:\ \\ \ \\::::_\/_    
 \:\/___/\   \::\ \  \:\ \  __\:(_) ) )_\:\/___/\  \::\ \         \:\ \    \:\ \ \ \\:\ \\ \ \\:\/___/\   
  \_::._\:\  _\::\ \__\:\ \/_/\\: __ `\ \\::___\/_  \::\ \         \:\ \____\:\ \ \ \\:\_/.:\ \\::___\/_  
    /____\:\/__\::\__/\\:\_\ \ \\ \ `\ \ \\:\____/\  \::\ \         \:\/___/\\:\_\ \ \\ ..::/ / \:\____/\ 
    \_____\/\________\/ \_____\/ \_\/ \_\/ \_____\/   \__\/          \_____\/ \_____\/ \___/_/   \_____\/ 
                                                                                                          
    )"<<endl;
}

int main(){
    string alfabeto = "abcdefghijklmnopqrstuvwxyz";
    string alfabetoCriptato;
    vector<char> frase;
    char letteraFrase;
    map<char, char> cr;
    cout<<"inserisci il tuo alfabeto personale di 26 caratteri (esempio: qwertyuiopasdfghjklzxcvbnm): ";
    getline(cin, alfabetoCriptato);
    welcomeMessage();
    cout<<"Per decidere se criptare o decriptare un messaggio secondo il mio alfabeto, crea un file di testo chiamato \"scelta.txt\" nel cuale scriverai \"cript\" per criptare o \"decript\" per decriptare (il programma di defaiult sarà impostato su criptaggio).\n\n";
    ifstream sceltafile("scelta.txt");
    string scelta;
    sceltafile>>scelta;
    if(sceltafile.is_open() && scelta == "decript"){
        for(int i = 0; i <alfabetoCriptato.size(); i++){
        cr[alfabetoCriptato[i]] = alfabeto[i];
    }
    cout << "\n\nInserisci il messaggio da decriptare: ";
    while(cin.get(letteraFrase) && letteraFrase != '\n'){
            frase.push_back(letteraFrase);
    }
    for(int i = 0; i < frase.size(); i++){
        if(cr.count(frase[i])){
            frase[i] = cr[frase[i]];
        }
    }
    cout<<"\n\nMessaggio decriptato: ";
    for(char c : frase){
        cout<<c;
    }

    }else{
        for(int i = 0; i <alfabeto.size(); i++){
        cr[alfabeto[i]] = alfabetoCriptato[i];
    }
    cout << "Inserisci il messaggio da criptare: ";
    while(cin.get(letteraFrase) && letteraFrase != '\n'){
            frase.push_back(letteraFrase);
    }
    for(int i = 0; i < frase.size(); i++){
        if(cr.count(frase[i])){
            frase[i] = cr[frase[i]];
        }
    }
    cout<<"\n\nMessaggio criptato: ";
    for(char c : frase){
        cout<<c;
    }
    }

}
