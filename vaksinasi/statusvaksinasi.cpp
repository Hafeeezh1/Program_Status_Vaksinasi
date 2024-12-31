#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Enumerasi untuk jenis vaksin
enum JenisVaksin {
    COVID19,
    INFLUENZA,
    HEPATITIS,
    DTP,
    BCG,
    TYPHOID
};

// Fungsi untuk mengubah nilai enum menjadi string
string jenisVaksinToString(JenisVaksin vaksin) {
    switch (vaksin) {
        case COVID19: return "COVID-19";
        case INFLUENZA: return "Influenza";
        case HEPATITIS: return "Hepatitis";
        case DTP: return "DTP (Difteri, Tetanus, Pertusis)";
        case BCG: return "BCG (Tuberkulosis)";
        case TYPHOID: return "Typhoid";
        default: return "Unknown";
    }
}

// Struktur untuk menyimpan data pasien
struct Pasien {
    int idPasien;
    string nama;
    bool statusVaksinasi; // true jika sudah divaksin, false jika belum
    JenisVaksin vaksin;    // Jenis vaksin yang diterima pasien
};

// Fungsi untuk menampilkan data pasien
void tampilkanDataPasien(const vector<Pasien>& pasienList) {
    cout << "\nDaftar Pasien dan Status Vaksinasi:\n";
    cout << "-----------------------------------\n";
    for (const auto& pasien : pasienList) {
        cout << "ID Pasien: " << pasien.idPasien << endl;
        cout << "Nama: " << pasien.nama << endl;
        cout << "Status Vaksinasi: " << (pasien.statusVaksinasi ? "Sudah Vaksin" : "Belum Vaksin") << endl;
        cout << "Jenis Vaksin: " << jenisVaksinToString(pasien.vaksin) << endl;
        cout << "-----------------------------------\n";
    }
}

// Fungsi untuk menambahkan data pasien
void tambahPasien(vector<Pasien>& pasienList, int id, const string& nama, bool statusVaksinasi, JenisVaksin vaksin) {
    Pasien pasienBaru = {id, nama, statusVaksinasi, vaksin};
    pasienList.push_back(pasienBaru);
}

// Fungsi untuk verifikasi status vaksinasi
void verifikasiStatusVaksinasi(const vector<Pasien>& pasienList, int id) {
    bool ditemukan = false;
    for (const auto& pasien : pasienList) {
        if (pasien.idPasien == id) {
            cout << "\nVerifikasi Status Vaksinasi Pasien (ID: " << id << "):\n";
            cout << "Nama: " << pasien.nama << endl;
            cout << "Status Vaksinasi: " << (pasien.statusVaksinasi ? "Sudah Vaksin" : "Belum Vaksin") << endl;
            cout << "Jenis Vaksin: " << jenisVaksinToString(pasien.vaksin) << endl;
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan) {
        cout << "\nPasien dengan ID " << id << " tidak ditemukan.\n";
    }
}

int main() {
    vector<Pasien> pasienList;

    // Menambahkan beberapa data pasien sebagai contoh
    tambahPasien(pasienList, 101, "Ahmad", true, COVID19);
    tambahPasien(pasienList, 102, "Budi", false, INFLUENZA);
    tambahPasien(pasienList, 103, "Citra", true, HEPATITIS);

    // Menampilkan semua data pasien
    tampilkanDataPasien(pasienList);

    // Melakukan verifikasi status vaksinasi berdasarkan ID pasien
    int idVerifikasi;
    cout << "\nMasukkan ID pasien untuk verifikasi status vaksinasi: ";
    cin >> idVerifikasi;
    verifikasiStatusVaksinasi(pasienList, idVerifikasi);

    return 0;
}
