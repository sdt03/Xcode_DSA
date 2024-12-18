#include<iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node* bottom;
    
    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }
    
};
