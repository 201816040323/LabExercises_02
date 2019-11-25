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
RationalNumber::RationalNumber( int a, int b)
{
    if(a>0)
        numerator=a;
    else
        numerator=1;
    if(b>0)
        denominator=b;
    else
        denominator=1;
    reduction();
}
// overloaded + operator
/* Write definition for overloaded operator + */
RationalNumber RationalNumber::operator+( const RationalNumber &a ) const
{
    RationalNumber temp;
    temp.numerator=numerator*a.denominator+denominator*a.numerator;
    temp.denominator=denominator*a.denominator;
    temp.reduction();
    return temp;
}
// overloaded - operator
/* Write definition for overloaded operator - */
RationalNumber RationalNumber::operator-( const RationalNumber &a ) const
{
    RationalNumber temp;
    temp.numerator=numerator*a.denominator-denominator*a.numerator;
    temp.denominator=denominator*a.denominator;
    temp.reduction();
    return temp;
}
// overloaded * operator
/* Write definition for overloaded operator * */
RationalNumber RationalNumber::operator*( const RationalNumber &a ) const
{
    RationalNumber temp;
    temp.numerator=numerator*a.numerator;
    temp.denominator=denominator*a.denominator;
    temp.reduction();
    return temp;
}
// overloaded / operator
/* Write definition for overloaded operator /. Check if the client is
   attempting to divide by zero and report an error message if so */
RationalNumber RationalNumber::operator/( const RationalNumber &a ) const
{
    RationalNumber temp;
    temp.numerator=numerator*a.denominator;
    temp.denominator=denominator*a.numerator;
    temp.reduction();
    return temp;
}
// overloaded > operator
/* Write definition for operator > */
bool RationalNumber::operator>( const  RationalNumber&a ) const
{
    int b,c;
    if(numerator*a.denominator>a.numerator*denominator)
        return true;
    else
        return false;
}
// overloaded < operator
/* Write definition for operator < */
bool RationalNumber::operator<( const  RationalNumber&a ) const
{
    return(a>*this);
}
// overloaded >= operator
/* Write definition for operator >= */
bool RationalNumber::operator>=( const  RationalNumber&a ) const
{
    return !(*this<a);
}
// overloaded <= operator
/* Write definition for operator <= */
bool RationalNumber::operator<=( const  RationalNumber&a ) const
{
    return !(*this>a);
}
// overloaded == operator
/* Write definition for operator == */
bool RationalNumber::operator==( const  RationalNumber&a ) const
{
    if(numerator==a.numerator&&denominator==a.denominator)
        return true;
    else
        return false;
}
// overloaded != operator
/* Write definition for operator != */
bool RationalNumber::operator!=( const  RationalNumber&a ) const
{
    return !(*this==a);
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
