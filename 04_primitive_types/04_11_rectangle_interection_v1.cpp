/***
Rectangle interesection.

Write a program which tests if two rectangles have a non-empty intersection. If the intersection is nonempty, return the rectangle formed by their intersection.
***/
#include <iostream>
#include <cstdlib>

typedef struct rect {
    int x1;
    int y1;
    int x2;
    int y2;
};

rect find_rect_intersection(rect r1, rect r2)
{
    rect iou;
    iou.x1 = std::max(r1.x1, r2.x1);
    iou.y1 = std::max(r1.y1, r2.y1);
    iou.x2 = std::min(r1.x2, r2.x2);
    iou.y2 = std::min(r1.y2, r2.y2);

    if (iou.y2 <= iou.y1 || iou.x2 <= iou.x1)
        return rect{-1, -1, -1, -1};

    return iou;
}

int main(int argc, char** argv)
{
    rect r1, r2;

    r1.x1 = atoi(argv[1]);
    r1.y1 = atoi(argv[2]);
    r1.x2 = atoi(argv[3]);
    r1.y2 = atoi(argv[4]);
   
    r2.x1 = atoi(argv[5]);
    r2.y1 = atoi(argv[6]);
    r2.x2 = atoi(argv[7]);
    r2.y2 = atoi(argv[8]);

    rect iou = find_rect_intersection(r1, r2);
    std::cout << iou.x1 << " " << iou.y1 << " " << iou.x2 << " " << iou.y2 << std::endl;

    return 0;
}
