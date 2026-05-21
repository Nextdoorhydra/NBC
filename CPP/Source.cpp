#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <Windows.h>

// 화면 크기 정의
const int SCREEN_WIDTH = 120;
const int SCREEN_HEIGHT = 40;

// 맵 크기 및 정의 (1: 벽, 0: 빈 공간)
const int MAP_WIDTH = 16;
const int MAP_HEIGHT = 16;

int main_()
{
    // 콘솔 스크린 버퍼 생성 (화면 깜빡임 방지)
    wchar_t* screen = new wchar_t[SCREEN_WIDTH * SCREEN_HEIGHT];
    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hConsole);
    DWORD dwBytesWritten = 0;

    // 2D 맵 데이터
    std::wstring map;
    map += L"################";
    map += L"#..............#";
    map += L"#...########...#";
    map += L"#..........#...#";
    map += L"#....####..#...#";
    map += L"#..............#";
    map += L"#...##########.#";
    map += L"#..............#";
    map += L"#.############.#";
    map += L"#..............#";
    map += L"####...#######.#";
    map += L"#..............#";
    map += L"#.##########...#";
    map += L"#..............#";
    map += L"################";

    // 플레이어 초기 상태 (위치, 시선 방향 각도)
    float playerX = 1.0f;
    float playerY = 1.0f;
    float playerA = 0.0f; // 시선 각도 (라디안)

    // 시야각 (FOV)
    float fov = 3.14159f / 4.0f;
    // 최대 렌더링 거리
    float depth = 16.0f;

    // 시간 계산용 변수
    auto tp1 = std::chrono::system_clock::now();
    auto tp2 = std::chrono::system_clock::now();

    // 게임 루프
    while (true)
    {
        // 프레임 타임 계산 (부드러운 이동용)
        tp2 = std::chrono::system_clock::now();
        std::chrono::duration<float> elapsedTime = tp2 - tp1;
        tp1 = tp2;
        float fElapsedTime = elapsedTime.count();

        // 입력 처리 (조작법: A/D 회전, W/S 전진/후진)
        if (GetAsyncKeyState((unsigned short)'A') & 0x8000) playerA -= (2.0f) * fElapsedTime;
        if (GetAsyncKeyState((unsigned short)'D') & 0x8000) playerA += (2.0f) * fElapsedTime;

        if (GetAsyncKeyState((unsigned short)'W') & 0x8000)
        {
            playerX += sinf(playerA) * 5.0f * fElapsedTime;
            playerY += cosf(playerA) * 5.0f * fElapsedTime;
            // 벽 충돌 검사
            if (map[(int)playerY * MAP_WIDTH + (int)playerX] == '#')
            {
                playerX -= sinf(playerA) * 5.0f * fElapsedTime;
                playerY -= cosf(playerA) * 5.0f * fElapsedTime;
            }
        }
        if (GetAsyncKeyState((unsigned short)'S') & 0x8000)
        {
            playerX -= sinf(playerA) * 5.0f * fElapsedTime;
            playerY -= cosf(playerA) * 5.0f * fElapsedTime;
            // 벽 충돌 검사
            if (map[(int)playerY * MAP_WIDTH + (int)playerX] == '#')
            {
                playerX += sinf(playerA) * 5.0f * fElapsedTime;
                playerY += cosf(playerA) * 5.0f * fElapsedTime;
            }
        }

        // 화면 가로 픽셀만큼 레이캐스팅 수행
        for (int x = 0; x < SCREEN_WIDTH; x++)
        {
            // 각 픽셀에 해당하는 레이의 상대 각도 계산
            float rayAngle = (playerA - fov / 2.0f) + ((float)x / (float)SCREEN_WIDTH) * fov;

            float distanceToWall = 0.0f;
            bool hitWall = false;

            float eyeX = sinf(rayAngle); // 레이의 단위 방향 벡터 X
            float eyeY = cosf(rayAngle); // 레이의 단위 방향 벡터 Y

            // 벽을 만날 때까지 레이를 전진시킴
            while (!hitWall && distanceToWall < depth)
            {
                distanceToWall += 0.1f;

                int testX = (int)(playerX + eyeX * distanceToWall);
                int testY = (int)(playerY + eyeY * distanceToWall);

                // 레이가 맵 경계를 벗어난 경우
                if (testX < 0 || testX >= MAP_WIDTH || testY < 0 || testY >= MAP_HEIGHT)
                {
                    hitWall = true;
                    distanceToWall = depth; // 최대 거리 처리
                }
                else
                {
                    // 벽과 충돌한 경우
                    if (map[testY * MAP_WIDTH + testX] == '#')
                    {
                        hitWall = true;
                    }
                }
            }

            // 거리에 따른 벽 높이(천장과 바닥의 위치) 계산
            int ceiling = (float)(SCREEN_HEIGHT / 2.0) - SCREEN_HEIGHT / ((float)distanceToWall);
            int floor = SCREEN_HEIGHT - ceiling;

            // 벽면에 음영 효과를 주기 위한 문자 선택
            wchar_t wallChar = ' ';
            if (distanceToWall <= depth / 4.0f)      wallChar = 0x2588; // 아주 가까움 (꽉 찬 블록)
            else if (distanceToWall < depth / 3.0f)  wallChar = 0x2593; // 가까움
            else if (distanceToWall < depth / 2.0f)  wallChar = 0x2592; // 중간
            else if (distanceToWall < depth)         wallChar = 0x2512; // 먼 거리
            else                                     wallChar = ' ';    // 보이지 않음

            // 화면 세로줄 채우기
            for (int y = 0; y < SCREEN_HEIGHT; y++)
            {
                if (y < ceiling)
                {
                    screen[y * SCREEN_WIDTH + x] = ' '; // 천장
                }
                else if (y >= ceiling && y <= floor)
                {
                    screen[y * SCREEN_WIDTH + x] = wallChar; // 벽
                }
                else
                {
                    // 바닥 (거리에 따른 음영 표현)
                    float b = 1.0f - (((float)y - SCREEN_HEIGHT / 2.0f) / ((float)SCREEN_HEIGHT / 2.0f));
                    if (b < 0.25)      screen[y * SCREEN_WIDTH + x] = '#';
                    else if (b < 0.5)  screen[y * SCREEN_WIDTH + x] = 'x';
                    else if (b < 0.75) screen[y * SCREEN_WIDTH + x] = '.';
                    else               screen[y * SCREEN_WIDTH + x] = ' ';
                }
            }
        }

        // 스크린 버퍼를 콘솔 화면에 출력
        screen[SCREEN_WIDTH * SCREEN_HEIGHT - 1] = '\0';
        WriteConsoleOutputCharacterW(hConsole, screen, SCREEN_WIDTH * SCREEN_HEIGHT, { 0,0 }, &dwBytesWritten);
    }

    return 0;
}