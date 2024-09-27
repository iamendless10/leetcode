#include <vector>
#include <utility>
#include <algorithm>

class MyCalendar {
private:
    std::vector<std::pair<int, int>> st;
public:
    MyCalendar() {
       
    }
    
    bool book(int start, int end) {
        for (auto booking : st){
            int l = booking.first;
            int r = booking.second;
          
            if (max(start, l) < min(end, r)) {
                return false; 
            }
        }
        st.push_back({start, end}); 
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
