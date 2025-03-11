#include <iostream>
#include "ask.h"
using namespace std;

int main() {
    cout << "Welcome to LICE 1.0.0" << endl;

    bool openSource = askYorN("Is this going to be open source?");
    if (openSource) {
        cout << "Open source project it is." << endl;
        
        bool allowModifications = askYorN("Do you want to allow modifications to your code?");
        bool allowRedistribution = askYorN("Do you want to allow redistribution of the code?");
        bool allowSublicensing = askYorN("Do you want to allow sublicensing (giving others the right to license your code)?");
        bool allowProprietaryUse = askYorN("Do you want others to use your code in proprietary software?");
        bool requireAttribution = askYorN("Do you want to require crediting the original authors?");
        bool includeDisclaimer = askYorN("Do you want to include a disclaimer of warranties?");
        bool imposeRestrictions = askYorN("Do you want to impose any restrictions on use?");
        
        bool permissiveLicense = askYorN("Do you want a permissive license (allows modification, redistribution, and commercial use)?");
        bool copyleftLicense = askYorN("Do you want to use a copyleft license (requires derivatives to be open source)?");
        bool simpleLicense = askYorN("Do you want a simple and minimal license?");
        bool noCommercialUse = askYorN("Should your license prevent commercial use?");
        
        // Based on the answers, here you can add logic to recommend a license.
        // For example:
        if (permissiveLicense) {
            cout << "You might want to consider using the MIT or Apache 2.0 license." << endl;
        } else if (copyleftLicense) {
            cout << "You might want to consider using the GPLv3 license." << endl;
        } else {
            cout << "You might want to consider other licenses based on your preferences." << endl;
        }
    } else {
        cout << "Closed source project selected!" << endl;
    }

    return 0;
}
