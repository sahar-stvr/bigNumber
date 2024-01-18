#include <iostream>
using namespace std;
int main(){
    system("cls");
    string num1, num2, ch;
    int n = 20, n1, n2, n3, t, r, k, j, s, x;
    cout << "enter number 1 : ";
    cin >> num1;
    cout << "enter number 2 : ";
    cin >> num2;
    n1 = num1.length();
    n2 = num2.length();
    n3 = n1;
    if(n3 < n2){
        n3 = n2;
    }
    k = n3 + 1;
    int a[n], b[n], c[k], d[n], e[n];
    // 
    // 
    for (int i = 0; i < n; i++){
        a[i] = 0;
        b[i] = 0;
        d[i] = 0;
    }
    for (int i = 0; i < k; i++){
        c[i] = 0;
    }
    // 
    // 
    for (int i = 0; i < n1; i++){
        a[i] = int(num1[i]) - 48;
        e[i] = a[i];
    }
    for (int i = 0; i < n2; i++){
        b[i] = int(num2[i]) - 48;
    }
    // 
    // sum
    t = 0;
    for (int i = n3-1; i >= 0; i--){
        r = t + a[i] + b[i];
        if(r < 10){
            c[i+1] = r;
            t = 0;
        } else {
            c[i+1] = r % 10;
            t = r / 10;
        }
    }
    if(t > 0){
        c[0] = t;
    }
    if(c[0] == 0){
        j = 1;
        ch = "   ";
    } else {
        j = 0;
        ch = "  ";
    }
    // 
    // 
    cout << "\n\n   ";
    for (int i = 0; i < n1; i++){
        cout << a[i];
    }
    cout << endl << "+  ";
    for (int i = 0; i < n2; i++){
        cout << b[i];
    }
    cout << endl << "  -";
    for (int i = 0; i < n3; i++){
        cout << "-";
    }
    cout << endl << ch;
    for (int i = j; i < k; i++){
        cout << c[i];
    }
    cout << "\n\n\n";
    // 
    // sub
    s = 1;
    for (int i = 0; i < n3; i++){
        if(i == 0){
            if(a[i] > b[i]){
                s = 1;
                break;
            }
        }
        else if(a[i] < b[i]){
            s = 0;
            break;
        }
    }
    if(s == 1){
        t = 10;
        for (int i = n3-1; i >= 0; i--){
            r = e[i] - b[i];
            if(r < 0){
                if(e[i-1] > 0){
                    e[i-1] = e[i-1] - 1;
                }
                if(i == n3-1){
                    d[i] = (e[i] + 10) - b[i];
                }
                else {
                    if(e[i-1] >= b[i] && e[i+1] < b[i+1]){
                        d[i] = (e[i] + 9) - b[i];
                    }
                    else {
                        d[i] = (e[i] + 10) - b[i];
                    }
                }
            } 
            else {
                d[i] = e[i] - b[i];
            }
        }
    }
    // 
    // 
    if(s == 0){
        cout << "Subtraction is not done\n";
    } else {
        ch = "   ";
        cout << endl << ch;
        for (int i = 0; i < n1; i++){
            cout << a[i];
        }
        cout << endl << "-  ";
        for (int i = 0; i < n2; i++){
            cout << b[i];
        }
        cout << endl << "  -";
        for (int i = 0; i < n3; i++){
            cout << "-";
        }
        cout << endl << ch;
        for (int i = 0; i < n3; i++){
            cout << d[i];
        }
        cout << "\n\n";
    }
}
