struct Marker
{
  int x, y, BH, St;
  int n;
Marker(int _n, int _BH, int _St): n(_n), BH(_BH), St(_St)
{
  x = BH + St / 2 + n * St; 
  y = BH + St / 2 + n * St;
}
};

struct Cell
{
  float x, y, c1, c2, c3;
  int size;
Cell(float _x = 0.0, float _y = 0.0, int _s = 0,
     float _c1 = 0.0, float _c2 = 0.0, float _c3 = 0.0)
{
  x = _x;
  y = _y;
  size = _s;
  c1 = _c1;
  c2 = _c2;
  c3 = _c3;
}

  void Draw()
  {
    glColor3f(c1, c2, c3);
    glVertex2f(this->x - 12 / size, this->y + 11 / size);
    glVertex2f(this->x + 11 / size, this->y + 11 / size);
    glVertex2f(this->x + 11 / size, this->y - 11 / size);
    glVertex2f(this->x - 12 / size, this->y - 11 / size);
  }
};
