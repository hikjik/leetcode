#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<char> chars;
    int size;
    std::vector<char> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .chars{'a', 'a', 'b', 'b', 'c', 'c', 'c'},
          .size = 6,
          .expected{'a', '2', 'b', '2', 'c', '3'},
      },
      {
          .chars{'a'},
          .size = 1,
          .expected{'a'},
      },
      {
          .chars{'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b',
                 'b'},
          .size = 4,
          .expected{'a', 'b', '1', '2'},
      },
      {
          .chars{'a', 'a', 'a', 'b', 'b', 'a', 'a'},
          .size = 6,
          .expected{'a', '3', 'b', '2', 'a', '2'},
      },
  };

  for (auto &[chars, size, expected] : test_cases) {
    REQUIRE(size == Solution::compress(chars));
    chars.resize(size);
    REQUIRE(expected == chars);
  }
}
