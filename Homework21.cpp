#include <iostream>
#include <cassert>
using namespace std;
#include "oopfunctions.h"

int main() {
    Garage garage("Ako Garage", "Baku Airport Road");

    garage.addAirplane(new Airplane("Boeing 747", "Red", 25000.0, 400));
    garage.addAirplane(new Airplane("Airbus A380", "Blue", 30000.0, 500));
    garage.addAirplane(new Airplane("Cessna 172", "Red", 2000.0, 4));
    garage.addAirplane(new Airplane("Piper Cub", "Yellow", 1000.0, 2));
    garage.addAirplane(new Airplane("Boeing 737", "Red", 15000.0, 250));

    garage.print();

    cout << "\nAirplanes with capacity greater than 400:\n";
    Airplane** largePlanes = garage.getAirplanesCapacityGreaterThan(400);
    if (largePlanes != nullptr) {
        for (size_t i = 0; largePlanes[i] != nullptr; ++i) {
            cout << largePlanes[i]->getModel() << " (" << largePlanes[i]->getCapacity() << ")\n";
        }
        delete[] largePlanes;
    }
    else {
        cout << "No airplanes found with capacity greater than 20000.\n";
    }

    cout << "\nAirplanes with color Red:\n";
    Airplane** redPlanes = garage.getAirplanesByColor("Red");

    if (redPlanes != nullptr) {
        for (size_t i = 0; redPlanes[i] != nullptr; ++i) {
            if (redPlanes[i] != nullptr) {
                cout << redPlanes[i]->getModel() << " == " << redPlanes[i]->getColor() << "\n";
            }
        }
        delete[] redPlanes;
    }
    else {
        cout << "No airplanes found with color Red.\n";
    }


    return 0;
}
