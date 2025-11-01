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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> s;
        for(int i = 0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        ListNode* pre = nullptr;
        ListNode* curr = head;
        ListNode* post = head->next;
        while(curr != nullptr){
            if(s.contains(curr->val)){
                if(pre == nullptr){
                    head = head->next;
                    curr = head;
                }
                else{
                    pre->next = post;
                    curr = curr->next;
                }
            }
            else{
                pre = curr;
                curr = post;
            }
            if(post != nullptr) post = post->next;
        }
        return head;
    }
};