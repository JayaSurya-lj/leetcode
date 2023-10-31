/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head==NULL||(head->next==NULL && head->child==NULL)) return head;
        Node* temp = head;
        Node* dummy = new Node(100);
        Node* td = dummy;
        while(temp!=NULL)
        {
            td->next = temp;
            td = td->next;
            if(temp!= NULL && temp->child!=NULL)
            {
                temp->child = flatten(temp->child);
                Node* t1 = temp->child;
                while(t1->next!=NULL) t1 = t1->next;
                t1->next = temp->next;
                if(temp->next!=NULL)
                temp->next->prev = t1;
                td->next = temp->child;
                temp->child->prev = td;
                temp->child = NULL;
                temp = t1->next;
                td = t1;
                continue;
            }
            temp = temp->next;
        }
        return dummy->next;
        
    }
};