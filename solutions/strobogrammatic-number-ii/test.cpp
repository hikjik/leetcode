#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<std::string> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 2,
          .expected{"11", "69", "88", "96"},
      },
      {
          .n = 1,
          .expected{"0", "1", "8"},
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::findStrobogrammatic(n);
    REQUIRE_THAT(expected, Catch::Matchers::UnorderedEquals(actual));
  }
}
