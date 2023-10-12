#include "../includes/NegativeImage.hpp"

cv::Mat NegativeImage::execute(const cv::Mat *image) {
  const int imageRows = image->rows;
  const int imageCols = image->cols;

  cv::Mat convertedOriginalImage;

  image->convertTo(convertedOriginalImage, CV_8UC3);

  cv::Vec3b rgbChannelResult;

  for (int i = 0; i < imageRows; i++) {
    for (int j = 0; j < imageCols; j++) {
      rgbChannelResult = convertedOriginalImage.at<cv::Vec3b>(i, j);

      rgbChannelResult[2] = 255 - rgbChannelResult[2];
      rgbChannelResult[1] = 255 - rgbChannelResult[1];
      rgbChannelResult[0] = 255 - rgbChannelResult[0];

      convertedOriginalImage.at<cv::Vec3b>(i, j) = rgbChannelResult;
    }
  }

  return cv::abs(convertedOriginalImage);
}
