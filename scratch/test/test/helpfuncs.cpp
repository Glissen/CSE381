#include "helpfuncs.h"
#include <iostream>
#include <iterator>


void PrintPoly(polygon_pos poly) {
    for (int i = 0; i < poly.size(); i ++) {
        std::cout << "{" << poly.at(i).x << "," << poly.at(i).y << "}";
    }
    std::cout << std::endl;
}

int Area2(point_pos a, point_pos b, point_pos c) {
    return (b.x - a.x) * (c.y - a.y) - 
            (c.x - a.x) * (b.y - a.y);
}

bool LeftOn(point_pos a, point_pos b, point_pos c) {
    return Area2(a, b, c) >= 0;
}

bool Left(point_pos a, point_pos b, point_pos c) {
    return Area2(a, b, c) > 0;
}

bool Contains(polygon_pos poly, point_pos pt) {
    bool ans1 = true, ans2 = true;
    for (int i = 0; i < poly.size() - 1; i ++) {
        if (!LeftOn(poly.at(i), poly.at(i+1), pt)) {
            ans1 = false;
        }
        if (Left(poly.at(i), poly.at(i+1), pt)) {
            ans2 = false;
        }
    }
    if (!LeftOn(poly.at(poly.size()-1), poly.at(0), pt))
        ans1 = false;
    if (Left(poly.at(poly.size()-1), poly.at(0), pt))
        ans2 = false;
    return ans1 || ans2;
}

int FarthestPoint(polygon_pos pts, point_pos start, point_pos end) {
    int max_dist = 0;
    int ans = -1;
    for (int i = 0; i < pts.size(); i ++) {
        int temp = Area2(start, end, pts.at(i));
        if (temp > max_dist) {
            max_dist = temp;
            ans = i;
        }
    }
    return ans;
}

void InsertPoint(polygon_pos *ans, point_pos pt) {
    for (int i = 0; i < ans->size(); i ++) {
        if (ans->at(i).x == pt.x && ans->at(i).y == pt.y) {
            return;
        }
    }
    ans->push_back(pt);
}

void QuickHullHelper(polygon_pos pts, point_pos start, point_pos end, polygon_pos *ans) {
    int ind = FarthestPoint(pts, start, end);
    if (ind > 0) {
        point_pos tmp = pts.at(ind);
        QuickHullHelper(pts, start, tmp, ans);
        QuickHullHelper(pts, tmp, end, ans);
    }
    else {
        InsertPoint(ans, start);
        InsertPoint(ans, end);
    }
}

polygon_pos *QuickHull(polygon_pos pts) {
    point_pos right = pts.at(0);
    point_pos left = pts.at(0);
    for (int i = 1; i < pts.size(); i ++) {
        if (pts.at(i).x < left.x) {
            left = pts.at(i);
        }
        if (pts.at(i).x > right.x) {
            right = pts.at(i);
        }
    }
    polygon_pos *ans = new polygon_pos;
    QuickHullHelper(pts, left, right, ans);
    QuickHullHelper(pts, right, left, ans);
    return ans;
}

polygon_pos *MinkowskiSum(polygon_pos pts1, polygon_pos pts2, point_pos origin) {
    polygon_pos *poly1 = QuickHull(pts1);
    polygon_pos *poly2 = QuickHull(pts2);
    polygon_pos poly3 = {};
    for (int i = 0; i < poly1->size(); i++) {
        point_pos pt1 = poly1->at(i);
        for (int j = 0; j < poly2->size(); j++) {
            point_pos pt2 = poly2->at(j);
            poly3.push_back({pt1.x + pt2.x - origin.x, pt1.y + pt2.y - origin.y});
        }
    }
    delete poly1;
    delete poly2;
    return QuickHull(poly3);
}

polygon_pos *MinkowskiDifference(polygon_pos pts1, polygon_pos pts2, point_pos origin) {
    polygon_pos *poly1 = QuickHull(pts1);
    polygon_pos *poly2 = QuickHull(pts2);
    polygon_pos poly3 = {};
    for (int i = 0; i < poly1->size(); i++) {
        point_pos pt1 = poly1->at(i);
        for (int j = 0; j < poly2->size(); j++) {
            point_pos pt2 = poly2->at(j);
            poly3.push_back({pt1.x - pt2.x + origin.x, pt1.y - pt2.y + origin.y});
        }
    }
    delete poly1;
    delete poly2;
    return QuickHull(poly3);
}

bool GJK(polygon_pos pts1, polygon_pos pts2, point_pos origin) {
    polygon_pos *m_diff = MinkowskiDifference(pts1, pts2, origin);
    bool ans = Contains(*m_diff, origin);
    delete m_diff;
    return ans;
}

int main() {
    polygon_pos poly1 = {{0,0}, {0,2}, {2,2}, {2,0}};
    polygon_pos poly2 = {{0,0}, {0,2}, {2,2}, {2,0}};
    // point_pos pt = {1,1};
    // std::cout << Contains(poly, pt) << std::endl;
    // PrintPoly(poly);
    PrintPoly(*MinkowskiSum(poly1, poly2, {0,0}));
    PrintPoly(*MinkowskiDifference(poly1, poly2, {0,0}));
    bool ans = GJK(poly1, poly2, {0,0});
    std::cout << (ans);
}