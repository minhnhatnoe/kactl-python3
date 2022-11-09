// Palindrome tree.

typedef long long ll;

const int maxn = 3e5+5;

int lnk[maxn], go[maxn][26], len[maxn];
ll dp[maxn];
// suffix link, transition, length

void init(string str){
    len[0]=-1;
    len[1]=0;
    int crr = 1, cnt = 2;
    for(int i = 1; i < str.length(); i++){
        int id = str[i]-'a';
        while(crr && str[i] != str[i-len[crr]-1])crr = lnk[crr];
        if(go[crr][id])crr = go[crr][id];
        else{
            int tmp = lnk[crr];
            while(tmp && str[i] != str[i-len[tmp]-1])tmp = lnk[tmp];
            if(!go[tmp][id])lnk[cnt]=1;
            else lnk[cnt]=go[tmp][id];
            go[crr][id]=cnt;
            len[cnt]=len[crr]+2;
            crr = cnt;
            cnt++;
        }
        dp[crr]++;
    }
}