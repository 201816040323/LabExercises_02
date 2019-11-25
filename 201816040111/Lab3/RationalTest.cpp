#include <iostream>
using namespace std;

#include "RationalNumber.h"

int main()
{
   RationalNumber c( 1, 0 ), d( 3, 7 ), x;

   cout << c;
   cout << " + ";
   cout << d;
   cout << " = ";
   x = c + d; // test overloaded operators + and =
   cout << x;

   cout << '\n';
   cout << c;
   cout << " - ";
   cout << d;
   cout << " = ";
   x = c - d; // test overloaded operators - and =
   cout << x;

   cout << '\n';
   cout << c;
   cout << " * ";
   cout << d;
   cout << " = ";
   x = c * d; // test overloaded operators * and =
   cout << x;

   cout << '\n';
   cout << c;
   cout << " / ";
   cout << d;
   cout << " = ";
   x = c / d; // test overloaded operators / and =
  cout << x;

   cout << '\n';
   cout << c;
   cout << " is:\n";

   // test overloaded greater than operator
   cout << ( ( c > d ) ? "  > " : "  <= " );
   cout << d;
   cout << " according to the overloaded > operator\n";

   // test overloaded less than operator
   cout << ( ( c < d ) ? "  < " : "  >= " );
   cout << d;
   cout << " according to the overloaded < operator\n";

   // test overloaded greater than or equal to operator
   cout << ( ( c >= d ) ? "  >= " : "  < " );
   cout << d;
   cout << " according to the overloaded >= operator\n";

   // test overloaded less than or equal to operator
   cout << ( ( c <= d ) ? "  <= " : "  > " );
   cout << d;
   cout << " according to the overloaded <= operator\n";

   // test overloaded equality operator
   cout << ( ( c == d ) ? "  == " : "  != " );
   cout << d;
   cout << " according to the overloaded == operator\n";

   // test overloaded inequality operator
   cout << ( ( c != d ) ? "  != " : "  == " );
   cout << d;
   cout << " according to the overloaded != operator" << endl;
} // end main
