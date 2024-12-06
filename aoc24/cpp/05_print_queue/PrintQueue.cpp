//
// Created by Matt Insley on 12/5/24.
//

#include <sstream>
#include "PrintQueue.h"
#include <unordered_set>

using namespace print_queue;

PrintQueue print_queue::parse(const std::string &inputStr) {
    PrintQueue printQueue;
    printQueue = PrintQueue{
        .rules = std::unordered_map<int, Node>(),
        .updates = std::vector<Update>()
    };

    std::istringstream iss(inputStr);
    std::string line;
    bool firstSection = true;
    std::string delim = "|";
    while(std::getline(iss, line)) {
        if (line.empty()) {
            firstSection = false;
            continue;
        }
        if(firstSection) {
            size_t sep = line.find(delim);
            int value1 = std::stoi(line.substr(0, sep));
            int value2 = std::stoi(line.substr(sep+1));
            Node &first = printQueue.rules.emplace(value1, Node(value1)).first->second;
            Node &second = printQueue.rules.emplace(value2, Node(value2)).first->second;
            first.followers.insert(value2);
            second.predecessors.insert(value1);
        } else {
            Update update;
            std::istringstream iss(line);
            std::string value;
            while (std::getline(iss, value, ',')) {
                update.push_back(std::stoi(value));
            }
            printQueue.updates.push_back(update);
        }
    }

    return printQueue;
}

bool print_queue::verify(const Update &update, const std::unordered_map<int, Node> &rules, int &middlePrinted) {
    for(int i=0; i<update.size(); i++) {
        int num = update[i];
        const Node &node = rules.at(num);
        for(int j=i+1; j<update.size(); j++) {
            int nextNum = update[j];
            if(node.followers.find(nextNum) == node.followers.end()) {
                return false;
            }
        }
        for(int k=i-1; k>=0; k--) {
            int prevNum = update[k];
            auto it = node.predecessors.find(prevNum);
            bool found = it != node.predecessors.end();
            if(!found) {
                return false;
            }
        }
    }
    middlePrinted = update[update.size()/2];
    return true;
}

int print_queue::solve(PrintQueue &printQueue) {
    int sumOfMids = 0;
    for(auto &update : printQueue.updates) {
        int middlePrinted = 0;
        if(verify(update, printQueue.rules, middlePrinted)) {
            sumOfMids += middlePrinted;
        }
    }
    return sumOfMids;
}