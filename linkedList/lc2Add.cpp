#include <iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode():val(0),next(nullptr){};
    ListNode(int x):val(x),next(nullptr){};
    ListNode(int x,ListNode *next):val(x),next(next){};
};
class Solution0{
    public:
        ListNode* add2Num(ListNode *l1,ListNode *l2){
            int sum=0;
            ListNode dummy(0);
            ListNode *tail=&dummy;
            while(l1||l2||sum){
                sum+=(l1?l1->val:0)+(l2?l2->val:0);
                l1=l1?l1->next:nullptr;
                l2=l2?l2->next:nullptr;
                tail->next=new ListNode(sum%10);
                sum/=10;
                tail=tail->next;
            }
            return dummy.next;
        }
};
void print(ListNode *pListNode){
    ListNode *p;
    for(p=pListNode;p;p=p->next) cout<<p->val<<" ";
    cout<<endl;
}
int main(){
    ListNode l10(2),l20(5);
    ListNode l11(4),l21(6);
    ListNode l12(3),l22(7);
    l10.next=&l11; l11.next=&l12;
    l20.next=&l21; l21.next=&l22;
    Solution0 s0;
    auto ans0=s0.add2Num(&l10,&l20);
    print(ans0);
    return 0;
}
