//
// Created by mins on 12/2/2024.
//

#include "HistorianHysteria.h"

#include <algorithm>
#include <map>
#include <vector>

using namespace HistorianHysteria;

/*
Sort both lists, count occurences in list2, muladd score for each in list1.
*/

int HistorianHysteria::solve2(std::vector<int> list1, std::vector<int> list2) {

    std::sort(list1.begin(), list1.end());
    std::sort(list2.begin(), list2.end());

    std::map<int, int> counts;
    for(auto j : list2) {
        counts[j] += 1;
    }

    int similarityScore = 0;
    for(auto i : list1) {
        similarityScore += i * counts[i];
    }

    return similarityScore;
}
