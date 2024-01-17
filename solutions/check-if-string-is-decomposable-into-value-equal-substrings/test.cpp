#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "000111000",
          .expected = false,
      },
      {
          .s = "00011111222",
          .expected = true,
      },
      {
          .s = "011100022233",
          .expected = false,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::isDecomposable(s);
    REQUIRE(expected == actual);
  }
}
