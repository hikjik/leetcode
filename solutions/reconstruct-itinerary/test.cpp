#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<std::string>> tickets{
        {"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
    std::vector<std::string> expected{"JFK", "MUC", "LHR", "SFO", "SJC"};
    REQUIRE(expected == Solution::findItinerary(tickets));
  }
  {
    std::vector<std::vector<std::string>> tickets{{"JFK", "SFO"},
                                                  {"JFK", "ATL"},
                                                  {"SFO", "ATL"},
                                                  {"ATL", "JFK"},
                                                  {"ATL", "SFO"}};
    std::vector<std::string> expected{"JFK", "ATL", "JFK", "SFO", "ATL", "SFO"};
    REQUIRE(expected == Solution::findItinerary(tickets));
  }
  {
    std::vector<std::vector<std::string>> tickets{
        {"EZE", "AXA"}, {"TIA", "ANU"}, {"ANU", "JFK"}, {"JFK", "ANU"},
        {"ANU", "EZE"}, {"TIA", "ANU"}, {"AXA", "TIA"}, {"TIA", "JFK"},
        {"ANU", "TIA"}, {"JFK", "TIA"}};
    std::vector<std::string> expected{"JFK", "ANU", "EZE", "AXA", "TIA", "ANU",
                                      "JFK", "TIA", "ANU", "TIA", "JFK"};
    REQUIRE(expected == Solution::findItinerary(tickets));
  }
}
