#include "RewardsService.hpp"

RewardsService::RewardsService(EligibilityService& eligibilityService)
    : eligibilityService(eligibilityService) {}

std::vector<RewardsService::Reward> RewardsService::getRewards(const std::string& accountNumber, const std::vector<std::string>& subscriptions) {
    std::vector<Reward> rewards;

    EligibilityService::Eligibility eligibility = eligibilityService.checkEligibility(accountNumber);

    if (eligibility == EligibilityService::CUSTOMER_ELIGIBLE) {
        for (const auto& subscription : subscriptions) {
            Reward reward = getRewardForSubscription(subscription);
            if (reward != NO_REWARD)
                rewards.push_back(reward);
        }
    }

    return rewards;
}

RewardsService::Reward RewardsService::getRewardForSubscription(const std::string& subscription) {
    if (subscription == "SPORTS")
        return CHAMPIONS_LEAGUE_FINAL_TICKET;
    else if (subscription == "KIDS")
        return NO_REWARD;
    else if (subscription == "MUSIC")
        return KARAOKE_PRO_MICROPHONE;
    else if (subscription == "NEWS")
        return NO_REWARD;
    else if (subscription == "MOVIES")
        return PIRATES_OF_THE_CARIBBEAN_COLLECTION;
    else
        return NO_REWARD;
}
