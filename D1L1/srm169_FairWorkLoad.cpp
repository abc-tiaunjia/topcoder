/*===========================================================================================
* Name : srm169_FairWorkLoad.cpp
* Author: tiaunjia
* Description: SRM 169 D1L2 & D2L3.
* Sources: 
*        [1] https://community.topcoder.com/stat?c=problem_statement&pm=1901&rd=4650
* Date Created: Sat.Oct.8.2016
*=============================================================================================*/

#include <limits>
#include <cstdio>
#include <vector>

using std::vector;


class FairWorkLoad
{

public:
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
};

int main()
{
  FairWorkLoad f;
  vector<int> folders = {10, 20, 30, 40, 50, 60, 70, 80, 90};
  int workers = 3;


  int m = f.getMostWork(folders, workers);

  printf("\033[92m m: \033[m %d \n", m);

  folders = { 10, 20, 30, 40, 50, 60, 70, 80, 90 };
  workers = 5;
  m = f.getMostWork(folders, workers);
  printf("\033[92m m: \033[m %d \n", m); // incorrect, returns 170, should return 110

}