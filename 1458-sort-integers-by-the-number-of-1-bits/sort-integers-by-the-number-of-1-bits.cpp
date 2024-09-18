class Solution {
public:
 
    static int comp(int a , int b){
        
        int num1 = a , num2 = b;
        int cnt1 = 0, cnt2 = 0;
        while(a){
            cnt1++;
            a = (a&(a-1));
        }

        while(b){
            cnt2++;
            b = (b&(b-1));
        }

  
        if(cnt1 == cnt2){
            return num2 > num1;
        }
       
        else{
            return cnt2 > cnt1;
        }
        
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),comp);

        return arr;
    }
};