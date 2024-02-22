#include "RationalNumber.h"
#include <iostream>
/*
Outputs:
  19/3
  4/3
  20/3
  4/3
  0/1
  2/1
*/

void test1()
{
  // Represents 4/3.
  yourname::RationalNumber<int> rationalNumber1(4, 3);
  // Represents 5/1.
  yourname::RationalNumber<int> rationalNumber2(5);
  // Represents 0/1
  yourname::RationalNumber<int> rationalNumber3;

  rationalNumber1 += rationalNumber2;
  std::cout << rationalNumber1 << "\n"; // 19/3
  
  rationalNumber1 -= rationalNumber2;
  std::cout << rationalNumber1 << "\n"; // 4/3

  rationalNumber1 *= rationalNumber2;
  std::cout << rationalNumber1 << "\n"; // 20/3

  rationalNumber1 /= rationalNumber2;
  std::cout << rationalNumber1 << "\n"; // 4/3

  std::cout << rationalNumber3++ << "\n"; // 0/1
  std::cout << ++rationalNumber3 << "\n"; // 2/1
}

/*
Outputs:
19/3
-11/3
20/3
4/15
*/

void test2()
{
  yourname::RationalNumber<int> rationalNumber1(4, 3);
  yourname::RationalNumber<int> rationalNumber2(5);
  yourname::RationalNumber<int> rationalNumber3;
  
  rationalNumber3 = rationalNumber1 + rationalNumber2; 
  std::cout << rationalNumber3 << "\n"; // 19/3

  
  rationalNumber3 = rationalNumber1 - rationalNumber2;
  std::cout << rationalNumber3 << "\n"; // -11/3
  
  rationalNumber3 = rationalNumber1 * rationalNumber2;
  std::cout << rationalNumber3 << "\n"; // 20/3
  
  rationalNumber3 = rationalNumber1 / rationalNumber2;
  std::cout << rationalNumber3 << "\n"; // 4/15
}

/*
Outputs:
  19/15
  4/5
  4/15
  -4/15
*/

void test3()
{
  yourname::RationalNumber<int> rationalNumber3(4, 15);
  std::cout << 1 + rationalNumber3 << "\n"; // 19/15
  std::cout << 3 * rationalNumber3 << "\n"; // 4/5
  std::cout << +rationalNumber3 << "\n"; // 4/15
  std::cout << -rationalNumber3 << "\n"; // -4/15
}

/*
Outputs:
  1.33333
  5
  3
*/

void test4()
{
  yourname::RationalNumber<int> rationalNumber1(4, 3);
  yourname::RationalNumber<int> rationalNumber2(5);
  yourname::RationalNumber<int> rationalNumber3(19, 5);
  
  // In order to understand this part - first read about static_cast,
  // then read about casting operators overloading.
  std::cout << static_cast<double>(rationalNumber1) << "\n"; // 1.33333
  std::cout << static_cast<float>(rationalNumber2) << "\n";  // 5
  std::cout << static_cast<int>(rationalNumber3) << "\n";    // 3
}

/*
Outputs:
   1/12
   7/2
   -5/4
   -9/10
*/

void test5()
{
  yourname::RationalNumber<int> rationalNumber4(10, 120);
  yourname::RationalNumber<int> rationalNumber5(-7, -2);
  yourname::RationalNumber<int> rationalNumber6(-5, 4);
  yourname::RationalNumber<int> rationalNumber7(9, -10);
  
  std::cout << rationalNumber4 << "\n"; // 1/12
  std::cout << rationalNumber5 << "\n"; // 7/2
  std::cout << rationalNumber6 << "\n"; // -5/4
  std::cout << rationalNumber7 << "\n"; // -9/10
}

/*
Outputs:
  rationalNumber4 < rationalNumber5
  rationalNumber5 <= rationalNumber7
  rationalNumber7 != rationalNumber6
*/

void test6()
{
  yourname::RationalNumber<int> rationalNumber4(10, 120);
  yourname::RationalNumber<int> rationalNumber5(-7, -2);
  yourname::RationalNumber<int> rationalNumber6(-5, 4);
  yourname::RationalNumber<int> rationalNumber7(9, -10);

  if(rationalNumber4 < rationalNumber5)       // true
    std::cout << "rationalNumber4 < rationalNumber5" << "\n";

  if(rationalNumber6 > rationalNumber7)       // false
    std::cout << "rationalNumber6 > rationalNumber7" << "\n";

  if(rationalNumber4 <= rationalNumber6)      // false
    std::cout << "rationalNumber4 <= rationalNumber6" << "\n";

  if(rationalNumber5 >= rationalNumber7)      // true
    std::cout << "rationalNumber5 >= rationalNumber7" << "\n";

  if(rationalNumber5 == rationalNumber4)      // false
    std::cout << "rationalNumber5 == rationalNumber4" << "\n";
  
  if(rationalNumber7 != rationalNumber6)      // true
    std::cout << "rationalNumber7 != rationalNumber6" << "\n";
}

/*
Outputs:
  1999999997/2000020394
  2/1
*/

void test7()
{
  yourname::RationalNumber<int> rationalNumber8(399999999, 1000010197);
  yourname::RationalNumber<int> rationalNumber9(1199999997, 2000020394);
  std::cout << rationalNumber8 + rationalNumber9 << "\n"; // 1999999997/2000020394
  yourname::RationalNumber<unsigned long long> rationalNumber10(2305843009213693951, 1000010197);
  yourname::RationalNumber<unsigned long long> rationalNumber11(2000020394, 2305843009213693951);
  std::cout << rationalNumber10 * rationalNumber11 << "\n"; // 2/1
}

/*
Outputs:
  10/1
  7/8
  You now understand literals! YAY!
*/

void test8()
{
  // literals must be a namespace inside yourname namespace.
  using namespace yourname::literals;

  // In order to understand this part read about user-defined literals.
  yourname::RationalNumber<unsigned long long> rationalNumber12 = 10_r;

  
  yourname::RationalNumber<unsigned long long> rationalNumber13 = 7_r / 8_r;
  std::cout << rationalNumber12 << "\n"; // 10/1
  std::cout << rationalNumber13 << "\n"; // 7/8

  auto rationalNumber14 = 7_r / 5_r;
  auto rationalNumber15 = 2_r / 10_r;

  if(rationalNumber14 + rationalNumber15 == 8_r / 5_r)
    std::cout << "You now understand literals! YAY!";
}

/*
If all calls are uncommented outputs:
19/3
4/3
20/3
4/3
0/1
2/1
19/3
-11/3
20/3
4/15
19/15
4/5
4/15
-4/15
1.33333
5
3
1/12
7/2
-5/4
-9/10
rationalNumber4 < rationalNumber5
rationalNumber5 >= rationalNumber7
rationalNumber7 != rationalNumber6
1999999995/2000020394
2/1
10/1
7/8
You now understand literals! YAY!
*/
int main()
{
   test1(); //done
   test2(); //done
   test3(); //done
   test4(); //done
   test5(); //done
   test6(); //done
   test7(); //done
   test8();
}
