#include<iostream>

using namespace std;

class Solution{
public:
    struct meeting{
        int start;
        int end;
        int pos;
    };
    
    bool static comparator(struct meeting m1, struct meeting m2){
        if(m1.end<m2.end) return true;
        else if(m1.end>m2.end) return false;
        else if(m1.pos>m2.pos) return true;
        return false;
    }
    
    int maxMeetings(int n, int start[], int end[]){
        struct meeting meet[n];
        for(int i=0;i<n;i++){
            meet[i].start = start[i], meet[i].end=end[i], meet[i].pos = i+1;
        }
        
        sort(meet, meet+n, comparator);
        
        vector<int> ans;
        int freeTime = meet[0].end;
        ans.push_back(meet[0].pos);
        int count = 1;
        
        for(int i=1;i<n;i++){
            if(meet[i].start > freeTime){
                freeTime=meet[i].end;
                ans.push_back(meet[i].pos);
                count++;
            }
        }
        return count;
    }
};

int main(){
    int start[] = {1,3,0,5,8,5};
    int end[] = {2,4,6,7,9,9};
    int n = sizeof(start)/sizeof(start[0]);
    
    Solution puss;
    int count = puss.maxMeetings(n, start, end);
    cout << count << endl;
    
}
