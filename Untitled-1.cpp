#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <limits>

using namespace std;

// Warna untuk tampilan menarik
class Colors {
public:
    static const string RED;
    static const string GREEN;
    static const string YELLOW;
    static const string BLUE;
    static const string PURPLE;
    static const string CYAN;
    static const string WHITE;
    static const string RESET;
};

const string Colors::RED = "\033[91m";
const string Colors::GREEN = "\033[92m";
const string Colors::YELLOW = "\033[93m";
const string Colors::BLUE = "\033[94m";
const string Colors::PURPLE = "\033[95m";
const string Colors::CYAN = "\033[96m";
const string Colors::WHITE = "\033[97m";
const string Colors::RESET = "\033[0m";

// Struktur data untuk node
struct Node {
    string tanggal;
    string nama;
    string layanan;
    Node* prev;
    Node* next;
    
    Node(string tgl, string nm, string lay) {
        tanggal = tgl;
        nama = nm;
        layanan = lay;
        prev = nullptr;
        next = nullptr;
    }
};

class DoubleLinkedList {
private:
    Node* head;
    Node* tail;
    int count;
    const int MAX_DATA = 4;

public:
    DoubleLinkedList() {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    // Animasi loading
    void loadingAnimation(string message) {
        cout << Colors::CYAN << "\n" << message;
        for(int i = 0; i < 3; i++) {
            cout << ".";
            cout.flush();
            Sleep(500);
        }
        cout << Colors::RESET << endl;
    }

    // Animasi teks berjalan
    void typewriterEffect(string text, int delay = 50) {
        for(char c : text) {
            cout << c;
            cout.flush();
            Sleep(delay);
        }
    }

    // Membersihkan layar
    void clearScreen() {
        system("cls");
    }

    // Menampilkan header
    void showHeader() {
        cout << Colors::PURPLE;
        cout << "+------------------------------------------------------------+\n";
        cout << "¦" << Colors::CYAN << "           SISTEM LAYANAN ADMINISTRASI KAMPUS             " << Colors::PURPLE << "¦\n";
        cout << "¦" << Colors::YELLOW << "          DOUBLE LINKED LIST ANIMATION                  " << Colors::PURPLE << "¦\n";
        cout << "+------------------------------------------------------------+\n";
        cout << Colors::RESET;
    }

    // Memeriksa apakah data penuh
    bool isFull() {
        return count >= MAX_DATA;
    }

    // Memeriksa apakah data kosong
    bool isEmpty() {
        return count == 0;
    }

    // Konversi tanggal ke format yang bisa diurutkan
    string convertDate(string date) {
        // Format: DD-MM-YYYY -> YYYYMMDD
        string day = date.substr(0, 2);
        string month = date.substr(3, 2);
        string year = date.substr(6, 4);
        return year + month + day;
    }

    // Menyisipkan data dengan urutan berdasarkan tanggal
    void insertData() {
        clearScreen();
        showHeader();
        
        if(isFull()) {
            cout << Colors::RED << " Data sudah penuh! Maksimal " << MAX_DATA << " data.\n" << Colors::RESET;
            cout << "\nTekan Enter untuk kembali...";
            cin.ignore();
            cin.get();
            return;
        }

        string tanggal, nama, layanan;
        
        cout << Colors::GREEN << " INSERT DATA BARU\n" << Colors::RESET;
        cout << "------------------------------------------------\n";
        
        cout << "Masukkan Tanggal (DD-MM-YYYY): ";
        getline(cin, tanggal);
        
        cout << "Masukkan Nama Mahasiswa: ";
        getline(cin, nama);
        
        cout << "Masukkan Layanan: ";
        getline(cin, layanan);

        loadingAnimation("Memproses data");

        Node* newNode = new Node(tanggal, nama, layanan);
        
        if(head == nullptr) {
            // List kosong
            head = tail = newNode;
            count++;
            cout << Colors::GREEN << " Data berhasil ditambahkan!\n" << Colors::RESET;
        } else {
            // Cari posisi yang tepat berdasarkan tanggal
            Node* current = head;
            string newDate = convertDate(tanggal);
            
            while(current != nullptr) {
                string currentDate = convertDate(current->tanggal);
                
                if(newDate < currentDate) {
                    // Sisipkan sebelum current
                    if(current == head) {
                        // Sisipkan di awal
                        newNode->next = head;
                        head->prev = newNode;
                        head = newNode;
                    } else {
                        // Sisipkan di tengah
                        newNode->prev = current->prev;
                        newNode->next = current;
                        current->prev->next = newNode;
                        current->prev = newNode;
                    }
                    count++;
                    cout << Colors::GREEN << " Data berhasil ditambahkan!\n" << Colors::RESET;
                    return;
                }
                current = current->next;
            }
            
            // Jika sampai di sini, sisipkan di akhir
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            count++;
            cout << Colors::GREEN << " Data berhasil ditambahkan!\n" << Colors::RESET;
        }

        // Animasi linked list
        animateLinkedList();
        
        cout << "\nTekan Enter untuk kembali...";
        cin.get();
    }

    // Menghapus data berdasarkan nama
    void deleteData() {
        clearScreen();
        showHeader();
        
        if(isEmpty()) {
            cout << Colors::RED << " Data masih kosong!\n" << Colors::RESET;
            cout << "\nTekan Enter untuk kembali...";
            cin.ignore();
            cin.get();
            return;
        }

        string nama;
        cout << Colors::RED << "  HAPUS DATA\n" << Colors::RESET;
        cout << "------------------------------------------------\n";
        cout << "Masukkan Nama Mahasiswa yang akan dihapus: ";
        getline(cin, nama);

        loadingAnimation("Mencari data");

        Node* current = head;
        bool found = false;

        // Animasi pencarian
        cout << Colors::YELLOW << "\n Mencari: ";
        while(current != nullptr) {
            cout << current->nama;
            if(current->nama == nama) {
                cout << Colors::GREEN << " ? DITEMUKAN!" << Colors::RESET;
                found = true;
                break;
            } else {
                cout << Colors::RED << " ?" << Colors::RESET;
                if(current->next != nullptr) cout << " ? ";
            }
            cout.flush();
            Sleep(800);
            current = current->next;
        }
        cout << endl;

        if(!found) {
            cout << Colors::RED << " Data dengan nama '" << nama << "' tidak ditemukan!\n" << Colors::RESET;
            cout << "\nTekan Enter untuk kembali...";
            cin.get();
            return;
        }

        // Kembali cari node yang akan dihapus
        current = head;
        while(current != nullptr && current->nama != nama) {
            current = current->next;
        }

        if(current == nullptr) return;

        loadingAnimation("Menghapus data");

        // Animasi penghapusan
        animateDeletion(current);

        // Proses penghapusan
        if(current == head && current == tail) {
            // Hanya satu node
            head = tail = nullptr;
        } else if(current == head) {
            // Node pertama
            head = head->next;
            head->prev = nullptr;
        } else if(current == tail) {
            // Node terakhir
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            // Node di tengah
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }

        delete current;
        count--;

        cout << Colors::GREEN << " Data berhasil dihapus!\n" << Colors::RESET;
        
        // Tampilkan linked list setelah penghapusan
        animateLinkedList();
        
        cout << "\nTekan Enter untuk kembali...";
        cin.get();
    }

    // Menampilkan semua data
    void displayData() {
        clearScreen();
        showHeader();
        
        if(isEmpty()) {
            cout << Colors::RED << " Data masih kosong!\n" << Colors::RESET;
            cout << "\nTekan Enter untuk kembali...";
            cin.ignore();
            cin.get();
            return;
        }

        cout << Colors::BLUE << " DAFTAR LAYANAN ADMINISTRASI\n" << Colors::RESET;
        cout << "------------------------------------------------------------\n";
        
        loadingAnimation("Memuat data");

        // Animasi menampilkan data
        Node* current = head;
        int index = 1;
        
        cout << Colors::CYAN << "\n";
        cout << "+----------------------------------------------------------------------+\n";
        cout << "¦ " << Colors::YELLOW << "No" << Colors::CYAN << " ¦ " << Colors::YELLOW << "Tanggal" << Colors::CYAN << "    ¦ " << Colors::YELLOW << "Nama Mahasiswa" << Colors::CYAN << "       ¦ " << Colors::YELLOW << "Layanan" << Colors::CYAN << "                     ¦\n";
        cout << "+-----+------------+----------------------+----------------------------¦\n";
        
        while(current != nullptr) {
            cout << "¦ " << Colors::WHITE << setw(3) << index << Colors::CYAN << " ¦ "
                 << Colors::GREEN << current->tanggal << Colors::CYAN << " ¦ "
                 << Colors::WHITE << setw(20) << left << current->nama.substr(0, 20) << Colors::CYAN << " ¦ "
                 << Colors::PURPLE << setw(26) << left << current->layanan.substr(0, 26) << Colors::CYAN << " ¦\n";
            
            // Animasi pointer
            if(current->next != nullptr) {
                cout << "¦     ¦            ¦                      ¦                            ¦\n";
                cout << "¦     " << Colors::YELLOW << "?" << Colors::CYAN << "          " << Colors::YELLOW << "?" << Colors::CYAN << "                    " << Colors::YELLOW << "?" << Colors::CYAN << "                          ¦\n";
            }
            
            current = current->next;
            index++;
            Sleep(500);
        }
        
        cout << "+----------------------------------------------------------------------+\n";
        cout << Colors::RESET;

        // Tampilkan animasi linked list
        animateLinkedList();

        cout << "\nTekan Enter untuk kembali...";
        cin.get();
    }

    // Animasi visualisasi linked list
    void animateLinkedList() {
        cout << Colors::YELLOW << "\n VISUALISASI LINKED LIST:\n" << Colors::RESET;
        cout << Colors::CYAN;
        
        Node* current = head;
        int nodeNum = 1;
        
        while(current != nullptr) {
            // Gambar node
            cout << "+-------------+";
            if(current->next != nullptr) cout << "    ?    ";
            current = current->next;
        }
        cout << " NULL\n";
        
        current = head;
        while(current != nullptr) {
            cout << "¦ Node " << nodeNum << "       ¦";
            if(current->next != nullptr) cout << "    ?    ";
            current = current->next;
            nodeNum++;
        }
        cout << "\n";
        
        current = head;
        while(current != nullptr) {
            cout << "+-------------¦";
            if(current->next != nullptr) cout << "          ";
            current = current->next;
        }
        cout << "\n";
        
        current = head;
        while(current != nullptr) {
            cout << "¦ " << setw(11) << left << current->nama.substr(0, 11) << "¦";
            if(current->next != nullptr) cout << "          ";
            current = current->next;
        }
        cout << "\n";
        
        current = head;
        while(current != nullptr) {
            cout << "+-------------+";
            if(current->next != nullptr) cout << "          ";
            current = current->next;
        }
        cout << "\n";
        
        // Tampilkan pointer prev
        current = head;
        cout << Colors::GREEN << "Prev: ";
        if(head->prev == nullptr) {
            cout << "NULL";
        } else {
            cout << "?";
        }
        
        current = head->next;
        while(current != nullptr) {
            cout << "    ??    ";
            current = current->next;
        }
        cout << Colors::RESET << "\n\n";
    }

    // Animasi penghapusan node
    void animateDeletion(Node* nodeToDelete) {
        cout << Colors::RED << "\n  PROSES PENGHAPUSAN:\n" << Colors::RESET;
        
        Node* current = head;
        while(current != nullptr) {
            if(current == nodeToDelete) {
                cout << Colors::RED << "[? " << current->nama << " ?]";
            } else {
                cout << Colors::GREEN << "[ " << current->nama << " ]";
            }
            
            if(current->next != nullptr) {
                cout << Colors::YELLOW << " ? ";
            }
            
            current = current->next;
        }
        cout << Colors::RESET << endl;
        
        for(int i = 0; i < 3; i++) {
            cout << Colors::RED << "" << Colors::RESET;
            cout.flush();
            Sleep(300);
        }
        cout << endl;
    }

    // Menampilkan menu
    void showMenu() {
        clearScreen();
        showHeader();
        
        cout << Colors::GREEN << " MENU UTAMA:\n" << Colors::RESET;
        cout << "------------------------------------------------\n";
        cout << Colors::YELLOW << "1. " << Colors::WHITE << "Insert Data" << Colors::BLUE << "    ? Tambah data baru\n";
        cout << Colors::YELLOW << "2. " << Colors::WHITE << "Delete Data" << Colors::RED << "    ???  Hapus data\n";
        cout << Colors::YELLOW << "3. " << Colors::WHITE << "Tampilkan Data" << Colors::CYAN << " ?? Lihat semua data\n";
        cout << Colors::YELLOW << "4. " << Colors::WHITE << "Exit" << Colors::PURPLE << "         ?? Keluar program\n";
        cout << Colors::RESET;
        cout << "------------------------------------------------\n";
        cout << Colors::YELLOW << " Status: " << Colors::RESET;
        cout << Colors::CYAN << count << Colors::RESET << "/" << Colors::CYAN << MAX_DATA << Colors::RESET << " data terisi\n";
        cout << "------------------------------------------------\n";
        cout << Colors::GREEN << "Pilih menu (1-4): " << Colors::RESET;
    }

    // Menjalankan program
    void run() {
        int choice;
        
        // Animasi pembuka
        clearScreen();
        cout << Colors::PURPLE;
        typewriterEffect("?? SISTEM LAYANAN ADMINISTRASI KAMPUS ??\n\n", 30);
        cout << Colors::CYAN;
        typewriterEffect("Menggunakan Double Linked List dengan Animasi...\n\n", 20);
        Sleep(1000);
        
        loadingAnimation("Memulai sistem");
        
        do {
            showMenu();
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            switch(choice) {
                case 1:
                    insertData();
                    break;
                case 2:
                    deleteData();
                    break;
                case 3:
                    displayData();
                    break;
                case 4:
                    clearScreen();
                    cout << Colors::GREEN;
                    typewriterEffect("Terima kasih telah menggunakan sistem!\n", 30);
                    cout << Colors::YELLOW;
                    typewriterEffect("Program selesai...\n", 20);
                    loadingAnimation("Keluar");
                    break;
                default:
                    cout << Colors::RED << " Pilihan tidak valid! Silakan pilih 1-4.\n" << Colors::RESET;
                    Sleep(1000);
                    break;
            }
        } while(choice != 4);
    }

    // Destructor untuk membersihkan memory
    ~DoubleLinkedList() {
        Node* current = head;
        while(current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    // Enable ANSI escape codes di Windows
    #ifdef _WIN32
        system("");
    #endif

    DoubleLinkedList list;
    list.run();
    
    return 0;
}
