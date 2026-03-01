#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
#include <set>
#include <sstream>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include <chrono>
#include <vector>
#include <utility>
#include <ctime>
#include <thread>
#include <windows.h>
using namespace std;

//---KRĀSAS---
#define RESET   "\033[0m"
#define BLACK   "\033[30m"  
#define RED     "\033[31m"   
#define GREEN   "\033[32m"  
#define YELLOW  "\033[33m"  
#define BLUE    "\033[34m" 
#define MAGENTA "\033[35m"  
#define CYAN    "\033[36m" 
#define WHITE   "\033[37m" 
#define STRIKE  "\033[9m"

int reize = 1;
const int ekranaPlatums = 100;
double punkti, karatavuPunkti;

bool dzintarsIzpildits = false;
bool romasIzpildits = false;
bool fortiIzpildits = false;
bool tirgusIzpildits = false;
bool rozulaukumsIzpildits = false;
bool laumaIzpildits = false;
bool molsIzpildits = false;
bool cietumsIzpildits = false;
bool alejaIzpildits = false;
bool pludmaleIzpildits = false;
bool rtuIzpildits = false;
bool faktiIzpildits = false;

void Titullapa();
void ParSpeli();
void Spele();  
void LielaisDzintars();
void RomasDarzs();
void ZiemeluForti();
void Petertirgus();
void RozuLaukums();
void Lauma();
void DienviduMols();
void KarostasCietums();
void MuzikuAleja();
void Pludmale();
void RTU();
void FaktiParLiepaju();
void karatavas(string pavediens, string fakts, string slepenaisVards);
void Atpakal(){
    cout << "\nNospied Enter, lai turpinātu...";
    cin.get();
    system("cls");
    Spele();
}

int main() {
    Titullapa();
}

// Spēles titullapa
void Titullapa(){
    // Spēles nosaukums
    cout << R"(     _     _              ___  _       _                           ___    _   ___            
    | |   (_) ___ _ __   /_ _/(_) __ _(_)   _ __   __ _    _ __   /_ _/  | | /_ _/ __  ___   
    | |   | |/ _ \ '_ \ / _` || |/ _` | |  | '_ \ / _` |  | '_ \ / _ \/ _` |/ _` | '_ ` _ \  
    | |___| |  __/ |_) | (_| || | (_| | |  | |_) | (_| |  | |_) |  __/ (_| | (_| | | | | | | 
    |_____|_|\___| .__/ \__,_|/ |\__,_|_|  | .__/ \__,_|  | .__/ \___|\__,_|\__,_|_| |_| |_| 
                 |_|        |__/           |_|            |_|                                
    )";
                    
    cout << "\n";
    cout<<string(ekranaPlatums, '-')<<"\n";
    cout<<"| "<<left<<setw(ekranaPlatums)<<"Spēles autori: Emīls Bergs, Airita Grīnberga, Mikus Matvejevs"<<"|\n";
    cout<<"| "<<left<<setw(ekranaPlatums)<<"Aiziet, sākam izzināt Liepāju!"<<"|\n";
    cout<<string(ekranaPlatums, '-')<<"\n";
    cout<<"| "<<left<<setw(ekranaPlatums-2)<<"PAR SPĒLI [1]"<<"|\n";
    cout<<"| "<<left<<setw(ekranaPlatums-1)<<"SĀKT SPĒLI [2]"<<"|\n";
    cout<<string(ekranaPlatums, '-')<<"\n";

    while (true) {
        char key = _getch();
        if (key == '1') {
            system("cls");
            ParSpeli();
        } else if (key == '2') {
            system("cls");
            Spele();
        }
    }
}

// Sadaļa "Par spēli"
void ParSpeli(){

    cout<<string(ekranaPlatums, '-')<<"\n";
    cout<<"| "<<string(ekranaPlatums-3, ' ')<<"|\n";
    cout<<"| "<<left<<setw(ekranaPlatums-2)<<"                                         -- PAR SPĒLI --"<<"|\n";
    cout<<"| "<<string(ekranaPlatums-3, ' ')<<"|\n";
    cout<<string(ekranaPlatums, '-')<<"\n";

    cout<<string(ekranaPlatums, '-')<<"\n";
    cout<<"| "<<string(ekranaPlatums-3, ' ')<<"|\n";
    cout<<"| "<<left<<setw(ekranaPlatums)<<"Spēles autori: Emīls Bergs, Airita Grīnberga, Mikus Matvejevs"<<"|\n";
    cout<<"| "<<left<<setw(ekranaPlatums+2)<<"Spēles pamats: C++ programmēšanas valodā rakstīta programma"<<"|\n";
    cout<<"| "<<string(ekranaPlatums-3, ' ')<<"|\n";
    cout<<string(ekranaPlatums, '-')<<"\n";

    cout<<"| \033[1m1. Spēles mērķis\033[0m"<<string(ekranaPlatums-19, ' ')<<"|\n";
    cout<<"|   Tavs uzdevums ir apmeklēt dažādas Liepājas vietas un izpildīt uzdevumus, "<<string(ekranaPlatums-78, ' ')<<"|\n";
    cout<<"|   lai iegūtu pēc iespējas vairāk punktu."<<string(ekranaPlatums-43, ' ')<<"|\n";
    cout<<"| \033[1m2. Vietu apmeklēšana\033[0m"<<string(ekranaPlatums-23, ' ')<<"|\n";
    cout<<"|   Katras apmeklējuma vietas uzdevumu var izpildīt 2 reizes."<<string(ekranaPlatums-62, ' ')<<"|\n";
    cout<<"|   Kad uzdevums ir pabeigts, tas izvēlnē tiek atzīmēts kā izpildīts."<<string(ekranaPlatums-70, ' ')<<"|\n";
    cout<<"| \033[1m3. Punktu sistēma\033[0m"<<string(ekranaPlatums-20, ' ')<<"|\n";
    cout<<"|   Par katru pareizo atbildi Tu saņem punktus."<<string(ekranaPlatums-48, ' ')<<"|\n";
    cout<<"|   Par otro mēģinājumu tiek piešķirta tikai 1/2 no punktiem."<<string(ekranaPlatums-62, ' ')<<"|\n";
    cout<<"|   Ja atbilde ir nepareiza, punkti netiek piešķirti."<<string(ekranaPlatums-54, ' ')<<"|\n"; 
    cout<<"|     \033[1m1. kategorija\033[0m (3p par pareizu atbildi):"<<string(ekranaPlatums-46, ' ')<<"|\n";
    cout<<"|       Romas dārzs, Ziemeļu forti, Pētertirgus, Rožu laukums, Uzņēmums \"Lauma Fabrics\""<<string(ekranaPlatums-88, ' ')<<"|\n";
    cout<<"|     \033[1m2. kategorija\033[0m (5p par pareizu atbildi):"<<string(ekranaPlatums-46, ' ')<<"|\n";
    cout<<"|       Koncertzāle \"Lielais Dzintars\", Liepājas pludmale, Dienvidu mols,"<<string(ekranaPlatums-74, ' ')<<"|\n";
    cout<<"|       Latvijas mūziķu slavas aleja"<<string(ekranaPlatums-37, ' ')<<"|\n";
    cout<<"|     \033[1m3. kategorija\033[0m (6p par pareizu atbildi):"<<string(ekranaPlatums-46, ' ')<<"|\n";
    cout<<"|       Karostas cietums, RTU Liepājas akadēmija, Fakti par Liepāju"<<string(ekranaPlatums-68, ' ')<<"|\n";
    cout<<"| \033[1m4. Laika ierobežojumi\033[0m"<<string(ekranaPlatums-24, ' ')<<"|\n";
    cout<<"|   Dažos uzdevumos Tev ir ierobežots laiks atbildēšanai."<<string(ekranaPlatums-58, ' ')<<"|\n";
    cout<<"|   Ja nepaspēj laikā, atbilde netiek ieskaitīta."<<string(ekranaPlatums-50, ' ')<<"|\n";
    cout<<"| \033[1m5. Uzmanības uzdevumi\033[0m"<<string(ekranaPlatums-24, ' ')<<"|\n";
    cout<<"|   Dažās aktivitātēs jāiegaumē simboli vai jāatrod atšķirības attēlos."<<string(ekranaPlatums-72, ' ')<<"|\n";
    cout<<"|   Esi vērīgs un koncentrējies!"<<string(ekranaPlatums-33, ' ')<<"|\n";
    cout<<"| \033[1m6. Spēles beigas\033[0m"<<string(ekranaPlatums-19, ' ')<<"|\n";
    cout<<"|   Spēle ir pabeigta, kad visas apskates vietas ir apmeklētas un uzdevumi - izpildīti."<<string(ekranaPlatums-88, ' ')<<"|\n";

    cout<<string(ekranaPlatums, '-')<<"\n\n";
    cout<<string(ekranaPlatums, '-')<<"\n";
    cout<<"| "<<left<<setw(ekranaPlatums-1)<<"SĀKT SPĒLI [1]"<<"|\n";
    cout<<"| "<<left<<setw(ekranaPlatums-3)<<"ATGRIEZTIES [2]"<<"|\n";
    cout<<string(ekranaPlatums, '-')<<"\n";

    while (true) {
        char key = _getch();
        if (key == '1') {
            system("cls");
            Spele();
        } else if (key == '2') {
            system("cls");
            Titullapa();
        }
    }
}

void Spele(){
    // // Apskates vietu izvēle

    cout << string(ekranaPlatums, '-') << "\n";
    cout << "| " << left << setw(ekranaPlatums-2) << "                                        APMEKLĒJUMA VIETAS" << "|\n";
    cout << "| " << left << setw(ekranaPlatums-3) << "                                         _______________" << "|\n";
    cout << "|                                             PUNKTI:"<<punkti<<"                                             |\n";
    cout << "| " << string(ekranaPlatums-3, ' ') << "|\n";
        // 1
    if (dzintarsIzpildits)
        cout << "| ° " << STRIKE << "Lielais dzintars (koncertzāle)" << RESET  << string(ekranaPlatums-39, ' ') << "[1] |\n";
    else
        cout << "| " << left << setw(ekranaPlatums-5) << "° Lielais dzintars (koncertzāle)" << "[1] |\n";
        // 2
    if (romasIzpildits)
        cout << "| ° " << STRIKE << "Romas dārzs" << RESET << string(ekranaPlatums-20, ' ') << "[2] |\n";
    else
        cout << "| " << left << setw(ekranaPlatums-5) << "° Romas dārzs" << "[2] |\n";
        // 3
    if (fortiIzpildits)
        cout << "| ° " << STRIKE << "Ziemeļu forti" << RESET << string(ekranaPlatums-22, ' ') << "[3] |\n";
    else
        cout << "| " << left << setw(ekranaPlatums-5) << "° Ziemeļu forti" << "[3] |\n";
        // 4
    if (tirgusIzpildits)
        cout << "| ° " << STRIKE << "Pētertirgus" << RESET << string(ekranaPlatums-20, ' ') << "[4] |\n";
    else
        cout << "| " << left << setw(ekranaPlatums-5) << "° Pētertirgus" << "[4] |\n";
        // 5
    if (rozulaukumsIzpildits)
        cout << "| ° " << STRIKE << "Rožu laukums" << RESET << string(ekranaPlatums-21, ' ') << "[5] |\n";
    else
        cout << "| " << left << setw(ekranaPlatums-5) << "° Rožu laukums" << "[5] |\n";
        // 6
    if (laumaIzpildits)
        cout << "| ° " << STRIKE << "Uzņēmums \"Lauma Fabrics\"" << RESET << string(ekranaPlatums-33, ' ') << "[6] |\n";
    else
        cout << "| " << left << setw(ekranaPlatums-4) << "° Uzņēmums \"Lauma Fabrics\"" << "[6] |\n";
        // 7
    if (molsIzpildits)
        cout << "| ° " << STRIKE << "Dienvidu mols" << RESET << string(ekranaPlatums-22, ' ') << "[7] |\n";
    else
        cout << "| " << left << setw(ekranaPlatums-6) << "° Dienvidu mols" << "[7] |\n";
        // 8
    if (cietumsIzpildits)
        cout << "| ° " << STRIKE << "Karostas cietums" << RESET << string(ekranaPlatums-25, ' ') << "[8] |\n";
    else
        cout << "| " << left << setw(ekranaPlatums-6) << "° Karostas cietums" << "[8] |\n";
        // 9
    if (alejaIzpildits)
        cout << "| ° " << STRIKE << "Latvijas mūziķu slavas aleja" << RESET << string(ekranaPlatums-37, ' ') << "[9] |\n";
    else
        cout << "| " << left << setw(ekranaPlatums-4) << "° Latvijas mūziķu slavas aleja" << "[9] |\n";
        // 10
    if (pludmaleIzpildits)
        cout << "| ° " << STRIKE << "Liepājas pludmale" << RESET << string(ekranaPlatums-26, ' ') << "[P] |\n";
    else
        cout << "| " << left << setw(ekranaPlatums-5) << "° Liepājas pludmale" << "[P] |\n";

    if (rtuIzpildits)
        cout << "| ° " << STRIKE << "RTU Liepājas akadēmija" << RESET << string(ekranaPlatums-31, ' ') << "[R] |\n";
    else
        cout << "| " << left << setw(ekranaPlatums-4) << "° RTU Liepājas akadēmija" << "[R] |\n";

    cout << "| " << left << setw(ekranaPlatums-3) << "                                         _______________" << "|\n";

    if (faktiIzpildits)
        cout << "| ° " << STRIKE << "Fakti par Liepāju" << RESET << string(ekranaPlatums-26, ' ') << "[F] |\n";
    else
        cout << "| " << left << setw(ekranaPlatums-5) << "° Fakti par Liepāju" << "[F] |\n";
        
    cout << "| " << left << setw(ekranaPlatums-3) << "                                         _______________" << "|\n";
    cout << "| " << left << setw(ekranaPlatums-5) << "° Iziet no  spēles" << "[0] |\n";
    cout << string(ekranaPlatums, '-') << "\n";

    if (dzintarsIzpildits && romasIzpildits && fortiIzpildits && tirgusIzpildits 
        && rozulaukumsIzpildits && laumaIzpildits && molsIzpildits 
        && cietumsIzpildits && alejaIzpildits && pludmaleIzpildits && rtuIzpildits && faktiIzpildits) {
            cout << "\nNospied Enter, lai pabeigtu spēli...";
            cin.get();
            system("cls");
            cout << string(ekranaPlatums, '-') << "\n";
            cout << "| " << left << setw(ekranaPlatums+3) << "🎉🎉🎉" << "|\n";
            cout << "| " << left << setw(ekranaPlatums-2) << "Paldies par spēli!" << "|\n";
            string rinda = "Tev izdevās iegūt " + to_string(punkti) + " punktus!";
            cout << "| " << left << setw(ekranaPlatums-1) << rinda << "|\n";
            cout << string(ekranaPlatums, '-') << "\n";
    }

    while (true) {
        char key = _getch();
        switch(key){
            case '1':  system("cls"); LielaisDzintars(); break;
            case '2':  system("cls"); RomasDarzs(); break;
            case '3':  system("cls"); ZiemeluForti(); break;
            case '4':  system("cls"); Petertirgus(); break;
            case '5':  system("cls"); RozuLaukums(); break;
            case '6':  system("cls"); Lauma(); break;
            case '7':  system("cls"); DienviduMols(); break;
            case '8':  system("cls"); KarostasCietums(); break;
            case '9':  system("cls"); MuzikuAleja(); break;
            case 'p':  system("cls"); Pludmale(); break;
            case 'r':  system("cls"); RTU(); break;
            case 'f':  system("cls"); FaktiParLiepaju(); break;
            case '0':  system("cls"); Titullapa(); break;
        }
    }
}

int dzintarsReize = 1;
void LielaisDzintars(){
    double dzintarsPunkti = 0;
    
    if (dzintarsIzpildits) {
        cout << YELLOW << "Šis tests jau ir izpildīts!\n"  << RESET;
        Atpakal();
    } else {
        cout << "\nKONCERTZĀLE \"LIELAIS DZINTARS\"\n\n";
        cout << "Lielais Dzintars (koncertzāle) - Mūsdienīga koncertzāle Liepājā ar iespaidīgu dzintara krāsas stikla fasādi.\n";
        cout << "Šeit notiek koncerti, festivāli un citi kultūras pasākumi.\n";

        {
            ifstream fails("TestsDzintars.txt");
            string jautajums, v1, v2, v3, pareiza;

            while (getline(fails, jautajums)) {
                getline(fails, v1);
                getline(fails, v2);
                getline(fails, v3);
                getline(fails, pareiza);

                cout << "\n" << jautajums << "\n";
                cout << "[1] " << v1 << "\n";
                cout << "[2] " << v2 << "\n";
                cout << "[3] " << v3 << "\n";

                int atbilde;
                cout << "Tava atbilde (1-3): ";
                cin >> atbilde;
                cin.get();

                if ((atbilde == 1 && v1 == pareiza) ||
                    (atbilde == 2 && v2 == pareiza) ||
                    (atbilde == 3 && v3 == pareiza)) {
                    if (dzintarsReize == 1){
                        cout << GREEN << "Pareizi! +1p\n" << RESET;
                        dzintarsPunkti++;
                    } else {
                        cout << GREEN << "Pareizi! +0.5p\n" << RESET;
                        dzintarsPunkti += 0.5;
                    }

                } else {cout << RED << "Nepareizi! Pareizā atbilde: " << pareiza << RESET << "\n";}
            }
            fails.close();
        }
        cout << "\nTAVI PUNKTI PAR ŠO TESTU: " << dzintarsPunkti << "\n\n";

        if (dzintarsReize == 1 && dzintarsPunkti < 5) {
           cout << "SPĒLĒT VĒLREIZ [1]\n";
           cout << "ATGRIEZTIES IZVĒLNĒ [0]\n"; 
           while (true) {
                char key = _getch();
                if (key == '0') {
                    punkti += dzintarsPunkti;
                    dzintarsIzpildits = true;
                    Atpakal();  
                }
                if (key == '1') {
                    dzintarsReize = 2;
                    system("cls");
                    LielaisDzintars();     
                }
            }
        } else {
            punkti += dzintarsPunkti;
            dzintarsIzpildits = true;
            Atpakal();
        }
    }
}

int romasDarzsReize = 1;
void RomasDarzs(){
    double romasDarzsPunkti = 0;
    if (romasIzpildits) {
        cout << YELLOW << "Šis tests jau ir izpildīts!\n" << RESET;
        Atpakal();
    } else {
        cout << "\nROMAS DĀRZS\n\n";
        cout << "Romas Dārzs - Skaists pagalms pilsētas centrā, lieliska vieta pastaigām un atpūtai.\n";
        cout << "Iespējams apmeklēt mākslas galeriju un nakšņot viesnīcā.\n";

        {
            ifstream fails2("TFRomasDarzs.txt");
            string jautajums, v1, v2, pareiza;

            while (getline(fails2, jautajums)) {
                getline(fails2, v1);
                getline(fails2, v2);
                getline(fails2, pareiza);

                cout << "\n" << jautajums << "\n";
                cout << "[1] " << v1 << "\n";
                cout << "[2] " << v2 << "\n";

                int atbilde;
                cout << "Tava atbilde (1-2): ";
                cin >> atbilde;
                cin.get();

                if ((atbilde == 1 && v1 == pareiza) ||
                    (atbilde == 2 && v2 == pareiza)) {

                    if (romasDarzsReize == 1){
                        cout << GREEN << "Pareizi! +1p\n" << RESET;
                        romasDarzsPunkti++;
                    } else {
                        cout << GREEN << "Pareizi! +0.5p\n" << RESET;
                        romasDarzsPunkti += 0.5;
                    }

                } else {
                    cout << RED << "Nepareizi! Pareizā atbilde: " << pareiza << RESET << "\n";
                }
            }
            fails2.close();
        }

        cout << "\nTAVI PUNKTI PAR ŠO TESTU: " << romasDarzsPunkti << "\n\n";

        if (romasDarzsReize == 1 && romasDarzsPunkti < 3) {
           cout << "SPĒLĒT VĒLREIZ [1]\n";
           cout << "ATGRIEZTIES IZVĒLNĒ [0]\n"; 
           while (true) {
                char key = _getch();
                if (key == '0') {
                    punkti += romasDarzsPunkti;
                    romasIzpildits = true;
                    Atpakal();  
                }
                if (key == '1') {
                    romasDarzsReize = 2;
                    system("cls");
                    RomasDarzs();     
                }
            }
        } else {
            punkti += romasDarzsPunkti;
            romasIzpildits = true;
            Atpakal();
        }
    }
}

int fortiReize = 1;
void ZiemeluForti(){
    double fortiPunkti = 0;
    if (fortiIzpildits) {
        cout << YELLOW << "Šis tests jau ir izpildīts!\n" << RESET;
        Atpakal();
    } else {
        cout << "\nZIEMEĻU FORTI\n\n";
        cout << "Ziemeļu Forti - Vēsturiskas militārās būves pie jūras.\n";
        cout << "Celtas 19. gadsimtā, šodien ir populāra apskates vieta.\n";

        {
            ifstream fails3("TestsZiemeluForti.txt");
            string jautajums, v1, v2, v3, pareiza;

            while (getline(fails3, jautajums)) {
                getline(fails3, v1);
                getline(fails3, v2);
                getline(fails3, v3);
                getline(fails3, pareiza);

                cout << "\n" << jautajums << "\n";
                cout << "[1] " << v1 << "\n";
                cout << "[2] " << v2 << "\n";
                cout << "[3] " << v3 << "\n";

                int atbilde;
                cout << "Tava atbilde (1-3): ";
                cin >> atbilde;
                cin.get();

                if ((atbilde == 1 && v1 == pareiza) ||
                    (atbilde == 2 && v2 == pareiza) ||
                    (atbilde == 3 && v3 == pareiza)) {

                    if (fortiReize == 1){
                        cout << GREEN << "Pareizi! +1p\n" << RESET;
                        fortiPunkti++;
                    } else {
                        cout << GREEN << "Pareizi! +0.5p\n" << RESET;
                        fortiPunkti += 0.5;
                    }

                } else {
                    cout << RED << "Nepareizi! Pareizā atbilde: " << pareiza << RESET << "\n";
                }
            }
            fails3.close();
        }

        cout << "\nTAVI PUNKTI PAR ŠO TESTU: " << fortiPunkti << "\n\n";

        if (fortiReize == 1 && fortiPunkti < 3) {
           cout << "SPĒLĒT VĒLREIZ [1]\n";
           cout << "ATGRIEZTIES IZVĒLNĒ [0]\n"; 
           while (true) {
                char key = _getch();
                if (key == '0') {
                    punkti += fortiPunkti;
                    fortiIzpildits = true;
                    Atpakal();  
                }
                if (key == '1') {
                    fortiReize = 2;
                    system("cls");
                    ZiemeluForti();     
                }
            }
        } else {
            punkti += fortiPunkti;
            fortiIzpildits = true;
            Atpakal();
        }
    }
}

int tirgusReize = 1;
void Petertirgus(){
    double tirgusPunkti = 0;
    if (tirgusIzpildits) {
        cout << YELLOW << "Šis uzdevums jau ir izpildīts!\n" << RESET;
        Atpakal();
    } else {
        cout << "\nPĒTERTIRGUS\n\n";
        cout << "Pētertirgus - Viens no skaistākajiem tirgus paviljoniem Eiropā.\n";
        cout << "Pētertirgus ir lielākais Liepājas un otrs lielākais Latvijas tirgus.\n";

        {
            ifstream fails4("TestsPetertirgus.txt");
            string jautajums, pareiza;

            while (getline(fails4, jautajums)) {
                getline(fails4, pareiza);

                cout << "\n" << jautajums << "\n";

                int atbilde;
                cout << "Tava atbilde (ar cipariem): ";
                cin >> atbilde;
                cin.get();

                if (atbilde == 27) {

                    if (tirgusReize == 1){
                        cout << GREEN << "Pareizi! +3p\n" << RESET;
                        tirgusPunkti += 3;
                    } else {
                        cout << GREEN << "Pareizi! +1.5p\n" << RESET;
                        tirgusPunkti += 1.5;
                    }

                } else {
                    cout << RED << "Nepareizi! Pareizā atbilde: " << pareiza << RESET << "\n";
                }
            }
            fails4.close();
        }

        cout << "\nTAVI PUNKTI PAR ŠO UZDEVUMU: " << tirgusPunkti << "\n\n";

        if (tirgusReize == 1 && tirgusReize < 3) {
           cout << "SPĒLĒT VĒLREIZ [1]\n";
           cout << "ATGRIEZTIES IZVĒLNĒ [0]\n"; 
           while (true) {
                char key = _getch();
                if (key == '0') {
                    punkti += tirgusPunkti;
                    tirgusIzpildits = true;
                    Atpakal();  
                }
                if (key == '1') {
                    tirgusReize = 2;
                    system("cls");
                    Petertirgus();     
                }
            }
        } else {
            punkti += tirgusPunkti;
            tirgusIzpildits = true;
            Atpakal();
        }
    }
}

int rozulaukumsReize = 1;
void RozuLaukums(){
    double rozuLaukumsPunkti = 0;
    if (rozulaukumsIzpildits) {
        cout << YELLOW << "Šis uzdevums jau ir izpildīts!\n" << RESET;
        Atpakal();
    } else {
        cout << "ROŽU LAUKUMS\n\n";
        cout << "Rožu laukums - Populārs laukums pilsētas centrā, tā nemainīga vērtība ir rozes, kas šeit tiek stādītas jau vairāk nekā simts gadus.\n";

        {
            ifstream fails5("TestsRozuLaukums.txt");
            string jautajums, pareiza;

            while (getline(fails5, jautajums)) {
                getline(fails5, pareiza);

                cout << "\n" << jautajums << "\n";

                int atbilde;
                cout << "Tava atbilde (ar cipariem): ";
                cin >> atbilde;
                cin.get();

                if (atbilde == 130) {

                    if (rozulaukumsReize == 1){
                        cout << GREEN << "Pareizi! +3p\n" << RESET;
                        rozuLaukumsPunkti += 3;
                    } else {
                        cout << GREEN << "Pareizi! +1.5p\n" << RESET;
                        rozuLaukumsPunkti += 1.5;
                    }

                } else {
                    cout << RED << "Nepareizi! Pareizā atbilde: " << pareiza << RESET << "\n";
                }
            }
            fails5.close();
        }

        cout << "\nTAVI PUNKTI PAR ŠO UZDEVUMU: " << rozuLaukumsPunkti << "\n\n";

        if (rozulaukumsReize == 1 && rozuLaukumsPunkti < 3) {
           cout << "SPĒLĒT VĒLREIZ [1]\n";
           cout << "ATGRIEZTIES IZVĒLNĒ [0]\n"; 
           while (true) {
                char key = _getch();
                if (key == '0') {
                    punkti += rozuLaukumsPunkti;
                    rozulaukumsIzpildits = true;
                    Atpakal();  
                }
                if (key == '1') {
                    rozulaukumsReize = 2;
                    system("cls");
                    RozuLaukums();     
                }
            }
        } else {
            punkti += rozuLaukumsPunkti;
            rozulaukumsIzpildits = true;
            Atpakal();
        }

    }
}

int laumaReize = 1;
void Lauma(){
    double laumaPunkti = 0;
   if (laumaIzpildits) {
        cout << YELLOW << "Šis uzdevums jau ir izpildīts!\n" << RESET;
        Atpakal();
    } else {
        string virkne;
        cout << "LAUMA FABRICS\n\n";
        cout << "Lauma Fabrics - Tekstila uzņēmums, kas ražo mežģīnes un audumus.\n";
        cout << "Viens no pazīstamākajiem Liepājas ražošanas uzņēmumiem.\n\n";
        cout << "Tev tiks parādīta simbolu virkne, kas satur uzņēmuma Lauma Fabrics vispārīgos datus.\n";
        cout << "Mēģini šo simbolu virkni iegaumēt!\n";

        cout << "Spēle sākas pēc: ";

        // Atpakaļskaitījums no 10 līdz 1
        for (int i = 10; i >= 1; i--) {
            cout << GREEN << i << " ";
            cout.flush(); // izdrukā uzreiz
            cout << RESET;
            Sleep(1000);
        }

        cout << RED << "\nLAUMA1971LIEPĀJAFABRICS2019" << RESET;
        Sleep(5000);
        system("cls");
        cout << "Ievadi simbolu virkni: ";
        cin >> virkne;
        cin.get();

        if (virkne == "LAUMA1971LIEPĀJAFABRICS2019") {

            if (laumaReize == 1){
                cout << GREEN << "Pareizi! +3p\n" << RESET;
                laumaPunkti += 3;
            } else {
                cout << GREEN << "Pareizi! +1.5p\n" << RESET;
                laumaPunkti += 1.5;
            }

        } else {
            cout << RED << "\nNepareizi! Pareizā atbilde: LAUMA1971LIEPĀJAFABRICS2019" << RESET << "\n";
        }

        cout << "\nTAVI PUNKTI PAR ŠO UZDEVUMU: " << laumaPunkti << "\n\n";

        if (laumaReize == 1 && laumaPunkti < 3) {
           cout << "SPĒLĒT VĒLREIZ [1]\n";
           cout << "ATGRIEZTIES IZVĒLNĒ [0]\n"; 
           while (true) {
                char key = _getch();
                if (key == '0') {
                    punkti += laumaPunkti;
                    laumaIzpildits = true;
                    Atpakal();  
                }
                if (key == '1') {
                   laumaReize = 2;
                    system("cls");
                    Lauma();     
                }
            }
        } else {
            punkti += laumaPunkti;
            laumaIzpildits = true;
            Atpakal();
        }
    }
}

int molsReize = 1;
void DienviduMols(){
    double molsPunkti = 0;
    if (molsIzpildits) {
        cout << YELLOW << "Šis uzdevums jau ir izpildīts!\n" << RESET;
        Atpakal();
    } else {
        system("cls");
        cout << "DIENVIDU MOLS\n\n";
        cout << "Dienvidu mols - Iemīļota pastaigu vieta pie jūras 700 metru garumā. No mola var vērot kuģus un saulrietus.\n\n";
        cout << "Tev tiks parādīti divi attēli. Atrodi atšķirības starp tiem!\n";
        Sleep(5000);

        string rinda;
        
        // Izvada pirmo attēlu (ascii3.txt)
        system("cls");
        cout << "1. ATTĒLS:\n";
        ifstream file1("ascii3.txt");
        if (file1.is_open()) {
            while (getline(file1, rinda)) {
                cout << rinda << "\n";
            }
            file1.close();
        } else {
            cout << "Kļūda: Nevarēja atvērt ascii3.txt\n";
        }

        cout << "\n(Nospied Enter, lai redzētu 2. attēlu...)\n";
        cin.get();

        // Izvada otro attēlu (ascii4.txt)
        system("cls");
        cout << "2. ATTĒLS (ar atšķirībām):\n";
        ifstream file2("ascii4.txt");
        if (file2.is_open()) {
            while (getline(file2, rinda)) {
                cout << rinda << "\n";
            }
            file2.close();
        } else {
            cout << "Kļūda: Nevarēja atvērt ascii4.txt\n";
        }

        // Atbildes pārbaude
        int atbilde;
        cout << "\nCik atšķirības Tu atradi? ";
        cin >> atbilde;
        cin.get();

        if (atbilde == 5) {

            if (molsReize == 1){
                cout << GREEN << "Pareizi! +5p\n" << RESET;
                molsPunkti += 5;
            } else {
                cout << GREEN << "Pareizi! +2.5p\n" << RESET;
                molsPunkti += 2.5;
            }
        } else {
            cout << RED << "\nNepareizi! Bija 5 atšķirības (saule, laiva, zvaigzne, logs, rokturis)." << RESET << "\n";
        }

        cout << "\nTAVI PUNKTI PAR ŠO UZDEVUMU: " << molsPunkti << "\n\n";

        if (molsReize == 1  && molsPunkti < 5) {
           cout << "SPĒLĒT VĒLREIZ [1]\n";
           cout << "ATGRIEZTIES IZVĒLNĒ [0]\n"; 
           while (true) {
                char key = _getch();
                if (key == '0') {
                    punkti += molsPunkti;
                    molsIzpildits = true;
                    Atpakal();  
                }
                if (key == '1') {
                    molsReize = 2;
                    system("cls");
                    DienviduMols();     
                }
            }
        } else {
            punkti += molsPunkti;
            molsIzpildits = true;
            Atpakal();
        }
    }
}

int cietumsReize = 1;
void KarostasCietums(){
    double cietumsPunkti = 0;
    if (cietumsIzpildits) {
        cout << YELLOW << "Šis tests jau ir izpildīts!\n" << RESET;
        Atpakal();
    } else {
        cout << "\nKAROSTAS CIETUMS\n\n";
        cout << "Karostas cietums - Vēsturiska militārā cietuma ēka Karostā. Apmeklētāji var piedalīties ekskursijās un izjust vēsturisko atmosfēru.\n";

        {
            ifstream fails("KarostasCietums.txt");
            string jautajums, v1, v2, v3, v4, pareiza;

            cout << "AK VAI! 😨\n";
            cout << "Tu esi notiesāts par noziegumu, ko neesi izdarījis.\n";
            cout << "5 gadi Karostas cietuma aukstajās sienās...\n\n";
            cout << "Bet tu zini vienu — tu šeit nepaliksi.\n";
            cout << "Šovakar sākas tavs plāns.\n";

            while (getline(fails, jautajums)) {
                getline(fails, v1);
                getline(fails, v2);
                getline(fails, v3);
                getline(fails, v4);
                getline(fails, pareiza);

                cout << "\n" << YELLOW << jautajums << "\n" << RESET;
                cout << "[1] " << v1 << "\n";
                cout << "[2] " << v2 << "\n";

                int atbilde;
                cout << "\nTu izvēlies: ";
                cin >> atbilde;
                cin.get();

                cout << "\n";

                if ((atbilde == 1 && v1 == pareiza) ||
                    (atbilde == 2 && v2 == pareiza)) {

                    cout << GREEN << v4 << RESET << "\n";
                    if (cietumsReize == 1){
                        cietumsPunkti++;
                    } else {
                        cietumsPunkti += 0.5;
                    }

                } else {
                    cout << RED << v3 << RESET << "\n";
                    break;
                }
            }
            fails.close();
        }

        cout << "\nTAVI PUNKTI PAR ŠO AKTIVITĀTI: " << cietumsPunkti << "\n\n";

        if (cietumsReize == 1 && cietumsPunkti < 6) {
           cout << "SPĒLĒT VĒLREIZ [1]\n";
           cout << "ATGRIEZTIES IZVĒLNĒ [0]\n"; 
           while (true) {
                char key = _getch();
                if (key == '0') {
                    punkti += cietumsPunkti;
                    cietumsIzpildits = true;
                    Atpakal();  
                }
                if (key == '1') {
                    cietumsReize = 2;
                    system("cls");
                    KarostasCietums();     
                }
            }
        } else {
            punkti += cietumsPunkti;
            cietumsIzpildits = true;
            Atpakal();
        }
    }
}

int alejaReize = 1;
void MuzikuAleja(){
    double alejaPunkti = 0;
    if (alejaIzpildits) {
        cout << YELLOW << "Šis uzdevums jau ir izpildīts!\n" << RESET;
        Atpakal();
    } else {
        cout << "\nLATVIJAS MŪZIĶU SLAVAS ALEJA\n\n";
        cout << "Latvijas mūziķu slavas aleja - Aleja, kurā iemūžināti slaveni Latvijas mūziķi ar plāksnēm un nospiedumiem.\n\n";

        {
        ifstream fails("MuzikuAleja.txt");
            string jautajums, v1, v2, v3, pareiza;

            cout << "Pārbaudi savas zināšanas par Latvijas mūzikas ansambļu dalībniekiem!\n";
            cout << YELLOW << "Tev ir dotas tikai 5 sekundes!\n" << RESET;
            cout << "\nNospied Enter, lai sāktu...";
            cin.get();
            
            while (getline(fails, jautajums)) {
                getline(fails, v1);
                getline(fails, v2);
                getline(fails, v3);
                getline(fails, pareiza);

                cout << "\n" << jautajums << "\n";
                cout << "[1] " << v1 << "\n";
                cout << "[2] " << v2 << "\n";
                cout << "[3] " << v3 << "\n";

                auto start = chrono::steady_clock::now();

                int atbilde;
                cout << "\nTava atbilde (1-3): ";
                cin >> atbilde;
                cin.get();

                auto end = chrono::steady_clock::now();
                double elapsed = chrono::duration<double>(end - start).count();

                cout << "\n";

                if (elapsed > 5.0) {
                    cout << RED << "⏳ Laiks beidzies! Pareizā atbilde bija: " << pareiza << RESET << "\n";
                } else if ((atbilde == 1 && v1 == pareiza) ||
                    (atbilde == 2 && v2 == pareiza) ||
                    (atbilde == 3 && v3 == pareiza)) {

                    if (alejaReize == 1){
                        cout << GREEN << "Pareizi! +1p\n" << RESET;
                        alejaPunkti++;
                    } else {
                        cout << GREEN << "Pareizi! +0.5p\n" << RESET;
                        alejaPunkti += 0.5;
                    }

                } else {
                    cout << RED << "Nepareizi! Pareizā atbilde: " << pareiza << RESET << "\n";
                }
            }
            fails.close();
        }

        cout << "\nTAVI PUNKTI PAR ŠO UZDEVUMU: " << alejaPunkti << "\n\n";

        if (alejaReize == 1 && alejaPunkti < 5) {
           cout << "SPĒLĒT VĒLREIZ [1]\n";
           cout << "ATGRIEZTIES IZVĒLNĒ [0]\n"; 
           while (true) {
                char key = _getch();
                if (key == '0') {
                    punkti += alejaPunkti;
                    alejaIzpildits = true;
                    Atpakal();  
                }
                if (key == '1') {
                    alejaReize = 2;
                    system("cls");
                    MuzikuAleja();     
                }
            }
        } else {
            punkti += alejaPunkti;
            alejaIzpildits = true;
            Atpakal();
        }
    }
}

int pludmaleReize = 1;
void Pludmale(){
    double pludmalePunkti = 0;
    if (pludmaleIzpildits) {
        cout << YELLOW << "Šī aktivitāte jau ir izpildīta!\n" << RESET;
        Atpakal();
    } else {
        cout << "\nDZINTARU SKAITĪŠANA\n\n";
        cout << "Liepājas pludmale - Plaša un smilšaina pludmale pie Baltijas jūras. Ideāla vieta atpūtai vasarā.\n\n";
        cout << "Uzdevums: Tev tiks rādīts attēls ar dzintariem. Tev ir dotas 3 sekundes.\n";
        cout << "Atceries, cik dzintari parādījās!\n";
        cout << "Spēle sākas pēc: ";

        // Atpakaļskaitījums no 10 līdz 1
        for (int i = 10; i >= 1; i--) {
            cout << GREEN<< i << " ";
            cout.flush(); // izdrukā uzreiz
            cout << RESET;
            Sleep(1000);
        }

        cout << "\n";

        // Ielasa ASCII no faila
        vector<string> ascii;
        ifstream asciiFails("ascii2.txt");
        string rinda;
        while (getline(asciiFails, rinda))
            ascii.push_back(rinda);
        asciiFails.close();

        int dzintaruSkaits = 10; // cik dzintari parādās
        srand(time(0));

        // Sagatavo dzintaru koordinātas tikai no 18. rindas uz leju
        vector<pair<int,int>> dzintaruVietas;
        int asciiRinduSkaits = ascii.size();

        while (dzintaruVietas.size() < dzintaruSkaits) {
            int x = 18 + rand() % (asciiRinduSkaits - 18);
            int y = rand() % ascii[x].length();

            bool briva = true;
            for (auto &v : dzintaruVietas) {
                if (v.first == x && v.second == y) {
                    briva = false;
                    break;
                }
            }
            if (briva)
                dzintaruVietas.push_back({x,y});
        }

        // Parāda ASCII ar dzintariem tikai izvēlētajās vietās
        for (int i = 0; i < ascii.size(); i++) {
            for (int j = 0; j < ascii[i].length(); j++) {
                bool irDzintars = false;
                for (auto &v : dzintaruVietas) {
                    if (v.first == i && v.second == j) {
                        irDzintars = true;
                        break;
                    }
                }
                if (irDzintars)
                    cout << YELLOW << "@" << RESET;
                else
                    cout << ascii[i][j];
            }
            cout << "\n";
        }

        // 3 sekundes pauze ar dzintariem
        Sleep(3000);

        // Notīra ekrānu
        system("cls");

        // Atkal uzzīmē tikai ASCII bez dzintariem
        for (auto &line : ascii)
            cout << line << "\n";

        // Jautājums spēlētājam
        int atbilde;
        cout << "\nCik dzintari parādījās? ";
        cin >> atbilde;
        cin.get();

        if (atbilde == dzintaruSkaits) {
            if (pludmaleReize == 1){
                cout << GREEN << "Pareizi! +5p\n" << RESET;
                pludmalePunkti += 5;
            } else {
                cout << GREEN << "Pareizi! +2.5p\n" << RESET;
                pludmalePunkti += 2.5;
            }
        } else {
            cout << RED << "Nepareizi! Pareizā atbilde: " << dzintaruSkaits << RESET << "\n";
        }

        cout << "\nTAVI PUNKTI PAR ŠO AKTIVITĀTI: " << pludmalePunkti << "\n\n";

        if (pludmaleReize == 1 && pludmalePunkti < 5) {
           cout << "SPĒLĒT VĒLREIZ [1]\n";
           cout << "ATGRIEZTIES IZVĒLNĒ [0]\n"; 
           while (true) {
                char key = _getch();
                if (key == '0') {
                    punkti += pludmalePunkti;
                    pludmaleIzpildits = true;
                    Atpakal();  
                }
                if (key == '1') {
                    pludmaleReize = 2;
                    system("cls");
                    Pludmale();     
                }
            }
        } else {
            punkti += pludmalePunkti;
            pludmaleIzpildits = true;
            Atpakal();
        }
    }
}

int rtuReize = 1;
void RTU(){
double rtuPunkti = 0;
    if (rtuIzpildits) {
        cout << YELLOW << "Šis tests jau ir izpildīts!\n"  << RESET;
        Atpakal();
    } else {
        cout << "RTU Liepājas akadēmija\n\n";
        cout << "RTU Liepājas akadēmija - Augstākās izglītības iestāde, kas piedāvā dažādas studiju programmas Liepājā, daļa no Rīgas Tehniskās universitātes.\n\n";
        cout << "Studiju programma - Datorsistēmas\n";
        cout << "Pasniedzējs pārbauda Tavas līdzšinējās zināšanas programmēšanas valodā Java.\n";
        cout << "Kāds būs katra programmas fragmenta izpildes rezultāts?\n";

        {
            ifstream fails("TestsRtu.txt");
            string jautajums, v1, v2, v3, pareiza;

            while (getline(fails, jautajums)) {
                getline(fails, v1);
                getline(fails, v2);
                getline(fails, v3);
                getline(fails, pareiza);

                cout << "\n" << jautajums << "\n";
                cout << "[1] " << v1 << "\n";
                cout << "[2] " << v2 << "\n";
                cout << "[3] " << v3 << "\n";

                int atbilde;
                cout << "Tava atbilde (1-3): ";
                cin >> atbilde;
                cin.get();

                if ((atbilde == 1 && v1 == pareiza) ||
                    (atbilde == 2 && v2 == pareiza) ||
                    (atbilde == 3 && v3 == pareiza)) {
                    if (rtuReize == 1){
                        cout << GREEN << "Pareizi! +1p\n" << RESET;
                        rtuPunkti++;
                    } else {
                        cout << GREEN << "Pareizi! +0.5p\n" << RESET;
                        rtuPunkti += 0.5;
                    }

                } else {cout << RED << "Nepareizi! Pareizā atbilde: " << pareiza << RESET << "\n";}
            }
            fails.close();
        }
        cout << "\nTAVI PUNKTI PAR ŠO TESTU: " << rtuPunkti << "\n\n";

        if (rtuReize == 1 && rtuPunkti < 6) {
            cout << "SPĒLĒT VĒLREIZ [1]\n";
            cout << "ATGRIEZTIES IZVĒLNĒ [0]\n"; 
            while (true) {
                char key = _getch();
                if (key == '0') {
                    punkti += rtuPunkti;
                    rtuIzpildits = true;
                    Atpakal();  
                }
                if (key == '1') {
                    rtuReize = 2;
                    system("cls");
                    RTU();     
                }
            }
        } else {
            punkti += rtuPunkti;
            rtuIzpildits = true;
            Atpakal();
        }
    }
}


void FaktiParLiepaju(){
    if (faktiIzpildits) {
        cout << YELLOW << "Šī aktivitāte jau ir izpildīta!\n" << RESET;
        Atpakal();
    } else {
        int LokalaisReize = 1;  
        while (true) {
            reize = LokalaisReize;

            cout<<string(ekranaPlatums, '-')<<"\n";
            cout<<"| "<<left<<setw(ekranaPlatums)<<
                "                               SPĒLE \"KARĀTAVAS - FAKTI PAR LIEPĀJU\""<<"|\n";
            cout<<"| "<<left<<setw(ekranaPlatums-3)<<
                "                                         _______________"<<"|\n";
            cout<<"| "<<left<<setw(ekranaPlatums + 1)<<
                "Balstoties uz doto pavedienu, jāatmin slepenais vārds, kas saistīts ar faktu par Liepāju."<<"|\n";

            if (reize == 1) {
                cout<<"| "<<left<<setw(ekranaPlatums - 1)<<
                    "Par katru pareizi atminētu vārdu - 2 punkti."<<"|\n";
            } else {
                karatavuPunkti = 0; 
                cout<<"| "<<left<<setw(ekranaPlatums - 1)<<
                    "Par katru pareizi atminētu vārdu - 1 punkts."<<"|\n";
            }
            cout<<string(ekranaPlatums, '-')<<"\n";

            karatavas("Preču vai pakalpojumu apgrozības sfēra.", "Pēter\033[1mtirgus\033[0m ir viens no arhitektoniski skaistākajiem tirgus paviljoniem.", "tirgus");
            karatavas("Vieta, kur ir ierobežota kustības brīvība.", "Karostas \033[1mcietums\033[0m ir vienīgais militārais cietums, kas atvērts tūristiem.", "cietums");
            karatavas("Virzīties, pārvietoties gaisā.", "No Liepājas uz Rīgu var aiz\033[1mlidot\033[0m 27 minūtēs.", "lidot");

            if (karatavuPunkti < 6) {
                cout<<string(ekranaPlatums, '-')<<"\n";
                string rinda = "Par šo aktivitāti Tu ieguvi: " + to_string(karatavuPunkti) + " punktus";
                cout<<"| "<<left<<setw(ekranaPlatums - 1)<<rinda<<"|\n";
                cout<<"| "<<string(ekranaPlatums-3, ' ')<<"|\n";
                cout<<"| "<<left<<setw(ekranaPlatums - 1)<<"ATGRIEZTIES IZVĒLNĒ [0]"<<"|\n";
                cout<<"| "<<left<<setw(ekranaPlatums)<<"SPĒLĒT VĒLREIZ [1]"<<"|\n";
                cout<<string(ekranaPlatums, '-')<<"\n";

                while (true) {
                    char key = _getch();
                    if (key == '0') {
                        faktiIzpildits = true;
                        punkti += karatavuPunkti;
                        system("cls");
                        Spele();
                        return;  
                    }
                    if (reize == 1 && key == '1') {
                        LokalaisReize = 2;
                        system("cls");
                        break;     
                    }
                }
            } else {
                cout << "\nTAVI PUNKTI PAR ŠO AKTIVITĀTI: " << karatavuPunkti << "\n\n";
                punkti += karatavuPunkti;
                faktiIzpildits = true;
                Atpakal();
            }
        }
    }
}

void karatavas(string pavediens, string fakts, string slepenaisVards){
    // Faktu karātavas par Liepāju
    string atminetaisVards(slepenaisVards.length(), '_');
    set<char> minetieBurti;
    int atlikusieMeginajumi = 6;
    
    cout<<"\n"<<string(ekranaPlatums, '-')<<"\n";
    string rinda = "Pavediens: " + pavediens;
    cout<<"| "<<left<<setw(ekranaPlatums-1)<<rinda<<" |\n";

    while (atlikusieMeginajumi > 0 && atminetaisVards != slepenaisVards) {
        ostringstream oss, oss2, oss3;
        for (char s : atminetaisVards) {
            oss<<s<<" ";
        }
        cout<<"| "<<left<<setw(ekranaPlatums - 2)<<("Vārds: " + oss.str())<<"|\n";

        oss2<<atlikusieMeginajumi;
        cout<<"| "<<left<<setw(ekranaPlatums + 1)<<("Atlikušie mēģinājumi: " + oss2.str())<<"|\n";
      
        for (char s : minetieBurti) {
            oss3<<s<<" ";
        }
        cout<<"| "<<left<<setw(ekranaPlatums - 2)<<("Minētie burti: " + oss3.str())<<"|\n";

        cout<<"| "<<"Ievadi burtu: ";
        char minamaisBurts;
        cin>>minamaisBurts;
        cin.get();
        cout<<"|"<<string(ekranaPlatums-2, ' ')<<"|\n";


        minamaisBurts = tolower(minamaisBurts);

        if (minetieBurti.count(minamaisBurts)) {
            cout<<"| "<<YELLOW<<left<<setw(ekranaPlatums - 1) <<"Tu jau minēji šo burtu!"<<RESET<<"|\n";
            cout<<"| "<<string(ekranaPlatums-3, ' ')<<"|\n";
            continue;
        }

        minetieBurti.insert(minamaisBurts);

        bool atrasts = false;
        for (int i = 0; i < (int)slepenaisVards.length(); i++) {
            if (slepenaisVards[i] == minamaisBurts) {
                atminetaisVards[i] = minamaisBurts;
                atrasts = true;
            }
        }

        if (!atrasts) {
            atlikusieMeginajumi--;
            cout<<"| "<<RED<<left<<setw(ekranaPlatums - 3) <<"Nepareizi!"<<RESET<<"|\n";
            cout<<"| "<<string(ekranaPlatums-3, ' ')<<"|\n";
        } else {
            cout<<"| "<<GREEN<<left<<setw(ekranaPlatums - 3)<<"Pareizi!"<<RESET<<"|\n";
            cout<<"| "<<string(ekranaPlatums-3, ' ')<<"|\n";
        }
    }
    if(slepenaisVards == atminetaisVards){
        if(reize == 1){
            cout<<"| "<<GREEN<<left<<setw(ekranaPlatums - 1)<<"Apsveicam! Tu atminēji vārdu! +2p"<<RESET<<"|\n";
            karatavuPunkti += 2;
        } else {
            cout<<"| "<<GREEN<<left<<setw(ekranaPlatums - 1)<<"Apsveicam! Tu atminēji vārdu! +1p"<<RESET<<"|\n";
           karatavuPunkti++;
        }
    } else {
        ostringstream oss4;
        oss4<<slepenaisVards;
        cout<<"| "<<RED<<left<<setw(ekranaPlatums + 2)<<"Diemžēl, Tev neizdevās atminēt vārdu!"<<RESET<<"|\n";
        cout<<"| "<<left<<setw(ekranaPlatums - 2)<<"Pareizais vārds bija: " + oss4.str()<<"|\n";
    }

    ostringstream oss5;
    oss5<<fakts;
    cout<<"| "<<string(ekranaPlatums-3, ' ')<<"|\n";
    cout<<"| "<<left<<setw(ekranaPlatums + 7) <<"Fakts: " + oss5.str()<<"|\n";
    cout<<string(ekranaPlatums, '-')<<"\n";
}