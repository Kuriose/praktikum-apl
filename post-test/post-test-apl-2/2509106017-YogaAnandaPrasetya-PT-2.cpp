#include <iostream> 
#include <tabulate/table.hpp>
#include <string>
using namespace std;
using namespace tabulate;

struct KebunRaya {
    int entriID; 
    string namaUmum; 
    string namaLatin; 
    string skalaKonservasi; 
    string habitatAsli;
    string tahunMasuk;  
    int jumlah;
    bool klasifikasi; // 0 -> Flora || 1 -> Fauna
};

struct Pengguna {
    int userID; 
    string username; 
    string password; 
    bool isAdmin;
};

string usernameAuth, passwordAuth, regisUsername, regisPassword;
string inputNamaUmum, inputNamaLatin, inputHabitat, inputTahunMasuk;
int inputJumlah;
bool kembali;
bool entriValid;

// DEKLARASI STRUCT
const int MAXPENGGUNA = 100;
const int MAXENTRI = 100; 
KebunRaya DataKebunRaya[MAXENTRI]; 
Pengguna akun[MAXPENGGUNA];

const string GARIS_BESAR = "===============================================================";
const string GARIS_SEDANG = "---------------------------------------------------------------";
const string GARIS_KECIL = "-------------------------------";

int main () { 
    int totalPengguna = 1;
    int totalEntri = 1; 
    int indeksEntri;
    int indeksUserSekarang; 

    // CONTOH AKUN
    akun[0].userID = 1; 
    akun[0].username = "Yoga"; 
    akun[0].password = "017"; 
    akun[0].isAdmin = true;

    // CONTOH ENTRI
    DataKebunRaya[0].entriID = 1;
    DataKebunRaya[0].namaUmum = "Padi"; 
    DataKebunRaya[0].namaLatin = "Oryza sativa"; 
    DataKebunRaya[0].skalaKonservasi = "Aman"; 
    DataKebunRaya[0].habitatAsli = "Indonesia"; 
    DataKebunRaya[0].tahunMasuk = "2000"; 
    DataKebunRaya[0].jumlah = 100000; 
    DataKebunRaya[0].klasifikasi = false;
    
    int pilihan;
    bool programJalan = true;
    bool adminToUser;

    while (programJalan) {
        int kesempatanLogin = 3; 
        bool berhasilLogin = false;
        bool pergiRegister = false;

        // ---- MENU AWAL ---- 
        cout << "\n" << GARIS_BESAR << endl;
        cout << "               SISTEM MANAJEMEN KEBUN RAYA" << endl;
        cout << GARIS_BESAR << endl;
        cout << "[1] Login" << endl; 
        cout << "[2] Register" << endl; 
        cout << GARIS_SEDANG << endl;
        cout << "[0] Keluar" << endl;
        cout << GARIS_BESAR << endl;
        cout << "Pilihan Anda : "; cin >> pilihan;



        // --- MENU UTAMA ----
        if (pilihan == 0) {
            break;
        } else if (pilihan == 1) { // MENU LOGIN
            cin.ignore();
            while (true) {
                cout << "\n" << GARIS_BESAR << endl << "MENU LOGIN" << endl << GARIS_BESAR << endl;
                cout << "Username : "; getline(cin, usernameAuth);
                cout << "Password : "; getline(cin, passwordAuth);

                for (int i = 0; i < totalPengguna; i++) { // DETEKSI AKUN
                    if (akun[i].username == usernameAuth & akun[i].password == passwordAuth) {
                        berhasilLogin = true;
                        indeksUserSekarang = i;
                        break; 
                    }
                }

                if (berhasilLogin) {
                    cout << GARIS_SEDANG << endl << "Login berhasil. Selamat datang!" << endl; 
                    break;
                } else {
                    kesempatanLogin--;
                    if (kesempatanLogin > 0) { 
                        cout << GARIS_SEDANG << endl << "Login gagal. Silakan coba lagi." << endl;
                        cout << "Sisa kesempatan : " << kesempatanLogin << endl;
                    } else {
                        cout << GARIS_SEDANG << endl << "Kesempatan login habis!" << endl; 
                        cout << "Silakan mulai ulang program!" << endl;
                        cout << endl;
                        exit(1);
                        break;
                    } 
                }
            }
        } else if (pilihan == 2) { // MENU REGISTER
            cin.ignore();
            while(true) {
                bool usernameValid = false;
                
                while (!usernameValid) {
                    cout << "\n" << GARIS_BESAR << endl << "MENU REGISTER" << endl << GARIS_BESAR << endl;        
                    cout << "Username baru : "; 
                    getline(cin, regisUsername);
                    
                    usernameValid = true;
                    for (int i = 0; i < totalPengguna; i++) {
                        if (regisUsername == akun[i].username) {
                            cout << "Username sudah dipakai. Silakan gunakan username lain." << endl;
                            usernameValid = false; 
                        }
                    }
                }
                
                cout << "Password baru : "; 
                getline(cin, regisPassword);

                cout << GARIS_SEDANG << endl << "Akun berhasil dibuat untuk username: " << regisUsername << endl;

                akun[totalPengguna].userID = totalPengguna + 1;
                akun[totalPengguna].username = regisUsername; 
                akun[totalPengguna].password = regisPassword; 
                akun[totalPengguna].isAdmin = false;
                totalPengguna++;
                break;
            }
        } else {
            cout << "Pilihan tidak valid!";
        }

        // --- MENU UTAMA ---
        while (berhasilLogin) {
            if (akun[indeksUserSekarang].isAdmin == true) {   // MENU ADMIN 
                adminToUser = false;
                while (true) {
                    cout << "\n" << GARIS_BESAR << endl << "MENU AKSES ADMIN" << endl << GARIS_BESAR << endl; 
                    cout << "[1] Menu Manajemen" << endl; 
                    cout << "[2] Menu Admin" << endl; 
                    cout << GARIS_SEDANG << endl;
                    cout << "[0] Logout" << endl;
                    cout << GARIS_SEDANG << endl;
                    cout << "Pilih menu : "; cin >> pilihan;

                    if (pilihan == 0) {
                        berhasilLogin = false;
                        break;
                    } else if (pilihan == 1) {
                        adminToUser = true; 
                        break;
                    } else if (pilihan == 2) {
                        while (true) {
                            cout << "\n" << GARIS_BESAR << endl << "MENU ADMIN" << endl << GARIS_BESAR << endl;
                            cout << "[1] Tambah User" << endl; 
                            cout << "[2] Lihat User" << endl;
                            cout << "[3] Update User" << endl; 
                            cout << "[4] Hapus User" << endl; 
                            cout << GARIS_KECIL << endl; 
                            cout << "[0] Keluar" << endl;
                            cout << "-----------------------------" << endl;
                            cout << "Masukkan Pilihan Anda" << endl; 
                            cout << "> "; cin >> pilihan;
                            
                            if (pilihan == 0) {
                                break; 
                            } else if (pilihan == 1) { // CREATE user
                                cin.ignore();
                                while (true) {
                                    cout << "--- Menambahkan User Baru ---" << endl; 
                                    cout << "Username baru : "; getline(cin, regisUsername); 
                                    
                                    if (regisUsername.empty()) {
                                        cout << "Username Tidak Boleh Kosong!" << endl; 
                                        continue; 
                                    } 

                                    cout << "Password baru : "; getline(cin, regisPassword); 

                                    if (regisPassword.empty()) {
                                        cout << "Password Tidak Boleh Kosong!" << endl; 
                                        continue; 
                                    }

                                    akun[totalPengguna].userID = totalPengguna + 1;
                                    akun[totalPengguna].username = regisUsername; 
                                    akun[totalPengguna].password = regisPassword; 
                                    akun[totalPengguna].isAdmin = false;
                                    totalPengguna++;
                                    break;
                                }
                                
                            } else if (pilihan == 2) { // READ User
                                cout << "\n" << GARIS_BESAR << endl;
                                cout << "DAFTAR USER" << endl;
                                cout << GARIS_BESAR << endl;
                                Table userTable;
                                userTable.add_row({"ID", "Username", "Password", "Role"});
                                for (int i = 0; i < totalPengguna; i++) {
                                    string roleAkun = (akun[i].isAdmin == true) ? "Admin" : "User";
                                    userTable.add_row({
                                        to_string(akun[i].userID),
                                        akun[i].username,
                                        akun[i].password,
                                        roleAkun
                                    });
                                }
                                cout << userTable << endl;
                            } else if (pilihan == 3) { // UPDATE User
                                while (true) {
                                    Table updateTable;
                                    string roleAkun;
                                    cout << "\n" << GARIS_BESAR << endl << "UPDATE USER" << endl << GARIS_BESAR << endl;
                                    updateTable.add_row({"ID", "Username", "Role"}); 
                                    for (int i = 0; i < totalPengguna; i++) {
                                        roleAkun = (akun[i].isAdmin == false) ? "Member" : "Admin";
                                        updateTable.add_row({
                                            to_string(akun[i].userID),
                                            akun[i].username, 
                                            roleAkun
                                        });
                                    }

                                    cout << updateTable << endl; 
                                    cout << GARIS_BESAR << endl; 
                                    cout << "[0] Keluar" << endl; 
                                    cout << GARIS_BESAR << endl;
                                    cout << "Masukkan Pilihan Anda" << endl; 
                                    cout << "> "; cin >> pilihan;

                                    if (pilihan == 0) {
                                        break;
                                    }

                                    entriValid = false; 
                                    int indeksUserSekarang; 

                                    for (int i = 0; i < totalPengguna; i++) {
                                        if (pilihan == akun[i].userID) {
                                            indeksUserSekarang = i; 
                                            entriValid = true; 
                                            break;
                                        }
                                    }

                                    if (entriValid) {
                                        while (true) {
                                            cout << "--- MENU UPDATE ---" << endl;
                                            cout << "[1] Ubah Username" << endl; 
                                            cout << "[2] Ubah Password" << endl; 
                                            cout << "[3] Ubah Role" << endl; 
                                            cout << "----------------------------------" << endl; 
                                            cout << "[0] Keluar" << endl;
                                            cout << "----------------------------------" << endl;
                                            cout << "Masukkan Pilihan Anda" << endl; 
                                            cout << "> "; cin >> pilihan; 

                                            if (pilihan == 0) {
                                                break; 
                                            } else if (pilihan == 1) { // Ganti username
                                                cin.ignore();
                                                string gantiUsername;
                                                while (true) {
                                                    cout << "--- MENGGANTI USERNAME ---" << endl;
                                                    cout << "Isi dengan '0' jika ingin kembali" << endl;
                                                    cout << "Username Lama: " << akun[indeksUserSekarang].username << endl;
                                                    cout << "Username Baru: "; getline(cin, gantiUsername);

                                                    if (gantiUsername.empty()) {
                                                        cout << "Username Baru Tidak Boleh Kosong!" << endl; 
                                                        continue; 
                                                    } else if (gantiUsername == "0") {
                                                        break;
                                                    }

                                                    akun[indeksUserSekarang].username = gantiUsername; 
                                                    break;
                                                }
                                                 
                                            } else if (pilihan == 2) { // Ganti password
                                                cin.ignore(); 
                                                string gantiPassword;
                                                while (true) {
                                                    cout << "--- MENGGANTI PASSWORD ---" << endl;
                                                    cout << "Isi dengan '0' jika ingin kembali" << endl;
                                                    cout << "Password Lama: " << akun[indeksUserSekarang].password << endl; 
                                                    cout << "Password Baru: "; getline(cin, gantiPassword);
                                                    
                                                    if (gantiPassword.empty()) {
                                                        cout << "Password Baru Tidak Boleh Kosong!" << endl; 
                                                        continue;
                                                    } else if (gantiPassword == "0") {
                                                        break;
                                                    }

                                                    akun[indeksUserSekarang].password = gantiPassword; 
                                                    break;
                                                }    
                                            } else if (pilihan == 3) { // Ganti role
                                                cin.ignore();
                                                while (true) {
                                                    cout << "--- MENGGANTI ROLE ---" << endl;
                                                    cout << "[1] Admin" << endl;
                                                    cout << "[2] User" << endl; 
                                                    cout << "--------------------------------" << endl; 
                                                    cout << "[0] Kembali" << endl; 
                                                    cout << "--------------------------------" << endl;
                                                    cout << "Masukkan Pilihan Anda" << endl;
                                                    cout << "> "; cin >> pilihan;
                                                    
                                                    if (pilihan == 0) {
                                                        break;
                                                    } else if (pilihan == 1) {
                                                        akun[indeksUserSekarang].isAdmin = true;
                                                        break;
                                                    } else if (pilihan == 2) {
                                                        akun[indeksUserSekarang].isAdmin = false;
                                                        break;
                                                    } else {
                                                        cout << "Pilihan tidak valid!" << endl;
                                                    }
                                                }
                                                
                                            }


                                        }
                                    }
                                    
                                    break;
                                }
                            } else if (pilihan == 4) { // DELETE User
                                while (true) {
                                    Table deleteTable; 
                                    string roleAkun;
                                    cout << "\n" << GARIS_BESAR << endl << "HAPUS USER" << endl << GARIS_BESAR << endl;
                                    deleteTable.add_row({"ID", "Username", "Role"}); 
                                    for (int i = 0; i < totalPengguna; i++) {
                                        roleAkun = (akun[i].isAdmin == false) ? "Member" : "Admin"; 
                                        deleteTable.add_row({
                                            to_string(akun[i].userID), 
                                            akun[i].username, 
                                            roleAkun
                                        });
                                    }

                                    cout << deleteTable << endl; 
                                    cout << GARIS_BESAR << endl; 
                                    cout << "[0] Keluar" << endl; 
                                    cout << GARIS_BESAR << endl;
                                    cout << "Masukkan Pilihan Anda" << endl; 
                                    cout << "> "; cin >> pilihan; 

                                    if (pilihan == 0) {
                                        break; 
                                    } 

                                    entriValid = false; 
                                    int indeksUserSekarang;

                                    for (int i = 0; i < totalPengguna; i++) {
                                        if (pilihan == akun[i].userID) {
                                            indeksUserSekarang = i;
                                            entriValid = true; 
                                            break;
                                        }
                                    }


                                    if (entriValid) {
                                        while (true) {
                                            string roleAkun;
                                            roleAkun = (akun[indeksUserSekarang].isAdmin == true) ? "Admin" : "Member";
                                            cout << "\n" << GARIS_SEDANG << endl << "AKUN YANG AKAN DIHAPUS" << endl; 
                                            cout << "ID Akun: " << akun[indeksUserSekarang].userID << endl;
                                            cout << "Username: " << akun[indeksUserSekarang].username << endl; 
                                            cout << "Role: " << roleAkun << endl;
                                            cout << "-----------------------------------------------------------" << endl; 
                                            cout << "[1] Hapus" << endl; 
                                            cout << "-----------------------------------------------------------" << endl;
                                            cout << "[0] Kembali" << endl;
                                            cout << "-----------------------------------------------------------" << endl;
                                            cout << "Masukkan Pilihan Anda" << endl; 
                                            cout << "> "; cin >> pilihan; 

                                            if (pilihan == 0) {
                                                break; 
                                            } else if (pilihan == 1) {
                                                cout << GARIS_SEDANG << endl << "KONFIRMASI HAPUS" << endl; 
                                                for (int i = indeksUserSekarang; i < totalPengguna; i++) {
                                                    akun[i] = akun[i + 1]; 
                                                    akun[i].userID = i + 1; 
                                                } totalPengguna--;
                                                
                                                break;
                                            }

                                        }
                                    }

                                }

                            }
                        }
                    } else {
                        cout << "Pilihan tidak valid!" << endl;
                    }
                }
            } 
            
            if (akun[indeksUserSekarang].isAdmin == false | adminToUser == true) { // MENU USER & ADMIN
                while (true) {
                    cout << "\n" << GARIS_BESAR << endl << "MENU MANAJEMEN KEBUN RAYA" << endl << GARIS_BESAR << endl;
                    if (adminToUser) {
                        cout << "Selamat Datang Kembali Admin " << akun[indeksUserSekarang].username << endl;    
                    } else {
                        cout << "Selamat Datang Kembali " << akun[indeksUserSekarang].username << endl;
                    }                    
                    cout << GARIS_BESAR << endl;
                    cout << "[1] Tambah Entri Baru" << endl;
                    cout << "[2] Lihat Entri" << endl; 
                    cout << "[3] Update Entri" << endl;
                    cout << "[4] Hapus Entri" << endl; 
                    cout << GARIS_BESAR << endl;
                    if (adminToUser) {
                        cout << "[0] Kembali" << endl;
                    } else {
                        cout << "[0] Logout" << endl;
                    }
                    cout << GARIS_BESAR << endl;
                    cout << "Pilih menu : "; cin >> pilihan;

                    if (pilihan == 0) { // MENU KELUAR
                        cout << GARIS_SEDANG << endl << "Kembali ke menu login." << endl;
                        if (!adminToUser) {
                            berhasilLogin = false;
                        }
                        break;
                    } else if (pilihan == 1) { // MENU CREATE
                        cin.ignore();
                        while (true) {
                            kembali = false;
                            cout << "\n" << GARIS_BESAR << endl << "TAMBAH ENTRI BARU" << endl << GARIS_BESAR << endl;
                            cout << "[1] Flora" << endl;
                            cout << "[2] Fauna" << endl;
                            cout << GARIS_BESAR << endl;
                            cout << "[0] Kembali" << endl;
                            cout << GARIS_BESAR << endl;
                            cout << "Masukkan Pilihan Anda" << endl; 
                            cout << "> "; cin >> pilihan; 

                            cout << "Pilihan terpilih : " << pilihan << endl;
                            
                            if (pilihan == 0) {
                                break;
                            } else if (pilihan == 1) { // CREATE -- FLORA
                                cin.ignore();
                                while (true) {
                                    cout << "\n" << GARIS_SEDANG << endl << "PILIH SKALA KONSERVASI" << endl << GARIS_SEDANG << endl;
                                    cout << "[1] Risiko Rendah (LC)" << endl; 
                                    cout << "[2] Hampir Terancam (NT)" << endl;
                                    cout << "[3] Rentan (VU)" << endl;
                                    cout << "[4] Terancam (EN)" << endl;
                                    cout << "[5] Sangat Terancam (CR)" << endl; 
                                    cout << "[6] Punah di Alam Liar (EW)" << endl;
                                    cout << GARIS_BESAR << endl;
                                    cout << "[0] Kembali" << endl; 
                                    cout << GARIS_BESAR << endl;
                                    cout << "Masukkan Pilihan Anda" << endl; 
                                    cout << "> "; cin >> pilihan;
                                    
                                    if (pilihan == 0) {
                                        kembali = true;
                                        break;
                                    } else if (pilihan == 1) { 
                                        DataKebunRaya[totalEntri].skalaKonservasi = "LC - Resiko Rendah";
                                        break; 
                                    } else if (pilihan == 2) {
                                        DataKebunRaya[totalEntri].skalaKonservasi = "NT - Hampir Terancam";
                                        break;
                                    } else if (pilihan == 3) {
                                        DataKebunRaya[totalEntri].skalaKonservasi = "VU - Rentan";
                                        break;
                                    } else if (pilihan == 4) {
                                        DataKebunRaya[totalEntri].skalaKonservasi = "EN - Terancam";
                                        break;
                                    } else if (pilihan == 5) {
                                        DataKebunRaya[totalEntri].skalaKonservasi = "CR - Sangat Terancam";
                                        break;
                                    } else if (pilihan == 6) {
                                        DataKebunRaya[totalEntri].skalaKonservasi = "EW - Punah di Alam";
                                        break;
                                    }   
                                    else {
                                        cout << "Pilihan Tidak Valid!";
                                    }
                                }
                                
                                if (!kembali) {
                                    cin.ignore();
                                    DataKebunRaya[totalEntri].klasifikasi = false; 
                                    cout << "Masukkan Nama Umum: "; getline(cin, inputNamaUmum);
                                    cout << "Masukkan Nama Latin: "; getline(cin, inputNamaLatin); 
                                    cout << "Masukkan Habitat Asli: "; getline(cin, inputHabitat);
                                    cout << "Masukkan Tahun Masuk Kebun Raya: "; getline(cin, inputTahunMasuk);
                                    cout << "Masukkan Jumlah Specimen: "; cin >> inputJumlah;
                                    
                                    DataKebunRaya[totalEntri].entriID = totalEntri + 1;
                                    DataKebunRaya[totalEntri].namaUmum = inputNamaUmum; 
                                    DataKebunRaya[totalEntri].namaLatin = inputNamaLatin; 
                                    DataKebunRaya[totalEntri].habitatAsli = inputHabitat; 
                                    DataKebunRaya[totalEntri].tahunMasuk = inputTahunMasuk; 
                                    DataKebunRaya[totalEntri].jumlah = inputJumlah;  
                                    
                                    totalEntri++;
                                }
                                
                                break;
                            } else if (pilihan == 2) { // CREATE -- FAUNA
                                cin.ignore();
                                while (true) {
                                    cout << "\n" << GARIS_SEDANG << endl << "PILIH SKALA KONSERVASI" << endl << GARIS_SEDANG << endl;
                                    cout << "[1] Risiko Rendah (LC)" << endl; 
                                    cout << "[2] Hampir Terancam (NT)" << endl;
                                    cout << "[3] Rentan (VU)" << endl;
                                    cout << "[4] Terancam (EN)" << endl;
                                    cout << "[5] Sangat Terancam (CR)" << endl; 
                                    cout << "[6] Punah di Alam Liar (EW)" << endl;
                                    cout << GARIS_BESAR << endl;
                                    cout << "[0] Kembali" << endl; 
                                    cout << GARIS_BESAR << endl;
                                    cout << "Masukkan Pilihan Anda" << endl; 
                                    cout << "> "; cin >> pilihan;
                                    
                                    if (pilihan == 0) {
                                        kembali = true;
                                        break;
                                    } else if (pilihan == 1) { 
                                        DataKebunRaya[totalEntri].skalaKonservasi = "LC - Resiko Rendah";
                                        break; 
                                    } else if (pilihan == 2) {
                                        DataKebunRaya[totalEntri].skalaKonservasi = "NT - Hampir Terancam";
                                        break;
                                    } else if (pilihan == 3) {
                                        DataKebunRaya[totalEntri].skalaKonservasi = "VU - Rentan";
                                        break;
                                    } else if (pilihan == 4) {
                                        DataKebunRaya[totalEntri].skalaKonservasi = "EN - Terancam";
                                        break;
                                    } else if (pilihan == 5) {
                                        DataKebunRaya[totalEntri].skalaKonservasi = "CR - Sangat Terancam";
                                        break;
                                    } else if (pilihan == 6) {
                                        DataKebunRaya[totalEntri].skalaKonservasi = "EW - Punah di Alam";
                                        break;
                                    }   
                                    else {
                                        cout << "Pilihan Tidak Valid!";
                                    }
                                }
                                
                                if (!kembali) {
                                    cin.ignore();
                                    DataKebunRaya[totalEntri].klasifikasi = true; 
                                    cout << "Masukkan Nama Umum: "; getline(cin, inputNamaUmum);
                                    cout << "Masukkan Nama Latin: "; getline(cin, inputNamaLatin); 
                                    cout << "Masukkan Habitat Asli: "; getline(cin, inputHabitat);
                                    cout << "Masukkan Tahun Masuk Kebun Raya: "; getline(cin, inputTahunMasuk);
                                    cout << "Masukkan Jumlah Specimen: "; cin >> inputJumlah;
                                    
                                    DataKebunRaya[totalEntri].entriID = totalEntri + 1;
                                    DataKebunRaya[totalEntri].namaUmum = inputNamaUmum; 
                                    DataKebunRaya[totalEntri].namaLatin = inputNamaLatin; 
                                    DataKebunRaya[totalEntri].habitatAsli = inputHabitat; 
                                    DataKebunRaya[totalEntri].tahunMasuk = inputTahunMasuk; 
                                    DataKebunRaya[totalEntri].jumlah = inputJumlah;  
                                    
                                    totalEntri++;
                                }
                                break;
                            }
                        
                        }  
                    } else if (pilihan == 2) { // MENU CREATE
                        string tipeEntri; 
                        cout << "\n" << GARIS_BESAR << endl;
                        cout << "DAFTAR ENTRI KEBUN RAYA" << endl;
                        cout << GARIS_BESAR << endl;
                        Table entriTable;
                        entriTable.add_row({"ID", "Nama Umum", "Nama Latin", "Jenis", "Skala", "Habitat", "Tahun", "Jumlah"});
                        for (int i = 0; i < totalEntri; i++) {
                            tipeEntri = (DataKebunRaya[i].klasifikasi == false) ? "Flora" : "Fauna";
                            entriTable.add_row({
                                to_string(DataKebunRaya[i].entriID),
                                DataKebunRaya[i].namaUmum,
                                DataKebunRaya[i].namaLatin,
                                tipeEntri,
                                DataKebunRaya[i].skalaKonservasi,
                                DataKebunRaya[i].habitatAsli,
                                DataKebunRaya[i].tahunMasuk,
                                to_string(DataKebunRaya[i].jumlah)
                            });
                        }
                        cout << entriTable << endl;

                    } else if (pilihan == 3) { // MENU UPDATE
                        bool selesaiUpdate = false;
                        while (!selesaiUpdate) {
                            cout << "\n" << GARIS_BESAR << endl << "UPDATE ENTRI" << endl << GARIS_BESAR << endl;
                            Table updateTable;
                            updateTable.add_row({"ID", "Nama Umum", "Jenis"});
                            for (int i = 0; i < totalEntri; i++) {
                                string tipeEntri;
                                tipeEntri = (DataKebunRaya[i].klasifikasi == false) ? "Flora" : "Fauna";
                                updateTable.add_row({
                                    to_string(DataKebunRaya[i].entriID),
                                    DataKebunRaya[i].namaUmum, 
                                    tipeEntri
                                });
                            }

                            cout << updateTable << endl;
                            cout << GARIS_BESAR << endl; 
                            cout << "[0] Keluar" << endl; 
                            cout << GARIS_BESAR << endl;
                            cout << "Masukkan Pilihan Anda" << endl; 
                            cout << "> "; cin >> pilihan;

                            if (pilihan == 0) {
                                break; 
                            } 

                            entriValid = false;
                            int indeksEntriSekarang;

                            for (int i = 0; i < totalEntri; i++) {
                                if (pilihan == DataKebunRaya[i].entriID) {
                                    indeksEntriSekarang = i;
                                    entriValid = true; 
                                    break;            
                                }
                            }

                            if (entriValid) {
                                while (true) {
                                    cout << "---- MENU UPDATE ---------------------------------------------" << endl;
                                    cout << "[1] Nama Umum" << endl; 
                                    cout << "[2] Nama Latin" << endl; 
                                    cout << "[3] Tipe" << endl; 
                                    cout << "[4] Skala Konservasi" << endl; 
                                    cout << "[5] Habitat Asli" << endl; 
                                    cout << "[6] Tahun Masuk" << endl; 
                                    cout << "[7] Jumlah" << endl;
                                    cout << "--------------------------------------------------" << endl;
                                    cout << "[0] Keluar" << endl; 
                                    cout << "--------------------------------------------------" << endl;
                                    cout << "Masukkan Pilihan Anda" << endl; 
                                    cout << "> "; cin >> pilihan; 

                                    if (pilihan == 0) {
                                        break;
                                    } else if (pilihan == 1) {
                                        cin.ignore();
                                        while (true) {
                                            cout << "---- NAMA UMUM ----" << endl;
                                            cout << "Kosongkan Untuk Kembali ke menu sebelumnya" << endl; 
                                            cout << "Nama Lama: " << DataKebunRaya[indeksEntriSekarang].namaUmum << endl; 
                                            cout << "Nama Baru: "; getline(cin, inputNamaUmum);

                                            if (inputNamaUmum.empty()) {
                                                break;
                                            }
                                            
                                            DataKebunRaya[indeksEntriSekarang].namaUmum = inputNamaUmum;
                                            break;
                                        }
                                        
                                    } else if (pilihan == 2) {
                                        cin.ignore();
                                        while (true) {
                                            cout << "--- NAMA LATIN -----------"; 
                                            cout << "Kosongkan jika ingin kembali ke menu sebelumnya" << endl;
                                            cout << "Nama Lama: " << DataKebunRaya[indeksEntriSekarang].namaLatin << endl; 
                                            cout << "Nama Baru: "; getline(cin, inputNamaLatin); 

                                            if (inputNamaLatin.empty()) {
                                                break;
                                            }

                                            DataKebunRaya[indeksEntriSekarang].namaLatin = inputNamaLatin;
                                            break;    
                                        }
                                        
                                    } else if (pilihan == 3) {
                                        cin.ignore();
                                        int pilihanTipe; 
                                        while (true) {
                                            cout << "--- TIPE ----" << endl; 
                                            cout << "[1] Flora" << endl;
                                            cout << "[2] Fauna" << endl; 
                                            cout << "--------------------" << endl; 
                                            cout << "[0] Kembali" << endl;
                                            cout << "--------------------" << endl;
                                            cout << "Masukkan Pilihan Anda" << endl; 
                                            cout << "> "; cin >> pilihanTipe;

                                            if (pilihanTipe == 0) {
                                                break; // Kembali ke menu sebelumnya
                                            } else if (pilihanTipe == 1) {
                                                DataKebunRaya[indeksEntriSekarang].klasifikasi = false;
                                                break; 
                                            } else if (pilihanTipe == 2) {
                                                DataKebunRaya[indeksEntriSekarang].klasifikasi = true;
                                                break;
                                            } else {
                                                cout << "Pilihan Tidak Valid" << endl;
                                            }
                                        }
                                            
                                    } else if (pilihan == 4) {
                                        cin.ignore(); 
                                        while (true) {
                                            cout << "\n" << GARIS_SEDANG << endl << "PILIH SKALA KONSERVASI" << endl << GARIS_SEDANG << endl;
                                            cout << "[1] Risiko Rendah (LC)" << endl; 
                                            cout << "[2] Hampir Terancam (NT)" << endl;
                                            cout << "[3] Rentan (VU)" << endl;
                                            cout << "[4] Terancam (EN)" << endl;
                                            cout << "[5] Sangat Terancam (CR)" << endl; 
                                            cout << "[6] Punah di Alam Liar (EW)" << endl;
                                            cout << "[7] Punah (EX)" << endl;
                                            cout << GARIS_BESAR << endl;
                                            cout << "[0] Kembali" << endl; 
                                            cout << GARIS_BESAR << endl;
                                            cout << "Skala Konservasi Sekarang: " << DataKebunRaya[totalEntri].skalaKonservasi << endl;
                                            cout << "Masukkan Pilihan Anda" << endl; 
                                            cout << "> "; cin >> pilihan;
                                            
                                            if (pilihan == 0) {
                                                kembali = true;
                                                break;
                                            } else if (pilihan == 1) { 
                                                DataKebunRaya[indeksEntriSekarang].skalaKonservasi = "LC - Resiko Rendah";
                                                break; 
                                            } else if (pilihan == 2) {
                                                DataKebunRaya[indeksEntriSekarang].skalaKonservasi = "NT - Hampir Terancam";
                                                break;
                                            } else if (pilihan == 3) {
                                                DataKebunRaya[indeksEntriSekarang].skalaKonservasi = "VU - Rentan";
                                                break;
                                            } else if (pilihan == 4) {
                                                DataKebunRaya[indeksEntriSekarang].skalaKonservasi = "EN - Terancam";
                                                break;
                                            } else if (pilihan == 5) {
                                                DataKebunRaya[indeksEntriSekarang].skalaKonservasi = "CR - Sangat Terancam";
                                                break;
                                            } else if (pilihan == 6) {
                                                DataKebunRaya[indeksEntriSekarang].skalaKonservasi = "EW - Punah di Alam";
                                                break;
                                            } else if (pilihan == 7) {
                                                DataKebunRaya[indeksEntriSekarang].skalaKonservasi = "EX - Punah";
                                                DataKebunRaya[indeksEntriSekarang].jumlah = 0;
                                                break;
                                            }
                                            else {
                                                cout << "Pilihan Tidak Valid!";
                                            }
                                        
                                        }
                                    } else if (pilihan == 5) {
                                        cin.ignore();
                                        while (true) {
                                            cout << "---- HABITAT ASLI ----" << endl;
                                            cout << "Kosongkan Untuk Kembali ke menu sebelumnya" << endl; 
                                            cout << "Habitat Sebelumnya: " << DataKebunRaya[indeksEntriSekarang].habitatAsli << endl; 
                                            cout << "Habitat Sekarang: "; getline(cin, inputHabitat);

                                            if (inputHabitat.empty()) {
                                                break;
                                            }
                                            
                                            DataKebunRaya[indeksEntriSekarang].habitatAsli = inputHabitat;
                                            break;
                                        }
                                    } else if (pilihan == 6) {
                                        cin.ignore();
                                        while (true) {
                                            cout << "---- TAHUN MASUK ----" << endl;
                                            cout << "Kosongkan Untuk Kembali ke menu sebelumnya" << endl; 
                                            cout << "Tahun Sebelumnya: " << DataKebunRaya[indeksEntriSekarang].tahunMasuk << endl; 
                                            cout << "Tahun Sekarang: "; getline(cin, inputTahunMasuk);

                                            if (inputTahunMasuk.empty()) {
                                                break;
                                            }
                                            
                                            DataKebunRaya[indeksEntriSekarang].tahunMasuk = inputTahunMasuk;
                                            break;
                                        }
                                    } else if (pilihan == 7) {
                                        while (true) {
                                            cout << "--- JUMLAH ---" << endl; 
                                            cout << "Masukkan 0 untuk kembali ke menu sebelumnya" << endl;
                                            cout << GARIS_BESAR << endl;
                                            cout << "Jumlah Sebelumnya: " << DataKebunRaya[indeksEntriSekarang].jumlah << endl; 
                                            cout << "Jumlah Sekarang: "; cin >> inputJumlah; 

                                            if (inputJumlah < 0) {
                                                cout << "Jumlah harus diatas nol!" << endl; 
                                                continue;
                                            }

                                            DataKebunRaya[indeksEntriSekarang].jumlah = inputJumlah;
                                            break;
                                        }
                                    }
                                }

                                break;
                            }
                        }

                    } else if (pilihan == 4) { // MENU DELETE
                        bool selesaiHapus = false;
                        while (!selesaiHapus) {
                            cout << "\n" << GARIS_BESAR << endl << "HAPUS ENTRI" << endl << GARIS_BESAR << endl;
                            Table deleteTable;
                            deleteTable.add_row({"ID", "Nama Umum", "Jenis"});
                            for (int i = 0; i < totalEntri; i++) {
                                string tipeEntri;
                                tipeEntri = (DataKebunRaya[i].klasifikasi == false) ? "Flora" : "Fauna";
                                deleteTable.add_row({
                                    to_string(DataKebunRaya[i].entriID),
                                    DataKebunRaya[i].namaUmum, 
                                    tipeEntri
                                });
                            }

                            cout << deleteTable << endl;
                            cout << GARIS_BESAR << endl; 
                            cout << "[0] Keluar" << endl; 
                            cout << GARIS_BESAR << endl;
                            cout << "Masukkan Pilihan Anda" << endl; 
                            cout << "> "; cin >> pilihan;

                            if (pilihan == 0) {
                                break; 
                            }

                            entriValid = false; 
                            int indeksEntriSekarang;

                            for (int i = 0; i < totalEntri; i++) {
                                if (pilihan == DataKebunRaya[i].entriID) {
                                    indeksEntriSekarang = i; 
                                    entriValid = true; 
                                    break;
                                }
                            }

                            if (entriValid) {
                                while (true) {
                                    string tipeEntri; 
                                    tipeEntri = (DataKebunRaya[indeksEntriSekarang].klasifikasi == false) ? "Flora" : "Fauna";
                                    cout << "\n" << GARIS_SEDANG << endl << "ENTRI YANG AKAN DIHAPUS" << endl; 
                                    cout << "Nama Umum: " << DataKebunRaya[indeksEntriSekarang].namaUmum << endl; 
                                    cout << "Nama Latin: " << DataKebunRaya[indeksEntriSekarang].namaLatin << endl; 
                                    cout << "Jenis: " << tipeEntri << endl; 
                                    cout << "Skala Konservasi: " << DataKebunRaya[indeksEntriSekarang].skalaKonservasi << endl; 
                                    cout << "Habitat Asli: " << DataKebunRaya[indeksEntriSekarang].habitatAsli << endl; 
                                    cout << "Tahun Masuk: " << DataKebunRaya[indeksEntriSekarang].tahunMasuk << endl; 
                                    cout << "Jumlah: " << DataKebunRaya[indeksEntriSekarang].jumlah << endl;
                                    cout << "-----------------------------------------------------------------" << endl;
                                    
                                    while (true) {
                                        cout << "--- KONFIRMASI HAPUS ---" << endl; 
                                        cout << "[1] Ya" << endl; 
                                        cout << "[2] Tidak" << endl; 
                                        cout << "-----------------------------------------------" << endl;
                                        cout << "Masukkan Pilihan Anda" << endl; 
                                        cout << "> "; cin >> pilihan; 

                                        if (pilihan == 1) {
                                            cout << "---- KONFIRMASI HAPUS ---" << endl;
                                            for (int i = indeksEntriSekarang; i < totalEntri; i++) {
                                                DataKebunRaya[i] = DataKebunRaya[i + 1];
                                                DataKebunRaya[i].entriID = i + 1;
                                            } totalEntri--;
                                            break;
                                        } else if (pilihan == 2) {
                                            break;
                                        } else {
                                            cout << "Pilihan tidak valid!" << endl;
                                        }
                                    }

                                    break;
                                } 
                            }
                        }
                    } else {
                        cout << "Pilihan tidak valid!" << endl; 
                    }
                } 
            }

        }

        cout << GARIS_BESAR << endl;
    } 

    return 0;
}