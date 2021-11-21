#include <iostream>
#include "Eigen/Dense"
#include <tuple>
#include <fstream>
#include <chrono>

#include "statespaceSim.h"

using namespace Eigen;
using namespace std;

int main() {
    SimulateSystem Simulation;
    Simulation.openFromFile("AFile.csv","BFile.csv","CFile.csv","x0File.csv","inputFile.csv");

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    Simulation.runSimulation();
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::cout << "Time Difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end-begin).count() << "[micro seconds]" << std::endl;
    Simulation.saveData("AFileOutput.csv", "BFileOutput.csv", "CFileOutput.csv", "x0FileOutput.csv", "inputSequenceFileOutput.csv", "simulatedStateSequenceFileOutput.csv", "simulatedOutputSequenceFileOutput.csv");
}