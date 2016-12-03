#include "Angle.h"

double Angle::radians() const {
  return rad;
}

double Angle::degrees() const {
  return radians()/(M_PI/180);
}

void Angle::radians(double newr) {
  while (newr > (2*M_PI)) {
    newr = newr - (2*M_PI);
  }

  while (newr < 0) {
    newr = newr + 2*M_PI;
  }
  rad = newr;
}

void Angle::degrees(double newd) {
  radians(newd*(M_PI/180));
}

double Angle::operator()() const {
  return radians();
}

void Angle::operator()(double newr) {
  radians(newr);
}

Angle Angle::operator+(const Angle b) const {
  return Angle(this->radians() + b.radians());
}

Angle Angle::operator-(const Angle b) const {
  return Angle(this->radians() - b.radians());
}

Angle Angle::operator+(const double b) const {
  return Angle(this->radians() + b);
}

Angle Angle::operator-(const double b) const {
  return Angle(this->radians() - b);
}

Angle::Angle(double newr) {
  radians(newr);
}

Angle::Angle() {
  radians(0);
}

Angle::operator double() const {
  return radians();
}
