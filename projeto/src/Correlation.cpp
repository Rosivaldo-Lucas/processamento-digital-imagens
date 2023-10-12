#include "../includes/Correlation.hpp"

cv::Mat Correlation::execute(const cv::Mat *image, const std::vector<std::vector<double>> *filter) {
  const int rowsFilter = filter->size();
  const int colsFilter = (rowsFilter > 0) ? filter[0].size() : 0;

  const int imageRows = image->rows;
  const int imageCols = image->cols;

  const int rowsResult = image->rows - rowsFilter + 1;
  const int colsResult = image->cols - colsFilter + 1;

  cv::Mat imageResult(rowsResult, colsResult, CV_8UC3);

  cv::Mat convertedOriginalImage;
  
  image->convertTo(convertedOriginalImage, CV_8UC3);

  for (int i = 0; i <= imageRows - rowsFilter; i++) {
    for (int j = 0; j <= imageCols - colsFilter; j++) {

      double R = 0.0;
      double G = 0.0;
      double B = 0.0;

      for (int ii = i; ii < rowsFilter + i; ii++) {
        for (int jj = j; jj < colsFilter + j; jj++) {

          cv::Vec3b rgbChannel = convertedOriginalImage.at<cv::Vec3b>(ii, jj);

          R = R + (filter->at(ii - i).at(jj - j) * rgbChannel[2]);
          G = G + (filter->at(ii - i).at(jj - j) * rgbChannel[1]);
          B = B + (filter->at(ii - i).at(jj - j) * rgbChannel[0]);
        }
      }

      cv::Vec3b rgbChannelResult;
      rgbChannelResult[2] = R;
      rgbChannelResult[1] = G;
      rgbChannelResult[0] = B;

      imageResult.at<cv::Vec3b>(i, j) = rgbChannelResult;
    }
  }

  imageResult.convertTo(imageResult, CV_8UC3);

  return cv::abs(imageResult);
}
