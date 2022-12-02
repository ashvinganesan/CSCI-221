/*
Ashvin Ganesan
Charlie Mcguffey
Friday, December 2nd 2022
Evaluation 7: C++ Intro Eval
*/
#include <cmath>
#include <iostream>
#include <cstring>

struct Location {
        double xCord;
        double yCord;
    };


class GasStation {
    private:
        struct Location position;
        double price; //per gallon
    public:
        GasStation(double xpos, double ypos, double cost) {
            position.xCord = xpos;
            position.yCord = ypos;
            price = cost;
        }
        Location pos(){
            return position;
        }
        double cost() {
            return price;
        }

};
class Car {
    

    private:
        struct Location position;
        double milesPerGallon;
        double fuel;
        double fueltank;

    public: 
        Car(double xpos, double ypos, double fueltanksize, double gas, double mpg) {
            position.xCord = xpos;
            position.yCord = ypos;
            fueltank = fueltanksize;
            fuel = gas;
            milesPerGallon = mpg;
        }
        Car() {
            position.xCord = 0.0;
            position.yCord = 0.0;
            fueltank = 25.0;
            fuel = 25.0;
            milesPerGallon = 20.0;
        }
        double xPosition() {
            return position.xCord;
        }
        double yPosition() {
            return position.yCord;
        }
        double tank() {
            return fueltank;
        }
        double gas() {
            return fuel;
        }
        double mpg() {
            return milesPerGallon;
        }

        bool moveTo(Location destination) {
            double distance = sqrt(pow(position.xCord -destination.xCord,2) + pow(position.yCord -destination.yCord,2));
            if(fuel*milesPerGallon < distance) {
                return false;
            }
            position = destination;
            fuel = fuel -(distance/milesPerGallon);
            return true;
        }
        bool canMoveTo(Location destination) {
            double distance = sqrt(pow(position.xCord -destination.xCord,2) + pow(position.yCord -destination.yCord,2));
            if(fuel*milesPerGallon < distance) {
                return false;
            }
            return true;
        }
        bool canMoveToFrom(Location from, Location destination, double gas) {
            double distance = sqrt(pow(from.xCord -destination.xCord,2) + pow(from.yCord -destination.yCord,2));
            if(gas*milesPerGallon < distance) {
                return false;
            }
            return true;
        }
        bool canMoveTo(Location destination, GasStation stations[], int length) {
            if(canMoveTo(destination)) {
                return true;
            }
            for(int i = 0; i < length; i++) {
                if(canMoveTo(stations[i].pos())) {
                    if(canMoveToFrom(destination, stations[i].pos(), fueltank)) {
                        return true;
                    }
                }
            }
            return false;
            
        }
        double moveTo(Location destination, GasStation stations[], int length) {
            if(canMoveTo(destination)) {
                moveTo(destination);
                return 0.0;
            }
            for(int i = 0; i < length; i++) {
                if(canMoveTo(stations[i].pos())) {
                    if(canMoveToFrom(destination, stations[i].pos(), fueltank)) {
                        moveTo(stations[i].pos());
                        double cost = (fueltank-fuel)/stations[i].cost();
                        fuel = fueltank;
                        moveTo(destination);
                        return cost;
                    }
                }
            }
            return 0.0;
        }

};

struct carArr {
    Car *cars;
    int length;
    double *price;
};
carArr canReach(struct Location pos, Car cars[], int length) {
            int counter = 0;
            int j = 0;
            for(int l = 0; l < length; l++) {
                if(cars[l].canMoveTo(pos)) {
                    counter++;
                }
            }
            // for(Car c: cars) {
            //     if(c.canMoveTo(pos)) {
            //         counter++;
            //     }
            // }
            Car canMove[counter];
            for(int i = 0; i < counter; i++) {
                while(!cars[j].canMoveTo(pos)) {
                    j++;
                }
                Car c(cars[j].xPosition(), cars[j].yPosition(), cars[j].tank(), cars[j].gas(), cars[j].mpg());
                c.moveTo(pos);
                canMove[i] = c;
                j++;
            }

            struct carArr ret;
            Car *pointer = canMove;
            ret.length = counter;
            ret.cars = pointer;
            return ret;
}
carArr canReach(struct Location pos, Car cars[], int carsLength, GasStation stations[], int gasLength) {
            int counter = 0;
            int j = 0;
            for(int l = 0; l < carsLength; l++) {
                if(cars[l].canMoveTo(pos,stations, gasLength)) {
                    counter++;
                }
            }
            Car canMove[counter];
            double prices[counter];
            for(int i = 0; i < counter; i++) {
                while(!cars[j].canMoveTo(pos,stations,gasLength)) {
                    j++;
                }
                Car c(cars[j].xPosition(), cars[j].yPosition(), cars[j].tank(), cars[j].gas(), cars[j].mpg());
                double cost = c.moveTo(pos,stations,gasLength);
                canMove[i] = c;
                prices[i] = cost;
                j++;
            }

            struct carArr ret;
            Car *pointer = canMove;
            double *costpointer = prices;
            ret.length = counter;
            ret.cars = pointer;
            ret.price = costpointer;
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

