#include <rgb/color.hpp>

namespace rgb {
    const color color::BLACK(0,0,0);
    const color color::WHITE(255,255,255);
    const color color::RED(255,0,0);
    const color color::GREEN(0,255,0);
    const color color::BLUE(0,0,255);
    color::color() {
        r = 0;
        g = 0;
        b = 0;
    }
    color::color(const color& other) {
        r = other.r;
        g = other.g;
        b = other.b;
    }
    color::color(rgb_value red, rgb_value green, rgb_value blue) {
        r = red;
        g = green;
        b = blue;
    }
    rgb_value color::red() const {
        return r;
    }
    rgb_value color::green() const {
        return g;
    }
    rgb_value color::blue() const {
        return b;
    }
    rgb_value& color::red()  {
        return r;
    }
    rgb_value& color::green()  {
        return g;
    }
    rgb_value& color::blue()  {
        return b;
    }
    color& color::operator=(const color& c) {
        r = c.r;
        g = c.g;
        b = c.b;
        return *this;
    }
    bool color::operator==(const color &c) const {
        return r == c.r && g == c.g && b == c.b;
    }
    bool color::operator!=(const color &c) const {
        return r != c.r || g != c.g || b != c.b;
    }
    void color::invert() {
        rgb_value temp_r = r;
        rgb_value temp_g = g;
        rgb_value temp_b = b;
        r = 255 - temp_r;
        g = 255 - temp_g;
        b = 255 - temp_b;
    }

    void color::mix(const color& c, int f) {
        rgb_value temp_r = r;
        rgb_value temp_g = g;
        rgb_value temp_b = b;
        r = (((100 - f)*temp_r) + (f*c.r))/100;
        g = (((100 - f)*temp_g) + (f*c.g))/100;
        b = (((100 - f)*temp_b) + (f*c.b))/100;
    }


    void color::to_gray_scale() {
        rgb_value temp_r = r;
        rgb_value temp_g = g;
        rgb_value temp_b = b;
        rgb_value v = (temp_r + temp_g + temp_b)/3;
        r = v;
        g = v;
        b = v;
    }
}