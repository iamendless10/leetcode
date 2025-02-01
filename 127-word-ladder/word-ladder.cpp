class Solution {
public:
    int ladderLength(string startWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        

        queue<pair<string,int>> q;
        q.push({startWord, 1});
        st.erase(startWord);

        if (st.find(endWord) == st.end()) return 0;

        while(!q.empty()){

            int steps = q.front().second;
            string word = q.front().first;
            q.pop();

            if(word == endWord) return steps;

            

            for(int i = 0 ; i < word.size(); i++){
                char og = word[i];
                for(char ch = 'a'; ch <= 'z' ; ch++){
                    if (ch == og){
                        continue;
                    }
                    
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        q.push({word, steps + 1});
                        st.erase(word);
                    }
                }
                word[i] = og;
            }
        }

        return 0;
    }
};