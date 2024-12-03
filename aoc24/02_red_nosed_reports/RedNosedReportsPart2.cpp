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

bool isValidDelta(int delta) {
    int a = abs(delta);
    return a >= 1 && a <= 3;
}

bool isValidDelta(int delta, bool increasing) {
    return ((increasing && delta > 0) || (!increasing && delta < 0)) && isValidDelta(delta);
}

int RedNosedReports::solve2(std::vector<std::vector<int> > reports) {
    int safeCt = 0;

    for(auto report : reports) {
        bool valid = true;

        // assume any empty or single item report is valid?
        if(report.size() >= 2) {

            // generate deltas for this report
            std::vector<int> deltas[report.size()-1];
            for(int i=0; i<report.size()-1; i++) {
                deltas->assign(i, report[i+1]-report[i]);
            }

            // if(report.size() == 3 && isValidDelta())

            // first pair determines if rest must incr or decr
            bool increasing = report[1] > report[0];

            for(int i=1; i<report.size(); i++) {
                int diff = report[i] - report[i-1];

                // invalidate report if not all incr by +1 to +3, or decr by -1 to -3
                valid = isValidDelta(diff, increasing);
                if(!valid) {
                    break;
                }
            }
        }

        if(valid) safeCt++;
    }

    return safeCt;
}
