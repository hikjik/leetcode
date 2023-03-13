#include <catch.hpp>

#include <solution.hpp>

#include <algorithm>

TEST_CASE("Simple") {
  {
    std::string s("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    std::vector<std::string> expected{"AAAAACCCCC", "CCCCCAAAAA"};
    auto actual = Solution::findRepeatedDnaSequences(s);
    std::sort(actual.begin(), actual.end());
    REQUIRE(expected == actual);
  }
  {
    std::string s("AAAAAAAAAAAAA");
    std::vector<std::string> expected{"AAAAAAAAAA"};
    auto actual = Solution::findRepeatedDnaSequences(s);
    std::sort(actual.begin(), actual.end());
    REQUIRE(expected == actual);
  }
  {
    std::string s("AAAAAAAAAAA");
    std::vector<std::string> expected{"AAAAAAAAAA"};
    auto actual = Solution::findRepeatedDnaSequences(s);
    std::sort(actual.begin(), actual.end());
    REQUIRE(expected == actual);
  }
  {
    std::string s(
        "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
        "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
        "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
        "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
        "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
        "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
        "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
        "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
    std::vector<std::string> expected{"AAAAAAAAAA"};
    auto actual = Solution::findRepeatedDnaSequences(s);
    std::sort(actual.begin(), actual.end());
    REQUIRE(expected == actual);
  }
}
