//
// Created by mins on 12/2/2024.
//

#include <cmath>
#include <vector>

#include "RedNosedReports.h"

using namespace RedNosedReports;

/*
Now we're allowed to remove 1 number from a sequence to make it compliant.
Determining incr or decr now requires 4 numbers depending on where you remove from.
Edge cases (underscore indicates deletion):
[] valid
[2] valid
[2,3] valid
[2,6] -> [_,6] or [2,_] valid because we can delete one
[2,3,9] -> [2,3,_] valid
[2,3,1] -> [2,3,_] or [_,3,1] or [2,_,1] valid
[2,3,1,4] -> [2,3,_,4] valid

General rules are:
1. a set of 2 or fewer is inherently valid
2. a set of 3 [A,B,C] is valid iff any pair AB, BC, AC is valid
3. a set of 4 or more must have a definite incr/decr direction
4. a set of 4 or more is valid if all pairs are valid and match direction
5. a set of 4 or more is valid if removing a single number puts the rest into case 4

I think parsing into pairwise deltas would be elegant.
For example:

[2,3,1,6]
[+1,-2,+5]
The presence of sign flip is invalidating.
If there is more than one flipped sign, the whole sequence is invalid.

Combining 2 deltas effectively removes the middle number
[+1,+3]
If the flipped sign can be combined with a neighbor to result in a valid jump [-3,-1]U[1,3] then the sequence is fixable.

[3,2,1,6]
[-1,-1,+5]
[-1,-1,_]
Additionally, either end may be discarded.
*/

bool RedNosedReports::isValidReport2(std::vector<int> &report) {
    int reportSize = report.size();

    // any set of 2 or fewer is valid
    if(reportSize == 0 || reportSize == 1 || reportSize == 2) {
        return true;
    }

    // any pair must be valid
    if(reportSize == 3) {
        return isValidDelta(report[1]-report[0]) || isValidDelta(report[2]-report[1]) || isValidDelta(report[2]-report[0]);
    }

    // generate deltas for this report
    std::vector<int> deltas(reportSize - 1);
    int pos = 0, neg = 0;
    for(int i=0; i<report.size()-1; i++) {
        int del = report[i+1] - report[i];
        deltas.at(i) = del;
        if(del > 0) pos++;
        if(del < 0) neg++;
    }

    // identify overall incr/decr direction
    bool increasing = pos > neg;

    // if more than 1 bad delta, invalid
    std::vector<int> badIds;
    for(int i=0; i<deltas.size(); i++){
        if(!isValidDelta(deltas[i], increasing)) {
            badIds.push_back(i);
        }
    }

    if(badIds.empty()) {
        // no bad deltas, valid
        return true;
    } else  if(badIds.size() == 1) {
        int badId = badIds[0];
        // if we have 1 bad delta, and it's on either end, we're free to remove it: valid
        if(badId == 0 || badId == deltas.size()-1) return true;

        // if we can combine the bad delta with left neighbor to make a valid delta, we're good
        int leftCombinedDelta = deltas[badId-1] + deltas[badId];
        int leftValid = isValidDelta(leftCombinedDelta, increasing);
        if(leftValid) return true;

        // if we can combine the bad delta with right neighbor to make a valid delta, we're good
        int rightCombinedDelta = deltas[badId] + deltas[badId+1];
        int rightValid = isValidDelta(rightCombinedDelta, increasing);
        if(rightValid) return true;

        return false;
    } else if (badIds.size() == 2){
        // if we have 2 adjacent bad deltas that we can combine to make a valid delta, we're saved
        bool adjacent = badIds[1] - badIds[0] == 1;
        if(!adjacent) return false;

        int combinedDelta = deltas[badIds[0]] + deltas[badIds[1]];
        bool combinedValid = isValidDelta(combinedDelta, increasing);
        return combinedValid;
    } else {
        // too many bad deltas to fix
        return false;
    }
}

int RedNosedReports::solve2(std::vector<std::vector<int>> &reports) {
    int safeCt = 0;

    for(auto report : reports) {
        bool valid = isValidReport2(report);
        if(valid) safeCt++;
    }

    return safeCt;
}
