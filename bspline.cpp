public struct point
{
public int x;
public int y;
public void setxy(int i,int j)
{
x=i;
y=j;
}
public void clearxy()
{
x=0;
y=0;
}
}
public void BSPLINE(point p1,point p2,point p3,point p4,int divisions)
{
double []a=new double[4];
double []b=new double[4];
a[0] = ( -p1.x + 3*p2.x - 3*p3.x + p4.x)/6.0;
a[1] = ( 3*p1.x - 6*p2.x + 3*p3.x )/6.0;
a[2] = (-3*p1.x + 3*p3.x )/6.0;
a[3] = ( p1.x + 4*p2.x + p3.x )/6.0;
b[0] = ( -p1.y + 3*p2.y - 3*p3.y + p4.y)/6.0;
b[1] = ( 3*p1.y - 6*p2.y + 3*p3.y )/6.0;
b[2] = (-3*p1.y + 3*p3.y )/6.0;
b[3] = ( p1.y + 4*p2.y + p3.y )/6.0;
spline_out_x[0] = a[3];
spline_out_y[0] = b[3];
for (int i = 1 ; i < divisions ; i++)
{
float t; 
t = ((float) i) / ((float) divisions);
spline_out_x[i] = a[3] + t*(a[2] + t*(a[1] + t*a[0]));
spline_out_y[i] = b[3] + t*(b[2] + t*(b[1] + t*b[0]));
}
} 
public void plus_draw(int x,int y,int pen_width,Color cl )
{
Graphics g = Graphics.FromHwnd(this.Handle);
g.DrawLine(new Pen(cl,pen_width) ,x-3,y,x+3,y);
g.DrawLine(new Pen(cl,pen_width) ,x,y-3,x,y+3);
} 
public void Form_MouseUp(object sender, System.Windows.Forms.MouseEventArgs e)
{
if (Movement_Click>3)
{
pt[0]=pt[1];
pt[1]=pt[2];
pt[2]=pt[3];
pt[3].setxy(e.X,e.Y);
int no_of_interpolated_points=(int)(Math.Sqrt(Math.Pow((pt[2].x-pt[1].x),2)+Math.Pow((pt[2].y-pt[1].y),2)));
BSPLINE(pt[0],pt[1],pt[2],pt[3],no_of_interpolated_points);
for (int i=0;i<no_of_interpolated_points;i++)
plus_draw((int )spline_out_x[i],(int)spline_out_y[i],2,Color.Blue);
}
else
{
pt[Movement_Click].setxy(e.X,e.Y);
}
Movement_Click=Movement_Click+1;
plus_draw(e.X,e.Y,1,Color.Red);
}