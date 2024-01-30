class Solution {
public:
    //The lowest time in leetcode just check first if the token is a number or not. Then proceed with the same logic.
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int aux1, aux2;
        for(int i = 0; i<tokens.size(); ++i){
            if(tokens[i] == "+"){
                aux1 = st.top(); st.pop();
                aux2 = st.top(); st.pop();
                st.push(aux2+aux1);
            }
            else if(tokens[i] == "-"){
                aux1 = st.top(); st.pop();
                aux2 = st.top(); st.pop();
                st.push(aux2-aux1);
            }
            else if(tokens[i] == "*"){
                aux1 = st.top(); st.pop();
                aux2 = st.top(); st.pop();
                st.push(aux2*aux1);
            }
            else if(tokens[i] == "/"){
                aux1 = st.top(); st.pop();
                aux2 = st.top(); st.pop();
                st.push(aux2/aux1);
            }
            else st.push(stoi(tokens[i]));
        }
        return st.top();
    }
};