//#include <iostream>
//#include <string>
//#include <vector>
//#include <map>
//#include <algorithm>
//
//using namespace std;
//
//int solution(vector<string> want, vector<int> number, vector<string> discount) {
//    // ¼±¾ð
//    vector<int> vn;
//    int answer = 0;
//    map<std::string, int> m;
//
//    // pre-process
//    for (int i = 0; i < want.size(); ++i) {
//        m.insert({ want[i], i });
//    }
//
//    // main
//    for (int i = 0; i + 10 < discount.size(); ++i) {
//        vn = number;
//
//        for (int j = i; j < i + 10; ++j) {
//            std::string key = discount[j];
//
//            if (m.find(key) != m.end()) {
//                int idx = m[key];
//
//                vn[idx] -= vn[idx] > 0 ? 1 : 0;
//            }
//        }
//
//        if (std::find(vn.begin(), vn.end(), 0) == vn.end())
//            answer++;
//    }
//
//    return answer;
//}
//
//int main() {
//    cout << solution(vector<string> {"banana", "apple", "rice", "pork", "pot"},
//        vector<int> {3, 2, 2, 2, 1},
//        vector<string> {"chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana"}
//    ) << endl;
//
//    return 0;
//}