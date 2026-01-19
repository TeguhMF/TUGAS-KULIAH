#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    string gender;
    float nilai;
    Mahasiswa* next;
};

Mahasiswa* topStack = nullptr;

Mahasiswa* buatNode(string nama, string nim, string gender, float nilai) {
    Mahasiswa* baru = new Mahasiswa;
    baru->nama = nama;
    baru->nim = nim;
    baru->gender = gender;
    baru->nilai = nilai;
    baru->next = nullptr;
    return baru;
}

void push(string nama, string nim, string gender, float nilai) {
    Mahasiswa* baru = buatNode(nama, nim, gender, nilai);
    baru->next = topStack;
    topStack = baru;
    cout << "Data berhasil ditambahkan\n";
}

void hapusKe4() {
    if (topStack == nullptr) {
        cout << "Data masih kosong\n";
        return;
    }

    int jumlah = 0;
    Mahasiswa* hitung = topStack;
    while (hitung != nullptr) {
        jumlah++;
        hitung = hitung->next;
    }

    if (jumlah < 4) {
        cout << "Data kurang dari 4\n";
        return;
    }

    Mahasiswa* bantu = topStack;
    for (int i = 1; i < 3; i++) {
        bantu = bantu->next;
    }

    Mahasiswa* hapus = bantu->next;
    bantu->next = hapus->next;
    cout << "Data ke-4 dengan nama " << hapus->nama << " berhasil dihapus\n";
    delete hapus;
}

void tampilkan() {
    if (topStack == nullptr) {
        cout << "Data masih kosong\n";
        return;
    }

    Mahasiswa* bantu = topStack;
    int no = 1;
    while (bantu != nullptr) {
        cout << "Data ke-" << no++ << endl;
        cout << "Nama   : " << bantu->nama << endl;
        cout << "NIM    : " << bantu->nim << endl;
        cout << "Gender : " << bantu->gender << endl;
        cout << "Nilai  : " << bantu->nilai << endl;
        cout << "-------------------\n";
        bantu = bantu->next;
    }
}

int main() {
    int pilihan;
    string nama, nim, gender;
    float nilai;

    do {
        cout << "\nMENU\n";
        cout << "1. Tambah Data\n";
        cout << "2. Hapus Data\n";
        cout << "3. Tampilkan Data\n";
        cout << "4. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            cout << "Nama   : ";
            getline(cin, nama);
            cout << "NIM    : ";
            getline(cin, nim);
            cout << "Gender : ";
            getline(cin, gender);
            cout << "Nilai  : ";
            cin >> nilai;
            push(nama, nim, gender, nilai);
        } 
        else if (pilihan == 2) {
            hapusKe4();
        } 
        else if (pilihan == 3) {
            tampilkan();
        } 
        else if (pilihan == 4) {
            cout << "Program selesai\n";
        } 
        else {
            cout << "Pilihan tidak valid\n";
        }

    } while (pilihan != 4);

    return 0;
}
