/*
class Node {
   public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
} */

class Solution {
  
  public:
    bool detectLoop(Node* head) {
        // code here
        map<Node*,int> mpp;
        Node* temp = head;
        while(temp!=NULL){
            if(mpp.find(temp)!=mpp.end()){
                return true;
            }
            else{
                mpp[temp]++;
            }
            temp = temp->next;
        }
        return false;
    }
};