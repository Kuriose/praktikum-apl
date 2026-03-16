#include <iostream>
using namespace std; 

struct Pengguna {
    int userID; 
    string username; 
    string password; 
    bool isAdmin;
};

const int MAXPENGGUNA = 100; 
Pengguna akun[MAXPENGGUNA]; 
int jumlahPengguna = 2; 

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

const int MAXENTRI = 100; 
KebunRaya entri[MAXENTRI]; 
int jumlahEntri = 1;

// FEAT: Prosedur & Fungsi Pembantu
void tampilkanAkun(Pengguna akun[], int jumlahPengguna) {
    cout << "\n=== DAFTAR AKUN =========================================" << endl;
    for (int i = 0; i < jumlahPengguna; i++) {
        string privilese = (akun[i].isAdmin) ? "Admin" : "Member";
        cout << "Akun ke-" << i + 1 << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << "User ID   : " << akun[i].userID << endl; 
        cout << "Username  : " << akun[i].username << endl; 
        cout << "Password  : " << akun[i].password << endl; 
        cout << "Role      : " << privilese << endl; 
        cout << "---------------------------------------------------------" << endl;
    }
}

void tampilkanEntri(KebunRaya entri[], int jumlahEntri) {
    cout << "\n=== DAFTAR ENTRI ========================================" << endl;
    for (int i = 0; i < jumlahEntri; i++) {
        string tipeEntri = (!entri[i].klasifikasi) ? "Flora" : "Fauna";

        cout << "Entri ke-" << i + 1 << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << "ID Entri          : " << entri[i].entriID << endl;
        cout << "Nama Umum         : " << entri[i].namaUmum << endl; 
        cout << "Nama Latin        : " << entri[i].namaLatin << endl; 
        cout << "Tipe              : " << tipeEntri << endl;
        cout << "Skala Konservasi  : " << entri[i].skalaKonservasi << endl;
        cout << "Habitat Asli      : " << entri[i].habitatAsli << endl;
        cout << "Tahun Masuk       : " << entri[i].tahunMasuk << endl; 
        cout << "Jumlah            : " << entri[i].jumlah << endl;
        cout << "---------------------------------------------------------" << endl;
    }
}

int errorHandling(int pilihan) {
    if (cin.fail()) {
        cin.clear();
        while (cin.peek() != '\n') {
            cin.ignore();
        }
        return pilihan = -1;
    } 
    else {
        cin.clear();
        while (cin.peek() != '\n') {
            cin.ignore();
        }
    }
    return pilihan;
}

void lihatEntri(KebunRaya entri[], int jumlahEntri) {
    string kembali; 
    cout << "\n=== ENTRI YANG ADA DI DATABASE ==========================" << endl; 
    for (int i = 0; i < jumlahEntri; i++) {
        string tipeTanaman = (!entri[i].klasifikasi) ? "Flora" : "Fauna"; 

        cout << "Entri ke-" << i + 1 << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << "ID Entri          : " << entri[i].entriID << endl;
        cout << "Nama Umum         : " << entri[i].namaUmum << endl;
        cout << "Nama Latin        : " << entri[i].namaLatin << endl;
        cout << "Tipe              : " << tipeTanaman << endl; 
        cout << "Skala Konservasi  : " << entri[i].skalaKonservasi << endl;
        cout << "Habitat Asli      : " << entri[i].habitatAsli << endl; 
        cout << "Tahun Masuk       : " << entri[i].tahunMasuk << endl; 
        cout << "Jumlah            : " << entri[i].jumlah << endl;
        cout << "---------------------------------------------------------" << endl;
    } 

    cin.ignore();
    cout << "Tekan Enter untuk kembali" << endl; 
    cout << "> "; getline(cin, kembali);
}

void lihatEntriShort(KebunRaya entri[], int jumlahEntri) { 
    cout << "=== DAFTAR SINGKAT ENTRI ================================" << endl;
    for (int i = 0; i < jumlahEntri; i++) {
        string tipeTanaman = (entri[i].klasifikasi == false) ? "Flora" : "Fauna"; 

        cout << "ID Entri  : " << entri[i].entriID << endl;
        cout << "Nama Umum : " << entri[i].namaUmum << endl;
        cout << "Tipe      : " << tipeTanaman << endl; 
        cout << "---------------------------------------------------------" << endl;
    } 
}

void tambahEntri(KebunRaya entri[], int &jumlahEntri) {
    int pilihan;
    bool lanjut = false;
    
    do {
        lanjut = false;
        
        cout << "\n=== BUAT ENTRI BARU =====================================" << endl; 
        cout << "Pilih Jenis Entri" << endl; 
        cout << "[1] Flora" << endl;
        cout << "[2] Fauna" << endl; 
        cout << "---------------------------------------------------------" << endl;
        cout << "[0] Kembali" << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << "Masukkan Pilihan Anda" << endl; 
        cout << "> "; cin >> pilihan; 
        
        pilihan = errorHandling(pilihan);
        switch (pilihan) {
            case 0: 
            cout << "=> Kembali ke menu sebelumnya" << endl; 
            break; 

            case 1: 
            cout << "=> Membuat entri dengan tipe 'Flora'" << endl;
            lanjut = true; 
            break; 

            case 2: 
            cout << "=> Membuat entri dengan tipe 'Fauna'" << endl;
            lanjut = true; 
            break; 

            default: 
            cout << "=> Pilihan yang Anda masukkan tidak valid" << endl;
            break;
        }

    } while (pilihan != 0 && !lanjut);

    if (lanjut) {
        const int ukuranSkala = 6;
        string skalaKonservasi[ukuranSkala] = {
            "LC - Risiko Rendah", 
            "NT - Hampir Terancam", 
            "VU - Rentan", 
            "EN - Terancam", 
            "CR - Sangat Terancam", 
            "EW - Punah di Alam Liar"
        };

        entri[jumlahEntri].klasifikasi = pilihan - 1;

        while (true) {
            cout << "\n=== PILIH SKALA KONSERVASI ==============================" << endl; 
            cout << "[1] Risiko Rendah (LC)" << endl; 
            cout << "[2] Hampir Terancam (NT)" << endl;
            cout << "[3] Rentan (VU)" << endl;
            cout << "[4] Terancam (EN)" << endl;
            cout << "[5] Sangat Terancam (CR)" << endl; 
            cout << "[6] Punah di Alam Liar (EW)" << endl;
            cout << "---------------------------------------------------------" << endl; 
            cout << "[10] Kembali" << endl; 
            cout << "---------------------------------------------------------" << endl;
            cout << "Masukkan Pilihan Anda" << endl; 
            cout << "> "; cin >> pilihan;

            pilihan = errorHandling(pilihan);

            if (pilihan == 10) {
                cout << "=> Kembali ke menu sebelumnya" << endl; 
                break;
            }

            else if (pilihan < 0 || pilihan > ukuranSkala) {
                cout << "=> Pilihan yang Anda masukkan tidak valid" << endl;
                continue; 
            }

            for (int i = 0; i < ukuranSkala; i++) {
                if (pilihan == i) {
                    entri[jumlahEntri].skalaKonservasi = skalaKonservasi[i - 1];
                    break; 
                }
            }

            string tipeEntri = (entri[jumlahEntri].klasifikasi == false) ? "Flora" : "Fauna";
            cout << "\n=== ENTRI BARU =========================================" << endl;
            cout << "Tipe Entri        : " << tipeEntri << endl; 
            cout << "Skala Konservasi  : " << entri[jumlahEntri].skalaKonservasi << endl;
            cout << "---------------------------------------------------------" << endl;

            string inputNamaUmum, inputNamaLatin, inputHabitat, inputTahunMasuk; 
            int inputJumlah;
            
            cin.ignore();
            cout << "Masukkan Nama Umum               : "; getline(cin, inputNamaUmum);
            cout << "Masukkan Nama Latin              : "; getline(cin, inputNamaLatin); 
            cout << "Masukkan Habitat Asli            : "; getline(cin, inputHabitat);
            cout << "Masukkan Tahun Masuk Kebun Raya  : "; getline(cin, inputTahunMasuk);
            cout << "Masukkan Jumlah Spesimen         : "; cin >> inputJumlah;

            entri[jumlahEntri].entriID = jumlahEntri + 1;
            entri[jumlahEntri].namaUmum = inputNamaUmum;
            entri[jumlahEntri].namaLatin = inputNamaLatin; 
            entri[jumlahEntri].habitatAsli = inputHabitat;
            entri[jumlahEntri].tahunMasuk = inputTahunMasuk;
            entri[jumlahEntri].jumlah = inputJumlah;
            jumlahEntri++;

            cout << "---------------------------------------------------------" << endl;
            cout << "=> Entri berhasil ditambahkan" << endl;
            cout << "---------------------------------------------------------" << endl;
            break;
        }
    }
}

void updateEntri(KebunRaya entri[], int jumlahEntri) {
    int pilihan, indeksEntriSekarang; 
    bool entriDitemukan = false;
    bool keluar;

    const int ukuranSkala = 6;
    string skalaKonservasi[ukuranSkala] = {
        "LC - Risiko Rendah", 
        "NT - Hampir Terancam", 
        "VU - Rentan", 
        "EN - Terancam", 
        "CR - Sangat Terancam", 
        "EW - Punah di Alam Liar"
    };

    do {
        indeksEntriSekarang = -1;
        entriDitemukan = false;
        cout << "\n=== PERBARUI ENTRI ======================================" << endl; 
        lihatEntriShort(entri, jumlahEntri);
        cout << "[0] Kembali" << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << "Masukkan ID entri yang ingin diperbarui" << endl; 
        cout << "> "; cin >> pilihan;

        pilihan = errorHandling(pilihan);

        if (pilihan == 0) {
            cout << "=> Kembali ke menu sebelumnya" << endl;
            cout << "---------------------------------------------------------" << endl;
            break;
        }
        
        for (int i = 0; i < jumlahEntri; i++) {
            if (pilihan == entri[i].entriID) {
                cout << "=> Entri ditemukan" << endl;
                entriDitemukan = true;
                indeksEntriSekarang = i;
                cout << "---------------------------------------------------------" << endl;
                break;
            }
        }

        if (!entriDitemukan) {
            cout << "=> Entri tidak ditemukan. Silakan coba lagi" << endl;
            cout << "---------------------------------------------------------" << endl;
        } 
    } while (!entriDitemukan);

    if (entriDitemukan) {
        string inputNamaUmum, inputNamaLatin, inputHabitat, inputTahunMasuk; 
        int inputJumlah;
        
        do {
            string tipeEntri = (entri[indeksEntriSekarang].klasifikasi == false) ? "Flora" : "Fauna";
            cout << "\n=== DATA ENTRI YANG AKAN DIPERBARUI =====================" << endl;
            cout << "[1] Nama Umum         : " << entri[indeksEntriSekarang].namaUmum << endl; 
            cout << "[2] Nama Latin        : " << entri[indeksEntriSekarang].namaLatin << endl; 
            cout << "[3] Tipe              : " << tipeEntri << endl; 
            cout << "[4] Skala Konservasi  : " << entri[indeksEntriSekarang].skalaKonservasi << endl; 
            cout << "[5] Habitat Asli      : " << entri[indeksEntriSekarang].habitatAsli << endl; 
            cout << "[6] Tahun Masuk       : " << entri[indeksEntriSekarang].tahunMasuk << endl; 
            cout << "[7] Jumlah            : " << entri[indeksEntriSekarang].jumlah << endl; 
            cout << "---------------------------------------------------------" << endl;
            cout << "[0] Kembali" << endl;
            cout << "---------------------------------------------------------" << endl;
            cout << "Masukkan Pilihan Anda" << endl; 
            cout << "> "; cin >> pilihan;

            pilihan = errorHandling(pilihan);
            cin.ignore();
            switch (pilihan) {
                case 0: 
                cout << "=> Kembali ke menu sebelumnya" << endl;
                cout << "---------------------------------------------------------" << endl;
                break;

                case 1: 
                cout << "\n=> Edit Nama Umum" << endl;
                cout << "Nama Sebelumnya : " << entri[indeksEntriSekarang].namaUmum << endl; 
                cout << "Nama Baru       : "; getline(cin, inputNamaUmum);
                cout << "---------------------------------------------------------" << endl;
                cout << "=> Nama Umum Berhasil diganti" << endl; 
                cout << "---------------------------------------------------------" << endl; 
                
                entri[indeksEntriSekarang].namaUmum = inputNamaUmum;
                break;

                case 2: 
                cout << "\n=> Edit Nama Latin" << endl;
                cout << "Nama Sebelumnya : " << entri[indeksEntriSekarang].namaLatin << endl; 
                cout << "Nama Baru       : "; getline(cin, inputNamaLatin);
                cout << "---------------------------------------------------------" << endl;
                cout << "=> Nama Latin Berhasil Diganti" << endl;
                cout << "---------------------------------------------------------" << endl;

                entri[indeksEntriSekarang].namaLatin = inputNamaLatin;
                break; 

                case 3: 
                keluar = false;
                while (!keluar) {
                    cout << "\n=== EDIT TIPE ENTRI =====================================" << endl; 
                    string tipeEntri = (entri[indeksEntriSekarang].klasifikasi == false) ? "Flora" : "Fauna";
                    
                    cout << "Tipe Sebelumnya : " << tipeEntri << endl;
                    cout << "---------------------------------------------------------" << endl;
                    cout << "[1] Flora" << endl; 
                    cout << "[2] Fauna" << endl; 
                    cout << "---------------------------------------------------------" << endl; 
                    cout << "[0] Kembali" << endl; 
                    cout << "---------------------------------------------------------" << endl;
                    cout << "Masukkan Pilihan Anda" << endl;
                    cout << "> "; cin >> pilihan;
                    cout << "---------------------------------------------------------" << endl;

                    pilihan = errorHandling(pilihan);
                    switch (pilihan) {
                        case 0: 
                        cout << "=> Kembali ke menu sebelumnya" << endl; 
                        cout << "---------------------------------------------------------" << endl;
                        keluar = true;
                        break; 

                        case 1: 
                        cout << "=> Mengganti tipe entri menjadi 'Flora'" << endl; 
                        entri[indeksEntriSekarang].klasifikasi = false; 
                        keluar = true;
                        cout << "---------------------------------------------------------" << endl;
                        break;

                        case 2: 
                        cout << "=> Mengganti tipe entri menjadi 'Fauna'" << endl; 
                        entri[indeksEntriSekarang].klasifikasi = true; 
                        keluar = true;
                        cout << "---------------------------------------------------------" << endl;
                        break; 

                        default: 
                        cout << "=> Pilihan yang Anda masukkan tidak valid" << endl;
                        cout << "---------------------------------------------------------" << endl;
                        break;
                    }

                    if (keluar) {
                        break;
                    }
                }                
                break; 


                case 4:
                while (true) {
                    cout << "\n=== EDIT SKALA KONSERVASI ===============================" << endl;
                    cout << "[1] Risiko Rendah (LC)" << endl; 
                    cout << "[2] Hampir Terancam (NT)" << endl;
                    cout << "[3] Rentan (VU)" << endl;
                    cout << "[4] Terancam (EN)" << endl;
                    cout << "[5] Sangat Terancam (CR)" << endl; 
                    cout << "[6] Punah di Alam Liar (EW)" << endl;
                    cout << "---------------------------------------------------------" << endl; 
                    cout << "[10] Kembali" << endl; 
                    cout << "---------------------------------------------------------" << endl;
                    cout << "Masukkan Pilihan Anda" << endl; 
                    cout << "> "; cin >> pilihan;
                    cout << "---------------------------------------------------------" << endl;

                    pilihan = errorHandling(pilihan);
                    if (pilihan == 10) {
                        cout << "=> Kembali ke menu sebelumnya" << endl; 
                        cout << "---------------------------------------------------------" << endl;
                        break;
                    }

                    else if (pilihan < 0 || pilihan > ukuranSkala) {
                        cout << "=> Pilihan yang Anda masukkan tidak valid" << endl;
                        cout << "---------------------------------------------------------" << endl;
                        continue; 
                    }

                    for (int i = 0; i < ukuranSkala; i++) {
                        if (pilihan == i) {
                            entri[indeksEntriSekarang].skalaKonservasi = skalaKonservasi[i - 1];
                            break; 
                        }
                    }
                    break;
                } 
                break; 

                case 5: 
                cout << "=> Edit Habitat Asli" << endl; 
                cout << "Habitat Sebelumnya : " << entri[indeksEntriSekarang].habitatAsli << endl; 
                cout << "Habitat Baru       : "; getline(cin, inputHabitat); 
                cout << "---------------------------------------------------------" << endl;
                cout << "=> Habitat Berhasil diganti" << endl;
                cout << "---------------------------------------------------------" << endl;

                entri[indeksEntriSekarang].habitatAsli = inputHabitat; 
                break; 

                case 6: 
                cout << "=> Edit Tahun Masuk" << endl; 
                cout << "Tahun Sebelumnya : " << entri[indeksEntriSekarang].tahunMasuk << endl;
                cout << "Tahun Baru       : "; getline(cin, inputTahunMasuk);
                cout << "---------------------------------------------------------" << endl;
                cout << "=> Tahun Berhasil Diubah" << endl;
                cout << "---------------------------------------------------------" << endl;

                entri[indeksEntriSekarang].tahunMasuk = inputTahunMasuk; 
                break; 

                case 7: 
                cout << "=> Edit Jumlah" << endl; 
                cout << "Jumlah Sebelumnya : " << entri[indeksEntriSekarang].jumlah << endl;
                cout << "Jumlah Baru       : "; cin >> inputJumlah;
                cout << "---------------------------------------------------------" << endl;
                cout << "=> Jumlah Spesimen Berhasil Diubah" << endl;
                cout << "---------------------------------------------------------" << endl;

                entri[indeksEntriSekarang].jumlah = inputJumlah; 
                break; 

                default: 
                cout << "=> Pilihan yang Anda masukkan tidak valid" << endl;
                cout << "---------------------------------------------------------" << endl; 
                break;
            }

        } while (pilihan != 0);
    }
    else {
        cout << "=> Entri tidak ditemukan" << endl;
        cout << "---------------------------------------------------------" << endl;
    }

}

void hapusEntri(KebunRaya entri[], int &jumlahEntri) {
    int pilihan, indeksEntriSekarang;
    bool entriDitemukan;

    do {
        entriDitemukan = false;
        cout << "\n=== HAPUS ENTRI =========================================" << endl; 
        lihatEntriShort(entri, jumlahEntri); 
        cout << "[0] Kembali" << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << "Masukkan ID entri yang ingin dihapus" << endl; 
        cout << "> "; cin >> pilihan;
        cout << "---------------------------------------------------------" << endl;

        pilihan = errorHandling(pilihan);

        if (pilihan == 0) {
            cout << "=> Kembali ke menu sebelumnya" << endl; 
            cout << "---------------------------------------------------------" << endl;
            break;
        }

        for (int i = 0; i < jumlahEntri; i++) {
            if (pilihan == entri[i].entriID) {
                cout << "=> Entri ditemukan" << endl;
                entriDitemukan = true;
                indeksEntriSekarang = i;
                cout << "---------------------------------------------------------" << endl;
                break;
            }
        }

        if (entriDitemukan) {
            while (true) {
                string tipeEntri = (entri[indeksEntriSekarang].klasifikasi == false) ? "Flora" : "Fauna";
                cout << "\n=== KONFIRMASI HAPUS ENTRI ==============================" << endl;
                cout << "Nama Umum         : " << entri[indeksEntriSekarang].namaUmum << endl; 
                cout << "Nama Latin        : " << entri[indeksEntriSekarang].namaLatin << endl; 
                cout << "Tipe              : " << tipeEntri << endl; 
                cout << "Skala Konservasi  : " << entri[indeksEntriSekarang].skalaKonservasi << endl; 
                cout << "---------------------------------------------------------" << endl; 
                cout << "[1] Hapus Entri" << endl; 
                cout << "[0] Kembali" << endl; 
                cout << "---------------------------------------------------------" << endl;
                cout << "Masukkan Pilihan Anda" << endl; 
                cout << "> "; cin >> pilihan;
                cout << "---------------------------------------------------------" << endl;

                pilihan = errorHandling(pilihan);

                if (pilihan == 0) {
                    cout << "=> Kembali ke menu sebelumnya" << endl;
                    cout << "---------------------------------------------------------" << endl;
                    break;
                }
                else if (pilihan == 1) {
                    cout << "=> Menghapus entri" << endl; 
                    for (int i = indeksEntriSekarang; i < jumlahEntri; i++) {
                        entri[i] = entri[i + 1]; 
                        entri[i].entriID = i + 1; 
                    } jumlahEntri--;
                    cout << "=> Entri berhasil dihapus" << endl;
                    cout << "---------------------------------------------------------" << endl;
                    break;
                }
                else {
                    cout << "=> Pilihan tidak valid" << endl; 
                    cout << "---------------------------------------------------------" << endl;
                }
            }
             
        } 
        else {
            cout << "=> Entri tidak ditemukan" << endl; 
            cout << "---------------------------------------------------------" << endl;
        }
    } while (pilihan != 0);
    
}

void lihatUser(Pengguna akun[], int jumlahPengguna) {
    string kembali; 
    cout << "\n=== AKUN YANG ADA DI DATABASE ===========================" << endl; 
    for (int i = 0; i < jumlahPengguna; i++) {
        string privilese = (akun[i].isAdmin) ? "Admin" : "Member"; 

        cout << "[Akun ke-" << i + 1 << "]" << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << "User ID   : " << akun[i].userID << endl;
        cout << "Username  : " << akun[i].username << endl;
        cout << "Password  : " << akun[i].password << endl;
        cout << "Role      : " << privilese << endl; 
        cout << "---------------------------------------------------------" << endl;
    } 

    cin.ignore();
    cout << "Tekan 'Enter' untuk kembali" << endl; 
    cout << "> "; getline(cin, kembali);
    cout << "---------------------------------------------------------" << endl;
}

void lihatUserShort(Pengguna akun[], int jumlahPengguna) {
    cout << "=== DAFTAR SINGKAT USER ================================" << endl;
    for (int i = 0; i < jumlahPengguna; i++) {
        string privilese = (akun[i].isAdmin == true) ? "Admin" : "Member"; 
        cout << "---------------------------------------------------------" << endl;
        cout << "User ID   : " << akun[i].userID << endl;
        cout << "Username  : " << akun[i].username << endl;
        cout << "Role      : " << privilese << endl; 
        cout << "---------------------------------------------------------" << endl;
    } 
}

void perbaruiUser(Pengguna akun[], int jumlahPengguna) {
    int pilihan, indeksUserSekarang; 
    string updateUsername, updatePassword;
    bool akunDitemukan; 

    do {
        akunDitemukan = false;
        cout << "\n=== PERBARUI USER =======================================" << endl;
        lihatUserShort(akun, jumlahPengguna); 
        cout << "[0] Kembali" << endl; 
        cout << "---------------------------------------------------------" << endl;
        cout << "Masukkan User ID yang ingin diperbarui" << endl; 
        cout << "> "; cin >> pilihan;
        cout << "---------------------------------------------------------" << endl;

        pilihan = errorHandling(pilihan);
        if (pilihan == 0) {
            cout << "=> Kembali ke menu sebelumnya" << endl; 
            cout << "---------------------------------------------------------" << endl;
            break; 
        }

        for (int i = 0; i < jumlahPengguna; i++) {
            if (pilihan == akun[i].userID) {
                cout << "=> Akun ditemukan" << endl; 
                akunDitemukan = true;
                indeksUserSekarang = i; 
                cout << "---------------------------------------------------------" << endl;
                break;
            }
        }
    } while (pilihan != 0 && !akunDitemukan);

    if (akunDitemukan) {
        while (true) {
            string privilese = (akun[indeksUserSekarang].isAdmin == true) ? "Admin" : "Member"; 
            cout << "\n=== AKUN YANG AKAN DIPERBARUI ===========================" << endl; 
            cout << "[1] Username  : " << akun[indeksUserSekarang].username << endl; 
            cout << "[2] Password  : " << akun[indeksUserSekarang].password << endl;
            cout << "[3] Role      : " << privilese << endl;
            cout << "---------------------------------------------------------" << endl; 
            cout << "[0] Kembali" << endl;
            cout << "---------------------------------------------------------" << endl;            
            cout << "Masukkan Pilihan Anda" << endl; 
            cout << "> "; cin >> pilihan;
            cout << "---------------------------------------------------------" << endl;

            pilihan = errorHandling(pilihan);
            if (pilihan == 0) {
                cout << "=> Kembali ke menu sebelumnya" << endl; 
                cout << "---------------------------------------------------------" << endl;
                break;
            }
            else if (pilihan == 1) {
                cin.ignore();
                cout << "=> Mengganti Username" << endl;
                cout << "Username Lama : " << akun[indeksUserSekarang].username << endl; 
                cout << "Username Baru : "; getline(cin, updateUsername);
                cout << "---------------------------------------------------------" << endl;
                cout << "=> Username Berhasil Diubah" << endl;
                cout << "---------------------------------------------------------" << endl; 
                
                akun[indeksUserSekarang].username = updateUsername;
            } 
            else if (pilihan == 2) {
                cin.ignore();
                cout << "=> Mengganti Password" << endl;
                cout << "Password Lama : " << akun[indeksUserSekarang].password << endl;
                cout << "Password Baru : "; getline(cin, updatePassword);
                cout << "---------------------------------------------------------" << endl;
                cout << "=> Password Berhasil Diubah" << endl;
                cout << "---------------------------------------------------------" << endl;

                akun[indeksUserSekarang].password = updatePassword;
            }
            else if (pilihan == 3) {
                while (true) {
                    cout << "\n=== GANTI ROLE USER =====================================" << endl;
                    cout << "Role Sebelumnya : " << privilese << endl; 
                    cout << "---------------------------------------------------------" << endl; 
                    cout << "[1] Admin" << endl; 
                    cout << "[2] Member" << endl; 
                    cout << "---------------------------------------------------------" << endl;
                    cout << "[0] Kembali" << endl;
                    cout << "---------------------------------------------------------" << endl;
                    cout << "Masukkan Pilihan Anda" << endl; 
                    cout << "> "; cin >> pilihan; 
                    cout << "---------------------------------------------------------" << endl;
                    
                    pilihan = errorHandling(pilihan);
                    if (pilihan == 0) {
                        cout << "=> Kembali ke menu sebelumnya" << endl;
                        cout << "---------------------------------------------------------" << endl;
                        break;
                    }
                    else if (pilihan == 1) {
                        cout << "=> Mengganti role menjadi 'Admin'" << endl; 
                        cout << "---------------------------------------------------------" << endl;
                        akun[indeksUserSekarang].isAdmin = true; 
                        break;
                    }
                    else if (pilihan == 2) {
                        cout << "=> Mengganti role menjadi 'Member'" << endl;
                        cout << "---------------------------------------------------------" << endl; 
                        akun[indeksUserSekarang].isAdmin = false; 
                        break;
                    }
                    else {
                        cout << "=> Pilihan tidak valid" << endl; 
                        cout << "---------------------------------------------------------" << endl;
                    }
                }
            }
            else {
                cout << "=> Pilihan tidak valid" << endl;
                cout << "---------------------------------------------------------" << endl;
            }
        }        
    }
    else {
        cout << "=> Akun tidak ditemukan" << endl;
        cout << "---------------------------------------------------------" << endl;
    }
}

void hapusUser(Pengguna akun[], int &jumlahPengguna) {
    int pilihan, indeksUserSekarang; 
    bool akunDitemukan; 

    do {
        akunDitemukan = false;
        cout << "\n=== HAPUS PENGGUNA ======================================" << endl; 
        lihatUserShort(akun, jumlahPengguna); 
        cout << "[0] Kembali" << endl; 
        cout << "---------------------------------------------------------" << endl;
        cout << "Masukkan User ID yang ingin dihapus" << endl; 
        cout << "> "; cin >> pilihan; 
        cout << "---------------------------------------------------------" << endl;

        pilihan = errorHandling(pilihan);
        if (pilihan == 0) {
            cout << "=> Kembali ke menu sebelumnya" << endl;
            cout << "---------------------------------------------------------" << endl; 
            break;
        }

        for (int i = 0; i < jumlahPengguna; i++) {
            if (pilihan == akun[i].userID) {
                cout << "=> Akun ditemukan" << endl;
                akunDitemukan = true; 
                indeksUserSekarang = i; 
                cout << "---------------------------------------------------------" << endl;
                break;
            }
        }

        if (!akunDitemukan) {
            cout << "=> Akun tidak ditemukan. Coba lagi" << endl;
            cout << "---------------------------------------------------------" << endl;
        }
    } while (pilihan != 0 && !akunDitemukan);

    if (akunDitemukan) {
        while (true) {
            string privilese = (akun[indeksUserSekarang].isAdmin == true) ? "Admin" : "Member";
            cout << "\n=== KONFIRMASI HAPUS USER ===============================" << endl; 
            cout << "User ID   : " << akun[indeksUserSekarang].userID << endl; 
            cout << "Username  : " << akun[indeksUserSekarang].username << endl; 
            cout << "Role      : " << privilese << endl;
            cout << "---------------------------------------------------------" << endl;
            cout << "[1] Hapus" << endl; 
            cout << "[0] Kembali" << endl;
            cout << "---------------------------------------------------------" << endl;
            cout << "Masukkan Pilihan Anda" << endl; 
            cout << "> "; cin >> pilihan; 
            cout << "---------------------------------------------------------" << endl;

            pilihan = errorHandling(pilihan);
            if (pilihan == 0) {
                cout << "=> Kembali ke menu sebelumnya" << endl; 
                cout << "---------------------------------------------------------" << endl;
                break;
            }
            else if (pilihan == 1) {
                cout << "=> Menghapus akun" << endl; 
                for (int i = indeksUserSekarang; i < jumlahPengguna; i++) {
                    akun[i] = akun[i + 1]; 
                    akun[i].userID = i + 1; 
                } jumlahPengguna--;
                cout << "=> Akun berhasil dihapus" << endl;
                cout << "---------------------------------------------------------" << endl;
                break;
            }
            else {
                cout << "=> Pilihan tidak valid" << endl; 
                cout << "---------------------------------------------------------" << endl;
            }
        } 
    }
}

int regis(Pengguna akun[], int &jumlahPengguna) {
    string username, password;
    bool usernameValid = true;

    cin.ignore();
    do {
        usernameValid = true;
        cout << "\n=== MENU REGISTER =======================================" << endl;
        cout << "Masukkan Username" << endl;
        cout << "> "; getline(cin, username);
        cout << "---------------------------------------------------------" << endl;

        for (int i = 0; i < jumlahPengguna; i++) {
            if (username == akun[i].username) {
                cout << "=> Username sudah digunakan. Silakan masukkan username lain" << endl;
                cout << "---------------------------------------------------------" << endl;
                usernameValid = false; 
                break;
            }
        }
    } while (!usernameValid);

    cout << "Masukkan Password" << endl; 
    cout << "> "; getline(cin, password); 
    cout << "---------------------------------------------------------" << endl;

    akun[jumlahPengguna].userID = jumlahPengguna + 1; 
    akun[jumlahPengguna].username = username; 
    akun[jumlahPengguna].password = password; 
    akun[jumlahPengguna].isAdmin = false; 
    jumlahPengguna++;

    cout << "=> Register berhasil" << endl;
    cout << "---------------------------------------------------------" << endl;
    return jumlahPengguna;
}

void menuAdmin(int indeksUser, KebunRaya entri[]) {
    int pilihan;
    
    do {
        cout << "\n==== MENU ADMIN =========================================" << endl;
        cout << "Selamat Datang Kembali, Admin " << akun[indeksUser].username << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << "[MENU MANAJEMEN ENTRI]" << endl;
        cout << "[1] Buat Entri Baru" << endl; 
        cout << "[2] Lihat Entri" << endl; 
        cout << "[3] Perbarui Entri" << endl; 
        cout << "[4] Hapus Entri" << endl; 
        cout << "---------------------------------------------------------" << endl;
        cout << "[MENU MANAJEMEN USER]" << endl;
        cout << "[5] Buat User Baru" << endl; 
        cout << "[6] Lihat User" << endl; 
        cout << "[7] Perbarui User" << endl; 
        cout << "[8] Hapus User" << endl; 
        cout << "---------------------------------------------------------" << endl;
        cout << "[0] Logout" << endl; 
        cout << "---------------------------------------------------------" << endl;
        cout << "Masukkan Pilihan Anda" << endl; 
        cout << "> "; cin >> pilihan;
    
        pilihan = errorHandling(pilihan);
        switch (pilihan) {
            case 0: 
            cout << "=> Logout dari program" << endl;
            cout << "---------------------------------------------------------" << endl; 
            break;
            
            case 1: 
            cout << "=> Mengarahkan ke menu 'Tambah Entri'" << endl;
            cout << "---------------------------------------------------------" << endl;
            tambahEntri(entri, jumlahEntri); 
            break;

            case 2: 
            cout << "=> Mengarahkan ke menu 'Lihat Entri'" << endl;  
            cout << "---------------------------------------------------------" << endl;
            lihatEntri(entri, jumlahEntri);
            break;

            case 3:
            cout << "=> Mengarahkan ke menu 'Perbarui Entri'" << endl;
            cout << "---------------------------------------------------------" << endl;
            updateEntri(entri, jumlahEntri); 
            break;

            case 4: 
            cout << "=> Mengarahkan ke menu 'Hapus Entri'" << endl;
            cout << "---------------------------------------------------------" << endl;
            hapusEntri(entri, jumlahEntri); 
            break;
            
            case 5: 
            cout << "=> Mengarahkan ke menu 'Buat User'" << endl;
            cout << "---------------------------------------------------------" << endl;
            regis(akun, jumlahPengguna); 
            break;

            case 6: 
            cout << "=> Mengarahkan ke menu 'Lihat User'" << endl; 
            cout << "---------------------------------------------------------" << endl;
            lihatUser(akun, jumlahPengguna);
            break; 

            case 7: 
            cout << "=> Mengarahkan ke menu 'Perbarui User'" << endl; 
            cout << "---------------------------------------------------------" << endl;
            perbaruiUser(akun, jumlahPengguna);
            break; 

            case 8: 
            cout << "=> Mengarahkan ke menu 'Hapus User'" << endl;
            cout << "---------------------------------------------------------" << endl;
            hapusUser(akun, jumlahPengguna);
            break;

            default: 
            cout << "=> Pilihan tidak valid, coba lagi" << endl; 
            cout << "---------------------------------------------------------" << endl;
            break;
        }
    } while (pilihan != 0);   
}

void menuUser(int indeksUser, KebunRaya entri[]) {
    int pilihan;
    
    do {
        cout << "\n==== MENU USER ==========================================" << endl;
        cout << "Selamat Datang Kembali, " << akun[indeksUser].username << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << "[1] Buat Entri Baru" << endl; 
        cout << "[2] Lihat Entri" << endl; 
        cout << "[3] Perbarui Entri" << endl; 
        cout << "[4] Hapus Entri" << endl; 
        cout << "---------------------------------------------------------" << endl;
        cout << "[0] Logout" << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << "Masukkan Pilihan Anda" << endl; 
        cout << "> "; cin >> pilihan;
        cout << "---------------------------------------------------------" << endl;

        pilihan = errorHandling(pilihan);
        switch (pilihan) {
            case 0: 
            cout << "=> Logout dari program" << endl; 
            cout << "---------------------------------------------------------" << endl;
            break;
            
            case 1: 
            cout << "=> Mengarahkan ke menu 'Tambah Entri'" << endl;
            cout << "---------------------------------------------------------" << endl;
            tambahEntri(entri, jumlahEntri); 
            break;

            case 2: 
            cout << "=> Mengarahkan ke menu 'Lihat Entri'" << endl;  
            cout << "---------------------------------------------------------" << endl;
            lihatEntri(entri, jumlahEntri);
            break;

            case 3:
            cout << "=> Mengarahkan ke menu 'Perbarui Entri'" << endl;
            cout << "---------------------------------------------------------" << endl;
            updateEntri(entri, jumlahEntri); 
            break;

            case 4: 
            cout << "=> Mengarahkan ke menu 'Hapus Entri'" << endl;
            cout << "---------------------------------------------------------" << endl;
            hapusEntri(entri, jumlahEntri); 
            break; 

            default: 
            cout << "=> Pilihan tidak valid, coba lagi" << endl; 
            cout << "---------------------------------------------------------" << endl;
            break;
        }
    } while (pilihan != 0);
}

int login(Pengguna akun[], int jumlahPengguna) {
    string username, password;
    bool akunDitemukan, passwordBenar = false;
    int indeksUser;
    int kesempatan = 3;

    cin.ignore();
    do {
        indeksUser = -1;
        akunDitemukan = false;
        
        cout << "\n=== MENU LOGIN ==========================================" << endl; 
        cout << "Masukkan Username Anda" << endl; 
        cout << "> "; getline(cin, username); 
        cout << "---------------------------------------------------------" << endl;

        for (int i = 0; i < jumlahPengguna; i++) {
            if (username == akun[i].username) {
                cout << "=> Akun ditemukan" << endl;
                cout << "---------------------------------------------------------" << endl;
                akunDitemukan = true; 
                indeksUser = i; 
                break;
            }
        }

        if (!akunDitemukan) {
            cout << "=> Akun tidak ditemukan. Coba lagi" << endl;
            cout << "---------------------------------------------------------" << endl;
        }
    } while (!akunDitemukan);
    
    do {
        cout << "Sisa Kesempatan: " << kesempatan << endl;
        cout << "Masukkan Password Anda" << endl;
        cout << "> "; getline(cin, password);
        cout << "---------------------------------------------------------" << endl;

        if (password == akun[indeksUser].password) {
            cout << "=> Password benar" << endl;
            cout << "---------------------------------------------------------" << endl; 
            passwordBenar = true;
        }
        else {
            cout << "=> Password salah! Silakan coba lagi" << endl;
            cout << "---------------------------------------------------------" << endl;
            kesempatan--;
        }

    } while (kesempatan != 0 && !passwordBenar);

    if (akunDitemukan && passwordBenar) {
        cout << "=> Login berhasil" << endl;
        cout << "---------------------------------------------------------" << endl;
        return indeksUser;
    } 
    else {
        cout << "=> Login gagal";
        cout << "---------------------------------------------------------" << endl;
        return -1;
    }
}

void menuUtama(Pengguna akun[], KebunRaya entri[]) {
    int pilihan;
    int indeksUser;

    do {
        cout << "\n==== SISTEM MANAJEMEN KEBUN RAYA ========================" << endl;
        cout << "[1] Login" << endl; 
        cout << "[2] Register" << endl;
        cout << "[0] Keluar" << endl; 
        cout << "---------------------------------------------------------" << endl;
        cout << "Pilihan Anda" << endl; 
        cout << "> "; cin >> pilihan;
        cout << "---------------------------------------------------------" << endl; 
        
        pilihan = errorHandling(pilihan);
        switch (pilihan) {
            case 0:
            cout << "=> Keluar dari program" << endl;
            cout << "---------------------------------------------------------" << endl;
            cout << "======== Terima kasih telah menggunakan program =========" << endl;
            cout << endl;
            break;
            
            case 1: 
            cout << "=> Mengalihkan ke menu login" << endl;
            cout << "---------------------------------------------------------" << endl; 
            
            indeksUser = login(akun, jumlahPengguna); 
            if (indeksUser >= 0) {
                cout << "=> Mengarahkan ke menu selanjutnya" << endl;
                cout << "---------------------------------------------------------" << endl;
                if (akun[indeksUser].isAdmin) {
                    menuAdmin(indeksUser, entri);
                } 
                else {
                    menuUser(indeksUser, entri);
                }
            } 
            else {
                cout << endl << "=> Keluar dari program" << endl;
                cout << "---------------------------------------------------------" << endl;
                cout << "===               Kesempatan Login Habis              ===" << endl;
                cout << "================= Silakan Ulang Program =================" << endl;
                pilihan = 0; 

                cout << endl;
            }
            break;

            case 2: 
            cout << "=> Mengalihkan ke menu register" << endl;
            cout << "---------------------------------------------------------" << endl; 
            regis(akun, jumlahPengguna);
            break;

            default: 
            cout << "=> Pilihan tidak valid. Coba lagi" << endl; 
            cout << "---------------------------------------------------------" << endl;
            break;
        }

    } while(pilihan != 0); 
}

int main() {    
    // CONTOH AKUN
    akun[0].userID      = 1;        akun[1].userID      = 2;
    akun[0].username    = "Yoga";   akun[1].username    = "LianSifwah";
    akun[0].password    = "017";    akun[1].password    = "aslabGantengA1";
    akun[0].isAdmin     = true;     akun[1].isAdmin     = false;

    // CONTOH ENTRI
    entri[0].entriID = 1;
    entri[0].namaUmum = "Padi"; 
    entri[0].namaLatin = "Oryza sativa"; 
    entri[0].skalaKonservasi = "Aman"; 
    entri[0].habitatAsli = "Indonesia"; 
    entri[0].tahunMasuk = "2000"; 
    entri[0].jumlah = 100000; 
    entri[0].klasifikasi = false;

    menuUtama(akun, entri);
    return 0;
}