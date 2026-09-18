#include <iostream>
using namespace std;

int main() {
    int n, k;

    cout << "Masukkan jumlah astronot(N): ";
    cin >> n;
    cout << "Masukkan nilai K di awal: ";
    cin >> k;

    
    int* astronot = new int[n];
    for (int i = 0; i < n; i++) {
        astronot[i] = i + 1;
    }

    int* urutanEliminasi = new int[n];
    int totalEliminasi = 0;

    int sisa = n;   
    int pos = 0;    

    while (sisa > 1) {
        pos = (pos + k - 1) % sisa;

        int nomorGugur = astronot[pos];
        urutanEliminasi[totalEliminasi] = nomorGugur;
        totalEliminasi++;

        for (int i = pos; i < sisa - 1; i++) {
            astronot[i] = astronot[i + 1];
        }
        sisa--;

        // Update K 
        if (nomorGugur % 2 == 0) {
            k += 2;
        } else {
            k -= 1;
        }
        if (k < 2) {
            k = 2;
        }


        if (sisa > 0) {
            pos = pos % sisa;
        }
    }

    cout << "\nUrutan astronot yang dieliminasi:\n";
    for (int i = 0; i < totalEliminasi; i++) {
        cout << urutanEliminasi[i];
        if (i != totalEliminasi - 1) cout << " -> ";
    }
    cout << "\n\nAstronot terakhir yang bertahan: " << astronot[0] << endl;
    return 0;
}
