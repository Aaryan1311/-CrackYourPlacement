/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int s1 = 0, s2 = 0;
        while(temp1 != nullptr){
            temp1 = temp1->next;
            s1++;
        }
        while(temp2 != nullptr){
            temp2 = temp2->next;
            s2++;
        }
        ListNode* ans = new ListNode();
        ListNode* x = ans;
        if(s1 == s2){
            int carry = 0;
            while(s1 > 0 || carry == 1){
                if(s1 == 0){
                    ans->next = new ListNode(1);
                    ans = ans->next;
                    carry = 0;
                }
                else{
                    int val = l1->val + l2->val + carry;
                    if(val <= 9){
                        ans->next = new ListNode(val);
                        ans = ans->next;
                        carry = 0;
                    }
                    else{
                        carry = 1;
                        val -= 10;
                        ans->next = new ListNode(val);
                        ans = ans->next;
                    }
                    l1 = l1->next;
                    l2 = l2->next;
                    s1--;
                }
            }
            return x->next;
        }
        else{
            int carry = 0;
            if(s1 > s2){
                ListNode* t = l1;
                l1 = l2;
                l2 = t;
                int tt = s1;
                s1 =  s2;
                s2 = tt;
            }
            while(s1 > 0){
                int val = l1->val + l2->val + carry;
                if(val <= 9){
                    ans->next = new ListNode(val);
                    ans = ans->next;
                    carry = 0;
                }
                else{
                    carry = 1;
                    val -= 10;
                    ans->next = new ListNode(val);
                    ans = ans->next;
                }
                l1 = l1->next;
                l2 = l2->next;
                s1--;
                s2--;
            }
            while(s2 > 0 || carry == 1){
                if(s2 == 0){
                    ans->next = new ListNode(1);
                    ans = ans->next;
                    carry = 0;
                }
                else{
                    int val = l2->val + carry;
                    if(val <= 9){
                        ans->next = new ListNode(val);
                        ans = ans->next;
                        carry = 0;
                    }
                    else{
                        carry = 1;
                        val -= 10;
                        ans->next = new ListNode(val);
                        ans = ans->next;
                    }
                    l2 = l2->next;
                    s2--;
                }
            }
            return x->next;
        }

    }
};