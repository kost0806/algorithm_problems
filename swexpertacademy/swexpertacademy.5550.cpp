// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWWxqfhKAWgDFAW4

#include <cstdio>
#include <vector>
#include <cstring>

#define max(a, b) (a) > (b) ? (a) : (b)

using namespace std;

int T;
int table[115];

int main() {
    scanf("%d", &T);

    table['c'] = 1;
    table['r'] = 2;
    table['o'] = 3;
    table['a'] = 4;
    table['k'] = 5;

    for (int t = 1; t <= T; ++t) {
        char str[2501];
        vector<int> croak;
        scanf("%s", str);

        size_t len = strlen(str);
        int ret = -1;
        int frogs = 0;
        for (int i = 0; i < len; ++i) {
            if (str[i] == 'c') {
                croak.push_back(2);
                ++frogs;
                ret = max(ret, frogs);
            }
            else {
                bool find = false;
                for (int j = frogs - 1; j >= 0; --j) {
                    if (croak[j] == table[str[i]]) {
                        find = true;
                        ++croak[j];
                        if (croak[j] == 6) {
                            croak.erase(croak.begin() + j);
                            --frogs;
                        }
                        break;
                    }
                }
                if (!find) {
                    ret = -1;
                    break;
                }
            }
        }

        if (!croak.empty() > 0) {
            printf("#%d -1\n", t);
            continue;
        }

        printf("#%d %d\n", t, ret);
    }
}