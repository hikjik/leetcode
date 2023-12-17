#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Priority Queue") {
  std::vector<std::string> foods{"kimchi",   "miso",  "sushi",
                                 "moussaka", "ramen", "bulgogi"};
  std::vector<std::string> cuisines{"korean", "japanese", "japanese",
                                    "greek",  "japanese", "korean"};
  std::vector<int> ratings{9, 12, 8, 15, 14, 7};
  auto food_ratings = pq::FoodRatings(foods, cuisines, ratings);

  REQUIRE("kimchi" == food_ratings.highestRated("korean"));
  REQUIRE("ramen" == food_ratings.highestRated("japanese"));
  food_ratings.changeRating("sushi", 16);
  REQUIRE("sushi" == food_ratings.highestRated("japanese"));
  food_ratings.changeRating("ramen", 16);
  REQUIRE("ramen" == food_ratings.highestRated("japanese"));
}

TEST_CASE("Set") {
  std::vector<std::string> foods{"kimchi",   "miso",  "sushi",
                                 "moussaka", "ramen", "bulgogi"};
  std::vector<std::string> cuisines{"korean", "japanese", "japanese",
                                    "greek",  "japanese", "korean"};
  std::vector<int> ratings{9, 12, 8, 15, 14, 7};
  auto food_ratings = set::FoodRatings(foods, cuisines, ratings);

  REQUIRE("kimchi" == food_ratings.highestRated("korean"));
  REQUIRE("ramen" == food_ratings.highestRated("japanese"));
  food_ratings.changeRating("sushi", 16);
  REQUIRE("sushi" == food_ratings.highestRated("japanese"));
  food_ratings.changeRating("ramen", 16);
  REQUIRE("ramen" == food_ratings.highestRated("japanese"));
}