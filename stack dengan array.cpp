#include <iostream>
#include <string>
#include <cctype>
#define MAX_SIZE 10
using namespace std;

class Stack {
private:
    char data[MAX_SIZE];
    int top;

public:
    Stack() { top = -1; }
    
    void push(char x) {
        if (top >= MAX_SIZE-1) {
            cout << "Stack overflow!" << endl;
            return;
        }
        data[++top] = x;
    }
    
    char pop() {
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
    Stack s;
    
    cout << "=== DEMO APLIKASI STACK DENGAN ARRAY ===" << endl;
    
    // Demo operasi dasar
    cout << "\n1. OPERASI DASAR STACK:" << endl;
    s.push('A');
    s.push('B');
    s.push('C');
    s.display();
    
    cout << "Peek: " << s.peek() << endl;
    cout << "Pop: " << s.pop() << endl;
    s.display();
    
    // Demo membalik string
    cout << "\n2. MEMBALIK STRING:" << endl;
    string kata = "STACK";
    cout << "Original: " << kata << endl;
    
    Stack balik;
    for (char c : kata) {
        balik.push(c);
    }
    
    cout << "Reversed: ";
    while (!balik.isEmpty()) {
        cout << balik.pop();
    }
    cout << endl;
    
    // Demo pengecekan tanda kurung
    cout << "\n3. PENGECEKAN TANDA KURUNG:" << endl;
    string expr1 = "((a+b)*(c-d))";
    string expr2 = "((a+b)*((c-d))";
    
    Stack cek;
    bool valid = true;
    
    for (char c : expr1) {
        if (c == '(') cek.push(c);
        else if (c == ')') {
            if (cek.isEmpty()) {
                valid = false;
                break;
            }
            cek.pop();
        }
    }
    
    cout << "Expression: " << expr1 << endl;
    cout << "Tanda kurung " << (valid && cek.isEmpty() ? "VALID" : "TIDAK VALID") << endl;
    
    return 0;
}