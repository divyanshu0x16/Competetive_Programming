#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        //We use two pointer. If these pointres ever meet, thene there is a cycle. If ever reach null then no cycle
        ListNode* slow = head;
        ListNode* fast = head;

        while (true)
        {
            if( fast == NULL or slow == NULL or slow->next == NULL or fast->next == NULL) break;

            fast = fast -> next -> next;
            slow = slow -> next;

            if( fast == slow ) return true;
        }

        return false;
    }
};


int32_t main() {
    return 0;
}
 