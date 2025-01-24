//
// Created by Matt Insley on 12/10/24.
//

#include "DiskFragmenter.h"

long DiskFragmenter::solve1(const std::vector<int> &input) {
    long sum = 0;

    int diskSize = static_cast<int>(input.size());
    int i=0;
    int j = diskSize % 2 == 0 ? diskSize-2 : diskSize-1; // start on the last file, skip trailing free space
    int block=0;
    int jj=0;
    while(i <= j){
        if(i%2==0){
            // i is a file
            // multiply the file id (i) by indices range between blocks already passed (iBlocks) and the end of the file (iBlocks + input[i])
            for(size_t ii = i==j?jj:0; ii < input[i]; ++ii){
                sum += i / 2 * block++;
            }
            ++i;
        } else {
            // i is free space
            // count in our j file until we run out of i free space
            for(size_t ii=0; ii < input[i]; ++ii){
                // if we still have i space left, move to next j file
                if(jj == input[j]){
                    jj=0;
                    j-=2;

                    // if we've run out of files, return the sum
                    if(j<=i) return sum;
                }
                // multiply the file id (j) by indices range between blocks already passed (iBlocks) and the end of the free space (iBlocks + input[i])
                sum += j / 2 * block++;
                ++jj;
            }
            ++i;
        }
    }

    return sum;
}