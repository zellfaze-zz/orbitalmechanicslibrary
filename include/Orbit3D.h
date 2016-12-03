#ifndef ORBIT3D_H
#define ORBIT3D_H
#include <stdexcept>
#include "Angle.h"
#include "Vector3D.h"
#include <iostream>

enum class OrbitalShape { Circle, Ellipsis, Parabola, Hyperbola };
double const G = (6.674*pow(10,-11)); ///< Gravitational constant

///Represents an orbit around an unspecified central body
/**
This class defines an orbit around a central body using Keplerian
elements.  The elements used to define the orbit are the eccentricity,
semi-major axis, inclination, longitude of ascending node, argument
of periapsis, and mean anomaly.

All other return values are calculated in terms of these elements.
The Standard Gravitational Parameter (mew) is required to calculate
any elements that are based on the mass of the planet.
*/
class Orbit3D {
  public:
    Orbit3D();

    //Orbital elements
    inline double e() const {return e_var;} ///< Eccentricity
    inline void e(double newe) {e_var = newe;} ///< Set Eccentricity
    inline double eccentricity() const {return e();} ///< Alias of e()
    inline void eccentricity(double newe) {e(newe);} ///< Alias of e(double)

    inline double a() const {return a_var;} ///< Semi-major axis
    inline void a(double newa) {a_var = newa;} ///< Set Semi-major axis
    inline double semiMajorAxis() const {return a();} ///< Alias of a()
    inline void semiMajorAxis(double newa) {a(newa);} ///< Alias of a(double)

    inline Angle i() const {return i_var;} ///< Inclination
    inline void i(Angle newi) {i_var = newi;} ///< Set Inclination
    inline Angle inclination() const {return i();} ///< Alias of i()
    inline void inclination(Angle newi) {i(newi);} ///< Alias of i(Angle)

    inline Angle o() const {return o_var;} ///< Longitude of Ascending Node
    inline void o(Angle newo) {o_var = newo;} ///< Set Longitude of Ascending Node

    inline Angle w() const {return w_var;} ///< Argument of periapsis
    inline void w(Angle neww) {w_var = neww;} ///< Set Argument of periapsis
    inline Angle argumentOfPeriapsis() const {return w();} ///< Alias of w()
    inline void argumentOfPeriapsis(Angle neww) {w(neww);} ///< Alias of w(Angle)

    inline Angle M() const {return M_var;} ///< Mean Anomaly
    inline void M(Angle newM) {M_var = newM;} ///< Set Mean anomaly
    inline Angle meanAnomaly() const {return M();} ///< Alias of M()
    inline void meanAnomaly(Angle newM) {M(newM);} ///< Alias of M(Angle)

    /// Returns r_ap + r_per
    /** Divides the semi-major axis by 2 giving the sum
        of the distance between the apoapsis and periapsis.*/
    double PeriAndApoDistance() const;

    /// Distance to Periapsis
    double r_per() const;

    /// Distance to Apoapsis
    double r_ap() const;

    /// Major axis
    double MajorAxis() const;

    /// Semi Minor Axis
    double b() const;

    /// Alias of b()
    inline double semiMinorAxis() const {
      return b();
    }

    /// Minor Axis
    double MinorAxis() const;

    /// Orbital period
    double T(double mew) const;

    /// Alias of T()
    inline double orbitalPeriod(double mew) const {
      return T(mew);
    }

    ///\brief Calculates semi-major axis required for selected orbital period
    ///\param T The amount of time in seconds
    double calculateaForSpecificT(double T, double mew) const;

    ///\brief Calculates semi-major axis for synchronous orbit
    ///\param srp The time it takes for one rotation in seconds
    inline double calculateSyncOrbit(double srp, double mew) const {
      return calculateaForSpecificT(srp, mew);
    }

    /// Argument of Latitude
    /** Undefined in circular orbits with zero inclination,
        use trueLongitude() */
    Angle u() const;
    /// Alias of u()
    inline Angle argumentOfLatitude() const {
      return u();
    }

    /// True Longitude
    Angle l() const;
    /// Alias of l()
    inline Angle trueLongitude() const {
      return l();
    }

    /// True anomaly
    /** Undefined in circular orbits, use argumentOfLatitude() */
    Angle f() const;
    void f(Angle newf); ///< Set True anomaly
    inline Angle trueAnomaly() const {return f();} ///< Alias of f()
    inline void trueAnomaly(Angle newf) {f(newf);} ///< Alias of f(Angle)

    /// Eccentric Anomaly
    /** Calculated using Newton's method */
    Angle E() const;
    inline Angle eccentricAnomaly() const {return E();} ///< Alias of E()

    /// Semi-Latus Rectum
    double ell() const;

    /// Alias of ell()
    inline double semiLatusRectum() const {
      return ell();
    }

    /// Latus Rectum
    double latusRectum() const;

    /// \brief Focal Parameter
    ///
    /// Focal parameter is infinite for circular orbits and this
    /// function will throw an exception.
    double p() const;

    /// Alias of p()
    inline double focalParameter() const {
      return p();
    }

    /// Shape of Orbit
    OrbitalShape shape() const;

    /// \brief Linear Eccentricity
    ///
    /// This is undefined for parabolic orbits and this function
    /// will throw an exception
    double c() const;

    /// Alias of c()
    inline double linearEccentricity() const {
      return c();
    }

    /// Radius from True Anomaly
    double radiusTrueAnomaly() const;

    /// Radius from Eccentric Anomaly
    double radiusEccentricAnomaly() const;

    /// Specific Orbital Energy
    double epsilon(double mew) const;

    /// Alias of epsilon()
    inline double specificOrbitalEnergy(double mew) const {
      return epsilon(mew);
    }

    /// Mean Orbital Speed
    double v(double mew) const;
    /// Alias of v(double)
    inline double meanOrbitalSpeed(double mew) const {return v(mew);}

    /// Specific Relative Angular Momentum
    Vector3D hBar() const;

    /// Alias of hBar()
    inline Vector3D specificRelativeAngularMomentum() const {
      return hBar();
    }

    /// Orbital state vector position
    Vector3D osvr() const;

    /// Orbital state vector velocity
    Vector3D osvv() const;

    /// Line of nodes vector
    Vector3D lineOfNodes() const;

    /// Mean Motion
    double n(double mew) const;
    /// Alias of n(double)
    inline double meanMotion(double mew) const {
      n(mew);
    }

    /// Mean longitude
    double meanLongitude() const;

    /// Longitude of Periapsis
    double longitudeOfPeriapsis() const;

    /// Angular Momentum
    Vector3D h() const;

    /// Alias of h()
    inline Vector3D angularMomentum() const {
      return h();
    }

  protected:
    //Orbital elements
    double e_var; ///< Eccentricity
    double a_var; ///< Semi-major axis
    Angle i_var; ///< Inclination
    Angle o_var; ///< Longitude of Ascending Node
    Angle w_var; ///< Argument of periapsis
    Angle M_var; ///< Mean anomaly
};

#endif // ORBIT3D_H
