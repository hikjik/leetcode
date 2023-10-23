#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  int n = 5;
  auto ordered_stream = OrderedStream(n);

  REQUIRE(std::vector<std::string>{} == ordered_stream.insert(3, "ccccc"));
  REQUIRE(std::vector<std::string>{"aaaaa"} ==
          ordered_stream.insert(1, "aaaaa"));
  REQUIRE(std::vector<std::string>{"bbbbb", "ccccc"} ==
          ordered_stream.insert(2, "bbbbb"));
  REQUIRE(std::vector<std::string>{} == ordered_stream.insert(5, "eeeee"));
  REQUIRE(std::vector<std::string>{"ddddd", "eeeee"} ==
          ordered_stream.insert(4, "ddddd"));
}
