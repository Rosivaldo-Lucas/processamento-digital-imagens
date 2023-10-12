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