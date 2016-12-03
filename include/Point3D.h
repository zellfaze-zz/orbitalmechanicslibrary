#ifndef POINT3D_H
#define POINT3D_H

/// A point in 3-dimensional space
class Point3D
{
  public:
    Point3D();

    //Point parameters
    inline double x() const {return x_val;} ///< Get coord x
    inline void x(double newx) {x_val = newx;} ///< Set coord x
    inline double y() const {return y_val;} ///< Get coord y
    inline void y(double newy) {y_val = newy;} ///< Set coord y
    inline double z() const {return z_val;} ///< Get coord z
    inline void z(double newz) {z_val = newz;} ///< Set coord z

  private:
    double x_val;
    double y_val;
    double z_val;
};

#endif // POINT3D_H
