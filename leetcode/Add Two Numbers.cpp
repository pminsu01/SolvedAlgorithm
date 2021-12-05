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
        
        ListNode* head = new ListNode(); // head 노드 설정
        ListNode* node = head; // ListNode의 head 노드 설정
        int plus = 0; // 10이 넘었을 때 +1의 Flag
        
        while(l1 != nullptr || l2 != nullptr){ // 두개 다 모두 nullptr이 아닐 때 (next값이 존재 할 때 )
            
            int sum = plus;
            
            if(l1 != nullptr) {
                sum += l1 -> val;
            }
            
            if(l2 != nullptr) {
                sum += l2 -> val;
            }
            
            
            if(sum > 9){
                sum = sum % 10;
                plus = 1;
            }
            
            else {
                plus = 0;
            }
            
            ListNode* insert = new ListNode(sum);
            node -> next = insert;
            node = node->next;
            
            l1  = l1 == nullptr ? nullptr : l1->next;
            l2  = l2 == nullptr ? nullptr : l2->next;
            
            if(plus == 1) {
                node -> next = new ListNode(plus); // 10이 넘어가면 그 다음 노드값에 value가 1인 노드를 생성한다.
            }
        
        }
        
        return head->next;
    }
};

/*
해당 코드는 단순 LinkedList 값들을 더하고 다시 LinkedList값으로 넣는 것이다.
단, 입력값 조건으로 The number of nodes in each linked list is in the range [1, 100]이므로 Integer뿐만 아니라 long long값의 범위를 넘어가서 range 오류가 발생한다.
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
*/