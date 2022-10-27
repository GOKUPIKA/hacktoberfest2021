// Question: Rotate List
// Platfrom: Leetcode
// Difficulty: Medium

// **OPTIMIZE APPROACH**
// * Time Complexity: O(n)+O(n-(n%2)) = O(n)
// * Space Complexity: O(1)


class Solution {
public:

    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0){
            return head;
        }
        ListNode* curr=head;
        int len=1;
        while(curr->next){
            len++;
            curr=curr->next;
        }
        curr->next=head;
        k=k%len;
        k=len-k;
        while(k--){
            curr=curr->next;
        }
        head=curr->next;
        curr->next=NULL;
        
        return head;
    }

};


// **EXPLANATION:**
// 1. First we find the count of nodes present in LinkedList, also we find the last node of LinkedList.
// 2. We change the connection of last node to head (temp->next=head); making a cyclic linkedList.
// 3. Then we take the modulus of k%len in case k is greater than count.
// 4. Then we subtract the k from count (k=count-k); to find the position of node which we have to change the connection
// 5. In last we traverse to the kth node and change its connection to NULL while making the its next as an head

// **BRUTE FORCE APPROACH**
// * Time Complexity: O(n*k)
// * Space Complexity: O(1)


class Solution {
public:

    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* temp=head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        for(int i=0;i<(k%count);i++){
            ListNode* nex=head;
            ListNode* prev=NULL;
            while(nex->next!=NULL){
                prev=nex;
                nex=nex->next;
            }
            nex->next=head;
            prev->next=NULL;
            head=nex;
        }
        return head;
    }

};


// **EXPLANATION:**
// We change the connection of last node to head kth times
