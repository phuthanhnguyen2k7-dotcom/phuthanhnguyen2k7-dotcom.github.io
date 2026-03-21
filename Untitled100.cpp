#include <iostream>
using namespace std;

int main() {
    int n, m;
    cout << "Nhap so tien trinh: ";
    cin >> n;
    cout << "Nhap so loai tai nguyen: ";
    cin >> m;

    int Allocation[n][m], Max[n][m], Need[n][m];
    int Available[m];

    cout << "\nNhap ma tran Allocation:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> Allocation[i][j];

    cout << "\nNhap ma tran Max:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> Max[i][j];

    cout << "\nNhap Available:\n";
    for(int j = 0; j < m; j++)
        cin >> Available[j];

    // Tính Need
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            Need[i][j] = Max[i][j] - Allocation[i][j];

    bool Finish[n] = {false};
    int SafeSeq[n];
    int Work[m];

    for(int i = 0; i < m; i++)
        Work[i] = Available[i];

    int count = 0;

    while(count < n) {
        bool found = false;

        for(int i = 0; i < n; i++) {
            if(!Finish[i]) {
                bool ok = true;

                for(int j = 0; j < m; j++) {
                    if(Need[i][j] > Work[j]) {
                        ok = false;
                        break;
                    }
                }

                if(ok) {
                    for(int j = 0; j < m; j++)
                        Work[j] += Allocation[i][j];

                    SafeSeq[count++] = i;
                    Finish[i] = true;
                    found = true;
                }
            }
        }

        if(!found) {
            cout << "\nHe thong KHONG an toan (Deadlock!)";
            return 0;
        }
    }

    cout << "\nHe thong an toan.\nChuoi an toan: ";
    for(int i = 0; i < n; i++)
        cout << "P" << SafeSeq[i] << " ";

    return 0;
}
