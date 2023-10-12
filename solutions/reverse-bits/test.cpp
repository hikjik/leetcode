#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    uint32_t n;
    uint32_t expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 43261596,
          .expected = 964176192,
      },
      {
          .n = 4294967293,
          .expected = 3221225471,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::reverseBits(n);
    REQUIRE(expected == actual);
  }
}
