/*===========================================================================================
* Name : srm258_AutoLoan.cpp
* Author: tiaunjia
* Description: SRM 258 D1L1 & D2L2.
* Sources: 
*        [1] https://community.topcoder.com/stat?c=problem_statement&pm=3970&rd=7993
* Date Created: Thurs.Oct.6.2016
*=============================================================================================*/

#include <cstdio>

class AutoLoan
{
public:

  // Predicate for binary search: Is the yearly rate >= target yearly Rate?
  bool p(double yearlyRate, double price, double monthlyPayment, int loanTerm, double epsilon)
  {
    double balance = price;
    double monthlyRate = yearlyRate/12.0/100.0;

    // printf("\033[94m balance: %.2f \n", balance);
    // printf("\033[94m monthlyRate: %.2f \n", monthlyRate);
    // printf("\033[94m yearlyRate: %.2f \n", yearlyRate);

    for(int i=0; i<loanTerm; i++)
    {
      // printf("\033[91m interest: %.2f \n", balance * (1.0 + monthlyRate));
      balance = (balance * (1.0 + monthlyRate)) - monthlyPayment;
    }

    // printf("balance: %.8f \n\n", balance);
    return balance > epsilon; // This is tricky - ensure you revise on paper how to move bounds!
  }

  double interestRate(double price, double monthlyPayment, int loanTerm)
  {
    double lo = 0.0;
    double hi = 100.0;
    int iterations = 100;
    double epsilon = 1e-9;

    while (iterations > 0)
    {
      double mid = (lo + hi)/2; // current yearly interest rate
      // printf("mid: %.2f, lo: %.2f, hi: %.2f \n", mid, lo, hi);
      if (p(mid, price, monthlyPayment, loanTerm, epsilon))
        hi = mid;
      else
        lo = mid;

      iterations--;
    }

    return lo;
  }
};

int main()
{
  AutoLoan a;
  double price, monthlyPayment, yearlyRate;
  int loanTerm;

  // SRM Problem Unit Test 1
  price = 6800;
  monthlyPayment = 100;
  loanTerm = 68;

  yearlyRate = a.interestRate(price, monthlyPayment, loanTerm);
  printf("\033[92m Yearly Rate: \033[m %.8f \n", yearlyRate);

  // SRM Problem Unit Test 2
  price = 2000;
  monthlyPayment = 510;
  loanTerm = 4;

  yearlyRate = a.interestRate(price, monthlyPayment, loanTerm);
  printf("\033[92m Yearly Rate: \033[m %.8f \n", yearlyRate);

  // SRM Problem Unit Test 3
  price = 15000;
  monthlyPayment = 364;
  loanTerm = 48;

  yearlyRate = a.interestRate(price, monthlyPayment, loanTerm);
  printf("\033[92m Yearly Rate: \033[m %.8f \n", yearlyRate);

}

