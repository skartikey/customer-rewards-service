#ifndef REWARDS_SERVICE_HPP
#define REWARDS_SERVICE_HPP

#include "EligibilityService.hpp"
#include <string>
#include <vector>

class RewardsService {
public:
    enum Reward {
        NO_REWARD,
        CHAMPIONS_LEAGUE_FINAL_TICKET,
        KARAOKE_PRO_MICROPHONE,
        PIRATES_OF_THE_CARIBBEAN_COLLECTION
    };

    RewardsService(EligibilityService& eligibilityService);

    std::vector<Reward> getRewards(const std::string& accountNumber, const std::vector<std::string>& subscriptions);

private:
    Reward getRewardForSubscription(const std::string& subscription);

    EligibilityService& eligibilityService;
};

#endif // REWARDS_SERVICE_HPP
