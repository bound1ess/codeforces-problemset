#include <cstdio>

const int N = 12, ROTATIONS = 4;
const char UP = 'U', DOWN = 'D', LEFT = 'L', RIGHT = 'R';
char map[N][N], angle[N][N];
bool visited[N][N];

inline bool validate_xy(int x, int y, int w, int h) {
  return 0 <= x && x < h && 0 <= y && y < w;
}

inline void update_xy(int &x, int &y, char direct) {
  switch (direct) {
    case UP: --y; break;
    case DOWN: ++y; break;
    case LEFT: --x; break;
    case RIGHT: ++x; break;
  }
}

inline void rotate(char &direct) {
  switch (direct) {
    case UP: direct = RIGHT; break;
    case RIGHT: direct = DOWN; break;
    case DOWN: direct = LEFT; break;
    case LEFT: direct = UP; break;
  }
}

int main() {
  int w, h, x = -1, y, area = 0;
  char direct;
  scanf("%d%d", &w, &h);
  for (int i = 0; i < w; ++i) {
    scanf("%s", map[i]);
  }
  for (int i = 0; i < w && x == -1; ++i) {
    for (int j = 0; j < h; ++j) {
      if (map[i][j] != '.' && map[i][j] != '*') {
        y = i, x = j;
        direct = map[y][x];
        break;
      }
    }
  }
  while ( ! visited[y][x] || angle[y][x] != direct) {
    angle[y][x] = direct;
    if ( ! visited[y][x]) {
      visited[y][x] = true;
      ++area;
    }
    for (int i = 0; i < ROTATIONS; ++i) {
      int old_x = x, old_y = y;
      update_xy(x, y, direct);
      if (validate_xy(x, y, w, h) && map[y][x] != '*') {
        break;
      }
      x = old_x, y = old_y;
      rotate(direct);
    }
  }
  printf("%d\n", area);
  return 0;
}
