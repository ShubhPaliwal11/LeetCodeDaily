// optimum : 
class Solution {
public:
    int findPoisonedDuration(vector<int>& t, int d) {
        int answer = 0 ;
        for(int i = 0 ; i < t.size() ;){
            int start = t[i];
            int end  = t[i] + d-1;
            i++;
            while(i<t.size() && end>=t[i]){
                end = t[i] + d - 1;
                i++;
            }
            answer += (end-start+1);
        }
        return answer;
    } 
};

// brute:
class Solution {
public:
    int findPoisonedDuration(vector<int>& t, int d) {
        vector<int>hash(1e7+10,0);
        int answer = 0 ;
        for(int i = 0 ; i < t.size() ; i++){
            int stun  = t[i] + d-1;
            for(int j = t[i] ; j <= stun ; j++){
                hash[j]++;
            }
        }
        for(int i = 0 ; i < hash.size() ; i++){
            if(hash[i]!=0){
                answer++;
            }
        }
        return answer;
    } 
};

