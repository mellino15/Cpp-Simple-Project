#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    cout<<"Welcome to \"sasso, carta, forbice\" game!\n\n";
    string segno;
    int segnoComputer;
    srand(time(NULL));
    cout<<"inserisci un segno tra sasso, carta e forbice (scrivili cosi come li ho scritti io!): ";
    cin>>segno;
    segnoComputer = rand()%3 + 1;
    switch(segnoComputer){
        case 1:
            cout<<"il computer ha scelto sasso\n";
            if(segno == "sasso"){
                cout<<"pareggio!\n";
            } else if(segno == "carta"){
                cout<<"hai vinto!\n";
            } else if(segno == "forbice"){
                cout<<"hai perso!\n";
            } else {
                cout<<"segno non valido\n";
            }
            break;
        case 2:
            cout<<"il computer ha scelto carta\n";
            if(segno == "carta"){
                cout<<"pareggio!\n";
            } else if(segno == "forbice"){
                cout<<"hai vinto!\n";
            } else if(segno == "sasso"){
                cout<<"hai perso!\n";
            } else {
                cout<<"segno non valido\n";
            }
            break;
        case 3:
            cout<<"il computer ha scelto forbice\n";
            if(segno == "forbice"){
                cout<<"pareggio!\n";
            } else if(segno == "sasso"){
                cout<<"hai vinto!\n";
            } else if(segno == "carta"){
                cout<<"hai perso!\n";
            } else {
                cout<<"segno non valido\n";
            }
            break;
    }
    return 0;
}