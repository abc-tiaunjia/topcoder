/*===========================================================================================
* Name : srm169_FairWorkLoad.cpp
* Author: tiaunjia
* Description: SRM 169 D1L2 & D2L3.
* Sources: 
*        [1] https://community.topcoder.com/stat?c=problem_statement&pm=1901&rd=4650
* Date Created: Sat.Oct.8.2016
* Date Last Modified: Mon.Oct.10.2016
*=============================================================================================*/

#include <limits>
#include <cstdio>
#include <vector>
#include <numeric>      // std::accumulate
#include <algorithm>

using std::vector;
using std::accumulate;
using std::max_element;


class FairWorkload
{

public:

int getMostWork(vector<int> folders, int workers)
  {
    int lo = 0;
    int hi = accumulate(folders.begin(), folders.end(), 0);
    size_t m = folders.size();

    while (lo < hi)
    {
      int mid = (lo + hi)/2;
      int sections = 1;
      int curr_folder_sum = 0;
      int i;
      for(i=0; i<m; i++)
      {
         if (curr_folder_sum + folders[i] <= mid ) {
            // the current worker can handle it
            curr_folder_sum += folders[i];
         }
         else {
            // assign next worker
            ++sections;
            curr_folder_sum = folders[i];               
         }
      }

      if (sections <= workers )
         hi = mid;
      else
         lo = mid+1;
    } // end while

    return lo;
  }
  /*
  int getMostWork(vector<int> folders, int workers)
  {
    int lo = 0;
    int hi = accumulate(folders.begin(), folders.end(), 0);

    size_t m = folders.size();
    int mid, sections;
    int j = 0;

    vector<int> section_sums;
    while (lo < hi)
    {
      section_sums.clear();
      j++;
      mid = (lo + hi)/2;
      sections = 0;
      int curr_folder_sum = 0;
      int i;
      for(i=0; i<m; i++)
      {
        curr_folder_sum += folders[i];
        if (curr_folder_sum > mid)
        {
          // We've found a partition
          sections++;

          // if (curr_folder_sum > mid)
          curr_folder_sum -= folders[i];

          section_sums.push_back(curr_folder_sum);

          // printf("curr_folder_sum: %d, mid: %d \n", curr_folder_sum, mid);

          curr_folder_sum = folders[i];
        }
        // printf("[%d] --> lo: %d, hi: %d, mid: %d, sections: %d \n", j, lo, hi, mid, sections);
      }

      // printf("\nsections: %d \n", sections);
      // printf("curr_folder_sum: %d, mid: %d \n", curr_folder_sum, mid);

      if (sections == workers && !section_sums.empty())
      {
        section_sums[sections-1] += curr_folder_sum;
      }
      else section_sums.push_back(curr_folder_sum); // Add final section sum
      // printf("\n\n");
      if (sections < workers)
        hi = mid;
      else
        lo = mid + 1;
    } // end while

    printVector(section_sums);

    int min_max = *max_element(section_sums.begin(), section_sums.end());
    return min_max;
    // return lo;
  }
  */

  void printVector(const vector<int>& v)
  {
    printf("\n ----------- Section Sums ------------------\n");
    for(size_t i=0; i<v.size(); i++)
      printf("[%lu] \t  %d \n", i, v[i]);

    printf("\n\n");
  }

  /*
  // 1st implementation
  int getMostWork(vector<int>& folders, int workers)
  {
    int sections;
    size_t m = folders.size();
    int max_folders = 0;
    int min_max = std::numeric_limits<int>::max();

    for(int i=m-1; i>=0; i--)
    {
      max_folders += folders[i]; //inaccurate assumption
      // printf("\033[96m max_folders: %d, m: %lu, folders[m]: %d\033[m\n", max_folders, m, folders[m]);
      sections = 1;
      int curr_folder_sum = 0;

      for(int j=0; j<i; j++)
      {
        curr_folder_sum += folders[j];
        if (curr_folder_sum > max_folders)
        {
          sections++;
          curr_folder_sum = folders[j];
        }

        if(sections >= workers)
          break;
      }

      // printf("\033[94m max_folders: %d, sections: %d \033[m\n", max_folders, sections);
      if (max_folders < min_max && sections < workers)
        min_max = max_folders;
    }

    return min_max;
  }
  */
};

int main()
{
  FairWorkload f;

  // // Unit Test 0
  vector<int> folders = {10, 20, 30, 40, 50, 60, 70, 80, 90};
  int workers = 3;
  int m = f.getMostWork(folders, workers);
  printf("\033[92m m: \033[m %d \n", m);

  // Unit Test 1
  // 1st implementation breaks down on this unit test
  folders = { 10, 20, 30, 40, 50, 60, 70, 80, 90 };
  workers = 5;
  m = f.getMostWork(folders, workers);
  printf("\033[92m m: \033[m %d \n", m); 

  // Unit Test 2
  folders = { 568, 712, 412, 231, 241, 393, 865, 287, 128, 457, 238, 98, 980, 23, 782 };
  workers = 4;
  m = f.getMostWork(folders, workers);
  printf("\033[92m m: \033[m %d \n", m); 

  // Unit Test 3
  // 2nd implementation fails here - investigate
  folders = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1000};
  workers = 2;
  m = f.getMostWork(folders, workers);
  printf("\033[92m m: \033[m %d \n", m); 

  // // Unit Test 4
  folders = {50, 50, 50, 50, 50, 50, 50 };
  workers = 2;
  m = f.getMostWork(folders, workers);
  printf("\033[92m m: \033[m %d \n", m); 


  // Test Case from TopCoder
  folders = {1, 1, 1, 1, 100};
  workers = 5;
  m = f.getMostWork(folders, workers);
  printf("\033[92m m: \033[m %d \n", m); 
}

