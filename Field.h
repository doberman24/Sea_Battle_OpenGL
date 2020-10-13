class Field
{
private:
  int W, H, St, BW, BH;
public:
  Field(int _W, int _H, int _St, int _BW, int _BH):
    W(_W), H(_H), St(_St), BW(_BW), BH(_BH) {}
  void DisplayField()
  {
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    for (int i = BW; i <= W + BW; i += St)
      {
	glVertex2f(i, BH);
	glVertex2f(i, H + BH);
      }
    for (int i = BH; i <= H + BH; i += St)
      {
	glVertex2f(BW, i);
	glVertex2f(W + BW, i);
      }
    glEnd();
  }
};
