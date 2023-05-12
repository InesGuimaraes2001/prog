#include <rgb/image.hpp>
//#include <rgb/color.hpp>

namespace rgb {
    image::image(int w, int h, const color &fill) {
        iwidth = w;
        iheight = h;

        /*int size_pixels = w * h;
        pixels = new color *[h];
        color *pointer = new color[size_pixels];
        for (int i = 0; i <= h - 1; i++) {
            pixels[i] = pointer + i * w;
            for (int j = 0; j <= h - 1; j++) {
                pixels[i][j] = fill;
            }
        }*/
        pixels = new color*[w];
        for(int i = 0; i < w; ++i)
            pixels[i] = new color[h];

        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                pixels[i][j] = fill;
            }
        }
    }

    image::~image() {
        for (int i = 0; i < width(); i++) {
            delete[] pixels[i];
        }
        delete[] pixels;
    }

    int image::width() const {
        return iwidth;
    }

    int image::height() const {
        return iheight;
    }

    color &image::at(int x, int y) {
        return pixels[x][y];
    }

    const color &image::at(int x, int y) const {
        return pixels[x][y];
    }

    void image::invert() {
        for (int i = 0; i < width(); i++) {
            for (int j = 0; j < height(); j++) {
                pixels[i][j].invert();
            }
        }
    }

    void image::to_gray_scale() {
        for (int i = 0; i < width(); i++) {
            for (int j = 0; j < height(); j++) {
                pixels[i][j].to_gray_scale();
            }
        }
    }

    void image::fill(int x, int y, int w, int h, const color &c) {
        for (int i = x; i < x + w; i++) {
            for (int j = y; j < y + h; j++) {
                pixels[i][j] = c;
            }
        }
    }

    void image::replace(const color &a, const color &b) {
        for (int i = 0; i < width(); i++) {
            for (int j = 0; j < height(); j++) {
                if (pixels[i][j] == a) {
                    pixels[i][j] = b;
                }
            }
        }
    }

    void image::add(const image &img, const color &neutral, int x, int y) {
        for (int i = x; i < width(); i++) {
            for (int j = y; j < height(); j++) {
                for (int k = 0; k < img.width(); k++) {
                    for (int q = 0; q < img.height(); q++) {
                        if (img.pixels[k][q] != neutral)
                            pixels[i][j] = img.pixels[k][q];
                    }
                }
            }
        }
    }

    void image::crop(int x, int y, int w, int h) {
        iwidth = w;
        iheight = h;
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                pixels[i][j] = pixels[x + i][y + j];
            }
        }
    }

    void image::rotate_left() {
        color **new_values = new color *[width()];
        color *data = new color[width() * height()];
        for (int k = 0; k < width(); k++) {
            new_values[k] = &data[k * height()];
        }

        for (int i = 0; i < height(); i++) {
            for (int j = 0; j < width(); j++) {
                new_values[j][i] = pixels[i][j];
            }
        }

        int temp = iheight;
        iheight = iwidth;
        iwidth = temp;

        delete[] pixels[0];
        delete[] pixels;



        for (int i = 0; i < width(); i++) {


            int start = 0;
            int end = height() - 1;


            while (start < end) {


                color *temp = new color;
                *temp = new_values[start][i];
                new_values[start][i] = new_values[end][i];
                new_values[end][i] = *temp;


                start++;
                end--;
            }


            pixels = new_values;

        }
    }

    void image::rotate_right() {
        color **new_values = new color *[width()];
        color *data = new color[width() * height()];
        for (int k = 0; k < width(); k++) {
            new_values[k] = &data[k * height()];
        }

        for (int i = 0; i < height(); i++) {
            for (int j = 0; j < width(); j++) {
                new_values[j][i] = pixels[i][j];
            }
        }

        int temp = iheight;
        iheight = iwidth;
        iwidth = temp;

        delete[] pixels[0];
        delete[] pixels;



        for (int i = 0; i < height(); i++) {


            int start = 0;
            int end = width() - 1;


            while (start < end) {



                color *tmp = new color;
                *tmp = new_values[i][start];
                new_values[i][start] = new_values[i][end];
                new_values[i][end] = *tmp;


                start++;
                end--;
            }


            pixels = new_values;

        }
    }

    void image::mix(const image &img, int factor) {
        for (int i = 0; i < img.width(); i++) {
            for (int j = 0; j < img.height(); j++) {
                img.pixels[i][j].mix(pixels[i][j], factor);
            }
        }
    }
}