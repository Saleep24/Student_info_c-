#include <iostream>
using namespace std;

int main(){
float cp;
float mp = 0;
cout << "Enter the manufacture's price of your product: ";
cin >> cp;
mp = cp + (0.35 * cp);
cout<< "Retail Price: $" << mp;
return 0;
}