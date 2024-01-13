#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> strs;
  };

  std::vector<TestCase> test_cases{
      {
          .strs{"Hello", "World"},
      },
      {
          .strs{""},
      },
      {
          .strs{"&8i]7{0`yCoq1Jxge(~z+q`)0Nl81d1HQ19l?TjHIT6`+y0iED]Wf/"
                "B^|rSV+SVF?HcTDp4y+%:-D#kRZdw<<oS,!Hx "
                "S)_)w>w!r`@2=sd(EdFK$EcJ*|W{HB7m]#?;$e4wKKu4bwtQjh8DE/"
                "Xehml6(!hB*I",
                "Jnx8ugODPuyl+,+0^)*5q#MovdX#DXEo "
                "|i>0Pa.6]];{:[mc<g]hw:94Kmj5~SzLIwf([j<]|6,*,3xJw "
                "`BD#}]1,!{4U}(yi~J;q"},
      },
  };

  for (const auto &[strs] : test_cases) {
    const auto actual = Codec::decode(Codec::encode(strs));
    // REQUIRE(strs.size() == actual.size());
    for (int i = 0; i < std::ssize(actual); ++i) {
      REQUIRE(strs[i] == actual[i]);
    }
  }
}
