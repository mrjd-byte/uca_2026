import java.util.Stack;

public class Postfix {

    public static int evaluatePostfix(String expression) {
        Stack<Integer> stack = new Stack<>();

        for (String token : expression.split(" ")) {

            // Operand
            if (token.matches("-?\\d+")) {
                stack.push(Integer.parseInt(token));
            }

            // Operator
            else {
                int second = stack.pop();
                int first = stack.pop();

                int result;

                switch (token) {
                    case "+":
                        result = first + second;
                        break;

                    case "-":
                        result = first - second;
                        break;

                    case "*":
                        result = first * second;
                        break;

                    case "/":
                        result = first / second;
                        break;

                    default:
                        throw new IllegalArgumentException("Invalid operator");
                }

                stack.push(result);
            }
        }

        return stack.pop();
    }

    public static void main(String[] args) {
        String expression = "2 3 1 * + 9 -";

        System.out.println(evaluatePostfix(expression));
    }
}