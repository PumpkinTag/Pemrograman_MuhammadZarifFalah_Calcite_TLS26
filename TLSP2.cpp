#include <iostream>
using namespace std;

int main() {
    const int MAX = 100;
    char pesan[MAX];

    cout << "Masukkan pesan (huruf kapital, tanpa spasi): ";
    cin >> pesan;

    // hitung panjang pesan manual, gak pakai strlen
    int panjang = 0;
    while (pesan[panjang] != '\0') {
        panjang++;
    }

    char hasil[MAX];
    int nilaiSebelumnya = 0; 

    for (int i = 0; i < panjang; i++) {
        int nilaiAsli = pesan[i] - 'A' + 1; // A=1, B=2, ..., Z=26
        int nilaiBaru = nilaiAsli + nilaiSebelumnya;

        // kalau kelewat Z, muter balik ke A lagi
        while (nilaiBaru > 26) {
            nilaiBaru -= 26;
        }

        hasil[i] = 'A' + (nilaiBaru - 1);

        // buat huruf berikutnya, yang dipakai adalah nilai ASLI huruf sekarang
        nilaiSebelumnya = nilaiAsli;
    }
    hasil[panjang] = '\0';

    cout << "\nPesan asli    : " << pesan << endl;
    cout << "Pesan Rahasia: " << hasil << endl;

    return 0;
}