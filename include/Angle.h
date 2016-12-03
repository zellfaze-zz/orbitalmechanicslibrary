#ifndef ANGLE_H
#define ANGLE_H
#include <math.h>

/// An angle in radians
class Angle {
  public:
    Angle(double newr); ///< Constructor with radians set
    Angle(); ///< Default constructor, angle set to 0
    double radians() const; ///< Get angle as radians
    double degrees() const; ///< Get angle as degrees
    void radians(double newr); ///< Set angle as radians
    void degrees(double newd); ///< Set angle as degrees
    double operator()() const; ///< Get angle as radians
    void operator()(double newr); ///< Set angle as radians
    Angle operator+(const Angle b) const; ///< Allows addition of angles
    Angle operator-(const Angle b) const; ///< Allows subtraction of angles
    Angle operator+(const double b) const; ///< Allows addition of angles
    Angle operator-(const double b) const; ///< Allows subtraction of angles
    operator double() const; ///< Allows casting to double
  protected:
    double rad; ///< Internal storage of angle in radians
};

#endif // ANGLE_H
