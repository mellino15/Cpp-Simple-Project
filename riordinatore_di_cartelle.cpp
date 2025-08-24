#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>

using namespace std;

namespace fs = std::filesystem;

ifstream file_debug("parangelia.txt");

string logo(){
    return R"(
 _______  _______  ______    _______  __    _  _______  _______  ___      ___   _______ 
|       ||   _   ||    _ |  |   _   ||  |  | ||       ||       ||   |    |   | |   _   |
|    _  ||  |_|  ||   | ||  |  |_|  ||   |_| ||    ___||    ___||   |    |   | |  |_|  |
|   |_| ||       ||   |_||_ |       ||       ||   | __ |   |___ |   |    |   | |       |
|    ___||       ||    __  ||       ||  _    ||   ||  ||    ___||   |___ |   | |       |
|   |    |   _   ||   |  | ||   _   || | |   ||   |_| ||   |___ |       ||   | |   _   |
|___|    |__| |__||___|  |_||__| |__||_|  |__||_______||_______||_______||___| |__| |__|
)";
}

int main() {

    string linea;

if(file_debug.is_open()){
        cout<<logo()<<endl;
        cout<<"Info relative al software:\n-----\nNome: Parangelia\nVersione: 1.0.0\nAutore: Elia Ghelli\nData di rilscio: 06/08/2025\n-----\n";
        ofstream file_debug("parangelia.txt");
        file_debug<<"Info relative al software:\n-----\nNome: Parangelia\nVersione: 1.0.0\nAutore: Elia Ghelli\nData di rilscio: 06/08/2025\n-----\n";
        return 1;
    }

    fs::path current_path = fs::current_path();

    vector<string> nomi_cartelle = {
        "Altro",
        "Musica",
        "Documenti",
        "Immagini",
        "Video"
    };

    // FASE 1: Creazione delle cartelle
    for (const auto& nome : nomi_cartelle) {
        fs::path nuova_cartella_path = current_path / nome;
            if (fs::create_directory(nuova_cartella_path)) {
                cout << "Cartella '" << nuova_cartella_path.string() << "' creata." << std::endl;
            } else {
                cout << "La cartella '" << nuova_cartella_path.string() << "' esiste già." << std::endl;
            }
    }

    // FASE 2: Spostamento dei file
    for (const auto& entry : fs::directory_iterator(current_path)) {
        if (entry.is_regular_file()) {
            fs::path percorso_origine = entry.path();
            fs::path estensione = percorso_origine.extension();
            fs::path percorso_destinazione;

            if (estensione == ".mp3" || estensione == ".wav" || estensione == ".aac" || estensione == ".flac" || estensione == ".ogg" || estensione == ".wma" || estensione == ".m4a") {
                percorso_destinazione = current_path / "Musica" / percorso_origine.filename();
            } else if (estensione == ".txt" || estensione == ".doc" || estensione == ".docx" || estensione == ".pdf" || estensione == ".html" || estensione == ".htm" || estensione == ".rtf" || estensione == ".odt" || estensione == ".xls" || estensione == ".xlsx" || estensione == ".ppt" || estensione == ".pptx" || estensione == ".csv" || estensione == ".md" || estensione == ".json" || estensione == ".xml" || estensione == ".log" || estensione == ".sql" || estensione == ".epub" || estensione == ".cpp" || estensione == ".c" || estensione == ".h" || estensione == ".hpp" || estensione == ".py" || estensione == ".js" || estensione == ".jsx" || estensione == ".ts" || estensione == ".tsx" || estensione == ".java" || estensione == ".cs" || estensione == ".php" || estensione == ".rb" || estensione == ".go" || estensione == ".swift" || estensione == ".kt" || estensione == ".rs" || estensione == ".sh" || estensione == ".bat" || estensione == ".ps1" || estensione == ".css" || estensione == ".scss" || estensione == ".sass" || estensione == ".less" || estensione == ".yml" || estensione == ".yaml" || estensione == ".toml" || estensione == ".ini" || estensione == ".cfg" || estensione == ".conf" ) {
                percorso_destinazione = current_path / "Documenti" / percorso_origine.filename();
            } else if (estensione == ".jpg" || estensione == ".jpeg" || estensione == ".png" || estensione == ".gif" || estensione == ".bmp" || estensione == ".tiff" || estensione == ".tif" || estensione == ".svg" || estensione == ".ico" || estensione == ".webp" || estensione == ".psd" || estensione == ".ai" || estensione == ".eps" || estensione == ".heic" || estensione == ".heif" || estensione == ".raw" || estensione == ".cr2" || estensione == ".nef" || estensione == ".orf" || estensione == ".dng") {
                percorso_destinazione = current_path / "Immagini" / percorso_origine.filename();
            } else if (estensione == ".mp4" || estensione == ".avi" || estensione == ".mov" || estensione == ".mkv" || estensione == ".wmv" || estensione == ".flv" || estensione == ".webm" || estensione == ".3gp") {
                percorso_destinazione = current_path / "Video" / percorso_origine.filename();
            } else {
                percorso_destinazione = current_path / "Altro" / percorso_origine.filename();
            }

                // Sposta il file solo se la destinazione è diversa dall'origine
                if (percorso_destinazione != percorso_origine) {
                    fs::rename(percorso_origine, percorso_destinazione);
                    cout << "Spostato '" << percorso_origine.filename() << "' in '"
                              << percorso_destinazione.parent_path().filename() << "'." <<endl;
                }
        }
    }

    return 0;
}