// Lab 2: Hugeint.h
// HugeInt class definition.
#ifndef HUGEINT_H
#define HUGEINT_H

#include <iostream>
using namespace std;

class HugeInt
{
   friend ostream &operator<<( ostream &, const HugeInt & );
public:
   HugeInt( long = 0 ); // conversion/default constructor
   HugeInt( const char * ); // conversion constructor

   // addition operator; HugeInt + HugeInt
   HugeInt operator+( const HugeInt & ) const;

   // addition operator; HugeInt + int
   HugeInt operator+( int ) const;

   // addition operator;
   // HugeInt + string that represents large integer value
   HugeInt operator+( const char * ) const;

   /* Write prototypes for the six relational and equality operators */
   bool operator==( const HugeInt &op2) const;
   bool operator==(int ) const;
   bool operator==(const char *op2) const;

   bool operator!=( const HugeInt & op2) const
   {
       return !(*this==op2);
   }
   bool operator!=(int op2) const
   {
       return !(*this==HugeInt(op2));
   }
   bool operator!=(const char *op2) const
   {
       return !(*this==HugeInt(op2));
   }

   bool operator<( const HugeInt & op2) const;
   bool operator<(int ) const;
   bool operator<(const char *op2) const;

   bool operator<=( const HugeInt & op2) const
   {
       return *this<op2||*this==op2;
   }
   bool operator<=(int op2) const
   {
       return *this<HugeInt(op2)||*this==HugeInt(op2);
   }
   bool operator<=(const char *op2) const
   {
       return *this<HugeInt(op2)||*this==HugeInt(op2);
   }

   bool operator>( const HugeInt & op2) const
   {
       return !(*this<=op2);
   }
   bool operator>(int op2) const
   {
       return !(*this<=HugeInt(op2));
   }
   bool operator>(const char *op2) const
   {
       return !(*this<=HugeInt(op2));
   }

   bool operator>=( const HugeInt & op2) const
   {
       return *this>op2||(*this==op2);
   }
   bool operator>=(int op2) const
   {
       return *this>HugeInt(op2)||(*this==HugeInt(op2));
   }
   bool operator>=(const char *op2) const
   {
       return *this>HugeInt(op2)||*this==HugeInt(op2);
   }
   int getLength() const;
private:
   short integer[ 30 ];
}; // end class HugeInt

#endif
