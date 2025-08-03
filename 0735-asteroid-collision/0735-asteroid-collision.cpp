#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> st;

        for (int asteroid : ast) {
            bool exploded = false;
            if (asteroid > 0) {
                // If the asteroid is moving right, it will never collide with anything
                // on the stack (yet), so we just push it.
                st.push(asteroid);
            } else { // asteroid is moving left
                while (!st.empty() && st.top() > 0) {
                    // Collision can only happen if asteroid is moving left and st.top() is moving right.
                    if (st.top() < abs(asteroid)) {
                        // The asteroid on the stack is smaller, so it gets destroyed.
                        st.pop();
                    } else if (st.top() == abs(asteroid)) {
                        // Both asteroids are the same size, so they both get destroyed.
                        st.pop();
                        exploded = true; // Mark as exploded so we don't push the current asteroid
                        break; // No need to check further collisions for this asteroid
                    } else { // st.top() > abs(asteroid)
                        // The current asteroid is smaller, so it gets destroyed.
                        exploded = true;
                        break; // The stack top remains, so we can stop checking for this asteroid.
                    }
                }
                
                // If the current asteroid has not exploded (it won't push itself
                // if it was destroyed by a larger asteroid on the stack)
                // and either the stack is empty or the top of the stack is also moving left,
                // we can push the current asteroid onto the stack.
                if (!exploded) {
                    st.push(asteroid);
                }
            }
        }

        // The stack contains the remaining asteroids in reverse order.
        vector<int> res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        // Reverse the vector to get the correct order.
        std::reverse(res.begin(), res.end());
        return res;
    }
};