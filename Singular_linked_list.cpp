#include<iostream>
#include<vector>
using namespace std; 

struct Node{
    int data ; 
    Node* next ; 


    Node(int a){
        data = a; 
        next = nullptr ; 
    }
}; 
// 1-> 2 -> 3 -> 4 -> 5 - > 6 

Node* convertoll(vector<int> &a){
    Node* head = new Node(a[0]); 
    Node* move = head ; 
    for(int  i = 1 ; i < a.size(); i++){
        Node* temp = new Node(a[i]); 
        move->next = temp ; 
        move = temp ; 
    }
    return head ; 
}

void deleteelement(Node* head , vector<int> a , int k ){
    Node* temp = head; 
    Node* prev = nullptr;

    if(temp->next == nullptr){
        delete temp ; 
        cout<<"Empty list \n"; 
        return; 
    }
    while(temp != nullptr){
        prev = temp ;
        temp= temp->next; 
        if(temp->data == k){
            prev->next= prev->next->next; 
            delete temp ; 
            break ;
        }
    } 

}
//  1-> 2 -> 3 -> 4 -> 5 - > 6 
void removehead(Node*& head , vector<int> aa ){
    Node* temp = head ; 
    head = head->next; 
    delete temp ; 
}

void printlinekdlist(Node* head){
    if(head == nullptr){
        cout<<"List is empty : "; 
        return ; 
    }
    Node* temp = head; 
    while(temp != nullptr){
        cout<<temp->data<<"->"; 
        temp = temp->next; 
    }

}
// 1-> 2 -> 3 -> 4 -> 5 -> 6 
void insertioninllatk(Node*& head , vector<int> a , int key, int data2 ){
    Node* newnode = new Node(data2); 
    if(key==0){
        
        newnode->next = head; 
        head = newnode;
        return ; 
    }
    Node* temp = head ; 
    for(int i = 0; i < key-1 ; i++){
        temp= temp->next; 
    }
    newnode->next = temp->next; 
    temp->next = newnode; 


}

void insertatail(Node*& head , vector<int> a , int data2){

    if (head == nullptr) {
        cout<<"list is empty : "; 
        return ; 
    }
    Node* newnode = new Node(data2); 
    Node* temp = head ; 
    while(temp->next != nullptr){
        temp = temp->next; 
    }
    temp->next = newnode; 
    newnode->next = nullptr; 
    


}

int main(){
    vector<int> aa = {4,2,3,4,5};
    int k = 0;
    Node* head = convertoll(aa); 
    printlinekdlist(head); 
    cout<<"\n"<<"\n"; 
    insertioninllatk(head , aa , k ,10);
    printlinekdlist(head); 
    // removehead(head , aa );
    insertatail(head , aa , 7);
    cout<<"\n"; 
    printlinekdlist(head); 
}