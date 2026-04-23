// 42587
// https://school.programmers.co.kr/learn/courses/30/lessons/42587
#include<iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;


int solution(vector<int> priorities, int location) {
    // ----------init----------
    struct element {
        int index, priority;
    };
    int idx = 0, answer = 1;
    element e;
    queue<element> q;
    priority_queue<int> pq;

    // ----------processing----------
    for (int x : priorities) q.push(element{ idx++, x });
    for (int x : priorities) pq.push(x);

    // ----------main----------
    vector<element> debug;

    while(!q.empty()) {
        e = q.front();
        q.pop();

        if (e.priority >= pq.top()) {
            if (e.index == location)
                return answer;
            
            answer++;
            pq.pop();
        }
        else {
            q.push(e);
        }        
    }

    return answer;
}