//linear queue ANDIKA SEPTA NUGRAHA 
#include <iostream>
using namespace std;

class MyCircularQueue {
private:
    int *data;      // array penyimpan data
    int frontIdx;   // posisi elemen depan
    int rearIdx;    // posisi elemen belakang
    int count;      // jumlah elemen
    int maxSize;    // kapasitas maksimum

public:
    // Konstruktor
    MyCircularQueue(int kapasitas = 5) {
        maxSize = kapasitas;
        data = new int[maxSize];
        frontIdx = -1;
        rearIdx = -1;
        count = 0;
    }

    // Destruktor
    ~MyCircularQueue() {
        delete[] data;
    }

    // Mengecek apakah kosong
    bool isEmpty() const {
        return count == 0;
    }

    // Mengecek apakah penuh
    bool isFull() const {
        return count == maxSize;
    }

    // Menambahkan elemen ke queue
    void addQueue(int val) {
        if (isFull()) {
            cout << "⚠️ Queue penuh! Gagal menambahkan " << val << endl;
            return;
        }

        if (isEmpty()) {
            frontIdx = rearIdx = 0;
        } else {
            rearIdx = (rearIdx + 1) % maxSize;
        }

        data[rearIdx] = val;
        count++;
        cout << "✅ Elemen " << val << " berhasil ditambahkan.\n";
        showQueue();
    }

    // Menghapus elemen dari queue
    int removeQueue() {
        if (isEmpty()) {
            cout << "⚠️ Queue kosong! Tidak ada yang dihapus.\n";
            return -1;
        }

        int removed = data[frontIdx];
        if (frontIdx == rearIdx) {
            frontIdx = rearIdx = -1;
        } else {
            frontIdx = (frontIdx + 1) % maxSize;
        }

        count--;
        cout << "🗑️ Elemen " << removed << " telah dihapus.\n";
        showQueue();
        return removed;
    }

    // Melihat elemen depan
    int frontValue() const {
        if (isEmpty()) {
            cout << "Queue masih kosong!\n";
            return -1;
        }
        return data[frontIdx];
    }

    // Menampilkan isi queue
    void showQueue() const {
        if (isEmpty()) {
            cout << "Queue: [kosong]\n";
            cout << "------------------------\n";
            return;
        }

        cout << "Queue: [";
        for (int i = 0; i < count; i++) {
            int index = (frontIdx + i) % maxSize;
            cout << data[index];
            if (i < count - 1) cout << ", ";
        }
        cout << "]\n";
        cout << "Front: " << frontIdx << " | Rear: " << rearIdx << " | Size: " << count << endl;
        cout << "------------------------\n";
    }
};

//=== Fungsi Utama ===//
int main() {
    MyCircularQueue q(5);

    cout << "===== IMPLEMENTASI CIRCULAR QUEUE =====\n";
    cout << "Kapasitas Maksimum: 5 Elemen\n";
    cout << "=======================================\n";

    cout << "\n1. addQueue(10)\n"; q.addQueue(10);
    cout << "\n2. addQueue(24)\n"; q.addQueue(24);
    cout << "\n3. removeQueue()\n"; q.removeQueue();
    cout << "\n4. addQueue(30)\n"; q.addQueue(30);
    cout << "\n5. addQueue(40)\n"; q.addQueue(40);
    cout << "\n6. addQueue(50)\n"; q.addQueue(50);
    cout << "\n7. addQueue(50)\n"; q.addQueue(50); // penuh
    cout << "\n8. removeQueue()\n"; q.removeQueue();

    return 0;
}
