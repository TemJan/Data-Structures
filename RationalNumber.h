// Your goal is to create a rational number class that would
// support each of the operations given in main.cpp.
//
// In this file you must declare only the interface of your class
// and implement the given functions separately from the class (at the bottom of
// this file inside the namespace).
// Notice that the RationalNumber is a class template, where the
// template parameter is an integer type for numerator and denominator.
//
// Note - Rename the namespace "yourname" to whatever you want, feel creative
// ( but not too much :) ).
//
// After you wrote RationalNumber class and the tests in the main function work
// - write at the bottom of the file the downsides of such rational numbers,
// what would you change/remove/add? Would you use such rational numbers instead
// of double/float numbers? There is no right/wrong answer, this question is
// more of a philosofical kind than technical.
#pragma once
#include <iostream>
#include <cmath>

namespace yourname 
{
template<typename T>
class RationalNumber  
{
private:
  T m;
  T n;
public:
  RationalNumber(T m=0, T n=1)
  :m(m)
  ,n(n)
  {
    reduce(this->m,this->n);
  }
  
  RationalNumber(const RationalNumber<T>& other)
  :m(other.m)
  ,n(other.n) 
  {
  }
  
  T gcd(T a, T b)
  {
    if(b == 0)
      return a;
    return gcd(b,a%b);
    //return std::abs(gcd(b,a%b));
  }

  T lcm(T a, T b)
  {
    return a*(b/gcd(a,b));
  }

  T& getM()
  {
    return m;
  }

  T& getN()
  {
    return n;
  }

  T& setM(const T& temp)
  {
    m = temp;
    return m;
  }

  T& setN(const T& temp)
  {
    n = temp;
    return n;
  }
  
  void reduce(T& m, T& n)
  {
    if((n < 0 and m < 0) or (n < 0))
      n *= -1, m *= -1;
    T temp = gcd(m,n);
    if(m%temp == 0 and n%temp == 0)
      m /= temp, n /= temp;
  }
  
  RationalNumber<T> operator+(const RationalNumber<T>& rhs)
  {
    RationalNumber result;
    result.m = m*(lcm(n,rhs.n)/n) + rhs.m*(lcm(n,rhs.n)/rhs.n);
    result.n = lcm(n,rhs.n);
    reduce(result.m, result.n);
    return result;
  }

  RationalNumber<T> operator+()
  {
    reduce(m, n);
    return *this;
  }

  RationalNumber<T> operator-()
  {
    m*=-1;
    reduce(m, n);
    return *this;
  }
  
  RationalNumber<T> operator+=(const RationalNumber<T>& other)
  {
    *this = *this + other;
    reduce(this->m, this->n);
    return *this;
  }

  RationalNumber<T> operator-(const RationalNumber<T>& rhs)
  {
    RationalNumber result;
    result.m = m*(lcm(n,rhs.n)/n) - rhs.m*(lcm(n,rhs.n)/rhs.n);
    result.n = lcm(n,rhs.n);
    reduce(result.m, result.n);
    return result;
  }

  RationalNumber<T>& operator++()
  {
    this->m += this->n;
    return *this;
  }

  RationalNumber<T> operator++(int)
  {
    RationalNumber<T> temp = *this;
    this->m += this->n;
    return temp;
  }
  
  RationalNumber<T> operator-=(const RationalNumber<T>& other)
  {
    *this = *this - other;
    reduce(this->m, this->n);
    return *this;
  }
  
  RationalNumber<T> operator*(const RationalNumber<T>& rhs)
  {
    RationalNumber result;
    T temp1 = gcd(m,rhs.n);
    T temp2 = gcd(rhs.m,n);
    result.m = (m/temp1)*(rhs.m/temp2);
    result.n = (n/temp2)*(rhs.n/temp1);
    reduce(result.m, result.n);
    return result;
  }

  RationalNumber<T> operator*=(const RationalNumber<T>& other)
  {
    *this = *this * other;
    reduce(this->m, this->n);
    return *this;
  }

  RationalNumber<T> operator/(RationalNumber<T> rhs)
  {
    std::swap(rhs.m,rhs.n);
    rhs *= *this;
    reduce(rhs.m, rhs.n);
    return rhs;
  }

  RationalNumber<T> operator/=(const RationalNumber<T>& other)
  {
    *this = *this / other;
    reduce(this->m, this->n);
    return *this;
  }
  
  RationalNumber<T> operator=(RationalNumber<T> other)
  {
    std::swap(m,other.m);
    std::swap(n,other.n);
    return *this;
  }

  operator double() const
  {
    return (double)m/(double)n;
  }

  operator float() const
  {
    return (float)m/(float)n;
  }

  operator int() const
  {
    return (int)m/(int)n;
  }

  operator unsigned long long() const
  {
    return (unsigned long long)m/(unsigned long long)n;
  }
  
  bool operator<(const RationalNumber<T>& obj)
  {
    T temp = lcm(obj.n,n);
    return (m*(temp/n) < obj.m*(temp/obj.n));
  }

  bool operator<=(const RationalNumber<T>& obj)
  {
    T temp = lcm(obj.n,n);
    return (m*(temp/n) <= obj.m*(temp/obj.n));
  }

  bool operator>(const RationalNumber<T> obj)
  {
    T temp = lcm(obj.n,n);
    return (m*(temp/n) > obj.m*(temp/obj.n));
  }

  bool operator>=(const RationalNumber<T> obj)
  {
    T temp = lcm(obj.n,n);
    return (m*(temp/n) >= obj.m*(temp/obj.n));
  }

  bool operator==(const RationalNumber<T> obj)
  {
    T temp = lcm(obj.n,n);
    return (m*(temp/n) == obj.m*(temp/obj.n));
  }

  bool operator!=(const RationalNumber<T> obj)
  {
    T temp = lcm(obj.n,n);
    return (m*(temp/n) != obj.m*(temp/obj.n));
  }
  
  friend std::ostream& operator<<(std::ostream& output,const RationalNumber<T>& obj)
  {
    /*if(obj.n == 1)
      output << obj.m; */
    output << obj.m << "/" << obj.n; 
    return output;
  }
};
namespace literals
{
  yourname::RationalNumber<unsigned long long> operator""_r(unsigned long long value)
  {
    return yourname::RationalNumber<unsigned long long>(value);
  }
}
  
  
} // namespace yourname

template<typename T>
yourname::RationalNumber<T> operator+(const T& temp ,yourname::RationalNumber<T> obj)
{
  yourname::RationalNumber<T> result;
  result.setM(obj.getM() + obj.getN()*temp);
  result.setN(obj.getN());
  result.reduce(result.getM(),result.getN());
  return result;
}

template<typename T>
yourname::RationalNumber<T> operator*(const T& temp , yourname::RationalNumber<T> obj)
{
  yourname::RationalNumber<T> result;
  result.setM(obj.getM()*temp);
  result.setN(obj.getN());
  result.reduce(result.getM(),result.getN());
  return result;
}