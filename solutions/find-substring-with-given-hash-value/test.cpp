#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int power;
    int modulo;
    int k;
    int hashValue;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "leetcode",
          .power = 7,
          .modulo = 20,
          .k = 2,
          .hashValue = 0,
          .expected = "ee",
      },
      {
          .s = "fbxzaad",
          .power = 31,
          .modulo = 100,
          .k = 3,
          .hashValue = 32,
          .expected = "fbx",
      },
  };

  for (const auto &[s, power, modulo, k, hashValue, expected] : test_cases) {
    const auto actual = Solution::subStrHash(s, power, modulo, k, hashValue);
    REQUIRE(expected == actual);
  }
}
