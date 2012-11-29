class Solution {
    char * trim(char *p) {
        while(*p==' ') {
            p++;
        }
        int len=strlen(p);
        for (int i=len-1; i>=0; i--) {
            if (p[i]==' '){
                p[i] = '\0';
            }
            else {
                break;
            }
        }
        
        return p;
    }
    bool is_pure_num2(char *p) {
        
        while(*p!='\0') {
            if (*p>'9' || *p<'0') {
                return false;
            }
            p++;
        }
        return true;
    }
    bool is_mark_num(char *p) {
        if (*p=='-' || *p=='+') {
            return is_pure_num(p+1);
        }
        else {
            return false;
        }
    }
    bool is_pure_num(char *p) {
        while(*p!='\0') {
            if (*p>'9' || *p<'0') {
                return false;
            }
            p++;
        }
        return true;
    }
    bool is_ex(char *p) {
        char * x = p;
        while(*x != '\0' && *x != 'e') {
            x++;
        }
        if (*x!='e') {
            return false;
        }
        
        *x= '\0';
        if (x==p)
            return false;
        bool ret = (is_pure_num(p) || (is_mark_num(p) && strlen(p+1)>0) || is_point(p)) && ((is_pure_num(x+1) && strlen(x+1)>0) || (is_mark_num(x+1) && strlen(x+2)>0));
        *x= 'e';
        return ret;
    }
    bool is_mark(char *p) {
        if (*p=='+' || *p=='-') {
            return true;
        }
        return false;
    }
    bool is_point(char *p) {
        char * x = p;
        while(*x != '\0' && *x != '.') {
            x++;
        }
        if (*x!='.') {
            return false;
        }
        
        *x= '\0';
        
        bool ret = (is_pure_num(p) || is_mark_num(p)) && (is_pure_num(x+1));
        
        int len = 0;
        if (is_pure_num(p)) {
            len+=strlen(p);
        }
        if (is_pure_num(x+1)) {
            len+=strlen(x+1);
        }
        if (is_mark_num(p)) {
            len+=strlen(p+1);
        }
       
        
        *x= '.';
        return ret && len>0;
    }
public:
    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        char * p = (char *)malloc(strlen(s) + 1);
        strcpy(p, s);
        p = trim(p);
        
        if (strlen(p)==0) {
            return false;
        }
        if (is_pure_num(p)) {
            return true;
        }
        if (is_mark_num(p) && strlen(p+1) > 0) {
            return true;
        }
        
        if (is_point(p)) {
            return true;
        }
        if (is_ex(p)) {
            return true;
        }
        return false;
    }
};
