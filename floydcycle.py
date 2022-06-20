class Node:
	def __init__(self, d):
		self.data = d
		self.next = None

head = None

def detectCycle(head):
	slowPointer = head
	fastPointer = head

	while (slowPointer != None and fastPointer != None and fastPointer.next != None):
		slowPointer = slowPointer.next
		fastPointer = fastPointer.next.next
		if (slowPointer == fastPointer):
			return 1

	return 0

head = Node(12)
head.next = Node(23)
head.next.next = Node(13)
head.next.next.next = Node(36)
head.next.next.next.next = Node(44)


temp = head
while (temp.next != None):
	temp = temp.next

temp.next = head

if (detectCycle(head)):
	print("Cycle exists in the Linked List")
else:
	print("Cycle does not exists in the Linked List")