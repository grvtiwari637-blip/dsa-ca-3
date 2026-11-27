
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };

        priority_queue<ListNode*,
                       vector<ListNode*>,
                       decltype(cmp)> pq(cmp);

        for (ListNode* node : lists) {
            if (node != NULL)
                pq.push(node);
        }

        ListNode dummy(0);
        ListNode* current = &dummy;

        while (!pq.empty()) {

            ListNode* node = pq.top();
            pq.pop();

            current->next = node;
            current = current->next;

            if (node->next != NULL)
                pq.push(node->next);
        }

        return dummy.next;
    }
};
