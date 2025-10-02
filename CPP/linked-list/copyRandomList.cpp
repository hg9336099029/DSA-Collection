class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head;
        // Step 1: Insert cloned nodes after each original node
        while(temp!=NULL){
            Node* node=new Node(temp->val);
            node->next=temp->next;
            temp->next=node;
            temp=temp->next->next;
        }

        // Step 2: Assign random pointers for cloned nodes
        temp=head;
        while(temp!=NULL){
            if(temp->random!=NULL){
                temp->next->random=temp->random->next; 
            }
            temp=temp->next->next;
        }

        // Step 3: Separate original and cloned lists
        Node* dummyNode = new Node(-1);
        temp=head;
        Node* res=dummyNode;
        while(temp!=NULL){
            res->next=temp->next;
            temp->next=temp->next->next;

            temp=temp->next;
            res=res->next;
        }
        return  dummyNode->next;
    }
};
