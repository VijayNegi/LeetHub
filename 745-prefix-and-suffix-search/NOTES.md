// TLE if you save both prefix and suffix in same tree
​
#define TRIE_LEN 26
​
struct Trie {
Trie* child[TRIE_LEN];
set<int> idxs;
Trie() {
fill(begin(child), end(child),nullptr);
}
void insert(string s,int idx) {
Trie* node = this;
for(auto c:s) {
if(!node->child[c-'a'])
node->child[c-'a'] = new Trie();
node = node->child[c-'a'];
node->idxs.insert(idx);
}
}
set<int> search(string s) {
Trie* node = this;
for(auto c:s) {
//cout<<c<<" ";
if(!(node->child[c-'a']))
return set<int>{};
node = node->child[c-'a'];