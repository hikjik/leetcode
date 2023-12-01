#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Hash Table") {
  {
    Tree root{-1, std::nullopt, -1};
    hash_table::FindElements find_elements(root);

    REQUIRE(false == find_elements.find(1));
    REQUIRE(true == find_elements.find(2));
  }
  {
    Tree root{-1, -1, -1, -1, -1};
    hash_table::FindElements find_elements(root);

    REQUIRE(true == find_elements.find(1));
    REQUIRE(true == find_elements.find(3));
    REQUIRE(false == find_elements.find(5));
  }
  {
    Tree root{-1, std::nullopt, -1, -1, std::nullopt, -1};
    hash_table::FindElements find_elements(root);

    REQUIRE(true == find_elements.find(2));
    REQUIRE(false == find_elements.find(3));
    REQUIRE(false == find_elements.find(4));
    REQUIRE(true == find_elements.find(5));
  }
}

TEST_CASE("No Extra Space") {
  {
    Tree root{-1,           -1,           std::nullopt, -1, -1,
              std::nullopt, std::nullopt, std::nullopt, -1};
    bit::FindElements find_elements(root);

    REQUIRE(false == find_elements.find(2));
    REQUIRE(true == find_elements.find(1));
  }
  {
    Tree root{-1, std::nullopt, -1};
    bit::FindElements find_elements(root);

    REQUIRE(false == find_elements.find(1));
    REQUIRE(true == find_elements.find(2));
  }
  {
    Tree root{-1, -1, -1, -1, -1};
    bit::FindElements find_elements(root);

    REQUIRE(true == find_elements.find(1));
    REQUIRE(true == find_elements.find(3));
    REQUIRE(false == find_elements.find(5));
  }
  {
    Tree root{-1, std::nullopt, -1, -1, std::nullopt, -1};
    bit::FindElements find_elements(root);

    REQUIRE(true == find_elements.find(2));
    REQUIRE(false == find_elements.find(3));
    REQUIRE(false == find_elements.find(4));
    REQUIRE(true == find_elements.find(5));
    REQUIRE(true == find_elements.find(11));
  }
}
