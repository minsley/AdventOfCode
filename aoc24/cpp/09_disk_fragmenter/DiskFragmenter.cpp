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

long DiskFragmenter::solve2(const std::vector<int> &input) {
    // create a list of files and free spaces
    int diskSize = static_cast<int>(input.size());
    int head = 0;
    std::vector<File> files;
    for(int i=0; i<diskSize; ++i){
        int id = i%2==0 ? i/2 : -1;
        files.push_back({.id = id, .size = input[i], .head = head});
        head += input[i];
    }

    // swap rear files into front free space
    for (int i = files.size()-1; i>0; i-=2) {
        if(files[i].id <= 0) continue;
        for (int j=1; j<i; j+=2) {
            if(files[j].size >= files[i].size){
                files[i].head = files[j].head;
                files[j].head += files[i].size;
                files[j].size -= files[i].size;
                break;
            }
        }
    }

    // calculate the checksum
    long sum = 0;
    for (int i=0; i<files.size(); i+=2){
        for (int j=files[i].head; j<files[i].head+files[i].size; ++j){
            sum += files[i].id * j;
        }
    }

    return sum;
}