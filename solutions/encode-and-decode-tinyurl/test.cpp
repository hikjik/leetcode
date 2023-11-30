#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string url;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .url = "https://leetcode.com/problems/design-tinyurl",
          .expected = "https://leetcode.com/problems/design-tinyurl",
      },
  };

  for (const auto &[url, expected] : test_cases) {
    Solution codec;
    const auto actual = codec.decode(codec.encode(url));
    REQUIRE(expected == actual);
  }
}
