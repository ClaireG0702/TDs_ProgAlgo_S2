#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <functional>
#include <random>
#include <algorithm>
#include <iterator>

enum class Insect {
    ClassicBee,
    Ladybug,
    Butterfly,
    Dragonfly,
    Ant,
    Grasshopper,
    Beetle,
    Wasp,
    Caterpillar,
    Spider,
    GuimielBee
};

const std::vector<Insect> insect_values {
    Insect::ClassicBee,
    Insect::Ladybug,
    Insect::Butterfly,
    Insect::Dragonfly,
    Insect::Ant,
    Insect::Grasshopper,
    Insect::Beetle,
    Insect::Wasp,
    Insect::Caterpillar,
    Insect::Spider,
    Insect::GuimielBee
};

const std::unordered_map<Insect, std::string> insect_to_string = {
    {Insect::ClassicBee, "ClassicBee"},
    {Insect::Ladybug, "Ladybug"},
    {Insect::Butterfly, "Butterfly"},
    {Insect::Dragonfly, "Dragonfly"},
    {Insect::Ant, "Ant"},
    {Insect::Grasshopper, "Grasshopper"},
    {Insect::Beetle, "Beetle"},
    {Insect::Wasp, "Wasp"},
    {Insect::Caterpillar, "Caterpillar"},
    {Insect::Spider, "Spider"},
    {Insect::GuimielBee, "GuimielBee"}
};

const std::vector<int> expected_insect_counts {
    75, // ClassicBee
    50, // Ladybug
    100, // Butterfly
    20, // Dragonfly
    400, // Ant
    150, // Grasshopper
    60, // Beetle
    10, // Wasp
    40, // Caterpillar
    90, // Spider 
    5, // GuimielBee
};

std::vector<std::pair<Insect, int>> get_insect_observations(
    const size_t number_of_observations,
    std::vector<float> const& insect_probabilities,
    const unsigned int seed = std::random_device{}()) {
    // Create a random engine with a given seed
    std::default_random_engine random_engine(seed);

    auto randInsectIndex { std::bind(std::discrete_distribution<size_t>{insect_probabilities.begin(), insect_probabilities.end()}, random_engine) };
    
    std::vector<std::pair<Insect, int>> observations {};
    observations.reserve(number_of_observations);

    for(size_t i {0}; i < number_of_observations; ++i) {
        size_t const random_insect_index { randInsectIndex() };
        Insect const random_insect { insect_values[random_insect_index] };
        
        if (!observations.empty() && observations.back().first == random_insect) {
            observations.back().second++;
            i -= 1;
        } else {
            observations.push_back({random_insect, 1});
        }
    }

    return observations;
}

std::vector<float> probabilities_from_count(std::vector<int> const& counts) {
    std::vector<float> probabilities(counts.size());
    float total_count {0};
    
    for(int count : counts) {
        total_count += count;
    }
    
    for(size_t i {0}; i < counts.size(); ++i) {
        probabilities[i] = static_cast<float>(counts[i]) / total_count;
    }

    return probabilities;
}

int main() {
    std::vector<std::pair<Insect, int>> observations = get_insect_observations(1000, {0.075f, 0.05f, 0.1f, 0.02f, 0.4f, 0.15f, 0.06f, 0.01f, 0.04f, 0.09f, 0.005f});

    std::unordered_map<Insect, int> insect_counts;
    for(const auto& insect : insect_values) {
        insect_counts[insect] = 0;
    }
    for(const auto& observation : observations) {
        insect_counts[observation.first] += observation.second;
    }
    // for(const auto& insect : insect_counts) {
    //     std::cout << insect_to_string.at(insect.first) << ": " << insect.second << std::endl;
    // }

    std::vector<int> counts;
    for(const auto& insect : insect_values) {
        counts.push_back(insect_counts[insect]);
    }
    std::vector<float> observ_prob = probabilities_from_count(counts);
    std::vector<float> expected_prob = probabilities_from_count(expected_insect_counts);
    std::cout << "Probabilities of observed insects vs expected probabilities " << std::endl;
    for(size_t i {0}; i < observ_prob.size(); ++i) {
        float rounded_observ_prob = std::round(observ_prob[i] * 1000) / 1000;

        float difference = std::abs(rounded_observ_prob - expected_prob[i]);
        std::string status = (difference <= 0.01f) ? "OK" : "BAD";

        std::cout << insect_to_string.at(insect_values[i]) << ": " << rounded_observ_prob << " vs " << expected_prob[i] << " " << status << std::endl;
    }

    return 0;
}