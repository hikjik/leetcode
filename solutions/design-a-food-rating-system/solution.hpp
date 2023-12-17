#pragma once

#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

// Time: O((N+Q)logN)
// Space: O(N)

namespace set {

// Time: O((N+Q)logN)
// Space: O(N)
class FoodRatings {
public:
  // O(NlogN)
  FoodRatings(const std::vector<std::string> &foods,
              const std::vector<std::string> &cuisines,
              const std::vector<int> &ratings) {
    for (int i = 0; i < std::ssize(foods); ++i) {
      foodToCuisines[foods[i]] = cuisines[i];
      foodToRating[foods[i]] = ratings[i];
      cuisineToFood[cuisines[i]].insert({-ratings[i], foods[i]});
    }
  }

  // O(logN)
  void changeRating(std::string food, int newRating) {
    const auto cuisine = foodToCuisines[food];
    const auto oldRating = foodToRating[food];
    cuisineToFood[cuisine].erase({-oldRating, food});
    cuisineToFood[cuisine].insert({-newRating, food});
    foodToRating[food] = newRating;
  }

  // O(1)
  std::string highestRated(std::string cuisine) const {
    return cuisineToFood.at(cuisine).begin()->second;
  }

private:
  std::unordered_map<std::string, int> foodToRating;
  std::unordered_map<std::string, std::string> foodToCuisines;
  std::unordered_map<std::string, std::set<std::pair<int, std::string>>>
      cuisineToFood;
};

} // namespace set

namespace pq {

// Time: O((N+Q)logN)
// Space: O(N)
class FoodRatings {
public:
  // O(NlogN)
  FoodRatings(const std::vector<std::string> &foods,
              const std::vector<std::string> &cuisines,
              const std::vector<int> &ratings) {
    for (int i = 0; i < std::ssize(foods); ++i) {
      foodToCuisines[foods[i]] = cuisines[i];
      foodToRating[foods[i]] = ratings[i];
      cuisineToFood[cuisines[i]].push({-ratings[i], foods[i]});
    }
  }

  // O(logN)
  void changeRating(std::string food, int newRating) {
    const auto cuisine = foodToCuisines[food];
    cuisineToFood[cuisine].push({-newRating, food});
    foodToRating[food] = newRating;
  }

  // O(1)
  std::string highestRated(std::string cuisine) {
    auto top = cuisineToFood[cuisine].top();
    while (top.first != -foodToRating[top.second]) {
      cuisineToFood[cuisine].pop();
      top = cuisineToFood[cuisine].top();
    }
    return top.second;
  }

private:
  std::unordered_map<std::string, int> foodToRating;
  std::unordered_map<std::string, std::string> foodToCuisines;
  std::unordered_map<
      std::string, std::priority_queue<std::pair<int, std::string>,
                                       std::vector<std::pair<int, std::string>>,
                                       std::greater<>>>
      cuisineToFood;
};

} // namespace pq
