// Lab 3: RationalNumber.cpp
// RationalNumber member-function definitions.
#include <cstdlib>
#include <iostream>
using namespace std;

#include "RationalNumber.h"

// RationalNumber constructor sets n and d and calls reduction
/* Implement the RationalNumber constructor. Validate d first to ensure that
   it is a positive number and set it to 1 if not. Call the reduction utility
   function at the end */
RationalNumber::RationalNumber(int n, int d)
{
    if(n < 0)
        numerator = 1;

    numerator = n;
    denominator = d;

    reduction();
}

// overloaded + operator
/* Write definition for overloaded operator + */
RationalNumber RationalNumber::operator+(const RationalNumber & a)  const
{
    RationalNumber temp;

    temp.numerator = this->numerator + a.numerator; //分子相加
    temp.denominator = this->denominator;   //分母不变
    temp.reduction();

    return temp;
}

// overloaded - operator
/* Write definition for overloaded operator - */
RationalNumber RationalNumber::operator-(const RationalNumber & a)  const
{
    RationalNumber temp;

    temp.numerator = this->numerator - a.numerator; //分子相减
    temp.denominator = this->denominator;  //分母不变
    temp.reduction();

    return temp;
}

// overloaded * operator
/* Write definition for overloaded operator * */
RationalNumber RationalNumber::operator*(const RationalNumber & a)  const
{
    RationalNumber temp;

    temp.numerator = this->numerator * a.numerator; //分子相乘
    temp.denominator = this->denominator * a.denominator;   //分母不变
    temp.reduction();

    return temp;
}

// overloaded / operator
/* Write definition for overloaded operator /. Check if the client is
   attempting to divide by zero and report an error message if so */
RationalNumber RationalNumber::operator/(const RationalNumber & a)  const
{
    RationalNumber temp;

    temp.numerator = this->numerator * a.denominator;   //分子乘分母
    temp.denominator = this->denominator * a.numerator; //分母乘分子
    temp.reduction();

    return temp;
}

// overloaded > operator
/* Write definition for operator > */
bool RationalNumber::operator>(const RationalNumber & a)  const
{
    double q = this->numerator / this->denominator;
    double b = a.numerator / this->denominator;

    if(q > b)
        return true;
    else
        return false;
}

// overloaded < operator
/* Write definition for operator < */
bool RationalNumber::operator<(const RationalNumber & a)  const
{
    double q = this->numerator / this->denominator;
    double b = a.numerator / a.denominator;

    if(q < b)
        return true;
    else
        return false;

}

// overloaded >= operator
/* Write definition for operator >= */
bool RationalNumber::operator>=(const RationalNumber & a)  const
{
    double q = this->numerator / this->denominator;
    double b = a.numerator / a.denominator;

    if(q >= b)
        return true;
    else
        return false;
}

// overloaded <= operator
/* Write definition for operator <= */
bool RationalNumber::operator<=(const RationalNumber & a)  const
{
    double q = this->numerator / this->denominator;
    double b = a.numerator / a.denominator;

    if(q <= b)
        return true;
    else
        return false;
}

// overloaded == operator
/* Write definition for operator == */
bool RationalNumber::operator==(const RationalNumber & a)  const
{
    if(this->denominator == a.denominator && this->numerator == a.numerator)
        return true;
    else
        return false;

}

// overloaded != operator
/* Write definition for operator != */
bool RationalNumber::operator!=(const RationalNumber & a)  const
{
    if(*this == a)
        return false;
    else
        return true;
}

// function printRational definition
void RationalNumber::printRational() const
{
   if ( numerator == 0 ) // print fraction as zero
      cout << numerator;
   else if ( denominator == 1 ) // print fraction as integer
      cout << numerator;
   else
      cout << numerator << '/' << denominator;
} // end function printRational

// function reduction definition
void RationalNumber::reduction()
{
   int largest, gcd = 1;  // greatest common divisor;

   largest = ( numerator > denominator ) ? numerator: denominator;

   for ( int loop = 2; loop <= largest; loop++ )
       if ( numerator % loop == 0 && denominator % loop == 0 )
          gcd = loop;

   numerator /= gcd;
   denominator /= gcd;
} // end function reduction


/**************************************************************************
 * (C) Copyright 1992-2012 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
