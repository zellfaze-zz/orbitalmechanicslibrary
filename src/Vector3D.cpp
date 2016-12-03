#include "Vector3D.h"

Vector3D::Vector3D() {
  x(0);
  y(0);
  z(0);
}

Vector3D::Vector3D(double newx, double newy, double newz) {
  x(newx);
  y(newy);
  z(newz);
}

Angle Vector3D::alpha() const {
  double coa;
  coa = x()/magnitude();
  Angle result = Angle(acos(coa));
  return result;
}

void Vector3D::alpha(Angle newa) {
  double coa;
  coa = cos(newa);
  x(coa * magnitude());
}

Angle Vector3D::beta() const {
  double cob;
  cob = y()/magnitude();
  Angle result = Angle(acos(cob));
  return result;
}

void Vector3D::beta(Angle newa) {
  double cob;
  cob = cos(newa);
  y(cob * magnitude());
}

Angle Vector3D::gamma() const {
  double cog;
  cog = z()/magnitude();
  Angle result = Angle(acos(cog));
  return result;
}

void Vector3D::gamma(Angle newa) {
  double cog;
  cog = cos(newa);
  z(cog * magnitude());
}

Angle Vector3D::phi() const {
  double cop;
  cop = x()/sqrt(pow(y(),2)+pow(z(),2));
  Angle result = Angle(acos(cop));
  return result;
}

double Vector3D::magnitude() const {
  return sqrt(pow(x(),2)+pow(y(),2)+pow(z(),2));
}

bool Vector3D::isZero() const {
  if ((x()+y()+z()) == 0)
    return true;
  else
    return false;
}

bool Vector3D::isUnit() const {
  if (magnitude() == 1)
    return true;
  else
    return false;
}

bool Vector3D::operator==(const Vector3D b) const {
  if (x() != b.x())
    return false;
  if (y() != b.y())
    return false;
  if (z() != b.z())
    return false;
  return true;
}

bool Vector3D::isOpposite(const Vector3D b) const {
  //Needs work
}

bool Vector3D::isParallel(const Vector3D b) const {
  //Needs work
}

bool Vector3D::isAntiparallel(const Vector3D b) const {
  //Needs work
}

Vector3D Vector3D::operator+(const Vector3D &b) const {
  double newx, newy, newz;
  newx = x() + b.x();
  newy = y() + b.y();
  newz = z() + b.z();

  Vector3D result = Vector3D(newx, newy, newz);
  return result;
}

Vector3D Vector3D::operator-(const Vector3D &b) const {
  double newx, newy, newz;
  newx = x() - b.x();
  newy = y() - b.y();
  newz = z() - b.z();

  Vector3D result = Vector3D(newx, newy, newz);
  return result;
}

Vector3D Vector3D::operator*(const double &b) const {
  double newx, newy, newz;
  newx = x() * b;
  newy = y() * b;
  newz = z() * b;

  Vector3D result = Vector3D(newx, newy, newz);
  return result;
}

Vector3D Vector3D::operator/(const double &b) const {
  double newx, newy, newz;
  newx = x() / b;
  newy = y() / b;
  newz = z() / b;

  Vector3D result = Vector3D(newx, newy, newz);
  return result;
}

double Vector3D::dotProduct(const Vector3D b) const {
  std::vector<double> a{x(), y(), z()};
  std::vector<double> c{b.x(), b.y(), b.z()};
  double result = std::inner_product(a.begin(), a.end(), c.begin(), 0);
  return result;
}

Vector3D Vector3D::crossProduct(const Vector3D b) const {
  Vector3D result;
  double newx, newy, newz;
  newx = y()*b.z() - z()*b.y();
  newy = z()*b.x() - x()*b.z();
  newz = x()*b.y() - y()*b.x();
  result = Vector3D(newx, newy, newz);
  return result;
}

Vector3D::Vector3D(Point3D p1, Point3D p2) {

  double newx, newy, newz;
  newx = p2.x()-p1.x();
  newy = p2.y()-p1.y();
  newz = p2.z()-p1.z();
  x(newx);
  y(newy);
  z(newz);
}

Angle Vector3D::findAngle(const Vector3D b) const {
  Angle result;
  double calcDot;
  double combinedMagnitude;
  calcDot = dotProduct(b);
  combinedMagnitude = magnitude() * b.magnitude();
  if (calcDot == combinedMagnitude)
    result = Angle();
  else
    result = Angle(acos(calcDot/combinedMagnitude));
  return result;
}
