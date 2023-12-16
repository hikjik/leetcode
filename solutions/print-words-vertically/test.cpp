#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::vector<std::string> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "TO BE OR NOT TO BE",
          .expected{"TBONTB", "OEROOE", "   T"},
      },
      {
          .s = "HOW ARE YOU",
          .expected{"HAY", "ORO", "WEU"},
      },
      {
          .s = "CONTEST IS COMING",
          .expected{"CIC", "OSO", "N M", "T I", "E N", "S G", "T"},
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::printVertically(s);
    REQUIRE(expected == actual);
  }
}
