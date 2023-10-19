#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string address;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .address = "1.1.1.1",
          .expected = "1[.]1[.]1[.]1",
      },
      {
          .address = "255.100.50.0",
          .expected = "255[.]100[.]50[.]0",
      },
  };

  for (const auto &[address, expected] : test_cases) {
    const auto actual = Solution::defangIPaddr(address);
    REQUIRE(expected == actual);
  }
}
