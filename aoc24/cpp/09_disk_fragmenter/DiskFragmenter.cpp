//
// Created by Matt Insley on 12/10/24.
//

#include "DiskFragmenter.h"

int DiskFragmenter::solve1(const std::vector<int> &input) {
    int sum = 0;

    size_t diskSize = input.size();
    size_t i=0;
    size_t j = diskSize % 2 == 0 ? diskSize-2 : diskSize-1; // start on the last file, skip trailing free space
    size_t iBlocks=0;
    size_t jj=0;
    while(i < j){
        if(i%2==0){
            // i is a file
            // multiply the file id (i) by indices range between blocks already passed (iBlocks) and the end of the file (iBlocks + input[i])
            for(size_t ii = 0; ii < input[i]; ii++){
                sum += i * (iBlocks + ii);
                iBlocks++;
            }
            i++;
        } else {
            // i is free space
            // count in our j file until we run out of i free space
            for(size_t ii=0; ii < input[i]; ii++){
                // if we stll have i space left, move to next j file
                if(jj == input[j]){
                    jj=0;
                    j-=2;
                }
                // multiply the file id (j) by indices range between blocks already passed (iBlocks) and the end of the free space (iBlocks + input[i])
                sum += j/2 * (iBlocks + ii);
                iBlocks++;
                jj++;
            }
            i++;
        }
    }

    return sum;
}