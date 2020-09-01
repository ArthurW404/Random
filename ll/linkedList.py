class LinkedList:
    def __init__(self, val, next_node=None):
        self.val = val
        self.next = next_node
    
    def print (self):
        if self is None:
            return

        if self.next is not None:
            print(self.val, "->", end=" ")
            self.next.print()
        else:
            print(self.val)
    
    def insert_end (self, val):
        if self.next is None:
            self.next = LinkedList(val,None)
        else:
            self.next.insert_end(val)

if __name__ == "__main__":
    head = LinkedList(5)
    head.insert_end("Wot")
    head.insert_end(8)
    for i in range(0,10):
        head.insert_end(i)
    head.print()