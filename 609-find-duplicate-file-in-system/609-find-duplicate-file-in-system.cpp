class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<int,string> id2file;
        unordered_map<string,vector<int>> content2id;
        int id=0;
        for(auto& dir: paths) {
            stringstream ss(dir);
            string dirpath;
            getline(ss,dirpath, ' ');
            //cout<<endl<<dirpath<<endl;
            string line;
            while(getline(ss,line, ' ')) {
                auto p = line.find('(');
                string fileName = line.substr(0,p);
                string content = line.substr(p+1,line.size()-p-2);
                //cout<<fileName<<" - "<<content<<endl;
                string fullPath = dirpath+"/"+fileName;
                id2file[id] = fullPath;
                content2id[content].push_back(id);
                ++id;
            }
        }
        vector<vector<string>> result;
        for(auto& [content,v]:content2id) {
            if(v.size()>1){
                vector<string> duplicate;
                for(auto& id:v){
                    duplicate.push_back(id2file[id]);
                }
                result.push_back(duplicate);
            }
        }
        return result;
    }
};