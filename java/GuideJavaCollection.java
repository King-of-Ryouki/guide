import java.io.*;
import java.util.*;

// Collection
// |
// |
// |---List(有序)---|---LinkList
// |              　|---ArrayList
// |
// |
// |---Set(不重複)---|---HashSet(無序)
// |                 |---SortedSet(有序)
// |                 |---TreeSet(有序，同類型)
// |
// |
// |---Set(可重複)---|---HashMap
// |                 |---TreeMap
// |                 |---SortedMap
// |
// |

public class GuideJavaCollection {

    /**
     * @param args
     */
    public static void main(String[] args) {

        Stack<Integer> stk_1 = new Stack<Integer>();
        stk_1.push(10);
        stk_1.peek();
        stk_1.pop();

        Vector<Integer> vec_1 = new Vector<Integer>();
        vec_1.add(10);
        vec_1.get(0);
        vec_1.contains(10); // 如果指定的對象是集合中的元素返回 true
        vec_1.size();

        List<Integer> list_1 = new LinkedList<Integer>();
        vec_1.add(10);
        vec_1.get(0);
        vec_1.listIterator();

        Queue<Integer> que_1 = new LinkedList<Integer>();
        // add() 和 remove() 方法在失敗的時候會丟擲異常(不推薦)
        que_1.add(10);   // 加入一個元素
        que_1.offer(10); // 加入一個元素
        que_1.remove();  // 删除第一個元素
        que_1.poll();    // 删除第一個元素
        que_1.element();
        que_1.peek();

        Set<Integer> set_1 = new HashSet<Integer>();
        set_1.add(10);      // 將對象添加到集合
        set_1.clear();      // 從集合中移除所有對象
        set_1.contains(10); // 如果指定的對象是集合中的元素返回 true
        set_1.isEmpty();    // 如果集合不包含任何元素，則返回 true
        set_1.iterator();   // 返回一個 Iterator 對象，可用於檢索對象的集合
        set_1.remove(10);   // 從集合中刪除指定的對象
        set_1.size();       // 返回元素集合中的數

        Map<String, Integer> map_1 = new HashMap<String, Integer>();
        map_1.put("100", 10);
        map_1.containsKey("100"); // 返回 true 如果調用映射包含 k 作為重點。否則，返回 false。
        map_1.containsValue(1);   // 返回 true 如果映射包含 v 作為一個值。否則，返回 false。
        map_1.keySet();           // 返回一個集，其中包含調用映射的鍵。這種方法提供了一組視圖中調用映射的鍵。
        map_1.values();           // 返回包含在映射中的值的集合。這種方法提供了一個集合視圖在映射中的值。
        map_1.entrySet();         // 返回一組包含在地圖中的條目。該集合包含類型 Map.Entry 對象。這種方法提供了一組視圖調用地圖。

        set_1      = map_1.entrySet();
        Iterator i = set_1.iterator();
        while (i.hasNext()) {
            Map.Entry map_2 = (Map.Entry) i.next();
            System.out.print(map_2.getKey() + ": ");
            System.out.println(map_2.getValue());
        }

        map_2.equals(10);   // 如果 obj 是一個 Map.Entry 返回 true，其鍵和值都等於調用對象。
        map_2.getKey();     // 返回此映射項的鍵。
        map_2.getValue();   // 返回此映射項的值。
        map_2.hashCode();   // 返回此映射項的哈希碼。
        map_2.setValue(10); // 此映射條目 v 的集合。如果 v 是不正確的類型，映射拋出一個 ClassCastException 異常值。如果 v 是空和映射不允許 null 鍵則拋出 NullPointerException 異常。一個 UnsupportedOperationException 被拋出如果映射不能更改。
    }
}