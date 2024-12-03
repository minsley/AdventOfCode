//
// Created by mins on 12/2/2024.
//

#include <algorithm>
#include <vector>

#include "HistorianHysteria.h"
using namespace HistorianHysteria;

/*
Sort both lists, step through and roll sum of differences.
*/

int HistorianHysteria::solve1(std::vector<int> list1, std::vector<int> list2) {
   int sum = 0;

   std::sort(list1.begin(), list1.end());
   std::sort(list2.begin(), list2.end());

   for (int j=0; j<list1.size(); j++) {
      const int n1 = list1[j];
      const int n2 = list2[j];
      
      sum += (n1 > n2 ? n1-n2 : n2-n1);
   }

   return sum;
}
