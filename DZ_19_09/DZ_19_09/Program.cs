#region Task1

// public class CSwap<T>
// {
//     public static void Swap(ref T num1, ref T num2)
//     {
//         T tmp;
//         
//         tmp = num1;
//         num1 = num2;
//         num2 = tmp;
//     }
// }
//
//
// class Program
// {
//     static void Main(string[] args)
//     {
//         int num1 = 10,num2 = 5;
//
//         Console.WriteLine($"Numbers before swap: {num1},{num2}");
//         
//         CSwap<int>.Swap(ref num1, ref num2);
//
//         Console.WriteLine($"Numbers after swap: {num1},{num2}");
//
//
//     }
// }


#endregion Task1
//

#region Task2

public class PriorityQueue<T>
{
    
    
    
    
    
    
    
    
    
    
    
    
    
    
}


class Program
{
    static void Main(string[] args)
    {
        
    }
}




#endregion Task2


#region Task3





#endregion Task3


#region Task4

// public class SingleLinkedList<T>
// {
//     public Node<T> Head;
//
//
//
//     public SingleLinkedList()
//     {
//         Head = null;
//         
//     }
//
//
//     public void AddFirstNode(T data)
//     {
//         Node<T> newNode = new Node<T>(data);
//         newNode.Next = Head;
//         Head = newNode;
//         
//     }
//
//     public void AddLastNode(T data)
//     {
//         Node<T> newNode = new Node<T>(data);
//         if (Head == null)
//         {
//             Head = newNode;
//         }
//         else
//         {
//             Node<T> current = Head;
//             while (current.Next != null)
//             {
//                 current = current.Next;
//             }
//             current.Next = newNode;
//         }
//     }
//
//
//
//     public bool RemoveNode(T data)
//     {
//         if (Head == null)
//             return false;
//
//         if (Head.Data.Equals(data))
//         {
//             Head = Head.Next;
//             return true;
//         }
//
//         Node<T> current = Head;
//         while (current.Next != null)
//         {
//             if (current.Next.Data.Equals(data))
//             {
//                 current.Next = current.Next.Next;
//                 return true;
//             }
//             current = current.Next;
//         }
//
//         return false;
//     }
//
//     public void Print()
//     {
//         Node<T> current = Head;
//         while (current != null)
//         {
//             Console.Write(current.Data + " ");
//             current = current.Next;
//         }
//
//         Console.WriteLine();
//     }
//     
//
// }
//
// public class Node<T>
// {
//     public T Data { get; set; }
//     public Node<T> Next { get; set; }
//
//     public Node(T data)
//     {
//         Data = data;
//         Next = null;
//     }
//
// }
//
//
// class Program
// {
//     static void Main(string[] args)
//     {
//         SingleLinkedList<int> list = new SingleLinkedList<int>();
//         
//         list.AddFirstNode(12);
//         list.AddLastNode(23);
//         list.AddLastNode(33);
//         list.AddLastNode(22);
//         
//         
//         list.Print();
//
//
//         list.RemoveNode(23);
//         
//         list.Print();
//     }
// }



#endregion Task4
//

#region Task5



#endregion Task5

