#region Task1

//int num1 = 1;
//int num2 = 2;

//Swap(ref num1, ref num2);

//Console.WriteLine(num1);
//Console.WriteLine(num2);
//static void Swap<T>(ref T num1, ref T num2)
//{
//    T num3 = num1;
//    num1 = num2;
//    num2 = num3;
//}



#endregion Task1


#region Task2


//    public class CircularQueue<T>
//{
//    private T[] array;
//    private int capacity;
//    private int front;
//    private int rear;
//    private int count;

//    public CircularQueue(int size)
//    {
//        capacity = size;
//        array = new T[size];
//        front = 0;
//        rear = -1;
//        count = 0;
//    }

//    public bool IsEmpty()
//    {
//        return count == 0;
//    }

//    public bool IsFull()
//    {
//        return count == capacity;
//    }

//    public int Count()
//    {
//        return count;
//    }

//    public void Enqueue(T item)
//    {
//        if (IsFull())
//        {
//            throw new InvalidOperationException("The ring queue is full");
//        }

//        rear = (rear + 1) % capacity;
//        array[rear] = item;
//        count++;
//    }

//    public T Dequeue()
//    {
//        if (IsEmpty())
//        {
//            throw new InvalidOperationException("The ring queue is empty");
//        }

//        T item = array[front];
//        front = (front + 1) % capacity;
//        count--;
//        return item;
//    }

//    public T Peek()
//    {
//        if (IsEmpty())
//        {
//            throw new InvalidOperationException("The ring queue is empty");
//        }
//        return array[front];
//    }
//}

#endregion Task2

#region Task3

//    public class PriorityQueue<T>
//    {
//        public enum Priority
//        {
//            Low,
//            Medium,
//            High
//        }

//        public class PrioritiItem<T>
//        {
//            public T Item { get; }
//            public Priority priority { get; }

//            public PrioritiItem(T item, Priority priority)
//            {
//                Item = item;
//                this.priority = priority;
//            }
//        }

//        private LinkedList<PrioritiItem<T>> PrList = new LinkedList<PrioritiItem<T>>();
//        public MyPriorityQueue() { }
//        ~MyPriorityQueue() { }

//        public void Enqueue(T item, Priority priority)
//        {
//            PrioritiItem<T> newItem = new PrioritiItem<T>(item, priority);

//            if (PrList.Count == 0)
//            {
//                PrList.AddLast(newItem);
//            }
//            else
//            {
//                var node = PrList.First;

//                while (node != null)
//                {
//                    if (newItem.priority > node.Value.priority)
//                    {
//                        PrList.AddBefore(node, newItem);
//                        return;
//                    }

//                    node = node.Next;
//                }

//                PrList.AddLast(newItem);
//            }
//        }
//        public T Dequeue()
//        {
//            if (IsEmpty())
//            {
//                throw new InvalidOperationException("The priority queue is empty");
//            }

//            T item = PrList.First.Value.Item;
//            PrList.RemoveFirst();
//            return item;
//        }
//        public bool IsEmpty()
//        {
//            return PrList.Count == 0;
//        }
//        public int Count()
//        {
//            return PrList.Count;
//        }
//    }


#endregion Task3

#region Task4


//    public class Node<T>
//    {
//        public T Data { get; set; }
//        public Node<T> Next { get; set; }

//        public Node<T> Previous { get; set; }


//        public Node(T data)
//        {
//            Data = data;
//            Next = null;
//            Previous = null;
//        }
//    }

//    public class MyLinkedList<T>
//    {
//        private Node<T> head;
//        private Node<T> tail;
//        private int count;

//        public int Count
//        {
//            get { return count; }
//        }

//        public MyLinkedList()
//        {
//            head = null;
//            tail = null;
//            count = 0;
//        }

//        public void Add(T data)
//        {
//            Node<T> newNode = new Node<T>(data);
//            if (head == null)
//            {
//                head = newNode;
//                tail = newNode;
//            }
//            else
//            {
//                tail.Next = newNode;
//                tail = newNode;
//            }
//            count++;
//        }

//        public bool Remove(T data)
//        {
//            if (head == null)
//                return false;

//            if (head.Data.Equals(data))
//            {
//                head = head.Next;
//                if (head == null)
//                    tail = null;
//                count--;
//                return true;
//            }

//            Node<T> current = head;
//            while (current.Next != null)
//            {
//                if (current.Next.Data.Equals(data))
//                {
//                    if (current.Next == tail)
//                        tail = current;

//                    current.Next = current.Next.Next;
//                    count--;
//                    return true;
//                }
//                current = current.Next;
//            }
//            return false;
//        }


//        public bool Contains(T data)
//        {
//            Node<T> current = head;
//            while (current != null)
//            {
//                if (current.Data.Equals(data))
//                    return true;
//                current = current.Next;
//            }
//            return false;
//        }

//        public void Clear()
//        {
//            head = null;
//            tail = null;
//            count = 0;
//        }

//        public void Print()
//        {
//            Node<T> current = head;
//            while (current != null)
//            {
//                Console.Write(current.Data + " ");
//                current = current.Next;
//            }
//            Console.WriteLine();
//        }
//    }


#endregion Task4

#region Task5

//    public class MyDoubleLinkedList<T>
//    {
//        private Node<T> head;
//        private Node<T> tail;
//        private Node<T> previous;

//        private int count;

//        public int Count
//        {
//            get { return count; }
//        }

//        public MyDoubleLinkedList()
//        {
//            head = null;
//            tail = null;
//            previous = null;
//            count = 0;
//        }

//        public void Add(T data)
//        {
//            Node<T> newNode = new Node<T>(data);
//            if (head == null)
//            {
//                head = newNode;
//                tail = newNode;
//            }
//            else
//            {
//                tail.Next = newNode;
//                newNode.Previous = tail;
//                tail = newNode;
//            }
//            count++;
//        }

//        public bool Remove(T data)
//        {
//            if (head == null)
//                return false;

//            if (head.Data.Equals(data))
//            {
//                head = head.Next;
//                if (head == null)
//                    tail = null;
//                count--;
//                return true;
//            }

//            Node<T> current = head;
//            while (current.Next != null)
//            {
//                if (current.Next.Data.Equals(data))
//                {
//                    if (current.Next == tail)
//                    {
//                        tail.Previous = current.Previous;
//                        tail = current;
//                        return true;
//                    }
//                    current.Next.Next.Previous = current;
//                    current.Next = current.Next.Next;
//                    count--;
//                    return true;
//                }
//                current = current.Next;
//            }
//            return false;
//        }

//        public void Clear()
//        {
//            head = null;
//            tail = null;
//            count = 0;
//        }

//    }

#endregion Task5
