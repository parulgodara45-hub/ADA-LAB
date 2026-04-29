#include <iostream> 
using namespace std; 
 
int main() 
{ 
    int n; 
 
    cout << "Enter degree of polynomial: "; 
    cin >> n; 
 
    int a[100]; 
 
    cout << "Enter coefficients from highest degree to constant:\n"; 
    for (int i = 0; i <= n; i++) 
    { 
        cout << "a[" << i << "] = "; 
        cin >> a[i]; 
    } 
 
    int x; 
    cout << "Enter value of x: "; 
    cin >> x; 
 
    int result = a[0]; 
 
    cout << "\nSteps of evaluation:\n"; 
    cout << "Initial result = " << result << endl; 
 
    for (int i = 1; i <= n; i++) 
    { 
        result = result * x + a[i]; 
 
        cout << "Step " << i << ": "; 
        cout << "result = result * x + a[" << i << "] = "; 
        cout << result << endl; 
    } 
 
    cout << "\nFinal Result: " << result << endl; 
 
    return 0; 
} 