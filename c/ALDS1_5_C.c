#include <stdio.h>
#include <math.h>

typedef struct {
    double x, y;
} Point;


void koch(int n, Point *p1, Point *p2);

int main(int argc, char const* argv[])
{
    int n;
    scanf("%d", &n);

    Point p1 = {0, 0}, p2 = {100, 0};

    printf("0 0\n");
    koch(n, &p1, &p2);
    printf("100 0\n");

    return 0;
}

void koch(int n, Point *p1, Point *p2) {
    if (n == 0) return;

    Point s, t, u;
    s.x = (2 * p1->x + p2->x) / 3.0;
    s.y = (2 * p1->y + p2->y) / 3.0;
    u.x = (p1->x + 2 * p2->x) / 3.0;
    u.y = (p1->y + 2 * p2->y) / 3.0;

    double theta = M_PI / 3.0;
    t.x = (u.x - s.x) * cos(theta) - (u.y - s.y) * sin(theta) + s.x;
    t.y = (u.x - s.x) * sin(theta) + (u.y - s.y) * cos(theta) + s.y;

    koch(n-1, p1, &s);
    printf("%lf %lf\n", s.x, s.y);
    koch(n-1, &s, &t);
    printf("%lf %lf\n", t.x, t.y);
    koch(n-1, &t, &u);
    printf("%lf %lf\n", u.x, u.y);
    koch(n-1, &u, p2);
}
