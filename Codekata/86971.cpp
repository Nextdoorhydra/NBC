//#include <iostream>
//#include <string>
//#include <vector>
//#include <queue>
//#include <map>
//
//using namespace std;
//
//int solution(int n, vector<vector<int>> wires) {
//    // init
//    int answer = -1, visitCount = 0;
//    map<int, vector<int>> edges;
//    queue<int> q;
//    vector<bool> Isvisited(n);
//
//    // process
//    for (int i = 0; i < wires.size(); i++) {
//        wires[i][0]--; 
//        wires[i][1]--;
//        edges[wires[i][0]].push_back(wires[i][1]);
//        edges[wires[i][1]].push_back(wires[i][0]);
//    }
//
//    // main
//    for (int i = 0; i < wires.size(); i++) {
//        int skip1 = wires[i][0], skip2 = wires[i][1];
//        visitCount = 0;
//        Isvisited.assign(n, false);
//
//        //bfs
//        q.push(0);
//        Isvisited[0] = true;
//
//        while (!q.empty()) {
//
//            visitCount++;
//
//            int curr = q.front();
//            q.pop();
//
//            for (int i : edges[curr]) {
//                if ((curr == skip1 && i == skip2) || (curr == skip2 && i == skip1))
//                    continue;
//                else if (!Isvisited[i]) {
//                    Isvisited[i] = true;
//                    q.push(i);
//                }
//            }
//        }
//
//        cout << visitCount << endl;
//    }
//
//
//    return answer;
//}
//
//int main(void) {
//    vector<vector<int>> v{ {1,3}, {2,3}, {3,4}, {4,5}, {4,6}, {4,7}, {7,8}, {7,9} };
//    int n = 9;
//
//    cout << solution(n, v) << endl;
//
//    return 0;
//}