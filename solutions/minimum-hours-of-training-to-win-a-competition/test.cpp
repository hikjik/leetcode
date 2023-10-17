#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int initialEnergy;
    int initialExperience;
    std::vector<int> energy;
    std::vector<int> experience;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .initialEnergy = 5,
          .initialExperience = 3,
          .energy{1, 4, 3, 2},
          .experience{2, 6, 3, 1},
          .expected = 8,
      },
      {
          .initialEnergy = 2,
          .initialExperience = 4,
          .energy{1},
          .experience{3},
          .expected = 0,
      },
  };

  for (const auto &[initialEnergy, initialExperience, energy, experience,
                    expected] : test_cases) {
    const auto actual = Solution::minNumberOfHours(
        initialEnergy, initialExperience, energy, experience);
    REQUIRE(expected == actual);
  }
}
