#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;

// Struktur data untuk produk
struct Produk {
    string nama;
    int harga;    
};

// Struktur data untuk struk belanja
struct StrukBelanja {
    string namaPelanggan;
    Produk daftarProduk[10]; // Maks 10
    int jumlahProduk; // jumlah produk yg dibeli
    int totalBelanja;
    int uangDibayarkan;
    int uangKembalian;
};

void printStrukBelanja(const StrukBelanja& struk) {
    cout << "Nama Pelanggan : " << struk.namaPelanggan << endl;
    cout << "Daftar Produk :" << endl;
    cout << left << setw(5) << "No" << setw(20) << "Nama Produk" << right<< setw(10) << "Harga" << endl;
    cout << "------------------------------------------" << endl;
    for (int i = 0; i < struk.jumlahProduk; i++) {
        Produk produk = struk.daftarProduk[i];
        cout << left << setw(5) << i + 1 << setw(20) << produk.nama << right << setw(10) << produk.harga << endl;
    }
    cout << "------------------------------------------" << endl;
    cout << "Total Belanja                 " << struk.totalBelanja << endl;
    cout << "Uang Dibayarkan               " << struk.uangDibayarkan << endl;
    cout << "Uang Kembalian                 " << struk.uangKembalian << endl;
}

int main() {
    //Nama & NIM
cout << "Nama : Clavino Ourizqi Rachmadi" << endl;
cout << "NIM : 41523010140" << endl;
cout << "Ujian Akhir Semester Pemrograman Lanjut" << endl;
cout << "Universitas Mercu Buana" << endl;
cout << " " << endl;
    Produk produk[] = {
        {"Sabun", 5000},
        {"Shampo", 7500},
        {"Susu", 10000},
        {"Mie Instan", 2500},
        {"Telur", 5000}
    };
    int jumlahProdukTersedia = sizeof(produk) / sizeof(Produk);
    cout << "Daftar Produk Tersedia : " << endl;
    cout << left << setw(5) << "ID" << setw(20) << "Nama Produk" << setw(10) << "Harga" << endl;
    for (int i = 0; i < jumlahProdukTersedia; i++) {
        cout << left << setw(5) << i + 1 << setw(20) << produk[i].nama << setw(10) << produk[i].harga << endl;
    }
    
    // Deklarasi queue untuk antrian pelanggan
    queue<string> antrianPelanggan;
    
    int jumlahPelanggan;
    cout << "Masukkan jumlah pelanggan : ";
    cin >> jumlahPelanggan;
    
    // Mengisi antrian pelanggan 
    for (int i = 0; i < jumlahPelanggan; i++) {
        string namaPelanggan;
        cout << "Masukkan Nama Pelanggan " << (i + 1) << ": ";
        cin >> namaPelanggan;
        antrianPelanggan.push(namaPelanggan); 
    }
    
    // Input daftar produk yang ingin dibeli
    int totalPendapatan = 0;
    while (!antrianPelanggan.empty()) {
        // ambil data pelanggan terdepan 
        StrukBelanja struk;
        struk.namaPelanggan = antrianPelanggan.front();
        antrianPelanggan.pop();
        
        // struk belanja untuk pelanggan
        struk.jumlahProduk = 0;
        struk.totalBelanja = 0;
        
        // Input daftar produk yang ingin dibeli
        int jumlahProduk;
        cout << "Nama Pelanggan: " << struk.namaPelanggan << endl;
        cout << "Masukkan jumlah produk yang ingin dibeli: ";
        cin >> jumlahProduk;
        
        for (int i = 0; jumlahProduk <= 10 && i < jumlahProduk; i++) {
            int idProduk;
            cout << "Masukkan ID produk " << (i + 1) << ": ";
            cin >> idProduk;
            
        
            // Cek ketersediaan produk
            if (idProduk >= 1 && idProduk <= jumlahProdukTersedia) {
                Produk produkBeli = produk[idProduk - 1];
                struk.daftarProduk[struk.jumlahProduk] = produkBeli;
                struk.jumlahProduk++;
                struk.totalBelanja += produkBeli.harga;
            } else {
                cout << "Produk dengan ID " << idProduk << " tidak tersedia." << endl;
            }
        }
        
        // hitung total pendapatan kasir
        totalPendapatan += struk.totalBelanja;
        
        // Menampilkan Total Belanja
        cout << "Total Belanja : " << struk.totalBelanja << endl;
        // Menerima pembayaran dan menghitung kembalian
        cout << "Masukkan jumlah uang yang dibayarkan (sisa yang harus dibayar: " << struk.totalBelanja << "): ";
        cin >> struk.uangDibayarkan;
        
        while (struk.uangDibayarkan < struk.totalBelanja) {
            cout << "Uang yang dibayarkan kurang. Masukkan kembali jumlah uang yang dibayarkan: ";
            cin >> struk.uangDibayarkan;
        }
        
        struk.uangKembalian = struk.uangDibayarkan - struk.totalBelanja;

        // tampilkan struk belanja
        printStrukBelanja(struk);

        cout << endl;
    }
    
    // tampilkan total pendapatan kasir
    cout << "Total pendapatan kasir: " << totalPendapatan << endl;
    cout << " " << endl;
    cout << "------------------------------------------" << endl;
    return 0;
}
