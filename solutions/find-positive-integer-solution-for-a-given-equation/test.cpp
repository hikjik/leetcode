#include <catch.hpp>

#include <solution.hpp>

class Plus : public CustomFunction {
  int f(int x, int y) override { return x + y; };
};

class Mult : public CustomFunction {
  int f(int x, int y) override { return x * y; };
};

TEST_CASE("Simple") {
  struct TestCase {
    int num;
    int z;
    std::vector<std::vector<int>> expected;
  };

  std::vector<std::unique_ptr<CustomFunction>> functions;
  functions.push_back(std::make_unique<Plus>());
  functions.push_back(std::make_unique<Mult>());

  std::vector<TestCase> test_cases{
      {
          .num = 0,
          .z = 5,
          .expected{{1, 4}, {2, 3}, {3, 2}, {4, 1}},
      },
      {
          .num = 1,
          .z = 5,
          .expected{{1, 5}, {5, 1}},
      },
  };

  SECTION("Brute Force") {
    for (const auto &[num, z, expected] : test_cases) {
      const auto actual =
          brute_force::Solution::findSolution(*functions[num], z);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Binary Search") {
    for (const auto &[num, z, expected] : test_cases) {
      const auto actual =
          binary_search::Solution::findSolution(*functions[num], z);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Linear") {
    for (const auto &[num, z, expected] : test_cases) {
      const auto actual = linear::Solution::findSolution(*functions[num], z);
      REQUIRE(expected == actual);
    }
  }
}
