class Solution {
public:
    int minimumRefill(vector<int>& plants, int capA, int capB) {
        int currA = capA;
        int currB = capB;
        int n = plants.size();
        int refill = 0;
        
        for(int i=0;i<=(n-1)/2;i++)
        {
            int j = n-i-1;
            if(i == j)
            {
                //cout<<currA<<" "<<currB<<endl;
                if(currA<currB)
                {
                   if(currB<plants[j])
                    {
                        ++refill;
                        currB = capB;
                    }
                    currB -= plants[j];
                }
                else 
                {
                    //Alice
                   if(currA<plants[i])
                    {
                        ++refill;
                        currA = capA;
                    }
                    currA -= plants[i];
                }
            }
            else
            {
                //Alice
                if(currA<plants[i])
                {
                    ++refill;
                    currA = capA;
                }
                currA -= plants[i];
                
                //bob
                if(currB<plants[j])
                {
                    ++refill;
                    currB = capB;
                }
                currB -= plants[j];
               
            }
            
        }
       
        
        return refill;
    }
};