#include <vector>

struct point_pos {
    int x;
    int y;
};

typedef std::vector<point_pos> polygon_pos;

bool Contains(polygon_pos poly, point_pos pt);

polygon_pos *QuickHull(polygon_pos pts);

polygon_pos *MinkowskiSum(polygon_pos pts1, polygon_pos pts2, point_pos origin);

polygon_pos *MinkowskiDifference(polygon_pos pts1, polygon_pos pts2,point_pos origin);

bool GJK(polygon_pos pts1, polygon_pos pts2, point_pos origin);