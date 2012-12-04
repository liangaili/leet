class Solution {
private:
    string getNext(string p, int &pos) {
        string ret = "";
        while(pos<p.length() && p[pos]!='/') {
            ret+=p[pos];
            pos++;
        }
        pos++;
        return ret;
    }
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> stack;
        stack.clear();
        int pos = 0;
        while (pos<path.length()){
            string x = getNext(path, pos);

            if (x=="" || x=="."){
                continue;
            }
            if (x==".." ) {
                if (stack.size()>0)
                    stack.pop_back();
            }
            else {
                stack.push_back(x);
            }
        }

        if (stack.size()==0) {
            return "/";
        }
        string ret = "";
        for (int i=0; i<stack.size(); i++) {
            ret += "/";
            ret += stack[i];
        }
        return ret;
    }
};