#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> names;std::vector<int> heights;std::vector<std::string> expected;
  };

  std::vector<TestCase> test_cases{
      {.names{"Mary","John","Emma"},.heights{180,165,170},.expected{"Mary","Emma","John"},},{.names{"Alice","Bob","Bob"},.heights{155,185,150},.expected{"Bob","Alice","Bob"},},
  };

  for (const auto &[names,heights,expected] : test_cases) {
    const auto actual = Solution::sortPeople(names, heights);
    REQUIRE(expected == actual);
  }
}
