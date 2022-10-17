#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

void findMindata(Node *head) {
    Node *minnode=head->next,*p=minnode;
    int mindata=minnode->data;
    while(p->next!=NULL) {
        p=p->next;
        if(p->data<mindata) {
            mindata=p->data;
            minnode=p;
        }
    }
    if(minnode->next!=NULL) {
        if(mindata%2)
            swap(minnode->data,minnode->next->data);
        else{
            p=minnode->next;
            minnode->next=minnode->next->next;
            free(p);
        }
    }
}

int main() {
    return 0;
}