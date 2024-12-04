//
// Created by mins on 12/2/2024.
//

#ifndef REDNOSEDREPORTS_H
#define REDNOSEDREPORTS_H

namespace RedNosedReports {
    bool isValidDelta(int delta);
    bool isValidDelta(int delta, bool increasing);
    bool isValidReport1(std::vector<int> &report);
    bool isValidReport2(std::vector<int> &report);
    int solve1(std::vector<std::vector<int>> &reports);
    int solve2(std::vector<std::vector<int>> &reports);
}

#endif //REDNOSEDREPORTS_H
