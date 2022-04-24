using psi = pair<string,int>;
class UndergroundSystem {
    unordered_map<int,psi> tmap;
    unordered_map<string,vector<double>> avg;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        tmap[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string str = tmap[id].first+":"+stationName;
        double time = t - tmap[id].second;
        if(avg[str].size())
        {
            avg[str][0] += time;
            avg[str][1]++;
        }
        else
        {
            avg[str] = {time,1};
        }
        
    }
    
    double getAverageTime(string startStation, string endStation) {
        string str = startStation+":"+endStation;
        double total = avg[str][0];
        return total/avg[str][1];
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */