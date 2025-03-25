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
    Node* temp = head ; 
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

int main(){
    vector<int> aa = {4,2,3,4,5};
    int k = 4;
    Node* head = convertoll(aa); 
    printlinekdlist(head); 
    cout<<"\n"<<"\n"; 
    deleteelement(head , aa , k); 
    printlinekdlist(head); 
}