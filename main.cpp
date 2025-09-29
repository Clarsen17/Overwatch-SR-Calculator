#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to convert rank and tier to SR
int rankToSR(const string& rank, int tier) {
    int sr = 0;
    int baseSR = 0;

    // Base SR for each rank
    if (rank == "Bronze") {
        baseSR = 0;  // Bronze starts at 0
    } else if (rank == "Silver") {
        baseSR = 1500;
    } else if (rank == "Gold") {
        baseSR = 2000;
    } else if (rank == "Platinum") {
        baseSR = 2500;
    } else if (rank == "Diamond") {
        baseSR = 3000;
    } else if (rank == "Master") {
        baseSR = 3500;
    } else if (rank == "Grandmaster") {
        baseSR = 4000;
    } else if (rank == "Champion") {
        baseSR = 4500;
    }

    // Calculate SR based on tier (lower tier means higher SR)
    sr = baseSR + (5 - tier) * 100; // Tier 1 is the highest SR

    return sr;
}

int getTier() {
    int tier;
    while (true) {
        cout << "Select the tier (1 = highest, 5 = lowest): ";
        cin >> tier;
        if (tier >= 1 && tier <= 5) {
            return tier;
        } else {
            cout << "Invalid input. Please enter a tier between 1 and 5." << endl;
        }
    }
}

string getRank() {
    string rank;
    while (true) {
        cout << "\nSelect the rank from the following list:" << endl;
        cout << "1. Bronze\n2. Silver\n3. Gold\n4. Platinum\n5. Diamond\n6. Master\n7. Grandmaster\n8. Champion" << endl;
        int rankChoice;
        cin >> rankChoice;
        switch (rankChoice) {
            case 1: return "Bronze";
            case 2: return "Silver";
            case 3: return "Gold";
            case 4: return "Platinum";
            case 5: return "Diamond";
            case 6: return "Master";
            case 7: return "Grandmaster";
            case 8: return "Champion";
            default:
                cout << "Invalid choice. Please select a valid rank number." << endl;
        }
    }
}

int main() {
    int numPlayers;
    cout << "Enter the number of players (6 to 20): ";
    cin >> numPlayers;

    if (numPlayers < 6 || numPlayers > 20) {
        cout << "Invalid number of players. Please enter between 6 and 20 players." << endl;
        return 1;
    }

    vector<string> ranks(numPlayers);
    vector<int> tiers(numPlayers);

    // Input rank and tier for each player
    for (int i = 0; i < numPlayers; ++i) {
        cout << "\n--- Player " << i + 1 << " ---" << endl;
        ranks[i] = getRank();
        tiers[i] = getTier();
    }

    // Calculate the total SR
    int totalSR = 0;
    cout << "\n--- Player SR Breakdown ---" << endl;
    for (int i = 0; i < numPlayers; ++i) {
        int sr = rankToSR(ranks[i], tiers[i]);
        totalSR += sr;
        cout << "Player " << i + 1 << " (" << ranks[i] << " " << tiers[i] << "): SR = " << sr << endl;
    }

    // Calculate and display the average SR
    double averageSR = static_cast<double>(totalSR) / numPlayers;
    cout << "\nThe average SR of the team is: " << averageSR << endl;

    return 0;
}
