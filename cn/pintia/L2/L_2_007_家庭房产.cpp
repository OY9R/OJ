#include <bits/stdc++.h>
#define MAX 10000
using namespace std;
class Record {
  public:
    int minPeopleId;
    int peopleSum;
    double avgHourse;
    double avgArea;

  public:
    Record() {
        this->minPeopleId= MAX;
        this->peopleSum= 0;
        this->avgArea= 0;
        this->avgHourse= 0;
    }
};
class People {
  public:
    int id;
    int mother;
    int father;
    vector<int> sonOrdaughter;
    int sonOrdaughterNum;
    int hourse;
    double area;

  public:
    People() {
        this->id= -1;
        this->mother= -1;
        this->father= -1;
        this->sonOrdaughterNum= 0;
        this->hourse= 0;
        this->area= 0;
    }
    People(int id, int mother, int father, vector<int> sonOrdaughter, int sonOrdaughterNum, int hourse, double area) {
        this->id= id;
        this->mother= mother;
        this->father= father;
        this->sonOrdaughter= sonOrdaughter;
        this->sonOrdaughterNum= sonOrdaughterNum;
        this->hourse= hourse;
        this->area= area;
    }
};
People *peoples[MAX];
bool isVisit[MAX];
Record *record[MAX];
int recordIndex= -1;
void visitPeople(People *people);
bool dealRecord(Record *front, Record *behind);
int main() {
    int n, i, id, mother, father, k, j, temp, hourse;
    float area;
    //	获取数据
    scanf("%d", &n);
    int *read= new int[n];
    for(i= 0; i < n; i++) {
        scanf("%d %d %d %d", &id, &mother, &father, &k);
        read[i]= id;
        vector<int> sonOrdaughter;
        for(j= 0; j < k; j++) {
            scanf("%d", &temp);
            sonOrdaughter.push_back(temp);
        }
        scanf("%d %f", &hourse, &area);
        peoples[id]= new People(id, mother, father, sonOrdaughter, k, hourse, area);
    }
    //	建立关系
    for(i= 0; i < n; i++) {
        mother= peoples[read[i]]->mother;
        if(mother != -1) {
            if(peoples[mother] == NULL) {
                peoples[mother]= new People();
                peoples[mother]->sonOrdaughter.push_back(read[i]);
                peoples[mother]->id= mother;
                peoples[mother]->sonOrdaughterNum= 1;
            } else {
                vector<int> &sonOrdaughter= peoples[mother]->sonOrdaughter;
                vector<int>::iterator it= find(sonOrdaughter.begin(), sonOrdaughter.end(), read[i]);
                if(it == sonOrdaughter.end()) {
                    sonOrdaughter.push_back(read[i]);
                    peoples[mother]->sonOrdaughterNum= peoples[mother]->sonOrdaughterNum + 1;
                }
            }
        }
        father= peoples[read[i]]->father;
        if(father != -1) {
            if(peoples[father] == NULL) {
                peoples[father]= new People();
                peoples[father]->sonOrdaughter.push_back(read[i]);
                peoples[father]->id= father;
                peoples[father]->sonOrdaughterNum= 1;
            } else {
                vector<int> &sonOrdaughter= peoples[father]->sonOrdaughter;
                vector<int>::iterator it= find(sonOrdaughter.begin(), sonOrdaughter.end(), read[i]);
                if(it == sonOrdaughter.end()) {
                    sonOrdaughter.push_back(read[i]);
                    peoples[father]->sonOrdaughterNum= peoples[father]->sonOrdaughterNum + 1;
                }
            }
        }
        vector<int> &sonOrdaughter= peoples[read[i]]->sonOrdaughter;
        int &sonOrdaughterSum= peoples[read[i]]->sonOrdaughterNum;
        for(j= 0; j < sonOrdaughterSum; j++) {
            if(peoples[sonOrdaughter[j]] == NULL) {
                peoples[sonOrdaughter[j]]= new People();
                peoples[sonOrdaughter[j]]->id= sonOrdaughter[j];
                peoples[sonOrdaughter[j]]->mother= read[i];
            } else if(peoples[sonOrdaughter[j]]->father == -1) {
                peoples[sonOrdaughter[j]]->father= read[i];
            }
        }
    }
    //	访问家族人员
    for(i= 0; i < n; i++) {
        if(isVisit[read[i]] == false) {
            recordIndex++;
            record[recordIndex]= new Record();
            visitPeople(peoples[read[i]]);
            record[recordIndex]->avgArea/= record[recordIndex]->peopleSum;
            record[recordIndex]->avgHourse/= record[recordIndex]->peopleSum;
        }
    }
    recordIndex++;
    //	整理记录
    sort(record, record + recordIndex, dealRecord);
    //	提交记录
    printf("%d\n", recordIndex);
    for(i= 0; i < recordIndex; i++)
        printf("%04d %d %.3f %.3f\n", record[i]->minPeopleId, record[i]->peopleSum, record[i]->avgHourse, record[i]->avgArea);
    return 0;
}
void visitPeople(People *people) {
    isVisit[people->id]= true;
    if(record[recordIndex]->minPeopleId > people->id)
        record[recordIndex]->minPeopleId= people->id;
    record[recordIndex]->peopleSum+= 1;
    record[recordIndex]->avgArea+= people->area;
    record[recordIndex]->avgHourse+= people->hourse;
    //	访问母亲
    if(people->mother != -1 && isVisit[people->mother] == false)
        visitPeople(peoples[people->mother]);
    //	访问父亲
    if(people->father != -1 && isVisit[people->father] == false)
        visitPeople(peoples[people->father]);
    //	访问儿子或女儿
    vector<int> &sonOrdaughter= people->sonOrdaughter;
    int i;
    for(i= 0; i < people->sonOrdaughterNum; i++)
        if(isVisit[sonOrdaughter[i]] == false)
            visitPeople(peoples[sonOrdaughter[i]]);
}
bool dealRecord(Record *front, Record *behind) {
    if(front->avgArea > behind->avgArea)
        return true;
    else if(front->avgArea == behind->avgArea && front->minPeopleId < behind->minPeopleId)
        return true;
    else
        return false;
}