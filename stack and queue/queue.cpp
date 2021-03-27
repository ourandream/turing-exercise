#include<iostream>

using namespace std;

class queue
{
private:
    int items;
    typedef struct node{
        int item;
        struct node *next;
    }node;
    node *front;
    node *rear;
    queue(const queue &q);
public:
    queue();
    ~queue();
    bool enqueue(int input);
    bool dequeue();
    bool isEmpty(){
        return items==0;
    }
    int howMany(){
        return items;
    }
};

queue::queue()
{   
    front=rear=nullptr;
    items=0;
}

queue::~queue()
{   
    node *temp;
    while(front!=nullptr){
        temp=front;
        front=front->next;
        delete temp;
    }
}

bool queue::enqueue(int input){
    node *add=new node;
    add->item=input;
    add->next=nullptr;
    if(!front){
        front=add;
    }
    rear=add;
    items++;

    return true;
}

bool queue::dequeue(){
    if(!items){
        return false;
    }
    if(items==1){
        items--;
        delete front;
        front=rear=nullptr;
    }
    else{
        node *temp=front;
        front=front->next;
        delete temp;
        items--;
    }
    return true;
}


int main(){
    queue test;
    test.enqueue(10);
    test.enqueue(20);
    test.dequeue();
    cout<<test.howMany()<<endl;

    return 0;
}