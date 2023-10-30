/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        Node* dummy = new Node(100);
        Node* t = dummy;
        while(temp!=NULL)
        {
            Node* node = new Node(temp->val);
            t->next = node;
            temp = temp->next;
            t = t->next;
            
        }
        Node* t1 = head;
        Node* t2 = dummy->next;
        dummy = new Node(100);
        Node* td = dummy;
        while(t1!=NULL && t2!=NULL)
        {
            td->next = t1;
            t1 = t1->next;
            td = td->next;
            td->next = t2;
            t2 = t2->next;
            td = td->next;

        }
        Node* merge = dummy->next;
        t1 = dummy->next;
        while(t1!=NULL)
        {
            t2 = t1->next;
            if(t1->random!=NULL) t2->random = t1->random->next;
            t1 = t1->next->next;
        }

        t1 = merge;
        Node* dummy1 = new Node(100);
        Node* td1 = dummy1;
        Node* dummy2 = new Node(100);
        Node* td2 = dummy2;

        while(t1!=NULL)
        {
            td1->next = t1;
            t1 = t1->next;
            td1 = td1->next;

            td2->next = t1;
            t1 = t1->next;
            td2 = td2->next;


        }
        td1->next = NULL;
        return dummy2->next;
    }
};