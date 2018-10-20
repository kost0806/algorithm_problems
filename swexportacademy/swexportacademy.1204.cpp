/*
* https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV13zo1KAAACFAYh
* Kostrian(Minyeong Kim, kost0806)
*/

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct num {
    short s, c;
    inline bool operator< (const num &a) const {
        if (c == a.c)
            return s > a.s;
        else
            return c > a.c;
    }
} num;

int T;
vector<num> s(101);

int main() {
    scanf("%d", &T);
    
    for (int c = 1; c <= T; ++c) {
        int t;
    	scanf("%d", &t);
        
        for (int i = 0; i < 101; ++i) {
        	s[i].s = i;
            s[i].c = 0;
        }
        
        for (int i = 0; i < 1000; ++i) {
            int n;
            scanf("%d", &n);
            ++s[n].c;
        }
        
        sort(s.begin(), s.end());
        printf("#%d %d\n", t, s[0].s);
    }
}