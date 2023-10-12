#ifndef __NEGATIVE_IMAGE__
#define __NEGATIVE_IMAGE__

#include <opencv2/opencv.hpp>

class NegativeImage {

  public:
    cv::Mat execute(const cv::Mat *image);

};

#endif
