/**
 * Author: minhnhatnoe
 * Date: 2022-11-12
 * License: CC0
 * Source: minhnhatnoe and tuanlinh123
 * Description: Suffix Automaton, supporting multiple strings.
 * The beginning iterator is $0$. Make calls to itmove to progress iterator.
 * Time: O(n)
 * Status: stress-tested
 */

const int ALPH = 26;
struct suffix_automaton{
    struct node{
        int len, link = -1;
        array<int, ALPH> next;
        node(int len): len(len) {next.fill(-1);}
        node(int len, int link, array<int, ALPH> &next): len(len), link(link), next(next) {}
    };
    vector<node> g = {0};
    int make(int p, char c, node &&a){ // Make new node
        for (int q = g[p].next[c]; p != -1 && g[p].next[c] == q; p = g[p].link)
            g[p].next[c] = g.size();
        g.emplace_back(move(a));
        return p;
    }
    int sttrans(int p, char c){ // Strict transition
        if (p == -1) return 0;
        int q = g[p].next[c];
        if (g[p].len + 1 == g[q].len) return q;
        make(p, c, {g[p].len+1, g[q].link, g[q].next});
        return g[q].link = g.size()-1;
    }
    int itmove(int last, char c){ // Progress iterator
        if (g[last].next[c] != -1){
            sttrans(last, c);
            return g[last].next[c];
        }
        int p = make(last, c, {g[last].len+1});
        int cr = g.size()-1; g[cr].link = sttrans(p, c);
        return g[last].next[c];
    }
};
