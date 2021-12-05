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
#include<string>

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        
        string l1Num = changeStr(l1);
        string l2Num = changeStr(l2);
       
        cout<<"l1 : " <<(l1Num)<<endl;
        cout<<"l2 : "  <<l2Num<<endl;
        long long nodeSum = stoll(l1Num) + stoll(l2Num);
        string nodeSumStr = reverseStr(to_string(nodeSum));
        ListNode* resultNode = makeNode(nodeSumStr);
     
        return resultNode;
    }
    
    
    
    string changeStr(ListNode* node) {
        
    // 2, Node(4) -> 4, Node(3) -> 3, NULL
        string changestr ="";
       
        while(true){
            
             changestr += to_string(node->val);   
             if(node->next == NULL) break;
             node = node -> next;
        }
   
     
        return reverseStr(changestr);        
    }
    
    
    ListNode* makeNode(string numStr) {
        
        // 708넘어옴
        ListNode* node = new ListNode();
        ListNode* resultNode = new ListNode();
        node = resultNode;
        
        for(int i=0; i< numStr.size(); i++) {
            if(i ==0) {
               resultNode -> val = numStr[i] -'0';
               continue;
            }
           node -> next = new ListNode(numStr[i]-'0');
           node = node -> next; 
        }
      
        return resultNode;
        
    }
    
    string reverseStr(string str){
        
        string reverseStr ="";
           for(long i = str.size()-1; i>=0; i--) {
            reverseStr += str[i];
        }
        cout<<"reverse : " << reverseStr<<endl;
        return reverseStr;
    } 
};