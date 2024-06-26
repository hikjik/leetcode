#include <catch.hpp>

#include <solution.hpp>

#include <unordered_map>

TEST_CASE("Simple") {
  {
    std::vector<int> w{1};
    auto solution = Solution(w);

    REQUIRE(0 == solution.pickIndex());
  }
  {
    {
      std::vector<int> weights{1, 3};
      const auto sum = std::accumulate(weights.begin(), weights.end(), 0);
      Solution solution(weights);
      std::unordered_map<int, double> frequencies;

      const size_t kN = 1e5;
      for (size_t i = 0; i < kN; ++i) {
        frequencies[solution.pickIndex()]++;
      }

      REQUIRE(2 == frequencies.size());
      for (size_t i = 0; i < weights.size(); ++i) {
        REQUIRE_THAT(frequencies[i] / kN,
                     Catch::Matchers::WithinAbs(weights[i] * 1.0 / sum, 1e-2));
      }
    }
  }
}
