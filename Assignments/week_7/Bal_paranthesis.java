import java.util.Stack;

public class Bal_paranthesis {
    public static boolean isBalanced(String expression) {
        Stack<Character> stack = new Stack<>();

        for (char ch : expression.toCharArray()) {

            if (ch == '(' || ch == '[' || ch == '{') {
                stack.push(ch);
            }

   
            else if (ch == ')' || ch == ']' || ch == '}') {

                // No matching opening bracket
                if (stack.isEmpty()) {
                    return false;
                }

                char top = stack.pop();

                if ((ch == ')' && top != '(') ||
                    (ch == ']' && top != '[') ||
                    (ch == '}' && top != '{')) {
                    return false;
                }
            }
        }

        return stack.isEmpty();
    }

    public static void main(String[] args) {
        System.out.println(isBalanced("[()]{}{[()()]}")); // this is true
        System.out.println(isBalanced("[()"));             // thIS Is false
    }
}