#include <bits/stdc++.h>
using namespace std;
const int MAXSIZE = 100;
typedef struct StackNode{
    int data;
    struct StackNode *next;
} LinkStack;

LinkStack *InitStack(){
    LinkStack *S = NULL;
    return S;
}

bool EmptyStack(LinkStack *S){
    return S == NULL;
}

LinkStack *Push(LinkStack *S, int x){
    LinkStack *p;
    p = (LinkStack *)malloc(sizeof(LinkStack));
    p->data = x;
    p->next = S;
    S = p;
    return S;
}

LinkStack *Pop(LinkStack *S, int *x){
    LinkStack *p;
    if (EmptyStack(S)){
        cout << "\t栈空，不能出栈！" << endl;
        return NULL;
    }
    *x = S->data;
    p = S;
    S = S->next;
    free(p);
    return S;
}

int GetTop(LinkStack *S, int *x){
    if (EmptyStack(S)){
        cout << "\t栈空！" << endl;
        return -1;
    }
    *x = S->data;
    return 0;
}

void ShowStack(LinkStack *S){
    LinkStack *p = S;
    if (p == NULL)
        cout << "\t栈空！" << endl;
    else{
        cout << "从栈顶起个元素为：";
        while (p != NULL){
            cout << p->data << ' ';
            p = p->next;
        }
    }
}

void D2B(LinkStack *S, int x){
    while (x){
        S = Push(S, x % 2);
        x /= 2;
    }
    cout << "转换后的二进制数为： ";
    while (!EmptyStack(S)){
        S = Pop(S, &x);
        cout << x;
    }
}

void trans(char *exp, char *postexp){
    struct{
        char data[MAXSIZE];
        int top;
    } op;
    int i = 0;
    op.top = -1;
    while (*exp != '#'){
        switch (*exp){
        case '(':
            op.data[++op.top] = *(exp++);
            break;
        case ')':
            while (op.data[op.top] != '(')
                postexp[i++] = op.data[op.top--];
            op.top--;
            exp++;
            break;
        case '+':
        case '-':
            while (op.top != -1 && op.data[op.top] != '(')
                postexp[i++] = op.data[op.top--];
            op.data[++op.top] = *(exp++);
            break;
        case '*':
        case '/':
            while (op.data[op.top] == '*' || op.data[op.top] == '/')
                postexp[i++] = op.data[op.top--];
            op.data[++op.top] = *(exp++);
            break;
        case ' ':
            break;
        default:
            while (*exp >= '0' && *exp <= '9')
                postexp[i++] = *(exp++);
            postexp[i++] = '#';
        }
    }
    while (op.top != -1)
        postexp[i++] = op.data[op.top--];
    postexp[i] = '\0';
}

double compvalue(char *postexp){
    struct{
        double data[MAXSIZE];
        int top;
    } st;
    double a, b, c, d;
    st.top = -1;
    while (*postexp != '\0'){
        switch (*postexp){
        case '+':
            a = st.data[st.top--];
            b = st.data[st.top--];
            st.data[++st.top] = a + b;
            break;
        case '-':
            a = st.data[st.top--];
            b = st.data[st.top--];
            st.data[++st.top] = b - a;
            break;
        case '*':
            a = st.data[st.top--];
            b = st.data[st.top--];
            st.data[++st.top] = a * b;
            break;
        case '/':
            a = st.data[st.top--];
            b = st.data[st.top--];
            if (a)
                st.data[++st.top] = b / a;
            else
                cout << "\n\t除零错误！\n";
            break;
        default:
            d = 0;
            while (*postexp >= '0' && *postexp <= '9')
                d = 10 * d + *(postexp++) - '0';
            st.data[++st.top] = d;
            break;
        }
        postexp++;
    }
    return st.data[st.top];
}

int printMenu(){
    printf("\n               栈子系统");
    printf("\n========================================");
    printf("\n|            1--初始化栈                |");
    printf("\n|            2--入栈操作                |");
    printf("\n|            3--出栈操作                |");
    printf("\n|            4--求栈顶元素              |");
    printf("\n|            5--显示栈中元素            |");
    printf("\n|            6--十、二进制数转换        |");
    printf("\n|            7--表达式转换并求值        |");
    printf("\n|            0--返回                    |");
    printf("\n========================================");
    printf("\n请输入菜单号(0-7): ");
    return 0;
}

int main(){
    int i,n;
    LinkStack *S;
    int x;
    char c1='y',c2,a;
    char exp[MAXSIZE],postexp[MAXSIZE];
    while(c1=='y'||c1=='Y'){
        printMenu();
        cin>>c2;
        getchar();
        switch(c2){
        case '1':
            S=InitStack();
            cout<<"栈的初始化完成！";
            break;
        case '2':
            cout<<"请输入要入栈的元素个数：";
            cin>>n;
            cout<<"请输入"<<n<<"个整数进行入栈：";
            for(i=0;i<n;i++){
                cin>>x;
                S=Push(S,x);
            }
            cout<<"入栈成功";
            break;
        case '3':
            cout<<"请输入要出栈的元素个数：";
            cin>>n;
            cout<<"出栈的元素为：";
            for(i=0;i<n;i++){
                S=Pop(S,&x);
                if(S!=NULL)printf("%5d",x);
            }
            //cout<<"出栈成功";
            break;
        case '4':
            if(GetTop(S,&x)==0)
                cout<<"当前栈顶元素为："<<x;
            break;
        case '5':
            ShowStack(S);
            break;
        case '6':
            S=InitStack();
            cout<<"请输入十进制整数：";
            cin>>x;
            D2B(S,x);
            break;
        case '7':
            cout<<"请输入算数表达式：";
            cin>>exp;
            trans(exp,postexp);
            cout<<"则该表达式的中缀表达式为："<<exp<<endl;
            cout<<"则转换之后的后缀表达式为："<<postexp<<endl;
            cout<<"表达式的值为："<<compvalue(postexp)<<endl;
            break;
        case '0': c1='n';break;
        default: cout<<"输入有误（0~5）：";
        }
        if(c2!='0'){
            cout<<"\n按回车继续，按任意键返回主菜单！"<<endl;
            a=getchar();
            if(a!='\xA') getchar(),c1='n';
        }
    }
    return 0;
}