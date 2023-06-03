import java.util.Scanner;

public class Main {

    static class StackNode {
        char value;
        StackNode next;

        public StackNode(char value) {
            this.value = value;
            this.next = null;
        }
    }

    static StackNode newNode(char value) {
        StackNode stackNode = new StackNode(value);
        return stackNode;
    }

    static boolean isNotEmpty(StackNode pointer) {
        return pointer != null;
    }

    static void push(StackNode[] pointer, char new_data) {
        StackNode stackNode = newNode(new_data);
        stackNode.next = pointer[0];
        pointer[0] = stackNode;
    }

    static void pop(StackNode[] pointer) {
        StackNode temp = pointer[0];
        pointer[0] = pointer[0].next;
        temp = null;
    }

    static char top(StackNode pointer) {
        return pointer.value;
    }

    static boolean revision(String str, StackNode[] stack) {
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == '(' || str.charAt(i) == '[') {
                push(stack, str.charAt(i));
            } else if (str.charAt(i) == ')' && isNotEmpty(stack[0]) && top(stack[0]) == '(') {
                pop(stack);
            } else if (str.charAt(i) == ']' && isNotEmpty(stack[0]) && top(stack[0]) == '[') {
                pop(stack);
            } else {
                return false;
            }
        }

        if (!isNotEmpty(stack[0])) {
            return true;
        } else {
            return false;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            String str = sc.nextLine();
            StackNode[] stack = {null};
            if (revision(str, stack)) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}
