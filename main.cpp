#include <iostream>
#include <string>
#include "Angle.h"
#include "Vector3D.h"
#include "Orbit3D.h"

int main() {
  Vector3D v = Vector3D(120,90,45);
  Vector3D v2 = Vector3D(7,15,90);

  //std::cout << v.findAngle(v2).degrees() << std::endl;

  Orbit3D orbit = Orbit3D();

  orbit.e(0.5);
  orbit.M(0.471239);

  std::cout << "E: " << orbit.E().degrees() << std::endl;
  std::cout << "f: " << orbit.f().degrees() << std::endl;

  return 0;
}
