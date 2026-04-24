//#include <iostream>
//#define TEST
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    // init
    struct Truck {
        int weight;
        int waitTime;
    };

    int answer = 1, currentWeight = 0, truck;
    vector<int> wait;
    queue<Truck> q;
    queue<Truck> wq;

    // process
    for (int w : truck_weights) {
        q.push(Truck{ w, bridge_length });
    }

    // main
    while (1) {

        if (!q.empty()) {
            Truck truck = q.front();

            if (weight >= currentWeight + truck.weight) {
                currentWeight += truck.weight;
                wq.push(truck);
                q.pop();
            }
        }

        if (!wq.empty()) {
            answer++;
            int loop = wq.size();


#ifdef TEST
            cout << "[";
            queue<Truck> f;

            for (int i = 0; i < loop; i++) {
                Truck _truck = wq.front();
                wq.pop();
                f.push(_truck);
                cout << _truck.weight << ", ";
            }

            cout << "]" << endl;;

            while (!f.empty()) {
                wq.push(f.front());
                f.pop();
            }
#endif


            for (int i = 0; i < loop; i++) {
                Truck _truck = wq.front();
                wq.pop();

                _truck.waitTime--;

                if (_truck.waitTime > 0) {
                    wq.push(_truck);
                }
                else {
                    currentWeight -= _truck.weight;
                }
            }
        }

        if (wq.empty() && q.empty()) break;
    }

    return answer;
}

//void main() {
//    //cout << solution(2, 10, vector<int>{7, 4, 5, 6}) << endl;
//    //cout << solution(100, 100, vector<int>{10}) << endl;
//    //cout << solution(100, 100, vector<int>{10, 10, 10, 10, 10, 10, 10, 10, 10, 10, }) << endl;
//}