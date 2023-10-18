#ifndef __CONVERSION_RGB_TO_HSB__
#define __CONVERSION_RGB_TO_HSB__

#include <opencv2/opencv.hpp>
#include <vector>
#include <cmath>

typedef struct HSB {
  double hue;
  double saturation;
  double brightness;
} HSB;

class ConversionImage {

  public:
    HSB **converterRgbToHsb(const cv::Mat *image);
    cv::Mat converterHsbToRgb(HSB **hsb, int rows, int cols);

    HSB **alterHue(HSB **hsb, int rows, int cols, double additionalHue);

};

#endif
