//
// Created by mins on 12/2/2024.
//

#include <cmath>
#include <vector>

#include "RedNosedReports.h"

using namespace RedNosedReports;

bool RedNosedReports::isValidDelta(int delta) {
    int a = abs(delta);
    return a >= 1 && a <= 3;
}

bool RedNosedReports::isValidDelta(int delta, bool increasing) {
    return ((increasing && delta > 0) || (!increasing && delta < 0)) && isValidDelta(delta);
}

bool RedNosedReports::isValidReport1(std::vector<int> &report) {
    if(report.size() < 2) {
        return true;
    }

    bool increasing = report[1] > report[0];

    for(int i=1; i<report.size(); i++) {
        int delta = report[i] - report[i-1];
        if(!RedNosedReports::isValidDelta(delta, increasing)) {
            return false;
        }
    }

    return true;
}

int RedNosedReports::solve1(std::vector<std::vector<int>> &reports) {
    int safeCt = 0;

    for(auto report: reports) {
        bool valid = isValidReport1(report);
        if(valid) safeCt++;
    }

    return safeCt;
}
