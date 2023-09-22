#include <iostream>
#include <cmath>

#include <opencv2/opencv.hpp>

int n = 15;
int m = 15;
int strid = 1;

double imagem[5][4] = {
  {1.0,  2.0,  3.0,  4.0},
  {5.0,  6.0,  7.0,  8.0},
  {9.0,  10.0, 11.0, 12.0},
  {13.0, 14.0, 15.0, 16.0},
  {17.0, 18.0, 19.0, 20.0}
};

double filtro_media_3x3[3][3] = {
  {1.0/9.0, 1.0/9.0, 1.0/9.0},
  {1.0/9.0, 1.0/9.0, 1.0/9.0},
  {1.0/9.0, 1.0/9.0, 1.0/9.0}
};

double filtro_media_15x15[15][15] = {
  {1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0},
  {1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0},
  {1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0},
  {1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0},
  {1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0},
  {1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0},
  {1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0},
  {1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0},
  {1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0},
  {1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0},
  {1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0},
  {1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0},
  {1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0, 1.0/225.0}
};

double filtro_media_1x15[1][15] = {
  {1.0/15.0, 1.0/15.0, 1.0/15.0, 1.0/15.0, 1.0/15.0, 1.0/15.0, 1.0/15.0, 1.0/15.0, 1.0/15.0, 1.0/15.0, 1.0/15.0, 1.0/15.0, 1.0/15.0, 1.0/15.0, 1.0/15.0}
};

double filtro_media_15x1[15][1] = {
  {1.0/15.0}, {1.0/15.0}, {1.0/15.0}, {1.0/15.0}, {1.0/15.0}, {1.0/15.0}, {1.0/15.0}, {1.0/15.0}, {1.0/15.0}, {1.0/15.0}, {1.0/15.0}, {1.0/15.0}, {1.0/15.0}, {1.0/15.0}, {1.0/15.0}
};

void correlacao(int L, int C) {
  int L_resultante = L - n + 1;
  int C_resultante = C - m + 1;

  double imagem_resultante[L_resultante][C_resultante];

  for (int i = 0; i <= L - n; i++) {
    for (int j = 0; j <= C - m; j++) {

      double produto = 0.0;

      for (int ii = i; ii < n + i; ii++) {
        for (int jj = j; jj < m + j; jj++) {
          
          produto = produto + (filtro_media_3x3[ii][jj] * imagem[ii][jj]);

        }
      }

      imagem_resultante[i][j] = produto;
    }
  }

  for (int i = 0; i < L_resultante; i++) {
    for (int j = 0; j < C_resultante; j++) {
      std::cout << imagem_resultante[i][j] << " ";

      if (j == (C_resultante - 1)) {
        std::cout << "" << std::endl;
      }
    }
  }

}

cv::Mat correlacao2(cv::Mat *image, int L, int C) {
  int L_resultante = L - n + 1;
  int C_resultante = C - m + 1;

  cv::Mat imagem_resultante(L_resultante, C_resultante, CV_8UC3);

  cv::Mat imagem_original_convetida;
  
  image->convertTo(imagem_original_convetida, CV_8UC3);

  for (int i = 0; i <= L - n; i++) {
    for (int j = 0; j <= C - m; j++) {

      double R = 0.0;
      double G = 0.0;
      double B = 0.0;

      for (int ii = i; ii < n + i; ii++) {
        for (int jj = j; jj < m + j; jj++) {

          cv::Vec3b canais = imagem_original_convetida.at<cv::Vec3b>(ii, jj);

          R = R + (filtro_media_15x15[ii - i][jj - j] * canais[2]);
          G = G + (filtro_media_15x15[ii - i][jj - j] * canais[1]);
          B = B + (filtro_media_15x15[ii - i][jj - j] * canais[0]);
        }
      }

      cv::Vec3b canais_resultantes;
      canais_resultantes[2] = R;
      canais_resultantes[1] = G;
      canais_resultantes[0] = B;

      imagem_resultante.at<cv::Vec3b>(i, j) = canais_resultantes;
    }
  }

  imagem_resultante.convertTo(imagem_resultante, CV_8UC3);

  return cv::abs(imagem_resultante);
}

cv::Mat negativo_rgb(cv::Mat *image) {
  int L = image->rows;
  int C = image->cols;

  cv::Mat imagem_original_convertida;

  image->convertTo(imagem_original_convertida, CV_8UC3);

  cv::Vec3b canais;

  for (int i = 0; i < L; i++) {
    for (int j = 0; j < C; j++) {
      canais = imagem_original_convertida.at<cv::Vec3b>(i, j);

      canais[2] = 255 - canais[2];
      canais[1] = 255 - canais[1];
      canais[0] = 255 - canais[0];

      imagem_original_convertida.at<cv::Vec3b>(i, j) = canais;
    }
  }

  return cv::abs(imagem_original_convertida);
}

int main() {

  cv::Mat imagem;

  imagem = cv::imread("DancingInWater.jpg", cv::IMREAD_COLOR);

  if (!imagem.data) {
    std::cout << "não abriu imagem" << std::endl;
  }
  
  // cv::Mat nova_imagem = correlacao2(&imagem, imagem.rows, imagem.cols);

  cv::Mat nova_imagem_negativa = negativo_rgb(&imagem);

  cv::namedWindow("janela", cv::WINDOW_NORMAL);
  cv::resizeWindow("janela", 800, 800);

  // cv::imshow("janela", nova_imagem);
  cv::imshow("janela", nova_imagem_negativa);
  cv::waitKey();

  return 0;
}
