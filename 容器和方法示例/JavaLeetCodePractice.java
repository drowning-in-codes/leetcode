import java.util.*;

/**
 * C++ 开发者的 Java 速成实战代码
 * 包含最常用的 LeetCode 代码片段和对比
 */

public class JavaLeetCodePractice {

    /** ========== 1. 容器基本操作对照 ========== */
    
    static void arrayListDemo() {
        // 创建和基本操作
        List<Integer> list = new ArrayList<>();
        
        list.add(1);              // 1
        list.add(2);              // [1, 2]
        list.add(0, 0);           // 在索引 0 插入 [0, 1, 2]
        
        int val = list.get(0);    // 获取
        list.set(1, 99);          // 修改 [0, 99, 2]
        list.remove(0);           // 删除 [99, 2]
        
        int size = list.size();
        boolean empty = list.isEmpty();
        
        // 遍历
        for (int x : list) {           // 增强 for
            System.out.println(x);
        }
        
        for (int i = 0; i < list.size(); i++) {  // 索引遍历
            System.out.println(list.get(i));
        }
    }
    
    static void hashMapDemo() {
        Map<String, Integer> map = new HashMap<>();
        
        // 添加和更新
        map.put("apple", 1);
        map.put("apple", 2);      // 覆盖
        
        // 查询
        Integer val = map.get("apple");           // 2
        Integer val2 = map.get("banana");         // null
        Integer val3 = map.getOrDefault("banana", 0);  // 0
        
        boolean exists = map.containsKey("apple");
        
        // 删除
        map.remove("apple");
        
        // 遍历所有键
        for (String key : map.keySet()) {
            System.out.println(key);
        }
        
        // 遍历所有值
        for (Integer value : map.values()) {
            System.out.println(value);
        }
        
        // 遍历键值对（推荐）
        for (Map.Entry<String, Integer> entry : map.entrySet()) {
            System.out.println(entry.getKey() + ": " + entry.getValue());
        }
    }
    
    static void hashSetDemo() {
        Set<Integer> set = new HashSet<>();
        
        set.add(1);
        set.add(2);
        set.add(1);               // 重复，不添加
        
        boolean contains = set.contains(1);
        set.remove(2);
        
        for (int x : set) {
            System.out.println(x);
        }
    }
    
    static void dequeAsStackDemo() {
        // Java 推荐用 Deque 代替 Stack
        Deque<Integer> stack = new ArrayDeque<>();
        
        stack.push(1);            // 入栈
        stack.push(2);
        
        int top = stack.peek();   // 查看栈顶
        int popped = stack.pop(); // 出栈
        
        boolean empty = stack.isEmpty();
    }
    
    static void dequeAsQueueDemo() {
        Deque<Integer> queue = new ArrayDeque<>();
        
        queue.offer(1);           // 入队
        queue.offer(2);
        
        int front = queue.peek(); // 查看队首
        int dequeued = queue.poll();  // 出队并返回值
        
        boolean empty = queue.isEmpty();
    }
    
    static void priorityQueueDemo() {
        // 最小堆（默认）
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        minHeap.offer(3);
        minHeap.offer(1);
        minHeap.offer(2);
        System.out.println(minHeap.poll());  // 1
        System.out.println(minHeap.poll());  // 2
        
        // 最大堆
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a, b) -> b - a);
        maxHeap.offer(3);
        maxHeap.offer(1);
        maxHeap.offer(2);
        System.out.println(maxHeap.poll());  // 3
        System.out.println(maxHeap.poll());  // 2
    }
    
    
    /** ========== 2. 字符串操作 ========== */
    
    static void stringDemo() {
        String s = "hello";
        
        // 长度
        int len = s.length();
        
        // 访问字符
        char c = s.charAt(0);     // 'h'
        
        // 子串
        String sub = s.substring(1, 3);   // "el" [1, 3)
        
        // 查找
        int idx = s.indexOf("ll");    // 2
        int notFound = s.indexOf("x"); // -1
        
        // 比较
        boolean eq = s.equals("hello");      // ⭐ 用 equals，不是 ==
        boolean eqIgnoreCase = s.equalsIgnoreCase("HELLO");
        
        // 大小写
        String upper = s.toUpperCase();    // "HELLO"
        String lower = s.toLowerCase();
        
        // 拆分
        String[] parts = "a,b,c".split(",");  // {"a", "b", "c"}
        
        // 拼接（频繁拼接用 StringBuilder）
        String concatenated = "hello" + " " + "world";
        
        // 替换
        String replaced = s.replace('l', 'L');  // "heLLo"
        String replacedStr = s.replace("ll", "LL");  // "heLLo"
    }
    
    static void stringBuilderDemo() {
        // 当需要频繁修改字符串时使用 StringBuilder
        StringBuilder sb = new StringBuilder();
        
        sb.append("hello");
        sb.append(" ");
        sb.append("world");
        
        String result = sb.toString();  // "hello world"
        
        // 清空并重用
        sb.setLength(0);
    }
    
    
    /** ========== 3. 排序与比较器 ========== */
    
    static class Interval implements Comparable<Interval> {
        int start, end;
        Interval(int s, int e) { start = s; end = e; }
        
        // 实现 Comparable 接口的方式
        @Override
        public int compareTo(Interval other) {
            if (this.start != other.start) return this.start - other.start;
            return this.end - other.end;
        }
    }
    
    static void sortDemo() {
        // 基本排序
        int[] arr = {3, 1, 4, 1, 5};
        Arrays.sort(arr);  // 升序 [1, 1, 3, 4, 5]
        
        // List 排序
        List<Integer> list = new ArrayList<>(Arrays.asList(3, 1, 4, 1, 5));
        Collections.sort(list);  // 升序
        Collections.sort(list, Collections.reverseOrder());  // 降序
        
        // 自定义对象排序
        List<Interval> intervals = new ArrayList<>();
        intervals.add(new Interval(1, 5));
        intervals.add(new Interval(1, 3));
        intervals.add(new Interval(2, 4));
        
        // 方式1：Lambda 比较器（推荐）
        Collections.sort(intervals, (a, b) -> {
            if (a.start != b.start) return a.start - b.start;
            return a.end - b.end;
        });
        
        // 方式2：使用 Comparator
        Collections.sort(intervals, new Comparator<Interval>() {
            public int compare(Interval a, Interval b) {
                if (a.start != b.start) return a.start - b.start;
                return a.end - b.end;
            }
        });
        
        // 方式3：List 自带 sort
        intervals.sort((a, b) -> a.start - b.start);
    }
    
    
    /** ========== 4. 数组处理 ========== */
    
    static void arrayUtilsDemo() {
        int[] arr = {3, 1, 4, 1, 5, 9, 2, 6};
        
        // 排序
        Arrays.sort(arr);
        
        // 填充
        Arrays.fill(arr, 0);
        
        // 复制
        int[] copied = Arrays.copyOf(arr, arr.length);
        
        // 范围复制
        int[] range = Arrays.copyOfRange(arr, 1, 4);
        
        // 二分搜索（必须先排序）
        Arrays.sort(arr);
        int index = Arrays.binarySearch(arr, 4);
        
        // 转为字符串
        String str = Arrays.toString(arr);  // "[1, 1, 2, 3, 4, 5, 6, 9]"
    }
    
    static void arrayListConversionsDemo() {
        // 数组转 List
        Integer[] arr = {1, 2, 3};
        List<Integer> list1 = new ArrayList<>(Arrays.asList(arr));
        
        // List 转数组
        List<Integer> list = new ArrayList<>();
        list.add(2); list.add(4); list.add(6);
        Integer[] arr2 = list.toArray(new Integer[0]);
        
        // 原始类型数组转 List（需要装箱）
        int[] primitiveArr = {1, 2, 3};
        List<Integer> boxedList = new ArrayList<>();
        for (int x : primitiveArr) boxedList.add(x);
    }
    
    
    /** ========== 5. 常用 LeetCode 题型模板 ========== */
    
    // 模板1：频率统计
    static int[] frequencyMap(int[] nums) {
        Map<Integer, Integer> freq = new HashMap<>();
        for (int x : nums) {
            freq.put(x, freq.getOrDefault(x, 0) + 1);
        }
        // 处理 freq
        return nums;
    }
    
    // 模板2：Top K
    static List<Integer> topK(int[] nums, int k) {
        Map<Integer, Integer> freq = new HashMap<>();
        for (int x : nums) {
            freq.put(x, freq.getOrDefault(x, 0) + 1);
        }
        
        PriorityQueue<Integer> minHeap = new PriorityQueue<>(
            (a, b) -> freq.get(a) - freq.get(b)
        );
        
        for (int x : freq.keySet()) {
            minHeap.offer(x);
            if (minHeap.size() > k) minHeap.poll();
        }
        
        return new ArrayList<>(minHeap);
    }
    
    // 模板3：两指针
    static int twoPointers(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == target) return left + right;
            else if (sum < target) left++;
            else right--;
        }
        return -1;
    }
    
    // 模板4：滑动窗口
    static int slidingWindow(String s, String t) {
        Map<Character, Integer> window = new HashMap<>();
        int minLen = Integer.MAX_VALUE;
        int left = 0;
        
        for (int right = 0; right < s.length(); right++) {
            char c = s.charAt(right);
            window.put(c, window.getOrDefault(c, 0) + 1);
            
            while (window.size() >= t.length()) {  // 这里是示意，实际需要更复杂的判断
                minLen = Math.min(minLen, right - left + 1);
                char leftChar = s.charAt(left);
                window.put(leftChar, window.get(leftChar) - 1);
                if (window.get(leftChar) == 0) window.remove(leftChar);
                left++;
            }
        }
        
        return minLen == Integer.MAX_VALUE ? -1 : minLen;
    }
    
    // 模板5：BFS
    static class Node {
        int val;
        List<Node> neighbors;
        Node(int val) { this.val = val; this.neighbors = new ArrayList<>(); }
    }
    
    static List<Node> bfs(Node start) {
        List<Node> result = new ArrayList<>();
        Queue<Node> queue = new LinkedList<>();
        Set<Node> visited = new HashSet<>();
        
        queue.offer(start);
        visited.add(start);
        
        while (!queue.isEmpty()) {
            Node node = queue.poll();
            result.add(node);
            
            for (Node neighbor : node.neighbors) {
                if (!visited.contains(neighbor)) {
                    visited.add(neighbor);
                    queue.offer(neighbor);
                }
            }
        }
        
        return result;
    }
    
    // 模板6：DFS
    static void dfs(Node node, Set<Node> visited) {
        if (visited.contains(node)) return;
        visited.add(node);
        
        for (Node neighbor : node.neighbors) {
            dfs(neighbor, visited);
        }
    }
    
    
    /** ========== 6. 类型转换 ========== */
    
    static void typeConversions() {
        // int ↔ String
        int num = 123;
        String numStr = String.valueOf(num);    // "123"
        int parsed = Integer.parseInt("456");   // 456
        
        // char ↔ ASCII
        char c = 'A';
        int ascii = c - '0';                    // 不同字符有不同处理
        int asciiValue = (int) c;               // 65
        
        // Long
        long bigNum = 999999999999L;
        String bigStr = Long.toString(bigNum);
        long parsedLong = Long.parseLong("123456789");
        
        // Boolean
        String trueStr = "true";
        boolean boolVal = Boolean.parseBoolean(trueStr);
        String boolStr = Boolean.toString(true);  // "true"
        
        // Double
        double d = 3.14;
        String dStr = String.valueOf(d);
        double parsed = Double.parseDouble("2.71");
    }
    
    
    /** ========== 7. 多线程基础 ========== */
    
    static class Counter {
        private volatile int value = 0;  // volatile 保证可见性
        
        public synchronized void increment() {
            value++;
        }
        
        public synchronized int getValue() {
            return value;
        }
    }
    
    static void threadDemo() throws InterruptedException {
        // 创建线程
        Thread t = new Thread(() -> {
            for (int i = 0; i < 5; i++) {
                System.out.println("线程: " + i);
                try {
                    Thread.sleep(100);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        });
        
        t.setName("myThread");
        t.start();  // ⭐ 是 start()，不是 run()
        t.join();   // 等待线程完成
    }
    
    
    /** ========== 8. 常见陷阱修正 ========== */
    
    static void pitfalls() {
        // ❌ 陷阱1：ArrayList 用 [] 访问
        List<Integer> list = new ArrayList<>();
        // list[0];      // 编译错误
        list.get(0);    // ✅ 正确
        
        // ❌ 陷阱2：HashMap 自动创建键
        Map<String, Integer> map = new HashMap<>();
        // map.get("key")++;  // NPE！
        map.put("key", map.getOrDefault("key", 0) + 1);  // ✅
        
        // ❌ 陷阱3：String 用 == 比较
        String s = "hello";
        // s == "hello";      // 可能为 false
        s.equals("hello");   // ✅ 正确
        
        // ❌ 陷阱4：遍历时删除
        for (int x : list) {
            // if (x > 5) list.remove(x);  // ConcurrentModificationException
        }
        // ✅ 使用迭代器
        Iterator<Integer> it = list.iterator();
        while (it.hasNext()) {
            if (it.next() > 5) it.remove();
        }
        
        // ❌ 陷阱5：PriorityQueue 默认最小堆
        PriorityQueue<Integer> pq = new PriorityQueue<>();  // 最小堆
        PriorityQueue<Integer> maxPq = new PriorityQueue<>((a, b) -> b - a);  // ✅ 最大堆
    }
    
    
    public static void main(String[] args) throws InterruptedException {
        System.out.println("=== C++ 开发者的 Java LeetCode 速成代码 ===\n");
        
        System.out.println("1. ArrayList 演示");
        arrayListDemo();
        System.out.println("\n2. HashMap 演示");
        hashMapDemo();
        System.out.println("\n3. 字符串演示");
        stringDemo();
        System.out.println("\n4. 排序演示");
        sortDemo();
        System.out.println("\n5. 类型转换");
        typeConversions();
        System.out.println("\n6. 多线程");
        threadDemo();
        
        System.out.println("\n✅ 所有演示完整！");
    }
}
