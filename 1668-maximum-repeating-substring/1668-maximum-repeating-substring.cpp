class Solution {
public:
    int maxRepeating(string sequence, string word) {
        
        int n = word.size();
        int result = 0;
        int curr = 0;
        int pos = sequence.find(word,0);
        while(pos !=string::npos && pos < sequence.size())
        {
            ++curr;
            int newpos = sequence.find(word,pos+n);
            if(newpos != pos+n)
            {
               newpos = sequence.find(word,pos+1);
                result = max(curr,result);
                curr = 0;
            }
            pos = newpos;
        }
        result = max(curr,result);
        return result;
    }
    int maxRepeating1(string sequence, string word) {
        int count=0;
        string temp=word;
        while(sequence.find(temp)!=string::npos)
        {
            count++;
            temp+=word;
        }
        return count;
    }
};