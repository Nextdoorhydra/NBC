#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    stack<char> st;

    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < s.size(); j++) {
            char c = s[j];

            switch (c) {
            case '(':
            case '{':
            case '[':
                st.push(c);
                break;
            case ')':
                if (st.empty())
                    goto EXIT;
                if (st.top() == '(') {
                    st.pop();
                }
                break;
            case '}':
                if (st.empty())
                    goto EXIT;
                if (st.top() == '{') {
                    st.pop();
                }
                break;
            case ']':
                if (st.empty())
                    goto EXIT;
                if (st.top() == '[') {
                    st.pop();
                }
                break;
            }
        }
        if (st.size() == 0) {
            answer++;
        }

        // µ¹·Á
    EXIT:s.push_back(s[0]);
        s.erase(0, 1);
    }


    return answer;
}

int main() {
    string s = "}]()[{";
    int result = solution(s);
    return 0;
}