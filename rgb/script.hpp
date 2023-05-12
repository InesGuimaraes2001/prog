
//! @file script.hpp
#ifndef __rgb_script_hpp__
#define __rgb_script_hpp__

#include <fstream>
#include <rgb/image.hpp>

namespace rgb {
    class script /*: public image*/ {
    private:
        void fill();
        void open();
        void blank();
        void save();
        void invert();
        void to_gray_scale();
        void rotate_left();
        void rotate_right();
        void replace();
        void crop();
        void mix();
        void add();

    public:
        script(const std::string& filename);
        ~script();
        void process();
    private:
        image* img;
        std::ifstream input;
        std::string root_path;
    };
}
#endif
