#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct student {
    ll id;
    int score,finrank,loca,locarank;
};
bool cmp(student a,student b){
    return a.score!=b.score?a.score>b.score:a.id<b.id;
}
int main(){
    int n,m;
    cin>>n;
    vector<student> rank;
    for(int i=1;i<=n;i++){
        cin>>m;
        vector<student> students(m);
        for(int j=0;j<m;j++){
            cin>>students[j].id>>students[j].score;
            students[j].loca=i;
        }
        sort(students.begin(),students.end(),cmp);
        students[0].locarank=1;
        rank.push_back(students[0]);
        for(int j=1;j<m;j++){
            students[j].locarank=students[j].score==students[j-1].score?students[j-1].locarank:j+1;
            rank.push_back(students[j]);
        }
    }
    sort(rank.begin(),rank.end(),cmp);
    rank[0].finrank=1;
    for(int j=1;j<rank.size();j++)
        rank[j].finrank=rank[j].score==rank[j-1].score?rank[j-1].finrank:j+1;
    cout<<rank.size()<<endl;
    for(int i=0;i<rank.size();i++)
        printf("%013lld %d %d %d\n",rank[i].id,rank[i].finrank,rank[i].loca,rank[i].locarank);
    return 0;
}