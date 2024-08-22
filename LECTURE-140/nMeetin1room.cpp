// N Meeting in one room : given an two array giving starting and ending time of n -meeting . we need to how many maximum number of meeting can be possible happened
// in a single room form these n meeting , return the count and order of meetings

#include <bits/stdc++.h>
using namespace std;
class ds
{
public:
    int start;
    int end;
    int pos;
};

// boolean function for sorting the meeting on basis of ending time
bool comparator(ds a, ds b)
{
    if (a.end < b.end)
    {
        return true;
    }
    else if (a.end > b.end)
        return false;
    else
    {
        if (a.pos < a.end)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
// function for the find the maximum number of meeting to happen
vector<int> maxMeetingOneroom(vector<int> &s, vector<int> &e, int n)
{

    // step1 : intializing the values of n meeting in the data structure and creating the data structure
    ds meeting[n];
    for (int i = 0; i < n; i++)
    {
        meeting[i].start = s[i];
        meeting[i].end = e[i];
        meeting[i].pos = i + 1;
    }

    // step 2  : Sort all the meeting on the basis of the ending time (and )create the data structure
    sort(meeting, meeting + n, comparator);

    // step 3 : Arrangement of meeting in one room
    int limit = meeting[0].end;
    vector<int> ans;
    ans.push_back(meeting[0].pos);

    // now placement of jobs
    for (int i = 1; i < n; i++)
    {
        if (meeting[i].start > limit)
        {
            // means new meeting will be held
            limit = meeting[i].end;
            ans.push_back(meeting[i].pos);
        }
    }

    return ans;
}

// function for printing the order of the meetings
void print(vector<int> a)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main()
{

    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 5, 7, 9, 9};
    int n = start.size();
    vector<int> ans = maxMeetingOneroom(start, end, n);
    print(ans);
    cout<<"The maximum number of meeting that can be happened is :"<<ans.size()<<endl;

    return 0;
}

/*
gfg :
leetcode :
interview bit :
code studio  :

*/