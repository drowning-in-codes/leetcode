import java.util.*;

public class JavaVsCppContainers {
    public static void main(String[] args) {
        // Array vs ArrayList size
        int[] arr = {1, 2, 3};
        System.out.println("array length: " + arr.length);

        List<Integer> list = new ArrayList<>();
        list.add(1);
        list.add(2);
        list.add(3);
        System.out.println("list size(): " + list.size());

        // String length
        String s = "hello";
        System.out.println("string length(): " + s.length());

        // ArrayList access and set
        System.out.println("list.get(1) before: " + list.get(1));
        list.set(1, 99);
        System.out.println("list.get(1) after: " + list.get(1));

        // Map get vs containsKey
        Map<String, Integer> map = new HashMap<>();
        map.put("a", 1);
        System.out.println("map.get('a'): " + map.get("a"));
        System.out.println("map.containsKey('b'): " + map.containsKey("b"));

        // Set contains
        Set<Integer> set = new HashSet<>();
        set.add(5);
        System.out.println("set contains 5: " + set.contains(5));

        // Stack pop returns value in Java
        Deque<Integer> stack = new ArrayDeque<>();
        stack.push(10);
        int top = stack.pop();
        System.out.println("stack pop returns: " + top);

        // Queue poll returns value in Java
        Deque<Integer> queue = new ArrayDeque<>();
        queue.offer(1);
        int front = queue.poll();
        System.out.println("queue poll returns: " + front);

        // PriorityQueue poll returns value in Java
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        pq.offer(3);
        pq.offer(7);
        int best = pq.poll();
        System.out.println("priority_queue poll returns: " + best);

        // 常见静态工具方法（Arrays / Collections）
        int[] nums = {4, 1, 3, 2};
        Arrays.sort(nums);
        Arrays.fill(nums, 9);

        List<Integer> list2 = new ArrayList<>(Arrays.asList(4, 1, 3, 2));
        Collections.sort(list2);
        Collections.reverse(list2);

        // 数组与 List 相互转换
        Integer[] boxed = {1, 2, 3};
        List<Integer> fromArray = new ArrayList<>(Arrays.asList(boxed));
        Integer[] backToArray = fromArray.toArray(new Integer[0]);

        int[] primitive = {7, 8, 9};
        List<Integer> boxedList = new ArrayList<>();
        for (int x : primitive) boxedList.add(x);

        // 基本类型与对象类型转换
        Integer boxedInt = 42;        // 自动装箱 int -> Integer
        int unboxedInt = boxedInt;    // 自动拆箱 Integer -> int

        int parsedInt = Integer.parseInt("123");
        Integer valueInt = Integer.valueOf("456");
        String strFromInt = String.valueOf(789);

        Double boxedDouble = 3.14;
        double unboxedDouble = boxedDouble;
        String strFromDouble = Double.toString(2.718);

        // Long 类型转换
        Long boxedLong = 9999999999L;  // 自动装箱
        long unboxedLong = boxedLong;  // 自动拆箱
        long parsedLong = Long.parseLong("123456789");
        String strFromLong = Long.toString(987654321L);

        // Boolean 类型转换
        Boolean boxedBool = true;      // 自动装箱
        boolean unboxedBool = boxedBool;  // 自动拆箱
        boolean parsedBool = Boolean.parseBoolean("true");
        String strFromBool = Boolean.toString(false);

        // Character 类型转换
        char ch = 'A';
        Character boxedChar = ch;          // 自动装箱
        char unboxedChar = boxedChar;      // 自动拆箱
        char charFromInt = (char) 65;
        int intFromChar = (int) 'A';
        String strFromChar = Character.toString('B');
        System.out.println("char 'A' as int: " + intFromChar);

        // String indexOf returns -1 when not found
        int pos = s.indexOf("ll");
        if (pos != -1) {
            System.out.println("indexOf 'll' at: " + pos);
        }
    }
}
