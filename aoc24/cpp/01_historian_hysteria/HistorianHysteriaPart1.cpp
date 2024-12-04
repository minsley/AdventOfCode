//
// Created by mins on 12/2/2024.
//

#include "HistorianHysteria.h"

#include <algorithm>
#include <vector>

using namespace HistorianHysteria;

/*
Sort both lists, step through and roll sum of differences.
*/

int HistorianHysteria::solve1(std::vector<int> list1, std::vector<int> list2) {
   int sum = 0;

   std::sort(list1.begin(), list1.end());
   std::sort(list2.begin(), list2.end());

   for (int i=0; i<list1.size(); i++) {
      const int n1 = list1[i];
      const int n2 = list2[i];
      
      sum += (n1 > n2 ? n1-n2 : n2-n1);
   }

   return sum;
}
