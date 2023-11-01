#pragma once

#include <iomanip>
#include <sstream>
#include <string>
#include <unordered_map>

/*
  1507. Reformat Date
  https://leetcode.com/problems/reformat-date/
  Difficulty: Easy
  Tags: String
  Time:
  Space:
*/

class Solution {
public:
  static std::string reformatDate(std::string date) {
    static const std::unordered_map<std::string, std::string> months{
        {"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"},
        {"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"},
        {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"},
    };

    std::istringstream istream(date);
    std::string day, month, year;
    istream >> day >> month >> year;

    day.resize(day.size() - 2);
    month = months.at(month);

    std::ostringstream ostream;
    ostream << year << '-';
    ostream << std::setw(2) << std::setfill('0') << month << '-';
    ostream << std::setw(2) << std::setfill('0') << day;
    return ostream.str();
  }
};
