//
// Created by balik on 24.10.18.
//

#ifndef PRACTICE_1_LONG_H
#define PRACTICE_1_LONG_H


class Long {
private:
    double meters;
    double centimeters;

    void convert() {
        if (centimeters < 100) return;

        double mtr = ((int) centimeters) / 100;
        meters += mtr;
        centimeters -= mtr * 100;
    }

public:
    /**Create/Delete**/
    Long(Long const &_long)
            : meters(_long.meters), centimeters(_long.centimeters) {}

    Long(double _meters = 0, double _centimeters = 0)
            : meters(_meters), centimeters(_centimeters) {
        convert();
    }

    Long &operator=(Long const &_long) {

        if (this != &_long) {
            meters = _long.meters;
            centimeters = _long.centimeters;
        }

        return *this;
    }

    ~Long() {}

    /**Get info**/
    float getCm() const {
        return (centimeters + (meters * 100));
    }

    float getCentimeters() const {
        return centimeters;
    }

    double getMeters() const {
        return meters;
    }

    /**Comparators**/
    friend bool operator==(Long const &left, Long const &right) {
        return (left.getCm() == right.getCm());
    }

    friend bool operator!=(Long const &left, Long const &right) {
        return !(left == right);
    }

    friend bool operator<(Long const &left, Long const &right) {
        return (left.getCm() < right.getCm());
    }

    friend bool operator>(Long const &left, Long const &right) {
        return (right < left);
    }

    /** +,* **/
    friend Long operator+(Long const &left, Long const &right) {
        return Long(0, left.getCm() + right.getCm());
    }


    friend Long operator*(Long const &_long, double number) {
        return Long(0, _long.getCm() * number);
    }

    friend Long operator*(double number, Long const &_long) {
        return (_long * number);
    }


    /**Input/Output**/
    friend std::ostream &operator<<(std::ostream &os, Long const &_long) {
        return os << "Meters=" << _long.meters << "\tCentimeters=" << _long.centimeters << "\n";
    }

    friend std::istream &operator>>(std::istream &is, Long &_long) {
        std::cout << "Enter meters and centimeters" << '\n';
        is >> _long.meters >> _long.centimeters;
        _long.convert();
        return is;
    }


};


#endif //PRACTICE_1_LONG_H
