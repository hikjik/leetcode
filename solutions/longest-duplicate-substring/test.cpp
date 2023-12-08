#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "banana",
          .expected = "ana",
      },
      {
          .s = "abcd",
          .expected = "",
      },
      {
          .s = "aaaaa",
          .expected = "aaaa",
      },
      {
          .s = "vcjwaksfwsykahshcddgkopaeiwtuspqkyduwhugimsegplvtuvrttfpzoxmvex"
               "kbqamyomdfhqftpenrjivntrrzseejrofenvdxviduskmfcqclvcbidskfgyrvv"
               "cqbsirshjcluzkjhrjayogeaixmqvdfrujwymeynkdccenlnsyvqxkcqvypclch"
               "skxqpshwpmswmgafpbdtiggcjcsoebeluyhqsdccxmbxndxbujekwwmclpjpzqx"
               "uqwzrogmeqzxoosddqwsuyhbxhvelbbnuvtavsavimxuahktntzuqbxbkquozjs"
               "vdgbvuybxuidchmbhiucwaijnocewwdgrpsaclqmkihutrbugzjemkctyrlaghi"
               "mhiifwoctnpgkyjcuzgsjfucmekogxnqbuoxbciplsefvbiqlrtvdaotxpwwxsp"
               "llqdzjdwhxhasvhxhfgsnkyesngvwavuatzhvqmalqwugotifukyvqsrhubddjr"
               "vwegvjvgkhjlidvvwmzeqhqichzyogfzzpomakemujrterqlboqljewxnawwvgp"
               "zahwzvzbxcfkiaddddikbvtvlrhvtlzbtdkmcgjxulhsjmuwklhvcjrdxtuirwm"
               "xunupfibwdupkgltmpbyurcuviufgyfcctjhasdvthgpztjurydisxdiiwywrdj"
               "nmniqytleujxnumqvcohrgjssdcdhpszqojpuxkylczjyqrvetmsdplljfjzmyc"
               "mgxlmpkorgpzgvrvklnuumflmtqbasqfuadqjsndookyzdappehwapwispgmiic"
               "xtiuuvyygzghxvkwavlukhbvjqrewvqcvlbsfgtygxfcwrhomjvwpdxvzbkpleo"
               "upekpxcvuvncececuaslnfsckzxotjzuakbyszvtoclggvxjhcyddycthewfxmn"
               "zlldxocnekdreivyxcyuivpsovdrrdvjddzacttireuyusphqxokmulbmhicxcj"
               "ntsczfcolwmslqvbzneakflnlfuszzkfjepyiwustdtnuvlnrtfhwguktklwlks"
               "kxtmqfejribfkanfxnwizkvmrxsypwfknzjsxxuvciopwkequszlbuoshihwmuu"
               "rbboygkvkpebsucswueaynqlnbtcewdcgnqqtgfqsivnpspjoruosnpifdprsuh"
               "kkrgqidinyhydwqslubwplbaujczehqxlppmbwgrrqoxiglvmgjfmtmcnoloyoy"
               "jvaaenqcikaqivannzzpriucewysujjjdlrbijvvutkinmvupbzattsumulmupz"
               "fdrdgtwgbtydhgsaqdhiwqirdfjdevegtkrjosoimjedvezrujnusqtvlmglwxs"
               "ttrtsrdfvcnzynoghikwkqsoovjoyfxlfanwekqjggbudsecqgoceegzutaqati"
               "idduwpgxnmsnkbtbakswawfdyqflbmunpsnkisfxnhpdjbtrzdjaflsviyvxloy"
               "rrbwcjfktupbajwvdyswnvqbbacalchehuaisewdwmuzlpkrzcdafffkkqgnmtp"
               "wpdbqbwyzshmvfgpitwsonmaiyomrjtuxmcayozfpkfpbqyyeamdfhnylefuswu"
               "jfqedejnizfyxfzorfkriozqtjsdltnzamthweaekzgngfbuzqlemdjnbxomior"
               "tghsoxsinwvcqfzrzywumtsjnygyrwfgkmuedytnfvsdjvneyjlrqohhlhrymtd"
               "mnhvjkztpfovcuraaxchteooetutsprsyjqevcmxrsjgzfvmmdfraeajuakyqcv"
               "rurqkkfwnlwqqdvpeicegbetzwjdgyqwegwijjqdqdzxrsdazuzwopyvqtvfcub"
               "ycfpchltcitasrrwylwxqxeetqqxhlzawwpxdgiiuucylraufgdbgbiaukjifji"
               "pvzmhjhbjfknehssybkmzllwaqelplslpgeqjhplpyisrccmjwdutdfgzmswcks"
               "tljyywvgxdhjzlwbtpvnegkgbuxncxjyspefqtqcrkoaiqlfrdenvxlsylbjlpq"
               "krlvjmsxzhfgfgwwoxaauydtgyyfqingvtaacflcradjfxxivvikzbdftnkaxov"
               "lvegozhbmzukwuvphahnarbuxbjxyefzsmbvqgylmkvvszyexdzqgaecccmzsvz"
               "lfnuakghgcecfbwczxuornuiviutmxhudoqcmqlusztfgoudxfmmcreeypqqxto"
               "jotlpkurwyzjdxyevszwuoekonsfdbazelktwionkuzkmhfqigymofbmagkrjao"
               "nyhuerckhtgqlsfprtrhtgiflpwjilbfczsqlscxbemigqijsgdnchptejowcyv"
               "npbmmduvndoevqephtapaobskqrjkijtobonudryrmhxuquueggnfziwkwrughx"
               "qyjsuyahrpbhsofnbawselqyxofoiowugqwfwyvxsrjwffzppvfnuwxlyeytsao"
               "uqipyqhtghuaxecvnirivewxndzajtjprkzufsyrujususujijwspgjfzahlany"
               "cdqkghamlwxokkwbnbqljmznktrvhcrwxwzdmqtlvqkqcxkdjmqolsjpewhkrmo"
               "llcbxlekykyhvuzwbdiwreupsrbxyuxwkweyxeqfpyvcuhwmzmvhzdhonlqhcqi"
               "yconuxzfwqgxvnfyeghgxnzckbatggwmhbwdrvrlxakcxsiolqzlmesngotj",
          .expected = "mdfh",
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::longestDupSubstring(s);
    REQUIRE(expected.size() == actual.size());
    const auto pos = s.find(actual);
    REQUIRE(pos != std::string::npos);
    REQUIRE(s.find(actual, pos + 1) != std::string::npos);
  }
}
