//
// Created by Matt Insley on 12/10/24.
//

#ifndef AOC24_DISKFRAGMENTER_H
#define AOC24_DISKFRAGMENTER_H

#include <vector>

namespace DiskFragmenter {
    struct File {
        int id;
        int head;
        int size;
    };

    long solve1(const std::vector<int> &input);
    long solve2(const std::vector<int> &input);
}
#endif //AOC24_DISKFRAGMENTER_H
