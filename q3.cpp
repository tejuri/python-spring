#include<iostream>
using namespace std;

class Evaluation {
public:

int st[50];
int top;
char str[50];
Evaluation() {
top = -1;

}


void push(int item) {
top++;
st[top] = item;

}


int pop() {

int item = st[top];
top--;
return item;

}
int operation(int a,int b,char opr) {

switch(opr) {

case '+':return a+b;
case '-':return a-b;
case '*':return a*b;
case '/':return a/b;
default: return 0;

}

}

int calculatePostfix();
};
int Evaluation::calculatePostfix() {

int index = 0;
while(str[index]!='#') {

if(isdigit(str[index])) {

push(str[index]-'0');

}
else {

int x = pop();
int y = pop();
int result = operation(x,y,str[index]);
push(result);

}
index++;

}
return pop();

}
int main() {

Evaluation eval;
cout << "Enter the postfix: ";
cin >> eval.str;
int result = eval.calculatePostfix();
cout << "the result is " << result;

return 0;
}