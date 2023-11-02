#pragma once

#include <set>
#include <string>

// Time:
// Space:

class SORTracker {
private:
  struct Location {
    Location(std::string name, int score) : name(name), score(score) {}

    std::string name;
    int score;
  };

  struct LocationGreater {
    bool operator()(const Location &lhs, const Location &rhs) const {
      return lhs.score == rhs.score ? lhs.name < rhs.name
                                    : lhs.score > rhs.score;
    }
  };

  std::set<Location, LocationGreater> locations;
  std::set<Location, LocationGreater>::const_iterator it_best = locations.end();

public:
  void add(std::string name, int score) {
    auto [it, _] = locations.emplace(name, score);
    if (it_best == locations.end() || LocationGreater()(*it, *it_best)) {
      --it_best;
    }
  }

  std::string get() { return (it_best++)->name; }
};
