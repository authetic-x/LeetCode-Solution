class Node {
    constructor(val, next) {
        this.val = val;
        this.next = next;
    }
}

function printLinkedList(head) {
    if (head.next) {
        printLinkedList(head.next);
    }
    head.val && console.log(head.val);
}

let head = new Node(1, null);
head.next = new Node(2, null);
head.next.next = new Node(3, null);

printLinkedList(head);