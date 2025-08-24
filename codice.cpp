#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <limits>
#include <fstream>

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


    //Questa parte di programma non vi serve a voi che state utilizzando il mio codice sorgente.
/*
    fstream key("key.txt", ios::in | ios::out);
    string linea;

    if(!key.is_open()){
        cout<<"Non hai la key per utilizzare il programma!\n";
        return 1;
    }else if(key.is_open()){
        getline(key, linea);
        if(linea != "annabertasi"){
            cout<<"Key non valida!\n";
            return 1;
        }
    }
*/

    welcomeMessage();
    string start;
    cout<<"\nVuoi avviare il programma? Digita \"START\" per avviare il programma: ";
    cin>>start;

    if(start != "START"){
        clearScreen();
        return 1;
    }else{
        clearScreen();
    }

    map<char, char> alfabetoCriptazione;
    alfabetoCriptazione['a'] = 'x';
    alfabetoCriptazione['b'] = 'y';
    alfabetoCriptazione['c'] = 'z';
    alfabetoCriptazione['d'] = 'a';
    alfabetoCriptazione['e'] = 'b';
    alfabetoCriptazione['f'] = 'c';
    alfabetoCriptazione['g'] = 'd';
    alfabetoCriptazione['h'] = 'e';
    alfabetoCriptazione['i'] = 'f';
    alfabetoCriptazione['j'] = 'g';
    alfabetoCriptazione['k'] = 'h';
    alfabetoCriptazione['l'] = 'i';
    alfabetoCriptazione['m'] = 'j';
    alfabetoCriptazione['n'] = 'k';
    alfabetoCriptazione['o'] = 'l';
    alfabetoCriptazione['p'] = 'm';
    alfabetoCriptazione['q'] = 'n';
    alfabetoCriptazione['r'] = 'o';
    alfabetoCriptazione['s'] = 'p';
    alfabetoCriptazione['t'] = 'q';
    alfabetoCriptazione['u'] = 'r';
    alfabetoCriptazione['v'] = 's';
    alfabetoCriptazione['w'] = 't';
    alfabetoCriptazione['x'] = 'u';
    alfabetoCriptazione['y'] = 'v';
    alfabetoCriptazione['z'] = 'w';
    alfabetoCriptazione[' '] = '_';
    alfabetoCriptazione['.'] = ',';
    alfabetoCriptazione[','] = '.';
    alfabetoCriptazione['!'] = '?';
    alfabetoCriptazione['?'] = '!';
    alfabetoCriptazione['0'] = '9';
    alfabetoCriptazione['1'] = '0';
    alfabetoCriptazione['2'] = '1';
    alfabetoCriptazione['3'] = '2';
    alfabetoCriptazione['4'] = '3';
    alfabetoCriptazione['5'] = '4';
    alfabetoCriptazione['6'] = '5';
    alfabetoCriptazione['7'] = '6';
    alfabetoCriptazione['8'] = '7';
    alfabetoCriptazione['9'] = '8';
    alfabetoCriptazione[';'] = '[';
    alfabetoCriptazione['['] = ';';
    alfabetoCriptazione[']'] = ':';
    alfabetoCriptazione[':'] = ']';
    alfabetoCriptazione['\''] = '"';
    alfabetoCriptazione['"'] = '\'';
    alfabetoCriptazione['-'] = '=';
    alfabetoCriptazione['='] = '-';
    alfabetoCriptazione['('] = ')';
    alfabetoCriptazione[')'] = '(';
    alfabetoCriptazione['{'] = '}';
    alfabetoCriptazione['}'] = '{';

    map<char, char> alfabetoDecriptazione;
    alfabetoDecriptazione['x'] = 'a';
    alfabetoDecriptazione['y'] = 'b';
    alfabetoDecriptazione['z'] = 'c';
    alfabetoDecriptazione['a'] = 'd';
    alfabetoDecriptazione['b'] = 'e';
    alfabetoDecriptazione['c'] = 'f';
    alfabetoDecriptazione['d'] = 'g';
    alfabetoDecriptazione['e'] = 'h';
    alfabetoDecriptazione['f'] = 'i';
    alfabetoDecriptazione['g'] = 'j';
    alfabetoDecriptazione['h'] = 'k';
    alfabetoDecriptazione['i'] = 'l';
    alfabetoDecriptazione['j'] = 'm';
    alfabetoDecriptazione['k'] = 'n';
    alfabetoDecriptazione['l'] = 'o';
    alfabetoDecriptazione['m'] = 'p';
    alfabetoDecriptazione['n'] = 'q';
    alfabetoDecriptazione['o'] = 'r';
    alfabetoDecriptazione['p'] = 's';
    alfabetoDecriptazione['q'] = 't';
    alfabetoDecriptazione['r'] = 'u';
    alfabetoDecriptazione['s'] = 'v';
    alfabetoDecriptazione['t'] = 'w';
    alfabetoDecriptazione['u'] = 'x';
    alfabetoDecriptazione['v'] = 'y';
    alfabetoDecriptazione['w'] = 'z';
    alfabetoDecriptazione['_'] = ' ';
    alfabetoDecriptazione[','] = '.';
    alfabetoDecriptazione['.'] = ',';
    alfabetoDecriptazione['?'] = '!';
    alfabetoDecriptazione['!'] = '?';
    alfabetoDecriptazione['9'] = '0';
    alfabetoDecriptazione['0'] = '1';
    alfabetoDecriptazione['1'] = '2';
    alfabetoDecriptazione['2'] = '3';
    alfabetoDecriptazione['3'] = '4';
    alfabetoDecriptazione['4'] = '5';
    alfabetoDecriptazione['5'] = '6';
    alfabetoDecriptazione['6'] = '7';
    alfabetoDecriptazione['7'] = '8';
    alfabetoDecriptazione['8'] = '9';
    alfabetoDecriptazione['['] = ';';
    alfabetoDecriptazione[';'] = '[';
    alfabetoDecriptazione[':'] = ']';
    alfabetoDecriptazione[']'] = ':';
    alfabetoDecriptazione['"'] = '\'';
    alfabetoDecriptazione['\''] = '"';
    alfabetoDecriptazione['='] = '-';
    alfabetoDecriptazione['-'] = '=';
    alfabetoDecriptazione[')'] = '(';
    alfabetoDecriptazione['('] = ')';
    alfabetoDecriptazione['}'] = '{';
    alfabetoDecriptazione['{'] = '}';

    vector<char> parola;
    char letteraParola;
    int scelta;
    cout<<"Digita \"1\" se vuoi criptare un messaggio con il mio alfabeto. Digita \"2\" se vuoi decriptare un messaggio con il mio alfabeto. Digita \"0\" se vuoi chiudere il programma lasciando stampato il logo iniziale:\n\n--- ";
    cin>>scelta;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if(scelta != 1 && scelta != 2 && scelta != 0){
        clearScreen();
        cout<<"Scelta non valida!\n";
        return 1;
    }else if(scelta == 1){
    clearScreen();
    cout << "Inserisci il messaggio da criptare: ";
    while (cin.get(letteraParola) && letteraParola != '\n'){
            parola.push_back(letteraParola);
    }

    for (int i = 0; i < parola.size(); ++i) {
        // Controlla se il carattere attuale è presente nella tua mappa
        if (alfabetoCriptazione.count(parola[i])) {
            // Se sì, sostituiscilo con il suo corrispondente criptato
            parola[i] = alfabetoCriptazione[parola[i]];
        }
    }

    cout << "\nmessaggio criptato: ";
    for(char c : parola){
        cout<<c;
    }

        cout<<"\n\nPremi un qualsiasi carattere e premi invio per uscire:\n\n--- ";
    int uscita;
    cin>>uscita;
    if(uscita == 1){
        return 1;
    }else{
        return 1;
    }

}else if(scelta == 2){
    clearScreen();
        cout << "Inserisci il messaggio da decriptare: ";
    while (cin.get(letteraParola) && letteraParola != '\n'){
            parola.push_back(letteraParola);
    }

    for (int i = 0; i < parola.size(); ++i) {
        // Controlla se il carattere attuale è presente nella tua mappa
        if (alfabetoDecriptazione.count(parola[i])) {
            // Se sì, sostituiscilo con il suo corrispondente criptato
            parola[i] = alfabetoDecriptazione[parola[i]];
        }
    }

    cout << "\nmessaggio decriptato: ";
    for(char c : parola){
        cout<<c;
    }

        cout<<"\n\nPremi un qualsiasi carattere e premi invio per uscire:\n\n--- ";
    int uscita2;
    cin>>uscita2;
    if(uscita2 == 1){
        return 1;
    }else{
        return 1;
    }
}else{
    welcomeMessage();
}
return 0;
}