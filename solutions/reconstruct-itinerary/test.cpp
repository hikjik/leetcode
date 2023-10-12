#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<std::string>> tickets;
    std::vector<std::string> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .tickets{
              {"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}},
          .expected{"JFK", "MUC", "LHR", "SFO", "SJC"},
      },
      {
          .tickets{{"JFK", "SFO"},
                   {"JFK", "ATL"},
                   {"SFO", "ATL"},
                   {"ATL", "JFK"},
                   {"ATL", "SFO"}},
          .expected{"JFK", "ATL", "JFK", "SFO", "ATL", "SFO"},
      },
  };

  for (const auto &[tickets, expected] : test_cases) {
    const auto actual = Solution::findItinerary(tickets);
    REQUIRE(expected == actual);
  }
}
