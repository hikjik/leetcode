#pragma once

#include <algorithm>
#include <vector>

class Solution {
public:
  static int numRescueBoats(std::vector<int> people, int limit) {
    std::sort(people.begin(), people.end());

    int i = 0, j = people.size() - 1;
    int cnt = 0;
    while (i <= j) {
      if (people[i] + people[j] <= limit) {
        i++;
      }
      j--;
      cnt++;
    }
    return cnt;
  }
};
