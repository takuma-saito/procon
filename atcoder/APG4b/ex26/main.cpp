#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
map<char, int> var_int;
map<char, vector<int>> var_vec;

char read_char() {
    char ch;
    cin >> ch;
    //cout << "DEBUG: " << ch << endl;
    return ch;
}
char expr_int_term() {
    char ch = read_char();
    return (ch >= '0' && ch <= '9') ? ch - '0' : var_int.at(ch);
}

int eval_int_expr() {
    int val = expr_int_term();
    while (true) {
        char op = read_char();
        if (op == '+') {
            val += expr_int_term();
        } else if (op == '-') {
            val -= expr_int_term();
        } else if (op == ';') {
            break;
        } else {
            runtime_error("unexpected: ch");
        }
    }
    return val;
}

void eval_int() {
    char ch, v;
    ch = read_char();
    v = ch;
    ch = read_char();
    if (ch != '=') {
        runtime_error("execpted '='");
    }
    var_int.insert_or_assign(v, eval_int_expr());
}

void eval_print_int() {
    char c;
    cout << eval_int_expr() << endl;
}

vector<int> eval_vec_expr() {
    vector<int> vec;
    char ch;
    ch = read_char();
    if (ch != '[') {
        return var_vec.at(ch);
    }
    while (true) {
        vec.push_back(expr_int_term()); // TODO 配列が空の場合は考慮していない
        char ch = read_char();
        if (ch == ',') {} else if (ch == ']') {
            break;
        } else {
            runtime_error("unknwon ch=" + ch); 
        }
    }
    return vec;
}

void eval_vec() {
    char ch, v;
    ch = read_char();
    v = ch;
    ch = read_char(); // skip
    if (ch != '=') {
        runtime_error("execpted '='");
    }
    var_vec.insert_or_assign(v, eval_vec_expr());
    ch = read_char();
    if (ch != ';') {
        runtime_error("execpted ';'");
    }
}

void vec_plus(vector<int>& a, vector<int> b) {
    rep(i, a.size()) { a[i] += b[i]; }
}

void vec_minus(vector<int>& a, vector<int> b) {
    rep(i, a.size()) {  a[i] -= b[i]; }
}

void eval_print_vec() {
    vector<int> a = eval_vec_expr();
    while (true) {
        char op = read_char();
        if (op == '+') {
            vec_plus(a, eval_vec_expr());
        } else if (op == '-') {
            vec_minus(a, eval_vec_expr());
        } else if (op == ';') {
            break;
        } else {
            runtime_error("unknwon operator: " + op);
        }
    }
    cout << '[';
    rep(i, a.size()) {
        cout << ' ' << a[i];
    }
    cout << " ]" << endl;
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
            eval_print_int();
        } else if (op == "vec") {
            eval_vec();
        } else if (op == "print_vec") {
            eval_print_vec();
        } else {
            cout << "[Error] OP = "  << op << endl;
            exit(1);
        }
    }
}
