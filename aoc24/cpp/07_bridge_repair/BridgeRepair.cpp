//
// Created by Matt Insley on 12/7/24.
//

#include "BridgeRepair.h"

bool BridgeRepair::evalEq1(long solution, long state, const std::span<const long> args) {
    if(args.empty()) {
        return solution == state;
    }

    if(state > solution) {
        return false;
    }

    return evalEq1(solution, state + args[0], args.subspan(1)) ||
           evalEq1(solution, state * args[0], args.subspan(1));
}

long BridgeRepair::solve1(InputSet &input) {
    long sum = 0;
    for (const auto &eq : input) {
        auto val = eq.right[0];
        auto sub = std::span(eq.right).subspan(1);
        if (BridgeRepair::evalEq1(eq.left, val, sub)) {
            sum += eq.left;
        }
    }
    return sum;
}

long BridgeRepair::pow10(long num, long pow){
    num <<= pow;
    while(pow--) num += num << 2;
    return num;
}

long BridgeRepair::concat(long a, long b) {
    auto shift = b == 0
         ? 1 // log10(0) is undefined, but it's ok, we just want to shift by the number of digits
         : (long)log10l((long double)b) + 1;
    return pow10(a, shift) + b;
}

bool BridgeRepair::evalEq2(long solution, long state, const std::span<const long> args) {
    if(args.empty()) {
        return solution == state;
    }

    if(state > solution) {
        return false;
    }

    auto val = args[0];
    auto sub = args.subspan(1);
    return evalEq2(solution, state * val, sub) ||
           evalEq2(solution, concat(state, val), sub) ||
           evalEq2(solution, state + val, sub);
}

long BridgeRepair::solve2(InputSet &input) {
    long sum = 0;
    for (const auto &eq : input) {
        auto val = eq.right[0];
        auto sub = std::span(eq.right).subspan(1);
        if (BridgeRepair::evalEq2(eq.left, val, sub)) {
            sum += eq.left;
        }
    }
    return sum;
}