#include <iostream> 
using namespace std; 

int main () {
    // Deklarasi Variabel Penting
    int kesempatanLogin = 3;
    bool berhasilLogin = false; 
    float nilai, konversiMenit, konversiDetik, konversiJam;
    
    // Username dan Password yang benar
    string username = "Yoga"; string password = "017";
    
    // Variabel untuk Authorisasi Login
    string usernameInput, passwordInput;
    
    cout << "\n==== Program Konversi Waktu =============================" << endl; 
    cout << "---------------------------------------------------------" << endl;
    cout << "              Silahkan Login Terlebih Dahulu!"             << endl;
    cout << "---------------------------------------------------------" << endl;
    while (true) {
        cout << "Username : "; cin >>  usernameInput; 
        cout << "Password : "; cin >> passwordInput;

        if (usernameInput == username & passwordInput == password) {
            cout << "---------------------------------------------------------" << endl;
            cout << "                      LOGIN BERHASIL!"                     << endl;
            cout << "---------------------------------------------------------" << endl;
            cout << "=========================================================" << endl;
            berhasilLogin = true;
            break;
        }
        else {
            cout << "---------------------------------------------------------" << endl;
            cout << "                      LOGIN GAGAL!"                     << endl;
            cout << "---------------------------------------------------------" << endl;

            kesempatanLogin--;
        }

        if (kesempatanLogin == 0) {            
            break;
        }

        cout << "Silahkan Coba Lagi!" << endl;
        cout << "Kesempatan Login : " << kesempatanLogin << endl;
        cout << "---------------------------------------------------------" << endl;
    }

    if (berhasilLogin) {
        while (true) {
            int pilihan;
            bool keluar = false;

            cout << "               ---- MENU KONVERSI WAKTU ----"              << endl;
            cout << "=========================================================" << endl;

            cout << "[1] Konversi Jam   -> Menit dan Detik" << endl; 
            cout << "[2] Konversi Menit -> Jam dan Detik" << endl; 
            cout << "[3] Konversi Detik -> Jam dan Menit" << endl;
            cout << "---------------------------------------------------------" << endl;
            cout << "[0] Keluar" << endl;
            cout << "---------------------------------------------------------" << endl;
            cout << "Masukkan Pilihan Anda : "; cin >> pilihan;
            cout << "---------------------------------------------------------" << endl;
            
            if (cin.fail()) {
                cin.clear();
                while (cin.peek() != '\n') {
                    cin.ignore();
                }
                pilihan = -1;
            } 
            else {
                cin.clear();
                while (cin.peek() != '\n') {
                    cin.ignore();
                }
            }

            switch (pilihan) {
                case 0:
                    keluar = true; 
                    break;
                
                case 1:
                    cout << "=========================================================" << endl;
                    cout << "         ---- Konversi Jam -> Menit dan Detik ----"        << endl;
                    cout << "=========================================================" << endl;
                    cout << "Masukkan Nilai Jam : "; cin >> nilai;
                    
                    if (cin.fail()) {
                        cin.clear();
                        while (cin.peek() != '\n') {
                            cin.ignore();
                        }
                        nilai = -1;
                    } 

                    else {
                        cin.clear();
                        while (cin.peek() != '\n') {
                            cin.ignore();
                        }
                    }
                    
                    if (nilai >= 0) {
                        konversiMenit = nilai * 60; konversiDetik = nilai * 3600; 
                        
                        cout << "=========================================================" << endl;
                        cout << "                 ---- Hasil Konversi ----"                 << endl;
                        cout << "=========================================================" << endl; 
                        cout << nilai << " Jam setara dengan:" << endl;
                        cout << "-> " << konversiMenit << " Menit" << endl;
                        cout << "-> " <<konversiDetik << " Detik" << endl;
                        cout << "=========================================================" << endl;
                    }
                    else {
                        cout << "Pilihan Tidak Valid!" << endl;
                        cout << "---------------------------------------------------------" << endl;
                        cout << "=========================================================" << endl;
                    }

                    break;
                
                case 2:
                    cout << "=========================================================" << endl; 
                    cout << "         ---- Konversi Menit -> Jam dan Detik ----"        << endl;
                    cout << "=========================================================" << endl;
                    cout << "Masukkan Nilai Menit : "; cin >> nilai; 

                    if (cin.fail()) {
                        cin.clear();
                        while (cin.peek() != '\n') {
                            cin.ignore();
                        }
                        nilai = -1;
                    } 

                    else {
                        cin.clear();
                        while (cin.peek() != '\n') {
                            cin.ignore();
                        }
                    }

                    if (nilai >= 0) {
                        konversiJam = nilai / 60; konversiDetik = nilai * 60; 
                        
                        cout << "=========================================================" << endl;
                        cout << "                 ---- Hasil Konversi ----"                 << endl;
                        cout << "=========================================================" << endl; 
                        cout << nilai << " Menit setara dengan:" << endl;
                        cout << "-> " << konversiJam << " Jam" << endl;
                        cout << "-> " << konversiDetik << " Detik" << endl;
                        cout << "=========================================================" << endl;
                    }
                    else {
                        cout << "Pilihan Tidak Valid!" << endl;
                        cout << "---------------------------------------------------------" << endl;
                        cout << "=========================================================" << endl;
                    } 

                    break; 
                
                case 3: 
                    cout << "=========================================================" << endl;
                    cout << "         ---- Konversi Detik -> Jam dan Menit ----"        << endl;
                    cout << "=========================================================" << endl;
                    cout << "Masukkan Nilai Detik : "; cin >> nilai; 
                    
                    if (cin.fail()) {
                        cin.clear();
                        while (cin.peek() != '\n') {
                            cin.ignore();
                        }
                        nilai = -1;
                    } 

                    else {
                        cin.clear();
                        while (cin.peek() != '\n') {
                            cin.ignore();
                        }
                    }
                    
                    if (nilai >= 0) {
                        konversiJam = nilai / 3600; konversiMenit = nilai / 60; 
                        
                        cout << "=========================================================" << endl;
                        cout << "                 ---- Hasil Konversi ----"                 << endl;
                        cout << "=========================================================" << endl; 

                        cout << nilai << " Detik setara dengan:" << endl;
                        cout << "-> " << konversiJam << " Jam" << endl;
                        cout << "-> " << konversiMenit << " Menit" << endl;
                        cout << "=========================================================" << endl;
                    }
                    else {
                        cout << "Pilihan Tidak Valid!" << endl;
                        cout << "---------------------------------------------------------" << endl;
                        cout << "=========================================================" << endl;
                    } 

                    break;
                
                default:
                    cout << "Pilihan Tidak Valid!" << endl;
                    cout << "---------------------------------------------------------" << endl;
                    cout << "=========================================================" << endl;
            }

            if (keluar) {
                cout << "                 KELUAR DARI KALKULATOR"                 << endl;
                cout << "        Terimakasih Sudah Menggunakan Program ini"       << endl;
                cout << "---------------------------------------------------------" << endl;

                cout << " ";
                break;
            }
        }
    } 
    else {
        cout << "                  Kesempatan Login Habis!"                 << endl;
        cout << "                  Silahkan Ulang Program"                  << endl;
        cout << "---------------------------------------------------------" << endl;
        
    }

    return 0; 
}