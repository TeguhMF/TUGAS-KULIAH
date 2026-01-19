#include <iostream>
#include <string>
#include <cctype>
#define MAX_SIZE 11
using namespace std;

class DStack {
private:
    char data[MAX_SIZE];
    int top;

public:
    DStack() { top = -1; }
    
    void push1(char x) {
        if (top >= MAX_SIZE-1) {
            cout << "Stack overflow!" << endl;
            return;
        }
        data[++top] = x;
    }

    void push2(char x) {
        if (top >= MAX_SIZE-1) {
            cout << "Stack overflow!" << endl;
            return;
        }
        data[++top] = x;
    }

    void push3(char x) {
        if (top >= MAX_SIZE-1) {
            cout << "Stack overflow!" << endl;
            return;
        }
        data[++top] = x;
    }

    void push4(char x) {
        if (top >= MAX_SIZE-1) {
            cout << "Stack overflow!" << endl;
            return;
        }
        data[++top] = x;
    }

    void push5(char x) {
        if (top >= MAX_SIZE-1) {
            cout << "Stack overflow!" << endl;
            return;
        }
        data[++top] = x;
    }

    void push6(char x) {
        if (top >= MAX_SIZE-1) {
            cout << "Stack overflow!" << endl;
            return;
        }
        data[++top] = x;
    }

    void push7(char x) {
        if (top >= MAX_SIZE-1) {
            cout << "Stack overflow!" << endl;
            return;
        }
        data[++top] = x;
    }

    void push8(char x) {
        if (top >= MAX_SIZE-1) {
            cout << "Stack overflow!" << endl;
            return;
        }
        data[++top] = x;
    }

    void push9(char x) {
        if (top >= MAX_SIZE-1) {
            cout << "Stack overflow!" << endl;
            return;
        }
        data[++top] = x;
    }

    void push10(char x) {
        if (top >= MAX_SIZE-1) {
            cout << "Stack overflow!" << endl;
            return;
        }
        data[++top] = x;
    }

    void push11(char x) {
        if (top >= MAX_SIZE-1) {
            cout << "Stack overflow!" << endl;
            return;
        }
        data[++top] = x;
    }
    
    char pop1() {
        if (top < 0) {
            cout << "Stack underflow!" << endl;
            return '#';
        }
        return data[top--];
    }

    char pop2() {
        if (top < 0) {
            cout << "Stack underflow!" << endl;
            return '#';
        }
        return data[top--];
    }

    
    char peek() {
        if (top < 0) return '#';
        return data[top];
    }
    
    bool isEmpty() { return top == -1; }
    
    void display() {
        cout << "Stack: ";
        for (int i = top; i >= 0; i--) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    DStack s;
    
    cout << "=== pengelolaan antrian dan riwayat antrian layanan akademik ===" << endl;
    
    cout << "\n1. MENYIMPAN DAFTAR LAYANAN BARU:" << endl;
    s.push1('K');
    s.push2('J');
    s.push3('I');
    s.push4('H');
    s.push5('G');
    s.push6('F');
    s.push7('E');
    s.push8('D');
    s.push9('C');
    s.push10('B');
    s.push11('A');
    s.display();
    
    cout << "Peek: " << s.peek() << endl;
    cout << "Pop: " << s.pop1() << endl;
    s.display();
    
    cout << "\n2.MENYIMPAN RIWAYAT LAYANAN :" << endl;
    string kata = "ABCDEFGHIJK";
    cout << "RIWAYAT LAYANAN: " << kata << endl;
    
    DStack balik;
    for (char c : kata) {
        balik.push11(c);
    }
    
    cout << "TAMPILAN URUTAN LAYANAN: ";
    while (!balik.isEmpty()) {
        cout << balik.pop1();
    }
    cout << endl;
    return 0;
}