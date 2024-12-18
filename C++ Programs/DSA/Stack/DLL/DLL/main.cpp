#include<iostream>

using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;
    
    Node(){
        prev = NULL;
        data = 0;
        next = NULL;
    }
    
    Node(int x){
        prev = NULL;
        data = x;
        next = NULL;
    }
};

class DoublyLinkedList{
public:
    Node* constructDLL(vector<int>& arr, int n){
        /*
         1. Create a new node and assign the first value of arr to the head; when the constructor is called, prev and next are set to NULL by default;
         2. Create a temporary pointer which points on head of LL;
         3. run a for loop till n; create a new node and the store the value in the node; point temp->next = current Node; point currentNode->prev = temp; move the temp pointer on currentNode;
         */
        Node* head = new Node(arr[0]);
        Node* p = head;
        for(int i=1;i<n;i++){
            Node* temp = new Node(arr[i]);
            p->next = temp;
            temp->prev = p;
            p=p->next;
        }
        return head;
    }
    
    int countLL(Node* head){
        if(head==NULL) return 0;
        Node* temp = head;
        int count = 0;
        while(temp!=NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }
    
    Node* InsertNode(Node* head, int pos, int data){
        /*
         1. Create a newNode with value (data).
         2. Find the length of LL and check where the position at which newNode needs to be inserted.
         3. Traverse the temp pointer till it reaches the prev position of pos.
         4. Change the links; return the linkedlist.
         */
        
        Node* newNode = new Node(data);
        if(head==NULL) return newNode;
        Node* temp = head;
        
        int i=0;
        while(temp){
            if(i==pos){
                newNode->next=temp->next;
                if(temp->next){
                    temp->next->prev=newNode;
                }
                temp->next=newNode;
                newNode->prev=temp;
            }
            i++;
            temp=temp->next;
        }
        return head;
    }
    
    Node* deleteNode(Node* head, int pos){
        /*
         1. Traverse till the position (1 based-indexing) assuming there exists a LL; if pos=0 then return LL the way it is;
         2. Copy the element at the position in a variable;
         3. Check if the linkedlist exists before and after the position; if it does change the neccessary links or point the next element to null;
         4. Delete that node;
         */
        Node* temp=head;
        int i=1;
        if(pos==0) return head;
        
        while(i!=pos){
            temp=temp->next;
            i++;
        }
        if(pos==1){
            head->next->prev = NULL;
            head=head->next;
        }
        if(temp->prev!=NULL){
            temp->prev->next = temp->next;
        }
        if(temp->next!=NULL){
            temp->next->prev = temp->prev;
        }
        
        return head;
    }
    
    Node* reverse(Node* head){
        /*
         1. Check is the linkedlist exists if yes also check if the next element exists. if no return it as it is.
         2. Create 3 pointers; 1 pointing on head; 1 on NULL; to change the links
         3. while traversing, change the links; curr->prev = curr->next, curr->next = temp;
         4. Move the pointers; temp = curr, curr = curr->prev;
         */
        if(head==NULL || head->next==NULL) return head;
        Node* curr = head;
        Node* temp = NULL;
        while(curr!=NULL){
            temp = curr->prev;
            curr->prev=curr->next;
            curr->next=temp;
            curr=curr->prev;
        }
        if(temp!=NULL) head = temp->prev;
        return head;
    }
    
    void printList(Node* head){
        Node* p = head;
        while(p){
            cout << p->data << " ";
            p=p->next;
        }
    }
};

int main(){
    vector<int> arr = {1,2,3,4,5};
    int n = arr.size();
    
    DoublyLinkedList obj;
    Node* DLL = obj.constructDLL(arr, n);
    //DLL = obj.reverse(DLL);
    DLL = obj.InsertNode(DLL, 3, 10);
    DLL = obj.deleteNode(DLL, 3);
    obj.printList(DLL);
    cout<<endl;
    cout << "Length of LL: " << obj.countLL(DLL) << endl;
    return 0;
}
