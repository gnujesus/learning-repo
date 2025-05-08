class Node {
  int? value;
  Node? next;

  Node(this.value);
}

class LinkedList{
  Node? head;

  LinkedList(this.head);
}

Node? findElement(Node? head, int? index){
  Node? temp = head?.next;
  int count = 0;

  if(temp == null){
    print("No list given");
    return null;
  }

  while(temp?.next != null){
    if(index == count){
      return temp;
    }

    if(index != null){
      count++;
    }

    temp = temp?.next;
  }

  return temp;
}

void printList(Node? head){
  Node? temp = head;

  if(temp == null){
    print("No list given");
    return;
  }

  while(temp != null){
    print(temp.value);
    temp = temp.next;
  }
}

void addToTail(Node? head, Node newElement){
  Node? tail = findElement(head, null);
  tail?.next = newElement;
}

void addToHead(Node? head, Node newElement){
  newElement.next = head?.next;
  head?.next = newElement;
}

void main(List<String> arguments) {

  // head and next -> null 
  Node head = Node(null);
  Node? temp = Node(null);

  // first node -> null 
  // head -> first
  Node firstNode = Node(1);
  head.next = firstNode;

  // temp = first
  temp = head.next;

  // create second
  Node secondNode = Node(2);

  // temp -> second = first -> second
  temp?.next = secondNode;

  // temp = second
  temp = temp?.next;

  // create third
  Node thirdNode = Node(3);

  // temp -> third = second -> third
  temp?.next = thirdNode;

  // temp = third
  temp = temp?.next;

  // temp -> null = third -> null
  temp?.next = null;

  // new linked list. value = null, head = head
  // head -> first -> second -> third -> null
  LinkedList linkedList = LinkedList(head);

  Node? twenty = Node(20); 
  addToHead(linkedList.head, twenty);

  Node? six = Node(6);
  addToTail(linkedList.head, six);

  printList(linkedList.head);
}
