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
        temp = head;
        t = dummy->next;
        while(temp!=NULL && t!=NULL)
        {
            Node* a = temp->random;
            if(a==NULL)
            {
                t->random = NULL;
                temp = temp->next;
                t = t->next;
                continue;
            }
            Node* a1 = head;
            Node* a2 = dummy->next;
            while(a1!=NULL)
            {
                if(a1==a) break;
                a1 = a1->next;
                a2 = a2->next;
            }

            t->random = a2;

            temp = temp->next;
            t = t->next;
        }
        return dummy->next;

        
    }
};