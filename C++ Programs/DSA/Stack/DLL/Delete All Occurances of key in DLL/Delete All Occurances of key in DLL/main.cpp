#include<iostream>

using namespace std;

class Node{
public:
    int data;
    Node* prev;
    Node* next;
    
    Node(){
        data = 0;
        prev = NULL;
        next = NULL;
    }
    
    Node(int x){
        data = x;
        prev = NULL;
        next = NULL;
    }
};

class DLL{
public:
    Node* constructDLL(vector<int>& arr, int n);
    Node* DeleteOccurancesOfX(Node* head, int x);
    Node* findTail(Node* head);
    vector<pair<int, int>> findPairswithGivenSum(Node* head, int target);
    Node* removeDuplicates(Node* head);
    void printList(Node* head);
};

Node* DLL::constructDLL(vector<int> &arr,int n){
    Node* head = new Node(arr[0]);
    Node* p = head;
    for(int i=1;i<n;i++){
        Node* temp = new Node(arr[i]);
        p->next=temp;
        temp->prev=p;
        p=p->next;
    }
    return head;
}

Node* DLL::DeleteOccurancesOfX(Node *head, int x){
    /*
     1. check if head exists.
     2. Check if head and temp are same(i.e., the first element), move the head to next element, initialise 2 pointers, prevNode & nextNode point the current head to null.
     3. Delete the Node with value x;
     4. If not found, traverse the linkedList till the element is found.
     5. Check if prevNode and nextNode exists. If yes point nextNode->prev=temp->prev and prevNode->next=nextNode;
     6. If not prevNode/nextNode not found point it to null.
     7. Free temp and move temp to nextNode.
     8. return the DLL.
     */
    Node* temp = head;
    while(temp!=NULL){
        if(temp->data == x){
            if(temp == head){
                head=temp->next;
            }
            Node* prevNode = temp->prev;
            Node* nextNode = temp->next;
            if(prevNode!=NULL) prevNode->next = nextNode;
            if(nextNode!=NULL) nextNode->prev = prevNode;
            free(temp);
            temp=nextNode;
        }
        else{
            temp=temp->next;
        }
    }
    return head;
}

Node* DLL::findTail(Node *head){
    Node* tail = head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    return tail;
}

vector<pair<int, int>> DLL::findPairswithGivenSum(Node *head, int target){
    /*
     1. Two pointer approach like arrays.
     */
    vector<pair<int, int>> ans;
    Node* left=head;
    Node* right=findTail(head);
    while(left->data<right->data){
        if(left->data+right->data==target){
            ans.push_back({left->data, right->data});
            left=left->next;
            right=right->prev;
        }
        else if(left->data+right->data>target) right=right->prev;
        else left=left->next;
    }
    return ans;
}

Node* DLL::removeDuplicates(Node *head){
    Node* temp = head;
    while(temp!=NULL && temp->next!=NULL){
        Node* nextNode = temp->next;
        while(nextNode!=NULL && temp->data==nextNode->data){
            Node* duplicate = nextNode;
            nextNode=nextNode->next;
            free(duplicate);
        }
        temp->next=nextNode;
        if(nextNode){
            nextNode->prev=temp;
        }
        temp=temp->next;
    }
    
    return head;
}

void DLL::printList(Node *head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<< "<-->";
        temp=temp->next;
    }
}


int main(){
    vector<int> arr = {1,1,1,2,2,3,4,7,7};
    int n = arr.size();
    
    DLL obj;
    Node* DL = obj.constructDLL(arr, n);
    //DL = obj.DeleteOccurancesOfX(DL, 2);
    obj.printList(DL);
    cout << endl;
    /*vector<pair<int, int>> ans = obj.findPairswithGivenSum(DL, 5);
    for(pair<int, int> num:ans){
        cout<<num.first<<", "<<num.second << endl;
    }*/
    DL = obj.removeDuplicates(DL);
    obj.printList(DL);
    
    return 0;
    
}
