//
// Created by mins on 12/2/2024.
//

#include <vector>

#include "RedNosedReports.h"

using namespace RedNosedReports;

int RedNosedReports::solve1(std::vector<std::vector<int> > reports) {
    int safeCt = 0;

    for(auto report : reports) {
        bool valid = true;

        // assume any empty or single item report is valid?
        if(report.size() >= 2) {

            // first pair determines if rest must incr or decr
            bool increasing = report[1] > report[0];

            for(int i=1; i<report.size(); i++) {
                int diff = report[i] - report[i-1];

                // invalidate report if not all incr by +1 to +3, or decr by -1 to -3
                valid = (increasing && diff >= 1 && diff <= 3) || (!increasing && diff <= -1 && diff >= -3);
                if(!valid) {
                    break;
                }
            }
        }

        if(valid) safeCt++;
    }

    return safeCt;
}
