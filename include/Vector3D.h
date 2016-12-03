#ifndef VECTOR3D_H
#define VECTOR3D_H
#include "Angle.h"
#include "Point3D.h"
#include <numeric>
#include <vector>
#include <iostream>

/// A vector in 3-dimensional space
class Vector3D : public Point3D{
  public:
    /// Constructor with coordinates
    Vector3D(double newx, double newy, double newz);
    /// Default constructor, makes zero vector
    Vector3D();
    /// Create a vector representing 2 sets of coordinates
    Vector3D(Point3D p1, Point3D p2);

    //Direction angles and cosines
    //Double check that the setters here work
    //  I worry about the magnitude calcs in it
    /// Angle from x axis to vector
    Angle alpha() const;
    /// Modify alpha angle
    void alpha(Angle newa);
    /// Angle from y axis to vector
    Angle beta() const;
    /// Modify beta angle
    void beta(Angle newa);
    /// Angle from z axis to vector
    Angle gamma() const;
    /// Modify gamma angle
    void gamma(Angle newa);

    //Spherical angles and cosines
    /// Angle from z axis to vector
    inline Angle theta() const {return gamma();}
    /// Angle from x axis to 2D vector
    Angle phi() const;

    //Alt vector parameters
    /// Returns magnitude of vector
    double magnitude() const;

    //Check stuff
    /// Checks if vector has no magnitude or direction
    bool isZero() const;
    /// Check if vector magnitude is 1
    bool isUnit() const;
    /// Allows vectors to be compared
    bool operator==(const Vector3D b) const;
    /// Checks if vector is opposite
    bool isOpposite(const Vector3D b) const;
    /// Checks if vector is parallel
    bool isParallel(const Vector3D b) const;
    /// Checks if vector is anitparallel
    bool isAntiparallel(const Vector3D b) const;

    //Math
    /// Allows vectors to be added
    Vector3D operator+(const Vector3D &b) const;
    /// Allows vectors to be subtracted
    Vector3D operator-(const Vector3D &b) const;
    /// Allows multiply vector by scalar
    Vector3D operator*(const double &b) const;
    /// Allows division vector by scalar
    Vector3D operator/(const double &b) const;
    /// Generate dot product of 2 vectors
    double dotProduct(const Vector3D b) const;
    /// Generate cross product of 2 vectors
    Vector3D crossProduct(const Vector3D b) const;
    /// Calculate angle between 2 vectors
    Angle findAngle(const Vector3D b) const;

  protected:/*
    double x_val; ///< Storage for x
    double y_val; ///< Storage for y
    double z_val; ///< Storage for z*/
};

#endif // VECTOR3D_H
