#include <bits/stdc++.h>

using namespace std;

namespace ge
{
    // 误差精度
    constexpr double eps = 1e-8;
    constexpr long double pi = 3.1415926535897932384l;
    // x的正负
    int sign(double x)
    {
        if (fabs(x) < eps)
            return 0;
        if (x < 0)
            return -1;
        return 1;
    }
    // 比较xy的大小
    int cmp(double x, double y)
    {
        if (fabs(x - y) < eps)
            return 0;
        if (x < y)
            return -1;
        return 1;
    }
    template <class T>
    struct point
    {
        T x, y;
        // point()=default;
        point(T x = 0, T y = 0) : x(x), y(y) {}
        bool operator<(const point &B) const
        {
            return x == B.x ? y < B.y : x < B.x;
        }
        bool operator==(const point &B) const
        {
            return !sign(x - B.x) && !sign(y - B.y);
        }
        point operator+(const point &B) const
        {
            return point(x + B.x, y + B.y);
        }
        point operator-(const point &B) const
        {
            return point(x - B.x, y - B.y);
        }
        point operator*(const T a) const
        {
            return point(x * a, y * a);
        }
        point operator/(const T a) const
        {
            return point(x / a, y / a);
        }
        T operator*(const point &B) const
        {
            return x * B.x + y * B.y;
        }
        // OA OB的叉积
        T operator^(const point &B) const
        {
            return x * B.y - y * B.x;
        }
        point operator-() const
        {
            return point(-x, -y);
        }
        // OA的幅角
        double angle() const
        {
            return atan2(this->y, this->x);
        }
        T length2() const
        {
            return x * x + y * y;
        }
        double length() const
        {
            return sqrt(length2());
        }
        // 单位向量
        point Unit()
        {
            return *this / this->length();
        }
        // 单位法向量
        point Normal()
        {
            return point(-y, x) / this->length();
        }
        // 化为长度为r的向量
        point trunc(double r)
        {
            double l = length();
            if (!sign(l))
                return *this;
            r /= l;
            return point(x * r, y * r);
        }
        // 左旋90度
        point toleft()
        {
            return point(-y, x);
        }
        // 右旋90度
        point toright()
        {
            return point(y, -x);
        }
        // 逆时针旋转
        point rotate(double rad)
        {
            return point(x * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad));
        }
        bool up() const
        {
            return y > 0 || (y == 0 && x >= 0);
        }
        // ab叉积ac的符号
        static int relation(const point &a, const point &b, const point &c)
        {
            return sign((b - a) ^ (c - a));
        }
        // OA与OB的角度
        static double get_angle(const point &a, const point &b)
        {
            return acos((a * b) / a.length() / b.length());
        }
        // 面积2倍
        static T area(const point &a, const point &b, const point &c)
        {
            return abs((b - a) ^ (c - a));
        }
        // ab长度平方
        static T get_dist2(const point &a, const point &b)
        {
            return (a - b).length2();
        }
        // ab长度
        static double get_dist(const point &a, const point &b)
        {
            return sqrt(get_dist2(a, b));
        }
        // 求向量ac在向量ab上的投影长度
        static double project(const point &a, const point &b, const point &c)
        {
            return ((b - a) * (c - a)) / (b - a).length();
        }
        // 按一,二,三,四象限的顺序(逆时针)
        bool argcmp(const point &A, const point &B)
        {
            if (A.up() ^ B.up())
                return A.up() > B.up();
            return (A ^ B) > 0;
        }
        // 将点A绕点B顺时针旋转theta(弧度)
        point turn_PP(const point &a, const point &b, double theta)
        {
            double x = (a.x - b.x) * cos(theta) + (a.y - b.y) * sin(theta) + b.x;
            double y = -(a.x - b.x) * sin(theta) + (a.y - b.y) * cos(theta) + b.y;
            return point(x, y);
        }
    };
    template <class T>
    struct Line
    {
        using Point = point<T>;
        Point p, v;
        double rad;
        Line() {}
        Line(Point P, Point V) : p(P), v(V)
        {
            rad = atan2(v.y, v.x);
        }
        Point get_point_in_line(double t) const
        {
            return p + v * t;
        }
        bool operator<(const Line &L) const
        {
            if (!cmp(rad, L.rad))
                return L.onLeft(p) > 0;
            return rad < L.rad;
        }
        int onLeft(const Point &a) const
        { // 点a是否在直线的左边(>0:左  <0:右)
            return relation(p, p + v, a);
        }
        double distance(const Point &a)
        { // 点a到直线的距离
            return abs((v ^ (a - p)) / v.length());
        }
        Point foot_point(const Point &a)
        { // 点a在直线上的投影(垂足)
            return p + v * ((v * (a - p)) / (v * v));
        }
        Point symmetry_point(const Point &a)
        { // 点a关于直线的对称点
            Point q = foot_point(a);
            return Point(2 * q.x - p.x, 2 * q.y - p.y);
        }
        friend Point getIntersection(const Line &a, const Line &b)
        { // 两直线交点(不能平行)
            Point u = a.p - b.p;
            double t = (b.v ^ u) / (a.v ^ b.v);
            return a.get_point_in_line(t);
        }
        friend bool on_right(const Line &a, const Line &b, const Line &c)
        { // b,c的交点是否在直线a的右边
            Point o = getIntersection(b, c);
            return a.onLeft(o) <= 0;
        }
    };

}

int main()
{

    return 0;
}