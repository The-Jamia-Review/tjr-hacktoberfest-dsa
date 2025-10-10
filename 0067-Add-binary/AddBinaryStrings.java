public class AddBinaryStrings {
    public static String addBinary(String a, String b) {
        StringBuilder result = new StringBuilder();
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        // Loop through both strings from the end
        while (i >= 0 || j >= 0 || carry != 0) {
            int sum = carry;
            if (i >= 0) sum += a.charAt(i--) - '0'; // Convert char to int
            if (j >= 0) sum += b.charAt(j--) - '0'; // Convert char to int

            result.append(sum % 2); // Append current bit
            carry = sum / 2;        // Update carry
        }

        return result.reverse().toString(); // Reverse to get correct order
    }

    public static void main(String[] args) {
        String a = "1010";
        String b = "1101";

        String sum = addBinary(a, b);
        System.out.println("Sum of " + a + " and " + b + " is: " + sum);
    }
}

