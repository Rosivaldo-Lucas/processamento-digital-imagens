#include "../includes/ConversionImage.hpp"

HSB **ConversionImage::converterRgbToHsb(const cv::Mat *image) {
  const int imageRows = image->rows;
  const int imageCols = image->cols;

  // std::vector<std::vector<HSB>> hsbResult(imageRows, std::vector<HSB>(imageCols));

  HSB **hsbResult = new HSB * [imageRows];

  for (int i = 0; i < imageRows; i++) {
    hsbResult[i] = new HSB[imageCols];
  }

  cv::Mat convertedOriginalImage;

  image->convertTo(convertedOriginalImage, CV_8UC3);

  double R = 0.0;
  double G = 0.0;
  double B = 0.0;

  for (int i = 0; i < imageRows; i++) {
    for (int j = 0; j < imageCols; j++) {

      cv::Vec3b rgbChannel = convertedOriginalImage.at<cv::Vec3b>(i, j);

      R = ((double) rgbChannel[2] / 255.0);
      G = ((double) rgbChannel[1] / 255.0);
      B = ((double) rgbChannel[0] / 255.0);

      double max = std::max(R, std::max(G, B));
      double min = std::min(R, std::min(G, B));

      double h = 0.0;

      if (max == R && G >= B) {
        h = 60 * ((G - B) / (max - min));
      } else if (max == R && G < B) {
        h = 60 * ((G - B) / (max - min)) + 360;
      } else if (max == G) {
        h = 60 * ((B - R) / (max - min)) + 120;
      } else if (max == B) {
        h = 60 * ((R - G) / (max - min)) + 240;
      }

      double s = 0.0;

      if (max == 0) {
        s = 0.0;
      } else {
        s = (1.0 - (min / max));
      }

      double b = max;

      HSB hsb;
      hsb.hue = h;
      hsb.saturation = s;
      hsb.brightness = b;

      hsbResult[i][j] = hsb;
    }
  }

  return hsbResult;
}

cv::Mat ConversionImage::converterHsbToRgb(HSB **hsb, int rows, int cols) {
  // const int rowsHsb = hsb->size();
  // const int colsHsb = (rowsHsb > 0) ? hsb[0].size() : 0;

  cv::Mat image(rows, cols, CV_8UC3);

  cv::Vec3b rgbChannel;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      double R = 0;
      double G = 0;
      double B = 0;

      if (hsb[i][j].saturation == 0) {
        R = G = B = hsb[i][j].brightness;

      } else {
        double sectorPos = hsb[i][j].hue / 60.0;

        int sectorNumber = (int) std::floor(sectorPos);

        double fractionalSector = sectorPos - sectorNumber;

        double p = hsb[i][j].brightness * (1.0 - hsb[i][j].saturation);
        double q = hsb[i][j].brightness * (1.0 - (hsb[i][j].saturation * fractionalSector));
        double t = hsb[i][j].brightness * (1.0 - (hsb[i][j].saturation * (1 - fractionalSector)));

        switch (sectorNumber) {
          case 0:
            R = hsb[i][j].brightness;
            G = t;
            B = p;

            break;
          case 1:
            R = q;
            G = hsb[i][j].brightness;
            B = p;

            break;
          case 2:
            R = p;
            G = hsb[i][j].brightness;
            B = t;

            break;
          case 3:
            R = p;
            G = q;
            B = hsb[i][j].brightness;

            break;
          case 4:
            R = t;
            G = p;
            B = hsb[i][j].brightness;

            break;
          case 5:
            R = hsb[i][j].brightness;
            G = p;
            B = q;

            break;
        }
      }

      rgbChannel[2] = static_cast<uchar>(std::abs(R) * 255);
      rgbChannel[1] = static_cast<uchar>(std::abs(G) * 255);
      rgbChannel[0] = static_cast<uchar>(std::abs(B) * 255);

      image.at<cv::Vec3b>(i, j) = rgbChannel;
    }
  }

  return image;
}

