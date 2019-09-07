#include <iostream>
using namespace std;
int main()
{
 bool felt;
 int a;
 felt = true;
 if(felt) // ez hamis lesz
 a = 1;
 else
 a = 2; // ez a rész hajtódik végre
 cout << a << endl;
 return 0;
} 
