#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string version1;
    std::string version2;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .version1 = "1.01",
          .version2 = "1.001",
          .expected = 0,
      },
      {
          .version1 = "1.0",
          .version2 = "1.0.0",
          .expected = 0,
      },
      {
          .version1 = "0.1",
          .version2 = "1.1",
          .expected = -1,
      },
  };

  for (const auto &[version1, version2, expected] : test_cases) {
    const auto actual = Solution::compareVersion(version1, version2);
    REQUIRE(expected == actual);
  }
}
