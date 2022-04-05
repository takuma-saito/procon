#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
map<char, int> var_int;
map<char, vector<int>> var_vec;

int eval_int_expr() {
    stack<int> stack;
    char ch;
    while (ch != ';') {
        cin >> ch;
        if (ch >= '0' && ch <= '9') {
            stack.push(ch - '0');
        } else if (ch == '+') {
            char a = stack.top();
            stack.pop();
            char b = stack.top();
            stack.pop();
            stack.push(a + b);
        } else if (ch == '-') {
            char a = stack.top();
            stack.pop();
            char b = stack.top();
            stack.pop();
            stack.push(a-b);
        } else {
            stack.push(var_int.at(ch));
        }
    }
    if (stack.size() != 1) {
        runtime_error("invalid stack");
    }
    return stack.top();
}

void eval_int() {
    char ch, v;
    cin >> ch;
    v = ch;
    cin >> ch; // skip
    if (ch != '=') {
        runtime_error("execpted '='");
    }
    var_int[v] = eval_int_expr();
}

void print_int() {
    char c;
    cout << eval_int_expr() << endl;
}

vector<int> eval_vec_expr() {
    vector<int> vec;
    char ch;
    cin >> ch;
    if (ch != '[') {
        return var_vec.at(ch);
    }
    while (ch != ']') {
        cin >> ch;
        if (ch >= '0' && ch <= '9') {
            vec.push_back(ch - '0');
        } else if (ch == ',') {
            // skip
        } else {
            vec.push_back(var_int.at(ch));
        }
    }
    if (vec.size() != 1) {
        runtime_error("invalid vec");
    }
    return vec;
}

void eval_vec() {
    char ch, v;
    cin >> ch;
    v = ch;
    cin >> ch; // skip
    if (ch != '=') {
        runtime_error("execpted '='");
    }
    var_vec.at(v) = eval_vec_expr();
}

void vec_plus(const vector<int> &a, vector<int> &b) {
    if (a.empty()) {
        rep(i, b.size()) { a.push_back(b[i]); }
    } else {
        rep(i, a.size()) {
            a[i] += b[i];
        }
    }
}

void vec_minus(const vector<int> &a, vector<int> &b) {
    if (a.empty()) {
        rep(i, b.size()) { a=>push_back(-b[i]); }
    } else {
        rep(i, a.size()) {
            a[i] -= b[i];
        }
    }
}

void eval_print_vec() {
    char ch;
    vector<int> vec;
    while (ch != ';') {
        char op;
        vector<int> a, b;
        a = eval_vec_expr();
        cin >> op;
        b = eval_vec_expr();
        if (op == '+') {
            vec_plus(&a, &b)
            vec_plus(&val, &a)
        } else if (op == '-') {
            vec_minus(&a, &b)
            vec_plus(&val, &a)
        } else {
            runtime_error("unknwon operator: " + op);
        }
    }
    cout << '[';
    while (!vec.empty()) {
        cout << ' ';
        cout << vec.back();
        vec.pop_back();
    }
    cout << " ]";
}

int main()
{
    int N;
    cin >> N;
    rep(i, N) {
        string op;
        cin >> op;
        if (op == "int") {
            eval_int();
        } else if (op == "print_int") {
            //eval_print_int();
        } else if (op == "vec") {
            //eval_vec();
        } else if (op == "print_vec") {
            //eval_print_vec();
        } else {
            cout << "[Error] OP = "  << op << endl;
            exit(1);
        }
    }
}