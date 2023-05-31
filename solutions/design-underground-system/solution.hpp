#pragma once

#include <string>
#include <unordered_map>

class UndergroundSystem {
private:
  struct CheckIn {
    std::string sourceStation;
    int departureTime;
  };

  struct CheckOut {
    int totalTripTime;
    int tripsCount;
  };

public:
  void checkIn(int passengerID, std::string sourceStation, int departureTime) {
    check_ins_[passengerID] = {sourceStation, departureTime};
  }

  void checkOut(int passengerID, std::string destinationStation,
                int arrivalTime) {
    const auto &[sourceStation, departureTime] = check_ins_[passengerID];

    const auto route = sourceStation + "->" + destinationStation;
    check_outs_[route].totalTripTime += arrivalTime - departureTime;
    ++check_outs_[route].tripsCount;

    check_ins_.erase(passengerID);
  }

  double getAverageTime(std::string sourceStation,
                        std::string destinationStation) {
    const auto route = sourceStation + "->" + destinationStation;
    return check_outs_[route].totalTripTime * 1.0 /
           check_outs_[route].tripsCount;
  }

private:
  std::unordered_map<int, CheckIn> check_ins_;
  std::unordered_map<std::string, CheckOut> check_outs_;
};
