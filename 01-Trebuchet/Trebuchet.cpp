//
// Created by mins on 11/27/2024.
//

#include "Trebuchet.h"

/*
Problem:
On each line, the calibration value can be found by combining the first digit and the last digit (in that order) to form a single two-digit number.

For example:
1abc2
pqr3stu8vwx
a1b2c3d4e5f
treb7uchet

In this example, the calibration values of these four lines are 12, 38, 15, and 77. Adding these together produces 142.
Consider your entire calibration document. What is the sum of all of the calibration values?

Solution(s):
A. cheat and use regex to match first last digit per line as group, parse groups to ints, sum groups
-> B. rely on them being single digits, do one fwd pass through file that parses first int (bitshifted 10x), tracks last int, combines and sums when hitting newline, repeat
*/

int Trebuchet::solve1(const char* input) {
   bool newline = true;
   int first = 0;
   int last = 0;
   int sum = 0;

   int i=0;
   bool eof = false;
   while (!eof) {
      const char c = input[i++];
      eof = c == '\0';

      // on newline, roll our sum and reset trackers
      if(c == '\n' || eof) {
         newline = true;
         const int val = first*10 + last;
         sum += val;
         first = last = 0;
         continue;
      }

      // parse and track first and last digits
      if(const int val = c - '0'; val >= 0 && val <= 9) {
         if(newline) {
            first = last = val;
            newline = false;
         } else {
            last = val;
         }
      }
   }

   return sum;
}

/*
Problem:
Your calculation isn't quite right. It looks like some of the digits are actually spelled out with letters: one, two, three, four, five, six, seven, eight, and nine also count as valid "digits".

Equipped with this new information, you now need to find the real first and last digit on each line. For example:

two1nine
eightwothree
abcone2threexyz
xtwone3four
4nineeightseven2
zoneight234
7pqrstsixteen
In this example, the calibration values are 29, 83, 13, 24, 42, 14, and 76. Adding these together produces 281.

What is the sum of all of the calibration values?

Solution:
Same B, but now we read ahead to parse specific 1-9 words. Note that words can overlap, so we'll step each char
*/
int Trebuchet::solve2(const char *input) {
   bool newline = true;
   int first = 0;
   int last = 0;
   int sum = 0;

   int i=0;
   bool eof = false;
   while (!eof) {
      const char c = input[i];
      eof = c == '\0';

      // on newline, roll our sum and reset trackers
      if(c == '\n' || eof) {
         newline = true;
         const int val = first*10 + last;
         sum += val;
         first = last = 0;
         i++;
         continue;
      }

      // parse digits (dumb and fast, since there are only 9 with no casing anyway)
      int val = 0;
      bool parsed = false;
      if(c >= '0' && c <= '9') {
         val = c - '0';
         parsed = true;
      } else if(input[i]=='o' && input[i+1]=='n' && input[i+2]=='e') {
         val = 1;
         parsed = true;
      } else if(input[i]=='t' && input[i+1]=='w' && input[i+2]=='o') {
         val = 2;
         parsed = true;
      } else if(input[i]=='t' && input[i+1]=='h' && input[i+2]=='r' && input[i+3]=='e' && input[i+4]=='e') {
         val = 3;
         parsed = true;
      } else if(input[i]=='f' && input[i+1]=='o' && input[i+2]=='u' && input[i+3]=='r') {
         val = 4;
         parsed = true;
      } else if(input[i]=='f' && input[i+1]=='i' && input[i+2]=='v' && input[i+3]=='e') {
         val = 5;
         parsed = true;
      } else if(input[i]=='s' && input[i+1]=='i' && input[i+2]=='x') {
         val = 6;
         parsed = true;
      } else if(input[i]=='s' && input[i+1]=='e' && input[i+2]=='v' && input[i+3]=='e' && input[i+4]=='n') {
         val = 7;
         parsed = true;
      } else if(input[i]=='e' && input[i+1]=='i' && input[i+2]=='g' && input[i+3]=='h' && input[i+4]=='t') {
         val = 8;
         parsed = true;
      } else if(input[i]=='n' && input[i+1]=='i' && input[i+2]=='n' && input[i+3]=='e') {
         val = 9;
         parsed = true;
      }

      // if we got a digit, track first and last
      if(parsed) {
         if(newline) {
            first = last = val;
            newline = false;
         } else {
            last = val;
         }
      }

      i++;
   }

   return sum;
}
