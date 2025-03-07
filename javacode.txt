
public class Entry2 {
	public static void main(String[] args) {

		System.out.println("CALCULATOR");
		System.out.println("-----------------------------");

		while (true) {

			System.out.println("Press 1 for Integer");
			System.out.println("Press 2 for Float");
			System.out.println("Press 3 for Exit\n");

			int datatype = ConsoleInput.getInteger();

			if (datatype == 1) {

				System.out.println("\nEnter the integer value: ");

				int firstNum = ConsoleInput.getInteger();

				System.out.println("Enter the integer value: ");

				int secondNum = ConsoleInput.getInteger();

				System.out.println("Press 1 for Addition");
				System.out.println("Press 2 for Subtraction");
				System.out.println("Press 3 for Multiplication");
				System.out.println("Press 4 for Division\n");

				Calculator objCalculator = new Calculator();

				int choice = ConsoleInput.getInteger();

				switch (choice) {

				case 1: {
					int result = objCalculator.add(firstNum, secondNum);

					System.out.println("\nResult for Addition is: " + result);
				}
					break;

				case 2: {
					int result = objCalculator.subtract(firstNum, secondNum);

					System.out.println("\nResult for Subtraction is: " + result);
				}
					break;

				case 3: {
					int result = objCalculator.multiply(firstNum, secondNum);

					System.out.println("\nResult for Multiplication is: " + result);
				}
					break;

				case 4: {
					int result = objCalculator.divide(firstNum, secondNum);

					System.out.println("\nResult for Division is: " + result);
				}
					break;

				default: {

					System.out.println("Error: Please enter correct choice..!!");
				}
					break;

				}

				System.out.println("------------------------------------");

			} else if (datatype == 2) {

				System.out.println("\nEnter the float value: ");

				float firstNum = ConsoleInput.getFloat();

				System.out.println("Enter the float value: ");

				float secondNum = ConsoleInput.getFloat();

				System.out.println("\nPress 1 for Addition");
				System.out.println("\nPress 2 for Subtraction");
				System.out.println("\nPress 3 for Multiplication");
				System.out.println("\nPress 4 for Division\n");

				Calculator objCalculator = new Calculator();

				int choice = ConsoleInput.getInteger();

				switch (choice) {

				case 1: {
					float result = objCalculator.add1(firstNum, secondNum);

					System.out.println("\nResult for Addition is: " + result);
				}
					break;

				case 2: {
					float result = objCalculator.subtract1(firstNum, secondNum);

					System.out.println("\nResult for Subtraction is: " + result);
				}
					break;

				case 3: {
					float result = objCalculator.multiply1(firstNum, secondNum);

					System.out.println("\nResult for Multiplication is: " + result);
				}
					break;

				case 4: {
					float result = objCalculator.divide1(firstNum, secondNum);

					System.out.println("\nResult for Division is: " + result);
					System.out.println("-------------------------------------------");
				}
					break;

				default: {

					System.out.println("\nError: Please enter correct choice..!!");
				}
					break;

				}

				System.out.println("------------------------------------");

			} else if (datatype == 3) {

				System.out.println("------------------------------------");

				break;

			} else {

				System.out.println("\nError: Please enter correct choice..!!");

				System.out.println("------------------------------------");
			}
		}

	}
}
