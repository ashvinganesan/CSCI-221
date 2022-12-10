/*
Ashvin Ganesan
Charlie Mcguffey
Friday, December 2nd 2022
Evaluation 8: C++ Advanced Eval
*/
#include <cmath>
#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include <map>
#include "Car.cpp"


using namespace std;

struct Passenger {
        struct Location stop;
        int stopNumber;
};

class Bus: public Car{
    private:
        int maxPass;
        double mpgReduction;
        vector<Passenger> stops;
        
    public:
        Bus(double xpos, double ypos, double fueltanksize, double gas, double mpg, int MaxPassengers, double reduction) {
            Car(xpos, ypos, fueltanksize,gas,mpg);
            maxPass = MaxPassengers;
            mpgReduction = reduction;
        }
        Bus(int MaxPassengers, double reduction) {
            Car();
            maxPass = MaxPassengers;
            mpgReduction = reduction;
        }
        void moveTo(Location destination) {
            //Assumes you can move there
            double distance = sqrt(pow(Car::xPosition() -destination.xCord,2) + pow(Car::yPosition() -destination.yCord,2));
            if(!Car::gas()*(Car::mpg()-mpgReduction*stops.size()) < distance) {
                Car::setGas(Car::gas()- distance*(Car::mpg()-mpgReduction*stops.size()));
                Car::setLocation(destination);
            }
        }
        bool canMoveTo(Location destination) {
            double distance = sqrt(pow(Car::xPosition() -destination.xCord,2) + pow(Car::yPosition() -destination.yCord,2));
            if(Car::gas()*(Car::mpg()-mpgReduction*stops.size()) < distance) {
                return false;
            }
            return true;
        }
        void addPassenger(Passenger p) {
            if(stops.size() == maxPass) {
                return;
            }
            stops.push_back(p);
        }

        vector<Passenger>* generateOut(int StartingStop) {
            int maxStop = 0;
            vector<Passenger> *ret = new vector<Passenger>();
            for (auto j = stops.begin(); j != stops.end(); ++j) {
                    if((*j).stopNumber > maxStop) {
                        maxStop = (*j).stopNumber;
                    }
                }
            for(int i = StartingStop; i < maxStop; i++) {
                for (auto j = stops.begin(); j != stops.end(); ++j) {
                    bool filler = true;
                    if((*j).stopNumber == i && filler) {
                        filler = false;
                        ret->push_back(*j);
                    }
                }
                    
            }
            for(int i = 0; i < StartingStop; i++) {
                for (auto j = stops.begin(); j != stops.end(); ++j) {
                    bool filler = true;
                    if((*j).stopNumber == i && filler) {
                        filler = false;
                        ret->push_back(*j);
                    }
                }
            }
            return ret;
        }
        

};
class MedicalCenter {
    private:
        map<string, string> providers;
        map<string, string> patients;
    public:
        MedicalCenter() {
            providers.insert(pair<string, string>("a","d"));
        }
        void addProvider(string provider, string role) {
            providers.insert(pair<string,string>(provider, role));
        }
        void addPatient(string patient, string role) {
            patients.insert(pair<string,string>(patient, role));
        }
        int totalPeople() {
            return providers.size() + patients.size();
        }
};

class Ambulance: public MedicalCenter, public Car {
    private:
        int maxPass;
        int maxPatients;
        double mpgReduction;
    public: 
        Ambulance(double xpos, double ypos, double fueltanksize, double gas, double mpg, int MaxPassengers, int MaximumPatients, double reduction) {
            Car(xpos, ypos, fueltanksize,gas,mpg);
            maxPass = MaxPassengers;
            maxPatients = MaximumPatients;
            mpgReduction = reduction;
        }
        Ambulance(int MaxPassengers, int MaximumPatients, double reduction) {
            maxPass = MaxPassengers;
            maxPatients = MaximumPatients;
            mpgReduction = reduction;
        }
        void moveTo(Location destination) {
            //Assumes you can move there
            double distance = sqrt(pow(Car::xPosition() -destination.xCord,2) + pow(Car::yPosition() -destination.yCord,2));
            if(!Car::gas()*(Car::mpg()-mpgReduction*MedicalCenter::totalPeople()) < distance) {
                Car::setGas(Car::gas()- distance*(Car::mpg()-mpgReduction*MedicalCenter::totalPeople()));
                Car::setLocation(destination);
            }
        }
        bool canMoveTo(Location destination) {
            double distance = sqrt(pow(Car::xPosition() -destination.xCord,2) + pow(Car::yPosition() -destination.yCord,2));
            if(Car::gas()*(Car::mpg()-mpgReduction*MedicalCenter::totalPeople()) < distance) {
                return false;
            }
            return true;
        }

};

vector<Car>* CanMoveTo(vector<Car> *cars, Location destination) {
    vector<Car> *ret = new vector<Car>();
    for(auto i=cars->begin(); i < cars->end(); i++) {
		if((*i).canMoveTo(destination)) {
            ret->push_back((*i));
        }
	}
    return ret;
}

int main() {
    // printf("test\n");
    Car car(100,100,10,10,20);
    Car newCar(0.0,0.0, 25.0, 0.0, 20.0);
    Car cars[5];
    cars[0] = car;
    struct Location positionTest;
    positionTest.xCord = 100;
    positionTest.yCord = 100;
    for(int i = 1; i < 5; i++) {
        cars[i] = newCar;
    }
    struct carArr canTravel;
    canTravel = canReach(positionTest, cars, 5);
    for(int i = 0; i< canTravel.length; i++) {
        printf("New Car:\n");
        //NOTE TO SELF %f = DOUBLE %d = INTEGER //I miss my java and python :(
        printf("\txpos: %f\n", canTravel.cars[i].xPosition());
        printf("\typos: %f\n", canTravel.cars[i].yPosition());
    }
} 