#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define 진짜정수 int
#define 정수 long
#define 동안에 while
#define 반환 return
#define 를_위해서 for
#define 수 n
#define 나머지_연산 %
#define 나누기 /
#define 곱하다 *
#define 빼다 -
#define 더하다 +
#define 대입 =
#define 같다 ==
#define 같지않다 !=
#define 적다 <
#define 크다 >
#define 대입 =
#define 공 0
#define 하나 1
#define 둘 2
#define 삼 3
#define 넷 4
#define 오 5
#define 여섯 6
#define 칠 7
#define 팔 8
#define 아홉 9
#define 끝 ;
#define 정답 solution
#define 소괄호_열다 (
#define 소괄호_닫다 )
#define 중괄호_열다 {
#define 중괄호_닫다 }
#define 기본 main
// 흥미로움
#define 같이 &
#define 연결_구현(가, 나) 가##나
#define 연결(가, 나) 연결_구현(가, 나)

정수 정답 소괄호_열다 진짜정수 수 소괄호_닫다
중괄호_열다
string 문자열 대입 "" 끝
정수 정수 반환값 대입 공 끝
동안에 소괄호_열다 수 크다 공 소괄호_닫다
중괄호_열다
정수 정수 나머지 대입 수 나머지_연산 삼 끝
정수 정수 몫 대입 수 나누기 삼 끝
수 대입 수 나누기 삼 끝
문자열.push_back 소괄호_열다 나머지 더하다 '0' 소괄호_닫다 끝
중괄호_닫다
정수 정수 가 대입 하나 끝
동안에 소괄호_열다 !문자열.empty 소괄호_열다 소괄호_닫다 소괄호_닫다
중괄호_열다
반환값 대입 반환값 더하다 가 곱하다 atoi(같이 문자열.back 소괄호_열다 소괄호_닫다) 끝
문자열.pop_back 소괄호_열다  소괄호_닫다  끝
가 대입 가 곱하다 삼 끝
중괄호_닫다
반환 반환값;
중괄호_닫다

// 진짜정수 기본 소괄호_열다 소괄호_닫다
// 중괄호_열다
// 정답 소괄호_열다 3 소괄호_닫다 끝
// 반환 공 끝
// 중괄호_닫다

#undef 기본
#undef 진짜정수
#undef 정수
#undef 같지않다
#undef 동안에 
#undef 반환
#undef 를_위해서
#undef 수
#undef 나머지_연산
#undef 나누기
#undef 곱하다
#undef 빼다
#undef 더하다
#undef 대입
#undef 같다
#undef 적다
#undef 크다
#undef 공
#undef 하나
#undef 둘
#undef 삼
#undef 넷
#undef 오
#undef 여섯
#undef 칠
#undef 팔
#undef 아홉 
#undef 끝 
#undef 정답
#undef 소괄호_열다 
#undef 소괄호_닫다 
#undef 중괄호_열다 
#undef 중괄호_닫다 