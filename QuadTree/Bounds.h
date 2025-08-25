#ifndef __BOUNDS_H__
#define __BOUNDS_H__

/**
    @class   Bounds
    @brief   객체가 겹치는 지 판단하기 위한 객체
    @details ~왼쪽 상단 기준으로 위치 잡음
**/

class Bounds
{
#pragma region 특수 멤버 함수
public:
    Bounds(float x, float y, float width = 1.0f, float height = 1.0f);
    ~Bounds() = default;
#pragma endregion

#pragma region 공개 함수
public:
    bool Intersects(const Bounds& other) const;
#pragma endregion

#pragma region 인라인 함수
public:
    /**
        @brief  x위치의 중점을 반환하는 함수
        @retval  - x위치 중점
    **/
    inline float GetPosX()     const { return _x; }
    
    /**
        @brief  y위치의 중점을 반환하는 함수
        @retval  - y위치 중점
    **/
    inline float GetPosY()     const { return _y; }
    
    /**
        @brief  가로 길이를 반환하는 함수
        @retval  - 가로 길이
    **/
    inline float GetWidth()    const { return _width; }
    
    /**
        @brief  세로 길이를 반환하는 함수
        @retval  - 세로 길이
    **/
    inline float GetHeight()   const { return _height; }


    /**
        @brief  x좌표의 최솟값을 반환하는 함수
        @retval  - x좌표의 최솟값
    **/
    inline float GetMinX()     const { return _x; }
    
    /**
        @brief  x좌표의 최댓값을 반환하는 함수
        @retval  - x좌표의 최댓값
    **/
    inline float GetMaxX()     const { return _x + _width; }
    
    /**
        @brief  y좌표의 최솟값을 반환하는 함수
        @retval  - y좌표의 최솟값
    **/
    inline float GetMinY()     const { return _y; }
    
    /**
        @brief  y좌표의 최댓값을 반환하는 함수
        @retval  - y좌표의 최댓값
    **/
    inline float GetMaxY()     const { return _y + _height; }
#pragma endregion

#pragma region 멤버 변수
private:
    float _x        = 0.0f;
    float _y        = 0.0f;
    float _width    = 0.0f;
    float _height   = 0.0f;
#pragma endregion
};

#endif

