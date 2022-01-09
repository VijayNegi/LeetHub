class Solution {
public:
    bool isRobotBounded(string instructions) {
        
        int s[2] = {0};
        
        int d = 0;
        
        function<void(int*,int)> makemove = [](int* s,int d)
        {
            switch(d)
            {
                case 0: 
                    s[1]++;
                    break;
                case 1:
                    s[0]--;
                    break;
                case 2:
                    s[1]--;
                    break;
                case 3:
                    s[0]++;
                    break;
            }
        };
        
         function<int(int,int)> changedir = [](int d,int l)
         {
             if(l)
                 return (++d)%4;
             return (d+3)%4;
         };
        
        int k=4;
        
        while(k--)
        {
        
            for(auto c: instructions)
            {
                if(c=='G')
                    makemove(s,d);
                else
                    d = changedir(d,c=='L');
            }
            
            if((s[0] == 0 && s[1]==0) )
            return true;
        }
        
        return false;
        
    }
};