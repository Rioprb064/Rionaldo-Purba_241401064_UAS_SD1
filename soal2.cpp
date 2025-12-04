#include <iostream>
#include <algorithm> 
#include <math.h>    
using namespace std;

int main() {
    int N;
    cin >> N;

    int data[N];
    for (int i = 0; i < N; i++) {
        cin >> data[i];
    }

    sort(data, data + N);  
    system("cls");
    cout << N << endl;
    for (int i = 0; i < N; i++) {
        cout << data[i] << " ";
    }

    int cari;
    cin >> cari;

    int low = 0, high = N - 1, x = 0;
    int posisi;
    float posisi1;

    while (low <= high && cari >= data[low] && cari <= data[high]){
        posisi1 = (float)(cari - data[low]) / (data[high] - data[low]) * (high - low) + low;
        posisi = floor(posisi1);

        if(data[posisi] == cari){
            x = 1;
            break;
        }
        if(data[posisi] > cari)
            high = posisi - 1;
        else
            low = posisi + 1;
    }
    if (x == 0) {
        int selisih_terdekat = abs(data[0] - cari);
        posisi = data[0];
        for (int i = 1; i < N; i++) {
            int selisih_sekarang = abs(data[i] - cari);
            if (selisih_sekarang < selisih_terdekat) {
                selisih_terdekat = selisih_sekarang;
                posisi = data[i];
            }
        }
    }

    cout << endl;
    if (x == 1) {
        cout << "Mencari Kursi No:" << cari << endl;
        cout << "Status : TERSEDIA" << endl;
        cout << "Detail : Ditemukan pada indeks [" << posisi <<"]" << endl;
    }
    else {
        cout << "Mencari Kursi No: " << cari << endl;
        cout << "Status : TIDAK TERSEDIA" << endl;
        cout << "Opsi : Kursi terdekat yang tersedia adalah No. " << posisi << endl;
    }
    return 0;
}