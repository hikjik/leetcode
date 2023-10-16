#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string key;
    std::string message;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .key = "the quick brown fox jumps over the lazy dog",
          .message = "vkbs bs t suepuv",
          .expected = "this is a secret",
      },
      {
          .key = "eljuxhpwnyrdgtqkviszcfmabo",
          .message = "zwx hnfx lqantp mnoeius ycgk vcnjrdb",
          .expected = "the five boxing wizards jump quickly",
      },
  };

  for (const auto &[key, message, expected] : test_cases) {
    const auto actual = Solution::decodeMessage(key, message);
    REQUIRE(expected == actual);
  }
}
