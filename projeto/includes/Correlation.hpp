#ifndef __CORRELATION__
#define __CORRELATION__

#include <opencv2/opencv.hpp>
#include <vector>

class Correlation {

  private:

  public:
    cv::Mat execute(const cv::Mat *image, const std::vector<std::vector<double>> *filter);
    
};

#endif
