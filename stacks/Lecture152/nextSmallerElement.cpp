#include <iostream>
#include <stack>
#include <vector>

using namespace std;



int main() {
    vector<int> input;
    input.push_back(2);
    input.push_back(1);
    input.push_back(4);
    input.push_back(3);

    stack<int> st;
    st.push(-1);

    vector<int> ans(input.size()); // Use parentheses for initialization
    for (int i = input.size() - 1; i >= 0; i--) {
        int curr = input[i];

        while (st.top() >= curr) {
            st.pop();
        }

        // Small element found
        ans[i] = st.top();
        // Push
        st.push(curr);
    }

    cout << "Printing: " << endl;
    for (int i = 0; i < input.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0; // Return statement indicating successful execution
}
