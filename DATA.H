

const rows  = 18;
const colls = 19;
const float tilecount = 15;
const float tilewidth = 32.0/480.0;
const float pixel = 1.0/480.0;
const chips=11;
int map[18][19] =
  {{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  { 1, 1, 1, 1, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 1, 1, 1, 1},
  { 1, 1, 1, 1, 2, 1, 1, 1, 2, 2, 2, 1, 1, 1, 2, 1, 1, 1, 1},
  { 1, 1, 1, 1, 2, 1,15, 1, 2, 3, 2, 1,15, 1, 2, 1, 1, 1, 1},
  { 1, 1, 2, 2, 2, 2, 2, 4, 2, 5, 2, 4, 2, 2, 2, 2, 2, 1, 1},
  { 1, 1, 2, 1,14, 1, 6, 1, 1, 1, 1, 1, 7, 1,14, 1, 2, 1, 1},
  { 1, 1, 2, 1,15, 1, 2,12, 1, 1, 1,11, 2, 1,15, 1, 2, 1, 1},
  { 1, 1, 2, 2, 2, 2, 2,15, 1, 1, 1,15, 2, 2, 2, 2, 2, 1, 1},
  { 1, 1, 2, 1, 15,1, 2,12, 1, 1, 1,11, 2, 1,15, 1, 2, 1, 1},
  { 1, 1, 2, 1, 1, 1, 7, 1, 1,15, 1, 1, 6, 1, 1, 1, 2, 1, 1},
  { 1, 1, 2, 2, 2, 2, 2, 2, 8, 2, 8, 2, 2, 2, 2, 2, 2, 1, 1},
  { 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1},
  { 1, 1, 1, 1, 1, 1, 2, 1,15, 2,15, 1, 2, 1, 1, 1, 1, 1, 1},
  { 1, 1, 1, 1, 1, 1, 2, 1,13, 2,13, 1, 2, 1, 1, 1, 1, 1, 1},
  { 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1},
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

int bound[18][19] =
 {{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0},
  { 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0},
  { 0, 0, 0, 0, 1, 0,10, 0, 1,12, 1, 0,10, 0, 1, 0, 0, 0, 0},
  { 0, 0, 1, 1, 1, 1, 1, 4, 1,11, 1, 4, 1, 1, 1, 1, 1, 0, 0},
  { 0, 0, 1, 0, 9, 0, 3, 0, 0, 0, 0, 0, 2, 0, 9, 0, 1, 0, 0},
  { 0, 0, 1, 0,10, 0, 1, 7, 0, 0, 0, 6, 1, 0,10, 0, 1, 0, 0},
  { 0, 0, 1, 1, 1, 1, 1,10, 0, 0, 0,10, 1, 1, 1, 1, 1, 0, 0},
  { 0, 0, 1, 0,10, 0, 1, 7, 0, 0, 0, 6, 1, 0,10, 0, 1, 0, 0},
  { 0, 0, 1, 0, 0, 0, 2, 0, 0,10, 0, 0, 3, 0, 0, 0, 1, 0, 0},
  { 0, 0, 1, 1, 1, 1, 1, 1, 5, 1, 5, 1, 1, 1, 1, 1, 1, 0, 0},
  { 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 1, 0,10, 1,10, 0, 1, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 1, 0, 8, 1, 8, 0, 1, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
