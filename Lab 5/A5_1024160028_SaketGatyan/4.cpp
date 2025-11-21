#include<iostream>
#include<vector>
#include"2.h"

class Solution{
 public:
    ListNode* reverseList(ListNode *head){
    vector<int>ans;
    ListNode *curr = head;
    while(curr){
        ans.push_back(curr->val);
        curr = curr->next;
    }
    curr = head;
    while(curr){
        for(int i=ans.size()-1;i>=0;i--){
            curr->val = ans[i];
            curr = curr->next;
        }
         
    }
    curr = head;
    return curr;
 }
 };
