#include "Bounds.h"

/*
*       Bounds의 특수 멤버 함수 
*/

Bounds::Bounds(float x, float y, float width, float height)
    : _x(x), _y(y), _width(width), _height(height)
{
}

/*
*       공개 함수
*/

bool Bounds::Intersects(const Bounds& other) const
{
    /* 다른 영역이 현재 영역의 오른쪽 바깥인지 확인 */

    // case 상대의 x최솟값이 나의 maxX보다 클 때
    if (other.GetMinX() > GetMaxX()) {
        return false;
    }

    // case 상대의 x최댓값이 나의 minX보다 작을 때
    if (other.GetMaxX() < GetMinX()) {
        return false;
    }

    // case 상대의 y최솟값이 나의 maxY보다 클 때
    if (other.GetMinY() > GetMaxY()) {
        return false;
    }

    // case 상대의 y최댓값이 나의 minY보다 작을 때
    if (other.GetMaxY() < GetMinY()) {
        return false;
    }

    // 전부 해당하지 않으면 충돌
    return true;
}
