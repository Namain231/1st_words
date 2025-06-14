#include <iostream>
#include <cmath>
using namespace std;
void hanoi(int n, char source, char target, char auxiliary) {
    if (n == 1) {
        cout << source << " "<< target << endl;
        return;
    }
    hanoi(n - 1, source, auxiliary, target);
    cout <<  source << " " << target << endl;
    hanoi(n - 1, auxiliary, target, source);
}
int main() {
    int n;
    cin >> n;
    cout<< (pow(2,n)-1) << endl; 
    hanoi(n, '1', '3', '2'); // A, B and C are names of rods
    return 0;
}