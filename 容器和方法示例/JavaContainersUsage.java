import java.util.*;

public class JavaContainersUsage {
    public static void main(String[] args) {
        // ========== ArrayList 基本用法 ==========
        System.out.println("=== ArrayList 基本用法 ===");
        
        List<Integer> list = new ArrayList<>();
        list.add(10);
        list.add(20);
        list.add(30);
        list.add(1, 15);  // 在索引1插入15
        
        // 访问
        System.out.println("list.get(0) = " + list.get(0));
        System.out.println("list.get(1) = " + list.get(1));
        
        // 修改
        list.set(1, 25);
        
        // 大小
        System.out.println("size: " + list.size());
        
        // 遍历
        System.out.print("遍历: ");
        for (int x : list) System.out.print(x + " ");
        System.out.println();
        
        // 删除
        list.remove(Integer.valueOf(15));  // 删除第一个值为15的元素
        list.remove(0);                     // 删除索引0
        System.out.print("删除后: ");
        for (int x : list) System.out.print(x + " ");
        System.out.println();
        
        // 错误做法：遍历时直接删除会跳元素
        // for (int x : list) { list.remove(Integer.valueOf(x)); }  // 错误！
        
        // 正确做法：用迭代器删除
        Iterator<Integer> iter = list.iterator();
        while (iter.hasNext()) {
            int x = iter.next();
            if (x > 20) {
                iter.remove();  // 安全删除
            }
        }
        System.out.println();
        
        // ========== String 基本用法 ==========
        System.out.println("=== String 基本用法 ===");
        
        String s = "hello world";
        
        // 访问
        System.out.println("s.charAt(0) = " + s.charAt(0));
        System.out.println("s.length() = " + s.length());
        
        // 子串 [begin, end)
        String sub = s.substring(6, 11);  // "world"
        System.out.println("substring(6, 11) = " + sub);
        
        // 查找 - 注意返回-1表示未找到
        int pos = s.indexOf("world");
        if (pos != -1) {
            System.out.println("找到'world'在位置 " + pos);
        }
        
        // 比较
        if (s.equals("hello world")) {
            System.out.println("字符串相等");
        }
        if ("hello".equals("hello")) {  // 防止NullPointerException
            System.out.println("用String.equals()安全");
        }
        
        // 替换（创建新对象）
        String s2 = s.replace("world", "java");
        System.out.println("replace后: " + s2);
        
        System.out.println();
        
        // ========== StringBuilder 频繁修改 ==========
        System.out.println("=== StringBuilder 频繁修改 ===");
        
        StringBuilder sb = new StringBuilder();
        sb.append("hello").append(" ").append("world");  // 链式调用
        System.out.println("sb = " + sb.toString());
        
        sb.reverse();  // 反转
        System.out.println("reverse = " + sb.toString());
        
        System.out.println();
        
        // ========== HashMap 用法 ==========
        System.out.println("=== HashMap 用法 ===");
        
        Map<String, Integer> map = new HashMap<>();
        
        // 插入/更新
        map.put("apple", 1);
        map.put("banana", 2);
        map.put("apple", 3);  // 覆盖
        
        // 查询 - get()返回null表示不存在
        System.out.println("apple: " + map.get("apple"));
        System.out.println("orange: " + map.get("orange"));  // null
        
        // 安全查询
        int count = map.getOrDefault("orange", 0);
        System.out.println("用getOrDefault: " + count);
        
        // putIfAbsent - key不存在时才插入
        map.putIfAbsent("cherry", 4);
        map.putIfAbsent("apple", 99);  // apple存在，不覆盖
        System.out.println("putIfAbsent后 apple: " + map.get("apple"));
        
        // 遍历
        System.out.print("遍历所有: ");
        for (Map.Entry<String, Integer> entry : map.entrySet()) {
            System.out.print(entry.getKey() + "=" + entry.getValue() + " ");
        }
        System.out.println();
        
        System.out.println();
        
        // ========== HashSet 用法 ==========
        System.out.println("=== HashSet 用法 ===");
        
        Set<Integer> set = new HashSet<>();
        
        // 添加
        System.out.println("add(10) = " + set.add(10));  // true
        System.out.println("add(10) = " + set.add(10));  // false 已存在
        
        set.add(20);
        set.add(30);
        
        // 查询
        System.out.println("contains(20) = " + set.contains(20));
        System.out.println("contains(40) = " + set.contains(40));
        
        // 遍历
        System.out.print("遍历: ");
        for (int x : set) System.out.print(x + " ");
        System.out.println();
        
        System.out.println();
        
        // ========== ArrayDeque 栈和队列 ==========
        System.out.println("=== ArrayDeque（栈和队列）===");
        
        // 作为栈
        Deque<Integer> stack = new ArrayDeque<>();
        stack.push(1);
        stack.push(2);
        stack.push(3);
        System.out.print("栈弹出: ");
        while (!stack.isEmpty()) {
            System.out.print(stack.pop() + " ");  // 3, 2, 1
        }
        System.out.println();
        
        // 作为队列
        Deque<Integer> queue = new ArrayDeque<>();
        queue.offer(1);
        queue.offer(2);
        queue.offer(3);
        System.out.print("队列弹出: ");
        while (!queue.isEmpty()) {
            System.out.print(queue.poll() + " ");  // 1, 2, 3
        }
        System.out.println();
        
        System.out.println();
        
        // ========== PriorityQueue 优先级队列 ==========
        System.out.println("=== PriorityQueue ===");
        
        // 小根堆（默认）
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        minHeap.offer(5);
        minHeap.offer(2);
        minHeap.offer(8);
        System.out.print("小根堆: ");
        while (!minHeap.isEmpty()) {
            System.out.print(minHeap.poll() + " ");  // 2, 5, 8
        }
        System.out.println();
        
        // 大根堆
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a, b) -> b - a);
        maxHeap.offer(5);
        maxHeap.offer(2);
        maxHeap.offer(8);
        System.out.print("大根堆: ");
        while (!maxHeap.isEmpty()) {
            System.out.print(maxHeap.poll() + " ");  // 8, 5, 2
        }
        System.out.println();
        
        System.out.println();
        
        // ========== TreeMap 有序和范围查询 ==========
        System.out.println("=== TreeMap 有序 ===");
        
        TreeMap<Integer, String> treeMap = new TreeMap<>();
        treeMap.put(3, "三");
        treeMap.put(1, "一");
        treeMap.put(2, "二");
        
        // 有序遍历
        System.out.print("有序遍历: ");
        for (Map.Entry<Integer, String> e : treeMap.entrySet()) {
            System.out.print(e.getKey() + "-" + e.getValue() + " ");
        }
        System.out.println();
        
        // 范围查询
        System.out.println("lowerKey(2) = " + treeMap.lowerKey(2));      // 1
        System.out.println("higherKey(2) = " + treeMap.higherKey(2));    // 3
        System.out.println("firstKey() = " + treeMap.firstKey());        // 1
        System.out.println("lastKey() = " + treeMap.lastKey());          // 3
        
        System.out.println();
        
        // ========== 常用工具 ==========
        System.out.println("=== 常用工具 ===");
        
        List<Integer> arr = new ArrayList<>(Arrays.asList(5, 2, 8, 2, 9, 1));
        
        // 排序
        Collections.sort(arr);
        System.out.print("排序后: ");
        for (int x : arr) System.out.print(x + " ");
        System.out.println();
        
        // 二分查找
        int idx = Collections.binarySearch(arr, 5);
        System.out.println("binarySearch(5) = " + idx);
        
        // 反转
        Collections.reverse(arr);
        System.out.print("反转后: ");
        for (int x : arr) System.out.print(x + " ");
        System.out.println();
        
        // 打乱
        Collections.shuffle(arr);
        System.out.print("打乱后: ");
        for (int x : arr) System.out.print(x + " ");
        System.out.println();
    }
}
