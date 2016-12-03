#include "Orbit3D.h"

Orbit3D::Orbit3D() {
  e_var = 0;
  a_var = 0;
  i_var = Angle();
  o_var = Angle();
  w_var = Angle();
  M_var = Angle();
}

double Orbit3D::PeriAndApoDistance() const {
  return a()/2;
}

double Orbit3D::r_per() const {
  return a()*(1-e());
}

double Orbit3D::r_ap() const {
  return a()*(1+e());
}

double Orbit3D::MajorAxis() const {
  return a()*2;
}

double Orbit3D::b() const{
  return a()*sqrt(1-pow(e(),2));
}

double Orbit3D::MinorAxis() const {
  return b()*2;
}

double Orbit3D::T(double mew) const {
  return 2*M_PI*sqrt((pow(a(),3))/mew);
}

double Orbit3D::calculateaForSpecificT(double T, double mew) const {
  return cbrt((mew*pow(T,2))/(4*pow(M_PI,2)));
}

Angle Orbit3D::u() const {
  return f()+w();
}

Angle Orbit3D::l() const {
  return f()+w()+o();
}

Angle Orbit3D::f() const {
  double ECache = E();
  double sinE = sin(ECache);
  double cosE = cos(ECache);
  double fDouble = atan2((sqrt(1-e()*e()))*sinE,cosE-e());
  Angle result = Angle(fDouble);
  return result;
}

Angle Orbit3D::E() const {
  //Needs work
  int maxIterations = 15;
  int decimalPlaces = 10;

  double delta = pow(10, -decimalPlaces);

  double EGuess = 0;
  double EGuess2 = 0;

  //We need to determine our initial guess
  //If the eccentricity is less than 0.8, we use M() as our guess
  //  otherwise we are going to use pi
  if (e() < 0.8) {
    EGuess = M();
  } else {
    EGuess = M_PI;
  }

  EGuess2 = EGuess - e()*sin(M()) - M();

  //Current iteration
  int i = 0;

  //Lets try to find E
  while ((fabs(EGuess2) > delta) && (i < maxIterations)) {
    EGuess = EGuess - EGuess2/(1-e()*cos(EGuess));
    EGuess2 = EGuess - e()*sin(EGuess) - M();
    i++;
  }

  //Check to make sure we actually found an answer
  if (i > maxIterations) {
    throw std::runtime_error("This should never happen");
  }

  Angle result;
  result = Angle(EGuess);
  return result;
}

double Orbit3D::ell() const {
  switch (shape()) {
    case OrbitalShape::Circle:
      return a();
      break;
    case OrbitalShape::Ellipsis:
    case OrbitalShape::Hyperbola:
      return (pow(b(),2))/a();
      break;
    case OrbitalShape::Parabola:
      return 2*a();
      break;
    default:
      throw std::domain_error("This should never happen");
  }
}

double Orbit3D::latusRectum() const {
  return l()*2;
}

double Orbit3D::p() const {
  switch (shape()) {
    case OrbitalShape::Circle:
      //Throw exception, value is infinite
      throw std::domain_error ("Orbit3D::p(): p is infinite for Circles");
      break;
    case OrbitalShape::Ellipsis:
    case OrbitalShape::Hyperbola:
      return (pow(b(),2))/(sqrt(pow(a(),2)-pow(b(),2)));
      break;
    case OrbitalShape::Parabola:
      return 2*a();
      break;
    default:
      throw std::domain_error("This should never happen");
  }
}

OrbitalShape Orbit3D::shape() const {
  if (e() == 0) {
    return OrbitalShape::Circle;
  }

  if ((e() > 0) && (e() < 1)) {
    return OrbitalShape::Ellipsis;
  }

  if (e() == 1) {
    return OrbitalShape::Parabola;
  }

  if (e() > 1) {
    return OrbitalShape::Hyperbola;
  }

  throw std::domain_error("This should never happen");
}

double Orbit3D::c() const {
  switch (shape()) {
    case OrbitalShape::Circle:
      return 0;
      break;
    case OrbitalShape::Ellipsis:
    case OrbitalShape::Hyperbola:
      return sqrt(pow(a(),2)-pow(b(),2));
      break;
    case OrbitalShape::Parabola:
      //Throw exception, value is undefined
      throw std::domain_error ("Orbit3D::c(): c is undefined for Parabolas");
      break;
    default:
      throw std::domain_error("This should never happen");
  }
}

double Orbit3D::radiusTrueAnomaly() const {
  return a()*(1-pow(e(),2))/(1+e()*cos(f()));
}

double Orbit3D::radiusEccentricAnomaly() const {
  return a()*(1-e()*cos(E()));
}

double Orbit3D::epsilon(double mew) const {
  //Needs work
  switch (shape()) {
    case OrbitalShape::Circle:
    case OrbitalShape::Ellipsis:
      return -(mew/2*a());
      break;
    case OrbitalShape::Hyperbola:
      return (mew/2*a());
      break;
    case OrbitalShape::Parabola:
      return 0;
      break;
    default:
      throw std::domain_error("This should never happen");
  }
}

double Orbit3D::v(double mew) const {
  return sqrt(mew/a());
}

Vector3D Orbit3D::hBar() const {
  Vector3D result;
  result = osvr().crossProduct(osvv());
  return result;
}

Vector3D Orbit3D::osvr() const {
  //f();
  //r = a()*(1-e()*cos(E()))

}

Vector3D Orbit3D::osvv() const {
  //Needs work
  //The velocity vector v can be derived from position vector r,
  //  by differentiation with respect to time
}

Vector3D Orbit3D::lineOfNodes() const {
  Vector3D result;
  Vector3D K = Vector3D(0,0,1);
  result = hBar().crossProduct(K);
  return result;
}

double Orbit3D::n(double mew) const {
  return sqrt(mew/pow(a(),3));
}

double Orbit3D::meanLongitude() const {
  return longitudeOfPeriapsis()+M();
}

double Orbit3D::longitudeOfPeriapsis() const {
  return o()+w();
}

Vector3D Orbit3D::h() const {
  return osvr().crossProduct(osvv());
}
