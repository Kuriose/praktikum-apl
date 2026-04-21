#include <iostream>
#include <string>
#include <cctype>
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
int uniqueUser = jumlahPengguna;

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
int jumlahEntri = 20;
int uniqueEntri = jumlahEntri;

// FEAT: Prosedur & Fungsi Pembantu
void addEntriDummy(KebunRaya arr[], int &ukuran) {
    KebunRaya temp[] = {
        {1, "PADI", "Oryza sativa", "LC - Risiko Rendah", "Indonesia", "2000", 10000, false},
        {2, "HARIMAU SUMATERA", "Panthera tigris sumatrae", "CR - Sangat Terancam", "Indonesia", "2005", 15, true},
        {3, "ANOA DATARAN RENDAH", "Bubalus depressicornis", "EN - Terancam", "Indonesia", "2008", 40, true},
        {4, "BURUNG MALEO", "Macrocephalon maleo", "EN - Terancam", "Indonesia", "2010", 200, true},
        {5, "BUNGA RAFFLESIA", "Rafflesia arnoldii", "VU - Rentan", "Indonesia", "2002", 50, false},

        {6, "ANGGREK BULAN", "Phalaenopsis amabilis", "LC - Risiko Rendah", "Indonesia", "2001", 500, false},
        {7, "KANTONG SEMAR", "Nepenthes rafflesiana", "VU - Rentan", "Kalimantan", "2003", 120, false},
        {8, "KAYU ULIN", "Eusideroxylon zwageri", "VU - Rentan", "Sumatera & Kalimantan", "2000", 300, false},
        {9, "CENDANA", "Santalum album", "VU - Rentan", "Nusa Tenggara", "2004", 150, false},
        {10, "EDELWEISS JAWA", "Anaphalis javanica", "LC - Risiko Rendah", "Jawa (Gunung)", "2006", 1000, false},

        {11, "ORANGUTAN KALIMANTAN", "Pongo pygmaeus", "CR - Sangat Terancam", "Kalimantan", "2007", 25, true},
        {12, "KOMODO", "Varanus komodoensis", "EN - Terancam", "Nusa Tenggara", "2005", 30, true},
        {13, "JALAK BALI", "Leucopsar rothschildi", "CR - Sangat Terancam", "Bali", "2009", 45, true},
        {14, "GAJAH SUMATERA", "Elephas maximus sumatranus", "CR - Sangat Terancam", "Sumatera", "2006", 18, true},
        {15, "BADAK JAWA", "Rhinoceros sondaicus", "CR - Sangat Terancam", "Jawa (Ujung Kulon)", "2005", 7, true},

        {16, "MERANTI", "Shorea leprosula", "EN - Terancam", "Sumatera", "2002", 400, false},
        {17, "TARSIUS", "Tarsius tarsier", "VU - Rentan", "Sulawesi", "2011", 60, true},
        {18, "IKAN ARWANA", "Scleropages formosus", "EN - Terancam", "Kalimantan", "2012", 80, true},
        {19, "BANGAU TONGTONG", "Leptoptilos javanicus", "VU - Rentan", "Jawa & Sumatera", "2013", 35, true},
        {20, "DAMAR", "Agathis dammara", "LC - Risiko Rendah", "Maluku & Sulawesi", "2001", 600, false}
    };

    int n = sizeof(temp) / sizeof(temp[0]);

    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }

    ukuran = n; 
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

void clearScreen() {
    system("clear"); 
    system("cls");
}

// NOTE : Prosedur & Fungsi Untuk User
void lihatEntri(KebunRaya *ptrEntri, int jumlahEntri) {
    if (jumlahEntri == 0) {
        cout << "=> Tidak ada Entri yang tersimpan" << endl; 
        system("pause");
        return;
    }
    
    int pilihan, indeksEntriSekarang;
    bool entriDitemukan;
    do {
        clearScreen();
        entriDitemukan = false;
        cout << "=== ENTRI YANG ADA DI DATABASE ==========================" << endl; 
        cout << "ID| Nama Umum | Tipe Entri | Skala Konservasi | Jumlah Entri" << endl;
        for (int i = 0; i < jumlahEntri; i++) {  
                string tipeEntri = (!(ptrEntri + i) -> klasifikasi) ? "Flora" : "Fauna"; 
                
                if (i % 5 == 0 && i != 0) {
                    cout << "------------------------------------------------------" << endl;
                }

                cout << ptrEntri[i].entriID 
                    << " | " << ptrEntri[i].namaUmum
                    << " | " << tipeEntri
                    << " | " << ptrEntri[i].skalaKonservasi
                    << " | " << ptrEntri[i].jumlah
                    << endl;
        }
        cout << "------------------------------------------------------" << endl;
        cout << "[0] Keluar" << endl;
        cout << "------------------------------------------------------" << endl;
        cout << "Pilih ID yang Ingin Anda Lihat" << endl; 
        cout << "> "; cin >> pilihan; 

        pilihan = errorHandling(pilihan); 
        if (pilihan == 0) {
            break; 
        }

        for (int i = 0; i < jumlahEntri; i++) {
            if (pilihan == (ptrEntri + i) -> entriID) { 
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
        
        clearScreen();
        string tipeEntri = (ptrEntri[indeksEntriSekarang].klasifikasi == false) ? "Flora" : "Fauna";
        cout << "=== DATA ENTRI YANG DIPILIH =====================" << endl;
        cout << "ID Entri          : " << ptrEntri[indeksEntriSekarang].entriID << endl;
        cout << "Nama Umum         : " << ptrEntri[indeksEntriSekarang].namaUmum << endl; 
        cout << "Nama Latin        : " << ptrEntri[indeksEntriSekarang].namaLatin << endl; 
        cout << "Tipe              : " << tipeEntri << endl; 
        cout << "Skala Konservasi  : " << ptrEntri[indeksEntriSekarang].skalaKonservasi << endl; 
        cout << "Habitat Asli      : " << ptrEntri[indeksEntriSekarang].habitatAsli << endl; 
        cout << "Tahun Masuk       : " << ptrEntri[indeksEntriSekarang].tahunMasuk << endl; 
        cout << "Jumlah            : " << ptrEntri[indeksEntriSekarang].jumlah << endl; 
        cout << "---------------------------------------------------------" << endl;
        system("pause");
        cout << "---------------------------------------------------------" << endl;
    }
}

void lihatEntriShort(KebunRaya *ptrEntri, int jumlahEntri) { 
    if (jumlahEntri == 0) {
        cout << "=> Tidak ada Entri yang tersimpan" << endl; 
        system("pause");
        return;
    }
    
    cout << "=== DAFTAR SINGKAT ENTRI ================================" << endl;
    cout << "ID| Nama Umum | Tipe Entri | Skala Konservasi | Jumlah Entri" << endl;
    for (int i = 0; i < jumlahEntri; i++) {  
            string tipeEntri = (!(ptrEntri + i) -> klasifikasi) ? "Flora" : "Fauna"; 
            
            if (i % 5 == 0 && i != 0) {
                cout << "------------------------------------------------------" << endl;
            }

            cout << ptrEntri[i].entriID
                << " | " << ptrEntri[i].namaUmum
                << " | " << tipeEntri
                << " | " << ptrEntri[i].skalaKonservasi
                << " | " << ptrEntri[i].jumlah
                << endl;
    } 
}

void tambahEntri(KebunRaya *ptrEntri, int &jumlahEntri) {
    int pilihan;
    bool lanjut = false;
    
    do {
        lanjut = false;

        clearScreen();
        if (jumlahEntri >= MAXENTRI) {
            cout << "=> Data Entri sudah penuh!" << endl; 
            cout << "---------------------------------------------------------" << endl; 
            system("pause");
            cout << "---------------------------------------------------------" << endl;
            break;
        }
        
        cout << "=== BUAT ENTRI BARU =====================================" << endl; 
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

        ptrEntri[jumlahEntri].klasifikasi = pilihan - 1;

        while (true) {
            clearScreen();
            cout << "=== PILIH SKALA KONSERVASI ==============================" << endl; 
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

            for (int i = 0; i < ukuranSkala + 1; i++) {
                if (pilihan == i) {
                    ptrEntri[jumlahEntri].skalaKonservasi = skalaKonservasi[i - 1];
                    break; 
                }
            }

            string inputNamaUmum, inputNamaLatin, inputHabitat, inputTahunMasuk; 
            int inputJumlah;

            while (true) {
                string tipeEntri = (ptrEntri[jumlahEntri].klasifikasi == false) ? "Flora" : "Fauna";
                clearScreen();
                cout << "=== ENTRI BARU =========================================" << endl;
                cout << "Tipe Entri        : " << tipeEntri << endl; 
                cout << "Skala Konservasi  : " << ptrEntri[jumlahEntri].skalaKonservasi << endl;
                cout << "---------------------------------------------------------" << endl;
                
                cout << "Masukkan Nama Umum               : "; getline(cin, inputNamaUmum);
                if (inputNamaUmum.length() == 0) {
                    cout << "=> Nama Umum Tidak Boleh Kosong" << endl; 
                    clearScreen();
                    continue;
                }

                cout << "Masukkan Nama Latin              : "; getline(cin, inputNamaLatin); 
                if (inputNamaLatin.length() == 0) {
                    cout << "=> Nama Latin Tidak Boleh Kosong!" << endl;
                    clearScreen();
                    continue; 
                }
                
                cout << "Masukkan Habitat Asli            : "; getline(cin, inputHabitat);
                if (inputHabitat.length() == 0) {
                    cout << "=> Habitat Tidak Boleh Kosong!" << endl; 
                    clearScreen();
                    continue;
                }

                cout << "Masukkan Tahun Masuk Kebun Raya  : "; getline(cin, inputTahunMasuk);
                if (inputTahunMasuk.length() == 0) {
                    cout << "=> Tahun Masuk Tidak Boleh Kosong!" << endl; 
                    clearScreen();
                    continue;
                }

                break;
            }
            
            cout << "Masukkan Jumlah Spesimen         : "; cin >> inputJumlah;

            for (int i = 0; i < inputNamaUmum.length(); i++) {
                inputNamaUmum[i] = toupper(inputNamaUmum[i]);
            }

            ptrEntri[jumlahEntri].entriID = uniqueEntri + 1;
            ptrEntri[jumlahEntri].namaUmum = inputNamaUmum;
            ptrEntri[jumlahEntri].namaLatin = inputNamaLatin; 
            ptrEntri[jumlahEntri].habitatAsli = inputHabitat;
            ptrEntri[jumlahEntri].tahunMasuk = inputTahunMasuk;
            ptrEntri[jumlahEntri].jumlah = inputJumlah;
            jumlahEntri++; uniqueEntri++;

            cout << "---------------------------------------------------------" << endl;
            cout << "=> Entri berhasil ditambahkan" << endl;
            system("pause");
            cout << "---------------------------------------------------------" << endl;
            break;
        }
    }
}

void updateEntri(KebunRaya *ptrEntri, int jumlahEntri) {
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
        clearScreen();
        indeksEntriSekarang = -1;
        entriDitemukan = false;
        cout << "=== PERBARUI ENTRI ======================================" << endl; 
        lihatEntriShort(entri, jumlahEntri);
        cout << "---------------------------------------------------------" << endl;
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
            if (pilihan == (ptrEntri + i) -> entriID) { 
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
            clearScreen();
            string tipeEntri = (ptrEntri[indeksEntriSekarang].klasifikasi == false) ? "Flora" : "Fauna";
            cout << "=== DATA ENTRI YANG AKAN DIPERBARUI =====================" << endl;
            cout << "[1] Nama Umum         : " << ptrEntri[indeksEntriSekarang].namaUmum << endl; 
            cout << "[2] Nama Latin        : " << ptrEntri[indeksEntriSekarang].namaLatin << endl; 
            cout << "[3] Tipe              : " << tipeEntri << endl; 
            cout << "[4] Skala Konservasi  : " << ptrEntri[indeksEntriSekarang].skalaKonservasi << endl; 
            cout << "[5] Habitat Asli      : " << ptrEntri[indeksEntriSekarang].habitatAsli << endl; 
            cout << "[6] Tahun Masuk       : " << ptrEntri[indeksEntriSekarang].tahunMasuk << endl; 
            cout << "[7] Jumlah            : " << ptrEntri[indeksEntriSekarang].jumlah << endl; 
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
                clearScreen();
                cout << "=> Edit Nama Umum" << endl;
                cout << "Nama Sebelumnya : " << ptrEntri[indeksEntriSekarang].namaUmum << endl; 
                cout << "Nama Baru       : "; getline(cin, inputNamaUmum);
                cout << "---------------------------------------------------------" << endl;
                cout << "=> Nama Umum Berhasil diganti" << endl; 
                cout << "---------------------------------------------------------" << endl; 
                
                if (inputNamaUmum.length() == 0) {
                    inputNamaUmum = ptrEntri[indeksEntriSekarang].namaUmum;
                }

                for (int i = 0; i < inputNamaUmum.length(); i++) {
                    inputNamaUmum[i] = toupper(inputNamaUmum[i]);
                }

                ptrEntri[indeksEntriSekarang].namaUmum = inputNamaUmum;
                break;

                case 2: 
                clearScreen();
                cout << "=> Edit Nama Latin" << endl;
                cout << "Nama Sebelumnya : " << ptrEntri[indeksEntriSekarang].namaLatin << endl; 
                cout << "Nama Baru       : "; getline(cin, inputNamaLatin);
                cout << "---------------------------------------------------------" << endl;
                cout << "=> Nama Latin Berhasil Diganti" << endl;
                cout << "---------------------------------------------------------" << endl;

                if (inputNamaLatin.length() == 0) {
                    inputNamaLatin = ptrEntri[indeksEntriSekarang].namaLatin;
                }

                ptrEntri[indeksEntriSekarang].namaLatin = inputNamaLatin;
                break; 

                case 3: 
                keluar = false;
                while (!keluar) {
                    clearScreen();
                    cout << "=== EDIT TIPE ENTRI =====================================" << endl; 
                    string tipeEntri = (ptrEntri[indeksEntriSekarang].klasifikasi == false) ? "Flora" : "Fauna";
                    
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
                        ptrEntri[indeksEntriSekarang].klasifikasi = false; 
                        keluar = true;
                        cout << "---------------------------------------------------------" << endl;
                        break;

                        case 2: 
                        cout << "=> Mengganti tipe entri menjadi 'Fauna'" << endl; 
                        ptrEntri[indeksEntriSekarang].klasifikasi = true; 
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
                    clearScreen();
                    cout << "=== EDIT SKALA KONSERVASI ===============================" << endl;
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

                    for (int i = 0; i < ukuranSkala + 1; i++) {
                        if (pilihan == i) {
                            ptrEntri[indeksEntriSekarang].skalaKonservasi = skalaKonservasi[i - 1];
                            break; 
                        }
                    }
                    break;
                } 
                break; 

                case 5: 
                clearScreen();
                cout << "=> Edit Habitat Asli" << endl; 
                cout << "Habitat Sebelumnya : " << ptrEntri[indeksEntriSekarang].habitatAsli << endl; 
                cout << "Habitat Baru       : "; getline(cin, inputHabitat); 
                cout << "---------------------------------------------------------" << endl;
                cout << "=> Habitat Berhasil diganti" << endl;
                cout << "---------------------------------------------------------" << endl;

                if (inputHabitat.length() == 0) {
                    inputHabitat = ptrEntri[indeksEntriSekarang].habitatAsli;
                }

                ptrEntri[indeksEntriSekarang].habitatAsli = inputHabitat; 
                break; 

                case 6: 
                clearScreen();
                cout << "=> Edit Tahun Masuk" << endl; 
                cout << "Tahun Sebelumnya : " << ptrEntri[indeksEntriSekarang].tahunMasuk << endl;
                cout << "Tahun Baru       : "; getline(cin, inputTahunMasuk);
                cout << "---------------------------------------------------------" << endl;
                cout << "=> Tahun Berhasil Diubah" << endl;
                cout << "---------------------------------------------------------" << endl;

                if (inputTahunMasuk.length() == 0) {
                    inputTahunMasuk = ptrEntri[indeksEntriSekarang].tahunMasuk;
                }

                ptrEntri[indeksEntriSekarang].tahunMasuk = inputTahunMasuk; 
                break; 

                case 7: 
                clearScreen();
                cout << "=> Edit Jumlah" << endl; 
                cout << "Jumlah Sebelumnya : " << ptrEntri[indeksEntriSekarang].jumlah << endl;
                cout << "Jumlah Baru       : "; cin >> inputJumlah;
                cout << "---------------------------------------------------------" << endl;
                cout << "=> Jumlah Spesimen Berhasil Diubah" << endl;
                cout << "---------------------------------------------------------" << endl;

                ptrEntri[indeksEntriSekarang].jumlah = inputJumlah; 
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

void hapusEntri(KebunRaya *ptrEntri, int &jumlahEntri) {
    int pilihan, indeksEntriSekarang;
    bool entriDitemukan;

    do {
        clearScreen();
        entriDitemukan = false;
        cout << "=== HAPUS ENTRI =========================================" << endl; 
        lihatEntriShort(entri, jumlahEntri); 
        cout << "---------------------------------------------------------" << endl;
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
            if (pilihan == (ptrEntri + i) -> entriID) {
                cout << "=> Entri ditemukan" << endl;
                entriDitemukan = true;
                indeksEntriSekarang = i;
                cout << "---------------------------------------------------------" << endl;
                break;
            }
        }

        if (entriDitemukan) {
            while (true) {
                clearScreen();
                string tipeEntri = (ptrEntri[indeksEntriSekarang].klasifikasi == false) ? "Flora" : "Fauna";
                cout << "=== KONFIRMASI HAPUS ENTRI ==============================" << endl;
                cout << "Nama Umum         : " << ptrEntri[indeksEntriSekarang].namaUmum << endl; 
                cout << "Nama Latin        : " << ptrEntri[indeksEntriSekarang].namaLatin << endl; 
                cout << "Tipe              : " << tipeEntri << endl; 
                cout << "Skala Konservasi  : " << ptrEntri[indeksEntriSekarang].skalaKonservasi << endl; 
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
                        ptrEntri[i] = ptrEntri[i + 1]; 
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

// NOTE : Prosedur & Fungsi untuk Admin
void lihatUser(Pengguna *ptrAkun, int jumlahPengguna) {
    clearScreen();
    cout << "=== AKUN YANG ADA DI DATABASE ===========================" << endl; 
    for (int i = 0; i < jumlahPengguna; i++) {
        string privilese = ((ptrAkun + i) -> isAdmin) ? "Admin" : "Member";  

        cout << "[Akun ke-" << i + 1 << "]" << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << "User ID   : " << (ptrAkun + i) -> userID << endl;
        cout << "Username  : " << (ptrAkun + i) -> username << endl;
        cout << "Password  : " << (ptrAkun + i) -> password << endl;
        cout << "Role      : " << privilese << endl; 
        cout << "---------------------------------------------------------" << endl;
    } 

    system("pause");
    cout << "---------------------------------------------------------" << endl;
}

void lihatUserShort(Pengguna *ptrAkun, int jumlahPengguna) {
    cout << "=== DAFTAR SINGKAT USER ================================" << endl;
    for (int i = 0; i < jumlahPengguna; i++) {
        string privilese = ((ptrAkun + i) -> isAdmin) ? "Admin" : "Member"; 
        cout << "---------------------------------------------------------" << endl;
        cout << "User ID   : " << (ptrAkun + i) -> userID << endl;
        cout << "Username  : " << (ptrAkun + i) -> username << endl;
        cout << "Role      : " << privilese << endl; 
        cout << "---------------------------------------------------------" << endl;
    } 
}

void perbaruiUser(Pengguna *ptrAkun, int jumlahPengguna) {
    int pilihan, indeksUserSekarang; 
    string updateUsername, updatePassword;
    bool akunDitemukan; 

    do {
        clearScreen();
        akunDitemukan = false;
        cout << "=== PERBARUI USER =======================================" << endl;
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
            if (pilihan == (ptrAkun + i) -> userID) { 
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
            clearScreen();
            string privilese = (ptrAkun[indeksUserSekarang].isAdmin == true) ? "Admin" : "Member"; 
            cout << "=== AKUN YANG AKAN DIPERBARUI ===========================" << endl; 
            cout << "[1] Username  : " << ptrAkun[indeksUserSekarang].username << endl; 
            cout << "[2] Password  : " << ptrAkun[indeksUserSekarang].password << endl;
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
                clearScreen();
                cout << "=> Mengganti Username" << endl;
                cout << "Username Lama : " << ptrAkun[indeksUserSekarang].username << endl; 
                cout << "Username Baru : "; getline(cin, updateUsername);
                cout << "---------------------------------------------------------" << endl;
                cout << "=> Username Berhasil Diubah" << endl;
                cout << "---------------------------------------------------------" << endl; 
                
                if (updateUsername.length() == 0) {
                    updateUsername = ptrAkun[indeksUserSekarang].username; 
                }

                ptrAkun[indeksUserSekarang].username = updateUsername;
            } 
            else if (pilihan == 2) {
                cin.ignore();
                clearScreen();
                cout << "=> Mengganti Password" << endl;
                cout << "Password Lama : " << ptrAkun[indeksUserSekarang].password << endl;
                cout << "Password Baru : "; getline(cin, updatePassword);
                cout << "---------------------------------------------------------" << endl;
                cout << "=> Password Berhasil Diubah" << endl;
                cout << "---------------------------------------------------------" << endl;

                if (updatePassword.length() == 0) {
                    updatePassword = ptrAkun[indeksUserSekarang].password;
                }

                ptrAkun[indeksUserSekarang].password = updatePassword;
            }
            else if (pilihan == 3) {
                while (true) {
                    clearScreen();
                    cout << "=== GANTI ROLE USER =====================================" << endl;
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
                        ptrAkun[indeksUserSekarang].isAdmin = true; 
                        break;
                    }
                    else if (pilihan == 2) {
                        cout << "=> Mengganti role menjadi 'Member'" << endl;
                        cout << "---------------------------------------------------------" << endl; 
                        ptrAkun[indeksUserSekarang].isAdmin = false; 
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

void hapusUser(Pengguna *ptrAkun, int &jumlahPengguna) {
    int pilihan, indeksUserSekarang; 
    bool akunDitemukan; 

    do {
        clearScreen();
        akunDitemukan = false;
        cout << "=== HAPUS PENGGUNA ======================================" << endl; 
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
            if (pilihan == (ptrAkun + i) -> userID) { 
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
            clearScreen();
            string privilese = (ptrAkun[indeksUserSekarang].isAdmin == true) ? "Admin" : "Member";
            cout << "=== KONFIRMASI HAPUS USER ===============================" << endl; 
            cout << "User ID   : " << ptrAkun[indeksUserSekarang].userID << endl; 
            cout << "Username  : " << ptrAkun[indeksUserSekarang].username << endl; 
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
                    ptrAkun[i] = ptrAkun[i + 1]; 
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

int regis(Pengguna *ptrAkun, int &jumlahPengguna) {
    string username, password;
    bool usernameValid = true;

    cin.ignore();
    do {
        usernameValid = true;
        if (jumlahPengguna >= MAXPENGGUNA) {
            cout << "=> Data Pengguna Sudah Penuh!" << endl; 
            cout << "---------------------------------------------------------" << endl;
            system("Pause");
            cout << "---------------------------------------------------------" << endl;
            return 0;
        }
        
        clearScreen();
        cout << "=== MENU REGISTER =======================================" << endl;
        cout << "Masukkan Username" << endl;
        cout << "> "; getline(cin, username);
        cout << "---------------------------------------------------------" << endl;

        if (username.length() == 0) {
            cout << "=> Username Tidak Boleh Kosong!" << endl;
            system("pause"); 
            usernameValid = false;
        }

        for (int i = 0; i < jumlahPengguna; i++) {
            if (username == (ptrAkun + i) -> username) { 
                cout << "=> Username sudah digunakan. Silakan masukkan username lain" << endl;
                system("pause");
                cout << "---------------------------------------------------------" << endl;
                usernameValid = false; 
                break;
            }
        }
    } while (!usernameValid);

    bool passwordValid = false;
    do {
        passwordValid = true;
        cout << "Masukkan Password" << endl; 
        cout << "> "; getline(cin, password); 
        cout << "---------------------------------------------------------" << endl;

        if (password.length() == 0) {
            cout << "=> Password Tidak Boleh Kosong!" << endl; 
            passwordValid = false;
            system("pause");
            cout << "---------------------------------------------------------" << endl;
        }
    } while (!passwordValid);

    ptrAkun[jumlahPengguna].userID = uniqueUser + 1; 
    ptrAkun[jumlahPengguna].username = username; 
    ptrAkun[jumlahPengguna].password = password; 
    ptrAkun[jumlahPengguna].isAdmin = false;
    jumlahPengguna++; uniqueUser++;

    cout << "=> Register berhasil" << endl;
    system("pause");
    cout << "---------------------------------------------------------" << endl;
    return jumlahPengguna;
}

int login(Pengguna *ptrAkun, int jumlahPengguna) {
    string username, password;
    bool akunDitemukan, passwordBenar = false;
    int indeksUser;
    int kesempatan = 3;

    cin.ignore();
    do {
        indeksUser = -1;
        akunDitemukan = false;
        
        clearScreen();
        cout << "=== MENU LOGIN ==========================================" << endl; 
        cout << "Masukkan Username Anda" << endl; 
        cout << "> "; getline(cin, username); 
        cout << "---------------------------------------------------------" << endl;

        for (int i = 0; i < jumlahPengguna; i++) {
            if (username == (ptrAkun + i) -> username) { 
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
        system("pause");
        cout << "---------------------------------------------------------" << endl;
        return indeksUser;
    } 
    else {
        cout << "=> Login gagal" << endl;
        cout << "---------------------------------------------------------" << endl;
        return -1;
    }
}

// NOTE: Sort Menggunakan Insertion Sort Secara Ascending
void sortNamaUmum(KebunRaya arr[], int n) {
    for (int i = 1; i < n; i++) {
        KebunRaya key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j].namaUmum > key.namaUmum) {
            arr[j + 1] = arr[j]; 
            j--;
        }
        arr[j + 1] = key;
    }
}

// NOTE: Sort Jumlah Spesimen Menggunakan Bubble Sort Secara Descending
void sortJumlah(KebunRaya *ptrArray, int jumlahEntri) {
    for (int i = 0; i < jumlahEntri - 1; i++) {
        for (int j = 0; j < jumlahEntri - i - 1; j++) {
            if ((ptrArray + j) -> jumlah < (ptrArray + j + 1) -> jumlah) {
                KebunRaya tukar = *(ptrArray + j);
                *(ptrArray + j) = *(ptrArray + j + 1);
                *(ptrArray + j + 1) = tukar;
            }
        }
    }    
}

// NOTE: Sort ID Entri Menggunakan Selection Sort Secara Ascending
void sortID (KebunRaya *ptrArray, int jumlahEntri) {
    for (int i = 0; i < jumlahEntri - 1; i++) {
        int indeksMin = i; 

        for (int j = i + 1; j < jumlahEntri; j++) {
            if ((ptrArray + j) -> entriID < (ptrArray + indeksMin) -> entriID) {
                indeksMin = j; 
            }
        }

        if (indeksMin != i) {
            KebunRaya tukar = *(ptrArray + i); 
            *(ptrArray + i) = *(ptrArray + indeksMin); 
            *(ptrArray + indeksMin) = tukar; 
        }
    }
}

void menuSort(KebunRaya *ptrEntri, int jumlahEntri) {
    int pilihan; 

    do {
        clearScreen();
        cout << "=== URUTKAN ENTRI ================================" << endl; 
        cout << "Urutkan Data Berdasarkan:" << endl;
        cout << "--------------------------------------------------" << endl; 
        cout << "[1] ID Entri" << endl;
        cout << "[2] Nama Umum" << endl; 
        cout << "[3] Jumlah Entri" << endl; 
        cout << "--------------------------------------------------" << endl;
        cout << "[0] Keluar" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << "Masukkan Pilihan Anda" << endl; 
        cout << "> "; cin >> pilihan; 
        cout << "--------------------------------------------------" << endl;

        pilihan = errorHandling(pilihan);
        clearScreen(); 
        if (pilihan == 0) {
            break; 
        }
        else if (pilihan == 1) {
            cout << "=> Mengurutkan Berdasarkan ID Entri" << endl;
            cout << "--------------------------------------------------" << endl;
            sortID(ptrEntri, jumlahEntri); 
            cout << "=> Data Setelah di Sort" << endl;
            cout << "--------------------------------------------------" << endl;
            lihatEntriShort(ptrEntri, jumlahEntri); 
            cout << "--------------------------------------------------" << endl;
            system("pause");   
        }
        else if (pilihan == 2) {
            cout << "=> Mengurutkan Berdasarkan Nama Umum" << endl; 
            cout << "--------------------------------------------------" << endl;
            sortNamaUmum(ptrEntri, jumlahEntri); 
            cout << "=> Data Setelah di Sort" << endl;
            cout << "--------------------------------------------------" << endl;
            lihatEntriShort(ptrEntri, jumlahEntri);
            cout << "--------------------------------------------------" << endl;
            system("pause");
        }
        else if (pilihan == 3) {
            cout << "=> Mengurutkan Berdasarkan Jumlah Entri" << endl; 
            cout << "--------------------------------------------------" << endl;
            sortJumlah(ptrEntri, jumlahEntri); 
            cout << "=> Data Setelah di Sort" << endl; 
            cout << "--------------------------------------------------" << endl;
            lihatEntriShort(ptrEntri, jumlahEntri);
            cout << "--------------------------------------------------" << endl;
            system("pause");
        }
        else {
            cout << "=> Pilihan Tidak Valid" << endl;
        }

    } while (pilihan != 0);
}

// NOTE: Search Nama Umum menggunakan Linear Search
int searchNamaUmum(KebunRaya *ptrArray, int jumlahEntri) {
    string cariNama; 
    
    cin.ignore();
    cout << "Masukkan Nama Entri yang ingin dicari" << endl;
    cout << "> "; getline(cin, cariNama); 
    cout << "---------------------------------------------------------" << endl;
 
    for (int i = 0; i < cariNama.length(); i++) {
        cariNama[i] = toupper(cariNama[i]);
    }
 
    for (int i = 0; i < jumlahEntri; i++) {
        if (cariNama == (ptrArray + i) -> namaUmum)
            return i;
    }
    return -1;
}

// NOTE: Search ID Entri menggunakan Binary Search
int searchEntriID(KebunRaya *ptrArray, int jumlahEntri) {
    sortID(ptrArray, jumlahEntri);
    int targetID; 

    int left = 0; 
    int right = jumlahEntri - 1; 

    cout << "Masukkan ID Entri yang ingin dicari" << endl;
    cout << "> "; cin >> targetID;  
    cout << "---------------------------------------------------------" << endl;

    targetID = errorHandling(targetID); 

    while (left <= right) {
        int mid = left + (right - left) / 2; 

        if (ptrArray[mid].entriID == targetID) {
            return mid; 
        }
        else if (ptrArray[mid].entriID > targetID) {
            right = mid - 1; 
        }
        else {
            left = mid + 1; 
        }
    }

    return -1;
}

void menuSearch(KebunRaya *ptrEntri, int jumlahEntri) {
    int pilihan; 

    do {
        clearScreen();
        cout << "=== CARI ENTRI TERTENTU ================================" << endl; 
        cout << "Cari Entri Berdasarkan:" << endl;
        cout << "--------------------------------------------------------" << endl; 
        cout << "[1] ID Entri" << endl;
        cout << "[2] Nama Umum" << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << "[0] Keluar" << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << "Masukkan Pilihan Anda" << endl; 
        cout << "> "; cin >> pilihan; 
        cout << "--------------------------------------------------------" << endl;

        pilihan = errorHandling(pilihan);
        clearScreen();
        
        if (pilihan == 0) {
            break; 
        }
        else if (pilihan == 1) {
            cout << "=> Mencari Berdasarkan 'ID Entri'" << endl; 
            cout << "---------------------------------------------------------" << endl;

            int indeksHasil = searchEntriID(ptrEntri, jumlahEntri); 

            if (indeksHasil < 0) {
                cout << "=> Entri tidak ditemukan!" << endl; 
                cout << "---------------------------------------------------------" << endl;
                system("pause");
                cout << "---------------------------------------------------------" << endl;
            }
            else {
                string tipeEntri = (ptrEntri[indeksHasil].klasifikasi == false) ? "Flora" : "Fauna";

                // clearScreen();
                cout << "---------------------------------------------------------" << endl;
                cout << "=== HASIL PENCARIAN =====================================" << endl;
                cout << "ID Entri          : " << ptrEntri[indeksHasil].entriID << endl;
                cout << "Nama Umum         : " << ptrEntri[indeksHasil].namaUmum << endl; 
                cout << "Nama Latin        : " << ptrEntri[indeksHasil].namaLatin << endl; 
                cout << "Tipe              : " << tipeEntri << endl; 
                cout << "Skala Konservasi  : " << ptrEntri[indeksHasil].skalaKonservasi << endl; 
                cout << "Habitat Asli      : " << ptrEntri[indeksHasil].habitatAsli << endl; 
                cout << "Tahun Masuk       : " << ptrEntri[indeksHasil].tahunMasuk << endl; 
                cout << "Jumlah            : " << ptrEntri[indeksHasil].jumlah << endl; 
                cout << "---------------------------------------------------------" << endl;
                system("pause");
                cout << "---------------------------------------------------------" << endl;
            }   
        }
        else if (pilihan == 2) {
            cout << "=> Mencari Berdasarkan 'Nama Umum'" << endl; 
            cout << "---------------------------------------------------------" << endl;
 
            int indeksHasil = searchNamaUmum(ptrEntri, jumlahEntri); 
            if (indeksHasil < 0) {
                cout << "=> Entri tidak Ditemukan" << endl;
                cout << "---------------------------------------------------------" << endl;
                system("pause"); 
                cout << "---------------------------------------------------------" << endl;
            } else {
                string tipeEntri = (ptrEntri[indeksHasil].klasifikasi == false) ? "Flora" : "Fauna";

                // clearScreen();
                cout << "---------------------------------------------------------" << endl;
                cout << "=== HASIL PENCARIAN =====================================" << endl;
                cout << "ID Entri          : " << ptrEntri[indeksHasil].entriID << endl;
                cout << "Nama Umum         : " << ptrEntri[indeksHasil].namaUmum << endl; 
                cout << "Nama Latin        : " << ptrEntri[indeksHasil].namaLatin << endl; 
                cout << "Tipe              : " << tipeEntri << endl; 
                cout << "Skala Konservasi  : " << ptrEntri[indeksHasil].skalaKonservasi << endl; 
                cout << "Habitat Asli      : " << ptrEntri[indeksHasil].habitatAsli << endl; 
                cout << "Tahun Masuk       : " << ptrEntri[indeksHasil].tahunMasuk << endl; 
                cout << "Jumlah            : " << ptrEntri[indeksHasil].jumlah << endl; 
                cout << "---------------------------------------------------------" << endl;
                system("pause");
                cout << "---------------------------------------------------------" << endl;
            }
        }
        else {
            cout << "=> Pilihan Tidak Valid" << endl;
        }
    } while (pilihan != 0);
}

void menuAdmin(int indeksUser, KebunRaya *ptrEntri) {
    int pilihan;
    
    do {
        clearScreen();
        cout << "==== MENU ADMIN =========================================" << endl;
        cout << "Selamat Datang Kembali, Admin " << akun[indeksUser].username << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << "[MENU MANAJEMEN ENTRI]" << endl;
        cout << "[1] Buat Entri Baru" << endl; 
        cout << "[2] Lihat Entri" << endl; 
        cout << "[3] Perbarui Entri" << endl; 
        cout << "[4] Hapus Entri" << endl; 
        cout << "[5] Urutkan Entri" << endl;
        cout << "[6] Cari Entri Tertentu" << endl; 
        cout << "---------------------------------------------------------" << endl;
        cout << "[MENU MANAJEMEN USER]" << endl;
        cout << "[7] Buat User Baru" << endl; 
        cout << "[8] Lihat User" << endl; 
        cout << "[9] Perbarui User" << endl; 
        cout << "[10] Hapus User" << endl; 
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
            tambahEntri(ptrEntri, jumlahEntri); 
            break;

            case 2: 
            cout << "=> Mengarahkan ke menu 'Lihat Entri'" << endl;  
            cout << "---------------------------------------------------------" << endl;
            lihatEntri(ptrEntri, jumlahEntri);
            break;

            case 3:
            cout << "=> Mengarahkan ke menu 'Perbarui Entri'" << endl;
            cout << "---------------------------------------------------------" << endl;
            updateEntri(ptrEntri, jumlahEntri); 
            break;

            case 4: 
            cout << "=> Mengarahkan ke menu 'Hapus Entri'" << endl;
            cout << "---------------------------------------------------------" << endl;
            hapusEntri(ptrEntri, jumlahEntri); 
            break;

            case 6: 
            cout << "=> Mengarahkan ke menu 'Cari Entri Tertentu'" << endl; 
            cout << "---------------------------------------------------------" << endl;
            menuSearch(ptrEntri, jumlahEntri);
            break;

            case 5: 
            cout << "=> Mengarahkan ke menu 'Urutkan Entri'" << endl; 
            cout << "---------------------------------------------------------" << endl;
            menuSort(ptrEntri, jumlahEntri);
            break;
            
            case 7: 
            cout << "=> Mengarahkan ke menu 'Buat User'" << endl;
            cout << "---------------------------------------------------------" << endl;
            regis(akun, jumlahPengguna); 
            break;

            case 8: 
            cout << "=> Mengarahkan ke menu 'Lihat User'" << endl; 
            cout << "---------------------------------------------------------" << endl;
            lihatUser(akun, jumlahPengguna);
            break; 

            case 9: 
            cout << "=> Mengarahkan ke menu 'Perbarui User'" << endl; 
            cout << "---------------------------------------------------------" << endl;
            perbaruiUser(akun, jumlahPengguna);
            break; 

            case 10: 
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

void menuUser(int indeksUser, KebunRaya *ptrEntri) {
    int pilihan;
    
    do {
        clearScreen();
        cout << "==== MENU USER ==========================================" << endl;
        cout << "Selamat Datang Kembali, " << akun[indeksUser].username << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << "[1] Buat Entri Baru" << endl; 
        cout << "[2] Lihat Entri" << endl; 
        cout << "[3] Perbarui Entri" << endl; 
        cout << "[4] Hapus Entri" << endl; 
        cout << "[5] Urutkan Entri" << endl;
        cout << "[6] Cari Entri Tertentu" << endl; 
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
            tambahEntri(ptrEntri, jumlahEntri); 
            break;

            case 2: 
            cout << "=> Mengarahkan ke menu 'Lihat Entri'" << endl;  
            cout << "---------------------------------------------------------" << endl;
            lihatEntri(ptrEntri, jumlahEntri);
            break;

            case 3:
            cout << "=> Mengarahkan ke menu 'Perbarui Entri'" << endl;
            cout << "---------------------------------------------------------" << endl;
            updateEntri(ptrEntri, jumlahEntri); 
            break;

            case 4: 
            cout << "=> Mengarahkan ke menu 'Hapus Entri'" << endl;
            cout << "---------------------------------------------------------" << endl;
            hapusEntri(ptrEntri, jumlahEntri); 
            break; 

            case 5: 
            cout << "=> Mengarahkan ke menu 'Sort Entri'" << endl;
            cout << "---------------------------------------------------------" << endl;
            menuSort(ptrEntri, jumlahEntri); 
            break; 

            case 6: 
            cout << "=> Mengarahkan ke menu 'Cari Entri Tertentu'" << endl; 
            cout << "---------------------------------------------------------" << endl;
            menuSearch(ptrEntri, jumlahEntri);
            break;

            default: 
            cout << "=> Pilihan tidak valid, coba lagi" << endl; 
            cout << "---------------------------------------------------------" << endl;
            break;
        }
    } while (pilihan != 0);
}

void menuUtama(Pengguna *ptrAkun, KebunRaya *entri) {
    int pilihan;
    int indeksUser;

    do {
        clearScreen();
        cout << "==== SISTEM MANAJEMEN KEBUN RAYA ========================" << endl;
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
                if ((ptrAkun + indeksUser) -> isAdmin) { 
                    menuAdmin(indeksUser, entri);
                } 
                else {
                    menuUser(indeksUser, entri);
                }
            } 
            else {
                cout << "=> Keluar dari program" << endl;
                clearScreen();
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

    addEntriDummy(entri, jumlahEntri);
    menuUtama(akun, entri);
    return 0;
}