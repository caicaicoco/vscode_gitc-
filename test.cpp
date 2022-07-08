#include<vector>
#include<unordered_map>
#include<iostream>
#include<string> 
#include<algorithm>
#include<numeric>
#include<cmath>
using namespace std;
// @lc code=start
struct Trie{
    unordered_map<char,Trie*> children;
};

    vector<string> split(string &sentence,char ch){
        vector<string> ret;
        string s(sentence);
        int start=0,pos=0,n=s.size();
        while(pos<n){
            while(pos<n&&s[pos]==ch){
                pos++;
            }
            start=pos;
            while(pos<n&&s[pos]!=ch){
                pos++;
            }
            if(start<n){
            ret.emplace_back(s.substr(start,pos-start));
            }
            }
        return ret;
    }
    string findRoot(string &word, Trie *trie) {
        string root;
        Trie *cur = trie;
        for (char &c : word) {
            if (cur->children.count('#')) {
                return root;
            }
            if (!cur->children.count(c)) {
                return word;
            }
            root.push_back(c);
            cur = cur->children[c];
        }
        return root;
    }
int main(){
    vector<string> s={"cat","bat","rat"};
    string s1="the cattle was rattled by the battery";
 Trie *trie = new Trie();
        for (auto &word : s) {
            Trie *cur = trie;
            for (char &c: word) {
                if (!cur->children.count(c)) {
                    cur->children[c] = new Trie();
                }
                cur = cur->children[c];
            }
            cur->children['#'] = new Trie();
        }
    vector<string> a=split(s1,' ');

    for (int i = 0; i < 7; i++)
    {
       cout<<a[i];
    }
    }

    

