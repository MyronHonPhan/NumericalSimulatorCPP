#include <iostream>
#include "Eigen/Dense"
#include <vector>

using namespace Eigen;

class Rocket {
public:
  Rocket() {
    
  }
private:
  int mass; // Newtons
  int length; // Meters


};



float RK4() {


}

class Dynamics {
public:
  Dynamics () {

  }
private:
  double phi;
  double theta;
  double psi;
  double x;
  double y;
  double z;
  
};

class Environment {
public:
  Environment() {

  }
};

int main() {
  std::cout << "Hello World!\n";
  MatrixXd m;
  m.resize(3,10);
  m.setZero();

  Matrix3d f;

  f << 1,2,3,
      4,5,6,
      7,8,9;

  int array[9];
  for(int i = 0; i < 9; ++i) array[i] = i;
  std::cout << Map<Matrix3i>(array) << std::endl;
}