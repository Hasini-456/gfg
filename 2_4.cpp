/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution {
  public:
    int intersectPoint(Node* head1, Node* head2) {
        // Your Code Here
        Node* a = head1;
        Node* b = head2;
        
        while(a != b){
            a = a? a->next : head2;
            b = b? b->next: head1;
        }
        return a->data;
    }
};
