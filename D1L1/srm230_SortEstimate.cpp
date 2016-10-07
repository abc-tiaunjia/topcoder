/*===========================================================================================
* Name : srm230_SortEstimate.cpp
* Author: tiaunjia
* Description: SRM 230 D1L1 & D2L2.
* Sources: 
*        [1] https://community.topcoder.com/stat?c=problem_statement&pm=3561&rd=6519
* Date Created: Fri.Oct.7.2016
*=============================================================================================*/

#include <cstdio>
#include <cmath>
#include <limits>


class SortEstimate
{
public:
  bool p(int c, int t, double n)
  {
    return (c * n * log2(n)) >= t;
  }

  double howMany(int c, int time)
  {
    double lo = 0;
    double hi = 1000000000; //std::numeric_limits<double>::max(); - max double causes overflow
    int iterations = 100;

    for(int i=0; i<iterations; i++)
    {
      double mid = (lo + hi)/2;
      if (p(c, time, mid))
        hi = mid;
      else
        lo = mid;
    }

    return lo;
  }

};


int main()
{
  SortEstimate s;
  int c, t;
  double n;

  // SRM Unit Test 1
  c = 1;
  t = 8;

  n = s.howMany(c, t);
  printf("\033[92m n: \033[m %.8f \n", n);

  // SRM Unit Test 2
  c = 2;
  t = 16;

  n = s.howMany(c, t);
  printf("\033[92m n: \033[m %.8f \n", n);


  // SRM Unit Test 3
  c = 37;
  t = 12392342;

  n = s.howMany(c, t);
  printf("\033[92m n: \033[m %.8f \n", n);

  // SRM Unit Test 4
  c = 1;
  t = 2000000000;

  n = s.howMany(c, t);
  printf("\033[92m n: \033[m %.8f \n", n);
}