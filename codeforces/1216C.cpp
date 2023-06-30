#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;


struct Rect {
    int x1, y1, x2, y2;

    long long area() {
        return (long long)(x2 - x1) * (y2 - y1);
    }
};

long long intersect(const Rect&, const Rect&);
Rect intersectingRect(const Rect&, const Rect&);

int main() {
    Rect white, black1, black2, b1Inside, b2Inside;
    long long b1Cover, b2Cover, totalCover;

    cin >> white.x1 >> white.y1 >> white.x2 >> white.y2;
    cin >> black1.x1 >> black1.y1 >> black1.x2 >> black1.y2;
    cin >> black2.x1 >> black2.y1 >> black2.x2 >> black2.y2;

    b1Cover = intersect(white, black1);
    b2Cover = intersect(white, black2);
    b1Inside = intersectingRect(white, black1);
    b2Inside = intersectingRect(white, black2);

    totalCover = b1Cover + b2Cover - intersect(b1Inside, b2Inside);
    
    if (white.area() - totalCover == 0) cout << "NO"; 
    else cout << "YES"; 
    
}

long long intersect(const Rect& rect1, const Rect& rect2) {
    long long x = max(0, min(rect1.x2, rect2.x2) - max(rect1.x1, rect2.x1));
    long long y = max(0, min(rect1.y2, rect2.y2) - max(rect1.y1, rect2.y1));

    return x * y;
}

Rect intersectingRect(const Rect& rect1, const Rect& rect2) {
    Rect rect;

    if (intersect(rect1, rect2)) {
        rect.x1 = max(rect1.x1, rect2.x1);
        rect.x2 = min(rect1.x2, rect2.x2);
        rect.y1 = max(rect1.y1, rect2.y1);
        rect.y2 = min(rect1.y2, rect2.y2);
    } else {
        rect.x1 = 0;
        rect.x2 = 0;
        rect.y1 = 0;
        rect.y2 = 0;
    }

    return rect;
}