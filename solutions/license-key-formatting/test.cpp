#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int k;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "5F3Z-2e-9-w",
          .k = 4,
          .expected = "5F3Z-2E9W",
      },
      {
          .s = "2-5g-3-J",
          .k = 2,
          .expected = "2-5G-3J",
      },
      {
          .s = "--22--",
          .k = 2,
          .expected = "22",
      },
  };

  for (const auto &[s, k, expected] : test_cases) {
    const auto actual = Solution::licenseKeyFormatting(s, k);
    REQUIRE(expected == actual);
  }
}
