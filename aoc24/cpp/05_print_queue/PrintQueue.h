//
// Created by Matt Insley on 12/5/24.
//

#ifndef CPP_PRINTQUEUE_H
#define CPP_PRINTQUEUE_H

#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <string>

namespace print_queue {
    class Node {
    public:
        int value;
        std::unordered_set<int> followers;
        std::unordered_set<int> predecessors;
        explicit Node(int value) : value(value), followers(), predecessors() {
        }
    };

    using Update = std::vector<int>;

    struct PrintQueue {
    public:
        std::unordered_map<int, Node> rules;
        std::vector<Update> updates;
    };

    PrintQueue parse(const std::string &inputStr);
    bool verify(const Update &update, const std::unordered_map<int, Node> &rules, int &middlePrinted);
    int solve1(PrintQueue &printQueue);
    bool verifyFixable(const Update &update, const std::unordered_map<int, Node> &rules, int &middlePrinted);
    int solve2(PrintQueue &printQueue);
}


#endif //CPP_PRINTQUEUE_H
